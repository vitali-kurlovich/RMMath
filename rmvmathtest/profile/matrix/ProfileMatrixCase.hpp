//
// Created by Vitali Kurlovich on 3/23/16.
//

#ifndef RMVECTORMATH_PROFILEMATRIXCASE_HPP
#define RMVECTORMATH_PROFILEMATRIXCASE_HPP

#include "../ProfileCase.hpp"

#include <types/float.h>



using namespace rmmath;
using namespace rmmath::matrix;

class ProfileMatrixCase : public profiler::ProfileCase {

public:

    ProfileMatrixCase(profiler::Profiler* profiler)
            : ProfileCase(profiler, "Profile Matrix") {
    }


public:


    virtual void run() const override {

        beginProfileCase("Matirx 4x4 multiplication");
        fmt4x4 a = {
                1.f, 2.f, 3.f, 4.f,
                5.f, 6.f, 7.f, 8.f,
                9.f, 10.f, 11.f, 12.f,
                13.f, 14.f, 15.f, 16.f
        };

        fmt4x4 b = {
                11.f, 12.f, 13.f, 14.f,
                15.f, 16.f, 17.f, 18.f,
                19.f, 110.f, 111.f, 112.f,
                113.f, 114.f, 115.f, 116.f
        };

        fmt4x4 c = {
                11.f, 12.f, 13.f, 14.f,
                15.f, 16.f, 17.f, 18.f,
                19.f, 110.f, 111.f, 112.f,
                113.f, 114.f, 115.f, 116.f
        };

        for (uint32_t i = 0; i < 1000000; ++i) {

            auto d = a*b*c*a*b*c;
            auto e = d*c*a;
            e*=d;
            d = a*e;
            e = b*c;
        }

        endProfileCase("Matirx multiplication");


        beginProfileCase("Matirx a4x4 multiplication");
        famt4x4 aa = {
                1.f, 2.f, 3.f,
                5.f, 6.f, 7.f,
                9.f, 10.f, 11.f,
                13.f, 14.f, 15.f
        };

        famt4x4 ab = {
                11.f, 12.f, 13.f,
                15.f, 16.f, 17.f,
                19.f, 110.f, 111.f,
                113.f, 114.f, 115.f
        };

        famt4x4 ac = {
                11.f, 12.f, 13.f,
                15.f, 16.f, 17.f,
                19.f, 110.f, 111.f,
                113.f, 114.f, 115.f
        };

        for (uint32_t i = 0; i < 1000000; ++i) {

            auto ad = aa*ab*ac*aa*ab*ac;
            auto ae = ad*ac*aa;
            ae*=ad;
            ad = aa*ae;
            ae = ab*ac;
        }

        endProfileCase("Matirx multiplication");

        beginProfileCase("Inverse 4x4");

        a = {
                1.f, 2.f, 3.f, 4.f,
                55.f, 76.f, 73.f, 9.f,
                19.f, 110.f, 141.f, 152.f,
                163.f, 144.f, 195.f, 169.f
        };
        bool success;

        for (uint32_t i = 0; i < 1000000; ++i) {

            a = inverse(a, success);

            a = inverse(a, success);
            a = inverse(a, success);
            a = inverse(a, success);

            a = inverse(a, success);
            a = inverse(a, success);
            a = inverse(a, success);
            a = inverse(a, success);

        }

        endProfileCase("Inverse 4x4");

        beginProfileCase("Inverse 4x4 fail");


        b = {
                1, 2, 3, 4,
                5, 6, 7, 8,
                9, 10, 11, 12,
                13, 14, 15, 16
        };

        for (uint32_t i = 0; i < 1000000; ++i) {

            b = inverse(b, success);
            b = inverse(b, success);
            b = inverse(b, success);
            b = inverse(b, success);

            b = inverse(b, success);
            b = inverse(b, success);
            b = inverse(b, success);
            b = inverse(b, success);
        }
        endProfileCase("Inverse 4x4 fails");



        beginProfileCase("fmt4x4::zero()");

        for (uint32_t i = 0; i < 1000000; ++i) {

            fmt4x4 a(fmt4x4::zero());
            fmt4x4 b(fmt4x4::zero());
            fmt4x4 c(fmt4x4::zero());
            fmt4x4 d(fmt4x4::zero());
            fmt4x4 f(fmt4x4::zero());
            fmt4x4 g(fmt4x4::zero());
        }

        endProfileCase("Inverse 4x4 fails");


        beginProfileCase("fmt4x4()");

        for (uint32_t i = 0; i < 1000000; ++i) {

            fmt4x4 a;
            fmt4x4 b;
            fmt4x4 c;
            fmt4x4 d;
            fmt4x4 f;
            fmt4x4 g;
        }

        endProfileCase("Inverse 4x4 fails");
    }

};

#endif //RMVECTORMATH_PROFILEMATRIXCASE_HPP
