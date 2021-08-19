#ifndef MAIN_CPP_ANALYSER_H
#define MAIN_CPP_ANALYSER_H
#include "boost/multi_array.hpp"
typedef boost::multi_array<long double, 1 > One_D_Array;
typedef boost::multi_array<long double, 2 > Two_D_Array;


struct ErrorValues
{
    long double error=0, eNorm=0, rErr=0;
    void Regression();
    void AnalyseVector(const int Num, Two_D_Array &Small, Two_D_Array &Large);
    void AnalysePotential(const int Num, long double pMass, Two_D_Array &PosS, Two_D_Array &PosL,Two_D_Array &VeS, Two_D_Array &VeL);
    void AnalyseTotalEnergy(const int Num, long double pMass, One_D_Array &PES, One_D_Array &PEL, Two_D_Array &VeS, Two_D_Array &VeL);
};

struct AnalyserValues
{
    ErrorValues C,V,P,E; //naming should be adjusted
    void Analyser(const int Num, long double pMass,Two_D_Array &PosL, Two_D_Array &PosS,
                  Two_D_Array &VeL, Two_D_Array &VeS, One_D_Array PEL, One_D_Array PES);
};

#endif //MAIN_CPP_ANALYSER_H
