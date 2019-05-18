#ifndef StAnMaker_h
#define StAnMaker_h

#include "StChain/StMaker.h"
#include "StRoot/StPicoEvent/StPicoEvent.h"
#include "StEmcPosition2.h"
#include "StJetFrameworkPicoBase.h"
class StJetFrameworkPicoBase;

// ROOT classes
class TClonesArray;
class TF1;
class TH1;
class TH1F;
class TH2;
class TH2F;
class TH3;
class THnSparse;
class TProfile;
class TString;

// STAR classes
class StPicoDst;
class StPicoDstMaker;
class StPicoEvent;
class StPicoTrack;
class StRefMultCorr;

// my STAR classes
class StJetMakerTask;
class StJet;
class StRho;
class StRhoParameter;

//class StAnMaker : public StMaker {
class StAnMaker : public StJetFrameworkPicoBase {
  public:

    StAnMaker(const char *name, StPicoDstMaker *picoMaker, const char *outName, const char *jetMakerName, const char *rhoMakerName);
    virtual ~StAnMaker();
   
    // class required functions
    virtual Int_t Init();
    virtual Int_t Make();
    virtual void  Clear(Option_t *opt="");
    virtual Int_t Finish();
    
    // booking of histograms (optional)
    void    DeclareHistograms();
    void    WriteHistograms();

    // switches
    virtual void            SetUsePrimaryTracks(Bool_t P)      { doUsePrimTracks   = P; }
    virtual void            SetDebugLevel(Int_t l)             { fDebugLevel       = l; }
    virtual void            SetPrintEventCounter(Bool_t c)     { doPrintEventCounter = c; }
    virtual void            SetRunFlag(Int_t f)                { fRunFlag          = f; }
    virtual void            SetCentralityDef(Int_t c)          { fCentralityDef    = c; }
    virtual void            SetTurnOnCentSelection(Bool_t o)   { fRequireCentSelection = o; }
    virtual void            SetCentralityBinCut(Int_t c)       { fCentralitySelectionCut = c; }
    virtual void	    SetdoConstituentSubtr(Bool_t c)    { doBGSubs = c;}
    // jet setters
    virtual void            SetMinJetPt(Double_t j)            { fMinPtJet         = j; }    // min jet pt
    virtual void            SetJetConstituentCut(Double_t mc)  { fJetConstituentCut= mc;}    // min constituent pt cut
    virtual void            SetJetMaxTrackPt(Double_t t)       { fTrackBias        = t; }    // track bias
    virtual void            SetJetMaxTowerE(Double_t t)        { fTowerBias        = t; }    // tower bias
    virtual void            SetJetRad(Double_t jrad)           { fJetRad           = jrad; } // jet radius 
    
    // event setters
    virtual void            SetEventZVtxRange(Double_t zmi, Double_t zma) { fEventZVtxMinCut = zmi; fEventZVtxMaxCut = zma; }

    // track setters
    virtual void            SetMinTrackPt(Double_t minpt)      { fTrackPtMinCut    = minpt;} // min track cut
    virtual void            SetMaxTrackPt(Double_t maxpt)      { fTrackPtMaxCut    = maxpt;} // max track cut
    virtual void            SetTrackPhiRange(Double_t ptmi, Double_t ptma) { fTrackPhiMinCut = ptmi; fTrackPhiMaxCut = ptma; }
    virtual void            SetTrackEtaRange(Double_t etmi, Double_t etma) { fTrackEtaMinCut = etmi; fTrackEtaMaxCut = etma; }
    virtual void            SetTrackDCAcut(Double_t d)         { fTrackDCAcut = d       ; }
    virtual void            SetTracknHitsFit(Double_t h)       { fTracknHitsFit = h     ; }
    virtual void            SetTracknHitsRatio(Double_t r)     { fTracknHitsRatio = r   ; }

    // tower setters
    virtual void            SetTowerERange(Double_t enmi, Double_t enmx) { fTowerEMinCut = enmi; fTowerEMaxCut = enmx; }
    virtual void            SetTowerEtaRange(Double_t temi, Double_t temx) { fTowerEtaMinCut = temi; fTowerEtaMaxCut = temx; }
    virtual void            SetTowerPhiRange(Double_t tpmi, Double_t tpmx) { fTowerPhiMinCut = tpmi; fTowerPhiMaxCut = tpmx; }

    // event selection - setters
    virtual void            SetEmcTriggerEventType(UInt_t te)    { fEmcTriggerEventType = te;  }
    virtual void            SetMBEventType(UInt_t mbe)           { fMBEventType = mbe; }

    // efficiency correction setter
    virtual void            SetDoEffCorr(Int_t effcorr)          { fDoEffCorr = effcorr; }

    // use rho to correct jet pt in correlation sparses
    virtual void            SetCorrectJetPt(Bool_t cpt)          { fCorrJetPt = cpt; }

  protected:
    void                    RunTracks();
    void                    RunTowers();
    void                    RunJets();
    Int_t                   GetCentBin(Int_t cent, Int_t nBin) const;             // centrality bin
    Double_t                RelativePhi(Double_t mphi, Double_t vphi) const;      // relative jet track angle
    Double_t                RelativeEPJET(Double_t jetAng, Double_t EPAng) const; // relative jet event plane angle
    void                    FillEmcTriggers();                          // EmcTrigger counter histo
    void                    FillEventTriggerQA();                           // filled event trigger QA plots
    Bool_t                  AcceptJet(StJet *jet);           // jets accept cuts function
    Bool_t                  DoComparison(int myarr[], int elems);
    int 		    GetCentralityBin(float cent);
    int			    GetPtDPeakRange(float ptD);
    int			    GetPtBin(float pt);
    int			    GetPtBin2(float pt);
    int			    GetIRBin(bool a);
    void                    SetSumw2(); // set errors weights 
    //Double_t                EffCorrection(Double_t trkETA, Double_t trkPT, Int_t effswitch) const; // efficiency correction function

    // switches
    Bool_t                  doPrintEventCounter;     // print event # switch
    Bool_t		    doBGSubs;
    Int_t                   fDoEffCorr;              // efficiency correction to tracks

    // event selection types
    UInt_t                  fEmcTriggerEventType;        // Physics selection of event used for signal
    UInt_t                  fMBEventType;                // Physics selection of event used for MB
    Int_t                   fEmcTriggerArr[8];           // EMCal triggers array: used to select signal and do QA

  private:
    Int_t                   fRunNumber;
    Double_t		    refCorr2;

    // Rho objects
    StRhoParameter         *GetRhoFromEvent(const char *name);

    // maker names
    TString                 fAnalysisMakerName;
    TString                 fEventMixerMakerName;

    ClassDef(StAnMaker, 1)

    // Histograms
     TH1F                  *fHistPtSpectraLeadingJet; //!
     TH1F		   *fHistRatioLeadingInclusive;//!
     TH1F		   *fHistPtSpectraInclusive;//!
     TH1F		   *fHistJetPhi;//!
     TH1F		   *fHistDPhiLeadingandAll;//!
     TH1F		   *fHistBGSubPtSpectraInc;//!
     TH2F		   *fHistJetAreavsPt;//!
     TH2F		   *fHistJetAreavsCorrPt;//!

     TH1F		   *fHistNJetsCentBins[4];//!
     TH1F		   *fHistNJetsArr[4][2][2];//! [Centrality] [Jet Pt] [IR or OOR]
     TH1F		   *fHistNEventsArr[4][2][2];//! [Centrality] [Jet Pt] [IR or OOR]

     //Subtractor Check Histograms
     TH1F		   *fHistConstitPt;//!
     TH1F		   *fHistSubConstitPt;//!
     TH1F		   *fHistAllTracksPt;//!
     TH1F		   *fHistEtaRefTracksPt;//!
    
     //LeSub Histograms
     TH1F                  *fHistLeSubSig;//!
     TH1F		   *fHistPtTrackSpectra;//!
     TH1F		   *fHistLeadingTrackPt;//!
     TH1F		   *fHistSubLeadingTrackPt;//!
     TH1F		   *fHistLeSubBG;//!
     TH1F		   *fHistLeSubBGOOR;//!
     TH1F                  *fHistLeSubArrSig[4][2][2];//! [Centrality] [pt Bin] [IR or OOR]
     TH1F	           *fHistLeSubArrSig2Track[4][2][2];//! Exactly the same as above, but only fills if atleast two tracks above min pt were used
     TH1F                  *fHistLeSubArrBG[4][2][2];//! [Centrality] [pt Bin] [IR or OOR]
     TH1F                  *fHistLeSubCentSel[4];//! 0-10, 10-30, 30-50, 50-80
     //Angularity Histograms
     TH1F                  *fHistAngularitySig;//!
     TH1F		   *fHistAngularityBG;//!
     TH1F		   *fHistAngularityBGOOR;//!
     TH1F		   *fHistAngularityDistanceSig;//!
     TH1F		   *fHistAngularityDistanceBG;//!
     TH1F		   *fHistAngularityDistanceBGOOR;//!
     TH1F		   *fHistAngularityArrSigBG[4][2][2];//! [Centrality] [pt Bin] [IR or OOR]
     TH1F                  *fHistAngularityArrSig[4][2][2];//! [Centrality] [pt Bin] [IR or OOR]
     TH1F                  *fHistAngularityArrBG[4][2][2];//! [Centrality] [pt Bin] [IR or OOR]
     TH1F                  *fHistAngularityCentSel[4];//! 0-10, 10-30, 30-50, 50-80

     //Momentum Dispersion Histograms
     TH1F                  *fHistPtDSig;//!
     TH1F		   *fHistPtD[4][3][2];//! ptD for different centrality selections, jeitPt ranges, and whether it's out of range (0) or in range (1)
     TH1F		   *fHistPtDArrSig[4][2][2];//! [Centrality] [pt Bin] [IR or OOR]
     TH1F		   *fHistPtDArrBG[4][2][2];//! [Centrality] [pt Bin] [IR or OOR]
     TH1F		   *fHistPtDArrSigBG[4][2][2];//! [Centrality] [pt Bin] [IR or OOR]
     TH1F		   *fHistPtDCentSel[4];//! 0-10, 10-30, 30-50, 50-80
     TH1F		   *fHistPtDPeaksNTracks[4][3][2];//! [Cent Bin] [ptD Range] [OOR or IR] NTracks around a peak
     TH1F		   *fHistPtDPeaksPtTracks[4][3][2];//! [Cent Bin] [ptD Range] [OOR or IR] trackPtSpectra around a peak
     TH1F		   *fHistPtDBG;//!
     TH1F		   *fHistPtDBGOOR;//!

     //Three Variables With Eta Range Selection
     TH1F		   *fHistLeSubOOR;//!
     TH1F		   *fHistAngularityOOR;//!
     TH1F		   *fHistPtDOOR;//!
     TH1F		   *fHistAngularityDistanceOOR;//!

     //High and Low Centrality Specific Histograms
     TH1F                  *fHistPtSpectraLeadingJetHighCent; //!
     TH1F                  *fHistRatioLeadingInclusiveHighCent;//!
     TH1F                  *fHistPtSpectraInclusiveHighCent;//!
     TH1F                  *fHistDPhiLeadingandAllHighCent;//!
     TH2F                  *fHistJetAreavsCorrPtHighCent;//!

     TH1F                  *fHistPtSpectraLeadingJetLowCent;//!
     TH1F                  *fHistRatioLeadingInclusiveLowCent;//!
     TH1F                  *fHistPtSpectraInclusiveLowCent;//!
     TH1F                  *fHistDPhiLeadingandAllLowCent;//!
     TH2F                  *fHistJetAreavsCorrPtLowCent;//!
};
#endif


