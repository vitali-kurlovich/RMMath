//
// Created by Vitali Kurlovich on 12/21/15.
//

#ifndef RMVECTORMATH_TMATRIX4X1_FUNC_MUL_HPP
#define RMVECTORMATH_TMATRIX4X1_FUNC_MUL_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TMatrix4x1_def.hpp"

#include "../../matrix1x4/TMatrix1x4_def.hpp"
#include "../../matrix1x3/TMatrix1x3_def.hpp"
#include "../../matrix1x2/TMatrix1x2_def.hpp"
#include "../../matrix1x1/TMatrix1x1_def.hpp"

#include "../../matrix4x4/TMatrix4x4_def.hpp"
#include "../../matrix4x3/TMatrix4x3_def.hpp"
#include "../../matrix4x2/TMatrix4x2_def.hpp"
#include "../../matrix4x1/TMatrix4x1_def.hpp"

namespace rmmath {

    namespace matrix {

        template<typename T>
        inline TMatrix4x4 <T> mul(const TMatrix4x1 <T> &a, const TMatrix1x4 <T> &b) {
            TMatrix4x4<T> c;

            c.m00 = a.m00 * b.m00;
            c.m01 = a.m00 * b.m01;
            c.m02 = a.m00 * b.m02;
            c.m03 = a.m00 * b.m03;

            c.m10 = a.m10 * b.m00;
            c.m11 = a.m10 * b.m01;
            c.m12 = a.m10 * b.m02;
            c.m13 = a.m10 * b.m03;

            c.m20 = a.m20 * b.m00;
            c.m21 = a.m20 * b.m01;
            c.m22 = a.m20 * b.m02;
            c.m23 = a.m20 * b.m03;

            c.m30 = a.m30 * b.m00;
            c.m31 = a.m30 * b.m01;
            c.m32 = a.m30 * b.m02;
            c.m33 = a.m30 * b.m03;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(16)
#endif
            return c;
        }

        template<typename T>
        inline TMatrix4x3 <T> mul(const TMatrix4x1 <T> &a, const TMatrix1x3 <T> &b) {
            TMatrix4x3<T> c;

            c.m00 = a.m00 * b.m00;
            c.m01 = a.m00 * b.m01;
            c.m02 = a.m00 * b.m02;

            c.m10 = a.m10 * b.m00;
            c.m11 = a.m10 * b.m01;
            c.m12 = a.m10 * b.m02;

            c.m20 = a.m20 * b.m00;
            c.m21 = a.m20 * b.m01;
            c.m22 = a.m20 * b.m02;

            c.m30 = a.m30 * b.m00;
            c.m31 = a.m30 * b.m01;
            c.m32 = a.m30 * b.m02;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(12)
#endif

            return c;
        }

        template<typename T>
        inline TMatrix4x2 <T> mul(const TMatrix4x1 <T> &a, const TMatrix1x2 <T> &b) {
            TMatrix4x2<T> c;

            c.m00 = a.m00 * b.m00;
            c.m01 = a.m00 * b.m01;

            c.m10 = a.m10 * b.m00;
            c.m11 = a.m10 * b.m01;

            c.m20 = a.m20 * b.m00;
            c.m21 = a.m20 * b.m01;

            c.m30 = a.m30 * b.m00;
            c.m31 = a.m30 * b.m01;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(8)
#endif
            return c;
        }

        template<typename T>
        inline TMatrix4x1 <T> mul(const TMatrix4x1 <T> &a, const TMatrix1x1 <T> &b) {
            TMatrix4x1<T> c;

            c.m00 = a.m00 * b.m00;
            c.m10 = a.m10 * b.m00;
            c.m20 = a.m20 * b.m00;
            c.m30 = a.m30 * b.m00;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(4)
#endif
            return c;
        }


        namespace ___unsafe {
            template<typename T>
            inline void _mul(TMatrix4x1 <T> &a, const TMatrix1x1 <T> &b) {
                a.m00 *= b.m00;
                a.m10 *= b.m00;
                a.m20 *= b.m00;
                a.m30 *= b.m00;

#ifdef RM_MATH_STAT
                RM_STAT_MUL(4)
#endif
            }

        }

    }
}

#endif //RMVECTORMATH_TMATRIX4X1_FUNC_MUL_HPP
