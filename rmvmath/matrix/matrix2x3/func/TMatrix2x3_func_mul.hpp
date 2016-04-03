//
// Created by Vitali Kurlovich on 12/23/15.
//

#ifndef RMVECTORMATH_TMATRIX2X3_FUNC_MUL_HPP
#define RMVECTORMATH_TMATRIX2X3_FUNC_MUL_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TMatrix2x3_def.hpp"

#include "../../matrix2x4/TMatrix2x4_def.hpp"
#include "../../matrix2x3/TMatrix2x3_def.hpp"
#include "../../matrix2x2/TMatrix2x2_def.hpp"
#include "../../matrix2x1/TMatrix2x1_def.hpp"

#include "../../matrix3x4/TMatrix3x4_def.hpp"
#include "../../matrix3x3/TMatrix3x3_def.hpp"
#include "../../matrix3x2/TMatrix3x2_def.hpp"
#include "../../matrix3x1/TMatrix3x1_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline TMatrix2x4<T> mul(const TMatrix2x3<T> &a, const TMatrix3x4<T> &b) {
            TMatrix2x4<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20;
            c.m01 = a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21;
            c.m02 = a.m00*b.m02 + a.m01*b.m12 + a.m02*b.m22;
            c.m03 = a.m00*b.m03 + a.m01*b.m13 + a.m02*b.m23;

            c.m10 = a.m10*b.m00 + a.m11*b.m10 + a.m12*b.m20;
            c.m11 = a.m10*b.m01 + a.m11*b.m11 + a.m12*b.m21;
            c.m12 = a.m10*b.m02 + a.m11*b.m12 + a.m12*b.m22;
            c.m13 = a.m10*b.m03 + a.m11*b.m13 + a.m12*b.m23;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(24)
            RM_STAT_SUM(16)
#endif
            return c;
        }

        template<typename T>
        inline TMatrix2x3<T> mul(const TMatrix2x3<T> &a, const TMatrix3x3<T> &b) {
            TMatrix2x3<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20;
            c.m01 = a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21;
            c.m02 = a.m00*b.m02 + a.m01*b.m12 + a.m02*b.m22;

            c.m10 = a.m10*b.m00 + a.m11*b.m10 + a.m12*b.m20;
            c.m11 = a.m10*b.m01 + a.m11*b.m11 + a.m12*b.m21;
            c.m12 = a.m10*b.m02 + a.m11*b.m12 + a.m12*b.m22;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(18)
            RM_STAT_SUM(12)
#endif
            return c;
        }

        template<typename T>
        inline TMatrix2x2<T> mul(const TMatrix2x3<T> &a, const TMatrix3x2<T> &b) {
            TMatrix2x2<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20;
            c.m01 = a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21;

            c.m10 = a.m10*b.m00 + a.m11*b.m10 + a.m12*b.m20;
            c.m11 = a.m10*b.m01 + a.m11*b.m11 + a.m12*b.m21;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(12)
            RM_STAT_SUM(8)
#endif
            return c;
        }

        template<typename T>
        inline TMatrix2x1<T> mul(const TMatrix2x3<T> &a, const TMatrix3x1<T> &b) {
            TMatrix2x1<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20;
            c.m10 = a.m10*b.m00 + a.m11*b.m10 + a.m12*b.m20;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(16)
            RM_STAT_SUM(4)
#endif
            return c;
        }

        namespace ___unsafe
        {
            template<typename T>
            inline void _mul(TMatrix2x3<T> &a, const TMatrix3x3<T> &b) {

                auto m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20;
                auto m01 = a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21;
                auto m02 = a.m00*b.m02 + a.m01*b.m12 + a.m02*b.m22;

                a.m00 = m00;
                a.m01 = m01;
                a.m02 = m02;

                auto m10 = a.m10*b.m00 + a.m11*b.m10 + a.m12*b.m20;
                auto m11 = a.m10*b.m01 + a.m11*b.m11 + a.m12*b.m21;
                auto m12 = a.m10*b.m02 + a.m11*b.m12 + a.m12*b.m22;

                a.m10 = m10;
                a.m11 = m11;
                a.m12 = m12;

#ifdef RM_MATH_STAT
                RM_STAT_MUL(18)
                RM_STAT_SUM(12)
#endif
            }
        }
    }
}

#endif //RMVECTORMATH_TMATRIX2X3_FUNC_MUL_HPP
