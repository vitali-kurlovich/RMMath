//
// Created by Vitali Kurlovich on 1/7/16.
//

#ifndef RMVECTORMATH_TMATRIX4X1_FUNC_MULVEC_HPP
#define RMVECTORMATH_TMATRIX4X1_FUNC_MULVEC_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TMatrix4x1_def.hpp"

#include "../../../vector/vector4x/TVector4_def.hpp"


namespace rmmath {

    template<typename T>
    inline vector::TVector4<T> mul(const matrix::TMatrix4x1<T> &a, T b) {
        vector::TVector4<T> c;

        c.x = a.m00*b;
        c.y = a.m10*b;
        c.z = a.m20*b;
        c.w = a.m30*b;

#ifdef RM_MATH_STAT
        RM_STAT_MUL(4)
#endif
        return c;
    }


    template<typename T>
    inline T mul(const vector::TVector4 <T> &b, const matrix::TMatrix4x1<T> &a) {
#ifdef RM_MATH_STAT
        RM_STAT_MUL(4)
        RM_STAT_SUM(3)
#endif
        return a.m30*b.w + a.m00*b.x + a.m10*b.y + a.m20*b.z;
    }

}

#endif //RMVECTORMATH_TMATRIX4X1_FUNC_MULVEC_HPP
