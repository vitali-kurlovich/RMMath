//
// Created by Vitali Kurlovich on 1/7/16.
//

#ifndef RMVECTORMATH_TMATRIX3X1_FUNC_MULVEC_HPP
#define RMVECTORMATH_TMATRIX3X1_FUNC_MULVEC_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TMatrix3x1_def.hpp"

#include "../../../vector/vector3x/TVector3_def.hpp"


namespace rmmath {

    template<typename T>
    inline vector::TVector3<T> mul(const matrix::TMatrix3x1<T> &a, T b) {
        vector::TVector3<T> c;

        c.x = a.m00*b;
        c.y = a.m10*b;
        c.z = a.m20*b;

#ifdef RM_MATH_STAT
        RM_STAT_MUL(3)
#endif
        return c;
    }


    template<typename T>
    inline T mul(const vector::TVector3 <T> &b, const matrix::TMatrix3x1<T> &a) {
#ifdef RM_MATH_STAT
        RM_STAT_MUL(3)
        RM_STAT_SUM(2)
#endif
        return a.m00*b.x + a.m10*b.y + a.m20*b.z;
    }

}

#endif //RMVECTORMATH_TMATRIX3X1_FUNC_MULVEC_HPP
