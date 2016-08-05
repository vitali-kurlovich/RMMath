//
// Created by Vitali Kurlovich on 8/5/16.
//

#ifndef RMVECTORMATH_PROFILEQUATERNIONCASE_HPP
#define RMVECTORMATH_PROFILEQUATERNIONCASE_HPP


#include "../ProfileCase.hpp"

#include <utils/TQuaternionUtils.hpp>

using namespace rmmath;
using namespace rmmath::complex;

class ProfileQuaternionCase : public profiler::ProfileCase {


public:

    ProfileQuaternionCase(profiler::Profiler* profiler)
    : ProfileCase(profiler, "Profile Quaternion") {
    }

    virtual void run() const override {

        beginProfileCase("Matirx 4x4 multiplication");




        endProfileCase("Matirx multiplication");

    }



};


#endif //RMVECTORMATH_PROFILEQUATERNIONCASE_HPP


