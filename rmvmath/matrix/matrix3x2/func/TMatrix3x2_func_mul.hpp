//
// Created by Vitali Kurlovich on 12/22/15.
//

#ifndef RMVECTORMATH_TMATRIX3X2_FUNC_MUL_HPP
#define RMVECTORMATH_TMATRIX3X2_FUNC_MUL_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TMatrix3x2_def.hpp"

#include "../../matrix3x4/TMatrix3x4_def.hpp"
#include "../../matrix3x3/TMatrix3x3_def.hpp"
#include "../../matrix3x2/TMatrix3x2_def.hpp"
#include "../../matrix3x1/TMatrix3x1_def.hpp"

#include "../../matrix2x4/TMatrix2x4_def.hpp"
#include "../../matrix2x3/TMatrix2x3_def.hpp"
#include "../../matrix2x2/TMatrix2x2_def.hpp"
#include "../../matrix2x1/TMatrix2x1_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline TMatrix3x4<T> mul(const TMatrix3x2<T> &a, const TMatrix2x4<T> &b) {
            TMatrix3x4<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10;
            c.m01 = a.m00*b.m01 + a.m01*b.m11;
            c.m02 = a.m00*b.m02 + a.m01*b.m12;
            c.m03 = a.m00*b.m03 + a.m01*b.m13;

            c.m10 = a.m10*b.m00 + a.m11*b.m10;
            c.m11 = a.m10*b.m01 + a.m11*b.m11;
            c.m12 = a.m10*b.m02 + a.m11*b.m12;
            c.m13 = a.m10*b.m03 + a.m11*b.m13;

            c.m20 = a.m20*b.m00 + a.m21*b.m10;
            c.m21 = a.m20*b.m01 + a.m21*b.m11;
            c.m22 = a.m20*b.m02 + a.m21*b.m12;
            c.m23 = a.m20*b.m03 + a.m21*b.m13;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(24)
            RM_STAT_SUM(12)
#endif
            return c;
        }

        template<typename T>
        inline TMatrix3x3<T> mul(const TMatrix3x2<T> &a, const TMatrix2x3<T> &b) {
            TMatrix3x3<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10;
            c.m01 = a.m00*b.m01 + a.m01*b.m11;
            c.m02 = a.m00*b.m02 + a.m01*b.m12;

            c.m10 = a.m10*b.m00 + a.m11*b.m10;
            c.m11 = a.m10*b.m01 + a.m11*b.m11;
            c.m12 = a.m10*b.m02 + a.m11*b.m12;

            c.m20 = a.m20*b.m00 + a.m21*b.m10;
            c.m21 = a.m20*b.m01 + a.m21*b.m11;
            c.m22 = a.m20*b.m02 + a.m21*b.m12;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(18)
            RM_STAT_SUM(9)
#endif
            return c;
        }

        template<typename T>
        inline TMatrix3x2<T> mul(const TMatrix3x2<T> &a, const TMatrix2x2<T> &b) {
            TMatrix3x2<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10;
            c.m01 = a.m00*b.m01 + a.m01*b.m11;

            c.m10 = a.m10*b.m00 + a.m11*b.m10;
            c.m11 = a.m10*b.m01 + a.m11*b.m11;

            c.m20 = a.m20*b.m00 + a.m21*b.m10;
            c.m21 = a.m20*b.m01 + a.m21*b.m11;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(12)
            RM_STAT_SUM(6)
#endif
            return c;
        }

        template<typename T>
        inline TMatrix3x1<T> mul(const TMatrix3x2<T> &a, const TMatrix2x1<T> &b) {
            TMatrix3x1<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10;
            c.m10 = a.m10*b.m00 + a.m11*b.m10;
            c.m20 = a.m20*b.m00 + a.m21*b.m10;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(6)
            RM_STAT_SUM(3)
#endif
            return c;
        }

        namespace ___unsafe
        {
            template<typename T>
            inline void _mul(TMatrix3x2<T> &a, const TMatrix2x2<T> &b) {

                auto m00 = a.m00*b.m00 + a.m01*b.m10;
                auto m01 = a.m00*b.m01 + a.m01*b.m11;

                a.m00 = m00;
                a.m01 = m01;

                auto m10 = a.m10*b.m00 + a.m11*b.m10;
                auto m11 = a.m10*b.m01 + a.m11*b.m11;

                a.m10 = m10;
                a.m11 = m11;

                auto m20 = a.m20*b.m00 + a.m21*b.m10;
                auto m21 = a.m20*b.m01 + a.m21*b.m11;

                a.m20 = m20;
                a.m21 = m21;

#ifdef RM_MATH_STAT
                RM_STAT_MUL(12)
                RM_STAT_SUM(6)
#endif
            }
        }

    }
}

#endif //RMVECTORMATH_TMATRIX3X2_FUNC_MUL_HPP
