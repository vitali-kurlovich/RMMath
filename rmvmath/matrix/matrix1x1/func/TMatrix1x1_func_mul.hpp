//
// Created by Vitali Kurlovich on 12/23/15.
//

#ifndef RMVECTORMATH_TMATRIX1X1_FUNC_MUL_HPP
#define RMVECTORMATH_TMATRIX1X1_FUNC_MUL_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TMatrix1x1_def.hpp"

#include "../../matrix1x4/TMatrix1x4_def.hpp"
#include "../../matrix1x3/TMatrix1x3_def.hpp"
#include "../../matrix1x2/TMatrix1x2_def.hpp"
#include "../../matrix1x1/TMatrix1x1_def.hpp"


namespace rmmath {

    namespace matrix {


        template<typename T>
        inline TMatrix1x4 <T> mul(const TMatrix1x1 <T> &a, const TMatrix1x4 <T> &b) {
            TMatrix1x4<T> c;
            c.m00 = a.m00 * b.m00;
            c.m01 = a.m00 * b.m01;
            c.m02 = a.m00 * b.m02;
            c.m03 = a.m00 * b.m03;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(4)
#endif
            return c;
        }

        template<typename T>
        inline TMatrix1x3 <T> mul(const TMatrix1x1 <T> &a, const TMatrix1x3 <T> &b) {
            TMatrix1x3<T> c;
            c.m00 = a.m00 * b.m00;
            c.m01 = a.m00 * b.m01;
            c.m02 = a.m00 * b.m02;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(3)
#endif
            return c;
        }

        template<typename T>
        inline TMatrix1x2 <T> mul(const TMatrix1x1 <T> &a, const TMatrix1x2 <T> &b) {
            TMatrix1x2<T> c;
            c.m00 = a.m00 * b.m00;
            c.m01 = a.m00 * b.m01;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(2)
#endif
            return c;
        }

        template<typename T>
        inline TMatrix1x1 <T> mul(const TMatrix1x1 <T> &a, const TMatrix1x1 <T> &b) {
            TMatrix1x1<T> c;
            c.m00 = a.m00 * b.m00;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(1)
#endif
            return c;
        }

        namespace ___unsafe
        {
            template<typename T>
            inline void _mul(TMatrix1x1<T> &a, const TMatrix1x1<T> &b) {
                a.m00 *= b.m00;

#ifdef RM_MATH_STAT
                RM_STAT_MUL(1)
#endif
            }
        }

    }
}

#endif //RMVECTORMATH_TMATRIX1X1_FUNC_MUL_HPP
