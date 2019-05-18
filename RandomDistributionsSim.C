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

void RandomDistributionsSim(){
        //Create the output canvases
	TCanvas * c1 = new TCanvas("Data", "Data", 1200, 800);
	TCanvas * c2 = new TCanvas("rho", "rho", 1000, 600);
	TCanvas * c3 = new TCanvas("particleDist","particleDist",1000,600);
	TCanvas * c4 = new TCanvas("trackSpectraComparison","trackSpectraComparison",1000,600);
	
        //Split off convases as appropriate
	c1->Divide(2,2);
	c2->Divide(1,1);
	c3->Divide(1,1);
	c4->Divide(1,1);
	
	gStyle->SetOptStat(111);
	
	float TrackPtmin = 0.2; //Follows our minimum Trackpt cutoff we use in real code of 200 MeV
	float TrackPtmax = 15.0; //Assign a 15 GeV maximum trackpt as well
	float JetPtmin = 15.0; //Follows minimum jetpt cutoff we use in real code of 15 GeV
	float JetPtmax = 50.0; //Assign a 50 GeV maximum jetpt as well
	bool multScale = kFALSE; //Switch between whether you use Run14 data (kTRUE) or pion data (kFALSE)
	
        //Create histograms
	TH2F *randomSetTracksSim = new TH2F("randomSetTracksSim","#Delta#eta #Delta#phi of Simulated Tracks |#eta| < 1;#Delta#eta;#Delta#phi (radians)",40,-1.0,1.0,36,0.0,2*TMath::Pi());
	TH2F *randomSetJetsSim = new TH2F("randomSetJetsSim","#Delta#eta #Delta#phi of Simulated Jets |#eta| < 0.7;#Delta#eta;#Delta#phi (radians)",40,-0.7,0.7,36,0.0,2*TMath::Pi());
	TH1F *TrackPtSim = new TH1F("TrackPtSim","p_{T} spectra of simulated Tracks;p_{T}",300,0.0,TrackPtmax);
	TH1F *JetPtSim = new TH1F("JetPtSim","p_{T} spectra of simulated jets;p_{T}",70,JetPtmin,JetPtmax);
	TH1F *rhoBGSim = new TH1F("rhoBGSim","#rho(r) of simulated data BG;r;1/NJets 1/#deltar",6,0.0,0.3);
	TH1F *rhoSim = new TH1F("rhoSim","#rho(r) of simulated data;r;1/NJets 1/#deltar",30,0.0,0.3);
	
        //Decide how many bins, tracks and jets you want in your event
	int nTracks = 30000;
	int nJets = 6000;
	int nRhoBins = 30;
	
	//Function to generate random values that follow pt distribution of Tracks
	TF1 *TrackPtSpectra;
	
        //pt fit function is created depending on whether we fit the pion data or Run14 data
	if(multScale){
		TrackPtSpectra = new TF1("TrackPtSpectra","[0]*(x+[1])^[2]",TrackPtmin,TrackPtmax);
		TrackPtSpectra->SetParameters(84.4444,3.12140,-2.75168); //Fit from my Data
		rhoSim->SetTitle("#rho(r) of simulated data (Multiplicity Scaled)");
		TrackPtSim->SetTitle("p_{T} spectra of simulated Tracks;p_{T};Unscaled");
	}
	else{
		//TrackPtSpectra->SetParameters(273.12,0.0,-2.072); //Pion data from Paper (power law fit)
		TrackPtSpectra = new TF1("TrackPtSpectra","[0]/(exp([1]*x)-1)",TrackPtmin,TrackPtmax); //Bose-Einstein Distribution Fit
		TrackPtSpectra->SetParameters(6424.62,3.60938);
		rhoSim->SetTitle("#rho(r) of simulated data (Pion Data Scaled)");
		TrackPtSim->SetTitle("p_{T} spectra of simulated Tracks (Fit to Pion Data);p_{T};Scaled by B/A");
	}
	
	//Function to generate random values that follow pt distribution of Jets
	TF1 *JetPtSpectra = new TF1("JetPtSpectra","[0]*(x+[1])^[2]",JetPtmin,JetPtmax);
	JetPtSpectra->SetParameters(1793.0,-0.8941,-5.976); //Values obtained from fit of real data
	
	//First Set of Data (Tracks)
	float TrackEta[nTracks];
	float TrackPhi[nTracks];
	float TrackPt[nTracks];
	//Background jets
	float BGEta[nJets];
	float BGPhi[nJets];
	float BGPt[nJets];
	//Second Set of Data (jets)
	float JetEta[nJets];
	float JetPhi[nJets];
	float JetPt[nJets];
	
	
	int loopCount = 0;
	
	//Randomly filling the Tracks Pt spectrum following the fit distribution
	//Randomly assigning eta and phi to Tracks
	for(int i = 0; i<nTracks; i++){
		TrackPt[i] = TrackPtSpectra->GetRandom(TrackPtmin,TrackPtmax);
		TrackPtSim->Fill(TrackPt[i]);
		
		float x1,y1;
		if(gRandom->Rndm()>0.5){
			x1 = -gRandom->Rndm();
		} else {
			x1 = gRandom->Rndm();
		}
		y1 = gRandom->Rndm()*2*TMath::Pi();
		
		TrackEta[i]=x1;
		TrackPhi[i]=y1;
		
		loopCount++;
	}
	
	//Randomly filling the Jet Pt spectrum following the pt distribution fit
	for(int i = 0; i<nJets; i++){
		float x2,y2;
		JetPt[i] = JetPtSpectra->GetRandom(JetPtmin,JetPtmax);
		JetPtSim->Fill(JetPt[i]);
		BGPt[i] = JetPt[i];
		
		if(gRandom->Rndm()>0.5){
			x2 = -0.7*gRandom->Rndm();
		} else {
			x2 = 0.7*gRandom->Rndm();
		}
		y2 = gRandom->Rndm()*2*TMath::Pi();
		
		JetEta[i]=x2;
		JetPhi[i]=y2;
		BGPhi[i]=JetPhi[i];
		
		if(BGEta[i] > -0.3 && BGEta[i] < 0.3){
			//Case 2
			BGPhi[i] = BGPhi[i] + TMath::Pi()*0.5;
			if(BGPhi[i]<-0*TMath::Pi()) 
				BGPhi[i]+=2.0*TMath::Pi();
			else if(BGPhi[i]>2*TMath::Pi()) 
				BGPhi[i]-=2.0*TMath::Pi();
			
			BGEta[i] = JetEta[i];
			
		} else { 
			//Case 1
			BGEta[i] = -JetEta[i];
			BGPhi[i] = JetPhi[i];
		}
		
		loopCount++;
	}
	
        //Fill the pion spectra plot, which will then be compared with the simulation data and compared
	int nEntries = 11;
	float scale = 4*TMath::Pi();
	float x1 = TMath::Sqrt(TMath::Power(0.126 + 0.13957,2) - TMath::Power(0.13957,2));
	float x2 = TMath::Sqrt(TMath::Power(0.169 + 0.13957,2) - TMath::Power(0.13957,2));
	float x3 = TMath::Sqrt(TMath::Power(0.214 + 0.13957,2) - TMath::Power(0.13957,2));
	float x4 = TMath::Sqrt(TMath::Power(0.261 + 0.13957,2) - TMath::Power(0.13957,2));
	float x5 = TMath::Sqrt(TMath::Power(0.308 + 0.13957,2) - TMath::Power(0.13957,2));
	float x6 = TMath::Sqrt(TMath::Power(0.356 + 0.13957,2) - TMath::Power(0.13957,2));
	float x7 = TMath::Sqrt(TMath::Power(0.404 + 0.13957,2) - TMath::Power(0.13957,2));
	float x8 = TMath::Sqrt(TMath::Power(0.452 + 0.13957,2) - TMath::Power(0.13957,2));
	float x9 = TMath::Sqrt(TMath::Power(0.501 + 0.13957,2) - TMath::Power(0.13957,2));
	float x10 = TMath::Sqrt(TMath::Power(0.550 + 0.13957,2) - TMath::Power(0.13957,2));
	float x11 = TMath::Sqrt(TMath::Power(0.599 + 0.13957,2) - TMath::Power(0.13957,2));
	
	float x[11] = {x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11};
	float y[11] = {scale*403.0,scale*298.1,scale*232.5,scale*183.9,scale*145.0,scale*113.8,scale*89.98,scale*71.1,scale*56.1,scale*44.3,scale*35.8};
	float ex[11] = {(x2-x1)/2,(x2-x1)/2,(x3-x2)/2,(x4-x3)/2,(x5-x4)/2,(x6-x5)/2,(x7-x6)/2,(x8-x7)/2,(x9-x8)/2,(x10-x9)/2,(x11-x10)/2};
	float ey[11] = {12.0,6.0,4.7,1.9,1.5,1.2,0.92,1.4,1.6,1.3,1.4};
	
	TGraphErrors *dataSpectra = new TGraphErrors(nEntries,x,y,ex,ey);
	dataSpectra->SetTitle("Spectra from Paper Data;p_{T};*4Pi");
	
	float a = TrackPtSim->Integral(2,12);
	float b = scale*(403.0+298.1+232.5+183.9+145.0+113.8+89.98+71.1+56.1+44.3+35.8); //I manually did the integral because it wasn't working properly with the command
	
	cout << "B/A: " << b/a << endl;
	if(!multScale)	{TrackPtSim->Scale(b/a);} 
	
	double binWidth = 0.0;
	if(nRhoBins == 30)
		binWidth = 0.01;
	else if(nRhoBins == 6)
		binWidth = 0.05;
	
	//Rho calculation for small bin width
	float jetSums[30] = {0.0};
	
	for(int i = 0; i<nJets; i++){
		float innerSums[30] = {0.0};
		
		for(int k = 0; k < nTracks; k++){
			double dphi = JetPhi[i] - TrackPhi[k];
			
			if(dphi<-0*TMath::Pi()) 
				dphi+=2.0*TMath::Pi();
			else if(dphi>2*TMath::Pi()) 
				dphi-=2.0*TMath::Pi();
			
			double r = TMath::Sqrt(TMath::Power(JetEta[i]-TrackEta[k],2) + TMath::Power(dphi,2));
			
			if(r <= 0.01)			{innerSums[0] += TrackPt[k];}
			else if(r > 0.01 && r <= 0.02)	{innerSums[1] += TrackPt[k];}
			else if(r > 0.02 && r <= 0.03)	{innerSums[2] += TrackPt[k];}
			else if(r > 0.03 && r <= 0.04)	{innerSums[3] += TrackPt[k];}
			else if(r > 0.04 && r <= 0.05)	{innerSums[4] += TrackPt[k];}
			else if(r > 0.05 && r <= 0.06)	{innerSums[5] += TrackPt[k];}
			else if(r > 0.06 && r <= 0.07)	{innerSums[6] += TrackPt[k];}
			else if(r > 0.07 && r <= 0.08)	{innerSums[7] += TrackPt[k];}
			else if(r > 0.08 && r <= 0.09)	{innerSums[8] += TrackPt[k];}
			else if(r > 0.09 && r <= 0.10)	{innerSums[9] += TrackPt[k];}
			else if(r > 0.10 && r <= 0.11)	{innerSums[10] += TrackPt[k];}
			else if(r > 0.11 && r <= 0.12)	{innerSums[11] += TrackPt[k];}
			else if(r > 0.12 && r <= 0.13)	{innerSums[12] += TrackPt[k];}
			else if(r > 0.13 && r <= 0.14)	{innerSums[13] += TrackPt[k];}
			else if(r > 0.14 && r <= 0.15)	{innerSums[14] += TrackPt[k];}
			else if(r > 0.15 && r <= 0.16)	{innerSums[15] += TrackPt[k];}
			else if(r > 0.16 && r <= 0.17)	{innerSums[16] += TrackPt[k];}
			else if(r > 0.17 && r <= 0.18)	{innerSums[17] += TrackPt[k];}
			else if(r > 0.18 && r <= 0.19)	{innerSums[18] += TrackPt[k];}
			else if(r > 0.19 && r <= 0.20)	{innerSums[19] += TrackPt[k];}
			else if(r > 0.20 && r <= 0.21)	{innerSums[20] += TrackPt[k];}
			else if(r > 0.21 && r <= 0.22)	{innerSums[21] += TrackPt[k];}
			else if(r > 0.22 && r <= 0.23)	{innerSums[22] += TrackPt[k];}
			else if(r > 0.23 && r <= 0.24)	{innerSums[23] += TrackPt[k];}
			else if(r > 0.24 && r <= 0.25)	{innerSums[24] += TrackPt[k];}
			else if(r > 0.25 && r <= 0.26)	{innerSums[25] += TrackPt[k];}
			else if(r > 0.26 && r <= 0.27)	{innerSums[26] += TrackPt[k];}
			else if(r > 0.27 && r <= 0.28)	{innerSums[27] += TrackPt[k];}
			else if(r > 0.28 && r <= 0.29)	{innerSums[28] += TrackPt[k];}
			else if(r > 0.29 && r <= 0.30)	{innerSums[29] += TrackPt[k];}
			else 				{loopCount++;continue;}
			
			loopCount++;
		}
		
		for(int z = 0; z<nRhoBins; z++){
			jetSums[z] = jetSums[z] + innerSums[z]/JetPt[i];
			loopCount++;
		}

	}
	
	for(int z = 0; z<nRhoBins; z++){
		rhoSim->SetBinContent(z+1,jetSums[z]);
		loopCount++;
	}
	
	double rhoScale =  0.0;
	
	if(multScale){
		rhoScale = ((float)nTracks)/((372.5+441.0)/2.0); //Central
		cout << "rhoScale: " << rhoScale << endl;
		//rhoScale = nTracks/((10+10)/2); //Peripheral
		rhoSim->Scale(1.0/(nJets*binWidth*rhoScale));
    	} else {
		rhoSim->Scale(1.0/(nJets*binWidth));
	}
	
	
	//Wider Bin Rho calculation 
	/*
	
	float jetSums[nRhoBins];
	float jetSumsBG[nRhoBins];
	
	int n1,n2,n3,n4,n5,n6;
	for(int i = 0; i<nJets; i++){
		float innerSums[nRhoBins];
		float innerSumsBG[nRhoBins];
		
		for(int k = 0; k < nTracks; k++){
			double dphi = JetPhi[i] - TrackPhi[k];
			
			if(dphi<-0*TMath::Pi()) 
				dphi+=2.0*TMath::Pi();
			else if(dphi>2*TMath::Pi()) 
				dphi-=2.0*TMath::Pi();
			
			
			double r = TMath::Sqrt(TMath::Power(JetEta[i]-TrackEta[k],2) + TMath::Power(dphi,2));
			if(r <= 0.05)					{innerSums[0] += TrackPt[k];n1++;}
			else if(r > 0.05 && r <= 0.10)	{innerSums[1] += TrackPt[k];n2++;}
			else if(r > 0.10 && r <= 0.15)	{innerSums[2] += TrackPt[k];n3++;}
			else if(r > 0.15 && r <= 0.20)	{innerSums[3] += TrackPt[k];n4++;}
			else if(r > 0.20 && r <= 0.25)	{innerSums[4] += TrackPt[k];n5++;}
			else if(r > 0.25 && r <= 0.30)	{innerSums[5] += TrackPt[k];n6++;}
			
			double dphiBG = BGPhi[i] - TrackPhi[k];
			
			if(dphiBG<-0*TMath::Pi()) 
				dphiBG+=2.0*TMath::Pi();
			else if(dphiBG>2*TMath::Pi()) 
				dphiBG-=2.0*TMath::Pi();
			
			double rBG = TMath::Sqrt(TMath::Power(BGEta[i]-TrackEta[k],2) + TMath::Power(dphiBG,2));
			if(rBG <= 0.05)						{innerSumsBG[0] += TrackPt[k];}
			else if(rBG > 0.05 && rBG <= 0.10)	{innerSumsBG[1] += TrackPt[k];}
			else if(rBG > 0.10 && rBG <= 0.15)	{innerSumsBG[2] += TrackPt[k];}
			else if(rBG > 0.15 && rBG <= 0.20)	{innerSumsBG[3] += TrackPt[k];}
			else if(rBG > 0.20 && rBG <= 0.25)	{innerSumsBG[4] += TrackPt[k];}
			else if(rBG > 0.25 && rBG <= 0.30)	{innerSumsBG[5] += TrackPt[k];}
			
			loopCount++;
		}
		for(int z = 0; z<nRhoBins; z++){
			jetSums[z] += innerSums[z]/JetPt[i];
			jetSumsBG[z] += innerSumsBG[z]/BGPt[i];
			loopCount++;
		}
		
		loopCount++;
	}
	for(int z = 0; z<nRhoBins; z++){
		rhoSim->SetBinContent(z+1,jetSums[z]);
		rhoBGSim->SetBinContent(z+1,jetSumsBG[z]);
		loopCount++;
	}
	*/
	
	//Forloop to fill eta phi histogram for tracks
	for(int i = 0;i<nTracks;i++){
		for(int k =i+1;k<nTracks;k++){
			float dphi1 = TrackPhi[i] - TrackPhi[k];
		
			if(dphi1<-0*TMath::Pi()) 
				dphi1+=2.0*TMath::Pi();
			else if(dphi1>2*TMath::Pi()) 
				dphi1-=2.0*TMath::Pi();
			
			randomSetTracksSim->Fill(TrackEta[i]-TrackEta[k],dphi1);
			
			loopCount++;
		}
	}
	
	//Forloop to fill eta phi histogram for jets
	for(int i = 0;i<nJets;i++){
		for(int k =i+1;k<nJets;k++){
			float dphi2 = JetPhi[i] - JetPhi[k];
			
			if(dphi2<-0*TMath::Pi())		{dphi2+=2.0*TMath::Pi();}
			else if(dphi2>2*TMath::Pi())	{dphi2-=2.0*TMath::Pi();}
			
			randomSetJetsSim->Fill(JetEta[i]-JetEta[k],dphi2);
			
			loopCount++;
		}
	}
	
        //Display the raw data
	c1->cd(1);
	randomSetTracksSim->Draw("COLZ");

	c1->cd(2);
	randomSetJetsSim->Draw("COLZ");
	
	c1->cd(3);
	TrackPtSim->Draw();
	
	c1->cd(4);
	JetPtSim->Draw();
	
	c2->cd(1);
	rhoSim->Draw();
	
	c3->cd(1);
	dataSpectra->Draw();
	
	c4->cd(1);
	dataSpectra->Draw();
	TrackPtSim->Draw("SAME");
	
	/*
	double binEdges[nEntries+1] = {x1-(x2-x1)/2, x2-(x2-x1)/2, x3-(x3-x2)/2, x4-(x4-x3)/2, x5-(x5-x4)/2, x6-(x6-x5)/2, x7-(x7-x6)/2, x8-(x8-x7)/2, x9-(x9-x8)/2, x10-(x10-x9)/2, 
	x11-(x11-x10)/2, x11+(x11-x10)/2};
	
	TH1F *TrackPtSimReBinned = new TH1F("TrackPtSimReBinned","p_{T} spectra of simulated tracks;p_{T}",nEntries,binEdges);
	TrackPtSimReBinned->Fill(TrackPtSim,1.0);
	TrackPtSimReBinned->Draw("SAME");
	*/
	
        //Show the efficiency of the simulation by showing the number of times a loop was iterated
	cout << "Number of loop runs: " << loopCount << endl;
	
        //Output all data accordingly
	if(multScale){
		TFile *File = new TFile("MultScaledSimulations.root", "RECREATE");
	
		randomSetTracksSim->Write("randomSetTracksSim");
		randomSetJetsSim->Write("randomSetJetsSim");
		rhoSim->Write("rhoSimMultScaled");
		TrackPtSim->Write("simTrackPtMultScaled");
		JetPtSim->Write("JetPtSim");
		rhoBGSim->Write("rhoBGSimMultScaled");
		dataSpectra->Write("pionSpectra");
		TrackPtSpectra->Write("trackFitLine");
		File->Close();
	} else {
		TFile *File = new TFile("DataScaledSimulations.root", "RECREATE");
		
		randomSetTracksSim->Write("randomSetTracksSim");
		randomSetJetsSim->Write("randomSetJetsSim");
                rhoSim->Write("rhoSimDataScaled");
		TrackPtSim->Write("simTrackPtDataScaled");
		JetPtSim->Write("JetPtSim");
		rhoBGSim->Write("rhoBGSimDataScaled");
		dataSpectra->Write("pionSpectra");
		TrackPtSpectra->Write("pionTrackFitLine");
		File->Close();
	}	
	
}
