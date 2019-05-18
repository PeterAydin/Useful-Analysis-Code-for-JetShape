// ################################################################
// Author:  Joel Mazer for the STAR Collaboration
// Affiliation: Rutgers University
//
// ################################################################

#include "StAnMaker.h"

#include "StMemStat.h"

// ROOT includes
#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
#include <THnSparse.h>
#include "TParameter.h"
#include <TProfile.h>
#include "TRandom.h"
#include "TRandom3.h"

// STAR includes
#include "StThreeVectorF.hh"
#include "StPicoDstMaker/StPicoDst.h"
#include "StRoot/StPicoDstMaker/StPicoDstMaker.h"
#include "StMaker.h"

// my STAR includes
#include "StJetFrameworkPicoBase.h"
#include "StRhoParameter.h"
#include "StRho.h"
#include "StJetMakerTask.h"
#include "StFemtoTrack.h"

// new includes
#include "StRoot/StPicoEvent/StPicoEvent.h"
#include "StRoot/StPicoEvent/StPicoTrack.h"
#include "StRoot/StPicoEvent/StPicoBTowHit.h"
#include "StRoot/StPicoEvent/StPicoBTofHit.h"
#include "StRoot/StPicoEvent/StPicoEmcTrigger.h"
#include "StRoot/StPicoEvent/StPicoMtdTrigger.h"
#include "StRoot/StPicoEvent/StPicoBEmcPidTraits.h"
#include "StRoot/StPicoEvent/StPicoBTofPidTraits.h"
#include "StRoot/StPicoEvent/StPicoMtdPidTraits.h"

// old file kept
#include "StPicoConstants.h"

// centrality includes
#include "StRoot/StRefMultCorr/StRefMultCorr.h"
#include "StRoot/StRefMultCorr/CentralityMaker.h"

ClassImp(StAnMaker)

//-----------------------------------------------------------------------------
StAnMaker::StAnMaker(const char* name, StPicoDstMaker *picoMaker, const char* outName = "", const char* jetMakerName = "", const char* rhoMakerName = "") : StJetFrameworkPicoBase(name) //StMaker(name),
{
  fLeadingJet = 0x0; fSubLeadingJet = 0x0;
  fJets = 0x0 ;
  fRunNumber = 0;
  refCorr2 = 0.0;
  mPicoDstMaker = 0x0;
  mPicoDst = 0x0;
  mPicoEvent = 0x0;
  JetMaker = 0;
  RhoMaker = 0;
  grefmultCorr = 0;
  mOutName = outName;
  doUsePrimTracks = kFALSE;
  fDebugLevel = 0;
  fRunFlag = 0;       // see StAnMaker::fRunFlagEnum
  fCentralityDef = 4; // see StJetFrameworkPicoBase::fCentralityDefEnum
  fRequireCentSelection = kFALSE;
  fCentralitySelectionCut = -99;
  doBGSubs = kFALSE;
  fDoEffCorr = kFALSE;
  fCorrJetPt = kFALSE;
  fMinPtJet = 0.0;
  fJetConstituentCut = 2.0;
  fTrackBias = 0.0;
  fTowerBias = 0.0;
  fJetRad = 0.4;
  fEventZVtxMinCut = -40.0; fEventZVtxMaxCut = 40.0;
  fTrackPtMinCut = 2.0; fTrackPtMaxCut = 30.0; //Track pt cutoffs
  fTrackPhiMinCut = 0.0; fTrackPhiMaxCut = 2.0*TMath::Pi();
  fTrackEtaMinCut = -1.0; fTrackEtaMaxCut = 1.0;
  fTrackDCAcut = 3.0;
  fTracknHitsFit = 15; fTracknHitsRatio = 0.52;
  fTowerEMinCut = 0.2; fTowerEMaxCut = 100.0;
  fTowerEtaMinCut = -1.0; fTowerEtaMaxCut = 1.0;
  fTowerPhiMinCut = 0.0;  fTowerPhiMaxCut = 2.0*TMath::Pi();
  fCentralityScaled = 0.;
  ref16 = -99; ref9 = -99;
  Bfield = 0.0;
  mVertex = 0x0;
  zVtx = 0.0;
  fEmcTriggerEventType = 0; fMBEventType = 2;
  fRho = 0x0;
  fRhoVal = 0;
  fAnalysisMakerName = name;
  fJetMakerName = jetMakerName;
  fRhoMakerName = rhoMakerName;
  for(int i=0; i<8; i++) { fEmcTriggerArr[i] = 0; }

}

//----------------------------------------------------------------------------- 
StAnMaker::~StAnMaker()
{ /*  */

  if(fHistPtSpectraLeadingJet) delete fHistPtSpectraLeadingJet;
  if(fHistRatioLeadingInclusive) delete fHistRatioLeadingInclusive;
  if(fHistPtSpectraInclusive) delete fHistPtSpectraInclusive;
  if(fHistJetPhi) delete fHistJetPhi;
  if(fHistDPhiLeadingandAll) delete fHistDPhiLeadingandAll;
  if(fHistJetAreavsPt) delete fHistJetAreavsPt;
  if(fHistJetAreavsCorrPt) delete fHistJetAreavsCorrPt;

  //Subtractor Checking Histograms
  if(fHistConstitPt) delete fHistConstitPt;
  if(fHistAllTracksPt) delete fHistAllTracksPt;
  if(fHistEtaRefTracksPt) delete fHistEtaRefTracksPt;

  //Three variables
  if(fHistLeSubSig) delete fHistLeSubSig;
  if(fHistLeSubBG) delete fHistLeSubBG;
  if(fHistLeSubBGOOR) delete fHistLeSubBGOOR;
  if(fHistAngularitySig) delete fHistAngularitySig;
  if(fHistAngularityBG) delete fHistAngularityBG;
  if(fHistAngularityBGOOR) delete fHistAngularityBGOOR;
  if(fHistAngularityDistanceSig) delete fHistAngularityDistanceSig;
  if(fHistAngularityDistanceBG) delete fHistAngularityDistanceBG;
  if(fHistAngularityDistanceBGOOR) delete fHistAngularityDistanceBGOOR;
  if(fHistPtDSig) delete fHistPtDSig;
  if(fHistPtDBG) delete fHistPtDBG;
  if(fHistPtDBGOOR) delete fHistPtDBGOOR;

  for(int i = 0; i<4;i++){
    if(fHistNJetsCentBins[i]) delete fHistNJetsCentBins[i];
    if(fHistPtDCentSel[i]) delete fHistPtDCentSel[i];
    if(fHistLeSubCentSel[i]) delete fHistLeSubCentSel[i];
    if(fHistAngularityCentSel[i]) delete fHistAngularityCentSel[i];

    for(int j = 0; j<3;j++){
      for(int k = 0; k<2;k++){
	if(fHistPtD[i][j][k]) delete fHistPtD[i][j][k];
	if(fHistPtDPeaksNTracks[i][j][k]) delete fHistPtDPeaksNTracks[i][j][k];
        if(fHistPtDPeaksPtTracks[i][j][k]) delete fHistPtDPeaksPtTracks[i][j][k];

        if(j==0 || j==1){
	  if(fHistLeSubArrSig[i][j][k]) delete fHistLeSubArrSig[i][j][k];
          if(fHistLeSubArrSig2Track[i][j][k]) delete fHistLeSubArrSig2Track[i][j][k];
	  if(fHistLeSubArrBG[i][j][k]) delete fHistLeSubArrBG[i][j][k];
	  if(fHistAngularityArrSig[i][j][k]) delete fHistAngularityArrSig[i][j][k];
	  if(fHistAngularityArrBG[i][j][k]) delete fHistAngularityArrBG[i][j][k];
	  if(fHistAngularityArrSigBG[i][j][k]) delete fHistAngularityArrSigBG[i][j][k];
	  if(fHistPtDArrSig[i][j][k]) delete fHistPtDArrSig[i][j][k];
	  if(fHistPtDArrBG[i][j][k]) delete fHistPtDArrBG[i][j][k];
	  if(fHistPtDArrSigBG[i][j][k]) delete fHistPtDArrSigBG[i][j][k];

          if(fHistNJetsArr[i][j][k]) delete fHistNJetsArr[i][j][k];
	  if(fHistNEventsArr[i][j][k]) delete fHistNEventsArr[i][j][k];
        }
      }
    }
  }
  
  //LeSub Histograms
  if(fHistPtTrackSpectra) delete fHistPtTrackSpectra;
  if(fHistLeadingTrackPt) delete fHistLeadingTrackPt;
  if(fHistSubLeadingTrackPt) delete fHistSubLeadingTrackPt;

  //Out Of Eta Range Three Variable
  if(fHistLeSubOOR) delete fHistLeSubOOR;
  if(fHistAngularityOOR) delete fHistAngularityOOR;
  if(fHistPtDOOR) delete fHistPtDOOR;
  if(fHistAngularityDistanceOOR) delete fHistAngularityDistanceOOR;

  //High and Low Centrality Histograms
  if(fHistPtSpectraLeadingJetHighCent) delete fHistPtSpectraLeadingJetHighCent;
  if(fHistRatioLeadingInclusiveHighCent) delete fHistRatioLeadingInclusiveHighCent;
  if(fHistPtSpectraInclusiveHighCent) delete fHistPtSpectraInclusiveHighCent;
  if(fHistDPhiLeadingandAllHighCent) delete fHistDPhiLeadingandAllHighCent;
  if(fHistJetAreavsCorrPtHighCent) delete fHistJetAreavsCorrPtHighCent;

  if(fHistPtSpectraLeadingJetLowCent) delete fHistPtSpectraLeadingJetLowCent;
  if(fHistRatioLeadingInclusiveLowCent) delete fHistRatioLeadingInclusiveLowCent;
  if(fHistPtSpectraInclusiveLowCent) delete fHistPtSpectraInclusiveLowCent;
  if(fHistDPhiLeadingandAllLowCent) delete fHistDPhiLeadingandAllLowCent;
  if(fHistJetAreavsCorrPtLowCent) delete fHistJetAreavsCorrPtLowCent;


}

//-----------------------------------------------------------------------------
Int_t StAnMaker::Init() {
  StJetFrameworkPicoBase::Init();

  DeclareHistograms();

  // Jet TClonesArray
  fJets = new TClonesArray("StJet"); // will have name correspond to the Maker which made it
  //fJets->SetName(fJetsName);
  //fJets->SetOwner(kTRUE);

  // may not need, used for old RUNS
  // StRefMultCorr* getgRefMultCorr() ; // For grefmult //Run14 AuAu200GeV
  // switch on Run Flag to look for firing trigger specifically requested for given run period
  switch(fRunFlag) {
    case StJetFrameworkPicoBase::Run14_AuAu200 : // Run14 AuAu
        switch(fCentralityDef) {
          case StJetFrameworkPicoBase::kgrefmult :
              grefmultCorr = CentralityMaker::instance()->getgRefMultCorr();
              break;
          case StJetFrameworkPicoBase::kgrefmult_P17id_VpdMB30 :
              grefmultCorr = CentralityMaker::instance()->getgRefMultCorr_P17id_VpdMB30();
              break;
          case StJetFrameworkPicoBase::kgrefmult_P16id :
              grefmultCorr = CentralityMaker::instance()->getgRefMultCorr_P16id();
              break;
          default: // this is the default for Run14
              grefmultCorr = CentralityMaker::instance()->getgRefMultCorr();
        }
        break;

    case StJetFrameworkPicoBase::Run16_AuAu200 : // Run16 AuAu
        switch(fCentralityDef) {      
          case StJetFrameworkPicoBase::kgrefmult :
              grefmultCorr = CentralityMaker::instance()->getgRefMultCorr();
              break;
          case StJetFrameworkPicoBase::kgrefmult_P16id :
              grefmultCorr = CentralityMaker::instance()->getgRefMultCorr_P16id();
              break;
          case StJetFrameworkPicoBase::kgrefmult_VpdMBnoVtx : 
              grefmultCorr = CentralityMaker::instance()->getgRefMultCorr_VpdMBnoVtx();
              break;
          case StJetFrameworkPicoBase::kgrefmult_VpdMB30 : 
              grefmultCorr = CentralityMaker::instance()->getgRefMultCorr_VpdMB30();
              break;
          default:
              grefmultCorr = CentralityMaker::instance()->getgRefMultCorr_P16id();
        }
        break;

    default :
        grefmultCorr = CentralityMaker::instance()->getgRefMultCorr();
  }

  return kStOK;
}

//----------------------------------------------------------------------------- 
Int_t StAnMaker::Finish() { 
  //  Summarize the run.
  cout << "StAnMaker::Finish()\n";

  //  Write histos to file and close it.
  if(mOutName!="") {
    TFile *fout = new TFile(mOutName.Data(), "UPDATE");
    fout->cd();
    fout->mkdir(fAnalysisMakerName);
    fout->cd(fAnalysisMakerName);
    WriteHistograms();
    fout->cd();
    fout->Write();
    fout->Close();
  }

  cout<<"End of StAnMaker::Finish"<<endl;
  StMemStat::PrintMem("End of Finish...");

  return kStOK;
}

//-----------------------------------------------------------------------------
void StAnMaker::DeclareHistograms() {

  //Standardized binning for the various types of histograms
  int nBinsPt = 6;
  Double_t ptedges[7] = {0.0,10.0,20.0,30.0,40.0,50.0,100.0}; 
 
  //ptD binning
  int nBinsPtD = 33;
  double minPtD = 0.0;
  double maxPtD = 1.0;

  //LeSub binning
  int nBinsLeSub = 32;
  double maxXLeSub = 32.0;

  //Angularity binning
  int nBinsAngularity = 20;
  double maxXAngularity = 0.3;

  //Pt spectra binning
  double maxPt = 50.0;
  double minPt = 0.0;
  int nBinsPtS = 50;

  //Multiplicity binning
  double multMin = 0.0;
  double multMax = 800.0;
  int nBinsMult = 160;

  
  fHistPtSpectraLeadingJet = new TH1F("fHistPtSpectraLeadingJet","BG Sub P_{T} spectra of leading jet;P_{T} of leading jet (GeV);Occurances",nBinsPt,ptedges);
  fHistRatioLeadingInclusive = new TH1F("fHistRatioLeadingInclusive","Ratio of Leading/Inclusive;Ratio",nBinsPt,ptedges);
  fHistPtSpectraInclusive = new TH1F("fHistPtSpectraInclusiveJet","P_{T} spectra of inclusive jet;P_{T} of inclusive (GeV);Occuraces",nBinsPtS,minPt,maxPt);
  fHistJetPhi = new TH1F("fHistJetPhi","#phi spectra of Jets;#phi",30,-2*TMath::Pi(),2*TMath::Pi());
  fHistDPhiLeadingandAll = new TH1F("fHistDPhiLeadingandAll","Angular Difference between Leading and All Jets;dPhi (Radians);Occurances",20,0.0,TMath::Pi());
  fHistBGSubPtSpectraInc = new TH1F("fHistBGSubPtSpectraInc","Background Subtracted P_{T} spectra of inclusive jet; Corrected Jet p_{T};Occurances",40,0.0,100.0);
  fHistJetAreavsPt = new TH2F("fHistJetAreavsPt","Jet Area vs Jet P_{T};Jet P_{T} (GeV);Jet Area",50,10.0,80.0,60,0.0,1.0);
  fHistJetAreavsCorrPt = new TH2F("fHistJetAreavsCorrPt","Jet Area vs Corrected Jet P_{T};Jet P_{T} - Jet Area*Rho;JetArea",50,0.0,40.0,60,0.0,1.0);
  
  fHistConstitPt = new TH1F("fHistConstitPt","Track Constituents P_{T};P_{T}",nBinsPtS,minPt,maxPt);
  fHistAllTracksPt = new TH1F("fHistAllTracksPt","All Tracks P_{T};P_{T}",nBinsPtS,minPt,maxPt);
  fHistEtaRefTracksPt = new TH1F("fHistEtaRefTracksPt","Eta Ref Tracks P_{T};P_{T}",nBinsPtS,minPt,maxPt);


  //Jet Shape Histograms

  fHistLeSubSig = new TH1F("fHistLeSubSig","LeSub Signal (|Jet #eta| < 0.3);LeSub (GeV/c)",nBinsLeSub,0.0,maxXLeSub);
  fHistLeSubBG = new TH1F("fHistLeSubBG","LeSub (#phi reflected);LeSub (GeV/c)",nBinsLeSub,0.0,maxXLeSub);
  fHistLeSubBGOOR = new TH1F("fHistLeSubBGOOR","LeSub (#eta reflected);LeSub (GeV/c)",nBinsLeSub,0.0,maxXLeSub);

  fHistAngularitySig = new TH1F("fHistAngularitySig","Angularity Signal (|Jet #eta| < 0.3);g",nBinsAngularity,0.0,maxXAngularity);
  fHistAngularityBG = new TH1F("fHistAngularityBG","Angularity #phi reflected;g",nBinsAngularity,0.0,maxXAngularity);
  fHistAngularityBGOOR = new TH1F("fHistAngularityBGOOR","Angularity #eta reflected;g",nBinsAngularity,0.0,maxXAngularity);

  fHistAngularityDistanceSig = new TH1F("fHistAngularityDistanceSig","#DeltaR in #eta #phi space (Signal) (|Jet #eta| < 0.3);#DeltaR",10,0.0,0.5);
  fHistAngularityDistanceBG = new TH1F("fHistAngularityDistanceBG","#phi reflected #DeltaR in #eta #phi space;#DeltaR",10,0.0,0.8);
  fHistAngularityDistanceBGOOR = new TH1F("fHistAngularityDistanceBGOOR","#eta reflected #DeltaR in #eta #phi space;#DeltaR",10,0.0,0.8);

  fHistPtDSig = new TH1F("fHistPtDSig","Momentum Dispersion Signal (|Jet #eta| < 0.3);ptD",nBinsPtD,minPtD,maxPtD);
  fHistPtDBG = new TH1F("fHistPtDBG","Momentum Dispersion (ptD) (#phi reflected);ptD",nBinsPtD,minPtD,maxPtD);
  fHistPtDBGOOR = new TH1F("fHistPtDBGOOR","Momentum Dispersion (ptD) (#eta reflected);ptD",nBinsPtD,minPtD,maxPtD);
  
  for(int i = 0; i<4;i++){
    fHistNJetsCentBins[i] = new TH1F(Form("fHistNJetsCentBins_%i",i), "counter for Njets In Specified Bins", 10, 0.0, 10.0);
    fHistPtDCentSel[i] = new TH1F(Form("fHistPtDCentSel_%i",i), Form("ptD for CentBin %i",i), nBinsPtD, minPtD, maxPtD);
    fHistLeSubCentSel[i] = new TH1F(Form("fHistLeSubCentSel_%i",i), Form("LeSub for CentBin %i",i), nBinsLeSub, 0.0, maxXLeSub);
    fHistAngularityCentSel[i] = new TH1F(Form("fHistAngularityCentSel_%i",i), Form("g for CentBin %i",i), nBinsAngularity, 0.0, maxXAngularity);

    for(int j = 0; j<3;j++){
      for(int k = 0; k<2;k++){
        fHistPtD[i][j][k] = new TH1F(Form("fHistPtD_%i_%i_%i",i,j,k), Form("ptD for CentBin %i, JetPtBin %i, IRorOORBin %i;ptD",i,j,k), nBinsPtD, minPtD, maxPtD);
	fHistPtDPeaksPtTracks[i][j][k] = new TH1F(Form("fHistPtDPeaksPtTracks_%i_%i_%i",i,j,k), Form("pt Spectra of Tracks in CentBin %i, ptD Range %i, IRorOORBin %i;p_{T}",i,j,k),25,0.0,25.0);
        fHistPtDPeaksNTracks[i][j][k] = new TH1F(Form("fHistPtDPeaksNTracks_%i_%i_%i",i,j,k), Form("N Tracks for given CentBin %i, ptD Range %i, IRorOORBin %i;N Tracks",i,j,k),20,0.0,20.0);

	if(j==0 || j==1){
	  fHistLeSubArrSig[i][j][k] = new TH1F(Form("fHistLeSubArrSig_%i_%i_%i",i,j,k), Form("LeSub Signal, Cent Bin %i, pT Bin %i, IRorOOR %i;LeSub;1/NJets",i,j,k),nBinsLeSub,0.0,maxXLeSub);
	  fHistLeSubArrSig2Track[i][j][k] = new TH1F(Form("fHistLeSubArrSig2Track_%i_%i_%i",i,j,k), Form("LeSub Signal, Cent Bin %i, pT Bin $i, IRorOOR %i;LeSub;1/Njets 1/binWidth",i,j,k),nBinsLeSub,0.0,maxXLeSub);
	  fHistLeSubArrBG[i][j][k] = new TH1F(Form("fHistLeSubArrBG_%i_%i_%i",i,j,k), Form("LeSub BG, Cent Bin %i, pT Bin %i, IRorOOR %i;LeSub;1/NJets",i,j,k),nBinsLeSub,0.0,maxXLeSub);

	  fHistAngularityArrSig[i][j][k] = new TH1F(Form("fHistAngularityArrSig_%i_%i_%i",i,j,k), Form("g Signal, Cent Bin %i, pT Bin %i, IRorOOR %i;g;1/NJets",i,j,k),nBinsAngularity,0.0,maxXAngularity);
	  fHistAngularityArrBG[i][j][k] = new TH1F(Form("fHistAngularityArrBG_%i_%i_%i",i,j,k), Form("g BG, Cent Bin %i, pT Bin %i, IRorOOR %i;g;1/NJets",i,j,k),nBinsAngularity,0.0,maxXAngularity);
          fHistAngularityArrSigBG[i][j][k] = new TH1F(Form("fHistAngularityArrSigBG_%i_%i_%i",i,j,k), Form("g BG and Signal, Cent Bin %i, pT Bin %i, IRorOOR %i;g;1/nJets",i,j,k),nBinsAngularity,0.0,maxXAngularity);

	  fHistPtDArrSig[i][j][k] = new TH1F(Form("fHistPtDArrSig_%i_%i_%i",i,j,k), Form("ptD Signal, Cent Bin %i, pT Bin %i, IRorOOR %i;ptD;1/NJets",i,j,k),nBinsPtD,minPtD,maxPtD);
	  fHistPtDArrBG[i][j][k] = new TH1F(Form("fHistPtDArrBG_%i_%i_%i",i,j,k), Form("ptD BG, Cent Bin %i, pT Bin %i, IRorOOR %i;ptD;1/NJets",i,j,k),nBinsPtD,minPtD,maxPtD);
	  fHistPtDArrSigBG[i][j][k] = new TH1F(Form("fHistPtDArrSigBG_%i_%i_%i",i,j,k), Form("PtD Signal and BG, Cent Bin %i, pT Bin %i, IRorOOR %i, ptD;1/NJets",i,j,k),nBinsPtD,minPtD,maxPtD);

	  fHistNJetsArr[i][j][k] = new TH1F(Form("fHistNJetsArr_%i_%i_%i",i,j,k), "counter for NJets In specified bins",10,0.0,5.0);
	  fHistNEventsArr[i][j][k] = new TH1F(Form("fHistNEventsArr_%i_%i_%i",i,j,k), "counter for NEvents In specified bins",10,0.0,5.0);
	}
      }
    }
  }



  fHistLeSubOOR = new TH1F("fHistLeSubOOR","LeSub Signal (|Jet #eta| > 0.3);LeSub (GeV/c)",nBinsLeSub,0.0,maxXLeSub);
  fHistAngularityOOR = new TH1F("fHistAngularityOOR","Angularity Signal (|Jet #eta| > 0.3);g",nBinsAngularity,0.0,maxXAngularity);
  fHistPtDOOR = new TH1F("fHistPtDOOR","Momentum Dispersion Signal (|Jet #eta| > 0.3);ptD",nBinsPtD,minPtD,maxPtD);
  fHistAngularityDistanceOOR = new TH1F("fHistAngularityDistanceOOR","#DeltaR in #eta #phi space Signal(|Jet #eta| > 0.3) ;#DeltaR",10,0.0,0.5);


  //LeSub Histograms
  fHistPtTrackSpectra = new TH1F("fHistPtTrackSpectra","p_{T tracks} Spectra;p_{T}",nBinsPtS,minPt,maxPt);
  fHistLeadingTrackPt = new TH1F("fHistLeadingTrackPt","Leading Track p_{T};p_{T}",nBinsPtS,minPt,maxPt);
  fHistSubLeadingTrackPt = new TH1F("fHistSubLeadingTrackPt","Sub Leading Track p_{T};p_{T}",nBinsPtS,minPt,maxPt);

  //High and Low Centrality Specific Histograms

  fHistPtSpectraLeadingJetHighCent = new TH1F("fHistPtSpectraLeadingJetHighCent","P_{T} spectra of leading jet (0-20% Centrality);P_{T} of leading jet (GeV);Occurances",nBinsPtS,minPt,maxPt); 
  fHistRatioLeadingInclusiveHighCent = new TH1F("fHistRatioLeadingInclusiveHighCent","Ratio of Leading/Inclusive (0-20% Centrality);Ratio",nBinsPt,ptedges);
  fHistPtSpectraInclusiveHighCent = new TH1F("fHistPtSpectraInclusiveJetHighCent","P_{T} spectra of inclusive jet (0-20% Centrality);P_{T} of inclusive (GeV);Occuraces",nBinsPtS,minPt,maxPt);
  fHistDPhiLeadingandAllHighCent = new TH1F("fHistDPhiLeadingandAllHighCent","dPhi between Leading and All Jets (0-20% Centrality);dPhi (Radians);Occurances",20,0.0,TMath::Pi());
  fHistJetAreavsCorrPtHighCent = new TH2F("fHistJetAreavsCorrPtHighCent","Jet Area vs Corrected Jet P_{T} (0-20% Centrality);Jet P_{T} - Jet Area*Rho;JetArea",50,0.0,40.0,60,0.0,1.0);

  fHistPtSpectraLeadingJetLowCent = new TH1F("fHistPtSpectraLeadingJetLowCent","P_{T} spectra of leading jet (40-80% Centrality);P_{T} of leading jet (GeV);Occurances",nBinsPtS,minPt,maxPt);
  fHistRatioLeadingInclusiveLowCent = new TH1F("fHistRatioLeadingInclusiveLowCent","Ratio of Leading/Inclusive (40-80% Centrality);Ratio",nBinsPt,ptedges);
  fHistPtSpectraInclusiveLowCent = new TH1F("fHistPtSpectraInclusiveJetLowCent","P_{T} spectra of inclusive jet (40-80% Centrality);P_{T} of inclusive (GeV);Occuraces",nBinsPtS,minPt,maxPt);
  fHistDPhiLeadingandAllLowCent = new TH1F("fHistDPhiLeadingandAllLowCent","dPhi between Leading and All Jets (40-80% Centrality);dPhi (Radians);Occurances",20,0.0,TMath::Pi());
  fHistJetAreavsCorrPtLowCent = new TH2F("fHistJetAreavsCorrPtLowCent","Jet Area vs Corrected Jet P_{T} (40-80% Centrality);Jet P_{T} - Jet Area*Rho;JetArea",50,0.0,40.0,60,0.0,1.0);

  //Optional Stylings for the histograms

  fHistJetAreavsPt->SetOption("COLZ");
  fHistJetAreavsCorrPt->SetOption("COLZ");
  fHistJetAreavsCorrPtLowCent->SetOption("COLZ");
  fHistJetAreavsCorrPtHighCent->SetOption("COLZ");

  SetSumw2();
}

// write histograms
//_____________________________________________________________________________
void StAnMaker::WriteHistograms() {
   
  fHistPtSpectraLeadingJet->Write();
  fHistRatioLeadingInclusive->Write();
  fHistPtSpectraInclusive->Write();
  fHistJetPhi->Write();
  fHistDPhiLeadingandAll->Write();
  fHistBGSubPtSpectraInc->Write();
  fHistJetAreavsPt->Write();
  fHistJetAreavsCorrPt->Write();
 
  fHistConstitPt->Write();
  fHistAllTracksPt->Write();
  fHistEtaRefTracksPt->Write(); 
 
  //Jet Shape Histos

  fHistLeSubSig->Write();
  fHistLeSubBG->Write();
  fHistLeSubOOR->Write();
  fHistLeSubBGOOR->Write();
   
  fHistPtTrackSpectra->Write();
  fHistLeadingTrackPt->Write();
  fHistSubLeadingTrackPt->Write();

  fHistAngularitySig->Write();
  fHistAngularityBG->Write();
  fHistAngularityOOR->Write();
  fHistAngularityBGOOR->Write();

  fHistAngularityDistanceSig->Write();
  fHistAngularityDistanceBG->Write();
  fHistAngularityDistanceOOR->Write();
  fHistAngularityDistanceBGOOR->Write();
 
  fHistPtDSig->Write();
  fHistPtDBG->Write();
  fHistPtDOOR->Write();
  fHistPtDBGOOR->Write();

  //Arrays
  for(int i = 0; i<4;i++){
    fHistNJetsCentBins[i]->Write();
    fHistPtDCentSel[i]->Write();
    fHistLeSubCentSel[i]->Write();
    fHistAngularityCentSel[i]->Write();
  
    for(int j = 0; j<3;j++){
      for(int k = 0; k<2;k++){
        fHistPtD[i][j][k]->Write();
        fHistPtDPeaksNTracks[i][j][k]->Write();
        fHistPtDPeaksPtTracks[i][j][k]->Write();

        if(j==0 || j==1){
	  fHistLeSubArrSig[i][j][k]->Write();
          fHistLeSubArrSig2Track[i][j][k]->Write();
	  fHistLeSubArrBG[i][j][k]->Write();

	  fHistAngularityArrSig[i][j][k]->Write();
	  fHistAngularityArrBG[i][j][k]->Write();
	  fHistAngularityArrSigBG[i][j][k]->Write();

	  fHistPtDArrSig[i][j][k]->Write();
	  fHistPtDArrBG[i][j][k]->Write();
	  fHistPtDArrSigBG[i][j][k]->Write();

	  fHistNJetsArr[i][j][k]->Write();
	  fHistNEventsArr[i][j][k]->Write();
        }
      }
    }
  }


  //High and Low Centrality Histograms
  fHistPtSpectraLeadingJetHighCent->Write();
  fHistRatioLeadingInclusiveHighCent->Write();
  fHistPtSpectraInclusiveHighCent->Write();
  fHistDPhiLeadingandAllHighCent->Write();
  fHistJetAreavsCorrPtHighCent->Write();

  fHistPtSpectraLeadingJetLowCent->Write();
  fHistRatioLeadingInclusiveLowCent->Write();
  fHistPtSpectraInclusiveLowCent->Write();
  fHistDPhiLeadingandAllLowCent->Write();
  fHistJetAreavsCorrPtLowCent->Write();

}

// OLD user code says: //  Called every event after Make(). 
//_____________________________________________________________________________
void StAnMaker::Clear(Option_t *opt) {
  fJets->Clear();

}
 
//  This method is called every event.
//_____________________________________________________________________________
Int_t StAnMaker::Make() {
  bool fHaveEmcTrigger = kFALSE;
  bool fHaveMBevent = kFALSE;

  // get PicoDstMaker 
  mPicoDstMaker = static_cast<StPicoDstMaker*>(GetMaker("picoDst"));
  if(!mPicoDstMaker) {
    LOG_WARN << " No PicoDstMaker! Skip! " << endm;
    return kStWarn;
  }

  // construct PicoDst object from maker
  mPicoDst = static_cast<StPicoDst*>(mPicoDstMaker->picoDst());
  if(!mPicoDst) {
    LOG_WARN << " No PicoDst! Skip! " << endm;
    return kStWarn;
  }

  // create pointer to PicoEvent 
  mPicoEvent = static_cast<StPicoEvent*>(mPicoDst->event());
  if(!mPicoEvent) {
    LOG_WARN << " No PicoEvent! Skip! " << endm;
    return kStWarn;
  }

  // get event B (magnetic) field
  Bfield = mPicoEvent->bField(); 

  // get vertex 3-vector and z-vertex component
  mVertex = mPicoEvent->primaryVertex();
  zVtx = mVertex.z();
  
  // Z-vertex cut 
  // the Aj analysis cut on (-40, 40) for reference
  if((zVtx < fEventZVtxMinCut) || (zVtx > fEventZVtxMaxCut)) return kStOk; //kStWarn;

  // get the Run #, fill, and event ID
  Int_t RunId = mPicoEvent->runId();
  fRunNumber = mPicoEvent->runId();
  Int_t fillId = mPicoEvent->fillId();
  Int_t eventId = mPicoEvent->eventId();
  Double_t fBBCCoincidenceRate = mPicoEvent->BBCx();
  Double_t fZDCCoincidenceRate = mPicoEvent->ZDCx();

  // ============================ CENTRALITY ============================== //
  // https://github.com/star-bnl/star-phys/blob/master/StRefMultCorr/Centrality_def_grefmult.txt
  int grefMult = mPicoEvent->grefMult();
  int refMult = mPicoEvent->refMult();
  Int_t centbin, cent9, cent16;
  Double_t refCorr2;

  if(!doppAnalysis) {
    // initialize event-by-event by RunID
    grefmultCorr->init(RunId);
    if(doUseBBCCoincidenceRate) { grefmultCorr->initEvent(grefMult, zVtx, fBBCCoincidenceRate); } // default
    else{ grefmultCorr->initEvent(grefMult, zVtx, fZDCCoincidenceRate); }

    // get centrality bin: either 0-7 or 0-15
    cent16 = grefmultCorr->getCentralityBin16();
    if(cent16 == -1) return kStWarn; // maybe kStOk; - this is for lowest multiplicity events 80%+ centrality, cut on them
    cent9 = grefmultCorr->getCentralityBin9();

    // re-order binning to be from central -> peripheral
    ref9 = GetCentBin(cent9, 9);
    ref16 = GetCentBin(cent16, 16);
    centbin = GetCentBin(cent16, 16);  // 0-16

    // calculate corrected multiplicity
    if(doUseBBCCoincidenceRate) { refCorr2 = grefmultCorr->getRefMultCorr(grefMult, zVtx, fBBCCoincidenceRate, 2);
    } else{ refCorr2 = grefmultCorr->getRefMultCorr(grefMult, zVtx, fZDCCoincidenceRate, 2); }

  } else {
    centbin = 0, cent9 = 0, cent16 = 0, refCorr2 = 0.0, ref9 = 0, ref16 = 0;
  }

  // cut on unset centrality, > 80%
  if(cent16 == -1) return kStWarn; // maybe kStOk; - this is for lowest multiplicity events 80%+ centrality, cut on them 
  fCentralityScaled = centbin*5.0;

  // cut on centrality for analysis before doing anything
  if(fRequireCentSelection) { if(!SelectAnalysisCentralityBin(centbin, fCentralitySelectionCut)) return kStOk; }
  // ============================ end of CENTRALITY ============================== //

  // ========================= Trigger Info =============================== //
  // looking at the EMCal triggers - used for QA and deciding on HT triggers
  // trigger information:  // cout<<"istrigger = "<<mPicoEvent->isTrigger(450021)<<endl;
  FillEmcTriggers();

  // get trigger IDs from PicoEvent class and loop over them
  vector<unsigned int> mytriggers = mPicoEvent->triggerIds();
  if(fDebugLevel == StJetFrameworkPicoBase::kDebugEmcTrigger) cout<<"EventTriggers: ";
  for(unsigned int i=0; i<mytriggers.size(); i++){
    if(fDebugLevel == StJetFrameworkPicoBase::kDebugEmcTrigger) cout<<"i = "<<i<<": "<<mytriggers[i] << ", ";
  }
  if(fDebugLevel == StJetFrameworkPicoBase::kDebugEmcTrigger) cout<<endl;

  // check for MB/HT event
  fHaveMBevent = CheckForMB(fRunFlag, fMBEventType);
  fHaveEmcTrigger = CheckForHT(fRunFlag, fEmcTriggerEventType);
  // ======================== end of Triggers ============================= //

  // ================= JetMaker ================ //
  // get JetMaker
  JetMaker = static_cast<StJetMakerTask*>(GetMaker(fJetMakerName));
  const char *fJetMakerNameCh = fJetMakerName;
  if(!JetMaker) {
    LOG_WARN << Form(" No %s! Skip! ", fJetMakerNameCh) << endm;
    return kStWarn;
  }

  // get jet collection associated with JetMaker
  //if(!doBGSubs)	{fJets = static_cast<TClonesArray*>(JetMaker->GetJets()); cout << " Subtractor Not used " << endl; 
  //} else { fJets = static_cast<TClonesArray*>(JetMaker->GetJetsBGsub()); cout << " Subtractor Used " << endl;}
  fJets = static_cast<TClonesArray*>(JetMaker->GetJetsBGsub());
  if(!fJets) {
    LOG_WARN << Form(" No fJets object! Skip! ") << endm;
    return kStWarn;
  }

  // ============== RhoMaker =============== //
  // get RhoMaker from event: old names "StRho_JetsBG"
  RhoMaker = static_cast<StRho*>(GetMaker(fRhoMakerName));
  const char *fRhoMakerNameCh = fRhoMakerName;
  if(!RhoMaker) {
    LOG_WARN << Form(" No %s! Skip! ", fRhoMakerNameCh) << endm;
    return kStWarn;
  }

  // set rho object, alt fRho = GetRhoFromEvent(fRhoName);
  fRho = static_cast<StRhoParameter*>(RhoMaker->GetRho());
  if(!fRho) {
    LOG_WARN << Form("Couldn't get fRho object! ") << endm;
    return kStWarn;    
  } 
  
  // get rho/area value from rho object     fRho->ls("");
  fRhoVal = fRho->GetVal();

  // get number of jets, tracks, and global tracks in events
  Int_t njets = fJets->GetEntries();
  const Int_t ntracks = mPicoDst->numberOfTracks();
  Int_t nglobaltracks = mPicoEvent->numberOfGlobalTracks();

  //cout<<"njets: "<<njets<<"  ntracks: "<<ntracks<<"  nglobaltracks: "<<nglobaltracks<<endl;
  //return kStOK;

  // run Jets:
  RunJets();

  // run Tracks:
  RunTracks();

  // run Towers:
  RunTowers();

  return kStOK;
}

//_____________________________________________________________________________________________
void StAnMaker::RunJets()
{
  // test - redefining jets clonesarray
  TClonesArray *fJets2;
  
  if(doBGSubs)  fJets2 = static_cast<TClonesArray*>(JetMaker->GetJetsBGsub());
  else		fJets2 = static_cast<TClonesArray*>(JetMaker->GetJets()); 

  // cache the leading + subleading jets within acceptance
  // first parameter is Jet Maker name, 2nd is Rho Parameter: fRho
  fLeadingJet = GetLeadingJet(fJetMakerName);
  fSubLeadingJet = GetSubLeadingJet(fJetMakerName);

  double leadingjetpt = 0.0;
  double leadingjetphi = 0.0;
  
  // ====================== Jet loop below ============================
  // loop over Jets in the event: initialize some parameter variables
  Int_t ijethi = -1;
  Double_t highestjetpt = 0.0;
  int njets = fJets2->GetEntries();
  
  //cout<<"njets2: "<<njets<<endl;

  //Arrays to keep track of jetpt outside of the jet forloop
  double jetpts[njets];
  double jetphis[njets];
  
  //Booleans to make sure events are only counted once per event as they should be
  bool eventCounted = false;
  bool irEventCounted = false;
  bool oorEventCounted = false;
  

  // loop over jets
  for(int ijet = 0; ijet < njets; ijet++) {  // JET LOOP
    StJet *jet = static_cast<StJet*>(fJets2->At(ijet));
    if(!jet) continue;
    
    // get some jet parameters
    double jetarea = jet->Area();
    double jetpt = jet->Pt();
    double corrjetpt = 0.0;
    if(doBGSubs) {corrjetpt = jet->Pt();}
    else 	 {corrjetpt = jet->Pt() - jetarea*fRhoVal;}
    double jetE = jet->E();
    double jetEta = jet->Eta();
    double jetPhi = jet->Phi();
    double jetNEF = jet->NEF();
    double nconstituents = jet->GetNumberOfConstituents();

    //Jet Selections
    bool jetInEtaRange = (jetEta < 0.3 && jetEta > -0.3);
    bool JetAboveMinimum = (corrjetpt >= fMinPtJet); //fMinPtJet provided by ReadPico
    

    if(!JetAboveMinimum) {continue;} //Save time and skip forloop if the jet doesn't reach its required pt

    int centBin = 0;
    int ptBin = 0;
    int ptBin2 = 0;
    int irBin = 0;

    int nGoodTracks = 0;

    //Get Jet Constituent Vector 
    vector<fastjet::PseudoJet> fConstituents = jet->GetJetConstituents();

    int nconstituentTracks = 0;
    if(doBGSubs) {nconstituentTracks = fConstituents.size();}
    else         {nconstituentTracks = jet->GetNumberOfTracks();}

    float trackConstitsPt[nconstituentTracks];

    if(nconstituentTracks == 1) {continue;} //We want jets with more than 1 constituent track. Comment out line if necesary


    //Find bins for arrays
    centBin = GetCentralityBin(fCentralityScaled);
    ptBin = GetPtBin(corrjetpt);
    ptBin2 = GetPtBin2(corrjetpt);
    irBin = GetIRBin(jetInEtaRange);

    //Counter for specific centralities
    fHistNJetsCentBins[centBin]->Fill(1.0);

    //Counting events that have ATLEAST one jet above the minimum pt
    if(!eventCounted){ //assuring no double count
      eventCounted = true;
      fHistNEventsArr[centBin][ptBin2][irBin]->Fill(1.0);
    }   

    //Counting events that have ATLEAST one jet IR or OOR and above the min pt
    if(!irEventCounted && jetInEtaRange){
      irEventCounted = true;
    }
    else if(!oorEventCounted && !jetInEtaRange){
      oorEventCounted = true;
    }


    jetpts[ijet] = corrjetpt;
    jetphis[ijet] = jetPhi;

    //Variables needed for any jet shape calculations
  
    float angularitySig = 0.0;
    float angularityBGEta = 0.0;
    float angularityBGPhi = 0.0;

    float subleadingtrackptSig = 0.0;
    float leadingtrackptSig = 0.0;
    float subleadingtrackptBGEta = 0.0;
    float leadingtrackptBGEta = 0.0;
    float subleadingtrackptBGPhi = 0.0;
    float leadingtrackptBGPhi = 0.0;

    float ptDValueSig= 0.0;
    float ptDValueBGEta = 0.0;
    float ptDValueBGPhi = 0.0;
    float pdisnumeratorsumSig = 0.0;
    float pdisdenominatorsumSig = 0.0;
    float pdisnumeratorsumBGEta = 0.0;
    float pdisdenominatorsumBGEta = 0.0;
    float pdisnumeratorsumBGPhi = 0.0;
    float pdisdenominatorsumBGPhi = 0.0;

    // get nTracks and maxTrackPt
    double maxtrackpt = jet->GetMaxTrackPt();
    double NtrackConstit = jet->GetNumberOfTracks();

    // highest Pt jet in event (leading jet) calculation
    if(highestjetpt<corrjetpt){
      ijethi=ijet;
      highestjetpt=corrjetpt;
      leadingjetpt=corrjetpt;
      leadingjetphi=jetPhi;
    }

    //filling whatever histograms I can right now
    fHistPtSpectraInclusive->Fill(corrjetpt);
    fHistJetPhi->Fill(jetPhi);
    fHistBGSubPtSpectraInc->Fill(corrjetpt);

    fHistJetAreavsPt->Fill(jetpt,jetarea);
    fHistJetAreavsCorrPt->Fill(corrjetpt,jetarea);

    //Centrality Specific Fills
    if(fCentralityScaled <= 20){
        fHistPtSpectraInclusiveHighCent->Fill(corrjetpt);
        fHistJetAreavsCorrPtHighCent->Fill(corrjetpt,jetarea);
    }
    else if(fCentralityScaled >= 40 && fCentralityScaled <= 80){
        fHistPtSpectraInclusiveLowCent->Fill(corrjetpt);
        fHistJetAreavsCorrPtLowCent->Fill(corrjetpt,jetarea);
    }


    //Track Constit Loop
    for(int itrk = 0; itrk< nconstituentTracks; itrk++){
      double pt = 0.0;
      double eta = 0.0;
      double phi = 0.0;
      double px = 0.0;
      double py = 0.0;
      double pz = 0.0;
      short charge = 0.0;

      //Data if using BG Subtractor
      if(doBGSubs){
          //get user defined index
          Int_t uid = fConstituents[itrk].user_index();
          pt = fConstituents[itrk].perp();
          eta = fConstituents[itrk].eta();
          phi = fConstituents[itrk].phi();
  
          StPicoTrack* trk = static_cast<StPicoTrack*>(mPicoDst->track(uid));
          if(!trk){ continue; }
     
          if(!AcceptTrack(trk, Bfield, mVertex)) { continue; }
      }
      else{ //Data if not using Subtractor
      	  int trackid = jet->TrackAt(itrk);      
      	  StPicoTrack* trk = static_cast<StPicoTrack*>(mPicoDst->track(trackid));
      	  if(!trk){ continue; }

      	  // acceptance and kinematic quality cuts
      	  if(!AcceptTrack(trk, Bfield, mVertex)) { continue; }

      	  StThreeVectorF mTrkMom;
      	  if(doUsePrimTracks) {
        	if(!(trk->isPrimary())) continue; // check if primary

          // get primary track vector
          mTrkMom = trk->pMom();
          } else {
          // get global track vector
          mTrkMom = trk->gMom(mVertex, Bfield);
          }
      	  // track variables
      	  pt = mTrkMom.perp();
      	  phi = mTrkMom.phi();
      	  eta = mTrkMom.pseudoRapidity();
      	  px = mTrkMom.x();
      	  py = mTrkMom.y();
      	  pz = mTrkMom.z();
      	  charge = trk->charge();
      }   
  
      //Track selections
      bool trackInPtRange = (pt>=fTrackPtMinCut);
      
      //Selection Pre Requisites (all must be satisfied)
      if(!JetAboveMinimum || !trackInPtRange)	{continue;}
      
      nGoodTracks = nGoodTracks + 1;

      trackConstitsPt[itrk] = pt;
      fHistConstitPt->Fill(pt);

      //Correction and calculation for non reflected dphi
      double dphi = TMath::Abs(phi - jetPhi); //Keeps all between 0 and 2pi
      double pi1 = TMath::Pi();

      if(dphi > 1.5*pi1)                      dphi = 2*pi1 - dphi;  //Correction if in quad 4
      if(dphi < 1.5*pi1 && dphi > pi1)        dphi = 2*pi1 - dphi; //Correction if in quad 3

      //R calculations
      double distanceSig = TMath::Sqrt(TMath::Power(dphi,2) + TMath::Power(jetEta-eta,2));
      
      if(distanceSig > 0.3)	{continue;}

      double r = distanceSig;
      //Spectra of pt of ALL track constit
      fHistPtTrackSpectra->Fill(pt);

      //rho inner loop calculations
      

      //LeSub Logic for Signal
      if(pt > leadingtrackptSig){
        subleadingtrackptSig = leadingtrackptSig;
        leadingtrackptSig = pt;
      }
      else if(pt > subleadingtrackptSig && pt < leadingtrackptSig) {
        subleadingtrackptSig = pt;
      }

      //angularity and ptD for Signal
      if(jetInEtaRange){ 
	 fHistAngularityDistanceSig->Fill(distanceSig);
      }
      else{
         fHistAngularityDistanceOOR->Fill(distanceSig);
      }

      angularitySig += (pt/corrjetpt)*distanceSig;
      pdisnumeratorsumSig = pdisnumeratorsumSig + TMath::Power(pt,2);
      pdisdenominatorsumSig = pdisdenominatorsumSig + pt;
   
  
    } // track constit loop
  
    /*---------------------------------------Loop for all tracks-------------------------------------------------
    * This loop is for calculating the eta and phi reflected backgrounds of the three variables.
    * All Tracks isn't affected by the Subtractor. Only Jet Constituents are.
    */
    double pi0mass = Pico::mMass[0]; // GeV
    unsigned int ntracks = mPicoDst->numberOfTracks();
    for(unsigned short iTracks=0;iTracks<ntracks;iTracks++){
	 StPicoTrack* trk = static_cast<StPicoTrack*>(mPicoDst->track(iTracks));
	 if(!trk){ continue; }
 
	 // acceptance and kinematic quality cuts
	 if(!AcceptTrack(trk, Bfield, mVertex)) { continue; }

	 // primary track switch
	 // get momentum vector of track - global or primary track
	 StThreeVectorF mTrkMom;
    	 if(doUsePrimTracks) {
	 // get primary track vector
	   mTrkMom = trk->pMom();
	 } else {
         // get global track vector
	 mTrkMom = trk->gMom(mVertex, Bfield);
     	 }
	// track variables
	double pt = mTrkMom.perp();
	double phi = mTrkMom.phi();
	double eta = mTrkMom.pseudoRapidity();
	double px = mTrkMom.x();
	double py = mTrkMom.y();
	double pz = mTrkMom.z();
	short charge = trk->charge();

	bool trackInPtRange = (pt>=fTrackPtMinCut);
	
	//Selections
	if(!JetAboveMinimum || !trackInPtRange)	{continue;}

	
	//Correction and calculation for non reflected dphi
	double dphi = TMath::Abs(phi - jetPhi); //Keeps all between 0 and 2pi
	double pi1 = TMath::Pi();
	
	if(dphi > 1.5*pi1)                      dphi = 2*pi1 - dphi;  //Correction if in quad 4
	if(dphi < 1.5*pi1 && dphi > pi1)        dphi = 2*pi1 - dphi; //Correction if in quad 3
	
	//Correction for reflected dphi
	double dphiref = TMath::Abs((jetPhi+pi1*0.5)-phi);
	if(dphiref > 1.5*pi1)                      dphiref = 2*pi1 - dphiref;  //Correction if in quad 4
	if(dphiref < 1.5*pi1 && dphiref > pi1)        dphiref = 2*pi1 - dphiref; //Correction if in quad 3
	
	//R calculations
	double distanceBGEta = TMath::Sqrt(TMath::Power(dphi,2) + TMath::Power(-jetEta-eta,2));
	double distanceBGPhi = TMath::Sqrt(TMath::Power(dphiref,2) + TMath::Power(jetEta-eta,2));

	fHistAllTracksPt->Fill(pt);

        bool refEtaRInRange = (distanceBGEta < 0.3);
	bool refPhiRInRange = (distanceBGPhi < 0.3);

	if(refEtaRInRange)	fHistEtaRefTracksPt->Fill(pt);

	//LeSub Logic For Eta Ref
	if(pt > leadingtrackptBGEta && refEtaRInRange){
          subleadingtrackptBGEta = leadingtrackptBGEta;
          leadingtrackptBGEta = pt;
        }
        else if(pt > subleadingtrackptBGEta && pt < leadingtrackptBGEta && refEtaRInRange) {
          subleadingtrackptBGEta = pt;
        }

	//LeSub Logic For Phi Ref
	if(pt > leadingtrackptBGPhi && refPhiRInRange){
          subleadingtrackptBGPhi = leadingtrackptBGPhi;
          leadingtrackptBGPhi = pt;
        }
        else if(pt > subleadingtrackptBGPhi && pt < leadingtrackptBGPhi && refPhiRInRange) {
          subleadingtrackptBGPhi = pt;
        }

	//Angularity and ptD for Eta Ref
	if(!jetInEtaRange){
         fHistAngularityDistanceBGOOR->Fill(distanceBGEta);
         if(refEtaRInRange){
                angularityBGEta = angularityBGEta + (pt/corrjetpt)*distanceBGEta;
                pdisnumeratorsumBGEta = pdisnumeratorsumBGEta + TMath::Power(pt,2);
                pdisdenominatorsumBGEta = pdisdenominatorsumBGEta + pt;
         }
        }
	//Angularity and ptD for Phi Ref
	if(jetInEtaRange){
         fHistAngularityDistanceBG->Fill(distanceBGPhi);
         if(refPhiRInRange){
                angularityBGPhi = angularityBGPhi + (pt/corrjetpt)*distanceBGPhi;
                pdisnumeratorsumBGPhi = pdisnumeratorsumBGPhi + TMath::Power(pt,2);
                pdisdenominatorsumBGPhi = pdisdenominatorsumBGPhi + pt;
         }
        }

    }//ALL Tracks Loop


    // loop over constituents towers
    for(int itow = 0; itow < jet->GetNumberOfClusters(); itow++) {
      int towerid = jet->ClusterAt(itow);
      StPicoBTowHit *tow = static_cast<StPicoBTowHit*>(mPicoDst->btowHit(towerid));
      if(!tow){ continue; }

      int towID = tow->id();
      
    } // tower constit loop
    
    //Denominators of ptD BG should always sum up to the jetpt anyway
    pdisdenominatorsumBGPhi = corrjetpt;
    pdisdenominatorsumBGEta = corrjetpt;

    if(!JetAboveMinimum || nGoodTracks < 2)	{continue;}

    //Info On Tracks Histograms Fill
  
    fHistLeadingTrackPt->Fill(leadingtrackptSig);
    fHistSubLeadingTrackPt->Fill(subleadingtrackptSig);
    
    //PtD Array Histograms Fills
    fHistPtD[centBin][ptBin][irBin]->Fill(TMath::Sqrt(pdisnumeratorsumSig)/corrjetpt);

    //Three variables cent selections
    fHistPtDCentSel[centBin]->Fill(TMath::Sqrt(pdisnumeratorsumSig)/corrjetpt);
    fHistLeSubCentSel[centBin]->Fill(leadingtrackptSig - subleadingtrackptSig);
    fHistAngularityCentSel[centBin]->Fill(angularitySig);

    //Three Variables Arrays
    fHistLeSubArrSig[centBin][ptBin2][irBin]->Fill(leadingtrackptSig - subleadingtrackptSig);
    fHistLeSubArrSig2Track[centBin][ptBin2][irBin]->Fill(leadingtrackptSig - subleadingtrackptSig); //At this point, is essentially the same as above histo
    
    fHistAngularityArrSigBG[centBin][ptBin2][irBin]->Fill(angularitySig);    
    fHistPtDArrSigBG[centBin][ptBin2][irBin]->Fill(TMath::Sqrt(pdisnumeratorsumSig)/corrjetpt);

    if(doBGSubs){
      fHistPtDArrSig[centBin][ptBin2][irBin]->Fill(TMath::Sqrt(pdisnumeratorsumSig)/corrjetpt);
      fHistAngularityArrSig[centBin][ptBin2][irBin]->Fill(angularitySig);
    }

 
    //If jet isn't in eta range, fill everything with the eta reflection case
    if(irBin == 0){
     fHistAngularityArrBG[centBin][ptBin2][irBin]->Fill(angularityBGEta);
     ptDValueBGEta = TMath::Sqrt(pdisnumeratorsumBGEta)/corrjetpt;
     if(!doBGSubs){
      fHistPtDArrSig[centBin][ptBin2][irBin]->Fill(TMath::Sqrt(pdisnumeratorsumSig)/corrjetpt - ptDValueBGEta);
      fHistAngularityArrSig[centBin][ptBin2][irBin]->Fill(angularitySig - angularityBGEta);
     }  
  
     fHistLeSubArrBG[centBin][ptBin2][irBin]->Fill(leadingtrackptBGEta - subleadingtrackptBGEta);
     fHistNJetsArr[centBin][ptBin2][irBin]->Fill(1.0);
    } //Now if the jet IS In eta range, fill everything with the phi reflection case
    else if(irBin == 1){
     fHistAngularityArrBG[centBin][ptBin2][irBin]->Fill(angularityBGPhi);
     ptDValueBGPhi = TMath::Sqrt(pdisnumeratorsumBGPhi)/corrjetpt;
     if(!doBGSubs){
      fHistPtDArrSig[centBin][ptBin2][irBin]->Fill(TMath::Sqrt(pdisnumeratorsumSig)/corrjetpt - ptDValueBGPhi);
      fHistAngularityArrSig[centBin][ptBin2][irBin]->Fill(angularitySig - angularityBGPhi);
     }
     fHistLeSubArrBG[centBin][ptBin2][irBin]->Fill(leadingtrackptBGPhi - subleadingtrackptBGPhi);
     fHistNJetsArr[centBin][ptBin2][irBin]->Fill(1.0);
    }


    int ptDPeakRangeBin = 0;
    ptDPeakRangeBin = GetPtDPeakRange(TMath::Sqrt(pdisnumeratorsumSig)/corrjetpt);
    fHistPtDPeaksNTracks[centBin][ptDPeakRangeBin][irBin]->Fill(nconstituentTracks);
    for(int i = 0; i<nconstituentTracks; i++){
      if(trackConstitsPt[i] >= 1.0)
        fHistPtDPeaksPtTracks[centBin][ptDPeakRangeBin][irBin]->Fill(trackConstitsPt[i]);
    }

    //Filling histos according to their eta bin
    if(jetInEtaRange){
        fHistAngularitySig->Fill(angularitySig);
	ptDValueSig = TMath::Sqrt(pdisnumeratorsumSig)/corrjetpt;
        fHistPtDSig->Fill(ptDValueSig);
        fHistLeSubSig->Fill(leadingtrackptSig - subleadingtrackptSig);
	
       	fHistAngularityBG->Fill(angularityBGPhi);
	fHistPtDBG->Fill(ptDValueBGPhi);
	fHistPtDArrBG[centBin][ptBin2][irBin]->Fill(ptDValueBGPhi);
	fHistLeSubBG->Fill(leadingtrackptBGPhi - subleadingtrackptBGPhi);

    } else {
	fHistAngularityOOR->Fill(angularitySig);
	ptDValueSig = TMath::Sqrt(pdisnumeratorsumSig)/corrjetpt;
        fHistPtDOOR->Fill(ptDValueSig);
        fHistLeSubOOR->Fill(leadingtrackptSig - subleadingtrackptSig);

	fHistAngularityBGOOR->Fill(angularityBGEta);
        fHistPtDBGOOR->Fill(ptDValueBGEta);
	fHistPtDArrBG[centBin][ptBin2][irBin]->Fill(ptDValueBGEta);
        fHistLeSubBGOOR->Fill(leadingtrackptBGEta - subleadingtrackptBGEta);
    }
    
  } // jet loop
  

   /*
   * Out of Jet Loop Calculations
   * Typically will only have one entry per event
   * Entries will be contributed by all Jets
   */

   fHistPtSpectraLeadingJet->Fill(leadingjetpt);

   for(int i = 0;i<njets;i++){
	if(jetpts[i] >= 15.0 && jetpts[i]!=leadingjetpt){   
		double pi1 = TMath::Pi();
		double dphi = TMath::Abs(jetphis[i] - leadingjetphi); //Keeps all between 0 and 2pi
		
		if(dphi > 1.5*pi1)			dphi = 2*pi1 - dphi;  //Correction if in quad 4
		if(dphi < 1.5*pi1 && dphi > pi1)	dphi = 0.5*pi1 + (1.5*pi1-dphi); //Correction if in quad 3
                fHistDPhiLeadingandAll->Fill(dphi);
			
	}
   }
}//method

//_______________________________________________________________________
void StAnMaker::RunTracks()
{
  // assume neutral pion mass
  double pi = 1.0*TMath::Pi();
  double pi0mass = Pico::mMass[0]; // GeV
  
  //Leading and subleading variables
  double subleadingtrackpt = 0.0;
  double leadingtrackpt = 0.0;

  unsigned int ntracks = mPicoDst->numberOfTracks();
  // loop over ALL tracks in PicoDst 
  for(unsigned short iTracks=0;iTracks<ntracks;iTracks++){
    StPicoTrack* trk = static_cast<StPicoTrack*>(mPicoDst->track(iTracks));
    if(!trk){ continue; }

    // acceptance and kinematic quality cuts
    if(!AcceptTrack(trk, Bfield, mVertex)) { continue; }

    // primary track switch
    // get momentum vector of track - global or primary track
    StThreeVectorF mTrkMom;
    if(doUsePrimTracks) {
      // get primary track vector
      mTrkMom = trk->pMom();
    } else {
      // get global track vector
      mTrkMom = trk->gMom(mVertex, Bfield);
    }

    // track variables
    double pt = mTrkMom.perp();
    double phi = mTrkMom.phi();
    double eta = mTrkMom.pseudoRapidity();
    double px = mTrkMom.x();
    double py = mTrkMom.y();
    double pz = mTrkMom.z();
    short charge = trk->charge();
  } // track loop

}  // track function

//
//________________________________________________________________________
void StAnMaker::RunTowers()
{
  // assume neutral pion mass:
  double pi = 1.0*TMath::Pi();
  double pi0mass = Pico::mMass[0]; // GeV

  // looping over clusters - STAR: matching already done
  // get # of clusters and set variables
  unsigned int nBEmcPidTraits = mPicoDst->numberOfBEmcPidTraits();
  StEmcPosition2 *mPosition = new StEmcPosition2();

  // loop over ALL clusters in PicoDst and add to jet //TODO
  for(unsigned short iClus = 0; iClus < nBEmcPidTraits; iClus++){
    StPicoBEmcPidTraits* cluster = static_cast<StPicoBEmcPidTraits*>(mPicoDst->bemcPidTraits(iClus));
    if(!cluster){ cout<<"Cluster pointer does not exist.. iClus = "<<iClus<<endl; continue; }

    // cluster and tower ID
    int clusID = cluster->bemcId();  // index in bemc point array
    int towID = cluster->btowId();   // projected tower Id: 1 - 4800
    int towID2 = cluster->btowId2(); // emc 2nd and 3rd closest tower local id  ( 2nd X 10 + 3rd), each id 0-8
    int towID3 = cluster->btowId3(); // emc 2nd and 3rd closest tower local id  ( 2nd X 10 + 3rd), each id 0-8
    if(towID < 0) continue;

    // cluster and tower position - from vertex and ID
    StThreeVectorF  towPosition;
    towPosition = mPosition->getPosFromVertex(mVertex, towID);
    double towPhi = towPosition.phi();
    double towEta = towPosition.pseudoRapidity();

    // matched track index
    int trackIndex = cluster->trackIndex();
    StPicoTrack* trk = static_cast<StPicoTrack*>(mPicoDst->track(trackIndex));
    if(!trk) { cout<<"No trk pointer...."<<endl; continue; }
    if(!AcceptTrack(trk, Bfield, mVertex)) { continue; }

  } // BEmc loop

  // loop over towers
  int nTowers = mPicoDst->numberOfBTOWHits();
  for(int itow = 0; itow < nTowers; itow++) {
    StPicoBTowHit *tower = static_cast<StPicoBTowHit*>(mPicoDst->btowHit(itow));
    if(!tower) { cout<<"No tower pointer... iTow = "<<itow<<endl; continue; }

    // tower ID
    int towerID = tower->id();
    if(towerID < 0) continue; // double check these aren't still in the event list

    // cluster and tower position - from vertex and ID: shouldn't need additional eta correction
    StThreeVectorF towerPosition = mPosition->getPosFromVertex(mVertex, towerID);
    double towerPhi = towerPosition.phi();
    double towerEta = towerPosition.pseudoRapidity();
    int towerADC = tower->adc();
    double towerE = tower->energy();

  } // tower loop

}  // run towers function

//
//________________________________________________________________________
Int_t StAnMaker::GetCentBin(Int_t cent, Int_t nBin) const
{  // Get centrality bin.
  Int_t centbin = -1;

  if(nBin == 16) {
    centbin = nBin - 1 - cent;
  }
  if(nBin == 9) {
    centbin = nBin - 1 - cent;
  }

  return centbin;
}

//________________________________________________________________________
Double_t StAnMaker::RelativePhi(Double_t mphi,Double_t vphi) const
{ // function to calculate relative PHI
  double dphi = mphi-vphi;

  // set dphi to operate on adjusted scale
  if(dphi<-0.5*TMath::Pi()) dphi+=2.*TMath::Pi();
  if(dphi>3./2.*TMath::Pi()) dphi-=2.*TMath::Pi();

  // test
  if( dphi < -1.*TMath::Pi()/2 || dphi > 3.*TMath::Pi()/2 )
    Form("%s: dPHI not in range [-0.5*Pi, 1.5*Pi]!", GetName());

  return dphi; // dphi in [-0.5Pi, 1.5Pi]                                                                                   
}

//_________________________________________________________________________
Double_t StAnMaker::RelativeEPJET(Double_t jetAng, Double_t EPAng) const
{ // function to calculate angle between jet and EP in the 1st quadrant (0,Pi/2)
  Double_t pi = 1.0*TMath::Pi();
  Double_t dphi = 1.0*TMath::Abs(EPAng - jetAng);
  
  // ran into trouble with a few dEP<-Pi so trying this...
  if( dphi<-1*TMath::Pi() ){
    dphi = dphi + 1*TMath::Pi();
  } // this assumes we are doing full jets currently 
 
  if(dphi > 1.5*pi) dphi -= 2*pi;
  if((dphi > 1.0*pi) && (dphi < 1.5*pi)) dphi -= 1*pi;
  if((dphi > 0.5*pi) && (dphi < 1.0*pi)) dphi -= 1*pi;
  dphi = 1.0*TMath::Abs(dphi);

  // test
  if( dphi < 0 || dphi > TMath::Pi()/2 ) {
    //Form("%s: dPHI not in range [0, 0.5*Pi]!", GetName());
    cout<<"dPhi not in range [0, 0.5*Pi]!"<<endl;
  }

  return dphi;   // dphi in [0, Pi/2]
}

//_________________________________________________________________________
void StAnMaker::FillEmcTriggers() {
  // number of Emcal Triggers
  for(int i=0; i<8; i++) { fEmcTriggerArr[i] = 0; }
  Int_t nEmcTrigger = mPicoDst->numberOfEmcTriggers();

  // set kAny true to use of 'all' triggers
  fEmcTriggerArr[StJetFrameworkPicoBase::kAny] = 1;  // always TRUE, so can select on all event (when needed/wanted) 

  // loop over valid EmcalTriggers
  for(int i = 0; i < nEmcTrigger; i++) {
    StPicoEmcTrigger *emcTrig = static_cast<StPicoEmcTrigger*>(mPicoDst->emcTrigger(i));
    if(!emcTrig) continue;

    // fill for valid triggers
    if(emcTrig->isHT0()) { fEmcTriggerArr[StJetFrameworkPicoBase::kIsHT0] = 1; }
    if(emcTrig->isHT1()) { fEmcTriggerArr[StJetFrameworkPicoBase::kIsHT1] = 1; }
    if(emcTrig->isHT2()) { fEmcTriggerArr[StJetFrameworkPicoBase::kIsHT2] = 1; }
    if(emcTrig->isHT3()) { fEmcTriggerArr[StJetFrameworkPicoBase::kIsHT3] = 1; }
    if(emcTrig->isJP0()) { fEmcTriggerArr[StJetFrameworkPicoBase::kIsJP0] = 1; }
    if(emcTrig->isJP1()) { fEmcTriggerArr[StJetFrameworkPicoBase::kIsJP1] = 1; }
    if(emcTrig->isJP2()) { fEmcTriggerArr[StJetFrameworkPicoBase::kIsJP2] = 1; }
  }
}

//_____________________________________________________________________________
// this function is not used in this class, but kept to keep track of the USEFUL triggers from various Runs 
void StAnMaker::FillEventTriggerQA() {
  // Run14 AuAu 200 GeV
  if(fRunFlag == StJetFrameworkPicoBase::Run14_AuAu200) {
    int arrBHT1[] = {450201, 450211, 460201};
    int arrBHT2[] = {450202, 450212, 460202, 460212};
    int arrBHT3[] = {460203, 450213, 460203};
    int arrMB[] = {450014};
    int arrMB30[] = {450010, 450020};
    int arrCentral5[] = {450010, 450020};
    int arrCentral[] = {460101, 460111};
    int arrMB5[] = {450005, 450008, 450009, 450014, 450015, 450018, 450024, 450025, 450050, 450060};
  }

  // Run16 AuAu
  if(fRunFlag == StJetFrameworkPicoBase::Run16_AuAu200) {
    // hard-coded trigger Ids for run16
    int arrBHT0[] = {520606, 520616, 520626, 520636, 520646, 520656};
    int arrBHT1[] = {520201, 520211, 520221, 520231, 520241, 520251, 520261, 520605, 520615, 520625, 520635, 520645, 520655, 550201, 560201, 560202, 530201, 540201};
    int arrBHT2[] = {530202, 540203};
    int arrBHT3[] = {520203, 530213};
    int arrMB[] = {520021};
    int arrMB5[] = {520001, 520002, 520003, 520011, 520012, 520013, 520021, 520022, 520023, 520031, 520033, 520041, 520042, 520043, 520051, 520822, 520832, 520842, 570702};
    int arrMB10[] = {520007, 520017, 520027, 520037, 520201, 520211, 520221, 520231, 520241, 520251, 520261, 520601, 520611, 520621, 520631, 520641};
    int arrCentral[] = {520101, 520111, 520121, 520131, 520141, 520103, 520113, 520123};
  }

}

// elems: sizeof(myarr)/sizeof(*myarr) prior to passing to function
// upon passing the array collapses to a pointer and can not get size anymore
//________________________________________________________________________
Bool_t StAnMaker::DoComparison(int myarr[], int elems) {
  //std::cout << "Length of array = " << (sizeof(myarr)/sizeof(*myarr)) << std::endl;
  bool match = kFALSE;

  // loop over specific physics selection array and compare to specific event trigger
  for(int i=0; i<elems; i++) {
    if(mPicoEvent->isTrigger(myarr[i])) match = kTRUE;
    if(match) break;
  }

  return match;
}

int StAnMaker::GetCentralityBin(float cent){
 int bin = 0; 
 if(cent < 10)	bin = 0;
 else if(cent >= 10 && cent <30)  bin = 1;
 else if(cent >= 30 && cent <50)  bin = 2;
 else if(cent >= 50 && cent <80)  bin = 3;
 else bin = 3;
 
 return bin;
}

int StAnMaker::GetPtDPeakRange(float ptD){
 int bin = 0;
 if(ptD >= 0.55 && ptD <= 0.60)  bin = 0;
 else if(ptD >= 0.70 && ptD <= 0.75) bin = 1;
 else  bin = 2;

 return bin;
}
int StAnMaker::GetPtBin2(float pt){
 int bin = 0;
 if(pt >= 15 && pt < 25) bin = 0;
 else bin = 1;

 return bin;
}

int StAnMaker::GetPtBin(float pt){
 int bin = 0;

 if(pt >= 15 && pt < 20) bin = 0;
 else if(pt >= 20 && pt < 30) bin = 1;
 else if(pt >= 30) bin = 2;

 return bin;
}

int StAnMaker::GetIRBin(bool a){
 int bin = 0;

 if(a)	bin = 1;
 else   bin = 0;

 return bin;
}

void StAnMaker::SetSumw2(){
  //Set sum weights
  fHistPtSpectraLeadingJet->Sumw2();
  fHistRatioLeadingInclusive->Sumw2();
  fHistPtSpectraInclusive->Sumw2();
  fHistJetPhi->Sumw2();
  fHistDPhiLeadingandAll->Sumw2();
  fHistBGSubPtSpectraInc->Sumw2();
  fHistJetAreavsPt->Sumw2();
  fHistJetAreavsCorrPt->Sumw2();

  //Subtractor Checking Histos
  fHistConstitPt->Sumw2();
  fHistAllTracksPt->Sumw2();
  fHistEtaRefTracksPt->Sumw2();
 
  //Jet Shape Histos
  fHistLeSubSig->Sumw2();
  fHistPtTrackSpectra->Sumw2();
  fHistLeadingTrackPt->Sumw2();
  fHistSubLeadingTrackPt->Sumw2();

  fHistLeSubBGOOR->Sumw2();
  fHistAngularitySig->Sumw2();
  fHistAngularityBGOOR->Sumw2();
  fHistAngularityDistanceSig->Sumw2();
  fHistAngularityDistanceBGOOR->Sumw2();
  fHistPtDSig->Sumw2();
  fHistPtDBGOOR->Sumw2();

  for(int i = 0; i<4;i++){
    fHistNJetsCentBins[i]->Sumw2();
    fHistPtDCentSel[i]->Sumw2();
    fHistLeSubCentSel[i]->Sumw2();
    fHistAngularityCentSel[i]->Sumw2();

    for(int j = 0; j<3;j++){
      for(int k = 0; k<2;k++){
        fHistPtD[i][j][k]->Sumw2();
        fHistPtDPeaksNTracks[i][j][k]->Sumw2();
        fHistPtDPeaksPtTracks[i][j][k]->Sumw2();

        if(j==0 || j==1){
         fHistLeSubArrSig[i][j][k]->Sumw2();
	 fHistLeSubArrSig2Track[i][j][k]->Sumw2();
	 fHistLeSubArrBG[i][j][k]->Sumw2();

	 fHistAngularityArrSig[i][j][k]->Sumw2();
	 fHistAngularityArrBG[i][j][k]->Sumw2();
	 fHistAngularityArrSigBG[i][j][k]->Sumw2();

	 fHistPtDArrSig[i][j][k]->Sumw2();
	 fHistPtDArrBG[i][j][k]->Sumw2();
 	 fHistPtDArrSigBG[i][j][k]->Sumw2();

	 fHistNJetsArr[i][j][k]->Sumw2();
	 fHistNEventsArr[i][j][k]->Sumw2();
        }
      }
    }
  }

  fHistLeSubBG->Sumw2();
  fHistAngularityBG->Sumw2();
  fHistPtDBG->Sumw2();
  fHistAngularityDistanceBG->Sumw2();

  //Out Of Eta Range Three Variable
  fHistLeSubOOR->Sumw2();
  fHistAngularityOOR->Sumw2();
  fHistPtDOOR->Sumw2();
  fHistAngularityDistanceOOR->Sumw2();

  fHistPtSpectraLeadingJetHighCent->Sumw2();
  fHistRatioLeadingInclusiveHighCent->Sumw2();
  fHistPtSpectraInclusiveHighCent->Sumw2();
  fHistDPhiLeadingandAllHighCent->Sumw2();
  fHistJetAreavsCorrPtHighCent->Sumw2();

  fHistPtSpectraLeadingJetLowCent->Sumw2();
  fHistRatioLeadingInclusiveLowCent->Sumw2();
  fHistPtSpectraInclusiveLowCent->Sumw2();
  fHistDPhiLeadingandAllLowCent->Sumw2();
  fHistJetAreavsCorrPtLowCent->Sumw2();

}
