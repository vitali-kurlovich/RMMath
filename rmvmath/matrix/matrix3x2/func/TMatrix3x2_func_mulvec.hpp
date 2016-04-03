//
// Created by Vitali Kurlovich on 1/7/16.
//

#ifndef RMVECTORMATH_TMATRIX3X2_FUNC_MULVEC_HPP
#define RMVECTORMATH_TMATRIX3X2_FUNC_MULVEC_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TMatrix3x2_def.hpp"

#include "../../../vector/vector3x/TVector3_def.hpp"
#include "../../../vector/vector2x/TVector2_def.hpp"

namespace rmmath {

    template<typename T>
    inline vector::TVector3<T> mul(const matrix::TMatrix3x2<T> &a, const vector::TVector2<T> &b) {
        vector::TVector3<T> c;

        c.x = a.m00*b.x + a.m01*b.y;
        c.y = a.m10*b.x + a.m11*b.y;
        c.z = a.m20*b.x + a.m21*b.y;

#ifdef RM_MATH_STAT
        RM_STAT_MUL(6)
        RM_STAT_SUM(3)
#endif
        return c;
    }


    template<typename T>
    inline vector::TVector2<T> mul(const vector::TVector3<T> &b, const matrix::TMatrix3x2<T> &a) {
        vector::TVector2<T> c;

        c.x = a.m00*b.x + a.m10*b.y + a.m20*b.z;
        c.y = a.m01*b.x + a.m11*b.y + a.m21*b.z;

#ifdef RM_MATH_STAT
        RM_STAT_MUL(6)
        RM_STAT_SUM(4)
#endif

        return c;
    }

}

#endif //RMVECTORMATH_TMATRIX3X2_FUNC_MULVEC_HPP
