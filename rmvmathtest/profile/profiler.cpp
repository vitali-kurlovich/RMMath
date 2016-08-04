//
// Created by Vitali Kurlovich on 3/22/16.
//

#include <iostream>

//#define RM_MATH_STAT 1

#include "Profiler.hpp"

#include "matrix/ProfileMatrixCase.hpp"
#include "ProfileCase.hpp"

#include <types/float.h>

using namespace std;

int  main(int argc, char* argv[]) {

    profiler::Profiler prof;

    ProfileMatrixCase* mc = new ProfileMatrixCase(&prof);
    prof.addProfileCases(mc);
    prof.run();

    //cout << "sizeof(fmt4x4): " << sizeof(fmt4x4) << endl;
    return 0;
}