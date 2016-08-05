//
// Created by Vitali Kurlovich on 8/5/16.
//

#ifndef RMVECTORMATH_TQUATERNIONUTILS_HPP
#define RMVECTORMATH_TQUATERNIONUTILS_HPP



#include "complex/quaternion/TQuaternion_def.hpp"
#include "matrix/matrix3x3/TMatrix3x3_def.hpp"


namespace rmmath {

    template<typename T>
    const matrix::TMatrix3x3<T> rotationMatrixFromQuaternion(const complex::TQuaternion <T> &q) noexcept {
        auto wp2 = q.w*q.w;
        auto ip2 = q.i*q.i;
        auto jp2 = q.j*q.j;
        auto kp2 = q.k*q.k;

        auto ij = q.i*q.j;
        auto kw = q.k*q.w;
        auto ik = q.i*q.k;
        auto jw = q.j*q.w;
        auto jk = q.j*q.k;
        auto iw = q.i*q.w;

        matrix::TMatrix3x3<T> m(
                1 - 2*jp2 - 2*kp2,       2*ij + 2*kw,      2*ik - 2*jw,
                             2*ij, 1 - 2*ip2 - 2*kp2,      2*jk + 2*iw,
                      2*ik + 2*jw,       2*jk - 2*iw, 1 - 2*ip2 - 2*jp2

        );
        return m;
    }
}


#endif //RMVECTORMATH_TQUATERNIONUTILS_HPP
