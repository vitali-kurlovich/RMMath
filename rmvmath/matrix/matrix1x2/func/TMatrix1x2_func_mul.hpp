//
// Created by Vitali Kurlovich on 12/14/15.
//

#ifndef RMVECTORMATH_TMATRIX1X2_FUNC_MUL_HPP
#define RMVECTORMATH_TMATRIX1X2_FUNC_MUL_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TMatrix1x2_def.hpp"

#include "../../matrix1x4/TMatrix1x4_def.hpp"
#include "../../matrix1x3/TMatrix1x3_def.hpp"
#include "../../matrix1x2/TMatrix1x2_def.hpp"
#include "../../matrix1x1/TMatrix1x1_def.hpp"

#include "../../matrix2x4/TMatrix2x4_def.hpp"
#include "../../matrix2x3/TMatrix2x3_def.hpp"
#include "../../matrix2x2/TMatrix2x2_def.hpp"
#include "../../matrix2x1/TMatrix2x1_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline TMatrix1x4<T> mul(const TMatrix1x2<T> &a, const TMatrix2x4<T> &b) {
            TMatrix1x4<T> c;

            c.m00 = a.m00 * b.m00 + a.m01 * b.m10;
            c.m01 = a.m00 * b.m01 + a.m01 * b.m11;
            c.m02 = a.m00 * b.m02 + a.m01 * b.m12;
            c.m03 = a.m00 * b.m03 + a.m01 * b.m13;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(8)
            RM_STAT_SUM(4)
#endif
            return c;
        }

        template<typename T>
        inline TMatrix1x3<T> mul(const TMatrix1x2<T> &a, const TMatrix2x3<T> &b) {
            TMatrix1x3<T> c;
            c.m00 = a.m00 * b.m00 + a.m01 * b.m10;
            c.m01 = a.m00 * b.m01 + a.m01 * b.m11;
            c.m02 = a.m00 * b.m02 + a.m01 * b.m12;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(6)
            RM_STAT_SUM(3)
#endif
            return c;
        }

        template<typename T>
        inline TMatrix1x2<T> mul(const TMatrix1x2<T> &a, const TMatrix2x2<T> &b) {
            TMatrix1x2<T> c;
            c.m00 = a.m00 * b.m00 + a.m01 * b.m10;
            c.m01 = a.m00 * b.m01 + a.m01 * b.m11;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(4)
            RM_STAT_SUM(2)
#endif
            return c;
        }

        template<typename T>
        inline TMatrix1x1<T> mul(const TMatrix1x2<T> &a, const TMatrix2x1<T> &b) {
            TMatrix1x1<T> c;
            c.m00 = a.m00 * b.m00 + a.m01 * b.m10;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(2)
            RM_STAT_SUM(1)
#endif
            return c;
        }

        namespace ___unsafe
        {
            template<typename T>
            inline void _mul(TMatrix1x2<T> &a, const TMatrix2x2<T> &b) {

                auto m00 = a.m00 * b.m00 + a.m01 * b.m10;
                auto m01 = a.m00 * b.m01 + a.m01 * b.m11;

                a.m00 = m00;
                a.m01 = m01;

#ifdef RM_MATH_STAT
                RM_STAT_MUL(4)
                RM_STAT_SUM(2)
#endif
            }
        }

    }
}


#endif //RMVECTORMATH_TMATRIX1X2_FUNC_MUL_HPP
