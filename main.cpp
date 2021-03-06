#include <iostream>
#include "vector"
#include "boost/multi_array.hpp"
#include <time.h>
#include "fstream"
#include <iomanip>
#include "PlummerSphereIC.h"
#include "CalcAcc.h"
#include "Analyser.h"


using boost::extents;
typedef boost::multi_array<long double, 2 > Two_D_Array;
typedef boost::multi_array<long double, 1 > One_D_Array;
long double pi = (long double) 4.0 *atan(1.0);

int main() {
    int NLeap = 2;
    int CodeTime= time(0);
    const int Num = 10000;
    int seed = 0;
    long double ZMass= 1.0;
    AnalyserValues ERROR_VALS;
    Two_D_Array PositionL(extents[Num][3]),PositionS(extents[Num][3]);//position vectors of particles
    Two_D_Array VeL(extents[Num][3]), VeS(extents[Num][3]);//velocity vectors of particles (Large ts vs small ts)
    Two_D_Array AccL(extents[Num][3]), AccS(extents[Num][3]);//acceleration vectors of particles
    One_D_Array PEL(extents[Num]), PES(extents[Num]); //Potential energy of each particle (Large vs small)
    long double TotalPotentialEnergy=0, TotalKineticEnergy=0; //Total energies of the system (scalar)
    long double pMass= (long double) ZMass/Num; //mass of single particle
    long double Tend = 100.0; //Time to end the simulation at
    long double dT =1.0; //Time step

    PlumIC(seed, Num, ZMass, pMass, TotalKineticEnergy, PositionL, VeL, PositionS, VeS);
    CalcAcc(Num, pMass, PositionL, AccL, TotalPotentialEnergy, PEL);
    ERROR_VALS.Analyser(Num, pMass, PositionL, PositionS, VeL, VeS, PEL, PES);

    std::cout <<time(0)-CodeTime;
    return 0;
}
