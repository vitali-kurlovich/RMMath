//
// Created by Vitali Kurlovich on 12/14/15.
//

#ifndef RMVECTORMATH_TMATRIX2X2_FUNC_MUL_HPP
#define RMVECTORMATH_TMATRIX2X2_FUNC_MUL_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TMatrix2x2_def.hpp"

#include "../../matrix2x4/TMatrix2x4_def.hpp"
#include "../../matrix2x3/TMatrix2x3_def.hpp"
#include "../../matrix2x2/TMatrix2x2_def.hpp"
#include "../../matrix2x1/TMatrix2x1_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline TMatrix2x4<T> mul(const TMatrix2x2<T> &a, const TMatrix2x4<T> &b) {
            TMatrix2x4<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10;
            c.m01 = a.m00*b.m01 + a.m01*b.m11;
            c.m02 = a.m00*b.m02 + a.m01*b.m12;
            c.m03 = a.m00*b.m03 + a.m01*b.m13;

            c.m10 = a.m10*b.m00 + a.m11*b.m10;
            c.m11 = a.m10*b.m01 + a.m11*b.m11;
            c.m12 = a.m10*b.m02 + a.m11*b.m12;
            c.m13 = a.m10*b.m03 + a.m11*b.m13;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(16)
            RM_STAT_SUM(8)
#endif
            return c;
        }

        template<typename T>
        inline TMatrix2x3<T> mul(const TMatrix2x2<T> &a, const TMatrix2x3<T> &b) {
            TMatrix2x3<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10;
            c.m01 = a.m00*b.m01 + a.m01*b.m11;
            c.m02 = a.m00*b.m02 + a.m01*b.m12;

            c.m10 = a.m10*b.m00 + a.m11*b.m10;
            c.m11 = a.m10*b.m01 + a.m11*b.m11;
            c.m12 = a.m10*b.m02 + a.m11*b.m12;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(12)
            RM_STAT_SUM(6)
#endif
            return c;
        }

        template<typename T>
        inline TMatrix2x2<T> mul(const TMatrix2x2<T> &a, const TMatrix2x2<T> &b) {
            TMatrix2x2<T> c;
            c.m00 = a.m00 * b.m00 + a.m01 * b.m10;
            c.m01 = a.m00 * b.m01 + a.m01 * b.m11;
            c.m10 = a.m10 * b.m00 + a.m11 * b.m10;
            c.m11 = a.m10 * b.m01 + a.m11 * b.m11;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(8)
            RM_STAT_SUM(4)
#endif
            return c;
        }

        template<typename T>
        inline TMatrix2x1<T> mul(const TMatrix2x2<T> &a, const TMatrix2x1<T> &b) {
            TMatrix2x1<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10;
            c.m10 = a.m10*b.m00 + a.m11*b.m10;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(4)
            RM_STAT_SUM(2)
#endif
            return c;
        }

        namespace ___unsafe
        {
            template<typename T>
            inline void _mul(TMatrix2x2<T> &a, const TMatrix2x2<T> &b) {
                auto am00 = a.m00;
                auto am01 = a.m01;
                a.m00 = am00 * b.m00 + am01 * b.m10;
                a.m01 = am00 * b.m01 + am01 * b.m11;

                auto am10 = a.m10;
                auto am11 = a.m11;
                a.m10 = am10 * b.m00 + am11 * b.m10;
                a.m11 = am10 * b.m01 + am11 * b.m11;

#ifdef RM_MATH_STAT
                RM_STAT_MUL(8)
                RM_STAT_SUM(4)
#endif
            }
        }
    }
}


#endif //RMVECTORMATH_TMATRIX2X2_FUNC_MUL_HPP
