//
// Created by Vitali Kurlovich on 1/7/16.
//

#ifndef RMVECTORMATH_TMATRIX4X3_FUNC_MULVEC_HPP
#define RMVECTORMATH_TMATRIX4X3_FUNC_MULVEC_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TMatrix4x3_def.hpp"

#include "../../../vector/vector4x/TVector4_def.hpp"
#include "../../../vector/vector3x/TVector3_def.hpp"

namespace rmmath {

    template<typename T>
    inline vector::TVector4<T> mul(const matrix::TMatrix4x3<T> &a, const vector::TVector3<T> &b) {
        vector::TVector4<T> c;

        c.x = a.m00*b.x + a.m01*b.y + a.m02*b.z;
        c.y = a.m10*b.x + a.m11*b.y + a.m12*b.z;
        c.z = a.m20*b.x + a.m21*b.y + a.m22*b.z;
        c.w = a.m30*b.x + a.m31*b.y + a.m32*b.z;

#ifdef RM_MATH_STAT
        RM_STAT_MUL(12)
        RM_STAT_SUM(8)
#endif

        return c;
    }


    template<typename T>
    inline vector::TVector3<T> mul(const vector::TVector4<T> &b, const matrix::TMatrix4x3<T> &a) {
        vector::TVector3<T> c;

        c.x = a.m30*b.w + a.m00*b.x + a.m10*b.y + a.m20*b.z;
        c.y = a.m31*b.w + a.m01*b.x + a.m11*b.y + a.m21*b.z;
        c.z = a.m32*b.w + a.m02*b.x + a.m12*b.y + a.m22*b.z;

#ifdef RM_MATH_STAT
        RM_STAT_MUL(12)
        RM_STAT_SUM(9)
#endif

        return c;
    }


}

#endif //RMVECTORMATH_TMATRIX4X3_FUNC_MULVEC_HPP
