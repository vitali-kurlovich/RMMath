//
// Created by Vitali Kurlovich on 8/9/16.
//

#ifndef RMVECTORMATH_PROFILETRANSFORMCASE_HPP
#define RMVECTORMATH_PROFILETRANSFORMCASE_HPP

#include "../ProfileCase.hpp"

#include <utils/TQuaternionUtils.hpp>
#include <utils/TRotationMatrixUtils.hpp>


using namespace rmmath;
using namespace rmmath::complex;
using namespace rmmath::vector;

class ProfileTransformUtilsCase : public profiler::ProfileCase {


public:

    ProfileTransformUtilsCase(profiler::Profiler* profiler)
    : ProfileCase(profiler, "Profile Utils") {
    }

    virtual void run() const override {

        {

            TQuaternion<float> qr = rotationQuaternion<float>(2.f, normalize(TVector3<float>(2.f,3.f,4.f)));
            TVector3<float> pos(12.f, 34.f, 22.f);
            TVector3<float> scale(2.f, 0.5f, 1.f);

            auto transformA = affineTRSMatrix4x4(pos, qr, scale);

            scale = TVector3<float>(2.f, 0.5f, 3.f);
            qr = rotationQuaternion<float>(9.f, normalize(TVector3<float>(2.f,3.f,-4.f)));
            pos = TVector3<float>(12.f, 4.f, 22.f);
            auto transformB = affineTRSMatrix4x4(pos, qr, scale);

            scale = TVector3<float>(5.f, 2.f, .1f);
            qr = rotationQuaternion<float>(-8.f, normalize(TVector3<float>(2.f,-3.f,-4.f)));
            pos = TVector3<float>(-2.f, 4.f, 22.f);
            auto transformC = affineTRSMatrix4x4(pos, qr, scale);

            scale = TVector3<float>(9.f, 12.f, .1f);
            qr = rotationQuaternion<float>(-.8f, normalize(TVector3<float>(12.f,-3.f,4.f)));
            pos = TVector3<float>(-7.f, 44.f, 22.f);
            auto transformD = affineTRSMatrix4x4(pos, qr, scale);

            scale = TVector3<float>(9.f, 2.f, .1f);
            qr = rotationQuaternion<float>(0.f, normalize(TVector3<float>(12.f,-3.f,4.f)));
            pos = TVector3<float>(-7.f, 44.f, 22.f);
            auto transformE = affineTRSMatrix4x4(pos, qr, scale);


            TVector3<float> s;
            TQuaternion<float> r;
            TVector3<float> p;


            beginProfileCase("convertTRSTransform scaled");

            for (uint32_t i = 0; i < 1000000; ++i) {

                convertTRSTransform(transformA, &p, &r, &s);
                convertTRSTransform(transformB, &p, &r, &s);
                convertTRSTransform(transformC, &p, &r, &s);
                convertTRSTransform(transformD, &p, &r, &s);
                convertTRSTransform(transformE, &p, &r, &s);

            }

            endProfileCase("convertTRSTransform scaled");
        }


        {


            TQuaternion<float> qr = rotationQuaternion<float>(2.f, normalize(TVector3<float>(2.f,3.f,4.f)));
            TVector3<float> pos(12.f, 34.f, 22.f);

            auto transformA = affineTRSMatrix4x4(pos, qr);

            qr = rotationQuaternion<float>(9.f, normalize(TVector3<float>(2.f,3.f,-4.f)));
            pos = TVector3<float>(12.f, 4.f, 22.f);
            auto transformB = affineTRSMatrix4x4(pos, qr);

            qr = rotationQuaternion<float>(-8.f, normalize(TVector3<float>(2.f,-3.f,-4.f)));
            pos = TVector3<float>(-2.f, 4.f, 22.f);
            auto transformC = affineTRSMatrix4x4(pos, qr);

            qr = rotationQuaternion<float>(-.8f, normalize(TVector3<float>(12.f,-3.f,4.f)));
            pos = TVector3<float>(-7.f, 44.f, 22.f);
            auto transformD = affineTRSMatrix4x4(pos, qr);

            qr = rotationQuaternion<float>(0.f, normalize(TVector3<float>(12.f,-3.f,4.f)));
            pos = TVector3<float>(-7.f, 44.f, 22.f);
            auto transformE = affineTRSMatrix4x4(pos, qr);


            TVector3<float> s;
            TQuaternion<float> r;
            TVector3<float> p;


            beginProfileCase("convertTRSTransform");

            for (uint32_t i = 0; i < 1000000; ++i) {

                convertTRSTransform(transformA, &p, &r, &s);
                convertTRSTransform(transformB, &p, &r, &s);
                convertTRSTransform(transformC, &p, &r, &s);
                convertTRSTransform(transformD, &p, &r, &s);
                convertTRSTransform(transformE, &p, &r, &s);

            }

            endProfileCase("convertTRSTransform");

        }

    }
};



#endif //RMVECTORMATH_PROFILETRANSFORMCASE_HPP
