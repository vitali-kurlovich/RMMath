//
// Created by Vitali Kurlovich on 12/23/15.
//

#ifndef RMVECTORMATH_TMATRIX1X4_FUNC_MUL_HPP
#define RMVECTORMATH_TMATRIX1X4_FUNC_MUL_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TMatrix1x4_def.hpp"

#include "../../matrix4x4/TMatrix4x4_def.hpp"
#include "../../matrix4x3/TMatrix4x3_def.hpp"
#include "../../matrix4x2/TMatrix4x2_def.hpp"
#include "../../matrix4x1/TMatrix4x1_def.hpp"

#include "../../matrix1x4/TMatrix1x4_def.hpp"
#include "../../matrix1x3/TMatrix1x3_def.hpp"
#include "../../matrix1x2/TMatrix1x2_def.hpp"
#include "../../matrix1x1/TMatrix1x1_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline TMatrix1x4<T> mul(const TMatrix1x4<T> &a, const TMatrix4x4<T> &b) {
            TMatrix1x4<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20 + a.m03*b.m30;
            c.m01 = a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21 + a.m03*b.m31;
            c.m02 = a.m00*b.m02 + a.m01*b.m12 + a.m02*b.m22 + a.m03*b.m32;
            c.m03 = a.m00*b.m03 + a.m01*b.m13 + a.m02*b.m23 + a.m03*b.m33;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(16)
            RM_STAT_SUM(12)
#endif
            return c;
        }

        template<typename T>
        inline TMatrix1x3<T> mul(const TMatrix1x4<T> &a, const TMatrix4x3<T> &b) {
            TMatrix1x3<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20 + a.m03*b.m30;
            c.m01 = a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21 + a.m03*b.m31;
            c.m02 = a.m00*b.m02 + a.m01*b.m12 + a.m02*b.m22 + a.m03*b.m32;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(12)
            RM_STAT_SUM(9)
#endif
            return c;
        }

        template<typename T>
        inline TMatrix1x2<T> mul(const TMatrix1x4<T> &a, const TMatrix4x2<T> &b) {
            TMatrix1x2<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20 + a.m03*b.m30;
            c.m01 = a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21 + a.m03*b.m31;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(8)
            RM_STAT_SUM(6)
#endif
            return c;
        }

        template<typename T>
        inline TMatrix1x1<T> mul(const TMatrix1x4<T> &a, const TMatrix4x1<T> &b) {
            TMatrix1x1<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20 + a.m03*b.m30;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(4)
            RM_STAT_SUM(3)
#endif
            return c;
        }


        namespace ___unsafe {
            template<typename T>
            inline void _mul(TMatrix1x4<T> &a, const TMatrix4x4<T> &b) {
                auto m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20 + a.m03*b.m30;
                auto m01 = a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21 + a.m03*b.m31;
                auto m02 = a.m00*b.m02 + a.m01*b.m12 + a.m02*b.m22 + a.m03*b.m32;
                auto m03 = a.m00*b.m03 + a.m01*b.m13 + a.m02*b.m23 + a.m03*b.m33;

                a.m00 = m00;
                a.m01 = m01;
                a.m02 = m02;
                a.m03 = m03;

#ifdef RM_MATH_STAT
                RM_STAT_MUL(16)
                RM_STAT_SUM(12)
#endif
            }
        }


    }
}

#endif //RMVECTORMATH_TMATRIX1X4_FUNC_MUL_HPP
