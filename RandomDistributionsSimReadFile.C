#include <iostream>
#include <stdio.h>
#include <fstream>
#include <TH1F.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TFile.h>
#include <TTree.h>
#include <TF1.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TFile.h>
#include <TStyle.h>
#include <TStopwatch.h>
#include <TRandom3.h>
#include <TChain.h>
#include <TProfile.h>
#include <TStopwatch.h>
#include <TCut.h>
#include <cstdlib>
#include <cmath>
#include "TLegend.h"
#include "TLatex.h"
#include "TMath.h"
#include "TLine.h"
#include "TFormula.h"
#include "TPaveText.h"

void RandomDistributionsSimReadFile(){

        //Read in the data
	TFile *multScaledData = new TFile("MultScaledSimulations.root");
	TFile *dataScaledData = new TFile("DataScaledSimulations.root");
	
	TH1F* rhoSimMultScaled = (TH1F*)multScaledData->Get("rhoSimMultScaled");
	TH1F* simTrackPtMultScaled = (TH1F*)multScaledData->Get("simTrackPtMultScaled");
	
	TH1F* rhoSimDataScaled = (TH1F*)dataScaledData->Get("rhoSimDataScaled");
	TH1F* simTrackPtDataScaled = (TH1F*)dataScaledData->Get("simTrackPtDataScaled");
	TH1F* pionSpectra = (TH1F*)dataScaledData->Get("pionSpectra");
	TF1* pionTrackFitLine = (TF1*)dataScaledData->Get("pionTrackFitLine");

        //Create appropropriate canvases	
	TCanvas * c5 = new TCanvas("rhoOverlap", "rhoOverlap", 1000, 600);
	TCanvas * c6 = new TCanvas("rhoRatio", "rhoRatio", 1000, 600);
	TCanvas * c7 = new TCanvas("rhoComparisons","rhoComparisons",1200,600);
	TCanvas * c8 = new TCanvas("trackSpectraComparisons","trackSpectraComparisons",1200,600);
	TCanvas * c9 = new TCanvas("pionSpectraFitting","pionSpectraFitting",1200,600);
	
        //Divide convases
	c5->Divide(1,1);
	c6->Divide(1,1);
	c7->Divide(2,1);
	c8->Divide(2,1);
	c9->Divide(2,2);
	
	//Style the outputted data according to which method was used
	
        //Run14 pt Spectra
	rhoSimMultScaled->SetLineWidth(2);
	rhoSimMultScaled->SetLineColor(kGreen+2);
	simTrackPtMultScaled->SetLineWidth(2);
	simTrackPtMultScaled->SetLineColor(kGreen+2);

        //pion data pt Spectra
	rhoSimDataScaled->SetLineWidth(2);
	rhoSimDataScaled->SetLineColor(kBlue+1);
	simTrackPtDataScaled->SetLineWidth(2);
	simTrackPtDataScaled->SetLineColor(kBlue+1);

	pionSpectra->SetLineWidth(2);
	pionSpectra->SetLineColor(kRed+1);
	pionTrackFitLine->SetLineWidth(2);
	pionTrackFitLine->SetLineColor(kBlack);

	
	
	//Compare the two results for rho
	TH1F* rhoRatioPlots = new TH1F("rhoRatioPlots","RhoDataScaled/RhoMultScaled plot;r;#rho(r)DataScale/#rho(r)MultScale",rhoSimDataScaled->GetNbinsX(),0.0,rhoSimDataScaled->GetXaxis()->GetXmax());
	
	c5->cd(1);
	rhoSimDataScaled->Draw("");
	rhoSimMultScaled->Draw("SAME");
	
	c6->cd(1);
	rhoRatioPlots->Divide(rhoSimDataScaled,rhoSimMultScaled,1.0,1.0,"");
	rhoRatioPlots->Draw("");
	
	/*
	for(int i = 1; i<rhoSimDataScaled->GetNbinsX()+1; i++){
		cout << "--------------------------------------------------------------------------"<<endl;
		cout << "Mult Scaled bin " << i << ": " << rhoSimMultScaled->GetBinContent(i) << endl; 
		cout << "Data Scaled bin " << i << ": " << rhoSimDataScaled->GetBinContent(i) << endl;
		cout << "Ratio of bin " << i << ": " << rhoSimDataScaled->GetBinContent(i)/rhoSimMultScaled->GetBinContent(i) << endl;
		
	}
	*/
	
        //Draw everything
	c7->cd(1);
	rhoSimDataScaled->Draw("");
	rhoSimMultScaled->Draw("SAME");
	
	c7->cd(2);
	rhoRatioPlots->Draw("");
	
	c8->cd(1);
	simTrackPtMultScaled->Draw("");
	
	c8->cd(2);
	simTrackPtDataScaled->Draw("");

	c9->cd(1);
	pionSpectra->Draw("");
	pionTrackFitLine->Draw("SAME");

	c9->cd(2);
	simTrackPtDataScaled->Draw("");
	pionTrackFitLine->Draw("SAME");

	c9->cd(3);
	pionSpectra->Draw("");
	simTrackPtDataScaled->Draw("SAME");
        pionTrackFitLine->Draw("SAME");

}
