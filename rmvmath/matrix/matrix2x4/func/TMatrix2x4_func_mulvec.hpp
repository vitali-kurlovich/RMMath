//
// Created by Vitali Kurlovich on 1/7/16.
//

#ifndef RMVECTORMATH_TMATRIX2X4_FUNC_MULVEC_HPP
#define RMVECTORMATH_TMATRIX2X4_FUNC_MULVEC_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TMatrix2x4_def.hpp"

#include "../../../vector/vector4x/TVector4_def.hpp"
#include "../../../vector/vector2x/TVector2_def.hpp"

namespace rmmath {

    template<typename T>
    inline vector::TVector2<T> mul(const matrix::TMatrix2x4<T> &a, const vector::TVector4<T> &b) {
        vector::TVector2<T> c;

        c.x = a.m03*b.w + a.m00*b.x + a.m01*b.y + a.m02*b.z;
        c.y = a.m13*b.w + a.m10*b.x + a.m11*b.y + a.m12*b.z;

#ifdef RM_MATH_STAT
        RM_STAT_MUL(8)
        RM_STAT_SUM(6)
#endif
        return c;
    }

    template<typename T>
    inline vector::TVector4<T> mul(const vector::TVector2<T> &b, const matrix::TMatrix2x4<T> &a) {
        vector::TVector4<T> c;

        c.x = a.m00*b.x + a.m10*b.y;
        c.y = a.m01*b.x + a.m11*b.y;
        c.z = a.m02*b.x + a.m12*b.y;
        c.w = a.m03*b.x + a.m13*b.y;

#ifdef RM_MATH_STAT
        RM_STAT_MUL(8)
        RM_STAT_SUM(4)
#endif
        return c;
    }
}

#endif //RMVECTORMATH_TMATRIX2X4_FUNC_MULVEC_HPP
