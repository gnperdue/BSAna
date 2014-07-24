#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <TROOT.h>
#include <TApplication.h>
#include "TSystem.h"
#include "TFile.h"
#include "TChain.h"
#include "TTree.h"
#include "gstana.h"

Int_t flag = -1;

int main(int argc,char** argv) {

  TApplication theApp("App", &argc, argv);
  gApplication->Init();

  argc=theApp.Argc();
  argv=theApp.Argv();

  char *s = getenv( "ANA_LIST_DIR" );
  std::string filelist = s + std::string("/berger_sehgal_");
	unsigned int svn_tag = 1;

	while ((optind < argc) && (argv[optind][0]=='-')) {
		std::string sw = argv[optind];
		if (sw=="-v") {
			optind++;
			svn_tag = (unsigned int)atoi(argv[optind]);
      std::string svn_string = static_cast<std::ostringstream*>( &(std::ostringstream() << svn_tag) )->str();
			filelist += svn_string + "_list.txt";
		}
		else {
			std::cout << "Unknown switch: " << argv[optind] << std::endl;
		}
		optind++;
	}

	std::cout << "List file = " << filelist << std::endl;
	std::ifstream filestream( filelist.c_str() );
	TChain* chain = new TChain("gst");
	Char_t fname[200];
	Char_t filename[200];
	while ( filestream >> filename ){
		sprintf(fname, "$ANA_DATA_DIR/%s",filename);
		std::cout << "  Adding " << fname << " to list..." << std::endl;
		chain->Add(fname);
	}

	std::cout << "Make new gstana pointer..." << std::endl;
	gstana * jjj = new gstana(chain);
	std::cout << "Starting loop..." << std::endl;
	jjj->Loop(svn_tag);
	std::cout << "Exiting loop..." << std::endl;
	std::cout << "Exiting Run Code..." << std::endl;
	return 0;
}
