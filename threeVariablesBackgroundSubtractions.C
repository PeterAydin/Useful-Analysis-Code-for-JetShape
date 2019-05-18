#include "TH1.h"
#include <TStyle.h>
#include <TPad.h>
#include "TMath.h"
#include "TCanvas.h"
#include "TStyle.h"

int threeVariablesBackgroundSubtractions(){

 //Declare canvases that'll be used to make useful to analyze images
 c1 = new TCanvas("ptD","ptD",1200,600);
 c2 = new TCanvas("Angularity","Angularity",1200,600);
 c3 = new TCanvas("LeSub","LeSub",1200,600);
 c4 = new TCanvas("Distances","Distances",1200,600);
 c5 = new TCanvas("ptDGraphs","ptDGraphs",1200,600);
 c6 = new TCanvas("AngularityGraphs","AngularityGraphs",1200,600);
 c7 = new TCanvas("LeSubGraphs","LeSubGraphs",1200,600);
 c8 = new TCanvas("PtSpectraComparisons","PtSpectraComparisons",1200,600); 
 c9 = new TCanvas("MvSLeSub","MvSLeSub",1200,600);
 c10 = new TCanvas("MvSptD","MvSptD",1200,600);
 c11 = new TCanvas("MvSg","MvSg",1200,600);
 c12 = new TCanvas("LeSubComparisons","LeSubComparisons",1200,600);
 c13 = new TCanvas("ptDComparisons","ptDComparisons",1200,600);
 c14 = new TCanvas("gComparisons","gComparisons",1200,600);
 c15 = new TCanvas("SubvsNoSubPtSpectra","SubvsNoSubPtSpectra",1200,600);
 c16 = new TCanvas("ptDCentComparisons","ptDCentComparisons",1200,600); 
 c17 = new TCanvas("IRPtDCentandPtSelections","IRPtDCentandPtSelections",1600,800);
 c18 = new TCanvas("OORPtDCentandPtSelections","OORPtDCentandPtSelections",1600,800);
 c19 = new TCanvas("IRPtDPeaksNTracksAroundPeak","IRPtDPeaksNTracksAroundPeak",1600,600);
 c20 = new TCanvas("OORPtDPeaksNTracksAroundPeak","OORPtDPeaksNTracksAroundPeak",1600,600);
 c21 = new TCanvas("IRPtDPeaksPtTracksAroundPeak","IRPtDPeaksPtTracksAroundPeak",1600,600);
 c22 = new TCanvas("OORPtDPeaksPtTracksAroundPeak","OORPtDPeaksPtTracksAroundPeak",1600,600);
 c23 = new TCanvas("LeSubCentRatioPlots","LeSubCentRatioPlots",1200,800); 
 c24 = new TCanvas("ptDCentRatioPlots","ptDCentRatioPlots",1200,800);
 c25 = new TCanvas("gCentRatioPlots","gCentRatioPlots",1200,800);
 c26 = new TCanvas("LeSubRatio1525PtOOR","LeSubRatio1525PtOOR",1200,800);
 c27 = new TCanvas("PtDRatio1525PtOOR","PtDRatio1525PtOOR",1200,800);
 c28 = new TCanvas("gRatio1525PtOOR","gRatio1525PtOOR",1200,800);
 c29 = new TCanvas("LeSubRatio1525PtIR","LeSubRatio1525PtIR",1200,800);
 c30 = new TCanvas("PtDRatio1525PtIR","PtDRatio1525PtIR",1200,800);
 c31 = new TCanvas("gRatio1525PtIR","gRatio1525PtIR",1200,800);
 c32 = new TCanvas("LeSubRatio25PtOOR","LeSubRatio25PtOOR",1200,800);
 c33 = new TCanvas("PtDRatio25PtOOR","PtDRatio25PtOOR",1200,800);
 c34 = new TCanvas("gRatio25PtOOR","gRatio25PtOOR",1200,800);
 c35 = new TCanvas("LeSubRatio25PtIR","LeSubRatio25PtIR",1200,800);
 c36 = new TCanvas("PtDRatio25PtIR","PtDRatio25PtIR",1200,800);
 c37 = new TCanvas("gRatio25PtIR","gRatio25PtIR",1200,800);
 c38 = new TCanvas("LeSubSelectionsSignal","LeSubSelectionsSignal",1600,1000);
 c39 = new TCanvas("PtDSelectionsSignal","PtDSelectionsSignal",1600,1000);
 c40 = new TCanvas("gSelectionsSignal","gSelectionsSignal",1600,1000);
 c41 = new TCanvas("LeSubSelectionsBG","LeSubSelectionsBG",1600,1000);
 c42 = new TCanvas("PtDSelectionsBG","PtDSelectionsBG",1600,1000);
 c43 = new TCanvas("gSelectionsBG","gSelectionsBG",1600,1000);
 c44 = new TCanvas("LeSubSelectionsBGSubbed","LeSubSelectionsBGSubbed",1600,1000);
 c45 = new TCanvas("PtDSelectionsBGSubbed","PtDSelectionsBGSubbed",1600,1000);
 c46 = new TCanvas("gSelectionsBGSubbed","gSelectionsBGSubbed",1600,1000);
 c47 = new TCanvas("LeSubMergedEtaHistos","LeSubMergedEtaHistos",1600,500);
 c48 = new TCanvas("PtDMergedEtaHistos","PtDMergedEtaHistos",1600,500);
 c49 = new TCanvas("gMergedEtaHistos","gMergedEtaHistos",1600,500);
 c50 = new TCanvas("LeSubRatioLowPt","LeSubRatioLowPt",1200,800);
 c51 = new TCanvas("PtDRatioLowPt","PtDRatioLowPt",1200,800);
 c52 = new TCanvas("gRatioLowPt","gRatioLowPt",1200,800);
 c53 = new TCanvas("LeSubRatioHighPt","LeSubRatioHighPt",1200,800);
 c54 = new TCanvas("PtDRatioHighPt","PtDRatioHighPt",1200,800);
 c55 = new TCanvas("gRatioHighPt","gRatioHighPt",1200,800);
 c56 = new TCanvas("jetPt","jetPt",800,600);
 c57 = new TCanvas("2TracksLeSubSigBG","2TracksLeSubSigBG",1600,1000);
 c58 = new TCanvas("2TracksLeSubSigBGEtaMerged","2TracksLeSubSigBGEtaMerged",1600,500);
 c59 = new TCanvas("2TracksLeSub1525PtOOR","2TracksLeSub1525PtOOR",1200,800);
 c60 = new TCanvas("2TracksLeSub1525PtIR","2TracksLeSub1525PtIR",1200,800);
 c61 = new TCanvas("2TracksLeSub25PtOOR","2TracksLeSub25PtOOR",1200,800);
 c62 = new TCanvas("2TracksLeSub25PtIR","2TracksLeSub25PtIR",1200,800);
 c63 = new TCanvas("2TracksLeSubRatioLowPt","2TracksLeSubRatioLowPt",1200,800);
 c64 = new TCanvas("2TracksLeSubRatioHighPt","2TracksLeSubRatioHighPt",1200,800);
 c65 = new TCanvas("trackConstitsPt","trackConstitsPt",800,600);
 c66 = new TCanvas("allTracksPt","allTracksPt",800,600);


 //Set styling preferences to the histograms
 gStyle->SetOptStat(0); //Get rid of stat box
 gStyle->SetOptTitle(0); //no title
 gStyle->SetHistMinimumZero(); //No negative y values by default
 gStyle->SetTitleSize(0.06,"XY"); //Scale font of the X and Y axis titles
 gStyle->SetTitleOffset(0.4,"XY"); //Offset location of the X and Y axis titles

 //Split canvases as necessary to display multiple sets of information
 c1->Divide(2,1);
 c2->Divide(2,1);
 c3->Divide(2,1);
 c4->Divide(2,2);
 c5->Divide(2,2);
 c6->Divide(2,2);
 c7->Divide(2,2);
 c8->Divide(2,2);
 c9->Divide(2,1);
 c10->Divide(2,1);
 c11->Divide(2,1);
 c12->Divide(2,1);
 c13->Divide(2,1);
 c14->Divide(2,1);
 c15->Divide(2,1);
 c16->Divide(2,2);
 c17->Divide(4,3);
 c18->Divide(4,3);
 c19->Divide(4,2);
 c20->Divide(4,2);
 c21->Divide(4,2);
 c22->Divide(4,2);
 c23->Divide(3,3);
 c24->Divide(3,3);
 c25->Divide(3,3);
 c26->Divide(3,3);
 c27->Divide(3,3);
 c28->Divide(3,3);
 c29->Divide(3,3);
 c30->Divide(3,3);
 c31->Divide(3,3);
 c32->Divide(3,3);
 c33->Divide(3,3);
 c34->Divide(3,3);
 c35->Divide(3,3);
 c36->Divide(3,3);
 c37->Divide(3,3);
 c38->Divide(4,4);
 c39->Divide(4,4);
 c40->Divide(4,4);
 c41->Divide(4,4);
 c42->Divide(4,4);
 c43->Divide(4,4);
 c44->Divide(4,4);
 c45->Divide(4,4);
 c46->Divide(4,4);
 c47->Divide(4,2);
 c48->Divide(4,2);
 c49->Divide(4,2);
 c50->Divide(3,3);
 c51->Divide(3,3);
 c52->Divide(3,3);
 c53->Divide(3,3);
 c54->Divide(3,3);
 c55->Divide(3,3);
 c56->Divide(1,1);
 c57->Divide(4,4);
 c58->Divide(4,2);
 c59->Divide(3,3);
 c60->Divide(3,3);
 c61->Divide(3,3);
 c62->Divide(3,3);
 c63->Divide(3,3);
 c64->Divide(3,3);
 c65->Divide(1,1);
 c66->Divide(1,1);
 
 double minTrackPt = 2.0; //Used to tell a future label, what the minimum track pt for the data set will be. Adjust this accordingly depending on your runs

 //Read the output files for the No Constituent Subtractor Runs
 TFile *myfile = new TFile("/star/u/pna16/research/joboutput/joboutput_Mar31_NoSubtractor2GeV/output/mergedOutput_Mar31_NoSubtractor2GeV.root");
 if(myfile) { TDirectory *mydir = (TDirectory*)myfile->Get("AnMaker");
 } else { cout<<"myfile does not exist!"<<endl; return kTRUE; }

 //Get histograms from this data set. Change their pointers so as to not overlab with the constituent subtractor names
 TH1F* kHistEventCounterNoSub = (TH1F*)mydir->Get("fHistEventCounterNoSub");
 kHistEventCounterNoSub->SetName("kHistEventCounterNoSub");
 TH1F* kHistEventCounterIRNoSub = (TH1F*)mydir->Get("fHistEventCounterIR");
 kHistEventCounterIRNoSub->SetName("kHistEventCounterIRNoSub");
 TH1F* kHistEventCounterOORNoSub = (TH1F*)mydir->Get("fHistEventCounterOOR");
 kHistEventCounterOORNoSub->SetName("kHistEventCounterOORNoSub");
 TH1F* kHistBGSubPtSpectraIncNoSub = (TH1F*)mydir->Get("fHistBGSubPtSpectraInc");
 kHistBGSubPtSpectraIncNoSub->SetName("kHistBGSubPtSpectraIncNoSub");
 TH1F* kHistTrackConstitsPtNoSub = (TH1F*)mydir->Get("fHistConstitPt");
 kHistTrackConstitsPtNoSub->SetName("kHistTrackConstitsPtNoSub");
 TH1F* kHistAllTracksPtNoSub = (TH1F*)mydir->Get("fHistAllTracksPt");
 kHistAllTracksPtNoSub->SetName("kHistAllTracksPtNoSub");

 TH1F* kHistPtSpectraInclusiveNoSub = (TH1F*)mydir->Get("fHistPtSpectraInclusiveJet");
 kHistPtSpectraInclusiveNoSub->SetName("kHistPtSpectraInclusiveNoSub");
 TH1F* kHistPtSpectraARangeNoSub = (TH1F*)mydir->Get("fHistPtSpectraARange");
 kHistPtSpectraARangeNoSub->SetName("kHistPtSpectraARangeNoSub");
 TH1F* kHistPtSpectraBRangeNoSub = (TH1F*)mydir->Get("fHistPtSpectraBRange");
 kHistPtSpectraBRangeNoSub->SetName("kHistPtSpectraBRangeNoSub");
 TH1F* kHistPtSpectraCRangeNoSub = (TH1F*)mydir->Get("fHistPtSpectraCRange");
 kHistPtSpectraCRangeNoSub->SetName("kHistPtSpectraCRangeNoSub");

 TH1F* kHistAngularitySigNoSub = (TH1F*)mydir->Get("fHistAngularitySig");
 kHistAngularitySigNoSub->SetName("kHistAngularitySigNoSub");
 TH1F* kHistAngularityOORNoSub = (TH1F*)mydir->Get("fHistAngularityOOR");
 kHistAngularityOORNoSub->SetName("kHistAngularityOORNoSub");
 TH1F* kHistAngularityBGNoSub = (TH1F*)mydir->Get("fHistAngularityBG");
 kHistAngularityBGNoSub->SetName("kHistAngularityBGNoSub");
 TH1F* kHistAngularityBGOORNoSub = (TH1F*)mydir->Get("fHistAngularityBGOOR");
 kHistAngularityBGOORNoSub->SetName("kHistAngularityBGOORNoSub");

 TH1F* kHistAngularityDistanceSigNoSub = (TH1F*)mydir->Get("fHistAngularityDistanceSig");
 kHistAngularityDistanceSigNoSub->SetName("kHistAngularityDistanceSigNoSub");
 TH1F* kHistAngularityDistanceOORNoSub = (TH1F*)mydir->Get("fHistAngularityDistanceOOR");
 kHistAngularityDistanceOORNoSub->SetName("kHistAngularityDistanceOORNoSub");
 TH1F* kHistAngularityDistanceBGNoSub = (TH1F*)mydir->Get("fHistAngularityDistanceBG");
 kHistAngularityDistanceBGNoSub->SetName("kHistAngularityDistanceBGNoSub");
 TH1F* kHistAngularityDistanceBGOORNoSub = (TH1F*)mydir->Get("fHistAngularityDistanceBGOOR");
 kHistAngularityDistanceBGOORNoSub->SetName("kHistAngularityDistanceBGOORNoSub");

 TH1F* kHistPtDSigNoSub = (TH1F*)mydir->Get("fHistPtDSig");
 kHistPtDSigNoSub->SetName("kHistPtDSigNoSub");
 TH1F* kHistPtDOORNoSub = (TH1F*)mydir->Get("fHistPtDOOR");
 kHistPtDOORNoSub->SetName("kHistPtDOORNoSub");
 TH1F* kHistPtDBGNoSub = (TH1F*)mydir->Get("fHistPtDBG");
 kHistPtDBGNoSub->SetName("kHistPtDBGNoSub");
 TH1F* kHistPtDBGOORNoSub = (TH1F*)mydir->Get("fHistPtDBGOOR");
 kHistPtDBGOORNoSub->SetName("kHistPtDBGOORNoSub");
 TH1F* kHistPtD010CentNoSub = (TH1F*)mydir->Get("fHistPtD010Cent");
 kHistPtD010CentNoSub->SetName("kHistPtD010CentNoSub");
 TH1F* kHistPtD1030CentNoSub = (TH1F*)mydir->Get("fHistPtD1030Cent");
 kHistPtD1030CentNoSub->SetName("kHistPtD1030CentNoSub");
 TH1F* kHistPtD3080CentNoSub = (TH1F*)mydir->Get("fHistPtD3080Cent");
 kHistPtD3080CentNoSub->SetName("kHistPtD3080CentNoSub");

 
 TH1F* kHistLeSubSigNoSub = (TH1F*)mydir->Get("fHistLeSubSig");
 kHistLeSubSigNoSub->SetName("kHistLeSubSigNoSub");
 TH1F* kHistLeSubOORNoSub = (TH1F*)mydir->Get("fHistLeSubOOR");
 kHistLeSubOORNoSub->SetName("kHistLeSubOORNoSub");

 TH1F* kHistLeSubBGNoSub = (TH1F*)mydir->Get("fHistLeSubBG");
 kHistLeSubBGNoSub->SetName("kHistLeSubBGNoSub");
 TH1F* kHistLeSubBGOORNoSub = (TH1F*)mydir->Get("fHistLeSubBGOOR");
 kHistLeSubBGOORNoSub->SetName("kHistLeSubBGOORNoSub");

 //Histogram Arrays Declaration
 TH1F* kHistPtDNoSub[4][3][2];
 TH1F* kHistPtDPeaksNTracksNoSub[4][3][2];
 TH1F* kHistPtDPeaksPtTracksNoSub[4][3][2];

 TH1F* kHistNJetsCentBinsNoSub[4];

 TH1F* kHistPtDCentSelNoSub[4];
 TH1F* kHistLeSubCentSelNoSub[4];
 TH1F* kHistAngularityCentSelNoSub[4];

 TH1F* kHistNJetsArrNoSub[4][2][2];
 TH1F* kHistNEventsArrNoSub[4][2][2];

 TH1F* kHistLeSubArrSigNoSub[4][2][2];
 TH1F* kHistLeSubArrSig2TrackNoSub[4][2][2];
 TH1F* kHistLeSubArrBGNoSub[4][2][2];
 TH1F* kHistPtDArrSigNoSub[4][2][2];
 TH1F* kHistPtDArrBGNoSub[4][2][2];
 TH1F* kHistPtDArrSigBGNoSub[4][2][2];
 TH1F* kHistAngularityArrSigNoSub[4][2][2];
 TH1F* kHistAngularityArrBGNoSub[4][2][2];
 TH1F* kHistAngularityArrSigBGNoSub[4][2][2];

 //Begin looping through all histogram arrays
 for(int i = 0; i < 4; i++){
  kHistNJetsCentBinsNoSub[i] = (TH1F*)mydir->Get(Form("fHistNJetsCentBins_%i",i));
  kHistNJetsCentBinsNoSub[i]->SetName(Form("kHistNJetsCentBinsNoSub_%i",i));

  kHistPtDCentSelNoSub[i] = (TH1F*)mydir->Get(Form("fHistPtDCentSel_%i",i));
  kHistPtDCentSelNoSub[i]->SetName(Form("kHistPtDCentSelNoSub_%i",i));
  kHistLeSubCentSelNoSub[i] = (TH1F*)mydir->Get(Form("fHistLeSubCentSel_%i",i));
  kHistLeSubCentSelNoSub[i]->SetName(Form("kHistLeSubCentSelNoSub_%i",i));
  kHistAngularityCentSelNoSub[i] = (TH1F*)mydir->Get(Form("fHistAngularityCentSel_%i",i));
  kHistAngularityCentSelNoSub[i]->SetName(Form("kHistAngularityCentSelNoSub_%i",i));


  for(int j = 0; j < 3; j++){
   for(int k = 0; k < 2; k++){
    kHistPtDNoSub[i][j][k] = (TH1F*)mydir->Get(Form("fHistPtD_%i_%i_%i",i,j,k));
    kHistPtDPeaksNTracksNoSub[i][j][k] = (TH1F*)mydir->Get(Form("fHistPtDPeaksNTracks_%i_%i_%i",i,j,k));
    kHistPtDPeaksPtTracksNoSub[i][j][k] = (TH1F*)mydir->Get(Form("fHistPtDPeaksPtTracks_%i_%i_%i",i,j,k));

    kHistPtDNoSub[i][j][k]->SetName(Form("kHistPtDNoSub_%i_%i_%i",i,j,k));
    kHistPtDPeaksNTracksNoSub[i][j][k]->SetName(Form("kHistPtDPeaksNTracksNoSub_%i_%i_%i",i,j,k));
    kHistPtDPeaksPtTracksNoSub[i][j][k]->SetName(Form("kHistPtDPeaksPtTracksNoSub_%i_%i_%i",i,j,k));

    if(j == 0 || j == 1){
     kHistLeSubArrSigNoSub[i][j][k] = (TH1F*)mydir->Get(Form("fHistLeSubArrSig_%i_%i_%i",i,j,k));
     kHistLeSubArrSig2TrackNoSub[i][j][k] = (TH1F*)mydir->Get(Form("fHistLeSubArrSig2Track_%i_%i_%i",i,j,k));
     kHistLeSubArrBGNoSub[i][j][k] = (TH1F*)mydir->Get(Form("fHistLeSubArrBG_%i_%i_%i",i,j,k));

     kHistAngularityArrSigNoSub[i][j][k] = (TH1F*)mydir->Get(Form("fHistAngularityArrSig_%i_%i_%i",i,j,k));
     kHistAngularityArrBGNoSub[i][j][k] = (TH1F*)mydir->Get(Form("fHistAngularityArrBG_%i_%i_%i",i,j,k));
     kHistAngularityArrSigBGNoSub[i][j][k] = (TH1F*)mydir->Get(Form("fHistAngularityArrSigBG_%i_%i_%i",i,j,k));

     kHistPtDArrSigNoSub[i][j][k] = (TH1F*)mydir->Get(Form("fHistPtDArrSig_%i_%i_%i",i,j,k));
     kHistPtDArrBGNoSub[i][j][k] = (TH1F*)mydir->Get(Form("fHistPtDArrBG_%i_%i_%i",i,j,k));
     kHistPtDArrSigBGNoSub[i][j][k] = (TH1F*)mydir->Get(Form("fHistPtDArrSigBG_%i_%i_%i",i,j,k));

     kHistNJetsArrNoSub[i][j][k] = (TH1F*)mydir->Get(Form("fHistNJetsArr_%i_%i_%i",i,j,k));
     kHistNEventsArrNoSub[i][j][k] = (TH1F*)mydir->Get(Form("fHistNEventsArr_%i_%i_%i",i,j,k));

     kHistLeSubArrSigNoSub[i][j][k]->SetName(Form("kHistLeSubArrSigNoSub_%i_%i_%i",i,j,k));
     kHistLeSubArrSig2TrackNoSub[i][j][k]->SetName(Form("kHistLeSubArrSig2TrackNoSub_%i_%i_%i",i,j,k));
     kHistLeSubArrBGNoSub[i][j][k]->SetName(Form("kHistLeSubArrBGNoSub_%i_%i_%i",i,j,k));

     kHistAngularityArrSigNoSub[i][j][k]->SetName(Form("kHistAngularityArrSigNoSub_%i_%i_%i",i,j,k));
     kHistAngularityArrBGNoSub[i][j][k]->SetName(Form("kHistAngularityArrBGNoSub_%i_%i_%i",i,j,k));
     kHistAngularityArrSigBGNoSub[i][j][k]->SetName(Form("kHistAngularityArrSigBGNoSub_%i_%i_%i",i,j,k));
 
     kHistPtDArrSigNoSub[i][j][k]->SetName(Form("kHistPtDArrSigNoSub_%i_%i_%i",i,j,k));
     kHistPtDArrBGNoSub[i][j][k]->SetName(Form("kHistPtDArrBGNoSub_%i_%i_%i",i,j,k));
     kHistPtDArrSigBGNoSub[i][j][k]->SetName(Form("kHistPtDArrSigBGNoSub_%i_%i_%i",i,j,k));

     kHistNJetsArrNoSub[i][j][k]->SetName(Form("kHistNJetsArrNoSub_%i_%i_%i",i,j,k));
     kHistNEventsArrNoSub[i][j][k]->SetName(Form("kHistNEventsArrNoSub_%i_%i_%i",i,j,k));
    }
   }
  }
 } //End histogram array loop

 //Read the output files for the Constituent Subtractor Runs
 TFile *myfile2 = new TFile("/star/u/pna16/research/joboutput/joboutput_Mar31_Subtractor2GeV/output/mergedOutput_Mar31_Subtractor2GeV.root");
 if(myfile2) { TDirectory *mydir2 = (TDirectory*)myfile2->Get("AnMaker");
 } else { cout<<" DON'T HAVE FILE 2"<<endl; return kTRUE; }

 if(!mydir2) cout<<" i don't have directory 2"<<endl;

 //Get histograms from this data set. Change their pointers so as to not overlab with the non constituent subtractor names
 TH1F* kHistPtSpectraARangeSub = (TH1F*)mydir2->Get("fHistPtSpectraARange");
 kHistPtSpectraARangeSub->SetName("kHistPtSpectraARangeSub");
 TH1F* kHistPtSpectraBRangeSub = (TH1F*)mydir2->Get("fHistPtSpectraBRange");
 kHistPtSpectraBRangeSub->SetName("kHistPtSpectraBRangeSub");
 TH1F* kHistPtSpectraCRangeSub = (TH1F*)mydir2->Get("fHistPtSpectraCRange");
 kHistPtSpectraCRangeSub->SetName("kHistPtSpectraCRangeSub");
 TH1F* kHistBGSubPtSpectraIncSub = (TH1F*)mydir2->Get("fHistBGSubPtSpectraInc");
 kHistBGSubPtSpectraIncSub->SetName("kHistBGSubPtSpectraIncSub");
 TH1F* kHistTrackConstitsPtSub = (TH1F*)mydir2->Get("fHistSubConstitPt");
 kHistTrackConstitsPtSub->SetName("kHistTrackConstitsPtSub");
 TH1F* kHistAllTracksPtSub = (TH1F*)mydir2->Get("fHistAllTracksPt");
 kHistAllTracksPtSub->SetName("kHistAllTracksPtSub");


 TH1F* kHistEventCounterSub = (TH1F*)mydir2->Get("fHistEventCounterSub");
 kHistEventCounterSub->SetName("kHistEventCounterSub");
 TH1F* kHistEventCounterIRSub = (TH1F*)mydir2->Get("fHistEventCounterIR");
 kHistEventCounterIRSub->SetName("kHistEventCounterIRSub");
 TH1F* kHistEventCounterOORSub = (TH1F*)mydir2->Get("fHistEventCounterOOR");
 kHistEventCounterOORSub->SetName("kHistEventCounterOORSub");

 TH1F* kHistAngularitySigSub = (TH1F*)mydir2->Get("fHistAngularitySig");
 kHistAngularitySigSub->SetName("kHistAngularitySigSub");
 TH1F* kHistAngularityOORSub = (TH1F*)mydir2->Get("fHistAngularityOOR");
 kHistAngularityOORSub->SetName("kHistAngularityOORSub");

 TH1F* kHistPtDSigSub = (TH1F*)mydir2->Get("fHistPtDSig");
 kHistPtDSigSub->SetName("kHistPtDSigSub");
 TH1F* kHistPtDOORSub = (TH1F*)mydir2->Get("fHistPtDOOR");
 kHistPtDOORSub->SetName("kHistPtDOORSub");
 TH1F* kHistPtD010CentSub = (TH1F*)mydir2->Get("fHistPtD010Cent");
 kHistPtD010CentSub->SetName("kHistPtD010CentSub");
 TH1F* kHistPtD1030CentSub = (TH1F*)mydir2->Get("fHistPtD1030Cent");
 kHistPtD1030CentSub->SetName("kHistPtD1030CentSub");
 TH1F* kHistPtD3080CentSub = (TH1F*)mydir2->Get("fHistPtD3080Cent");
 kHistPtD3080CentSub->SetName("kHistPtD3080CentSub");


 TH1F* kHistLeSubSigSub = (TH1F*)mydir2->Get("fHistLeSubSig");
 kHistLeSubSigSub->SetName("kHistLeSubSigSub");
 TH1F* kHistLeSubOORSub = (TH1F*)mydir2->Get("fHistLeSubOOR");
 kHistLeSubOORSub->SetName("kHistLeSubOORSub");

 //Declare the histogram arrays
 TH1F* kHistPtDSub[4][3][2];
 TH1F* kHistPtDPeaksNTracksSub[4][3][2];
 TH1F* kHistPtDPeaksPtTracksSub[4][3][2];
 TH1F* kHistNJetsCentBinsSub[4];

 TH1F* kHistPtDCentSelSub[4];
 TH1F* kHistLeSubCentSelSub[4];
 TH1F* kHistAngularityCentSelSub[4];

 TH1F* kHistNJetsArrSub[4][2][2];
 TH1F* kHistNEventsArrSub[4][2][2];

 TH1F* kHistLeSubArrSigSub[4][2][2];
 TH1F* kHistLeSubArrSig2TrackSub[4][2][2];
 TH1F* kHistLeSubArrBGSub[4][2][2];
 TH1F* kHistPtDArrSigSub[4][2][2];
 TH1F* kHistPtDArrBGSub[4][2][2];
 TH1F* kHistAngularityArrSigSub[4][2][2];
 TH1F* kHistAngularityArrBGSub[4][2][2];

 //Loop through the histogram arrays and read them from the output files
 for(int i = 0; i < 4; i++){
  kHistNJetsCentBinsSub[i] = (TH1F*)mydir2->Get(Form("fHistNJetsCentBins_%i",i));
  kHistNJetsCentBinsSub[i]->SetName(Form("kHistNJetsCentBinsSub_%i",i));

  kHistPtDCentSelSub[i] = (TH1F*)mydir2->Get(Form("fHistPtDCentSel_%i",i));
  kHistPtDCentSelSub[i]->SetName(Form("kHistPtDCentSelSub_%i",i));
  kHistLeSubCentSelSub[i] = (TH1F*)mydir2->Get(Form("fHistLeSubCentSel_%i",i));
  kHistLeSubCentSelSub[i]->SetName(Form("kHistLeSubCentSelSub_%i",i));
  kHistAngularityCentSelSub[i] = (TH1F*)mydir2->Get(Form("fHistAngularityCentSel_%i",i));
  kHistAngularityCentSelSub[i]->SetName(Form("kHistAngularityCentSelSub_%i",i));

  for(int j = 0; j < 3; j++){
   for(int k = 0; k < 2; k++){
    kHistPtDSub[i][j][k] = (TH1F*)mydir2->Get(Form("fHistPtD_%i_%i_%i",i,j,k));
    kHistPtDPeaksNTracksSub[i][j][k] = (TH1F*)mydir2->Get(Form("fHistPtDPeaksNTracks_%i_%i_%i",i,j,k));
    kHistPtDPeaksPtTracksSub[i][j][k] = (TH1F*)mydir2->Get(Form("fHistPtDPeaksPtTracks_%i_%i_%i",i,j,k));

    kHistPtDSub[i][j][k]->SetName(Form("kHistPtDSub_%i_%i_%i",i,j,k));
    kHistPtDPeaksNTracksSub[i][j][k]->SetName(Form("kHistPtDPeaksNTracksSub_%i_%i_%i",i,j,k));
    kHistPtDPeaksPtTracksSub[i][j][k]->SetName(Form("kHistPtDPeaksPtTracksSub_%i_%i_%i",i,j,k));

    if(j == 0 || j == 1){
     kHistLeSubArrSigSub[i][j][k] = (TH1F*)mydir2->Get(Form("fHistLeSubArrSig_%i_%i_%i",i,j,k));
     kHistLeSubArrSig2TrackSub[i][j][k] = (TH1F*)mydir2->Get(Form("fHistLeSubArrSig2Track_%i_%i_%i",i,j,k));
     kHistLeSubArrBGSub[i][j][k] = (TH1F*)mydir2->Get(Form("fHistLeSubArrBG_%i_%i_%i",i,j,k));

     kHistAngularityArrSigSub[i][j][k] = (TH1F*)mydir2->Get(Form("fHistAngularityArrSig_%i_%i_%i",i,j,k));
     kHistAngularityArrBGSub[i][j][k] = (TH1F*)mydir2->Get(Form("fHistAngularityArrBG_%i_%i_%i",i,j,k));

     kHistPtDArrSigSub[i][j][k] = (TH1F*)mydir2->Get(Form("fHistPtDArrSig_%i_%i_%i",i,j,k));
     kHistPtDArrBGSub[i][j][k] = (TH1F*)mydir2->Get(Form("fHistPtDArrBG_%i_%i_%i",i,j,k));

     kHistNJetsArrSub[i][j][k] = (TH1F*)mydir2->Get(Form("fHistNJetsArr_%i_%i_%i",i,j,k));
     kHistNEventsArrSub[i][j][k] = (TH1F*)mydir->Get(Form("fHistNEventsArr_%i_%i_%i",i,j,k));

     kHistLeSubArrSigSub[i][j][k]->SetName(Form("kHistLeSubArrSigSub_%i_%i_%i",i,j,k));
     kHistLeSubArrSig2TrackSub[i][j][k]->SetName(Form("kHistLeSubArrSig2TrackSub_%i_%i_%i",i,j,k));
     kHistLeSubArrBGSub[i][j][k]->SetName(Form("kHistLeSubArrBGSub_%i_%i_%i",i,j,k));

     kHistAngularityArrSigSub[i][j][k]->SetName(Form("kHistAngularityArrSigSub_%i_%i_%i",i,j,k));
     kHistAngularityArrBGSub[i][j][k]->SetName(Form("kHistAngularityArrBGSub_%i_%i_%i",i,j,k));

     kHistPtDArrSigSub[i][j][k]->SetName(Form("kHistPtDArrSigSub_%i_%i_%i",i,j,k));
     kHistPtDArrBGSub[i][j][k]->SetName(Form("kHistPtDArrBGSub_%i_%i_%i",i,j,k));

     kHistNJetsArrSub[i][j][k]->SetName(Form("kHistNJetsArrSub_%i_%i_%i",i,j,k));
     kHistNEventsArrSub[i][j][k]->SetName(Form("kHistNEventsArrSub_%i_%i_%i",i,j,k));
    }
   }
  }
 }//End histogram array loop



 //Create any new histograms for further analysis
 //Further analysis i.e: Ratios, Manual Subtractions, etc.
 kHistEtaSubAngularityNoSub = new TH1F("fHistEtaSubAngularity","BG Sub Angularity (#eta sub);g",kHistAngularitySigNoSub->GetNbinsX(),0.0,kHistAngularitySigNoSub->GetXaxis()->GetXmax());
 kHistEtaSubPtDNoSub = new TH1F("fHistEtaSubPtD","BG Sub ptD (#eta sub);ptD",kHistPtDSigNoSub->GetNbinsX(),0.0,kHistPtDSigNoSub->GetXaxis()->GetXmax());
 kHistEtaSubLeSubNoSub =  new TH1F("fHistEtaSubLeSub","BG Sub LeSub (#eta sub);LeSub",kHistLeSubSigNoSub->GetNbinsX(),0.0,kHistLeSubSigNoSub->GetXaxis()->GetXmax());

 kHistPhiSubAngularityNoSub = new TH1F("fHistEtaSubAngularity","BG Sub Angularity (#phi sub);g",kHistAngularitySigNoSub->GetNbinsX(),0.0,kHistAngularitySigNoSub->GetXaxis()->GetXmax());
 kHistPhiSubPtDNoSub = new TH1F("fHistEtaSubPtD","BG Sub ptD (#phi sub);ptD",kHistPtDSigNoSub->GetNbinsX(),0.0,kHistPtDSigNoSub->GetXaxis()->GetXmax());
 kHistPhiSubLeSubNoSub =  new TH1F("fHistEtaSubLeSub","BG Sub LeSub (#phi sub);LeSub",kHistLeSubSigNoSub->GetNbinsX(),0.0,kHistLeSubSigNoSub->GetXaxis()->GetXmax());

 //9 ratio plots for the 9 indeces displayable on the 3x3 canvas I dedicate to these ratios
 TH1F* kHistLeSubCentCompNoSub[9];
 TH1F* kHistLeSubCentCompSub[9];
 TH1F* kHistPtDCentCompNoSub[9];
 TH1F* kHistPtDCentCompSub[9];
 TH1F* kHistAngularityCentCompNoSub[9];
 TH1F* kHistAngularityCentCompSub[9];

 //9 indeces on canvas, then furhter selections on jet eta and jet pt bins
 TH1F* kHistLeSubRatioNoSub[9][2][2];
 TH1F* kHistLeSubRatio2TrackNoSub[9][2][2];
 TH1F* kHistLeSubRatioSub[9][2][2];
 TH1F* kHistLeSubRatio2TrackSub[9][2][2];
 TH1F* kHistPtDRatioNoSub[9][2][2];
 TH1F* kHistPtDRatioSub[9][2][2];
 TH1F* kHistAngularityRatioNoSub[9][2][2];
 TH1F* kHistAngularityRatioSub[9][2][2];

 //9 indeces on canvas, then further selection on the jet pt bins. We merge the jet eta on these ones
 TH1F* kHistLeSubRatioEtaMergedNoSub[9][2];
 TH1F* kHistLeSubRatioEtaMerged2TrackNoSub[9][2];
 TH1F* kHistLeSubRatioEtaMergedSub[9][2];
 TH1F* kHistLeSubRatioEtaMerged2TrackSub[9][2];
 TH1F* kHistPtDRatioEtaMergedNoSub[9][2];
 TH1F* kHistPtDRatioEtaMergedSub[9][2];
 TH1F* kHistAngularityRatioEtaMergedNoSub[9][2];
 TH1F* kHistAngularityRatioEtaMergedSub[9][2];

 //Initialize the for analysis arrays we just created
 for(int i = 0; i < 9; i++){
  kHistLeSubCentCompNoSub[i] = new TH1F(Form("kHistLeSubCentCompNoSub_%i",i), Form("No Subtractor LeSubRatio %i",i),kHistLeSubSigNoSub->GetNbinsX(),0.0,kHistLeSubSigNoSub->GetXaxis()->GetXmax());
  kHistLeSubCentCompSub[i] = new TH1F(Form("kHistLeSubCentCompSub_%i",i), Form("Subtractor LeSubRatio %i",i),kHistLeSubSigNoSub->GetNbinsX(),0.0,kHistLeSubSigNoSub->GetXaxis()->GetXmax());

  kHistPtDCentCompNoSub[i] = new TH1F(Form("kHistPtDCentCompNoSub_%i",i), Form("No Subtractor ptDRatio %i",i),kHistPtDSigNoSub->GetNbinsX(),0.0,kHistPtDSigNoSub->GetXaxis()->GetXmax());
  kHistPtDCentCompSub[i] = new TH1F(Form("kHistPtDCentCompSub_%i",i), Form("Subtractor ptDRatio %i",i),kHistPtDSigNoSub->GetNbinsX(),0.0,kHistPtDSigNoSub->GetXaxis()->GetXmax());

  kHistAngularityCentCompNoSub[i] = new TH1F(Form("kHistAngularityCentCompNoSub_%i",i), Form("No Subtractor gRatio %i",i),kHistAngularitySigNoSub->GetNbinsX(),0.0,kHistAngularitySigNoSub->GetXaxis()->GetXmax());
  kHistAngularityCentCompSub[i] = new TH1F(Form("kHistAngularityCentCompSub_%i",i), Form("Subtractor gRatio %i",i),kHistAngularitySigNoSub->GetNbinsX(),0.0,kHistAngularitySigNoSub->GetXaxis()->GetXmax());

   for(int j = 0; j<2; j++){
     kHistLeSubRatioEtaMergedNoSub[i][j] = new TH1F(Form("kHistLeSubRatioEtaMergedNoSub_%i_%i",i,j), "Merged Eta Ratio Plot",kHistLeSubSigNoSub->GetNbinsX(),0.0,kHistLeSubSigNoSub->GetXaxis()->GetXmax());
     kHistLeSubRatioEtaMerged2TrackNoSub[i][j] = new TH1F(Form("kHistLeSubRatioEtaMerged2TrackNoSub_%i_%i",i,j), "Merged Eta Ratio Plot;LeSub;Ratio",kHistLeSubSigNoSub->GetNbinsX(),0.0,kHistLeSubSigNoSub->GetXaxis()->GetXmax());
     kHistLeSubRatioEtaMergedSub[i][j] = new TH1F(Form("kHistLeSubRatioEtaMergedSub_%i_%i",i,j), "Merged Eta Ratio Plot",kHistLeSubSigNoSub->GetNbinsX(),0.0,kHistLeSubSigNoSub->GetXaxis()->GetXmax());
     kHistLeSubRatioEtaMerged2TrackSub[i][j] = new TH1F(Form("kHistLeSubRatioEtaMerged2TrackSub_%i_%i",i,j), "Merged Eta Ratio Plot;LeSub;Ratio",kHistLeSubSigNoSub->GetNbinsX(),0.0,kHistLeSubSigNoSub->GetXaxis()->GetXmax());

     kHistPtDRatioEtaMergedNoSub[i][j] = new TH1F(Form("kHistPtDRatioEtaMergedNoSub_%i_%i",i,j), "Merged Eta Ratio Plot",kHistPtDArrSigNoSub[0][0][0]->GetNbinsX(),0.0,kHistPtDArrSigNoSub[0][0][0]->GetXaxis()->GetXmax());
     kHistPtDRatioEtaMergedSub[i][j] = new TH1F(Form("kHistPtDRatioEtaMergedSub_%i_%i",i,j), "Merged Eta Ratio Plot",kHistPtDArrSigNoSub[0][0][0]->GetNbinsX(),0.0,kHistPtDArrSigNoSub[0][0][0]->GetXaxis()->GetXmax());

     kHistAngularityRatioEtaMergedNoSub[i][j] = new TH1F(Form("kHistAngularityRatioEtaMergedNoSub_%i_%i",i,j), "Merged Eta Ratio Plot",kHistAngularitySigNoSub->GetNbinsX(),0.0,kHistAngularitySigNoSub->GetXaxis()->GetXmax());
     kHistAngularityRatioEtaMergedSub[i][j] = new TH1F(Form("kHistAngularityRatioEtaMergedSub_%i_%i",i,j), "Merged Eta Ratio Plot",kHistAngularitySigNoSub->GetNbinsX(),0.0,kHistAngularitySigNoSub->GetXaxis()->GetXmax());


     for(int k = 0; k<2; k++){
       kHistLeSubRatioNoSub[i][j][k] = new TH1F(Form("kHistLeSubRatioNoSub_%i_%i_%i",i,j,k), Form("No Subtractor LeSubRatio %i_%i_%i",i,j,k),kHistLeSubSigNoSub->GetNbinsX(),0.0,kHistLeSubSigNoSub->GetXaxis()->GetXmax());
       kHistLeSubRatio2TrackNoSub[i][j][k] = new TH1F(Form("kHistLeSubRatio2TrackNoSub_%i_%i_%i",i,j,k), Form("No Subtractor LeSubRatio %i_%i_%i;LeSub;Ratio",i,j,k),kHistLeSubSigNoSub->GetNbinsX(),0.0,kHistLeSubSigNoSub->GetXaxis()->GetXmax());
       kHistLeSubRatioSub[i][j][k] = new TH1F(Form("kHistLeSubRatioSub_%i_%i_%i",i,j,k), Form("Subtractor LeSubRatio %i_%i_%i",i,j,k),kHistLeSubSigNoSub->GetNbinsX(),0.0,kHistLeSubSigNoSub->GetXaxis()->GetXmax());
       kHistLeSubRatio2TrackSub[i][j][k] = new TH1F(Form("kHistLeSubRatio2TrackSub_%i_%i_%i",i,j,k), Form("No Subtractor LeSubRatio %i_%i_%i;LeSub;Ratio",i,j,k),kHistLeSubSigNoSub->GetNbinsX(),0.0,kHistLeSubSigNoSub->GetXaxis()->GetXmax());

       kHistPtDRatioNoSub[i][j][k] = new TH1F(Form("kHistPtDRatioNoSub_%i_%i,%i",i,j,k), Form("No Subtractor ptDRatio %i_%i_%i",i,j,k),kHistPtDArrSigNoSub[0][0][0]->GetNbinsX(),0.0,kHistPtDArrSigNoSub[0][0][0]->GetXaxis()->GetXmax());
       kHistPtDRatioSub[i][j][k] = new TH1F(Form("kHistPtDRatioSub_%i_%i_%i",i,j,k), Form("Subtractor ptDRatio %i_%i_%i",i,j,k),kHistPtDArrSigSub[0][0][0]->GetNbinsX(),0.0,kHistPtDArrSigSub[0][0][0]->GetXaxis()->GetXmax());

       kHistAngularityRatioNoSub[i][j][k] = new TH1F(Form("kHistAngularityRatioNoSub_%i_%i,%i",i,j,k), Form("No Subtractor gRatio %i_%i_%i",i,j,k),kHistAngularitySigNoSub->GetNbinsX(),0.0,kHistAngularitySigNoSub->GetXaxis()->GetXmax());
       kHistAngularityRatioSub[i][j][k] = new TH1F(Form("kHistAngularityRatioSub_%i_%i_%i",i,j,k), Form("Subtractor gRatio %i_%i_%i",i,j,k),kHistAngularitySigNoSub->GetNbinsX(),0.0,kHistAngularitySigNoSub->GetXaxis()->GetXmax());

     }
   }
 }

 //Acquire values on the nJet or nEvents necessary to make normalizations. These are specific to their scenarios
 double nJetsSub = kHistBGSubPtSpectraIncSub->GetEntries();
 double nJetsNoSub = kHistBGSubPtSpectraIncNoSub->GetEntries();
 double nJetsIR = kHistLeSubSigNoSub->GetEntries();
 double nJetsOOR = kHistLeSubOORNoSub->GetEntries();
 double nEventsIRNoSub = kHistEventCounterIRNoSub->GetEntries();
 double nEventsOORNoSub = kHistEventCounterOORNoSub->GetEntries();
 double nEventsNoSub = nEventsIRNoSub + nEventsOORNoSub;

 double nJetsIRSub = kHistLeSubSigSub->GetEntries();
 double nJetsOORSub = kHistLeSubOORSub->GetEntries();
 double nEventsIRSub = kHistEventCounterIRSub->GetEntries();
 double nEventsOORSub = kHistEventCounterOORSub->GetEntries();
 double nEventsSub = nEventsIRSub + nEventsOORSub;

 double nJetsCentNoSub[4];
 double nJetsCentSub[4];
 double nJetsArrNoSub[4][2][2]; //[Centrality] [Jet Pt] [IR or OOR]
 double nJetsArrSub[4][2][2]; //[Centrality] [Jet Pt] [IR or OOR]
 double nEventsArrNoSub[4][2][2];
 double nEventsArrSub[4][2][2];

 double ptDBinWidth = (kHistPtDArrSigSub[0][0][0]->GetXaxis()->GetXmax())/(kHistPtDArrSigSub[0][0][0]->GetNbinsX());
 double leSubBinWidth = (kHistLeSubArrSigSub[0][0][0]->GetXaxis()->GetXmax())/(kHistLeSubArrSigSub[0][0][0]->GetNbinsX());
 double gBinWidth = (kHistAngularityArrSigSub[0][0][0]->GetXaxis()->GetXmax())/(kHistAngularityArrSigSub[0][0][0]->GetNbinsX());

 //Fill nJets for specific selection bins
 for(int i = 0; i<4; i++){
  nJetsCentNoSub[i] = kHistNJetsCentBinsNoSub[i]->GetEntries();
  nJetsCentSub[i] = kHistNJetsCentBinsSub[i]->GetEntries(); 

  for(int j = 0; j<2; j++){
   for(int k = 0; k<2; k++){
    nJetsArrNoSub[i][j][k] = kHistNJetsArrNoSub[i][j][k]->GetEntries();
    nJetsArrSub[i][j][k] = kHistNJetsArrSub[i][j][k]->GetEntries();
    nEventsArrNoSub[i][j][k] = kHistNEventsArrNoSub[i][j][k]->GetEntries();
    nEventsArrSub[i][j][k] = kHistNEventsArrSub[i][j][k]->GetEntries();
   }
  }
 }

 //Display information for personal knowledge
 cout << "NEvents IR No Subtractor: " << nEventsIRNoSub << endl;
 cout << "NEvents OOR No Subtractor: " << nEventsOORNoSub << endl;
 cout << "NEvents IR Subtractor: " << nEventsIRSub << endl;
 cout << "NEvents OOR Subtractor: " << nEventsOORSub << endl;

 //Normalizing The Histograms
 
 //Non Constituent Subtractor
 kHistPtSpectraARangeNoSub->Scale(1/nEventsOORNoSub);
 kHistPtSpectraBRangeNoSub->Scale(1/nEventsIRNoSub);
 kHistPtSpectraCRangeNoSub->Scale(1/nEventsOORNoSub);
 
 kHistAngularitySigNoSub->Scale(1/(gBinWidth*nJetsIR));
 kHistAngularityOORNoSub->Scale(1/(gBinWidth*nJetsOOR));
 kHistAngularityBGNoSub->Scale(1/(gBinWidth*nJetsIR));
 kHistAngularityBGOORNoSub->Scale(1/(gBinWidth*nJetsOOR));

 kHistAngularityDistanceSigNoSub->Scale(1/nJetsIR);
 kHistAngularityDistanceOORNoSub->Scale(1/nJetsOOR);
 kHistAngularityDistanceBGNoSub->Scale(1/nJetsIR);
 kHistAngularityDistanceBGOORNoSub->Scale(1/nJetsOOR);

 kHistPtDSigNoSub->Scale(1/(ptDBinWidth*nJetsIR));
 kHistPtDOORNoSub->Scale(1/(ptDBinWidth*nJetsOOR));
 kHistPtDBGNoSub->Scale(1/(ptDBinWidth*nJetsIR));
 kHistPtDBGOORNoSub->Scale(1/(ptDBinWidth*nJetsOOR));

 kHistPtD010CentNoSub->Scale(1/(ptDBinWidth*nJetsCentNoSub[0]));
 kHistPtD1030CentNoSub->Scale(1/(ptDBinWidth*nJetsCentNoSub[1]));
 kHistPtD3080CentNoSub->Scale(1/(ptDBinWidth*(nJetsCentNoSub[4] + nJetsCentNoSub[3])));

 kHistLeSubSigNoSub->Scale(1/(leSubBinWidth*nJetsIR));
 kHistLeSubOORNoSub->Scale(1/(leSubBinWidth*nJetsOOR));
 kHistLeSubBGNoSub->Scale(1/(leSubBinWidth*nJetsIR));
 kHistLeSubBGOORNoSub->Scale(1/(leSubBinWidth*nJetsOOR));

 //Constituent Subtractor
 kHistPtD010CentSub->Scale(1/(nJetsCentSub[0]));
 kHistPtD1030CentSub->Scale(1/(nJetsCentSub[1]));
 kHistPtD3080CentSub->Scale(1/(nJetsCentSub[2] + nJetsCentSub[3]));
 
 kHistPtSpectraARangeSub->Scale(1/nEventsOORSub);
 kHistPtSpectraBRangeSub->Scale(1/nEventsIRSub);
 kHistPtSpectraCRangeSub->Scale(1/nEventsOORSub);
 
 kHistAngularitySigSub->Scale(1/(gBinWidth*nJetsIRSub));
 kHistAngularityOORSub->Scale(1/(gBinWidth*nJetsOORSub));
 kHistPtDSigSub->Scale(1/(ptDBinWidth*nJetsIRSub));
 kHistPtDOORSub->Scale(1/(ptDBinWidth*nJetsOORSub));
 kHistLeSubSigSub->Scale(1/(leSubBinWidth*nJetsIRSub));
 kHistLeSubOORSub->Scale(1/(leSubBinWidth*nJetsOORSub));

 //Stylings
 int subtractorColor = kGreen+2; //Default: shade of green
 int subtractorThickness = 3;
 int presubtractorColor = 53; //Default: shade of purple
 int presubtractorThickness = 2;
 int yoffset = 1.0;

 //Apply styling choices
 kHistBGSubPtSpectraIncNoSub->SetLineColor(presubtractorColor);
 kHistBGSubPtSpectraIncSub->SetLineColor(subtractorColor);
 kHistBGSubPtSpectraIncNoSub->SetLineWidth(presubtractorThickness);
 kHistBGSubPtSpectraIncSub->SetLineWidth(subtractorThickness);
 kHistBGSubPtSpectraIncNoSub->SetTitle("Background Subtracted Jet p_{T}'s;Corrected Jet pt;Counts");
 kHistBGSubPtSpectraIncSub->SetTitle("Background Subtracted Jet p_{T}'s;Corrected Jet pt;Counts");
 kHistBGSubPtSpectraIncNoSub->SetTitleOffset(yoffset,"y");
 kHistBGSubPtSpectraIncSub->SetTitleOffset(yoffset,"y");

 kHistTrackConstitsPtSub->SetLineColor(subtractorColor);
 kHistTrackConstitsPtSub->SetLineWidth(subtractorThickness);
 kHistTrackConstitsPtSub->SetTitle("Track Constituent p_{T}'s;Track p_{T};Counts");
 kHistTrackConstitsPtSub->SetTitleOffset(yoffset,"y");
 kHistTrackConstitsPtNoSub->SetLineColor(presubtractorColor);
 kHistTrackConstitsPtNoSub->SetLineWidth(presubtractorThickness);
 kHistTrackConstitsPtNoSub->SetTitle("Track Constituent p_{T}'s;Track p_{T};Counts");
 kHistTrackConstitsPtNoSub->SetTitleOffset(yoffset,"y");

 kHistAllTracksPtNoSub->SetLineColor(presubtractorColor);
 kHistAllTracksPtSub->SetLineColor(subtractorColor);
 kHistAllTracksPtNoSub->SetLineWidth(presubtractorThickness);
 kHistAllTracksPtSub->SetLineWidth(subtractorThickness);
 kHistAllTracksPtSub->SetTitle("All Track p_{T}'s;pt;Counts");
 kHistAllTracksPtSub->SetTitle("All Track p_{T}'s;pt;Counts");
 kHistAllTracksPtSub->SetTitleOffset(yoffset,"y");
 kHistAllTracksPtSub->SetTitleOffset(yoffset,"y");

 //Create labels to be displayed on the histograms
 TText *minTrackPtLabel = new TText();
 minTrackPtLabel->SetTextColor(1);
 minTrackPtLabel->SetTextFont(1);
 minTrackPtLabel->SetTextSize(0.1);
 minTrackPtLabel->SetTextAngle(0);

 //Inclusive Jet Pt Spectrum post background subtraction
 c56->cd(1);
 gPad->SetGrid(0,0);
 kHistBGSubPtSpectraIncSub->Scale(1/nJetsSub);
 kHistBGSubPtSpectraIncSub->SetYTitle("Counts/nJets");
 kHistBGSubPtSpectraIncSub->Draw();
 if(minTrackPt == 1.0)   minTrackPtLabel->DrawText(0.0,0.0,"track pt > 1.0 GeV");
 else if(minTrackPt == 2.0) minTrackPtLabel->DrawText(0.0,0.0,"track pt > 2.0 GeV");
 kHistBGSubPtSpectraIncNoSub->Scale(1/nJetsNoSub);
 kHistBGSubPtSpectraIncNoSub->Draw("SAME");

 //Inclusive track constituents pt subtraction
 c65->cd(1);
 gPad->SetGrid(0,0);
 kHistTrackConstitsPtSub->Scale(1/nJetsSub);
 kHistTrackConstitsPtSub->SetYTitle("Counts/nJets");
 kHistTrackConstitsPtSub->Draw();
 if(minTrackPt == 1.0)   minTrackPtLabel->DrawText(0.0,0.0,"track pt > 1.0 GeV");
 else if(minTrackPt == 2.0) minTrackPtLabel->DrawText(0.0,0.0,"track pt > 2.0 GeV");
 kHistTrackConstitsPtNoSub->Scale(1/nJetsNoSub);
 kHistTrackConstitsPtNoSub->Draw("SAME");

 //Spectra of all the track pt's in both the no sub and sub data sets
 c66->cd(1);
 gPad->SetGrid(0,0);
 kHistAllTracksPtSub->Scale(1/nEventsSub);
 kHistAllTracksPtSub->SetYTitle("Counts/nEvents");
 kHistAllTracksPtSub->Draw();
 if(minTrackPt == 1.0)   minTrackPtLabel->DrawText(0.0,0.0,"track pt > 1.0 GeV");
 else if(minTrackPt == 2.0) minTrackPtLabel->DrawText(0.0,0.0,"track pt > 2.0 GeV");
 kHistAllTracksPtNoSub->Scale(1/nEventsNoSub);
 kHistAllTracksPtNoSub->Draw("SAME");

 //More stylings
 kHistAngularitySigNoSub->SetYTitle("1/nJets 1/binWidth");
 kHistAngularityOORNoSub->SetYTitle("1/nJets 1/binWidth");
 kHistAngularityBGNoSub->SetYTitle("1/nJets 1/binWidth");
 kHistAngularityBGOORNoSub->SetYTitle("1/nJets 1/binWidth");
 kHistAngularitySigNoSub->SetTitleOffset(yoffset,"y");
 kHistAngularityOORNoSub->SetTitleOffset(yoffset,"y");
 kHistAngularityBGNoSub->SetTitleOffset(yoffset,"y");
 kHistAngularityBGOORNoSub->SetTitleOffset(yoffset,"y");
 kHistAngularitySigNoSub->SetLineWidth(presubtractorThickness);
 kHistAngularityOORNoSub->SetLineWidth(presubtractorThickness);
 kHistAngularityBGNoSub->SetLineWidth(presubtractorThickness);
 kHistAngularityBGOORNoSub->SetLineWidth(presubtractorThickness);
 kHistAngularitySigNoSub->SetLineColor(presubtractorColor);
 kHistAngularityOORNoSub->SetLineColor(presubtractorColor);
 kHistAngularityBGNoSub->SetLineColor(presubtractorColor);
 kHistAngularityBGOORNoSub->SetLineColor(presubtractorColor);

 kHistAngularityDistanceSigNoSub->SetYTitle("1/nJets 1/binWidth");
 kHistAngularityDistanceOORNoSub->SetYTitle("1/nJets 1/binWidth");
 kHistAngularityDistanceBGNoSub->SetYTitle("1/nJets 1/binWidth");
 kHistAngularityDistanceBGOORNoSub->SetYTitle("1/nJets 1/binWidth");
 kHistAngularityDistanceSigNoSub->SetTitleOffset(yoffset,"y");
 kHistAngularityDistanceOORNoSub->SetTitleOffset(yoffset,"y");
 kHistAngularityDistanceBGNoSub->SetTitleOffset(yoffset,"y");
 kHistAngularityDistanceBGOORNoSub->SetTitleOffset(yoffset,"y");
 kHistAngularityDistanceSigNoSub->SetLineWidth(presubtractorThickness);
 kHistAngularityDistanceOORNoSub->SetLineWidth(presubtractorThickness);
 kHistAngularityDistanceBGNoSub->SetLineWidth(presubtractorThickness);
 kHistAngularityDistanceBGOORNoSub->SetLineWidth(presubtractorThickness);
 kHistAngularityDistanceSigNoSub->SetLineColor(presubtractorColor);
 kHistAngularityDistanceOORNoSub->SetLineColor(presubtractorColor);
 kHistAngularityDistanceBGNoSub->SetLineColor(presubtractorColor);
 kHistAngularityDistanceBGOORNoSub->SetLineColor(presubtractorColor);

 kHistPtDSigNoSub->SetYTitle("1/nJets 1/binWidth");
 kHistPtDOORNoSub->SetYTitle("1/nJets 1/binWidth");
 kHistPtDBGNoSub->SetYTitle("1/nJets 1/binWidth");
 kHistPtDBGOORNoSub->SetYTitle("1/nJets 1/binWidth");
 kHistPtDSigNoSub->SetTitleOffset(yoffset,"y");
 kHistPtDOORNoSub->SetTitleOffset(yoffset,"y");
 kHistPtDBGNoSub->SetTitleOffset(yoffset,"y");
 kHistPtDBGOORNoSub->SetTitleOffset(yoffset,"y");
 kHistPtDSigNoSub->SetLineWidth(presubtractorThickness);
 kHistPtDOORNoSub->SetLineWidth(presubtractorThickness);
 kHistPtDBGNoSub->SetLineWidth(presubtractorThickness);
 kHistPtDBGOORNoSub->SetLineWidth(presubtractorThickness);
 kHistPtDSigNoSub->SetLineColor(presubtractorColor);
 kHistPtDOORNoSub->SetLineColor(presubtractorColor);
 kHistPtDBGNoSub->SetLineColor(presubtractorColor);
 kHistPtDBGOORNoSub->SetLineColor(presubtractorColor);

 kHistPtD010CentNoSub->SetYTitle("1/nJets 1/binWidth");
 kHistPtD1030CentNoSub->SetYTitle("1/nJets 1/binWidth");
 kHistPtD3080CentNoSub->SetYTitle("1/nJets 1/binWidth");
 kHistPtD010CentNoSub->SetTitleOffset(yoffset,"y");
 kHistPtD1030CentNoSub->SetTitleOffset(yoffset,"y");
 kHistPtD3080CentNoSub->SetTitleOffset(yoffset,"y");
 kHistPtD010CentNoSub->SetLineWidth(presubtractorThickness);
 kHistPtD1030CentNoSub->SetLineWidth(presubtractorThickness);
 kHistPtD3080CentNoSub->SetLineWidth(presubtractorThickness);
 kHistPtD010CentNoSub->SetLineColor(presubtractorColor);
 kHistPtD1030CentNoSub->SetLineColor(presubtractorColor);
 kHistPtD3080CentNoSub->SetLineColor(presubtractorColor);


 kHistLeSubSigNoSub->SetYTitle("1/nJets 1/binWidth");
 kHistLeSubOORNoSub->SetYTitle("1/nJets 1/binWidth");
 kHistLeSubBGNoSub->SetYTitle("1/nJets 1/binWidth");
 kHistLeSubBGOORNoSub->SetYTitle("1/nJets 1/binWidth");
 kHistLeSubSigNoSub->SetTitleOffset(yoffset,"y");
 kHistLeSubOORNoSub->SetTitleOffset(yoffset,"y");
 kHistLeSubBGNoSub->SetTitleOffset(yoffset,"y");
 kHistLeSubBGOORNoSub->SetTitleOffset(yoffset,"y");
 kHistLeSubSigNoSub->SetLineWidth(presubtractorThickness);
 kHistLeSubOORNoSub->SetLineWidth(presubtractorThickness);
 kHistLeSubBGNoSub->SetLineWidth(presubtractorThickness);
 kHistLeSubBGOORNoSub->SetLineWidth(presubtractorThickness);
 kHistLeSubSigNoSub->SetLineColor(presubtractorColor);
 kHistLeSubOORNoSub->SetLineColor(presubtractorColor);
 kHistLeSubBGNoSub->SetLineColor(presubtractorColor);
 kHistLeSubBGOORNoSub->SetLineColor(presubtractorColor);

 kHistPtSpectraARangeNoSub->SetTitle("Jet Pt Spectra |Jet #eta| > 0.3;p_{T};1/nEvents");
 kHistPtSpectraBRangeNoSub->SetTitle("Jet Pt Spectra |Jet #eta| < 0.3;p_{T};1/nEvents");
 kHistPtSpectraCRangeNoSub->SetTitle("Jet Pt Spectra |Jet #eta| > 0.3;p_{T};1/nEvents");
 kHistPtSpectraARangeNoSub->SetTitleOffset(yoffset,"y");
 kHistPtSpectraBRangeNoSub->SetTitleOffset(yoffset,"y");
 kHistPtSpectraCRangeNoSub->SetTitleOffset(yoffset,"y");
 kHistPtSpectraARangeNoSub->SetLineWidth(presubtractorThickness);
 kHistPtSpectraBRangeNoSub->SetLineWidth(presubtractorThickness);
 kHistPtSpectraCRangeNoSub->SetLineWidth(presubtractorThickness);
 kHistPtSpectraARangeNoSub->SetLineColor(presubtractorColor);
 kHistPtSpectraBRangeNoSub->SetLineColor(presubtractorColor);
 kHistPtSpectraCRangeNoSub->SetLineColor(presubtractorColor);

 kHistAngularitySigSub->SetYTitle("1/Jets 1/binWidth");
 kHistAngularityOORSub->SetYTitle("1/nJets 1/binWidth");
 kHistPtDSigSub->SetYTitle("1/nJets 1/binWidth");
 kHistPtDOORSub->SetYTitle("1/nJets 1/binWidth");
 kHistLeSubSigSub->SetYTitle("1/nJets 1/binWidth");
 kHistLeSubOORSub->SetYTitle("1/nJets 1/binWidth");
 kHistAngularitySigSub->SetTitleOffset(yoffset,"y");
 kHistAngularityOORSub->SetTitleOffset(yoffset,"y");
 kHistPtDSigSub->SetTitleOffset(yoffset,"y");
 kHistPtDOORSub->SetTitleOffset(yoffset,"y");
 kHistLeSubSigSub->SetTitleOffset(yoffset,"y");
 kHistLeSubOORSub->SetTitleOffset(yoffset,"y");
 kHistAngularitySigSub->SetLineWidth(subtractorThickness);
 kHistAngularityOORSub->SetLineWidth(subtractorThickness);
 kHistPtDSigSub->SetLineWidth(subtractorThickness);
 kHistPtDOORSub->SetLineWidth(subtractorThickness);
 kHistLeSubSigSub->SetLineWidth(subtractorThickness);
 kHistLeSubOORSub->SetLineWidth(subtractorThickness);
 kHistAngularitySigSub->SetLineColor(subtractorColor);
 kHistAngularityOORSub->SetLineColor(subtractorColor);
 kHistPtDSigSub->SetLineColor(subtractorColor);
 kHistPtDOORSub->SetLineColor(subtractorColor);
 kHistLeSubSigSub->SetLineColor(subtractorColor);
 kHistLeSubOORSub->SetLineColor(subtractorColor);

 kHistPtD010CentSub->SetYTitle("1/nJets 1/binWidth");
 kHistPtD1030CentSub->SetYTitle("1/nJets 1/binWidth");
 kHistPtD3080CentSub->SetYTitle("1/nJets 1/binWidth");
 kHistPtD010CentSub->SetTitleOffset(yoffset,"y");
 kHistPtD1030CentSub->SetTitleOffset(yoffset,"y");
 kHistPtD3080CentSub->SetTitleOffset(yoffset,"y");
 kHistPtD010CentSub->SetLineWidth(subtractorThickness);
 kHistPtD1030CentSub->SetLineWidth(subtractorThickness);
 kHistPtD3080CentSub->SetLineWidth(subtractorThickness);
 kHistPtD010CentSub->SetLineColor(subtractorColor);
 kHistPtD1030CentSub->SetLineColor(subtractorColor);
 kHistPtD3080CentSub->SetLineColor(subtractorColor);


 kHistPtSpectraARangeSub->SetTitle("Jet Pt Spectra |Jet #eta| > 0.3;p_{T};1/nEvents");
 kHistPtSpectraBRangeSub->SetTitle("Jet Pt Spectra |Jet #eta| < 0.3;p_{T};1/nEvents");
 kHistPtSpectraCRangeSub->SetTitle("Jet Pt Spectra |Jet #eta| > 0.3;p_{T};1/nEvents");
 kHistPtSpectraARangeSub->SetTitleOffset(yoffset,"y");
 kHistPtSpectraBRangeSub->SetTitleOffset(yoffset,"y");
 kHistPtSpectraCRangeSub->SetTitleOffset(yoffset,"y");
 kHistPtSpectraARangeSub->SetLineWidth(subtractorThickness);
 kHistPtSpectraBRangeSub->SetLineWidth(subtractorThickness);
 kHistPtSpectraCRangeSub->SetLineWidth(subtractorThickness);
 kHistPtSpectraARangeSub->SetLineColor(subtractorColor);
 kHistPtSpectraBRangeSub->SetLineColor(subtractorColor);
 kHistPtSpectraCRangeSub->SetLineColor(subtractorColor);

 //Arrays Styling and Normalizations
 for(int i = 0; i<4; i++){
  kHistPtDCentSelNoSub[i]->Scale(1/(ptDBinWidth*nJetsCentNoSub[i]));
  kHistLeSubCentSelNoSub[i]->Scale(1/(leSubBinWidth*nJetsCentNoSub[i]));
  kHistAngularityCentSelNoSub[i]->Scale(1/(gBinWidth*nJetsCentNoSub[i]));

  kHistPtDCentSelNoSub[i]->SetYTitle("1/nJets 1/binWidth");
  kHistLeSubCentSelNoSub[i]->SetYTitle("1/nJets 1/binWidth");
  kHistAngularityCentSelNoSub[i]->SetYTitle("1/nJets 1/binWidth");

  kHistPtDCentSelNoSub[i]->SetLineWidth(presubtractorThickness);
  kHistLeSubCentSelNoSub[i]->SetLineWidth(presubtractorThickness);
  kHistAngularityCentSelNoSub[i]->SetLineWidth(presubtractorThickness);

  kHistPtDCentSelNoSub[i]->SetLineColor(presubtractorColor);
  kHistLeSubCentSelNoSub[i]->SetLineColor(presubtractorColor);
  kHistAngularityCentSelNoSub[i]->SetLineColor(presubtractorColor);

  kHistPtDCentSelSub[i]->Scale(1/(ptDBinWidth*nJetsCentSub[i]));
  kHistLeSubCentSelSub[i]->Scale(1/(leSubBinWidth*nJetsCentSub[i]));
  kHistAngularityCentSelSub[i]->Scale(1/(gBinWidth*nJetsCentSub[i]));

  kHistPtDCentSelSub[i]->SetYTitle("1/nJets 1/binWidth");
  kHistLeSubCentSelSub[i]->SetYTitle("1/nJets 1/binWidth");
  kHistAngularityCentSelSub[i]->SetYTitle("1/nJets 1/binWidth");

  kHistPtDCentSelSub[i]->SetLineWidth(subtractorThickness);
  kHistLeSubCentSelSub[i]->SetLineWidth(subtractorThickness);
  kHistAngularityCentSelSub[i]->SetLineWidth(subtractorThickness);

  kHistPtDCentSelSub[i]->SetLineColor(subtractorColor);
  kHistLeSubCentSelSub[i]->SetLineColor(subtractorColor);
  kHistAngularityCentSelSub[i]->SetLineColor(subtractorColor);


  for(int j = 0; j<3; j++){
   for(int k = 0; k<2; k++){
    //No Sub
    kHistPtDNoSub[i][j][k]->Scale(1/(ptDBinWidth*nJetsCentNoSub[i]));
    kHistPtDPeaksNTracksNoSub[i][j][k]->Scale(1/nJetsCentNoSub[i]);
    kHistPtDPeaksPtTracksNoSub[i][j][k]->Scale(1/nJetsCentNoSub[i]);
    kHistPtDNoSub[i][j][k]->SetYTitle("1/nJets 1/binWidth");
    kHistPtDPeaksNTracksNoSub[i][j][k]->SetYTitle("1/nJets 1/binWidth");
    kHistPtDPeaksPtTracksNoSub[i][j][k]->SetYTitle("1/nJets 1/binWidth");
    kHistPtDNoSub[i][j][k]->SetTitleOffset(yoffset,"y");
    kHistPtDPeaksNTracksNoSub[i][j][k]->SetTitleOffset(yoffset,"y");
    kHistPtDPeaksPtTracksNoSub[i][j][k]->SetTitleOffset(yoffset,"y");
    kHistPtDNoSub[i][j][k]->SetLineWidth(presubtractorThickness);
    kHistPtDPeaksNTracksNoSub[i][j][k]->SetLineWidth(presubtractorThickness);
    kHistPtDPeaksPtTracksNoSub[i][j][k]->SetLineWidth(presubtractorThickness);
    kHistPtDNoSub[i][j][k]->SetLineColor(presubtractorColor);
    kHistPtDPeaksNTracksNoSub[i][j][k]->SetLineColor(presubtractorColor);
    kHistPtDPeaksPtTracksNoSub[i][j][k]->SetLineColor(presubtractorColor);
    
    if(j == 0 || j == 1){
     kHistLeSubArrSigNoSub[i][j][k]->Scale(1/(leSubBinWidth*nJetsArrNoSub[i][j][k]));
     kHistLeSubArrBGNoSub[i][j][k]->Scale(1/(leSubBinWidth*nJetsArrNoSub[i][j][k]));
     kHistLeSubArrSig2TrackNoSub[i][j][k]->Scale(1/(leSubBinWidth*nJetsArrNoSub[i][j][k]));
     kHistAngularityArrSigNoSub[i][j][k]->Scale(1/(gBinWidth*nJetsArrNoSub[i][j][k]));
     kHistAngularityArrBGNoSub[i][j][k]->Scale(1/(gBinWidth*nJetsArrNoSub[i][j][k]));
     kHistAngularityArrSigBGNoSub[i][j][k]->Scale(1/(gBinWidth*nJetsArrNoSub[i][j][k]));
     kHistPtDArrSigNoSub[i][j][k]->Scale(1/(ptDBinWidth*nJetsArrNoSub[i][j][k]));
     kHistPtDArrBGNoSub[i][j][k]->Scale(1/(ptDBinWidth*nJetsArrNoSub[i][j][k]));
     kHistPtDArrSigBGNoSub[i][j][k]->Scale(1/(ptDBinWidth*nJetsArrNoSub[i][j][k]));

     kHistLeSubArrSigNoSub[i][j][k]->SetTitleOffset(yoffset,"y");
     kHistLeSubArrBGNoSub[i][j][k]->SetTitleOffset(yoffset,"y");
     kHistLeSubArrSig2TrackNoSub[i][j][k]->SetTitleOffset(yoffset,"y");
     kHistAngularityArrSigNoSub[i][j][k]->SetTitleOffset(yoffset,"y");
     kHistAngularityArrBGNoSub[i][j][k]->SetTitleOffset(yoffset,"y");
     kHistAngularityArrSigBGNoSub[i][j][k]->SetTitleOffset(yoffset,"y");
     kHistPtDArrSigNoSub[i][j][k]->SetTitleOffset(yoffset,"y");
     kHistPtDArrBGNoSub[i][j][k]->SetTitleOffset(yoffset,"y");
     kHistPtDArrSigBGNoSub[i][j][k]->SetTitleOffset(yoffset,"y");

     kHistLeSubArrSigNoSub[i][j][k]->SetLineWidth(presubtractorThickness);
     kHistLeSubArrBGNoSub[i][j][k]->SetLineWidth(presubtractorThickness);
     kHistLeSubArrSig2TrackNoSub[i][j][k]->SetLineWidth(presubtractorThickness);
     kHistAngularityArrSigNoSub[i][j][k]->SetLineWidth(presubtractorThickness);
     kHistAngularityArrBGNoSub[i][j][k]->SetLineWidth(presubtractorThickness);
     kHistAngularityArrSigBGNoSub[i][j][k]->SetLineWidth(presubtractorThickness);
     kHistPtDArrSigNoSub[i][j][k]->SetLineWidth(presubtractorThickness);
     kHistPtDArrBGNoSub[i][j][k]->SetLineWidth(presubtractorThickness);
     kHistPtDArrSigBGNoSub[i][j][k]->SetLineWidth(presubtractorThickness);

     kHistLeSubArrSigNoSub[i][j][k]->SetLineColor(presubtractorColor);
     kHistLeSubArrBGNoSub[i][j][k]->SetLineColor(presubtractorColor);
     kHistLeSubArrSig2TrackNoSub[i][j][k]->SetLineColor(presubtractorColor);
     kHistAngularityArrSigNoSub[i][j][k]->SetLineColor(presubtractorColor);
     kHistAngularityArrBGNoSub[i][j][k]->SetLineColor(presubtractorColor);
     kHistAngularityArrSigBGNoSub[i][j][k]->SetLineColor(presubtractorColor);
     kHistPtDArrSigNoSub[i][j][k]->SetLineColor(presubtractorColor);
     kHistPtDArrBGNoSub[i][j][k]->SetLineColor(presubtractorColor);
     kHistPtDArrSigBGNoSub[i][j][k]->SetLineColor(presubtractorColor);

    }
    
    //Sub
    kHistPtDSub[i][j][k]->Scale(1/(ptDBinWidth*nJetsCentSub[i]));
    kHistPtDPeaksNTracksSub[i][j][k]->Scale(1/nJetsCentSub[i]);
    kHistPtDPeaksPtTracksSub[i][j][k]->Scale(1/nJetsCentSub[i]);
    kHistPtDSub[i][j][k]->SetYTitle("1/nJets 1/binWidth");
    kHistPtDPeaksNTracksSub[i][j][k]->SetYTitle("1/nJets");
    kHistPtDPeaksPtTracksSub[i][j][k]->SetYTitle("1/nJets");
    kHistPtDSub[i][j][k]->SetTitleOffset(yoffset,"y");
    kHistPtDPeaksNTracksSub[i][j][k]->SetTitleOffset(yoffset,"y");
    kHistPtDPeaksPtTracksSub[i][j][k]->SetTitleOffset(yoffset,"y");
    kHistPtDSub[i][j][k]->SetLineWidth(subtractorThickness);
    kHistPtDPeaksNTracksSub[i][j][k]->SetLineWidth(subtractorThickness);
    kHistPtDPeaksPtTracksSub[i][j][k]->SetLineWidth(subtractorThickness);
    kHistPtDSub[i][j][k]->SetLineColor(subtractorColor);
    kHistPtDPeaksNTracksSub[i][j][k]->SetLineColor(subtractorColor);
    kHistPtDPeaksPtTracksSub[i][j][k]->SetLineColor(subtractorColor);

    if(j == 0 || j == 1){
     kHistLeSubArrSigSub[i][j][k]->Scale(1/(leSubBinWidth*nJetsArrSub[i][j][k]));
     kHistLeSubArrSig2TrackSub[i][j][k]->Scale(1/(leSubBinWidth*nJetsArrSub[i][j][k]));
     kHistLeSubArrBGSub[i][j][k]->Scale(1/(leSubBinWidth*nJetsArrSub[i][j][k]));
     kHistAngularityArrSigSub[i][j][k]->Scale(1/(gBinWidth*nJetsArrSub[i][j][k]));
     kHistAngularityArrBGSub[i][j][k]->Scale(1/(gBinWidth*nJetsArrSub[i][j][k]));
     kHistPtDArrSigSub[i][j][k]->Scale(1/(ptDBinWidth*nJetsArrSub[i][j][k]));
     kHistPtDArrBGSub[i][j][k]->Scale(1/(ptDBinWidth*nJetsArrSub[i][j][k]));

     kHistLeSubArrSigSub[i][j][k]->SetTitleOffset(yoffset,"y");
     kHistLeSubArrSig2TrackSub[i][j][k]->SetTitleOffset(yoffset,"y");
     kHistLeSubArrBGSub[i][j][k]->SetTitleOffset(yoffset,"y");
     kHistAngularityArrSigSub[i][j][k]->SetTitleOffset(yoffset,"y");
     kHistAngularityArrBGSub[i][j][k]->SetTitleOffset(yoffset,"y");
     kHistPtDArrSigSub[i][j][k]->SetTitleOffset(yoffset,"y");
     kHistPtDArrBGSub[i][j][k]->SetTitleOffset(yoffset,"y");

     kHistLeSubArrSigSub[i][j][k]->SetLineWidth(subtractorThickness);
     kHistLeSubArrSig2TrackSub[i][j][k]->SetLineWidth(subtractorThickness);
     kHistLeSubArrBGSub[i][j][k]->SetLineWidth(subtractorThickness);
     kHistAngularityArrSigSub[i][j][k]->SetLineWidth(subtractorThickness);
     kHistAngularityArrBGSub[i][j][k]->SetLineWidth(subtractorThickness);
     kHistPtDArrSigSub[i][j][k]->SetLineWidth(subtractorThickness);
     kHistPtDArrBGSub[i][j][k]->SetLineWidth(subtractorThickness);

     kHistLeSubArrSigSub[i][j][k]->SetLineColor(subtractorColor);
     kHistLeSubArrSig2TrackSub[i][j][k]->SetLineColor(subtractorColor);
     kHistLeSubArrBGSub[i][j][k]->SetLineColor(subtractorColor);
     kHistAngularityArrSigSub[i][j][k]->SetLineColor(subtractorColor);
     kHistAngularityArrBGSub[i][j][k]->SetLineColor(subtractorColor);
     kHistPtDArrSigSub[i][j][k]->SetLineColor(subtractorColor);
     kHistPtDArrBGSub[i][j][k]->SetLineColor(subtractorColor);
    }

   }
  }
 }


 //Declare histogram arrays for Background manual subtraction
 TH1F* kHistLeSubArrBGManSub[4][2][2];
 TH1F* kHistPtDArrBGManSub[4][2][2];
 TH1F* kHistAngularityArrBGManSub[4][2][2];
 
 TH1F* kHistLeSubArrMergedEtaNoSub[4][2][2];
 TH1F* kHistLeSubArrMergedEta2TrackNoSub[4][2][2];
 TH1F* kHistPtDArrMergedEtaNoSub[4][2][2];
 TH1F* kHistAngularityArrMergedEtaNoSub[4][2][2];

 TH1F* kHistLeSubArrMergedEtaSub[4][2][2];
 TH1F* kHistLeSubArrMergedEta2TrackSub[4][2][2];
 TH1F* kHistPtDArrMergedEtaSub[4][2][2];
 TH1F* kHistAngularityArrMergedEtaSub[4][2][2];

 //Run calculations for the NOT per jet manual subtraction. This method isn't very useful
 //Also a merging of the Eta Bins
 for(int i = 0; i<4; i++){
  for(int j = 0; j<2; j++){
   for(int k = 0; k<2; k++){
    TH1F* kHistLeSubArrSigClone = (TH1F*)kHistLeSubArrSigNoSub[i][j][k]->Clone();
    TH1F* kHistPtDArrSigClone = (TH1F*)kHistPtDArrSigNoSub[i][j][k]->Clone();
    TH1F* kHistAngularityArrSigClone = (TH1F*)kHistAngularityArrSigBGNoSub[i][j][k]->Clone();

    kHistLeSubArrBGManSub[i][j][k] = kHistLeSubArrSigClone;
    kHistPtDArrBGManSub[i][j][k] = kHistPtDArrSigClone;
    kHistAngularityArrBGManSub[i][j][k] = kHistAngularityArrSigClone;

    kHistLeSubArrBGManSub[i][j][k]->Add(kHistLeSubArrBGNoSub[i][j][k],-1);
    kHistPtDArrBGManSub[i][j][k]->Add(kHistPtDArrBGNoSub[i][j][k],-1);
    kHistAngularityArrBGManSub[i][j][k]->Add(kHistAngularityArrBGNoSub[i][j][k],-1);

    kHistLeSubArrBGManSub[i][j][k]->SetTitle("Manual BG Sub LeSub;LeSub;1/nJets 1/binWidth");
    kHistPtDArrBGManSub[i][j][k]->SetTitle("Manual BG Sub PtD;PtD;1/nJets 1/binWidth");
    kHistAngularityArrBGManSub[i][j][k]->SetTitle("Manual BG Sub g;g;1/nJets 1/binWidth");

    
    //eta bin merge
    TH1F* kHistLeSubArrNoSubClone = (TH1F*)kHistLeSubArrSigNoSub[i][j][k]->Clone();
    TH1F* kHistLeSubArrSig2TrackNoSubClone = (TH1F*)kHistLeSubArrSig2TrackNoSub[i][j][k]->Clone();
    TH1F* kHistPtDArrNoSubClone = (TH1F*)kHistPtDArrSigNoSub[i][j][k]->Clone();
    TH1F* kHistAngularityArrNoSubClone = (TH1F*)kHistAngularityArrSigNoSub[i][j][k]->Clone();

    TH1F* kHistLeSubArrSubClone = (TH1F*)kHistLeSubArrSigSub[i][j][k]->Clone();
    TH1F* kHistLeSubArrSig2TrackSubClone = (TH1F*)kHistLeSubArrSig2TrackSub[i][j][k]->Clone();
    TH1F* kHistPtDArrSubClone = (TH1F*)kHistPtDArrSigSub[i][j][k]->Clone();
    TH1F* kHistAngularityArrSubClone = (TH1F*)kHistAngularityArrSigSub[i][j][k]->Clone();

    kHistLeSubArrMergedEtaNoSub[i][j][k] = kHistLeSubArrNoSubClone;
    kHistLeSubArrMergedEta2TrackNoSub[i][j][k] = kHistLeSubArrSig2TrackNoSubClone;
    kHistPtDArrMergedEtaNoSub[i][j][k] = kHistPtDArrNoSubClone;
    kHistAngularityArrMergedEtaNoSub[i][j][k] = kHistAngularityArrNoSubClone;
 
    kHistLeSubArrMergedEtaSub[i][j][k] = kHistLeSubArrSubClone;
    kHistLeSubArrMergedEta2TrackSub[i][j][k] = kHistLeSubArrSig2TrackSubClone;
    kHistPtDArrMergedEtaSub[i][j][k] = kHistPtDArrSubClone;
    kHistAngularityArrMergedEtaSub[i][j][k] = kHistAngularityArrSubClone;

   }
  }
 }

 //Merge the eta bins for the three variables
 kHistLeSubArrMergedEtaNoSub[0][0][0]->Add(kHistLeSubArrSigNoSub[0][0][1],1);
 kHistLeSubArrMergedEtaNoSub[1][0][0]->Add(kHistLeSubArrSigNoSub[1][0][1],1);
 kHistLeSubArrMergedEtaNoSub[2][0][0]->Add(kHistLeSubArrSigNoSub[2][0][1],1);
 kHistLeSubArrMergedEtaNoSub[3][0][0]->Add(kHistLeSubArrSigNoSub[3][0][1],1);
 kHistLeSubArrMergedEtaNoSub[0][1][0]->Add(kHistLeSubArrSigNoSub[0][1][1],1);
 kHistLeSubArrMergedEtaNoSub[1][1][0]->Add(kHistLeSubArrSigNoSub[1][1][1],1);
 kHistLeSubArrMergedEtaNoSub[2][1][0]->Add(kHistLeSubArrSigNoSub[2][1][1],1);
 kHistLeSubArrMergedEtaNoSub[3][1][0]->Add(kHistLeSubArrSigNoSub[3][1][1],1);

 kHistLeSubArrMergedEta2TrackNoSub[0][0][0]->Add(kHistLeSubArrSig2TrackNoSub[0][0][1],1);
 kHistLeSubArrMergedEta2TrackNoSub[1][0][0]->Add(kHistLeSubArrSig2TrackNoSub[1][0][1],1);
 kHistLeSubArrMergedEta2TrackNoSub[2][0][0]->Add(kHistLeSubArrSig2TrackNoSub[2][0][1],1);
 kHistLeSubArrMergedEta2TrackNoSub[3][0][0]->Add(kHistLeSubArrSig2TrackNoSub[3][0][1],1);
 kHistLeSubArrMergedEta2TrackNoSub[0][1][0]->Add(kHistLeSubArrSig2TrackNoSub[0][1][1],1);
 kHistLeSubArrMergedEta2TrackNoSub[1][1][0]->Add(kHistLeSubArrSig2TrackNoSub[1][1][1],1);
 kHistLeSubArrMergedEta2TrackNoSub[2][1][0]->Add(kHistLeSubArrSig2TrackNoSub[2][1][1],1);
 kHistLeSubArrMergedEta2TrackNoSub[3][1][0]->Add(kHistLeSubArrSig2TrackNoSub[3][1][1],1);


 kHistLeSubArrMergedEtaSub[0][0][0]->Add(kHistLeSubArrSigSub[0][0][1],1);
 kHistLeSubArrMergedEtaSub[1][0][0]->Add(kHistLeSubArrSigSub[1][0][1],1);
 kHistLeSubArrMergedEtaSub[2][0][0]->Add(kHistLeSubArrSigSub[2][0][1],1);
 kHistLeSubArrMergedEtaSub[3][0][0]->Add(kHistLeSubArrSigSub[3][0][1],1);
 kHistLeSubArrMergedEtaSub[0][1][0]->Add(kHistLeSubArrSigSub[0][1][1],1);
 kHistLeSubArrMergedEtaSub[1][1][0]->Add(kHistLeSubArrSigSub[1][1][1],1);
 kHistLeSubArrMergedEtaSub[2][1][0]->Add(kHistLeSubArrSigSub[2][1][1],1);
 kHistLeSubArrMergedEtaSub[3][1][0]->Add(kHistLeSubArrSigSub[3][1][1],1);

 kHistLeSubArrMergedEta2TrackSub[0][0][0]->Add(kHistLeSubArrSig2TrackSub[0][0][1],1);
 kHistLeSubArrMergedEta2TrackSub[1][0][0]->Add(kHistLeSubArrSig2TrackSub[1][0][1],1);
 kHistLeSubArrMergedEta2TrackSub[2][0][0]->Add(kHistLeSubArrSig2TrackSub[2][0][1],1);
 kHistLeSubArrMergedEta2TrackSub[3][0][0]->Add(kHistLeSubArrSig2TrackSub[3][0][1],1);
 kHistLeSubArrMergedEta2TrackSub[0][1][0]->Add(kHistLeSubArrSig2TrackSub[0][1][1],1);
 kHistLeSubArrMergedEta2TrackSub[1][1][0]->Add(kHistLeSubArrSig2TrackSub[1][1][1],1);
 kHistLeSubArrMergedEta2TrackSub[2][1][0]->Add(kHistLeSubArrSig2TrackSub[2][1][1],1);
 kHistLeSubArrMergedEta2TrackSub[3][1][0]->Add(kHistLeSubArrSig2TrackSub[3][1][1],1);


 kHistPtDArrMergedEtaNoSub[0][0][0]->Add(kHistPtDArrSigNoSub[0][0][1],1);
 kHistPtDArrMergedEtaNoSub[1][0][0]->Add(kHistPtDArrSigNoSub[1][0][1],1);
 kHistPtDArrMergedEtaNoSub[2][0][0]->Add(kHistPtDArrSigNoSub[2][0][1],1);
 kHistPtDArrMergedEtaNoSub[3][0][0]->Add(kHistPtDArrSigNoSub[3][0][1],1);
 kHistPtDArrMergedEtaNoSub[0][1][0]->Add(kHistPtDArrSigNoSub[0][1][1],1);
 kHistPtDArrMergedEtaNoSub[1][1][0]->Add(kHistPtDArrSigNoSub[1][1][1],1);
 kHistPtDArrMergedEtaNoSub[2][1][0]->Add(kHistPtDArrSigNoSub[2][1][1],1);
 kHistPtDArrMergedEtaNoSub[3][1][0]->Add(kHistPtDArrSigNoSub[3][1][1],1);

 kHistPtDArrMergedEtaSub[0][0][0]->Add(kHistPtDArrSigSub[0][0][1],1);
 kHistPtDArrMergedEtaSub[1][0][0]->Add(kHistPtDArrSigSub[1][0][1],1);
 kHistPtDArrMergedEtaSub[2][0][0]->Add(kHistPtDArrSigSub[2][0][1],1);
 kHistPtDArrMergedEtaSub[3][0][0]->Add(kHistPtDArrSigSub[3][0][1],1);
 kHistPtDArrMergedEtaSub[0][1][0]->Add(kHistPtDArrSigSub[0][1][1],1);
 kHistPtDArrMergedEtaSub[1][1][0]->Add(kHistPtDArrSigSub[1][1][1],1);
 kHistPtDArrMergedEtaSub[2][1][0]->Add(kHistPtDArrSigSub[2][1][1],1);
 kHistPtDArrMergedEtaSub[3][1][0]->Add(kHistPtDArrSigSub[3][1][1],1);

 kHistAngularityArrMergedEtaNoSub[0][0][0]->Add(kHistAngularityArrSigNoSub[0][0][1],1);
 kHistAngularityArrMergedEtaNoSub[1][0][0]->Add(kHistAngularityArrSigNoSub[1][0][1],1);
 kHistAngularityArrMergedEtaNoSub[2][0][0]->Add(kHistAngularityArrSigNoSub[2][0][1],1);
 kHistAngularityArrMergedEtaNoSub[3][0][0]->Add(kHistAngularityArrSigNoSub[3][0][1],1);
 kHistAngularityArrMergedEtaNoSub[0][1][0]->Add(kHistAngularityArrSigNoSub[0][1][1],1);
 kHistAngularityArrMergedEtaNoSub[1][1][0]->Add(kHistAngularityArrSigNoSub[1][1][1],1);
 kHistAngularityArrMergedEtaNoSub[2][1][0]->Add(kHistAngularityArrSigNoSub[2][1][1],1);
 kHistAngularityArrMergedEtaNoSub[3][1][0]->Add(kHistAngularityArrSigNoSub[3][1][1],1);

 kHistAngularityArrMergedEtaSub[0][0][0]->Add(kHistAngularityArrSigSub[0][0][1],1);
 kHistAngularityArrMergedEtaSub[1][0][0]->Add(kHistAngularityArrSigSub[1][0][1],1);
 kHistAngularityArrMergedEtaSub[2][0][0]->Add(kHistAngularityArrSigSub[2][0][1],1);
 kHistAngularityArrMergedEtaSub[3][0][0]->Add(kHistAngularityArrSigSub[3][0][1],1);
 kHistAngularityArrMergedEtaSub[0][1][0]->Add(kHistAngularityArrSigSub[0][1][1],1);
 kHistAngularityArrMergedEtaSub[1][1][0]->Add(kHistAngularityArrSigSub[1][1][1],1);
 kHistAngularityArrMergedEtaSub[2][1][0]->Add(kHistAngularityArrSigSub[2][1][1],1);
 kHistAngularityArrMergedEtaSub[3][1][0]->Add(kHistAngularityArrSigSub[3][1][1],1);

 //Stylize and also fill the ratio histograms accordingly
 for(int i = 0; i<9; i++){
  kHistLeSubCentCompNoSub[i]->SetLineWidth(presubtractorThickness);
  kHistLeSubCentCompSub[i]->SetLineWidth(subtractorThickness);
  kHistPtDCentCompNoSub[i]->SetLineWidth(presubtractorThickness);
  kHistPtDCentCompSub[i]->SetLineWidth(subtractorThickness);
  kHistAngularityCentCompNoSub[i]->SetLineWidth(presubtractorThickness);
  kHistAngularityCentCompSub[i]->SetLineWidth(subtractorThickness);

  kHistLeSubCentCompNoSub[i]->SetLineColor(presubtractorColor);
  kHistLeSubCentCompSub[i]->SetLineColor(subtractorColor);
  kHistPtDCentCompNoSub[i]->SetLineColor(presubtractorColor);
  kHistPtDCentCompSub[i]->SetLineColor(subtractorColor);
  kHistAngularityCentCompNoSub[i]->SetLineColor(presubtractorColor);
  kHistAngularityCentCompSub[i]->SetLineColor(subtractorColor);

  if(i==0){
   kHistLeSubCentCompNoSub[i]->Divide(kHistLeSubCentSelNoSub[0],kHistLeSubCentSelNoSub[1],1.0,1.0,"");
   kHistLeSubCentCompSub[i]->Divide(kHistLeSubCentSelSub[0],kHistLeSubCentSelSub[1],1.0,1.0,"");
   kHistPtDCentCompNoSub[i]->Divide(kHistPtDCentSelNoSub[0],kHistPtDCentSelNoSub[1],1.0,1.0,"");
   kHistPtDCentCompSub[i]->Divide(kHistPtDCentSelSub[0],kHistPtDCentSelSub[1],1.0,1.0,"");
   kHistAngularityCentCompNoSub[i]->Divide(kHistAngularityCentSelNoSub[0],kHistAngularityCentSelNoSub[1],1.0,1.0,"");
   kHistAngularityCentCompSub[i]->Divide(kHistAngularityCentSelSub[0],kHistAngularityCentSelSub[1],1.0,1.0,"");

   kHistLeSubCentCompNoSub[i]->SetTitle("(0-10 Cent)/(10-30 Cent) LeSub Ratio;(0/10%)/(10-30%);Ratio");
   kHistLeSubCentCompSub[i]->SetTitle("(0-10 Cent)/(10-30 Cent) LeSub Ratio;(0/10%)/(10-30%);Ratio");
   kHistPtDCentCompNoSub[i]->SetTitle("(0-10 Cent)/(10-30 Cent) ptD Ratio;(0/10%)/(10-30%);Ratio");
   kHistPtDCentCompSub[i]->SetTitle("(0-10 Cent)/(10-30 Cent) ptD Ratio;(0/10%)/(10-30%);Ratio");
   kHistAngularityCentCompNoSub[i]->SetTitle("(0-10 Cent)/(10-30 Cent) g Ratio;(0/10%)/(10-30%);Ratio");
   kHistAngularityCentCompSub[i]->SetTitle("(0-10 Cent)/(10-30 Cent) g Ratio;(0/10%)/(10-30%);Ratio");

  }
  else if(i==1){
   kHistLeSubCentCompNoSub[i]->Divide(kHistLeSubCentSelNoSub[0],kHistLeSubCentSelNoSub[2],1.0,1.0,"");
   kHistLeSubCentCompSub[i]->Divide(kHistLeSubCentSelSub[0],kHistLeSubCentSelSub[2],1.0,1.0,"");
   kHistPtDCentCompNoSub[i]->Divide(kHistPtDCentSelNoSub[0],kHistPtDCentSelNoSub[2],1.0,1.0,"");
   kHistPtDCentCompSub[i]->Divide(kHistPtDCentSelSub[0],kHistPtDCentSelSub[2],1.0,1.0,"");
   kHistAngularityCentCompNoSub[i]->Divide(kHistAngularityCentSelNoSub[0],kHistAngularityCentSelNoSub[2],1.0,1.0,"");
   kHistAngularityCentCompSub[i]->Divide(kHistAngularityCentSelSub[0],kHistAngularityCentSelSub[2],1.0,1.0,"");

   kHistLeSubCentCompNoSub[i]->SetTitle("(0-10 Cent)/(30-50 Cent) LeSub Ratio;(0/10%)/(30-50%);Ratio");
   kHistLeSubCentCompSub[i]->SetTitle("(0-10 Cent)/(30-50 Cent) LeSub Ratio;(0/10%)/(30-50%);Ratio");
   kHistPtDCentCompNoSub[i]->SetTitle("(0-10 Cent)/(30-50 Cent) ptD Ratio;(0/10%)/(30-50%);Ratio");
   kHistPtDCentCompSub[i]->SetTitle("(0-10 Cent)/(30-50 Cent) ptD Ratio;(0/10%)/(30-50%);Ratio");
   kHistAngularityCentCompNoSub[i]->SetTitle("(0-10 Cent)/(30-50 Cent) g Ratio;(0/10%)/(30-50%);Ratio");
   kHistAngularityCentCompSub[i]->SetTitle("(0-10 Cent)/(30-50 Cent) g Ratio;(0/10%)/(30-50%);Ratio");

 }
 else if(i==2){
   kHistLeSubCentCompNoSub[i]->Divide(kHistLeSubCentSelNoSub[0],kHistLeSubCentSelNoSub[3],1.0,1.0,"");
   kHistLeSubCentCompSub[i]->Divide(kHistLeSubCentSelSub[0],kHistLeSubCentSelSub[3],1.0,1.0,"");
   kHistPtDCentCompNoSub[i]->Divide(kHistPtDCentSelNoSub[0],kHistPtDCentSelNoSub[3],1.0,1.0,"");
   kHistPtDCentCompSub[i]->Divide(kHistPtDCentSelSub[0],kHistPtDCentSelSub[3],1.0,1.0,"");
   kHistAngularityCentCompNoSub[i]->Divide(kHistAngularityCentSelNoSub[0],kHistAngularityCentSelNoSub[3],1.0,1.0,"");
   kHistAngularityCentCompSub[i]->Divide(kHistAngularityCentSelSub[0],kHistAngularityCentSelSub[3],1.0,1.0,"");

   kHistLeSubCentCompNoSub[i]->SetTitle("(0-10 Cent)/(50-80 Cent) LeSub Ratio;(0/10%)/(50-80%);Ratio");
   kHistLeSubCentCompSub[i]->SetTitle("(0-10 Cent)/(50-80 Cent) LeSub Ratio;(0/10%)/(50-80%);Ratio");
   kHistPtDCentCompNoSub[i]->SetTitle("(0-10 Cent)/(50-80 Cent) ptD Ratio;(0/10%)/(50-80%);Ratio");
   kHistPtDCentCompSub[i]->SetTitle("(0-10 Cent)/(50-80 Cent) ptD Ratio;(0/10%)/(50-80%);Ratio");
   kHistAngularityCentCompNoSub[i]->SetTitle("(0-10 Cent)/(50-80 Cent) g Ratio;(0/10%)/(50-80%);Ratio");
   kHistAngularityCentCompSub[i]->SetTitle("(0-10 Cent)/(50-80 Cent) g Ratio;(0/10%)/(50-80%);Ratio");

  }
 else if(i==4){
   kHistLeSubCentCompNoSub[i]->Divide(kHistLeSubCentSelNoSub[1],kHistLeSubCentSelNoSub[2],1.0,1.0,"");
   kHistLeSubCentCompSub[i]->Divide(kHistLeSubCentSelSub[1],kHistLeSubCentSelSub[2],1.0,1.0,"");
   kHistPtDCentCompNoSub[i]->Divide(kHistPtDCentSelNoSub[1],kHistPtDCentSelNoSub[2],1.0,1.0,"");
   kHistPtDCentCompSub[i]->Divide(kHistPtDCentSelSub[1],kHistPtDCentSelSub[2],1.0,1.0,"");
   kHistAngularityCentCompNoSub[i]->Divide(kHistAngularityCentSelNoSub[1],kHistAngularityCentSelNoSub[2],1.0,1.0,"");
   kHistAngularityCentCompSub[i]->Divide(kHistAngularityCentSelSub[1],kHistAngularityCentSelSub[2],1.0,1.0,"");

   kHistLeSubCentCompNoSub[i]->SetTitle("(10-30 Cent)/(30-50 Cent) LeSub Ratio;(10/30%)/(30-50%);Ratio");
   kHistLeSubCentCompSub[i]->SetTitle("(10-30 Cent)/(30-50 Cent) LeSub Ratio;(10/30%)/(30-50%);Ratio");
   kHistPtDCentCompNoSub[i]->SetTitle("(10-30 Cent)/(30-50 Cent) ptD Ratio;(10/30%)/(30-50%);Ratio");
   kHistPtDCentCompSub[i]->SetTitle("(10-30 Cent)/(30-50 Cent) ptD Ratio;(10/30%)/(30-50%);Ratio");
   kHistAngularityCentCompNoSub[i]->SetTitle("(10-30 Cent)/(30-50 Cent) g Ratio;(10/30%)/(30-50%);Ratio");
   kHistAngularityCentCompSub[i]->SetTitle("(10-30 Cent)/(30-50 Cent) g Ratio;(10/30%)/(30-50%);Ratio");

 }
 else if(i==5){
   kHistLeSubCentCompNoSub[i]->Divide(kHistLeSubCentSelNoSub[1],kHistLeSubCentSelNoSub[3],1.0,1.0,"");
   kHistLeSubCentCompSub[i]->Divide(kHistLeSubCentSelSub[1],kHistLeSubCentSelSub[3],1.0,1.0,"");
   kHistPtDCentCompNoSub[i]->Divide(kHistPtDCentSelNoSub[1],kHistPtDCentSelNoSub[3],1.0,1.0,"");
   kHistPtDCentCompSub[i]->Divide(kHistPtDCentSelSub[1],kHistPtDCentSelSub[3],1.0,1.0,"");
   kHistAngularityCentCompNoSub[i]->Divide(kHistAngularityCentSelNoSub[1],kHistAngularityCentSelNoSub[3],1.0,1.0,"");
   kHistAngularityCentCompSub[i]->Divide(kHistAngularityCentSelSub[1],kHistAngularityCentSelSub[3],1.0,1.0,"");

   kHistLeSubCentCompNoSub[i]->SetTitle("(10-30 Cent)/(50-80 Cent) LeSub Ratio;(10/30%)/(50-80%);Ratio");
   kHistLeSubCentCompSub[i]->SetTitle("(10-30 Cent)/(50-80 Cent) LeSub Ratio;(10/30%)/(50-80%);Ratio");
   kHistPtDCentCompNoSub[i]->SetTitle("(10-30 Cent)/(50-80 Cent) ptD Ratio;(10/30%)/(50-80%);Ratio");
   kHistPtDCentCompSub[i]->SetTitle("(10-30 Cent)/(50-80 Cent) ptD Ratio;(10/30%)/(50-80%);Ratio");
   kHistAngularityCentCompNoSub[i]->SetTitle("(10-30 Cent)/(50-80 Cent) g Ratio;(10/30%)/(50-80%);Ratio");
   kHistAngularityCentCompSub[i]->SetTitle("(10-30 Cent)/(50-80 Cent) g Ratio;(10/30%)/(50-80%);Ratio");

  }
 else if(i==8){
   kHistLeSubCentCompNoSub[i]->Divide(kHistLeSubCentSelNoSub[2],kHistLeSubCentSelNoSub[3],1.0,1.0,"");
   kHistLeSubCentCompSub[i]->Divide(kHistLeSubCentSelSub[2],kHistLeSubCentSelSub[3],1.0,1.0,"");
   kHistPtDCentCompNoSub[i]->Divide(kHistPtDCentSelNoSub[2],kHistPtDCentSelNoSub[3],1.0,1.0,"");
   kHistPtDCentCompSub[i]->Divide(kHistPtDCentSelSub[2],kHistPtDCentSelSub[3],1.0,1.0,"");
   kHistAngularityCentCompNoSub[i]->Divide(kHistAngularityCentSelNoSub[2],kHistAngularityCentSelNoSub[3],1.0,1.0,"");
   kHistAngularityCentCompSub[i]->Divide(kHistAngularityCentSelSub[2],kHistAngularityCentSelSub[3],1.0,1.0,"");

   kHistLeSubCentCompNoSub[i]->SetTitle("(30-50 Cent)/(50-80 Cent) LeSub Ratio;(30/50%)/(50-80%);Ratio");
   kHistLeSubCentCompSub[i]->SetTitle("(30-50 Cent)/(50-80 Cent) LeSub Ratio;(30/50%)/(50-80%);Ratio");
   kHistPtDCentCompNoSub[i]->SetTitle("(30-50 Cent)/(50-80 Cent) ptD Ratio;(30/50%)/(50-80%);Ratio");
   kHistPtDCentCompSub[i]->SetTitle("(30-50 Cent)/(50-80 Cent) ptD Ratio;(30/50%)/(50-80%);Ratio");
   kHistAngularityCentCompNoSub[i]->SetTitle("(30-50 Cent)/(50-80 Cent) g Ratio;(30/50%)/(50-80%);Ratio");
   kHistAngularityCentCompSub[i]->SetTitle("(30-50 Cent)/(50-80 Cent) g Ratio;(30/50%)/(50-80%);Ratio");

  }
  //Merged eta ratios styling and filling
  for(int j = 0; j<2; j++){
   kHistLeSubRatioEtaMergedNoSub[i][j]->SetLineWidth(presubtractorThickness);
   kHistLeSubRatioEtaMerged2TrackNoSub[i][j]->SetLineWidth(presubtractorThickness);
   kHistLeSubRatioEtaMergedSub[i][j]->SetLineWidth(subtractorThickness);
   kHistLeSubRatioEtaMerged2TrackSub[i][j]->SetLineWidth(subtractorThickness);
   kHistPtDRatioEtaMergedNoSub[i][j]->SetLineWidth(presubtractorThickness);
   kHistPtDRatioEtaMergedSub[i][j]->SetLineWidth(subtractorThickness);
   kHistAngularityRatioEtaMergedNoSub[i][j]->SetLineWidth(presubtractorThickness);
   kHistAngularityRatioEtaMergedSub[i][j]->SetLineWidth(subtractorThickness);

   kHistLeSubRatioEtaMergedNoSub[i][j]->SetLineColor(presubtractorColor);
   kHistLeSubRatioEtaMerged2TrackNoSub[i][j]->SetLineColor(presubtractorColor);
   kHistLeSubRatioEtaMergedSub[i][j]->SetLineColor(subtractorColor);
   kHistLeSubRatioEtaMerged2TrackSub[i][j]->SetLineColor(subtractorColor);
   kHistPtDRatioEtaMergedNoSub[i][j]->SetLineColor(presubtractorColor);
   kHistPtDRatioEtaMergedSub[i][j]->SetLineColor(subtractorColor);
   kHistAngularityRatioEtaMergedNoSub[i][j]->SetLineColor(presubtractorColor);
   kHistAngularityRatioEtaMergedSub[i][j]->SetLineColor(subtractorColor);
   
   if(i==0){
    kHistLeSubRatioEtaMergedNoSub[i][j]->Divide(kHistLeSubArrMergedEtaNoSub[0][j][0],kHistLeSubArrMergedEtaNoSub[1][j][0],1.0,1.0,"");
    kHistLeSubRatioEtaMergedSub[i][j]->Divide(kHistLeSubArrMergedEtaSub[0][j][0],kHistLeSubArrMergedEtaSub[1][j][0],1.0,1.0,"");
    kHistLeSubRatioEtaMerged2TrackNoSub[i][j]->Divide(kHistLeSubArrMergedEta2TrackNoSub[0][j][0],kHistLeSubArrMergedEta2TrackNoSub[1][j][0],1.0,1.0,"");
    kHistLeSubRatioEtaMerged2TrackSub[i][j]->Divide(kHistLeSubArrMergedEta2TrackSub[0][j][0],kHistLeSubArrMergedEta2TrackSub[1][j][0],1.0,1.0,"");
    kHistPtDRatioEtaMergedNoSub[i][j]->Divide(kHistPtDArrMergedEtaNoSub[0][j][0],kHistPtDArrMergedEtaNoSub[1][j][0],1.0,1.0,"");
    kHistPtDRatioEtaMergedSub[i][j]->Divide(kHistPtDArrMergedEtaSub[0][j][0],kHistPtDArrMergedEtaSub[1][j][0],1.0,1.0,"");
    kHistAngularityRatioEtaMergedNoSub[i][j]->Divide(kHistAngularityArrMergedEtaNoSub[0][j][0],kHistAngularityArrMergedEtaNoSub[1][j][0],1.0,1.0,"");
    kHistAngularityRatioEtaMergedSub[i][j]->Divide(kHistAngularityArrMergedEtaSub[0][j][0],kHistAngularityArrMergedEtaSub[1][j][0],1.0,1.0,"");

    kHistLeSubRatioEtaMergedNoSub[i][j]->SetTitle(Form("(0-10%)/(10-30%) LeSub Ratio (Pt Bin %i);LeSub;Ratio",j));
    kHistLeSubRatioEtaMergedSub[i][j]->SetTitle(Form("(0-10%)/(10-30%) LeSub Ratio (Pt Bin %i);LeSub;Ratio",j));
    kHistPtDRatioEtaMergedNoSub[i][j]->SetTitle(Form("(0-10%)/(10-30%) ptD Ratio (Pt Bin %i);ptD;Ratio",j));
    kHistPtDRatioEtaMergedSub[i][j]->SetTitle(Form("(0-10%)/(10-30%) ptD Ratio (Pt Bin %i);ptD;Ratio",j));
    kHistAngularityRatioEtaMergedNoSub[i][j]->SetTitle(Form("(0-10%)/(10-30%) g Ratio (Pt Bin %i);g;Ratio",j));
    kHistAngularityRatioEtaMergedSub[i][j]->SetTitle(Form("(0-10%)/(10-30%) g Ratio (Pt Bin %i);g;Ratio",j));
   }
   
   if(i==1){
    kHistLeSubRatioEtaMergedNoSub[i][j]->Divide(kHistLeSubArrMergedEtaNoSub[0][j][0],kHistLeSubArrMergedEtaNoSub[2][j][0],1.0,1.0,"");
    kHistLeSubRatioEtaMergedSub[i][j]->Divide(kHistLeSubArrMergedEtaSub[0][j][0],kHistLeSubArrMergedEtaSub[2][j][0],1.0,1.0,"");
    kHistLeSubRatioEtaMerged2TrackNoSub[i][j]->Divide(kHistLeSubArrMergedEta2TrackNoSub[0][j][0],kHistLeSubArrMergedEta2TrackNoSub[2][j][0],1.0,1.0,"");
    kHistLeSubRatioEtaMerged2TrackSub[i][j]->Divide(kHistLeSubArrMergedEta2TrackSub[0][j][0],kHistLeSubArrMergedEta2TrackSub[2][j][0],1.0,1.0,"");
    kHistPtDRatioEtaMergedNoSub[i][j]->Divide(kHistPtDArrMergedEtaNoSub[0][j][0],kHistPtDArrMergedEtaNoSub[2][j][0],1.0,1.0,"");
    kHistPtDRatioEtaMergedSub[i][j]->Divide(kHistPtDArrMergedEtaSub[0][j][0],kHistPtDArrMergedEtaSub[2][j][0],1.0,1.0,"");
    kHistAngularityRatioEtaMergedNoSub[i][j]->Divide(kHistAngularityArrMergedEtaNoSub[0][j][0],kHistAngularityArrMergedEtaNoSub[2][j][0],1.0,1.0,"");
    kHistAngularityRatioEtaMergedSub[i][j]->Divide(kHistAngularityArrMergedEtaSub[0][j][0],kHistAngularityArrMergedEtaSub[2][j][0],1.0,1.0,"");

    kHistLeSubRatioEtaMergedNoSub[i][j]->SetTitle(Form("(0-10%)/(30-50%) LeSub Ratio (Pt Bin %i);LeSub;Ratio",j));
    kHistLeSubRatioEtaMergedSub[i][j]->SetTitle(Form("(0-10%)/(30-50%) LeSub Ratio (Pt Bin %i);LeSub;Ratio",j));
    kHistPtDRatioEtaMergedNoSub[i][j]->SetTitle(Form("(0-10%)/(30-50%) ptD Ratio (Pt Bin %i);ptD;Ratio",j));
    kHistPtDRatioEtaMergedSub[i][j]->SetTitle(Form("(0-10%)/(30-50%) ptD Ratio (Pt Bin %i);ptD;Ratio",j));
    kHistAngularityRatioEtaMergedNoSub[i][j]->SetTitle(Form("(0-10%)/(30-50%) g Ratio (Pt Bin %i);g;Ratio",j));
    kHistAngularityRatioEtaMergedSub[i][j]->SetTitle(Form("(0-10%)/(30-50%) g Ratio (Pt Bin %i);g;Ratio",j));
   }
 
   if(i==2){
    kHistLeSubRatioEtaMergedNoSub[i][j]->Divide(kHistLeSubArrMergedEtaNoSub[0][j][0],kHistLeSubArrMergedEtaNoSub[3][j][0],1.0,1.0,"");
    kHistLeSubRatioEtaMergedSub[i][j]->Divide(kHistLeSubArrMergedEtaSub[0][j][0],kHistLeSubArrMergedEtaSub[3][j][0],1.0,1.0,"");
    kHistLeSubRatioEtaMerged2TrackNoSub[i][j]->Divide(kHistLeSubArrMergedEta2TrackNoSub[0][j][0],kHistLeSubArrMergedEta2TrackNoSub[3][j][0],1.0,1.0,"");
    kHistLeSubRatioEtaMerged2TrackSub[i][j]->Divide(kHistLeSubArrMergedEta2TrackSub[0][j][0],kHistLeSubArrMergedEta2TrackSub[3][j][0],1.0,1.0,"");
    kHistPtDRatioEtaMergedNoSub[i][j]->Divide(kHistPtDArrMergedEtaNoSub[0][j][0],kHistPtDArrMergedEtaNoSub[3][j][0],1.0,1.0,"");
    kHistPtDRatioEtaMergedSub[i][j]->Divide(kHistPtDArrMergedEtaSub[0][j][0],kHistPtDArrMergedEtaSub[3][j][0],1.0,1.0,"");
    kHistAngularityRatioEtaMergedNoSub[i][j]->Divide(kHistAngularityArrMergedEtaNoSub[0][j][0],kHistAngularityArrMergedEtaNoSub[3][j][0],1.0,1.0,"");
    kHistAngularityRatioEtaMergedSub[i][j]->Divide(kHistAngularityArrMergedEtaSub[0][j][0],kHistAngularityArrMergedEtaSub[3][j][0],1.0,1.0,"");

    kHistLeSubRatioEtaMergedNoSub[i][j]->SetTitle(Form("(0-10%)/(50-80%) LeSub Ratio (Pt Bin %i);LeSub;Ratio",j));
    kHistLeSubRatioEtaMergedSub[i][j]->SetTitle(Form("(0-10%)/(50-80%) LeSub Ratio (Pt Bin %i);LeSub;Ratio",j));
    kHistPtDRatioEtaMergedNoSub[i][j]->SetTitle(Form("(0-10%)/(50-80%) ptD Ratio (Pt Bin %i);ptD;Ratio",j));
    kHistPtDRatioEtaMergedSub[i][j]->SetTitle(Form("(0-10%)/(50-80%) ptD Ratio (Pt Bin %i);ptD;Ratio",j));
    kHistAngularityRatioEtaMergedNoSub[i][j]->SetTitle(Form("(0-10%)/(50-80%) g Ratio (Pt Bin %i);g;Ratio",j));
    kHistAngularityRatioEtaMergedSub[i][j]->SetTitle(Form("(0-10%)/(50-80%) g Ratio (Pt Bin %i);g;Ratio",j));
   }

   if(i==4){
    kHistLeSubRatioEtaMergedNoSub[i][j]->Divide(kHistLeSubArrMergedEtaNoSub[1][j][0],kHistLeSubArrMergedEtaNoSub[2][j][0],1.0,1.0,"");
    kHistLeSubRatioEtaMergedSub[i][j]->Divide(kHistLeSubArrMergedEtaSub[1][j][0],kHistLeSubArrMergedEtaSub[2][j][0],1.0,1.0,"");
    kHistLeSubRatioEtaMerged2TrackNoSub[i][j]->Divide(kHistLeSubArrMergedEta2TrackNoSub[1][j][0],kHistLeSubArrMergedEta2TrackNoSub[2][j][0],1.0,1.0,"");
    kHistLeSubRatioEtaMerged2TrackSub[i][j]->Divide(kHistLeSubArrMergedEta2TrackSub[1][j][0],kHistLeSubArrMergedEta2TrackSub[2][j][0],1.0,1.0,"");
    kHistPtDRatioEtaMergedNoSub[i][j]->Divide(kHistPtDArrMergedEtaNoSub[1][j][0],kHistPtDArrMergedEtaNoSub[2][j][0],1.0,1.0,"");
    kHistPtDRatioEtaMergedSub[i][j]->Divide(kHistPtDArrMergedEtaSub[1][j][0],kHistPtDArrMergedEtaSub[2][j][0],1.0,1.0,"");
    kHistAngularityRatioEtaMergedNoSub[i][j]->Divide(kHistAngularityArrMergedEtaNoSub[1][j][0],kHistAngularityArrMergedEtaNoSub[2][j][0],1.0,1.0,"");
    kHistAngularityRatioEtaMergedSub[i][j]->Divide(kHistAngularityArrMergedEtaSub[1][j][0],kHistAngularityArrMergedEtaSub[2][j][0],1.0,1.0,"");

    kHistLeSubRatioEtaMergedNoSub[i][j]->SetTitle(Form("(10-30%)/(30-50%) LeSub Ratio (Pt Bin %i);LeSub;Ratio",j));
    kHistLeSubRatioEtaMergedSub[i][j]->SetTitle(Form("(10-30%)/(30-50%) LeSub Ratio (Pt Bin %i);LeSub;Ratio",j));
    kHistPtDRatioEtaMergedNoSub[i][j]->SetTitle(Form("(10-30%)/(30-50%) ptD Ratio (Pt Bin %i);ptD;Ratio",j));
    kHistPtDRatioEtaMergedSub[i][j]->SetTitle(Form("(10-30%)/(30-50%) ptD Ratio (Pt Bin %i);ptD;Ratio",j));
    kHistAngularityRatioEtaMergedNoSub[i][j]->SetTitle(Form("(10-30%)/(30-50%) g Ratio (Pt Bin %i);g;Ratio",j));
    kHistAngularityRatioEtaMergedSub[i][j]->SetTitle(Form("(10-30%)/(30-50%) g Ratio (Pt Bin %i);g;Ratio",j));
   }

   if(i==5){
    kHistLeSubRatioEtaMergedNoSub[i][j]->Divide(kHistLeSubArrMergedEtaNoSub[1][j][0],kHistLeSubArrMergedEtaNoSub[3][j][0],1.0,1.0,"");
    kHistLeSubRatioEtaMergedSub[i][j]->Divide(kHistLeSubArrMergedEtaSub[1][j][0],kHistLeSubArrMergedEtaSub[3][j][0],1.0,1.0,"");
    kHistLeSubRatioEtaMerged2TrackNoSub[i][j]->Divide(kHistLeSubArrMergedEta2TrackNoSub[1][j][0],kHistLeSubArrMergedEta2TrackNoSub[3][j][0],1.0,1.0,"");
    kHistLeSubRatioEtaMerged2TrackSub[i][j]->Divide(kHistLeSubArrMergedEta2TrackSub[1][j][0],kHistLeSubArrMergedEta2TrackSub[3][j][0],1.0,1.0,"");
    kHistPtDRatioEtaMergedNoSub[i][j]->Divide(kHistPtDArrMergedEtaNoSub[1][j][0],kHistPtDArrMergedEtaNoSub[3][j][0],1.0,1.0,"");
    kHistPtDRatioEtaMergedSub[i][j]->Divide(kHistPtDArrMergedEtaSub[1][j][0],kHistPtDArrMergedEtaSub[3][j][0],1.0,1.0,"");
    kHistAngularityRatioEtaMergedNoSub[i][j]->Divide(kHistAngularityArrMergedEtaNoSub[1][j][0],kHistAngularityArrMergedEtaNoSub[3][j][0],1.0,1.0,"");
    kHistAngularityRatioEtaMergedSub[i][j]->Divide(kHistAngularityArrMergedEtaSub[1][j][0],kHistAngularityArrMergedEtaSub[3][j][0],1.0,1.0,"");

    kHistLeSubRatioEtaMergedNoSub[i][j]->SetTitle(Form("(10-30%)/(50-80%) LeSub Ratio (Pt Bin %i);LeSub;Ratio",j));
    kHistLeSubRatioEtaMergedSub[i][j]->SetTitle(Form("(10-30%)/(50-80%) LeSub Ratio (Pt Bin %i);LeSub;Ratio",j));
    kHistPtDRatioEtaMergedNoSub[i][j]->SetTitle(Form("(10-30%)/(50-80%) ptD Ratio (Pt Bin %i);ptD;Ratio",j));
    kHistPtDRatioEtaMergedSub[i][j]->SetTitle(Form("(10-30%)/(50-80%) ptD Ratio (Pt Bin %i);ptD;Ratio",j));
    kHistAngularityRatioEtaMergedNoSub[i][j]->SetTitle(Form("(10-30%)/(50-80%) g Ratio (Pt Bin %i);g;Ratio",j));
    kHistAngularityRatioEtaMergedSub[i][j]->SetTitle(Form("(10-30%)/(50-80%) g Ratio (Pt Bin %i);g;Ratio",j));
   }

   if(i==8){
    kHistLeSubRatioEtaMergedNoSub[i][j]->Divide(kHistLeSubArrMergedEtaNoSub[2][j][0],kHistLeSubArrMergedEtaNoSub[3][j][0],1.0,1.0,"");
    kHistLeSubRatioEtaMergedSub[i][j]->Divide(kHistLeSubArrMergedEtaSub[2][j][0],kHistLeSubArrMergedEtaSub[3][j][0],1.0,1.0,"");
    kHistLeSubRatioEtaMerged2TrackNoSub[i][j]->Divide(kHistLeSubArrMergedEta2TrackNoSub[2][j][0],kHistLeSubArrMergedEta2TrackNoSub[3][j][0],1.0,1.0,"");
    kHistLeSubRatioEtaMerged2TrackSub[i][j]->Divide(kHistLeSubArrMergedEta2TrackSub[2][j][0],kHistLeSubArrMergedEta2TrackSub[3][j][0],1.0,1.0,"");
    kHistPtDRatioEtaMergedNoSub[i][j]->Divide(kHistPtDArrMergedEtaNoSub[2][j][0],kHistPtDArrMergedEtaNoSub[3][j][0],1.0,1.0,"");
    kHistPtDRatioEtaMergedSub[i][j]->Divide(kHistPtDArrMergedEtaSub[2][j][0],kHistPtDArrMergedEtaSub[3][j][0],1.0,1.0,"");
    kHistAngularityRatioEtaMergedNoSub[i][j]->Divide(kHistAngularityArrMergedEtaNoSub[2][j][0],kHistAngularityArrMergedEtaNoSub[3][j][0],1.0,1.0,"");
    kHistAngularityRatioEtaMergedSub[i][j]->Divide(kHistAngularityArrMergedEtaSub[2][j][0],kHistAngularityArrMergedEtaSub[3][j][0],1.0,1.0,"");

    kHistLeSubRatioEtaMergedNoSub[i][j]->SetTitle(Form("(30-50%)/(50-80%) LeSub Ratio (Pt Bin %i);LeSub;Ratio",j));
    kHistLeSubRatioEtaMergedSub[i][j]->SetTitle(Form("(30-50%)/(50-80%) LeSub Ratio (Pt Bin %i);LeSub;Ratio",j));
    kHistPtDRatioEtaMergedNoSub[i][j]->SetTitle(Form("(30-50%)/(50-80%) ptD Ratio (Pt Bin %i);ptD;Ratio",j));
    kHistPtDRatioEtaMergedSub[i][j]->SetTitle(Form("(30-50%)/(50-80%) ptD Ratio (Pt Bin %i);ptD;Ratio",j));
    kHistAngularityRatioEtaMergedNoSub[i][j]->SetTitle(Form("(30-50%)/(50-80%) g Ratio (Pt Bin %i);g;Ratio",j));
    kHistAngularityRatioEtaMergedSub[i][j]->SetTitle(Form("(30-50%)/(50-80%) g Ratio (Pt Bin %i);g;Ratio",j));
   }


   //Ratios for the not merged eta ranges
   for(int k = 0; k<2; k++){
    kHistLeSubRatioSub[i][j][k]->SetLineWidth(subtractorThickness);
    kHistLeSubRatio2TrackNoSub[i][j][k]->SetLineWidth(presubtractorThickness);
    kHistLeSubRatio2TrackSub[i][j][k]->SetLineWidth(subtractorThickness);
    kHistPtDRatioSub[i][j][k]->SetLineWidth(subtractorThickness);
    kHistAngularityRatioSub[i][j][k]->SetLineWidth(subtractorThickness);
    kHistLeSubRatioSub[i][j][k]->SetLineColor(subtractorColor);
    kHistPtDRatioSub[i][j][k]->SetLineColor(subtractorColor);
    kHistAngularityRatioSub[i][j][k]->SetLineColor(subtractorColor);
    
    kHistLeSubRatioNoSub[i][j][k]->SetLineWidth(presubtractorThickness);
    kHistLeSubRatio2TrackNoSub[i][j][k]->SetLineColor(presubtractorColor);
    kHistLeSubRatio2TrackSub[i][j][k]->SetLineColor(subtractorColor);
    kHistPtDRatioNoSub[i][j][k]->SetLineWidth(presubtractorThickness);
    kHistAngularityRatioNoSub[i][j][k]->SetLineWidth(presubtractorThickness);
    kHistLeSubRatioNoSub[i][j][k]->SetLineColor(presubtractorColor);
    kHistPtDRatioNoSub[i][j][k]->SetLineColor(presubtractorColor);
    kHistAngularityRatioNoSub[i][j][k]->SetLineColor(presubtractorColor);

    if(i==0){
     kHistLeSubRatioNoSub[i][j][k]->Divide(kHistLeSubArrSigNoSub[0][j][k],kHistLeSubArrSigNoSub[1][j][k],1.0,1.0,"");
     kHistLeSubRatioSub[i][j][k]->Divide(kHistLeSubArrSigSub[0][j][k],kHistLeSubArrSigSub[1][j][k],1.0,1.0,"");
     kHistLeSubRatio2TrackNoSub[i][j][k]->Divide(kHistLeSubArrSig2TrackNoSub[0][j][k],kHistLeSubArrSig2TrackNoSub[1][j][k],1.0,1.0,"");
     kHistLeSubRatio2TrackSub[i][j][k]->Divide(kHistLeSubArrSig2TrackNoSub[0][j][k],kHistLeSubArrSig2TrackNoSub[1][j][k],1.0,1.0,"");
     kHistPtDRatioNoSub[i][j][k]->Divide(kHistPtDArrSigNoSub[0][j][k],kHistPtDArrSigNoSub[1][j][k],1.0,1.0,"");
     kHistPtDRatioSub[i][j][k]->Divide(kHistPtDArrSigSub[0][j][k],kHistPtDArrSigSub[1][j][k],1.0,1.0,"");
     kHistAngularityRatioNoSub[i][j][k]->Divide(kHistAngularityArrSigNoSub[0][j][k],kHistAngularityArrSigNoSub[1][j][k],1.0,1.0,"");
     kHistAngularityRatioSub[i][j][k]->Divide(kHistAngularityArrSigSub[0][j][k],kHistAngularityArrSigSub[1][j][k],1.0,1.0,"");

     kHistLeSubRatioNoSub[i][j][k]->SetTitle(Form("(0-10%)/(10-30%) LeSub Ratio (Pt Bin %i)(IR: %i);LeSub;Ratio",j,k));
     kHistLeSubRatioSub[i][j][k]->SetTitle(Form("(0-10%)/(10-30%) LeSub Ratio (Pt Bin %i)(IR: %i);LeSub;Ratio",j,k));
     kHistPtDRatioNoSub[i][j][k]->SetTitle(Form("(0-10%)/(10-30%) PtD Ratio (Pt Bin %i)(IR: %i);PtD;Ratio",j,k));
     kHistPtDRatioSub[i][j][k]->SetTitle(Form("(0-10%)/(10-30%) PtD Ratio (Pt Bin %i)(IR: %i);PtD;Ratio",j,k));
     kHistAngularityRatioNoSub[i][j][k]->SetTitle(Form("(0-10%)/(10-30%) g Ratio (Pt Bin %i)(IR: %i);g;Ratio",j,k));
     kHistAngularityRatioSub[i][j][k]->SetTitle(Form("(0-10%)/(10-30%) g Ratio (Pt Bin %i)(IR: %i);g;Ratio",j,k));
    }
    else if(i==1){
     kHistLeSubRatioNoSub[i][j][k]->Divide(kHistLeSubArrSigNoSub[0][j][k],kHistLeSubArrSigNoSub[2][j][k],1.0,1.0,"");
     kHistLeSubRatioSub[i][j][k]->Divide(kHistLeSubArrSigSub[0][j][k],kHistLeSubArrSigSub[2][j][k],1.0,1.0,"");
     kHistLeSubRatio2TrackNoSub[i][j][k]->Divide(kHistLeSubArrSig2TrackNoSub[0][j][k],kHistLeSubArrSig2TrackNoSub[2][j][k],1.0,1.0,"");
     kHistLeSubRatio2TrackSub[i][j][k]->Divide(kHistLeSubArrSig2TrackNoSub[0][j][k],kHistLeSubArrSig2TrackNoSub[2][j][k],1.0,1.0,"");
     kHistPtDRatioNoSub[i][j][k]->Divide(kHistPtDArrSigNoSub[0][j][k],kHistPtDArrSigNoSub[2][j][k],1.0,1.0,"");
     kHistPtDRatioSub[i][j][k]->Divide(kHistPtDArrSigSub[0][j][k],kHistPtDArrSigSub[2][j][k],1.0,1.0,"");
     kHistAngularityRatioNoSub[i][j][k]->Divide(kHistAngularityArrSigNoSub[0][j][k],kHistAngularityArrSigNoSub[2][j][k],1.0,1.0,"");
     kHistAngularityRatioSub[i][j][k]->Divide(kHistAngularityArrSigSub[0][j][k],kHistAngularityArrSigSub[2][j][k],1.0,1.0,"");

     kHistLeSubRatioNoSub[i][j][k]->SetTitle(Form("(0-10%)/(30-50%) LeSub Ratio (Pt Bin %i)(IR: %i);LeSub;Ratio",j,k));
     kHistLeSubRatioSub[i][j][k]->SetTitle(Form("(0-10%)/(30-50%) LeSub Ratio (Pt Bin %i)(IR: %i);LeSub;Ratio",j,k));
     kHistPtDRatioNoSub[i][j][k]->SetTitle(Form("(0-10%)/(30-50%) PtD Ratio (Pt Bin %i)(IR: %i);PtD;Ratio",j,k));
     kHistPtDRatioSub[i][j][k]->SetTitle(Form("(0-10%)/(30-50%) PtD Ratio (Pt Bin %i)(IR: %i);PtD;Ratio",j,k));
     kHistAngularityRatioNoSub[i][j][k]->SetTitle(Form("(0-10%)/(30-50%) g Ratio (Pt Bin %i)(IR: %i);g;Ratio",j,k));
     kHistAngularityRatioSub[i][j][k]->SetTitle(Form("(0-10%)/(30-50%) g Ratio (Pt Bin %i)(IR: %i);g;Ratio",j,k));
    }
    else if(i==2){
     kHistLeSubRatioNoSub[i][j][k]->Divide(kHistLeSubArrSigNoSub[0][j][k],kHistLeSubArrSigNoSub[3][j][k],1.0,1.0,"");
     kHistLeSubRatioSub[i][j][k]->Divide(kHistLeSubArrSigSub[0][j][k],kHistLeSubArrSigSub[3][j][k],1.0,1.0,"");
     kHistLeSubRatio2TrackNoSub[i][j][k]->Divide(kHistLeSubArrSig2TrackNoSub[0][j][k],kHistLeSubArrSig2TrackNoSub[3][j][k],1.0,1.0,"");
     kHistLeSubRatio2TrackSub[i][j][k]->Divide(kHistLeSubArrSig2TrackNoSub[0][j][k],kHistLeSubArrSig2TrackNoSub[3][j][k],1.0,1.0,"");
     kHistPtDRatioNoSub[i][j][k]->Divide(kHistPtDArrSigNoSub[0][j][k],kHistPtDArrSigNoSub[3][j][k],1.0,1.0,"");
     kHistPtDRatioSub[i][j][k]->Divide(kHistPtDArrSigSub[0][j][k],kHistPtDArrSigSub[3][j][k],1.0,1.0,"");
     kHistAngularityRatioNoSub[i][j][k]->Divide(kHistAngularityArrSigNoSub[0][j][k],kHistAngularityArrSigNoSub[3][j][k],1.0,1.0,"");
     kHistAngularityRatioSub[i][j][k]->Divide(kHistAngularityArrSigSub[0][j][k],kHistAngularityArrSigSub[3][j][k],1.0,1.0,"");

     kHistLeSubRatioNoSub[i][j][k]->SetTitle(Form("(0-10%)/(50-80%) LeSub Ratio (Pt Bin %i)(IR: %i);LeSub;Ratio",j,k));
     kHistLeSubRatioSub[i][j][k]->SetTitle(Form("(0-10%)/(50-80%) LeSub Ratio (Pt Bin %i)(IR: %i);LeSub;Ratio",j,k));
     kHistPtDRatioNoSub[i][j][k]->SetTitle(Form("(0-10%)/(50-80%) PtD Ratio (Pt Bin %i)(IR: %i);PtD;Ratio",j,k));
     kHistPtDRatioSub[i][j][k]->SetTitle(Form("(0-10%)/(50-80%) PtD Ratio (Pt Bin %i)(IR: %i);PtD;Ratio",j,k));
     kHistAngularityRatioNoSub[i][j][k]->SetTitle(Form("(0-10%)/(50-80%) g Ratio (Pt Bin %i)(IR: %i);g;Ratio",j,k));
     kHistAngularityRatioSub[i][j][k]->SetTitle(Form("(0-10%)/(50-80%) g Ratio (Pt Bin %i)(IR: %i);g;Ratio",j,k));
    }
    else if(i==4){
     kHistLeSubRatioNoSub[i][j][k]->Divide(kHistLeSubArrSigNoSub[1][j][k],kHistLeSubArrSigNoSub[2][j][k],1.0,1.0,"");
     kHistLeSubRatioSub[i][j][k]->Divide(kHistLeSubArrSigSub[1][j][k],kHistLeSubArrSigSub[2][j][k],1.0,1.0,"");
     kHistLeSubRatio2TrackNoSub[i][j][k]->Divide(kHistLeSubArrSig2TrackNoSub[1][j][k],kHistLeSubArrSig2TrackNoSub[2][j][k],1.0,1.0,"");
     kHistLeSubRatio2TrackSub[i][j][k]->Divide(kHistLeSubArrSig2TrackNoSub[1][j][k],kHistLeSubArrSig2TrackNoSub[2][j][k],1.0,1.0,"");
     kHistPtDRatioNoSub[i][j][k]->Divide(kHistPtDArrSigNoSub[1][j][k],kHistPtDArrSigNoSub[2][j][k],1.0,1.0,"");
     kHistPtDRatioSub[i][j][k]->Divide(kHistPtDArrSigSub[1][j][k],kHistPtDArrSigSub[2][j][k],1.0,1.0,"");
     kHistAngularityRatioNoSub[i][j][k]->Divide(kHistAngularityArrSigNoSub[1][j][k],kHistAngularityArrSigNoSub[2][j][k],1.0,1.0,"");
     kHistAngularityRatioSub[i][j][k]->Divide(kHistAngularityArrSigSub[1][j][k],kHistAngularityArrSigSub[2][j][k],1.0,1.0,"");

     kHistLeSubRatioNoSub[i][j][k]->SetTitle(Form("(10-30%)/(30-50%) LeSub Ratio (Pt Bin %i)(IR: %i);LeSub;Ratio",j,k));
     kHistLeSubRatioSub[i][j][k]->SetTitle(Form("(10-30%)/(30-50%) LeSub Ratio (Pt Bin %i)(IR: %i);LeSub;Ratio",j,k));
     kHistPtDRatioNoSub[i][j][k]->SetTitle(Form("(10-30%)/(30-50%) PtD Ratio (Pt Bin %i)(IR: %i);PtD;Ratio",j,k));
     kHistPtDRatioSub[i][j][k]->SetTitle(Form("(10-30%)/(30-50%) PtD Ratio (Pt Bin %i)(IR: %i);PtD;Ratio",j,k));
     kHistAngularityRatioNoSub[i][j][k]->SetTitle(Form("(10-30%)/(30-50%) g Ratio (Pt Bin %i)(IR: %i);g;Ratio",j,k));
     kHistAngularityRatioSub[i][j][k]->SetTitle(Form("(10-30%)/(30-50%) g Ratio (Pt Bin %i)(IR: %i);g;Ratio",j,k));
    }
    else if(i==5){
     kHistLeSubRatioNoSub[i][j][k]->Divide(kHistLeSubArrSigNoSub[1][j][k],kHistLeSubArrSigNoSub[3][j][k],1.0,1.0,"");
     kHistLeSubRatioSub[i][j][k]->Divide(kHistLeSubArrSigSub[1][j][k],kHistLeSubArrSigSub[3][j][k],1.0,1.0,"");
     kHistLeSubRatio2TrackNoSub[i][j][k]->Divide(kHistLeSubArrSig2TrackNoSub[1][j][k],kHistLeSubArrSig2TrackNoSub[3][j][k],1.0,1.0,"");
     kHistLeSubRatio2TrackSub[i][j][k]->Divide(kHistLeSubArrSig2TrackNoSub[1][j][k],kHistLeSubArrSig2TrackNoSub[3][j][k],1.0,1.0,"");
     kHistPtDRatioNoSub[i][j][k]->Divide(kHistPtDArrSigNoSub[1][j][k],kHistPtDArrSigNoSub[3][j][k],1.0,1.0,"");
     kHistPtDRatioSub[i][j][k]->Divide(kHistPtDArrSigSub[1][j][k],kHistPtDArrSigSub[3][j][k],1.0,1.0,"");
     kHistAngularityRatioNoSub[i][j][k]->Divide(kHistAngularityArrSigNoSub[1][j][k],kHistAngularityArrSigNoSub[3][j][k],1.0,1.0,"");
     kHistAngularityRatioSub[i][j][k]->Divide(kHistAngularityArrSigSub[1][j][k],kHistAngularityArrSigSub[3][j][k],1.0,1.0,"");

     kHistLeSubRatioNoSub[i][j][k]->SetTitle(Form("(10-30%)/(50-80%) LeSub Ratio (Pt Bin %i)(IR: %i);LeSub;Ratio",j,k));
     kHistLeSubRatioSub[i][j][k]->SetTitle(Form("(10-30%)/(50-80%) LeSub Ratio (Pt Bin %i)(IR: %i);LeSub;Ratio",j,k));
     kHistPtDRatioNoSub[i][j][k]->SetTitle(Form("(10-30%)/(50-80%) PtD Ratio (Pt Bin %i)(IR: %i);PtD;Ratio",j,k));
     kHistPtDRatioSub[i][j][k]->SetTitle(Form("(10-30%)/(50-80%) PtD Ratio (Pt Bin %i)(IR: %i);PtD;Ratio",j,k));
     kHistAngularityRatioNoSub[i][j][k]->SetTitle(Form("(10-30%)/(50-80%) g Ratio (Pt Bin %i)(IR: %i);g;Ratio",j,k));
     kHistAngularityRatioSub[i][j][k]->SetTitle(Form("(10-30%)/(50-80%) g Ratio (Pt Bin %i)(IR: %i);g;Ratio",j,k));
    }
    else if(i==8){
     kHistLeSubRatioNoSub[i][j][k]->Divide(kHistLeSubArrSigNoSub[2][j][k],kHistLeSubArrSigNoSub[3][j][k],1.0,1.0,"");
     kHistLeSubRatioSub[i][j][k]->Divide(kHistLeSubArrSigSub[2][j][k],kHistLeSubArrSigSub[3][j][k],1.0,1.0,"");
     kHistLeSubRatio2TrackNoSub[i][j][k]->Divide(kHistLeSubArrSig2TrackNoSub[2][j][k],kHistLeSubArrSig2TrackNoSub[3][j][k],1.0,1.0,"");
     kHistLeSubRatio2TrackSub[i][j][k]->Divide(kHistLeSubArrSig2TrackNoSub[2][j][k],kHistLeSubArrSig2TrackNoSub[3][j][k],1.0,1.0,"");
     kHistPtDRatioNoSub[i][j][k]->Divide(kHistPtDArrSigNoSub[2][j][k],kHistPtDArrSigNoSub[3][j][k],1.0,1.0,"");
     kHistPtDRatioSub[i][j][k]->Divide(kHistPtDArrSigSub[2][j][k],kHistPtDArrSigSub[3][j][k],1.0,1.0,"");
     kHistAngularityRatioNoSub[i][j][k]->Divide(kHistAngularityArrSigNoSub[2][j][k],kHistAngularityArrSigNoSub[3][j][k],1.0,1.0,"");
     kHistAngularityRatioSub[i][j][k]->Divide(kHistAngularityArrSigSub[2][j][k],kHistAngularityArrSigSub[3][j][k],1.0,1.0,"");

     kHistLeSubRatioNoSub[i][j][k]->SetTitle(Form("(30-50%)/(50-80%) LeSub Ratio (Pt Bin %i)(IR: %i);LeSub;Ratio",j,k));
     kHistLeSubRatioSub[i][j][k]->SetTitle(Form("(30-50%)/(50-80%) LeSub Ratio (Pt Bin %i)(IR: %i);LeSub;Ratio",j,k));
     kHistPtDRatioNoSub[i][j][k]->SetTitle(Form("(30-50%)/(50-80%) PtD Ratio (Pt Bin %i)(IR: %i);PtD;Ratio",j,k));
     kHistPtDRatioSub[i][j][k]->SetTitle(Form("(30-50%)/(50-80%) PtD Ratio (Pt Bin %i)(IR: %i);PtD;Ratio",j,k));
     kHistAngularityRatioNoSub[i][j][k]->SetTitle(Form("(30-50%)/(50-80%) g Ratio (Pt Bin %i)(IR: %i);g;Ratio",j,k));
     kHistAngularityRatioSub[i][j][k]->SetTitle(Form("(30-50%)/(50-80%) g Ratio (Pt Bin %i)(IR: %i);g;Ratio",j,k));
    }

   }
  } 
 

 }

 //Drawing the Raw Histograms
 c5->cd(1);
 kHistPtDOORNoSub->Draw();
 c5->cd(2);
 kHistPtDSigNoSub->Draw();
 c5->cd(3);
 kHistPtDBGOORNoSub->Draw();
 c5->cd(4);
 kHistPtDBGNoSub->Draw();

 c6->cd(1);
 kHistAngularityOORNoSub->Draw();
 c6->cd(2);
 kHistAngularitySigNoSub->Draw();
 c6->cd(3);
 kHistAngularityBGOORNoSub->Draw();
 c6->cd(4);
 kHistAngularityBGNoSub->Draw();

 c7->cd(1);
 kHistLeSubOORNoSub->Draw();
 c7->cd(2);
 kHistLeSubSigNoSub->Draw();
 c7->cd(3);
 kHistLeSubBGOORNoSub->Draw();
 c7->cd(4);
 kHistLeSubBGNoSub->Draw();

 c4->cd(1);
 kHistAngularityDistanceSigNoSub->Draw();
 c4->cd(2);
 kHistAngularityDistanceOORNoSub->Draw();
 c4->cd(3);
 kHistAngularityDistanceBGNoSub->Draw();
 c4->cd(4);
 kHistAngularityDistanceBGOORNoSub->Draw();

 
 TH1F *fHistPtSpectraARangeClone = (TH1F*)kHistPtSpectraARangeSub->Clone();
 kHistJetPtSpectraOORSub = fHistPtSpectraARangeClone;
 kHistJetPtSpectraOORSub->Add(kHistPtSpectraCRangeSub,1);

 TH1F *fHistPtSpectraARangeNoSubClone = (TH1F*)kHistPtSpectraARangeNoSub->Clone();
 kHistJetPtSpectraOORNoSub = fHistPtSpectraARangeNoSubClone;
 kHistJetPtSpectraOORNoSub->Add(kHistPtSpectraCRangeNoSub,1);

 //Performing Manual Background Subtractions
 TH1F *fHistAngularityOORClone = (TH1F*)kHistAngularityOORNoSub->Clone();
 kHistEtaSubAngularityNoSub = fHistAngularityOORClone;
 kHistEtaSubAngularityNoSub->Add(kHistAngularityBGOORNoSub,-1);
 kHistEtaSubAngularityNoSub->SetTitle("BG Sub Angularity (#eta sub);g");

 TH1F *fHistAngularitySigClone = (TH1F*)kHistAngularitySigNoSub->Clone();
 kHistPhiSubAngularityNoSub = fHistAngularitySigClone;
 kHistPhiSubAngularityNoSub->Add(kHistAngularityBGNoSub,-1);
 kHistPhiSubAngularityNoSub->SetTitle("BG Sub Angularity (#phi sub);g");

 TH1F *fHistLeSubOORClone = (TH1F*)kHistLeSubOORNoSub->Clone();
 kHistEtaSubLeSubNoSub = fHistLeSubOORClone;
 kHistEtaSubLeSubNoSub->Add(kHistLeSubBGOORNoSub,-1);
 kHistEtaSubLeSubNoSub->SetTitle("BG Sub LeSub (#eta sub);LeSub");

 TH1F *fHistLeSubSigClone = (TH1F*)kHistLeSubSigNoSub->Clone();
 kHistPhiSubLeSubNoSub = fHistLeSubSigClone;
 kHistPhiSubLeSubNoSub->Add(kHistLeSubBGNoSub,-1);
 kHistPhiSubLeSubNoSub->SetTitle("BG Sub LeSub (#phi sub);LeSub");

 TH1F *fHistPtDOORClone = (TH1F*)kHistPtDOORNoSub->Clone();
 kHistEtaSubPtDNoSub = fHistPtDOORClone;
 kHistEtaSubPtDNoSub->Add(kHistPtDBGOORNoSub,-1);
 kHistEtaSubPtDNoSub->SetTitle("BG Sub ptD (#eta sub);ptD");

 TH1F *fHistPtDSigClone = (TH1F*)kHistPtDSigNoSub->Clone();
 kHistPhiSubPtDNoSub = fHistPtDSigClone;
 kHistPhiSubPtDNoSub->Add(kHistPtDBGNoSub,-1);
 kHistPhiSubPtDNoSub->SetTitle("BG Sub ptD (#phi sub);ptD");
 
 

 //Display all results to their appropriate canvases
 //See top of macro to know which canvas number to use
 c1->cd(1);
 kHistEtaSubPtDNoSub->Draw();
 c1->cd(2);
 kHistPhiSubPtDNoSub->Draw();

 c2->cd(1);
 kHistEtaSubAngularityNoSub->Draw();
 c2->cd(2);
 kHistPhiSubAngularityNoSub->Draw();

 c3->cd(1);
 kHistEtaSubLeSubNoSub->Draw();
 c3->cd(2);
 kHistPhiSubLeSubNoSub->Draw();

 c8->cd(1);
 kHistPtSpectraInclusiveNoSub->Draw();
 c8->cd(2);
 kHistPtSpectraARangeNoSub->Draw();
 c8->cd(3);
 kHistPtSpectraBRangeNoSub->Draw();
 c8->cd(4);
 kHistPtSpectraCRangeNoSub->Draw();

 c9->cd(1);
 kHistEtaSubLeSubNoSub->Draw();
 kHistLeSubOORSub->Draw("SAME");
 c9->cd(2);
 kHistPhiSubLeSubNoSub->Draw();
 kHistLeSubSigSub->Draw("SAME");
 c10->cd(1);
 kHistEtaSubPtDNoSub->Draw();
 kHistPtDOORSub->Draw("SAME");
 c10->cd(2);
 kHistPhiSubPtDNoSub->Draw();
 kHistPtDSigSub->Draw("SAME");
 c11->cd(1);
 kHistEtaSubAngularityNoSub->Draw();
 kHistAngularityOORSub->Draw("SAME");
 c11->cd(2);
 kHistPhiSubAngularityNoSub->Draw();
 kHistAngularitySigSub->Draw("SAME");

 c12->cd(1);
 kHistLeSubOORNoSub->Draw();
 kHistLeSubOORSub->Draw("SAME");
 c12->cd(2);
 kHistLeSubSigNoSub->Draw();
 kHistLeSubSigSub->Draw("SAME");
 c13->cd(1);
 kHistPtDOORNoSub->Draw();
 kHistPtDOORSub->Draw("SAME");
 c13->cd(2);
 kHistPtDSigNoSub->Draw();
 kHistPtDSigSub->Draw("SAME");
 c14->cd(1);
 kHistAngularityOORNoSub->Draw();
 kHistAngularityOORSub->Draw("SAME");
 c14->cd(2);
 kHistAngularitySigNoSub->Draw();
 kHistAngularitySigSub->Draw("SAME");

 c15->cd(1);
 kHistJetPtSpectraOORSub->Draw();
 kHistJetPtSpectraOORNoSub->Draw("SAME");

 c15->cd(2);
 kHistPtSpectraBRangeSub->Draw();
 kHistPtSpectraBRangeNoSub->Draw("SAME");

 c16->cd(1);
 kHistPtD010CentNoSub->Draw();
 kHistPtD010CentSub->Draw("SAME");
 c16->cd(2);
 kHistPtD1030CentNoSub->Draw();
 kHistPtD1030CentSub->Draw("SAME");
 c16->cd(3);
 kHistPtD3080CentNoSub->Draw();
 kHistPtD3080CentSub->Draw("SAME");

 c17->cd(1);
 int index17 = 1;
 for(int j = 0; j<3; j++){
  for(int i = 0; i<4; i++){
   c17->cd(index17);
   gPad->SetGrid(0,0);
   kHistPtDNoSub[i][j][1]->Draw();
   kHistPtDSub[i][j][1]->Draw("SAME");
   index17++;
  }
 }

 c18->cd(1);
 int index18 = 1;
 for(int j = 0; j<3; j++){
  for(int i = 0; i<4; i++){
   c18->cd(index18);
   gPad->SetGrid(0,0);
   kHistPtDNoSub[i][j][0]->Draw();
   kHistPtDSub[i][j][0]->Draw("SAME");
   index18++;
  }
 }

 c19->cd(1);
 int index19 = 1;
 for(int j = 0; j<2; j++){
  for(int i = 0; i<4; i++){
   c19->cd(index19);
   gPad->SetGrid(0,0);
   kHistPtDPeaksNTracksNoSub[i][j][1]->Draw();
   kHistPtDPeaksNTracksSub[i][j][1]->Draw("SAME");
   index19++;
  }
 }
 
 c20->cd(1);
 int index20 = 1;
 for(int j = 0; j<2; j++){
  for(int i = 0; i<4; i++){
   c20->cd(index20);
   gPad->SetGrid(0,0);
   kHistPtDPeaksNTracksNoSub[i][j][0]->Draw();
   kHistPtDPeaksNTracksSub[i][j][0]->Draw("SAME");
   index20++;
  }
 }
 

 c21->cd(1);
 int index21 = 1;
 for(int j = 0; j<2; j++){
  for(int i = 0; i<4; i++){
   c21->cd(index21);
   gPad->SetGrid(0,0);
   kHistPtDPeaksPtTracksNoSub[i][j][1]->Draw();
   kHistPtDPeaksPtTracksSub[i][j][1]->Draw("SAME");
   index21++;
  }
 }
 
 c22->cd(1);
 int index22 = 1;
 for(int j = 0; j<2; j++){
  for(int i = 0; i<4; i++){
   c22->cd(index22);
   gPad->SetGrid(0,0);
   kHistPtDPeaksPtTracksNoSub[i][j][0]->Draw();
   kHistPtDPeaksPtTracksSub[i][j][0]->Draw("SAME");
   index22++;
  }
 }

 //LeSub Centrality Ratios
 c23->cd(1);
 kHistLeSubCentCompNoSub[0]->Draw();
 kHistLeSubCentCompSub[0]->Draw("SAME");

 c23->cd(2);
 kHistLeSubCentCompNoSub[1]->Draw();
 kHistLeSubCentCompSub[1]->Draw("SAME");

 c23->cd(3);
 kHistLeSubCentCompNoSub[2]->Draw();
 kHistLeSubCentCompSub[2]->Draw("SAME");

 c23->cd(5);
 kHistLeSubCentCompNoSub[4]->Draw();
 kHistLeSubCentCompSub[4]->Draw("SAME");

 c23->cd(6);
 kHistLeSubCentCompNoSub[5]->Draw();
 kHistLeSubCentCompSub[5]->Draw("SAME");

 c23->cd(9);
 kHistLeSubCentCompNoSub[8]->Draw();
 kHistLeSubCentCompSub[8]->Draw("SAME");


 //ptD Centrality Ratios
 c24->cd(1);
 kHistPtDCentCompNoSub[0]->Draw();
 kHistPtDCentCompSub[0]->Draw("SAME");

 c24->cd(2);
 kHistPtDCentCompNoSub[1]->Draw();
 kHistPtDCentCompSub[1]->Draw("SAME");

 c24->cd(3);
 kHistPtDCentCompNoSub[2]->Draw();
 kHistPtDCentCompSub[2]->Draw("SAME");

 c24->cd(5);
 kHistPtDCentCompNoSub[4]->Draw();
 kHistPtDCentCompSub[4]->Draw("SAME");

 c24->cd(6);
 kHistPtDCentCompNoSub[5]->Draw();
 kHistPtDCentCompSub[5]->Draw("SAME");

 c24->cd(9);
 kHistPtDCentCompNoSub[8]->Draw();
 kHistPtDCentCompSub[8]->Draw("SAME");


 //g Centrality Ratios
 c25->cd(1);
 kHistAngularityCentCompNoSub[0]->Draw();
 kHistAngularityCentCompSub[0]->Draw("SAME");

 c25->cd(2);
 kHistAngularityCentCompNoSub[1]->Draw();
 kHistAngularityCentCompSub[1]->Draw("SAME");

 c25->cd(3);
 kHistAngularityCentCompNoSub[2]->Draw();
 kHistAngularityCentCompSub[2]->Draw("SAME");

 c25->cd(5);
 kHistAngularityCentCompNoSub[4]->Draw();
 kHistAngularityCentCompSub[4]->Draw("SAME");

 c25->cd(6);
 kHistAngularityCentCompNoSub[5]->Draw();
 kHistAngularityCentCompSub[5]->Draw("SAME");

 c25->cd(9);
 kHistAngularityCentCompNoSub[8]->Draw();
 kHistAngularityCentCompSub[8]->Draw("SAME");


 c26->cd(1);
 c27->cd(1);
 c28->cd(1);
 c29->cd(1);
 c30->cd(1);
 c31->cd(1);
 c32->cd(1);
 c33->cd(1);
 c34->cd(1);
 c35->cd(1);
 c36->cd(1);
 c37->cd(1);
 c59->cd(1);
 c60->cd(1);
 c61->cd(1);
 c62->cd(1);


 for(int index = 1; index < 10; index++){
  
  //Declare and style labels
  TText *centralityLabel = new TText();
  centralityLabel->SetTextColor(1);
  centralityLabel->SetTextFont(1);
  centralityLabel->SetTextSize(0.1);
  centralityLabel->SetTextAngle(0);
  TText *ptLabel = new TText();
  ptLabel->SetTextColor(1);
  ptLabel->SetTextFont(1);
  ptLabel->SetTextSize(0.1);
  ptLabel->SetTextAngle(0);
  TText *etaLabel = new TText();
  etaLabel->SetTextColor(1);
  etaLabel->SetTextFont(1);
  etaLabel->SetTextSize(0.1);
  etaLabel->SetTextAngle(0);
  TText *trackPtLabel = new TText();
  trackPtLabel->SetTextColor(1);
  trackPtLabel->SetTextFont(1);
  trackPtLabel->SetTextSize(0.1);
  trackPtLabel->SetTextAngle(0);

  //List the labels at the bottom left (7th index) of the 3x3 canvases
  if(index==1){
   c26->cd(7);
   ptLabel->DrawText(0.4,0.7,"15 GeV < Jet pt < 25 GeV");
   etaLabel->DrawText(0.4,0.3,"|Jet eta| > 0.3");

   if(minTrackPt == 1.0)   trackPtLabel->DrawText(0.4,0.5,"track pt > 1.0 GeV");
   else if(minTrackPt == 2.0) trackPtLabel->DrawText(0.4,0.5,"track pt > 2.0 GeV");
   
   c27->cd(7);
   ptLabel->DrawText(0.4,0.7,"15 GeV < Jet pt < 25 GeV");
   etaLabel->DrawText(0.4,0.3,"|Jet eta| > 0.3");

   if(minTrackPt == 1.0)   trackPtLabel->DrawText(0.4,0.5,"track pt > 1.0 GeV");
   else if(minTrackPt == 2.0) trackPtLabel->DrawText(0.4,0.5,"track pt > 2.0 GeV");

   c28->cd(7);
   ptLabel->DrawText(0.4,0.7,"15 GeV < Jet pt < 25 GeV");
   etaLabel->DrawText(0.4,0.3,"|Jet eta| > 0.3");

   if(minTrackPt == 1.0)   trackPtLabel->DrawText(0.4,0.5,"track pt > 1.0 GeV");
   else if(minTrackPt == 2.0) trackPtLabel->DrawText(0.4,0.5,"track pt > 2.0 GeV");


   c29->cd(7);
   ptLabel->DrawText(0.4,0.7,"15 GeV < Jet pt < 25 GeV");
   etaLabel->DrawText(0.4,0.3,"|Jet eta| < 0.3");

   if(minTrackPt == 1.0)   trackPtLabel->DrawText(0.4,0.5,"track pt > 1.0 GeV");
   else if(minTrackPt == 2.0) trackPtLabel->DrawText(0.4,0.5,"track pt} > 2.0 GeV");

   c30->cd(7);
   ptLabel->DrawText(0.4,0.7,"15 GeV < Jet pt < 25 GeV");
   etaLabel->DrawText(0.4,0.3,"|Jet eta| < 0.3");

   if(minTrackPt == 1.0)   trackPtLabel->DrawText(0.4,0.5,"track pt > 1.0 GeV");
   else if(minTrackPt == 2.0) trackPtLabel->DrawText(0.4,0.5,"track pt > 2.0 GeV");

   c31->cd(7);
   ptLabel->DrawText(0.4,0.7,"15 GeV < Jet pt < 25 GeV");
   etaLabel->DrawText(0.4,0.3,"|Jet eta| < 0.3");

   if(minTrackPt == 1.0)   trackPtLabel->DrawText(0.4,0.5,"track pt > 1.0 GeV");
   else if(minTrackPt == 2.0) trackPtLabel->DrawText(0.4,0.5,"track pt > 2.0 GeV");

   
   c32->cd(7);
   ptLabel->DrawText(0.4,0.7,"Jet pt > 25 GeV");
   etaLabel->DrawText(0.4,0.3,"|Jet eta| > 0.3");

   if(minTrackPt == 1.0)   trackPtLabel->DrawText(0.4,0.5,"track pt > 1.0 GeV");
   else if(minTrackPt == 2.0) trackPtLabel->DrawText(0.4,0.5,"track pt > 2.0 GeV");

   c33->cd(7);
   ptLabel->DrawText(0.4,0.7,"Jet pt > 25 GeV");
   etaLabel->DrawText(0.4,0.3,"|Jet eta| > 0.3");

   if(minTrackPt == 1.0)   trackPtLabel->DrawText(0.4,0.5,"track pt > 1.0 GeV");
   else if(minTrackPt == 2.0) trackPtLabel->DrawText(0.4,0.5,"track pt > 2.0 GeV");

   c34->cd(7);
   ptLabel->DrawText(0.4,0.7,"Jet pt > 25 GeV");
   etaLabel->DrawText(0.4,0.3,"|Jet eta| > 0.3");

   if(minTrackPt == 1.0)   trackPtLabel->DrawText(0.4,0.5,"track pt > 1.0 GeV");
   else if(minTrackPt == 2.0) trackPtLabel->DrawText(0.4,0.5,"track pt > 2.0 GeV");


   c35->cd(7);
   ptLabel->DrawText(0.4,0.7,"Jet pt > 25 GeV");
   etaLabel->DrawText(0.4,0.3,"|Jet eta| < 0.3");
  
   if(minTrackPt == 1.0)   trackPtLabel->DrawText(0.4,0.5,"track pt > 1.0 GeV");
   else if(minTrackPt == 2.0) trackPtLabel->DrawText(0.4,0.5,"track pt > 2.0 GeV");
   
   c36->cd(7);
   ptLabel->DrawText(0.4,0.7,"Jet pt > 25 GeV");
   etaLabel->DrawText(0.4,0.3,"|Jet eta| < 0.3");
   
   if(minTrackPt == 1.0)   trackPtLabel->DrawText(0.4,0.5,"track pt > 1.0 GeV");
   else if(minTrackPt == 2.0) trackPtLabel->DrawText(0.4,0.5,"track pt > 2.0 GeV");

   c37->cd(7);
   ptLabel->DrawText(0.4,0.7,"Jet pt > 25 GeV");
   etaLabel->DrawText(0.4,0.3,"|Jet eta| < 0.3");

   if(minTrackPt == 1.0)   trackPtLabel->DrawText(0.4,0.5,"track pt > 1.0 GeV");
   else if(minTrackPt == 2.0) trackPtLabel->DrawText(0.4,0.5,"track pt > 2.0 GeV");

   c59->cd(7);
   ptLabel->DrawText(0.4,0.7,"15 GeV < Jet pt < 25 GeV");
   etaLabel->DrawText(0.4,0.3,"|Jet eta| > 0.3");

   if(minTrackPt == 1.0)   trackPtLabel->DrawText(0.4,0.5,"track pt > 1.0 GeV");
   else if(minTrackPt == 2.0) trackPtLabel->DrawText(0.4,0.5,"track pt > 2.0 GeV");
 
   c60->cd(7);
   ptLabel->DrawText(0.4,0.7,"15 GeV < Jet pt < 25 GeV");
   etaLabel->DrawText(0.4,0.3,"|Jet eta| < 0.3");

   if(minTrackPt == 1.0)   trackPtLabel->DrawText(0.4,0.5,"track pt > 1.0 GeV");
   else if(minTrackPt == 2.0) trackPtLabel->DrawText(0.4,0.5,"track pt > 2.0 GeV");

   c61->cd(7);
   ptLabel->DrawText(0.4,0.7,"Jet pt > 25 GeV");
   etaLabel->DrawText(0.4,0.3,"|Jet eta| > 0.3");

   if(minTrackPt == 1.0)   trackPtLabel->DrawText(0.4,0.5,"track pt > 1.0 GeV");
   else if(minTrackPt == 2.0) trackPtLabel->DrawText(0.4,0.5,"track pt > 2.0 GeV");

   c62->cd(7);
   ptLabel->DrawText(0.4,0.7,"Jet pt > 25 GeV");
   etaLabel->DrawText(0.4,0.3,"|Jet eta| < 0.3");

   if(minTrackPt == 1.0)   trackPtLabel->DrawText(0.4,0.5,"track pt > 1.0 GeV");
   else if(minTrackPt == 2.0) trackPtLabel->DrawText(0.4,0.5,"track pt > 2.0 GeV");
  }

  //Display the actual ratio in their respective indeces (making an upper right triangle on the canvas)
  if(index==1 || index==2 || index==3 || index==5 || index==6 || index==9){
   c26->cd(index);
   gPad->SetGrid(0,0);
   kHistLeSubRatioNoSub[index-1][0][0]->Draw();
   if(index==1)        centralityLabel->DrawText(0.0,0.08,"(0-10)/(10-30)");
   else if(index==2)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(30-50)");
   else if(index==3)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(50-80)");
   else if(index==5)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(30-50)");
   else if(index==6)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(50-80)");
   else if(index==9)   centralityLabel->DrawText(0.0,0.08,"(30-50)/(50-80)");
   kHistLeSubRatioSub[index-1][0][0]->Draw("SAME");

   c59->cd(index);
   gPad->SetGrid(0,0);
   kHistLeSubRatio2TrackNoSub[index-1][0][0]->Draw();
   if(index==1)        centralityLabel->DrawText(0.0,0.08,"(0-10)/(10-30)");
   else if(index==2)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(30-50)");
   else if(index==3)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(50-80)");
   else if(index==5)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(30-50)");
   else if(index==6)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(50-80)");
   else if(index==9)   centralityLabel->DrawText(0.0,0.08,"(30-50)/(50-80)");
   kHistLeSubRatio2TrackSub[index-1][0][0]->Draw("SAME");


   c27->cd(index);
   gPad->SetGrid(0,0);
   kHistPtDRatioNoSub[index-1][0][0]->Draw();
   if(index==1)        centralityLabel->DrawText(0.0,0.08,"(0-10)/(10-30)");
   else if(index==2)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(30-50)");
   else if(index==3)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(50-80)");
   else if(index==5)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(30-50)");
   else if(index==6)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(50-80)");
   else if(index==9)   centralityLabel->DrawText(0.0,0.08,"(30-50)/(50-80)");
   kHistPtDRatioSub[index-1][0][0]->Draw("SAME");

   c28->cd(index);
   gPad->SetGrid(0,0);
   kHistAngularityRatioNoSub[index-1][0][0]->Draw();
   if(index==1)        centralityLabel->DrawText(0.0,0.08,"(0-10)/(10-30)");
   else if(index==2)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(30-50)");
   else if(index==3)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(50-80)");
   else if(index==5)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(30-50)");
   else if(index==6)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(50-80)");
   else if(index==9)   centralityLabel->DrawText(0.0,0.08,"(30-50)/(50-80)");
   kHistAngularityRatioSub[index-1][0][0]->Draw("SAME");

   c29->cd(index);
   gPad->SetGrid(0,0);
   kHistLeSubRatioNoSub[index-1][0][1]->Draw();
   if(index==1)        centralityLabel->DrawText(0.0,0.08,"(0-10)/(10-30)");
   else if(index==2)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(30-50)");
   else if(index==3)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(50-80)");
   else if(index==5)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(30-50)");
   else if(index==6)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(50-80)");
   else if(index==9)   centralityLabel->DrawText(0.0,0.08,"(30-50)/(50-80)");
   kHistLeSubRatioSub[index-1][0][1]->Draw("SAME");
 
   c60->cd(index);
   gPad->SetGrid(0,0);
   kHistLeSubRatio2TrackNoSub[index-1][0][1]->Draw();
   if(index==1)        centralityLabel->DrawText(0.0,0.08,"(0-10)/(10-30)");
   else if(index==2)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(30-50)");
   else if(index==3)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(50-80)");
   else if(index==5)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(30-50)");
   else if(index==6)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(50-80)");
   else if(index==9)   centralityLabel->DrawText(0.0,0.08,"(30-50)/(50-80)");
   kHistLeSubRatio2TrackSub[index-1][0][1]->Draw("SAME");


   c30->cd(index);
   gPad->SetGrid(0,0);
   kHistPtDRatioNoSub[index-1][0][1]->Draw();
   if(index==1)        centralityLabel->DrawText(0.0,0.08,"(0-10)/(10-30)");
   else if(index==2)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(30-50)");
   else if(index==3)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(50-80)");
   else if(index==5)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(30-50)");
   else if(index==6)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(50-80)");
   else if(index==9)   centralityLabel->DrawText(0.0,0.08,"(30-50)/(50-80)");
   kHistPtDRatioSub[index-1][0][1]->Draw("SAME");

   c31->cd(index);
   gPad->SetGrid(0,0);
   kHistAngularityRatioNoSub[index-1][0][1]->Draw();
   if(index==1)        centralityLabel->DrawText(0.0,0.08,"(0-10)/(10-30)");
   else if(index==2)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(30-50)");
   else if(index==3)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(50-80)");
   else if(index==5)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(30-50)");
   else if(index==6)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(50-80)");
   else if(index==9)   centralityLabel->DrawText(0.0,0.08,"(30-50)/(50-80)");
   kHistAngularityRatioSub[index-1][0][1]->Draw("SAME");

   c32->cd(index);
   gPad->SetGrid(0,0);
   kHistLeSubRatioNoSub[index-1][1][0]->Draw();
   if(index==1)        centralityLabel->DrawText(0.0,0.08,"(0-10)/(10-30)");
   else if(index==2)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(30-50)");
   else if(index==3)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(50-80)");
   else if(index==5)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(30-50)");
   else if(index==6)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(50-80)");
   else if(index==9)   centralityLabel->DrawText(0.0,0.08,"(30-50)/(50-80)");
   kHistLeSubRatioSub[index-1][1][0]->Draw("SAME");

   c61->cd(index);
   gPad->SetGrid(0,0);
   kHistLeSubRatio2TrackNoSub[index-1][1][0]->Draw();
   if(index==1)        centralityLabel->DrawText(0.0,0.08,"(0-10)/(10-30)");
   else if(index==2)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(30-50)");
   else if(index==3)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(50-80)");
   else if(index==5)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(30-50)");
   else if(index==6)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(50-80)");
   else if(index==9)   centralityLabel->DrawText(0.0,0.08,"(30-50)/(50-80)");
   kHistLeSubRatio2TrackSub[index-1][1][0]->Draw("SAME");

   c33->cd(index);
   gPad->SetGrid(0,0);
   kHistPtDRatioNoSub[index-1][1][0]->Draw();
   if(index==1)        centralityLabel->DrawText(0.0,0.08,"(0-10)/(10-30)");
   else if(index==2)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(30-50)");
   else if(index==3)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(50-80)");
   else if(index==5)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(30-50)");
   else if(index==6)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(50-80)");
   else if(index==9)   centralityLabel->DrawText(0.0,0.08,"(30-50)/(50-80)");
   kHistPtDRatioSub[index-1][1][0]->Draw("SAME");

   c34->cd(index);
   gPad->SetGrid(0,0);
   kHistAngularityRatioNoSub[index-1][1][0]->Draw();
   if(index==1)        centralityLabel->DrawText(0.0,0.08,"(0-10)/(10-30)");
   else if(index==2)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(30-50)");
   else if(index==3)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(50-80)");
   else if(index==5)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(30-50)");
   else if(index==6)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(50-80)");
   else if(index==9)   centralityLabel->DrawText(0.0,0.08,"(30-50)/(50-80)");
   kHistAngularityRatioSub[index-1][1][0]->Draw("SAME");

   c35->cd(index);
   gPad->SetGrid(0,0);
   kHistLeSubRatioNoSub[index-1][1][1]->Draw();
   if(index==1)        centralityLabel->DrawText(0.0,0.08,"(0-10)/(10-30)");
   else if(index==2)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(30-50)");
   else if(index==3)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(50-80)");
   else if(index==5)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(30-50)");
   else if(index==6)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(50-80)");
   else if(index==9)   centralityLabel->DrawText(0.0,0.08,"(30-50)/(50-80)");
   kHistLeSubRatioSub[index-1][1][1]->Draw("SAME");

   c62->cd(index);
   gPad->SetGrid(0,0);
   kHistLeSubRatio2TrackNoSub[index-1][1][1]->Draw();
   if(index==1)        centralityLabel->DrawText(0.0,0.08,"(0-10)/(10-30)");
   else if(index==2)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(30-50)");
   else if(index==3)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(50-80)");
   else if(index==5)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(30-50)");
   else if(index==6)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(50-80)");
   else if(index==9)   centralityLabel->DrawText(0.0,0.08,"(30-50)/(50-80)");
   kHistLeSubRatio2TrackSub[index-1][1][1]->Draw("SAME");


   c36->cd(index);
   gPad->SetGrid(0,0);
   kHistPtDRatioNoSub[index-1][1][1]->Draw();
   if(index==1)        centralityLabel->DrawText(0.0,0.08,"(0-10)/(10-30)");
   else if(index==2)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(30-50)");
   else if(index==3)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(50-80)");
   else if(index==5)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(30-50)");
   else if(index==6)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(50-80)");
   else if(index==9)   centralityLabel->DrawText(0.0,0.08,"(30-50)/(50-80)");
   kHistPtDRatioSub[index-1][1][1]->Draw("SAME");

   c37->cd(index);
   gPad->SetGrid(0,0);
   kHistAngularityRatioNoSub[index-1][1][1]->Draw();
   if(index==1)        centralityLabel->DrawText(0.0,0.08,"(0-10)/(10-30)");
   else if(index==2)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(30-50)");
   else if(index==3)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(50-80)");
   else if(index==5)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(30-50)");
   else if(index==6)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(50-80)");
   else if(index==9)   centralityLabel->DrawText(0.0,0.08,"(30-50)/(50-80)");
   kHistAngularityRatioSub[index-1][1][1]->Draw("SAME");
  }
 }

 c38->cd(1);
 c39->cd(1);
 c40->cd(1);
 c41->cd(1);
 c42->cd(1);
 c43->cd(1);
 c44->cd(1);
 c45->cd(1);
 c46->cd(1);
 c47->cd(1);
 c48->cd(1);
 c49->cd(1);
 c57->cd(1);
 c58->cd(1);


 int indexHolder = 1;

 //Show the histograms that display the raw, normalized data for bin selections
 for(int k=0; k<2; k++){
  for(int j=0; j<2; j++){
   for(int i=0; i<4; i++){
    
    if(indexHolder > 16) {break;}

    //Prepare labels
    TText *centralityLabel = new TText();
    centralityLabel->SetTextColor(1);
    centralityLabel->SetTextFont(1);
    centralityLabel->SetTextSize(0.06);
    centralityLabel->SetTextAngle(0);
    TText *ptLabel = new TText();
    ptLabel->SetTextColor(1);
    ptLabel->SetTextFont(1);
    ptLabel->SetTextSize(0.06);
    ptLabel->SetTextAngle(0);
    TText *etaLabel = new TText();
    etaLabel->SetTextColor(1);
    etaLabel->SetTextFont(1);
    etaLabel->SetTextSize(0.06);
    etaLabel->SetTextAngle(0);
    TText *trackPtLabel = new TText();
    trackPtLabel->SetTextColor(1);
    trackPtLabel->SetTextFont(1);
    trackPtLabel->SetTextSize(0.06);
    trackPtLabel->SetTextAngle(0);

    double lesubX = 9.0;
    double lesubY = 0.0;
    double ptdX = 0.02;
    double ptdY = 0.0;
    double gX = 0.2;
    double gY = 0.0;


    c38->cd(indexHolder);
    gPad->SetGrid(0,0);
    kHistLeSubArrSigSub[i][j][k]->SetYTitle("1/nJets 1/binWidth");
    kHistLeSubArrSigSub[i][j][k]->Draw();
    lesubY = kHistLeSubArrSigSub[i][j][k]->GetMaximum();
    if(i==0)    centralityLabel->DrawText(lesubX,lesubY*0.9,"0-10 Centrality");
    else if(i==1) centralityLabel->DrawText(lesubX,lesubY*0.9,"10-30 Centrality");
    else if(i==2) centralityLabel->DrawText(lesubX,lesubY*0.9,"30-50 Centrality");
    else if(i==3)  centralityLabel->DrawText(lesubX,lesubY*0.9,"50-80 Centrality");

    if(j==0)    ptLabel->DrawText(lesubX,lesubY*0.8,"15 GeV < Jet pt < 25 GeV");
    else if(j==1)  ptLabel->DrawText(lesubX,lesubY*0.8,"Jet pt > 25 GeV");

    if(k==0)    etaLabel->DrawText(lesubX,lesubY*0.7,"|Jet eta| > 0.3");
    else if(k==1)  etaLabel->DrawText(lesubX,lesubY*0.7,"|Jet eta| < 0.3");

    if(minTrackPt == 1.0)   trackPtLabel->DrawText(lesubX,lesubY*0.6,"track pt > 1.0 GeV");
    else if(minTrackPt == 2.0) trackPtLabel->DrawText(lesubX,lesubY*0.6,"track pt > 2.0 GeV");
    kHistLeSubArrSigNoSub[i][j][k]->Draw("SAME");

    c57->cd(indexHolder);
    gPad->SetGrid(0,0);
    kHistLeSubArrSig2TrackSub[i][j][k]->SetYTitle("1/nJets 1/binWidth");
    kHistLeSubArrSig2TrackSub[i][j][k]->Draw();
    lesubY = kHistLeSubArrSig2TrackSub[i][j][k]->GetMaximum();
    if(i==0)    centralityLabel->DrawText(lesubX,lesubY*0.9,"0-10 Centrality");
    else if(i==1) centralityLabel->DrawText(lesubX,lesubY*0.9,"10-30 Centrality");
    else if(i==2) centralityLabel->DrawText(lesubX,lesubY*0.9,"30-50 Centrality");
    else if(i==3)  centralityLabel->DrawText(lesubX,lesubY*0.9,"50-80 Centrality");

    if(j==0)    ptLabel->DrawText(lesubX,lesubY*0.8,"15 GeV < Jet pt < 25 GeV");
    else if(j==1)  ptLabel->DrawText(lesubX,lesubY*0.8,"Jet pt > 25 GeV");

    if(k==0)    etaLabel->DrawText(lesubX,lesubY*0.7,"|Jet eta| > 0.3");
    else if(k==1)  etaLabel->DrawText(lesubX,lesubY*0.7,"|Jet eta| < 0.3");

    if(minTrackPt == 1.0)   trackPtLabel->DrawText(lesubX,lesubY*0.6,"track pt > 1.0 GeV");
    else if(minTrackPt == 2.0) trackPtLabel->DrawText(lesubX,lesubY*0.6,"track pt > 2.0 GeV");
    kHistLeSubArrSig2TrackNoSub[i][j][k]->Draw("SAME");


    c39->cd(indexHolder);
    gPad->SetGrid(0,0);
    kHistPtDArrSigBGNoSub[i][j][k]->SetYTitle("1/nJets 1/binWidth");
    kHistPtDArrSigBGNoSub[i][j][k]->Draw();
    ptdY = kHistPtDArrSigBGNoSub[i][j][k]->GetMaximum();
    if(i==0)    centralityLabel->DrawText(ptdX,ptdY*0.9,"0-10 Centrality");
    else if(i==1) centralityLabel->DrawText(ptdX,ptdY*0.9,"10-30 Centrality");
    else if(i==2) centralityLabel->DrawText(ptdX,ptdY*0.9,"30-50 Centrality");
    else if(i==3)  centralityLabel->DrawText(ptdX,ptdY*0.9,"50-80 Centrality");

    if(j==0)    ptLabel->DrawText(ptdX,ptdY*0.8,"15 GeV < Jet pt < 25 GeV");
    else if(j==1)  ptLabel->DrawText(ptdX,ptdY*0.8,"Jet pt > 25 GeV");

    if(k==0)    etaLabel->DrawText(ptdX,ptdY*0.7,"|Jet eta| > 0.3");
    else if(k==1)  etaLabel->DrawText(ptdX,ptdY*0.7,"|Jet eta| < 0.3");

    if(minTrackPt == 1.0)   trackPtLabel->DrawText(ptdX,ptdY*0.6,"track pt > 1.0 GeV");
    else if(minTrackPt == 2.0) trackPtLabel->DrawText(ptdX,ptdY*0.6,"track pt > 2.0 GeV");

    kHistPtDArrSigSub[i][j][k]->Draw("SAME");

    c40->cd(indexHolder);
    gPad->SetGrid(0,0);
    kHistAngularityArrSigSub[i][j][k]->SetYTitle("1/nJets 1/binWidth");
    kHistAngularityArrSigSub[i][j][k]->Draw();
    gY = kHistAngularityArrSigSub[i][j][k]->GetMaximum();
    if(i==0)    centralityLabel->DrawText(gX,gY*0.9,"0-10 Centrality");
    else if(i==1) centralityLabel->DrawText(gX,gY*0.9,"10-30 Centrality");
    else if(i==2) centralityLabel->DrawText(gX,gY*0.9,"30-50 Centrality");
    else if(i==3)  centralityLabel->DrawText(gX,gY*0.9,"50-80 Centrality");

    if(j==0)    ptLabel->DrawText(gX,gY*0.8,"15 GeV < Jet pt < 25 GeV");
    else if(j==1)  ptLabel->DrawText(gX,gY*0.8,"Jet pt > 25 GeV");

    if(k==0)    etaLabel->DrawText(gX,gY*0.7,"|Jet eta| > 0.3");
    else if(k==1)  etaLabel->DrawText(gX,gY*0.7,"|Jet eta| < 0.3");

    if(minTrackPt == 1.0)   trackPtLabel->DrawText(gX,gY*0.6,"track pt > 1.0 GeV");
    else if(minTrackPt == 2.0) trackPtLabel->DrawText(gX,gY*0.6,"track pt > 2.0 GeV");
    kHistAngularityArrSigBGNoSub[i][j][k]->Draw("SAME");

    c41->cd(indexHolder);
    gPad->SetGrid(0,0);
    kHistLeSubArrBGNoSub[i][j][k]->SetYTitle("1/nJets 1/binWidth");
    kHistLeSubArrBGNoSub[i][j][k]->Draw();
    lesubY = kHistLeSubArrBGNoSub[i][j][k]->GetMaximum();
    if(i==0)    centralityLabel->DrawText(6.0,lesubY*0.9,"0-10 Centrality");
    else if(i==1) centralityLabel->DrawText(6.0,lesubY*0.9,"10-30 Centrality");
    else if(i==2) centralityLabel->DrawText(6.0,lesubY*0.9,"30-50 Centrality");
    else if(i==3)  centralityLabel->DrawText(6.0,lesubY*0.9,"50-80 Centrality");

    if(j==0)    ptLabel->DrawText(6.0,lesubY*0.8,"15 GeV < Jet pt < 25 GeV");
    else if(j==1)  ptLabel->DrawText(6.0,lesubY*0.8,"Jet pt > 25 GeV");

    if(k==0)    etaLabel->DrawText(6.0,lesubY*0.7,"|Jet eta| > 0.3");
    else if(k==1)  etaLabel->DrawText(6.0,lesubY*0.7,"|Jet eta| < 0.3");

    if(minTrackPt == 1.0)   trackPtLabel->DrawText(6.0,lesubY*0.6,"track pt > 1.0 GeV");
    else if(minTrackPt == 2.0) trackPtLabel->DrawText(6.0,lesubY*0.6,"track pt > 2.0 GeV");

    c42->cd(indexHolder);
    gPad->SetGrid(0,0);
    kHistPtDArrBGNoSub[i][j][k]->SetYTitle("1/nJets 1/binWidth");
    kHistPtDArrBGNoSub[i][j][k]->Draw();
    ptdY = kHistPtDArrBGNoSub[i][j][k]->GetMaximum();
    if(i==0)    centralityLabel->DrawText(0.35,ptdY*0.9,"0-10 Centrality");
    else if(i==1) centralityLabel->DrawText(0.35,ptdY*0.9,"10-30 Centrality");
    else if(i==2) centralityLabel->DrawText(0.35,ptdY*0.9,"30-50 Centrality");
    else if(i==3)  centralityLabel->DrawText(0.35,ptdY*0.9,"50-80 Centrality");

    if(j==0)    ptLabel->DrawText(0.35,ptdY*0.8,"15 GeV < Jet pt < 25 GeV");
    else if(j==1)  ptLabel->DrawText(0.35,ptdY*0.8,"Jet pt > 25 GeV");

    if(k==0)    etaLabel->DrawText(0.35,ptdY*0.7,"|Jet eta| > 0.3");
    else if(k==1)  etaLabel->DrawText(0.35,ptdY*0.7,"|Jet eta| < 0.3");
 
    if(minTrackPt == 1.0)   trackPtLabel->DrawText(0.35,ptdY*0.6,"track pt > 1.0 GeV");
    else if(minTrackPt == 2.0) trackPtLabel->DrawText(0.35,ptdY*0.6,"track pt > 2.0 GeV");

    c43->cd(indexHolder);
    gPad->SetGrid(0,0);
    kHistAngularityArrBGNoSub[i][j][k]->SetYTitle("1/nJets 1/binWidth");
    kHistAngularityArrBGNoSub[i][j][k]->Draw();
    gY = kHistAngularityArrBGNoSub[i][j][k]->GetMaximum();
    if(i==0)    centralityLabel->DrawText(0.1,gY*0.9,"0-10 Centrality");
    else if(i==1) centralityLabel->DrawText(0.1,gY*0.9,"10-30 Centrality");
    else if(i==2) centralityLabel->DrawText(0.1,gY*0.9,"30-50 Centrality");
    else if(i==3)  centralityLabel->DrawText(0.1,gY*0.9,"50-80 Centrality");

    if(j==0)    ptLabel->DrawText(0.1,gY*0.8,"15 GeV < Jet pt < 25 GeV");
    else if(j==1)  ptLabel->DrawText(0.1,gY*0.8,"Jet pt > 25 GeV");

    if(k==0)    etaLabel->DrawText(0.1,gY*0.7,"|Jet eta| > 0.3");
    else if(k==1)  etaLabel->DrawText(0.1,gY*0.7,"|Jet eta| < 0.3");

    if(minTrackPt == 1.0)   trackPtLabel->DrawText(0.1,gY*0.6,"track pt > 1.0 GeV");
    else if(minTrackPt == 2.0) trackPtLabel->DrawText(0.1,gY*0.6,"track pt > 2.0 GeV");

    c44->cd(indexHolder);
    gPad->SetGrid(0,0);
    kHistLeSubArrSigSub[i][j][k]->SetYTitle("1/nJets 1/binWidth");
    kHistLeSubArrSigSub[i][j][k]->Draw();
    lesubY = kHistLeSubArrSigSub[i][j][k]->GetMaximum();
    if(i==0)    centralityLabel->DrawText(lesubX,lesubY*0.9,"0-10 Centrality");
    else if(i==1) centralityLabel->DrawText(lesubX,lesubY*0.9,"10-30 Centrality");
    else if(i==2) centralityLabel->DrawText(lesubX,lesubY*0.9,"30-50 Centrality");
    else if(i==3)  centralityLabel->DrawText(lesubX,lesubY*0.9,"50-80 Centrality");

    if(j==0)    ptLabel->DrawText(lesubX,lesubY*0.8,"15 GeV < Jet pt < 25 GeV");
    else if(j==1)  ptLabel->DrawText(lesubX,lesubY*0.8,"Jet pt > 25 GeV");

    if(k==0)    etaLabel->DrawText(lesubX,lesubY*0.7,"|Jet eta| > 0.3");
    else if(k==1)  etaLabel->DrawText(lesubX,lesubY*0.7,"|Jet eta| < 0.3");

    if(minTrackPt == 1.0)   trackPtLabel->DrawText(lesubX,lesubY*0.6,"track pt > 1.0 GeV");
    else if(minTrackPt == 2.0) trackPtLabel->DrawText(lesubX,lesubY*0.6,"track pt > 2.0 GeV");

    kHistLeSubArrSigNoSub[i][j][k]->Draw("SAME");

    c45->cd(indexHolder);
    gPad->SetGrid(0,0);
    kHistPtDArrSigNoSub[i][j][k]->SetYTitle("1/nJets 1/binWidth");
    kHistPtDArrSigNoSub[i][j][k]->Draw();
    ptdY = kHistPtDArrSigNoSub[i][j][k]->GetMaximum();
    if(i==0)    centralityLabel->DrawText(ptdX,ptdY*0.9,"0-10 Centrality");
    else if(i==1) centralityLabel->DrawText(ptdX,ptdY*0.9,"10-30 Centrality");
    else if(i==2) centralityLabel->DrawText(ptdX,ptdY*0.9,"30-50 Centrality");
    else if(i==3)  centralityLabel->DrawText(ptdX,ptdY*0.9,"50-80 Centrality");

    if(j==0)    ptLabel->DrawText(ptdX,ptdY*0.8,"15 GeV < Jet pt < 25 GeV");
    else if(j==1)  ptLabel->DrawText(ptdX,ptdY*0.8,"Jet pt > 25 GeV");

    if(k==0)    etaLabel->DrawText(ptdX,ptdY*0.7,"|Jet eta| > 0.3");
    else if(k==1)  etaLabel->DrawText(ptdX,ptdY*0.7,"|Jet eta| < 0.3");

    if(minTrackPt == 1.0)   trackPtLabel->DrawText(ptdX,ptdY*0.6,"track pt > 1.0 GeV");
    else if(minTrackPt == 2.0) trackPtLabel->DrawText(ptdX,ptdY*0.6,"track pt > 2.0 GeV");

    kHistPtDArrSigSub[i][j][k]->Draw("SAME");

    c46->cd(indexHolder);
    gPad->SetGrid(0,0);
    kHistAngularityArrSigSub[i][j][k]->SetYTitle("1/nJets 1/binWidth");
    kHistAngularityArrSigSub[i][j][k]->Draw();
    gY = kHistAngularityArrSigSub[i][j][k]->GetMaximum();
    if(i==0)    centralityLabel->DrawText(gX,gY*0.9,"0-10 Centrality");
    else if(i==1) centralityLabel->DrawText(gX,gY*0.9,"10-30 Centrality");
    else if(i==2) centralityLabel->DrawText(gX,gY*0.9,"30-50 Centrality");
    else if(i==3)  centralityLabel->DrawText(gX,gY*0.9,"50-80 Centrality");

    if(j==0)    ptLabel->DrawText(gX,gY*0.8,"15 GeV < Jet pt < 25 GeV");
    else if(j==1)  ptLabel->DrawText(gX,gY*0.8,"Jet pt > 25 GeV");

    if(k==0)    etaLabel->DrawText(gX,gY*0.7,"|Jet eta| > 0.3");
    else if(k==1)  etaLabel->DrawText(gX,gY*0.7,"|Jet eta| < 0.3");

    if(minTrackPt == 1.0)   trackPtLabel->DrawText(gX,gY*0.6,"track pt > 1.0 GeV");
    else if(minTrackPt == 2.0) trackPtLabel->DrawText(gX,gY*0.6,"track pt > 2.0 GeV");
    kHistAngularityArrSigNoSub[i][j][k]->Draw("SAME");

    if(indexHolder < 9){
      c47->cd(indexHolder);
      gPad->SetGrid(0,0);
      kHistLeSubArrMergedEtaSub[i][j][k]->SetYTitle("1/nJets 1/binWidth");
      kHistLeSubArrMergedEtaSub[i][j][k]->Draw();
      lesubY = kHistLeSubArrMergedEtaSub[i][j][k]->GetMaximum();
      if(i==0)    centralityLabel->DrawText(lesubX,lesubY*0.9,"0-10 Centrality");
      else if(i==1) centralityLabel->DrawText(lesubX,lesubY*0.9,"10-30 Centrality");
      else if(i==2) centralityLabel->DrawText(lesubX,lesubY*0.9,"30-50 Centrality");
      else if(i==3)  centralityLabel->DrawText(lesubX,lesubY*0.9,"50-80 Centrality");

      if(j==0)    ptLabel->DrawText(lesubX,lesubY*0.8,"15 GeV < Jet pt < 25 GeV");
      else if(j==1)  ptLabel->DrawText(lesubX,lesubY*0.8,"Jet pt > 25 GeV");

      etaLabel->DrawText(lesubX,lesubY*0.7,"-0.7 < Jet Eta < 0.7");

      if(minTrackPt == 1.0)   trackPtLabel->DrawText(lesubX,lesubY*0.6,"track pt > 1.0 GeV");
      else if(minTrackPt == 2.0) trackPtLabel->DrawText(lesubX,lesubY*0.6,"track pt > 2.0 GeV");
      kHistLeSubArrMergedEtaNoSub[i][j][k]->Draw("SAME");

      c58->cd(indexHolder);
      gPad->SetGrid(0,0);
      kHistLeSubArrMergedEta2TrackSub[i][j][k]->SetYTitle("1/nJets 1/binWidth");
      kHistLeSubArrMergedEta2TrackSub[i][j][k]->Draw();
      lesubY = kHistLeSubArrMergedEta2TrackSub[i][j][k]->GetMaximum();
      if(i==0)    centralityLabel->DrawText(lesubX,lesubY*0.9,"0-10 Centrality");
      else if(i==1) centralityLabel->DrawText(lesubX,lesubY*0.9,"10-30 Centrality");
      else if(i==2) centralityLabel->DrawText(lesubX,lesubY*0.9,"30-50 Centrality");
      else if(i==3)  centralityLabel->DrawText(lesubX,lesubY*0.9,"50-80 Centrality");

      if(j==0)    ptLabel->DrawText(lesubX,lesubY*0.8,"15 GeV < Jet pt < 25 GeV");
      else if(j==1)  ptLabel->DrawText(lesubX,lesubY*0.8,"Jet pt > 25 GeV");

      etaLabel->DrawText(lesubX,lesubY*0.7,"-0.7 < Jet Eta < 0.7");

      if(minTrackPt == 1.0)   trackPtLabel->DrawText(lesubX,lesubY*0.6,"track pt > 1.0 GeV");
      else if(minTrackPt == 2.0) trackPtLabel->DrawText(lesubX,lesubY*0.6,"track pt > 2.0 GeV");
      kHistLeSubArrMergedEta2TrackNoSub[i][j][k]->Draw("SAME");


      c48->cd(indexHolder);
      gPad->SetGrid(0,0);
      kHistPtDArrMergedEtaSub[i][j][k]->SetYTitle("1/nJets 1/binWidth");
      kHistPtDArrMergedEtaSub[i][j][k]->Draw();
      ptdY = kHistPtDArrMergedEtaSub[i][j][k]->GetMaximum();
      if(i==0)    centralityLabel->DrawText(ptdX,ptdY*0.9,"0-10 Centrality");
      else if(i==1) centralityLabel->DrawText(ptdX,ptdY*0.9,"10-30 Centrality");
      else if(i==2) centralityLabel->DrawText(ptdX,ptdY*0.9,"30-50 Centrality");
      else if(i==3)  centralityLabel->DrawText(ptdX,ptdY*0.9,"50-80 Centrality");

      if(j==0)    ptLabel->DrawText(ptdX,ptdY*0.8,"15 GeV < Jet pt < 25 GeV");
      else if(j==1)  ptLabel->DrawText(ptdX,ptdY*0.8,"Jet pt > 25 GeV");

      etaLabel->DrawText(ptdX,ptdY*0.7,"-0.7 < Jet Eta < 0.7");

      if(minTrackPt == 1.0)   trackPtLabel->DrawText(ptdX,ptdY*0.6,"track pt > 1.0 GeV");
      else if(minTrackPt == 2.0) trackPtLabel->DrawText(ptdX,ptdY*0.6,"track pt > 2.0 GeV");
      kHistPtDArrMergedEtaNoSub[i][j][k]->Draw("SAME");

      c49->cd(indexHolder);
      gPad->SetGrid(0,0);
      kHistAngularityArrMergedEtaSub[i][j][k]->SetYTitle("1/nJets 1/binWidth");
      kHistAngularityArrMergedEtaSub[i][j][k]->Draw();
      gY = kHistAngularityArrMergedEtaSub[i][j][k]->GetMaximum();
      if(i==0)    centralityLabel->DrawText(gX*0.7,gY*0.9,"0-10 Centrality");
      else if(i==1) centralityLabel->DrawText(gX*0.7,gY*0.9,"10-30 Centrality");
      else if(i==2) centralityLabel->DrawText(gX*0.7,gY*0.9,"30-50 Centrality");
      else if(i==3)  centralityLabel->DrawText(gX*0.7,gY*0.9,"50-80 Centrality");

      if(j==0)    ptLabel->DrawText(gX*0.7,gY*0.8,"15 GeV < Jet pt < 25 GeV");
      else if(j==1)  ptLabel->DrawText(gX*0.7,gY*0.8,"Jet pt > 25 GeV");

      etaLabel->DrawText(gX*0.7,gY*0.7,"-0.7 < Jet Eta < 0.7");

      if(minTrackPt == 1.0)   trackPtLabel->DrawText(gX*0.7,gY*0.6,"track pt > 1.0 GeV");
      else if(minTrackPt == 2.0) trackPtLabel->DrawText(gX*0.7,gY*0.6,"track pt > 2.0 GeV");
      kHistAngularityArrMergedEtaNoSub[i][j][k]->Draw("SAME");
    }
 
    //Give info on Njets for given bin selections
    cout << Form("Histogram: %i",indexHolder) << endl;
    cout << Form("NJets Constituent Subtractor (Cent Bin: %i, Pt Bin: %i, Eta Bin: %i) : ",i,j,k) << nJetsArrSub[i][j][k] << endl;
    cout << Form("NJets Area*Rho Subtraction (Cent Bin: %i, Pt Bin: %i, Eta Bin: %i) : ",i,j,k) << nJetsArrNoSub[i][j][k] << endl;
    cout << "------------------------------------------------------------------------------------" << endl;

    indexHolder++;
   }
  }
 }

 //Give info on NEvents for given bin selections
 int histnum = 1;
 for(int k=0; k<2; k++){
  for(int j=0; j<2; j++){
   for(int i=0; i<4; i++){
    cout << Form("Histogram: %i",histnum) << endl;
    cout << Form("NEvents Constituent Subtractor (Cent Bin: %i, Pt Bin: %i, Eta Bin: %i) : ",i,j,k) << nEventsArrSub[i][j][k] << endl;
    cout << Form("NEvents Area*Rho Subtraction (Cent Bin: %i, Pt Bin: %i, Eta Bin: %i) : ",i,j,k) << nEventsArrNoSub[i][j][k] << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    histnum++;
   }
  }
 }

 //Merged eta ratios
 for(int index = 1; index<10; index++){
  TText *centralityLabel = new TText();
  centralityLabel->SetTextColor(1);
  centralityLabel->SetTextFont(1);
  centralityLabel->SetTextSize(0.1);
  centralityLabel->SetTextAngle(0);
  TText *ptLabel = new TText();
  ptLabel->SetTextColor(1);
  ptLabel->SetTextFont(1);
  ptLabel->SetTextSize(0.1);
  ptLabel->SetTextAngle(0);
  TText *etaLabel = new TText();
  etaLabel->SetTextColor(1);
  etaLabel->SetTextFont(1);
  etaLabel->SetTextSize(0.1);
  etaLabel->SetTextAngle(0);
  TText *trackPtLabel = new TText();
  trackPtLabel->SetTextColor(1);
  trackPtLabel->SetTextFont(1);
  trackPtLabel->SetTextSize(0.1);
  trackPtLabel->SetTextAngle(0);
  
  //Place the labels in he bottom left of the canvas to display information on the ratio selections
  if(index==1){
    c50->cd(7);
    ptLabel->DrawText(0.4,0.7,"15 GeV < Jet pt < 25 GeV");
    etaLabel->DrawText(0.4,0.3,"-0.7 < Jet eta < 0.7");

    if(minTrackPt == 1.0)   trackPtLabel->DrawText(0.4,0.5,"track pt > 1.0 GeV");
    else if(minTrackPt == 2.0) trackPtLabel->DrawText(0.4,0.5,"track pt > 2.0 GeV");

    c53->cd(7);
    ptLabel->DrawText(0.4,0.7,"Jet pt > 25 GeV");
    etaLabel->DrawText(0.4,0.3,"-0.7 < Jet eta < 0.7");

    if(minTrackPt == 1.0)   trackPtLabel->DrawText(0.4,0.5,"track pt > 1.0 GeV");
    else if(minTrackPt == 2.0) trackPtLabel->DrawText(0.4,0.5,"track pt > 2.0 GeV");

    c51->cd(7);
    ptLabel->DrawText(0.4,0.7,"15 GeV < Jet pt < 25 GeV");
    etaLabel->DrawText(0.4,0.3,"-0.7 < Jet eta < 0.7");

    if(minTrackPt == 1.0)   trackPtLabel->DrawText(0.4,0.5,"track pt > 1.0 GeV");
    else if(minTrackPt == 2.0) trackPtLabel->DrawText(0.4,0.5,"track pt > 2.0 GeV");

    c54->cd(7);
    ptLabel->DrawText(0.4,0.7,"Jet pt > 25 GeV");
    etaLabel->DrawText(0.4,0.3,"-0.7 < Jet eta < 0.7");

    if(minTrackPt == 1.0)   trackPtLabel->DrawText(0.4,0.5,"track pt > 1.0 GeV");
    else if(minTrackPt == 2.0) trackPtLabel->DrawText(0.4,0.5,"track pt> 2.0 GeV");

    c52->cd(7);
    ptLabel->DrawText(0.4,0.7,"15 GeV < Jet pt < 25 GeV");
    etaLabel->DrawText(0.4,0.3,"-0.7 < Jet eta < 0.7");

    if(minTrackPt == 1.0)   trackPtLabel->DrawText(0.4,0.5,"track pt > 1.0 GeV");
    else if(minTrackPt == 2.0) trackPtLabel->DrawText(0.4,0.5,"track pt > 2.0 GeV");

    c55->cd(7);
    ptLabel->DrawText(0.4,0.7,"Jet pt > 25 GeV");
    etaLabel->DrawText(0.4,0.3,"-0.7 < Jet eta < 0.7");

    if(minTrackPt == 1.0)   trackPtLabel->DrawText(0.4,0.5,"track pt > 1.0 GeV");
    else if(minTrackPt == 2.0) trackPtLabel->DrawText(0.4,0.5,"track pt > 2.0 GeV");

    c63->cd(7);
    ptLabel->DrawText(0.4,0.7,"15 GeV < Jet pt < 25 GeV");
    etaLabel->DrawText(0.4,0.3,"-0.7 < Jet eta < 0.7");

    if(minTrackPt == 1.0)   trackPtLabel->DrawText(0.4,0.5,"track pt > 1.0 GeV");
    else if(minTrackPt == 2.0) trackPtLabel->DrawText(0.4,0.5,"track pt > 2.0 GeV");

    c64->cd(7);
    ptLabel->DrawText(0.4,0.7,"Jet pt > 25 GeV");
    etaLabel->DrawText(0.4,0.3,"-0.7 < Jet eta < 0.7");

    if(minTrackPt == 1.0)   trackPtLabel->DrawText(0.4,0.5,"track pt > 1.0 GeV");
    else if(minTrackPt == 2.0) trackPtLabel->DrawText(0.4,0.5,"track pt > 2.0 GeV");

  }

  //Begin displaying the merged eta ratios
  if(index==1 || index==2 || index==3 || index==5 || index==6 || index==9){
   for(int j = 0; j<2; j++){
    
    if(j==0){

     c50->cd(index);
     gPad->SetGrid(0,0);
     kHistLeSubRatioEtaMergedNoSub[index-1][j]->Draw();
     if(index==1)        centralityLabel->DrawText(0.0,0.08,"(0-10)/(10-30)");
     else if(index==2)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(30-50)");
     else if(index==3)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(50-80)");
     else if(index==5)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(30-50)");
     else if(index==6)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(50-80)");
     else if(index==9)   centralityLabel->DrawText(0.0,0.08,"(30-50)/(50-80)");
     kHistLeSubRatioEtaMergedSub[index-1][j]->Draw("SAME");

     c63->cd(index);
     gPad->SetGrid(0,0);
     kHistLeSubRatioEtaMerged2TrackNoSub[index-1][j]->Draw();
     if(index==1)        centralityLabel->DrawText(0.0,0.08,"(0-10)/(10-30)");
     else if(index==2)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(30-50)");
     else if(index==3)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(50-80)");
     else if(index==5)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(30-50)");
     else if(index==6)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(50-80)");
     else if(index==9)   centralityLabel->DrawText(0.0,0.08,"(30-50)/(50-80)");
     kHistLeSubRatioEtaMerged2TrackSub[index-1][j]->Draw("SAME");

     c51->cd(index);
     gPad->SetGrid(0,0);
     kHistPtDRatioEtaMergedNoSub[index-1][j]->Draw();
     if(index==1)        centralityLabel->DrawText(0.0,0.08,"(0-10)/(10-30)");
     else if(index==2)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(30-50)");
     else if(index==3)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(50-80)");
     else if(index==5)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(30-50)");
     else if(index==6)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(50-80)");
     else if(index==9)   centralityLabel->DrawText(0.0,0.08,"(30-50)/(50-80)");
     kHistPtDRatioEtaMergedSub[index-1][j]->Draw("SAME");

     c52->cd(index);
     gPad->SetGrid(0,0);
     kHistAngularityRatioEtaMergedNoSub[index-1][j]->Draw();
     if(index==1)        centralityLabel->DrawText(0.0,0.08,"(0-10)/(10-30)");
     else if(index==2)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(30-50)");
     else if(index==3)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(50-80)");
     else if(index==5)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(30-50)");
     else if(index==6)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(50-80)");
     else if(index==9)   centralityLabel->DrawText(0.0,0.08,"(30-50)/(50-80)");
     kHistAngularityRatioEtaMergedSub[index-1][j]->Draw("SAME");

    }
    else if(j==1){
     c53->cd(index);
     gPad->SetGrid(0,0);
     kHistLeSubRatioEtaMergedNoSub[index-1][j]->Draw();
     if(index==1)        centralityLabel->DrawText(0.0,0.08,"(0-10)/(10-30)");
     else if(index==2)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(30-50)");
     else if(index==3)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(50-80)");
     else if(index==5)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(30-50)");
     else if(index==6)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(50-80)");
     else if(index==9)   centralityLabel->DrawText(0.0,0.08,"(30-50)/(50-80)");
     kHistLeSubRatioEtaMergedSub[index-1][j]->Draw("SAME");

     c64->cd(index);
     gPad->SetGrid(0,0);
     kHistLeSubRatioEtaMerged2TrackNoSub[index-1][j]->Draw();
     if(index==1)        centralityLabel->DrawText(0.0,0.08,"(0-10)/(10-30)");
     else if(index==2)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(30-50)");
     else if(index==3)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(50-80)");
     else if(index==5)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(30-50)");
     else if(index==6)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(50-80)");
     else if(index==9)   centralityLabel->DrawText(0.0,0.08,"(30-50)/(50-80)");
     kHistLeSubRatioEtaMerged2TrackSub[index-1][j]->Draw("SAME");

     c54->cd(index);
     gPad->SetGrid(0,0);
     kHistPtDRatioEtaMergedNoSub[index-1][j]->Draw();
     if(index==1)        centralityLabel->DrawText(0.0,0.08,"(0-10)/(10-30)");
     else if(index==2)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(30-50)");
     else if(index==3)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(50-80)");
     else if(index==5)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(30-50)");
     else if(index==6)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(50-80)");
     else if(index==9)   centralityLabel->DrawText(0.0,0.08,"(30-50)/(50-80)");
     kHistPtDRatioEtaMergedSub[index-1][j]->Draw("SAME");

     c55->cd(index);
     gPad->SetGrid(0,0);
     kHistAngularityRatioEtaMergedNoSub[index-1][j]->Draw();
     if(index==1)        centralityLabel->DrawText(0.0,0.08,"(0-10)/(10-30)");
     else if(index==2)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(30-50)");
     else if(index==3)   centralityLabel->DrawText(0.0,0.08,"(0-10)/(50-80)");
     else if(index==5)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(30-50)");
     else if(index==6)   centralityLabel->DrawText(0.0,0.08,"(10-30)/(50-80)");
     else if(index==9)   centralityLabel->DrawText(0.0,0.08,"(30-50)/(50-80)");
     kHistAngularityRatioEtaMergedSub[index-1][j]->Draw("SAME");

    }
   }
  }
 }

} 
