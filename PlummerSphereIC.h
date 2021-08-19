//
// Created by dia2s on 8/19/2021.
//

#ifndef MAIN_CPP_PLUMMERSPHEREIC_H
#define MAIN_CPP_PLUMMERSPHEREIC_H

#include "fstream"
#include <iomanip>
#include "boost/multi_array.hpp"
//using boost::extents;
typedef boost::multi_array<long double, 2 > Two_D_Array;

void PlumIC(int seed, const int Num, long double ZMass, long double Pmass, long double& TKE, Two_D_Array &PositionsL,Two_D_Array & VeL, Two_D_Array &PositionsS, Two_D_Array &VeS);


#endif //MAIN_CPP_PLUMMERSPHEREIC_H
