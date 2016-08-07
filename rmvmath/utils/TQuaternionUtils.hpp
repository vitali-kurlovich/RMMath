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

#ifdef RM_MATH_STAT
        RM_STAT_MUL(3)
#endif

        const T half_angle(angle*(T)0.5);
        const T _sin(math::sin<T>(half_angle));

        return complex::TQuaternion<T>(math::cos<T>(half_angle), axis.x*_sin, axis.y*_sin, axis.z*_sin);
    }

    template<typename T>
    const matrix::TMatrix3x3<T> rotationMatrix3x3(const complex::TQuaternion <T> &q) noexcept {

#ifdef RM_MATH_STAT
        RM_STAT_MUL(9)
        RM_STAT_SUM(9)
        RM_STAT_SUB(6)
#endif

        const T x2(q.i + q.i);
        const T y2(q.j + q.j);
        const T z2(q.k + q.k);

        const T xx(q.i * x2);
        const T xy(q.i * y2);
        const T xz(q.i * z2);

        const T yy(q.j * y2);
        const T yz(q.j * z2);
        const T zz(q.k * z2);

        const T wx(q.w * x2);
        const T wy(q.w * y2);
        const T wz(q.w * z2);

        return matrix::TMatrix3x3<T> (
                (T)1 - (yy + zz),
                xy - wz,
                xz + wy,

                xy + wz,
                (T)1 - (xx + zz),
                yz - wx,

                xz - wy,
                yz + wx,
                (T)1 - (xx + yy)
        );
    }

}


#endif //RMVECTORMATH_TQUATERNIONUTILS_HPP
