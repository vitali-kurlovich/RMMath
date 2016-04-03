//
// Created by Vitali Kurlovich on 12/19/15.
//

#ifndef RMVECTORMATH_TMATRIX3X4_FUNC_MUL_HPP
#define RMVECTORMATH_TMATRIX3X4_FUNC_MUL_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TMatrix3x4_def.hpp"

#include "../../matrix3x4/TMatrix3x4_def.hpp"
#include "../../matrix3x3/TMatrix3x3_def.hpp"
#include "../../matrix3x2/TMatrix3x2_def.hpp"
#include "../../matrix3x1/TMatrix3x1_def.hpp"

#include "../../matrix4x4/TMatrix4x4_def.hpp"
#include "../../matrix4x3/TMatrix4x3_def.hpp"
#include "../../matrix4x2/TMatrix4x2_def.hpp"
#include "../../matrix4x1/TMatrix4x1_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline TMatrix3x4<T> mul(const TMatrix3x4<T> &a, const TMatrix4x4<T> &b) {
            TMatrix3x4<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20 + a.m03*b.m30;
            c.m01 = a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21 + a.m03*b.m31;
            c.m02 = a.m00*b.m02 + a.m01*b.m12 + a.m02*b.m22 + a.m03*b.m32;
            c.m03 = a.m00*b.m03 + a.m01*b.m13 + a.m02*b.m23 + a.m03*b.m33;

            c.m10 = a.m10*b.m00 + a.m11*b.m10 + a.m12*b.m20 + a.m13*b.m30;
            c.m11 = a.m10*b.m01 + a.m11*b.m11 + a.m12*b.m21 + a.m13*b.m31;
            c.m12 = a.m10*b.m02 + a.m11*b.m12 + a.m12*b.m22 + a.m13*b.m32;
            c.m13 = a.m10*b.m03 + a.m11*b.m13 + a.m12*b.m23 + a.m13*b.m33;

            c.m20 = a.m20*b.m00 + a.m21*b.m10 + a.m22*b.m20 + a.m23*b.m30;
            c.m21 = a.m20*b.m01 + a.m21*b.m11 + a.m22*b.m21 + a.m23*b.m31;
            c.m22 = a.m20*b.m02 + a.m21*b.m12 + a.m22*b.m22 + a.m23*b.m32;
            c.m23 = a.m20*b.m03 + a.m21*b.m13 + a.m22*b.m23 + a.m23*b.m33;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(48)
            RM_STAT_SUM(36)
#endif
            return c;
        }


        template<typename T>
        inline TMatrix3x3<T> mul(const TMatrix3x4<T> &a, const TMatrix4x3<T> &b) {
            TMatrix3x3<T> c;
            c.m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20 + a.m03*b.m30;
            c.m01 = a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21 + a.m03*b.m31;
            c.m02 = a.m00*b.m02 + a.m01*b.m12 + a.m02*b.m22 + a.m03*b.m32;

            c.m10 = a.m10*b.m00 + a.m11*b.m10 + a.m12*b.m20 + a.m13*b.m30;
            c.m11 = a.m10*b.m01 + a.m11*b.m11 + a.m12*b.m21 + a.m13*b.m31;
            c.m12 = a.m10*b.m02 + a.m11*b.m12 + a.m12*b.m22 + a.m13*b.m32;

            c.m20 = a.m20*b.m00 + a.m21*b.m10 + a.m22*b.m20 + a.m23*b.m30;
            c.m21 = a.m20*b.m01 + a.m21*b.m11 + a.m22*b.m21 + a.m23*b.m31;
            c.m22 = a.m20*b.m02 + a.m21*b.m12 + a.m22*b.m22 + a.m23*b.m32;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(36)
            RM_STAT_SUM(27)
#endif

            return c;
        }

        template<typename T>
        inline TMatrix3x2<T> mul(const TMatrix3x4<T> &a, const TMatrix4x2<T> &b) {
            TMatrix3x2<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20 + a.m03*b.m30;
            c.m01 = a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21 + a.m03*b.m31;

            c.m10 = a.m10*b.m00 + a.m11*b.m10 + a.m12*b.m20 + a.m13*b.m30;
            c.m11 = a.m10*b.m01 + a.m11*b.m11 + a.m12*b.m21 + a.m13*b.m31;

            c.m20 = a.m20*b.m00 + a.m21*b.m10 + a.m22*b.m20 + a.m23*b.m30;
            c.m21 = a.m20*b.m01 + a.m21*b.m11 + a.m22*b.m21 + a.m23*b.m31;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(24)
            RM_STAT_SUM(18)
#endif
            return c;
        }


        template<typename T>
        inline TMatrix3x1<T> mul(const TMatrix3x4<T> &a, const TMatrix4x1<T> &b) {
            TMatrix3x1<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20 + a.m03*b.m30;
            c.m10 = a.m10*b.m00 + a.m11*b.m10 + a.m12*b.m20 + a.m13*b.m30;
            c.m20 = a.m20*b.m00 + a.m21*b.m10 + a.m22*b.m20 + a.m23*b.m30;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(12)
            RM_STAT_SUM(9)
#endif

            return c;
        }


        namespace ___unsafe
        {
            template<typename T>
            inline void _mul(TMatrix3x4<T> &a, const TMatrix4x4<T> &b) {

                auto m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20 + a.m03*b.m30;
                auto m01 = a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21 + a.m03*b.m31;
                auto m02 = a.m00*b.m02 + a.m01*b.m12 + a.m02*b.m22 + a.m03*b.m32;
                auto m03 = a.m00*b.m03 + a.m01*b.m13 + a.m02*b.m23 + a.m03*b.m33;

                a.m00 = m00;
                a.m01 = m01;
                a.m02 = m02;
                a.m03 = m03;

                auto m10 = a.m10*b.m00 + a.m11*b.m10 + a.m12*b.m20 + a.m13*b.m30;
                auto m11 = a.m10*b.m01 + a.m11*b.m11 + a.m12*b.m21 + a.m13*b.m31;
                auto m12 = a.m10*b.m02 + a.m11*b.m12 + a.m12*b.m22 + a.m13*b.m32;
                auto m13 = a.m10*b.m03 + a.m11*b.m13 + a.m12*b.m23 + a.m13*b.m33;

                a.m10 = m10;
                a.m11 = m11;
                a.m12 = m12;
                a.m13 = m13;

                auto m20 = a.m20*b.m00 + a.m21*b.m10 + a.m22*b.m20 + a.m23*b.m30;
                auto m21 = a.m20*b.m01 + a.m21*b.m11 + a.m22*b.m21 + a.m23*b.m31;
                auto m22 = a.m20*b.m02 + a.m21*b.m12 + a.m22*b.m22 + a.m23*b.m32;
                auto m23 = a.m20*b.m03 + a.m21*b.m13 + a.m22*b.m23 + a.m23*b.m33;

                a.m20 = m20;
                a.m21 = m21;
                a.m22 = m22;
                a.m23 = m23;

#ifdef RM_MATH_STAT
                RM_STAT_MUL(48)
                RM_STAT_SUM(36)
#endif
            }
        }
    }
}


#endif //RMVECTORMATH_TMATRIX3X4_FUNC_MUL_HPP
