#define gstana_cxx
#include "gstana.h"
#include <iomanip>
#include <sstream>
#include <string>
#include <TMath.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void gstana::Loop(unsigned int svn_tag) {
  if (fChain == 0) return;

  TObjArray * Hlist = new TObjArray(0);

  // Histograms
  TH1D *h_ev     = new TH1D("h_ev","Neutrino Energy;GeV;Counts per 500 MeV",20,0,10); 
  TH1D *h_neu    = new TH1D("h_neu","PDG Code;PDG Code;Counts per Code",40,-20,20); 
  TH1D *h_Q2s    = new TH1D("h_Q2s","Q^{2}s;GeV^{2};Counts per 50 bins",50,0,1); 
  TH1D *h_Q2     = new TH1D("h_Q2","Q^{2};GeV^{2};Counts per 50 bins",50,0,1); 
  TH1D *h_ts     = new TH1D("h_ts","ts;GeV^{2};Counts per 50 bins",50,0,0.25); 
  TH1D *h_t      = new TH1D("h_t","t;GeV^{2};Counts per 50 bins",50,0,0.25); 
  TH1D *h_ys     = new TH1D("h_ys","ys;;Counts per 50 bins",50,0,1); 
  TH1D *h_y      = new TH1D("h_y","y;;Counts per 50 bins",50,0,1); 
  TH1D *h_Epi    = new TH1D("h_Epi","E_{#pi};GeV;Counts per 50 bins",50,0,2); 
  TH1D *h_deltaE = new TH1D("h_deltaE","Final-Initial E",50,-0.001,0.001);
  TH1D *h_deltax = new TH1D("h_deltax","Final-Initial P_{X}",50,-0.001,0.001);
  TH1D *h_deltay = new TH1D("h_deltay","Final-Initial P_{Y}",50,-0.001,0.001);
  TH1D *h_deltaz = new TH1D("h_deltaz","Final-Initial P_{Z}",50,-0.001,0.001);
  TH1D *h_pimuDeltaPhi = new TH1D("h_pimuDeltaPhi","pi-mu Delta Phi",50,-6.2831,6.2831);
  TH1D *h_piPhiInMuCo  = new TH1D("h_piPhiInMuCo","pi phi in mu co",50,-6.2831,6.2831);
  TH1D *h_calcGenQ2    = new TH1D("h_calcGenQ2","Gen-Calc Q^{2};Gen-Calc Q^{2};",50,-0.01,0.01);
  TH1D *h_calcGent     = new TH1D("h_calcGent","Gen-Calc t;Gen-Calc t;",50,-2,2);
  TH1D *h_calcGeny     = new TH1D("h_calcGeny","Gen-Calc y;Gen-Calc y;",50,-0.1,0.1);

  Hlist->Add(h_ev);
  Hlist->Add(h_neu);
  Hlist->Add(h_Q2s);
  Hlist->Add(h_Q2);
  Hlist->Add(h_ts);
  Hlist->Add(h_t);
  Hlist->Add(h_ys);
  Hlist->Add(h_y);
  Hlist->Add(h_Epi);
  Hlist->Add(h_deltaE);
  Hlist->Add(h_deltax);
  Hlist->Add(h_deltay);
  Hlist->Add(h_deltaz);
  Hlist->Add(h_pimuDeltaPhi);
  Hlist->Add(h_piPhiInMuCo);
  Hlist->Add(h_calcGenQ2);
  Hlist->Add(h_calcGent);
  Hlist->Add(h_calcGeny);

  Long64_t nentries = fChain->GetEntriesFast();

  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;

    h_ev->Fill(Ev);
    h_neu->Fill(neu);
    h_Q2s->Fill(Q2s);
    h_Q2->Fill(Q2);
    h_ts->Fill(ts);
    h_t->Fill(t);
    h_ys->Fill(ys);
    h_y->Fill(y);
    h_Epi->Fill(Ei[1]);

    double carbonMass = 11.179019200000001;
    double initialE   = Ev + En + carbonMass;
    double finalE     = El + Ei[0] + Ei[1];
    double Mgamma     = Ei[0]/carbonMass;
    double Mvel       = TMath::Sqrt( 1 - 1/(Mgamma*Mgamma) );

    // beam is on z-axis
    double Mmu          = 0.10566; 
    double Mpi          = 0.13957; 
    double ptl2         = pxl*pxl + pyl*pyl;
    double ptpi2        = pxi[1]*pxi[1] + pyi[1]*pyi[1];
    double Pl           = TMath::Sqrt( pxl*pxl + pyl*pyl + pzl*pzl );
    double Ppi          = TMath::Sqrt( pxi[1]*pxi[1] + pyi[1]*pyi[1] + pzi[1]*pzi[1] );
    double thetaMu      = TMath::ACos( pzl / TMath::Sqrt( pzl*pzl + ptl2 ) );
    double phiMu        = TMath::ATan2(pyl,pxl);
    double phiPi        = TMath::ATan2(pyi[1],pxi[1]);
    double piDotMu      = pxl * pxi[1] + pyl * pyi[1] + pzl * pzi[1]; 
    double CosThetaPi   = pzi[1] / TMath::Sqrt( pzi[1]*pzi[1] + ptpi2 );
    double CosThetaMu   = pzl / TMath::Sqrt( pzl*pzl + ptl2 );
    double CosThetaPiMu = (piDotMu)/(Pl*Ppi); 

    double calcQ2 = 2*Ev*(El - Pl*CosThetaMu) - Mmu*Mmu;
    double calct  = calcQ2 + Mpi*Mpi + 2 * (
        Ei[1]*((En+carbonMass)-Ei[0]) - 
        pxi[1]*(pxn-pxi[0]) - 
        pyi[1]*(pyn-pyi[0]) - 
        pzi[1]*(pzn-pzi[0]) );
    double calcy = Ev > 0 ? (Ev - El)/Ev : -1;

    h_deltaE->Fill(finalE-initialE);
    h_deltax->Fill(pxv + pxn - pxl - pxi[0] - pxi[1]);
    h_deltay->Fill(pyv + pyn - pyl - pyi[0] - pyi[1]);
    h_deltaz->Fill(pzv + pzn - pzl - pzi[0] - pzi[1]);
    h_calcGenQ2->Fill(Q2s - calcQ2);
    h_calcGent->Fill(ts - calct);
    h_calcGeny->Fill(ys - calcy);
    h_pimuDeltaPhi->Fill( phiMu - phiPi );
    h_piPhiInMuCo->Fill( 
        TMath::ATan2( -pxi[1]*TMath::Sin(phiMu) + pyi[1]*TMath::Cos(phiMu),
          pxi[1]*TMath::Cos(phiMu) + pyi[1]*TMath::Sin(phiMu) )
        );
  } // end event for loop

  std::string histname = "$ANA_HIST_DIR/berger_sehgal_gstana_";
  std::string svn_string = static_cast<std::ostringstream*>( &(std::ostringstream() << svn_tag) )->str();
	histname += svn_string + ".root";
  TFile * outputfile = new TFile(histname.c_str(),"RECREATE");
  Hlist->Write();
  outputfile->Close();

  delete h_ev;
  delete h_neu;
  delete h_Q2s;
  delete h_Q2;
  delete h_ts;
  delete h_t;
  delete h_ys;
  delete h_y;
  delete h_deltaE;
  delete h_deltax;
  delete h_deltay;
  delete h_deltaz;
  delete h_piPhiInMuCo;
  delete h_pimuDeltaPhi;
  delete h_calcGenQ2;
  delete h_calcGent;
  delete h_calcGeny;

} // end of Loop() function
