//
// Created by Vitali Kurlovich on 2/21/16.
//

#ifndef RMVECTORMATH_TAFFINEMATRIX4X4_FUNC_MULAFFINEVEC_HPP
#define RMVECTORMATH_TAFFINEMATRIX4X4_FUNC_MULAFFINEVEC_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TAffineMatrix4x4_def.hpp"

#include "../../../vector/vector4x/TVector4_def.hpp"
#include "../../../vector/affinevector4x/TAffineVector4_def.hpp"

namespace rmmath {

    template<typename T>
    inline vector::TVector4 <T> mul(const matrix::TAffineMatrix4x4 <T> &a, const vector::TAffineVector4 <T> &b) {
        vector::TVector4<T> c;

        c.x = a.m00 * b.x + a.m01 * b.y + a.m02 * b.z;
        c.y = a.m10 * b.x + a.m11 * b.y + a.m12 * b.z;
        c.z = a.m20 * b.x + a.m21 * b.y + a.m22 * b.z;
        c.w = 1 + a.m30 * b.x + a.m31 * b.y + a.m32 * b.z;

#ifdef RM_MATH_STAT
        RM_STAT_MUL(12)
        RM_STAT_SUM(9)
#endif
        return c;
    }


    template<typename T>
    inline vector::TAffineVector4 <T> mul(const vector::TAffineVector4 <T> &b, const matrix::TAffineMatrix4x4 <T> &a) {
        vector::TAffineVector4<T> c;

        c.x = a.m30 + a.m00 * b.x + a.m10 * b.y + a.m20 * b.z;
        c.y = a.m31 + a.m01 * b.x + a.m11 * b.y + a.m21 * b.z;
        c.z = a.m32 + a.m02 * b.x + a.m12 * b.y + a.m22 * b.z;

#ifdef RM_MATH_STAT
        RM_STAT_MUL(9)
        RM_STAT_SUM(9)
#endif
        return c;
    }

    namespace ___unsafe {
        template<typename T>
        inline void _mul(vector::TAffineVector4 <T> &b, const matrix::TAffineMatrix4x4 <T> &a) {

            auto x = a.m30 + a.m00 * b.x + a.m10 * b.y + a.m20 * b.z;
            auto y = a.m31 + a.m01 * b.x + a.m11 * b.y + a.m21 * b.z;
            auto z = a.m32 + a.m02 * b.x + a.m12 * b.y + a.m22 * b.z;

            b.x = x;
            b.y = y;
            b.z = z;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(9)
            RM_STAT_SUM(9)
#endif
        }
    }
}

#endif //RMVECTORMATH_TAFFINEMATRIX4X4_FUNC_MULAFFINEVEC_HPP
