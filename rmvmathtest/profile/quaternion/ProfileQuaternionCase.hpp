//
// Created by Vitali Kurlovich on 8/5/16.
//

#ifndef RMVECTORMATH_PROFILEQUATERNIONCASE_HPP
#define RMVECTORMATH_PROFILEQUATERNIONCASE_HPP


#include "../ProfileCase.hpp"

#include <utils/TQuaternionUtils.hpp>
#include <utils/TRotationMatrixUtils.hpp>

using namespace rmmath;
using namespace rmmath::complex;
using namespace rmmath::vector;
using namespace rmmath::utils;

class ProfileQuaternionCase : public profiler::ProfileCase {


public:

    ProfileQuaternionCase(profiler::Profiler* profiler)
    : ProfileCase(profiler, "Profile Quaternion") {
    }

    virtual void run() const override {

        {
            TQuaternion<float> a = normalize(TQuaternion<float>(0.f, 0.f, 0.f, 1.f));
            TQuaternion<float> b = normalize(TQuaternion<float>(0.f, 0.f, 1.f, 0.f));
            TQuaternion<float> c = normalize(TQuaternion<float>(0.f, 1.f, 0.f, 0.f));
            TQuaternion<float> d = normalize(TQuaternion<float>(1.f, 1.f, 0.f, 0.f));
            TQuaternion<float> e = normalize(TQuaternion<float>(1.f, 10.f, 7.f, .5f));
            TQuaternion<float> f = normalize(TQuaternion<float>(1.f, 10.f, 78.f, .5f));
            TQuaternion<float> g = normalize(TQuaternion<float>(1.f, 100.f, 78.f, .5f));
            TQuaternion<float> h = normalize(TQuaternion<float>(10.f, 100.f, 178.f, .5f));

            beginProfileCase("rotationMatrix3x3");

            for (uint32_t i = 0; i < 1000000; ++i) {

                rotationMatrix3x3(a);
                rotationMatrix3x3(b);
                rotationMatrix3x3(c);
                rotationMatrix3x3(d);
                rotationMatrix3x3(e);
                rotationMatrix3x3(f);
                rotationMatrix3x3(g);
                rotationMatrix3x3(h);
            }

            endProfileCase("rotationMatrix3x3");
        }


        {

            TVector3<float> a(0,0,1);
            TVector3<float> b(0,1,0);
            TVector3<float> c(1,0,0);

            beginProfileCase("rotationMatrix3x3 axis");

            for (uint32_t i = 0; i < 1000000; ++i) {

                rotationMatrix3x3<float>(0.f, a);
                rotationMatrix3x3<float>(0.f, b);
                rotationMatrix3x3<float>(0.f, c);

                rotationMatrix3x3<float>(M_PI/3, a);
                rotationMatrix3x3<float>(M_PI/3, b);
                rotationMatrix3x3<float>(M_PI/3, c);

            }

            endProfileCase("rotationMatrix3x3 axis");


            beginProfileCase("_rotationMatrix3x3 axis");

            for (uint32_t i = 0; i < 1000000; ++i) {

                _rotationMatrix3x3<float>(0.f, a);
                _rotationMatrix3x3<float>(0.f, b);
                _rotationMatrix3x3<float>(0.f, c);

                _rotationMatrix3x3<float>(M_PI/3, a);
                _rotationMatrix3x3<float>(M_PI/3, b);
                _rotationMatrix3x3<float>(M_PI/3, c);

            }

            endProfileCase("_rotationMatrix3x3 axis");

        }

    }
};


#endif //RMVECTORMATH_PROFILEQUATERNIONCASE_HPP


