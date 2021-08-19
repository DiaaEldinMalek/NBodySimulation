#include <iostream>
#include "vector"
#include "boost/multi_array.hpp"
#include <time.h>
#include "fstream"
#include <iomanip>
using boost::extents;
typedef boost::multi_array<long double, 2 > Two_D_Array;
typedef boost::multi_array<long double, 1 > One_D_Array;
long double pi = (long double) 4.0 *atan(1.0);
#include "PlummerSphereIC.h"


int main() {
    int CodeTime= time(0);
    const int Num = 1000;
    long double ZMass= 1.0;

    Two_D_Array PositionL(extents[Num][3]),PositionS(extents[Num][3]);//position vectors of particles
    Two_D_Array VeL(extents[Num][3]), VeS(extents[Num][3]);//velocity vectors of particles
    Two_D_Array AccL(extents[Num][3]), AccS(extents[Num][3]);//acceleration vectors of particles
    One_D_Array PEL(extents[Num]), PES(extents[Num]);
//    Two_D_Array AA(extents[2][2]);
//    Fun(AA);
    long double TotalKineticEnergy=0;
    long double error_C, eNorm_C, error_V, eNorm_V, error_E, eNorm_E, error_P, eNorm_P;
    long double pMass= (long double) ZMass/Num;
    long double Tend = 100.0;
    long double dT =1.0;
    int NLeap = 2;

    PlumIC(Num, ZMass, pMass, TotalKineticEnergy, PositionL, VeL, PositionS, VeS);
    std::cout <<time(0)-CodeTime;
    return 0;
}
