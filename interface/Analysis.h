#ifndef ANALYSIS_H
#define ANALYSIS_H
#include "TObject.h"

#include <iostream>
#include <cmath>
#include "TH1.h"
#include "TH2.h"
#include "TTree.h"
#include "TBranch.h"
#include "TLorentzVector.h"
#include "TLorentzRotation.h"
#include "TFile.h"
#include "TCanvas.h"
#include <TLegend.h>
#include <TPad.h>
#include "TF1.h"
#include "TF2.h"
#include <TStyle.h>
#include "TLine.h"
#include "TProfile.h"
#include "TAttFill.h"
#include <iostream>
#include <cstring>
#include <string>
#include <TGraphErrors.h>
#include <Riostream.h>
#include "TFile.h"
#include <TChain.h>
#include <TClonesArray.h>
#include <TLegendEntry.h>
#include <TGraphAsymmErrors.h>
#include <THStack.h>




class Analysis : public TObject {
    
 public:
    
    
  Analysis();
  Analysis(int selezione, string FileNameTree_in);
  virtual ~Analysis();
    
  void analisi( int selezione,   int num_histo_kin	   
		   );
  double derivateR(double a, double x, double y, double z);
  double derivate2_with_sigmaR(double a, double sa, double x, double y, double z);
  double derivateR2D(double a, double x, double y);
  double derivate2_with_sigmaR2D(double a, double sa, double x, double y);
  double error_ingridient(double a, double b, double ea, double eb);
  double pu_weight ( TH1D *histo, double numberInteractions);
  void printDataCard(const double obsYield, const double sigYield, const std::string& sigName, const double* bkgYield, const unsigned nBkg, const std::string* bkgNames, const std::vector<std::vector<double> >& systUnc, const unsigned nSyst, const std::string* systNames, const std::string* systDist, const std::string& cardName, const bool shapeCard, const std::string& shapeFileName, int number_bin);


  void norm ( TH2D *histo);
  void put_at_zero(TH1D *histo);
  void put_at_zero2d(TH2D *histo);

  
  double maximum(double a, double b);
  void from_TGraph_to_TH1D (TGraphAsymmErrors *graph, TH1D *histo, int number_point);
  void find_leptons(int selezione, unsigned displacedC, TLorentzVector lepton_tobeselected[10], int index_displaced[10], int index_s[2]);


  double FR_factor(TGraphAsymmErrors *fakeRate_mu[3],
			      TGraphAsymmErrors *fakeRate_e[3],
			      double eta,
			      double flavors,
			      double lptcone
		   );

  void class_os(int event_clas[1], int  flavors_3l[3], int  charge_3l[3]);
  void ossf_no_ossf(int kind[1],TLorentzVector pair1[3],TLorentzVector leep1, TLorentzVector leep2,TLorentzVector leep3, int  flavors_3l[3], int  charge_3l[3]);

  void fr_selection (int number, TLorentzVector lepton_fake_order[3],TLorentzVector leep1, TLorentzVector leep2,TLorentzVector leep3, int index_leptons[3],  int flavor_leptons[3], int origin_leptons[3],int index_3l[3],  int flavor_3l[3], int origin_3l[3]);


void printProgress(double progress) ;
 private:
    
    
    
  ClassDef(Analysis,1) 
    };

#endif



