{
  gROOT->Reset();

  TCanvas *c1 = new TCanvas("c1","c1",500,500);
  TFile *f_bs = new TFile("$ANA_HIST_DIR/berger_sehgal_gstana.root");
  TFile *f_rs = new TFile("$ANA_HIST_DIR/rein_sehgal_gstana.root");
  c1->Divide(1,2);

  //
  TH1D *hev_bs = (TH1D*)f_bs->Get("h_ev");
  TH1D *hev_rs = (TH1D*)f_rs->Get("h_ev");
  c1->cd(1);
  hev_bs->Draw();
  c1->cd(2);
  hev_rs->Draw();
  c1->Print("$ANA_PS_DIR/bstop_rs_ev.pdf","pdf");
  //
  TH1D *hEpi_bs = (TH1D*)f_bs->Get("h_Epi");
  TH1D *hEpi_rs = (TH1D*)f_rs->Get("h_Epi");
  c1->cd(1);
  hEpi_bs->Draw();
  c1->cd(2);
  hEpi_rs->Draw();
  c1->Print("$ANA_PS_DIR/bstop_rs_Epi.pdf","pdf");
  //
  TH1D *hQ2s_bs = (TH1D*)f_bs->Get("h_Q2s");
  TH1D *hQ2s_rs = (TH1D*)f_rs->Get("h_Q2s");
  c1->cd(1);
  hQ2s_bs->Draw();
  c1->cd(2);
  hQ2s_rs->Draw();
  c1->Print("$ANA_PS_DIR/bstop_rs_Q2s.pdf","pdf");
  //
  TH1D *hts_bs = (TH1D*)f_bs->Get("h_ts");
  TH1D *hts_rs = (TH1D*)f_rs->Get("h_ts");
  c1->cd(1);
  hts_bs->Draw();
  c1->cd(2);
  hts_rs->Draw();
  c1->Print("$ANA_PS_DIR/bstop_rs_ts.pdf","pdf");
  //
  TH1D *ht_bs = (TH1D*)f_bs->Get("h_t");
  TH1D *ht_rs = (TH1D*)f_rs->Get("h_t");
  c1->cd(1);
  ht_bs->Draw();
  c1->cd(2);
  ht_rs->Draw();
  c1->Print("$ANA_PS_DIR/bstop_rs_t.pdf","pdf");
  //
  TH1D *hys_bs = (TH1D*)f_bs->Get("h_ys");
  TH1D *hys_rs = (TH1D*)f_rs->Get("h_ys");
  c1->cd(1);
  hys_bs->Draw();
  c1->cd(2);
  hys_rs->Draw();
  c1->Print("$ANA_PS_DIR/bstop_rs_ys.pdf","pdf");
  //
  TH1D *hy_bs = (TH1D*)f_bs->Get("h_y");
  TH1D *hy_rs = (TH1D*)f_rs->Get("h_y");
  c1->cd(1);
  hy_bs->Draw();
  c1->cd(2);
  hy_rs->Draw();
  c1->Print("$ANA_PS_DIR/bstop_rs_y.pdf","pdf");
  //
  TH1D *hdeltaE_bs = (TH1D*)f_bs->Get("h_deltaE");
  TH1D *hdeltaE_rs = (TH1D*)f_rs->Get("h_deltaE");
  c1->cd(1);
  hdeltaE_bs->Draw();
  c1->cd(2);
  hdeltaE_rs->Draw();
  c1->Print("$ANA_PS_DIR/bstop_rs_deltaE.pdf","pdf");
  //
  TH1D *hdeltax_bs = (TH1D*)f_bs->Get("h_deltax");
  TH1D *hdeltax_rs = (TH1D*)f_rs->Get("h_deltax");
  c1->cd(1);
  hdeltax_bs->Draw();
  c1->cd(2);
  hdeltax_rs->Draw();
  c1->Print("$ANA_PS_DIR/bstop_rs_deltax.pdf","pdf");
  //
  TH1D *hdeltay_bs = (TH1D*)f_bs->Get("h_deltay");
  TH1D *hdeltay_rs = (TH1D*)f_rs->Get("h_deltay");
  c1->cd(1);
  hdeltay_bs->Draw();
  c1->cd(2);
  hdeltay_rs->Draw();
  c1->Print("$ANA_PS_DIR/bstop_rs_deltay.pdf","pdf");
  //
  TH1D *hdeltaz_bs = (TH1D*)f_bs->Get("h_deltaz");
  TH1D *hdeltaz_rs = (TH1D*)f_rs->Get("h_deltaz");
  c1->cd(1);
  hdeltaz_bs->Draw();
  c1->cd(2);
  hdeltaz_rs->Draw();
  c1->Print("$ANA_PS_DIR/bstop_rs_deltaz.pdf","pdf");
  //
  TH1D *hpimuDeltaPhi_bs = (TH1D*)f_bs->Get("h_pimuDeltaPhi");
  TH1D *hpimuDeltaPhi_rs = (TH1D*)f_rs->Get("h_pimuDeltaPhi");
  c1->cd(1);
  hpimuDeltaPhi_bs->Draw();
  c1->cd(2);
  hpimuDeltaPhi_rs->Draw();
  c1->Print("$ANA_PS_DIR/bstop_rs_pimuDeltaPhi.pdf","pdf");
  //
  TH1D *hpiPhiInMuCo_bs = (TH1D*)f_bs->Get("h_piPhiInMuCo");
  TH1D *hpiPhiInMuCo_rs = (TH1D*)f_rs->Get("h_piPhiInMuCo");
  c1->cd(1);
  hpiPhiInMuCo_bs->Draw();
  c1->cd(2);
  hpiPhiInMuCo_rs->Draw();
  c1->Print("$ANA_PS_DIR/bstop_rs_piPhiInMuCo.pdf","pdf");
  //
  TH1D *hcalcGenQ2_bs = (TH1D*)f_bs->Get("h_calcGenQ2");
  TH1D *hcalcGenQ2_rs = (TH1D*)f_rs->Get("h_calcGenQ2");
  c1->cd(1);
  hcalcGenQ2_bs->Draw();
  c1->cd(2);
  hcalcGenQ2_rs->Draw();
  c1->Print("$ANA_PS_DIR/bstop_rs_calcGenQ2.pdf","pdf");
  //
  TH1D *hcalcGent_bs = (TH1D*)f_bs->Get("h_calcGent");
  TH1D *hcalcGent_rs = (TH1D*)f_rs->Get("h_calcGent");
  c1->cd(1);
  hcalcGent_bs->Draw();
  c1->cd(2);
  hcalcGent_rs->Draw();
  c1->Print("$ANA_PS_DIR/bstop_rs_calcGent.pdf","pdf");
  //
  TH1D *hcalcGeny_bs = (TH1D*)f_bs->Get("h_calcGeny");
  TH1D *hcalcGeny_rs = (TH1D*)f_rs->Get("h_calcGeny");
  c1->cd(1);
  hcalcGeny_bs->Draw();
  c1->cd(2);
  hcalcGeny_rs->Draw();
  c1->Print("$ANA_PS_DIR/bstop_rs_calcGeny.pdf","pdf");

}
