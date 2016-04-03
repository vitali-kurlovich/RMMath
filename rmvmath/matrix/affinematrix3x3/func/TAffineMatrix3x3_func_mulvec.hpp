//
// Created by Vitali Kurlovich on 1/15/16.
//

#ifndef RMVECTORMATH_TAFFINEMATRIX3X3_FUNC_MULVEC_HPP
#define RMVECTORMATH_TAFFINEMATRIX3X3_FUNC_MULVEC_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TAffineMatrix3x3_def.hpp"

#include "../../../vector/vector3x/TVector3_def.hpp"

namespace rmmath {

    template<typename T>
    inline vector::TVector3 <T> mul(const matrix::TAffineMatrix3x3 <T> &a, const vector::TVector3 <T> &b) {
        vector::TVector3<T> c;

        c.x = a.m00*b.x + a.m01*b.y;
        c.y = a.m10*b.x + a.m11*b.y;
        c.z = a.m20*b.x + a.m21*b.y + b.z;

#ifdef RM_MATH_STAT
        RM_STAT_MUL(6)
        RM_STAT_SUM(4)
#endif
        return c;
    }
    
    template<typename T>
    inline vector::TVector3 <T> mul(const vector::TVector3 <T> &b, const matrix::TAffineMatrix3x3 <T> &a) {
        vector::TVector3<T> c;

        c.x = a.m00*b.x + a.m10*b.y + a.m20*b.z;
        c.y = a.m01*b.x + a.m11*b.y + a.m21*b.z;
        c.z = b.z;

#ifdef RM_MATH_STAT
        RM_STAT_MUL(6)
        RM_STAT_SUM(4)
#endif
        return c;
    }

    namespace ___unsafe {
        template<typename T>
        inline void _mul(vector::TVector3 <T> &b, const matrix::TAffineMatrix3x3 <T> &a) {

            auto x = a.m00*b.x + a.m10*b.y + a.m20*b.z;
            auto y = a.m01*b.x + a.m11*b.y + a.m21*b.z;

            b.x = x;
            b.y = y;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(6)
            RM_STAT_SUM(4)
#endif
        }
    }
}

#endif //RMVECTORMATH_TAFFINEMATRIX3X3_FUNC_MULVEC_HPP
