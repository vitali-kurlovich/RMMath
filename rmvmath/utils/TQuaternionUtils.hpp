//
// Created by Vitali Kurlovich on 8/5/16.
//

#ifndef RMVECTORMATH_TQUATERNIONUTILS_HPP
#define RMVECTORMATH_TQUATERNIONUTILS_HPP



#include "complex/quaternion/TQuaternion_def.hpp"
#include "matrix/matrix3x3/TMatrix3x3_def.hpp"

#include "common/trigonometry.hpp"

namespace rmmath {

    template<typename T>
    const complex::TQuaternion<T> rotationQuaternion(const T angle, const vector::TVector3<T> &axis) {

        const T half_angle(angle*(T)0.5);
        const T _sin(math::sin<T>(half_angle));

        return complex::TQuaternion<T>(math::cos<T>(half_angle), axis.x*_sin, axis.y*_sin, axis.z*_sin);
    }

    template<typename T>
    const matrix::TMatrix3x3<T> rotationMatrix3x3(const complex::TQuaternion <T> &q) noexcept {

        const auto ip2(2*q.i*q.i);
        const auto jp2(2*q.j*q.j);
        const auto kp2(2*q.k*q.k);

        const auto ij(2*q.i*q.j);
        const auto kw(2*q.k*q.w);
        const auto ik(2*q.i*q.k);
        const auto jw(2*q.j*q.w);
        const auto jk(2*q.j*q.k);
        const auto iw(2*q.i*q.w);

        return matrix::TMatrix3x3<T>
                (
            (T) 1 - jp2 - kp2,
            ij + kw,
            ik - jw,

            ij,
            (T) 1 - ip2 - kp2,
            jk + iw,

            ik + jw,
            jk - iw,
            (T) 1 - ip2 - jp2
                );


/*        matrix::TMatrix3x3<T> m(
                (T)1 - jp2 - kp2,         ij + kw,          ik - jw,
                              ij, (T)1 - ip2 - kp2,         jk + iw,
                         ik + jw,         jk -  iw, (T)1 - ip2 - jp2

        );*/
        //return m;
    }


    template<typename T>
    const matrix::TMatrix3x3<T> _rotationMatrix3x3(const complex::TQuaternion <T> &q) noexcept {
        auto ip2 = q.i*q.i;
        ip2 += ip2;

        auto jp2 = q.j*q.j;
        jp2 += jp2;

        auto kp2 = q.k*q.k;
        kp2 += kp2;

        auto ij = q.i*q.j;
        ij += ij;

        auto kw = q.k*q.w;
        kw += kw;

        auto ik = q.i*q.k;
        ik += ik;

        auto jw = q.j*q.w;
        jw += jw;

        auto jk = q.j*q.k;
        jk += jk;

        auto iw = q.i*q.w;
        iw += iw;

        matrix::TMatrix3x3<T> m(
                1 - jp2 - kp2,       ij + kw,      ik - jw,
                           ij, 1 - ip2 - kp2,      jk + iw,
                      ik + jw,       jk - iw, 1 - ip2 - jp2
        );
        return m;
    }

}


#endif //RMVECTORMATH_TQUATERNIONUTILS_HPP
