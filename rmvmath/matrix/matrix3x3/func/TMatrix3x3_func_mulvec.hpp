//
// Created by Vitali Kurlovich on 1/7/16.
//

#ifndef RMVECTORMATH_TMATRIX3X3_FUNC_MULVEC_HPP
#define RMVECTORMATH_TMATRIX3X3_FUNC_MULVEC_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TMatrix3x3_def.hpp"

#include "../../../vector/vector3x/TVector3_def.hpp"

namespace rmmath {

    template<typename T>
    inline vector::TVector3 <T> mul(const matrix::TMatrix3x3 <T> &a, const vector::TVector3 <T> &b) {
        vector::TVector3<T> c;

        c.x = a.m00*b.x + a.m01*b.y + a.m02*b.z;
        c.y = a.m10*b.x + a.m11*b.y + a.m12*b.z;
        c.z = a.m20*b.x + a.m21*b.y + a.m22*b.z;

#ifdef RM_MATH_STAT
        RM_STAT_MUL(9)
        RM_STAT_SUM(6)
#endif
        return c;
    }


    template<typename T>
    inline vector::TVector3 <T> mul(const vector::TVector3 <T> &b, const matrix::TMatrix3x3 <T> &a) {
        vector::TVector3<T> c;

        c.x = a.m00*b.x + a.m10*b.y + a.m20*b.z;
        c.y = a.m01*b.x + a.m11*b.y + a.m21*b.z;
        c.z = a.m02*b.x + a.m12*b.y + a.m22*b.z;

#ifdef RM_MATH_STAT
        RM_STAT_MUL(9)
        RM_STAT_SUM(6)
#endif
        return c;
    }

    namespace ___unsafe {
        template<typename T>
        inline void _mul(vector::TVector3 <T> &b, const matrix::TMatrix3x3 <T> &a) {

            auto x = a.m00*b.x + a.m10*b.y + a.m20*b.z;
            auto y = a.m01*b.x + a.m11*b.y + a.m21*b.z;
            auto z = a.m02*b.x + a.m12*b.y + a.m22*b.z;

            b.x = x;
            b.y = y;
            b.z = z;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(9)
            RM_STAT_SUM(6)
#endif
        }
    }
}

#endif //RMVECTORMATH_TMATRIX3X3_FUNC_MULVEC_HPP
