{
  gROOT->Reset();

  TCanvas *c1 = new TCanvas("c1","c1",500,500);
  c1->Divide(1,2);
  TFile *f_bs = new TFile("$ANA_HIST_DIR/berger_sehgal_grooana.root");
  TFile *f_rs = new TFile("$ANA_HIST_DIR/rein_sehgal_grooana.root");

  //
  TH1D *hevtXSec_bs = (TH1D*)f_bs->Get("h_evtXSec");
  TH1D *hevtXSec_rs = (TH1D*)f_rs->Get("h_evtXSec");
  c1->cd(1);
  hevtXSec_bs->Draw();
  c1->cd(2);
  hevtXSec_rs->Draw();
  c1->Print("$ANA_PS_DIR/bstop_rs_evtXSec.pdf","pdf");
  //
  TH1D *hevtDXSec_bs = (TH1D*)f_bs->Get("h_evtDXSec");
  TH1D *hevtDXSec_rs = (TH1D*)f_rs->Get("h_evtDXSec");
  c1->cd(1);
  gPad->SetLogy();
  hevtDXSec_bs->Draw();
  c1->cd(2);
  gPad->SetLogy();
  hevtDXSec_rs->Draw();
  c1->Print("$ANA_PS_DIR/bstop_rs_evtDXSec.pdf","pdf");
  //
  TH1D *hevtDXSecZoom_bs = (TH1D*)f_bs->Get("h_evtDXSecZoom");
  TH1D *hevtDXSecZoom_rs = (TH1D*)f_rs->Get("h_evtDXSecZoom");
  c1->cd(1);
  gPad->SetLogy();
  hevtDXSecZoom_bs->Draw();
  c1->cd(2);
  gPad->SetLogy();
  hevtDXSecZoom_rs->Draw();
  c1->Print("$ANA_PS_DIR/bstop_rs_evtDXSecZoom.pdf","pdf");

}
