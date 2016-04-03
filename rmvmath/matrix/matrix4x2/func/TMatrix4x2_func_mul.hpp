//
// Created by Vitali Kurlovich on 12/20/15.
//

#ifndef RMVECTORMATH_TMATRIX4X2_FUNC_MUL_HPP
#define RMVECTORMATH_TMATRIX4X2_FUNC_MUL_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TMatrix4x2_def.hpp"

#include "../../matrix2x4/TMatrix2x4_def.hpp"
#include "../../matrix2x3/TMatrix2x3_def.hpp"
#include "../../matrix2x2/TMatrix2x2_def.hpp"
#include "../../matrix2x1/TMatrix2x1_def.hpp"

#include "../../matrix4x4/TMatrix4x4_def.hpp"
#include "../../matrix4x3/TMatrix4x3_def.hpp"
#include "../../matrix4x2/TMatrix4x2_def.hpp"
#include "../../matrix4x1/TMatrix4x1_def.hpp"

namespace rmmath {

    namespace matrix {

        template<typename T>
        inline TMatrix4x4<T> mul(const TMatrix4x2<T> &a, const TMatrix2x4<T> &b) {
            TMatrix4x4<T> c;

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

            c.m30 = a.m30*b.m00 + a.m31*b.m10;
            c.m31 = a.m30*b.m01 + a.m31*b.m11;
            c.m32 = a.m30*b.m02 + a.m31*b.m12;
            c.m33 = a.m30*b.m03 + a.m31*b.m13;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(32)
            RM_STAT_SUM(16)
#endif
            return c;
        }


        template<typename T>
        inline TMatrix4x3<T> mul(const TMatrix4x2<T> &a, const TMatrix2x3<T> &b) {
            TMatrix4x3<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10;
            c.m01 = a.m00*b.m01 + a.m01*b.m11;
            c.m02 = a.m00*b.m02 + a.m01*b.m12;

            c.m10 = a.m10*b.m00 + a.m11*b.m10;
            c.m11 = a.m10*b.m01 + a.m11*b.m11;
            c.m12 = a.m10*b.m02 + a.m11*b.m12;

            c.m20 = a.m20*b.m00 + a.m21*b.m10;
            c.m21 = a.m20*b.m01 + a.m21*b.m11;
            c.m22 = a.m20*b.m02 + a.m21*b.m12;

            c.m30 = a.m30*b.m00 + a.m31*b.m10;
            c.m31 = a.m30*b.m01 + a.m31*b.m11;
            c.m32 = a.m30*b.m02 + a.m31*b.m12;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(24)
            RM_STAT_SUM(12)
#endif

            return c;
        }

        template<typename T>
        inline TMatrix4x2<T> mul(const TMatrix4x2<T> &a, const TMatrix2x2<T> &b) {
            TMatrix4x2<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10;
            c.m01 = a.m00*b.m01 + a.m01*b.m11;

            c.m10 = a.m10*b.m00 + a.m11*b.m10;
            c.m11 = a.m10*b.m01 + a.m11*b.m11;

            c.m20 = a.m20*b.m00 + a.m21*b.m10;
            c.m21 = a.m20*b.m01 + a.m21*b.m11;

            c.m30 = a.m30*b.m00 + a.m31*b.m10;
            c.m31 = a.m30*b.m01 + a.m31*b.m11;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(16)
            RM_STAT_SUM(8)
#endif

            return c;
        }


        template<typename T>
        inline TMatrix4x1<T> mul(const TMatrix4x2<T> &a, const TMatrix2x1<T> &b) {
            TMatrix4x1<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10;
            c.m10 = a.m10*b.m00 + a.m11*b.m10;
            c.m20 = a.m20*b.m00 + a.m21*b.m10;
            c.m30 = a.m30*b.m00 + a.m31*b.m10;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(8)
            RM_STAT_SUM(4)
#endif

            return c;
        }


        namespace ___unsafe
        {
            template<typename T>
            inline void _mul(TMatrix4x2<T> &a, const TMatrix2x2<T> &b) {

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

                auto m30 = a.m30*b.m00 + a.m31*b.m10;
                auto m31 = a.m30*b.m01 + a.m31*b.m11;

                a.m30 = m30;
                a.m31 = m31;

#ifdef RM_MATH_STAT
                RM_STAT_MUL(16)
                RM_STAT_SUM(8)
#endif

            }
        }
    }
}

#endif //RMVECTORMATH_TMATRIX4X2_FUNC_MUL_HPP
