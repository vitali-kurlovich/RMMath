//
// Created by Vitali Kurlovich on 1/8/16.
//

#ifndef RMVECTORMATH_TAFFINEMATRIX4X4_FUNC_MUL_HPP
#define RMVECTORMATH_TAFFINEMATRIX4X4_FUNC_MUL_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TAffineMatrix4x4_def.hpp"

#include "../../matrix4x4/TMatrix4x4_def.hpp"
#include "../../matrix4x3/TMatrix4x3_def.hpp"
#include "../../matrix4x2/TMatrix4x2_def.hpp"
#include "../../matrix4x1/TMatrix4x1_def.hpp"


#include "../../matrix3x4/TMatrix3x4_def.hpp"
#include "../../matrix2x4/TMatrix2x4_def.hpp"
#include "../../matrix1x4/TMatrix1x4_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline TAffineMatrix4x4<T> mul(const TAffineMatrix4x4<T> &a, const TAffineMatrix4x4<T> &b) {
            TAffineMatrix4x4<T> c;

            c.m00 = a.m00 * b.m00 + a.m01 * b.m10 + a.m02 * b.m20;
            c.m01 = a.m00 * b.m01 + a.m01 * b.m11 + a.m02 * b.m21;
            c.m02 = a.m00 * b.m02 + a.m01 * b.m12 + a.m02 * b.m22;

            c.m10 = a.m10 * b.m00 + a.m11 * b.m10 + a.m12 * b.m20;
            c.m11 = a.m10 * b.m01 + a.m11 * b.m11 + a.m12 * b.m21;
            c.m12 = a.m10 * b.m02 + a.m11 * b.m12 + a.m12 * b.m22;

            c.m20 = a.m20 * b.m00 + a.m21 * b.m10 + a.m22 * b.m20;
            c.m21 = a.m20 * b.m01 + a.m21 * b.m11 + a.m22 * b.m21;
            c.m22 = a.m20 * b.m02 + a.m21 * b.m12 + a.m22 * b.m22;

            c.m30 = a.m30 * b.m00 + a.m31 * b.m10 + a.m32 * b.m20 + b.m30;
            c.m31 = a.m30 * b.m01 + a.m31 * b.m11 + a.m32 * b.m21 + b.m31;
            c.m32 = a.m30 * b.m02 + a.m31 * b.m12 + a.m32 * b.m22 + b.m32;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(36)
            RM_STAT_SUM(27)
#endif
            return c;
        }


        template<typename T>
        inline TMatrix4x4<T> mul(const TAffineMatrix4x4<T> &a, const TMatrix4x4<T> &b) {
            TMatrix4x4<T> c;

            c.m00 = a.m00 * b.m00 + a.m01 * b.m10 + a.m02 * b.m20;
            c.m01 = a.m00 * b.m01 + a.m01 * b.m11 + a.m02 * b.m21;
            c.m02 = a.m00 * b.m02 + a.m01 * b.m12 + a.m02 * b.m22;
            c.m03 = a.m00 * b.m03 + a.m01 * b.m13 + a.m02 * b.m23;

            c.m10 = a.m10 * b.m00 + a.m11 * b.m10 + a.m12 * b.m20;
            c.m11 = a.m10 * b.m01 + a.m11 * b.m11 + a.m12 * b.m21;
            c.m12 = a.m10 * b.m02 + a.m11 * b.m12 + a.m12 * b.m22;
            c.m13 = a.m10 * b.m03 + a.m11 * b.m13 + a.m12 * b.m23;

            c.m20 = a.m20 * b.m00 + a.m21 * b.m10 + a.m22 * b.m20;
            c.m21 = a.m20 * b.m01 + a.m21 * b.m11 + a.m22 * b.m21;
            c.m22 = a.m20 * b.m02 + a.m21 * b.m12 + a.m22 * b.m22;
            c.m23 = a.m20 * b.m03 + a.m21 * b.m13 + a.m22 * b.m23;

            c.m30 = a.m30 * b.m00 + a.m31 * b.m10 + a.m32 * b.m20 + b.m30;
            c.m31 = a.m30 * b.m01 + a.m31 * b.m11 + a.m32 * b.m21 + b.m31;
            c.m32 = a.m30 * b.m02 + a.m31 * b.m12 + a.m32 * b.m22 + b.m32;
            c.m33 = a.m30 * b.m03 + a.m31 * b.m13 + a.m32 * b.m23 + b.m33;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(48)
            RM_STAT_SUM(36)
#endif
            return c;
        }


        template<typename T>
        inline TMatrix4x4<T> mul(const TMatrix4x4<T> &a, const TAffineMatrix4x4<T> &b) {
            TMatrix4x4<T> c;

            c.m00 = a.m00 * b.m00 + a.m01 * b.m10 + a.m02 * b.m20 + a.m03 * b.m30;
            c.m01 = a.m00 * b.m01 + a.m01 * b.m11 + a.m02 * b.m21 + a.m03 * b.m31;
            c.m02 = a.m00 * b.m02 + a.m01 * b.m12 + a.m02 * b.m22 + a.m03 * b.m32;
            c.m03 = a.m03;

            c.m10 = a.m10 * b.m00 + a.m11 * b.m10 + a.m12 * b.m20 + a.m13 * b.m30;
            c.m11 = a.m10 * b.m01 + a.m11 * b.m11 + a.m12 * b.m21 + a.m13 * b.m31;
            c.m12 = a.m10 * b.m02 + a.m11 * b.m12 + a.m12 * b.m22 + a.m13 * b.m32;
            c.m13 = a.m13;

            c.m20 = a.m20 * b.m00 + a.m21 * b.m10 + a.m22 * b.m20 + a.m23 * b.m30;
            c.m21 = a.m20 * b.m01 + a.m21 * b.m11 + a.m22 * b.m21 + a.m23 * b.m31;
            c.m22 = a.m20 * b.m02 + a.m21 * b.m12 + a.m22 * b.m22 + a.m23 * b.m32;
            c.m23 = a.m23;

            c.m30 = a.m30 * b.m00 + a.m31 * b.m10 + a.m32 * b.m20 + a.m33 * b.m30;
            c.m31 = a.m30 * b.m01 + a.m31 * b.m11 + a.m32 * b.m21 + a.m33 * b.m31;
            c.m32 = a.m30 * b.m02 + a.m31 * b.m12 + a.m32 * b.m22 + a.m33 * b.m32;
            c.m33 = a.m33;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(48)
            RM_STAT_SUM(36)
#endif
            return c;
        }


        template<typename T>
        inline TMatrix4x3<T> mul(const TAffineMatrix4x4<T> &a, const TMatrix4x3<T> &b) {
            TMatrix4x3<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20;
            c.m01 = a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21;
            c.m02 = a.m00*b.m02 + a.m01*b.m12 + a.m02*b.m22;

            c.m10 = a.m10*b.m00 + a.m11*b.m10 + a.m12*b.m20;
            c.m11 = a.m10*b.m01 + a.m11*b.m11 + a.m12*b.m21;
            c.m12 = a.m10*b.m02 + a.m11*b.m12 + a.m12*b.m22;

            c.m20 = a.m20*b.m00 + a.m21*b.m10 + a.m22*b.m20;
            c.m21 = a.m20*b.m01 + a.m21*b.m11 + a.m22*b.m21;
            c.m22 = a.m20*b.m02 + a.m21*b.m12 + a.m22*b.m22;

            c.m30 = a.m30*b.m00 + a.m31*b.m10 + a.m32*b.m20 + b.m30;
            c.m31 = a.m30*b.m01 + a.m31*b.m11 + a.m32*b.m21 + b.m31;
            c.m32 = a.m30*b.m02 + a.m31*b.m12 + a.m32*b.m22 + b.m32;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(36)
            RM_STAT_SUM(27)
#endif
            return c;
        }


        template<typename T>
        inline TMatrix3x4<T> mul(const TMatrix3x4<T> &a, const TAffineMatrix4x4<T> &b) {
            TMatrix3x4<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20 + a.m03*b.m30;
            c.m01 = a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21 + a.m03*b.m31;
            c.m02 = a.m00*b.m02 + a.m01*b.m12 + a.m02*b.m22 + a.m03*b.m32;
            c.m03 = a.m03;

            c.m10 = a.m10*b.m00 + a.m11*b.m10 + a.m12*b.m20 + a.m13*b.m30;
            c.m11 = a.m10*b.m01 + a.m11*b.m11 + a.m12*b.m21 + a.m13*b.m31;
            c.m12 = a.m10*b.m02 + a.m11*b.m12 + a.m12*b.m22 + a.m13*b.m32;
            c.m13 = a.m13;

            c.m20 = a.m20*b.m00 + a.m21*b.m10 + a.m22*b.m20 + a.m23*b.m30;
            c.m21 = a.m20*b.m01 + a.m21*b.m11 + a.m22*b.m21 + a.m23*b.m31;
            c.m22 = a.m20*b.m02 + a.m21*b.m12 + a.m22*b.m22 + a.m23*b.m32;
            c.m23 = a.m23;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(36)
            RM_STAT_SUM(27)
#endif
            return c;
        }


        template<typename T>
        inline TMatrix4x2<T> mul(const TAffineMatrix4x4<T> &a, const TMatrix4x2<T> &b) {
            TMatrix4x2<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20;
            c.m01 = a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21;

            c.m10 = a.m10*b.m00 + a.m11*b.m10 + a.m12*b.m20;
            c.m11 = a.m10*b.m01 + a.m11*b.m11 + a.m12*b.m21;

            c.m20 = a.m20*b.m00 + a.m21*b.m10 + a.m22*b.m20;
            c.m21 = a.m20*b.m01 + a.m21*b.m11 + a.m22*b.m21;

            c.m30 = a.m30*b.m00 + a.m31*b.m10 + a.m32*b.m20 + b.m30;
            c.m31 = a.m30*b.m01 + a.m31*b.m11 + a.m32*b.m21 + b.m31;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(24)
            RM_STAT_SUM(18)
#endif
            return c;
        }


        template<typename T>
        inline TMatrix2x4<T> mul(const TMatrix2x4<T> &a, const TAffineMatrix4x4<T> &b) {
            TMatrix2x4<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20 + a.m03*b.m30;
            c.m01 = a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21 + a.m03*b.m31;
            c.m02 = a.m00*b.m02 + a.m01*b.m12 + a.m02*b.m22 + a.m03*b.m32;
            c.m03 = a.m03;

            c.m10 = a.m10*b.m00 + a.m11*b.m10 + a.m12*b.m20 + a.m13*b.m30;
            c.m11 = a.m10*b.m01 + a.m11*b.m11 + a.m12*b.m21 + a.m13*b.m31;
            c.m12 = a.m10*b.m02 + a.m11*b.m12 + a.m12*b.m22 + a.m13*b.m32;
            c.m13 = a.m13;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(24)
            RM_STAT_SUM(18)
#endif
            return c;
        }


        template<typename T>
        inline TMatrix4x1<T> mul(const TAffineMatrix4x4<T> &a, const TMatrix4x1<T> &b) {
            TMatrix4x1<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20;
            c.m10 = a.m10*b.m00 + a.m11*b.m10 + a.m12*b.m20;
            c.m20 = a.m20*b.m00 + a.m21*b.m10 + a.m22*b.m20;
            c.m30 = a.m30*b.m00 + a.m31*b.m10 + a.m32*b.m20 + b.m30;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(12)
            RM_STAT_SUM(9)
#endif
            return c;
        }


        template<typename T>
        inline TMatrix1x4<T> mul(const TMatrix1x4<T> &a, const TAffineMatrix4x4<T> &b) {
            TMatrix1x4<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20 + a.m03*b.m30;
            c.m01 = a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21 + a.m03*b.m31;
            c.m02 = a.m00*b.m02 + a.m01*b.m12 + a.m02*b.m22 + a.m03*b.m32;
            c.m03 = a.m03;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(12)
            RM_STAT_SUM(9)
#endif
            return c;
        }

        namespace ___unsafe {
            template<typename T>
            inline void _mul(TAffineMatrix4x4<T> &a, const TAffineMatrix4x4<T> &b) {

                auto m00 = a.m00 * b.m00 + a.m01 * b.m10 + a.m02 * b.m20;
                auto m01 = a.m00 * b.m01 + a.m01 * b.m11 + a.m02 * b.m21;
                auto m02 = a.m00 * b.m02 + a.m01 * b.m12 + a.m02 * b.m22;

                a.m00 = m00;
                a.m01 = m01;
                a.m02 = m02;

                auto m10 = a.m10 * b.m00 + a.m11 * b.m10 + a.m12 * b.m20;
                auto m11 = a.m10 * b.m01 + a.m11 * b.m11 + a.m12 * b.m21;
                auto m12 = a.m10 * b.m02 + a.m11 * b.m12 + a.m12 * b.m22;

                a.m10 = m10;
                a.m11 = m11;
                a.m12 = m12;

                auto m20 = a.m20 * b.m00 + a.m21 * b.m10 + a.m22 * b.m20;
                auto m21 = a.m20 * b.m01 + a.m21 * b.m11 + a.m22 * b.m21;
                auto m22 = a.m20 * b.m02 + a.m21 * b.m12 + a.m22 * b.m22;

                a.m20 = m20;
                a.m21 = m21;
                a.m22 = m22;

                auto m30 = a.m30 * b.m00 + a.m31 * b.m10 + a.m32 * b.m20 + b.m30;
                auto m31 = a.m30 * b.m01 + a.m31 * b.m11 + a.m32 * b.m21 + b.m31;
                auto m32 = a.m30 * b.m02 + a.m31 * b.m12 + a.m32 * b.m22 + b.m32;

                a.m30 = m30;
                a.m31 = m31;
                a.m32 = m32;

#ifdef RM_MATH_STAT
                RM_STAT_MUL(36)
                RM_STAT_SUM(27)
#endif
            }

            template<typename T>
            inline void _mul(TMatrix4x4<T> &a, const TAffineMatrix4x4<T> &b) {
                auto m00 = a.m00 * b.m00 + a.m01 * b.m10 + a.m02 * b.m20 + a.m03 * b.m30;
                auto m01 = a.m00 * b.m01 + a.m01 * b.m11 + a.m02 * b.m21 + a.m03 * b.m31;
                auto m02 = a.m00 * b.m02 + a.m01 * b.m12 + a.m02 * b.m22 + a.m03 * b.m32;

                a.m00 = m00;
                a.m01 = m01;
                a.m02 = m02;

                auto m10 = a.m10 * b.m00 + a.m11 * b.m10 + a.m12 * b.m20 + a.m13 * b.m30;
                auto m11 = a.m10 * b.m01 + a.m11 * b.m11 + a.m12 * b.m21 + a.m13 * b.m31;
                auto m12 = a.m10 * b.m02 + a.m11 * b.m12 + a.m12 * b.m22 + a.m13 * b.m32;

                a.m10 = m10;
                a.m11 = m11;
                a.m12 = m12;

                auto m20 = a.m20 * b.m00 + a.m21 * b.m10 + a.m22 * b.m20 + a.m23 * b.m30;
                auto m21 = a.m20 * b.m01 + a.m21 * b.m11 + a.m22 * b.m21 + a.m23 * b.m31;
                auto m22 = a.m20 * b.m02 + a.m21 * b.m12 + a.m22 * b.m22 + a.m23 * b.m32;

                a.m20 = m20;
                a.m21 = m21;
                a.m22 = m22;

                auto m30 = a.m30 * b.m00 + a.m31 * b.m10 + a.m32 * b.m20 + a.m33 * b.m30;
                auto m31 = a.m30 * b.m01 + a.m31 * b.m11 + a.m32 * b.m21 + a.m33 * b.m31;
                auto m32 = a.m30 * b.m02 + a.m31 * b.m12 + a.m32 * b.m22 + a.m33 * b.m32;

                a.m30 = m30;
                a.m31 = m31;
                a.m32 = m32;

#ifdef RM_MATH_STAT
                RM_STAT_MUL(48)
                RM_STAT_SUM(36)
#endif
            }


            template<typename T>
            inline void _mul(TMatrix3x4<T> &a, const TAffineMatrix4x4<T> &b) {

                auto m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20 + a.m03*b.m30;
                auto m01 = a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21 + a.m03*b.m31;
                auto m02 = a.m00*b.m02 + a.m01*b.m12 + a.m02*b.m22 + a.m03*b.m32;

                a.m00 = m00;
                a.m01 = m01;
                a.m02 = m02;

                auto m10 = a.m10*b.m00 + a.m11*b.m10 + a.m12*b.m20 + a.m13*b.m30;
                auto m11 = a.m10*b.m01 + a.m11*b.m11 + a.m12*b.m21 + a.m13*b.m31;
                auto m12 = a.m10*b.m02 + a.m11*b.m12 + a.m12*b.m22 + a.m13*b.m32;

                a.m10 = m10;
                a.m11 = m11;
                a.m12 = m12;

                auto m20 = a.m20*b.m00 + a.m21*b.m10 + a.m22*b.m20 + a.m23*b.m30;
                auto m21 = a.m20*b.m01 + a.m21*b.m11 + a.m22*b.m21 + a.m23*b.m31;
                auto m22 = a.m20*b.m02 + a.m21*b.m12 + a.m22*b.m22 + a.m23*b.m32;

                a.m20 = m20;
                a.m21 = m21;
                a.m22 = m22;

#ifdef RM_MATH_STAT
                RM_STAT_MUL(36)
                RM_STAT_SUM(27)
#endif
            }

            template<typename T>
            inline void _mul(TMatrix2x4<T> &a, const TAffineMatrix4x4<T> &b) {

                auto m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20 + a.m03*b.m30;
                auto m01 = a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21 + a.m03*b.m31;
                auto m02 = a.m00*b.m02 + a.m01*b.m12 + a.m02*b.m22 + a.m03*b.m32;

                a.m00 = m00;
                a.m01 = m01;
                a.m02 = m02;

                auto m10 = a.m10*b.m00 + a.m11*b.m10 + a.m12*b.m20 + a.m13*b.m30;
                auto m11 = a.m10*b.m01 + a.m11*b.m11 + a.m12*b.m21 + a.m13*b.m31;
                auto m12 = a.m10*b.m02 + a.m11*b.m12 + a.m12*b.m22 + a.m13*b.m32;

                a.m10 = m10;
                a.m11 = m11;
                a.m12 = m12;

#ifdef RM_MATH_STAT
                RM_STAT_MUL(24)
                RM_STAT_SUM(18)
#endif
            }

            template<typename T>
            inline void _mul(TMatrix1x4<T> &a, const TAffineMatrix4x4<T> &b) {

                auto m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20 + a.m03*b.m30;
                auto m01 = a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21 + a.m03*b.m31;
                auto m02 = a.m00*b.m02 + a.m01*b.m12 + a.m02*b.m22 + a.m03*b.m32;

                a.m00 = m00;
                a.m01 = m01;
                a.m02 = m02;

#ifdef RM_MATH_STAT
                RM_STAT_MUL(12)
                RM_STAT_SUM(9)
#endif
            }
        }
    }
}

#endif //RMVECTORMATH_TAFFINEMATRIX4X4_FUNC_MUL_HPP
