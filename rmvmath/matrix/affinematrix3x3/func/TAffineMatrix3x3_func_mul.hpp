//
// Created by Vitali Kurlovich on 1/12/16.
//

#ifndef RMVECTORMATH_TAFFINEMATRIX3X3_FUNC_MUL_HPP
#define RMVECTORMATH_TAFFINEMATRIX3X3_FUNC_MUL_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TAffineMatrix3x3_def.hpp"

#include "../../matrix3x4/TMatrix3x4_def.hpp"
#include "../../matrix3x3/TMatrix3x3_def.hpp"
#include "../../matrix3x2/TMatrix3x2_def.hpp"
#include "../../matrix3x1/TMatrix3x1_def.hpp"

#include "../../matrix4x3/TMatrix4x3_def.hpp"
#include "../../matrix3x3/TMatrix3x3_def.hpp"
#include "../../matrix2x3/TMatrix2x3_def.hpp"
#include "../../matrix1x3/TMatrix1x3_def.hpp"

namespace rmmath {

    namespace matrix {

        template<typename T>
        inline TAffineMatrix3x3<T> mul(const TAffineMatrix3x3<T> &a, const TAffineMatrix3x3<T> &b) {
            TAffineMatrix3x3<T> c;

            c.m00 = a.m00 * b.m00 + a.m01 * b.m10;
            c.m01 = a.m00 * b.m01 + a.m01 * b.m11;

            c.m10 = a.m10 * b.m00 + a.m11 * b.m10;
            c.m11 = a.m10 * b.m01 + a.m11 * b.m11;

            c.m20 = a.m20 * b.m00 + a.m21 * b.m10 + b.m20;
            c.m21 = a.m20 * b.m01 + a.m21 * b.m11 + b.m21;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(12)
            RM_STAT_SUM(8)
#endif
            return c;
        }


        template<typename T>
        inline TMatrix3x4<T> mul(const TAffineMatrix3x3<T> &a, const TMatrix3x4<T> &b) {
            TMatrix3x4<T> c;

            c.m00 = a.m00 * b.m00 + a.m01 * b.m10;
            c.m01 = a.m00 * b.m01 + a.m01 * b.m11;
            c.m02 = a.m00 * b.m02 + a.m01 * b.m12;
            c.m03 = a.m00 * b.m03 + a.m01 * b.m13;

            c.m10 = a.m10 * b.m00 + a.m11 * b.m10;
            c.m11 = a.m10 * b.m01 + a.m11 * b.m11;
            c.m12 = a.m10 * b.m02 + a.m11 * b.m12;
            c.m13 = a.m10 * b.m03 + a.m11 * b.m13;

            c.m20 = a.m20 * b.m00 + a.m21 * b.m10 + b.m20;
            c.m21 = a.m20 * b.m01 + a.m21 * b.m11 + b.m21;
            c.m22 = a.m20 * b.m02 + a.m21 * b.m12 + b.m22;
            c.m23 = a.m20 * b.m03 + a.m21 * b.m13 + b.m23;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(24)
            RM_STAT_SUM(16)
#endif
            return c;
        }

        template<typename T>
        inline TMatrix4x3<T> mul(const TMatrix4x3<T> &a, const TAffineMatrix3x3<T> &b) {
            TMatrix4x3<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20;
            c.m01 = a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21;
            c.m02 = a.m02;

            c.m10 = a.m10*b.m00 + a.m11*b.m10 + a.m12*b.m20;
            c.m11 = a.m10*b.m01 + a.m11*b.m11 + a.m12*b.m21;
            c.m12 = a.m12;

            c.m20 = a.m20*b.m00 + a.m21*b.m10 + a.m22*b.m20;
            c.m21 = a.m20*b.m01 + a.m21*b.m11 + a.m22*b.m21;
            c.m22 = a.m22;

            c.m30 = a.m30*b.m00 + a.m31*b.m10 + a.m32*b.m20;
            c.m31 = a.m30*b.m01 + a.m31*b.m11 + a.m32*b.m21;
            c.m32 = a.m32;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(24)
            RM_STAT_SUM(16)
#endif
            return c;
        }


        template<typename T>
        inline TMatrix3x3<T> mul(const TAffineMatrix3x3<T> &a, const TMatrix3x3<T> &b) {
            TMatrix3x3<T> c;

            c.m00 = a.m00 * b.m00 + a.m01 * b.m10;
            c.m01 = a.m00 * b.m01 + a.m01 * b.m11;
            c.m02 = a.m00 * b.m02 + a.m01 * b.m12;

            c.m10 = a.m10 * b.m00 + a.m11 * b.m10;
            c.m11 = a.m10 * b.m01 + a.m11 * b.m11;
            c.m12 = a.m10 * b.m02 + a.m11 * b.m12;

            c.m20 = a.m20 * b.m00 + a.m21 * b.m10 + b.m20;
            c.m21 = a.m20 * b.m01 + a.m21 * b.m11 + b.m21;
            c.m22 = a.m20 * b.m02 + a.m21 * b.m12 + b.m22;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(18)
            RM_STAT_SUM(12)
#endif
            return c;
        }

        template<typename T>
        inline TMatrix3x3<T> mul(const TMatrix3x3<T> &a, const TAffineMatrix3x3<T> &b) {
            TMatrix3x3<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20;
            c.m01 = a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21;
            c.m02 = a.m02;


            c.m10 = a.m10*b.m00 + a.m11*b.m10 + a.m12*b.m20;
            c.m11 = a.m10*b.m01 + a.m11*b.m11 + a.m12*b.m21;
            c.m12 = a.m12;


            c.m20 = a.m20*b.m00 + a.m21*b.m10 + a.m22*b.m20;
            c.m21 = a.m20*b.m01 + a.m21*b.m11 + a.m22*b.m21;
            c.m22 = a.m22;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(18)
            RM_STAT_SUM(12)
#endif
            return c;
        }


        template<typename T>
        inline TMatrix3x2<T> mul(const TAffineMatrix3x3<T> &a, const TMatrix3x2<T> &b) {
            TMatrix3x2<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10;
            c.m01 = a.m00*b.m01 + a.m01*b.m11;

            c.m10 = a.m10*b.m00 + a.m11*b.m10;
            c.m11 = a.m10*b.m01 + a.m11*b.m11;

            c.m20 = a.m20*b.m00 + a.m21*b.m10 + b.m20;
            c.m21 = a.m20*b.m01 + a.m21*b.m11 + b.m21;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(12)
            RM_STAT_SUM(8)
#endif
            return c;
        }


        template<typename T>
        inline TMatrix2x3<T> mul(const TMatrix2x3<T> &a, const TAffineMatrix3x3<T> &b) {
            TMatrix2x3<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20;
            c.m01 = a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21;
            c.m02 = a.m02;

            c.m10 = a.m10*b.m00 + a.m11*b.m10 + a.m12*b.m20;
            c.m11 = a.m10*b.m01 + a.m11*b.m11 + a.m12*b.m21;
            c.m12 = a.m12;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(12)
            RM_STAT_SUM(8)
#endif
            return c;
        }

        template<typename T>
        inline TMatrix3x1<T> mul(const TAffineMatrix3x3<T> &a, const TMatrix3x1<T> &b) {
            TMatrix3x1<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10;
            c.m10 = a.m10*b.m00 + a.m11*b.m10;
            c.m20 = a.m20*b.m00 + a.m21*b.m10 + b.m20;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(6)
            RM_STAT_SUM(4)
#endif
            return c;
        }

        template<typename T>
        inline TMatrix1x3<T> mul(const TMatrix1x3<T> &a, const TAffineMatrix3x3<T> &b) {
            TMatrix1x3<T> c;

            c.m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20;
            c.m01 = a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21;
            c.m02 = a.m02;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(6)
            RM_STAT_SUM(4)
#endif
            return c;
        }

        namespace ___unsafe {
            template<typename T>
            inline void _mul(TAffineMatrix3x3<T> &a, const TAffineMatrix3x3<T> &b) {

                auto m00 = a.m00 * b.m00 + a.m01 * b.m10;
                auto m01 = a.m00 * b.m01 + a.m01 * b.m11;

                a.m00 = m00;
                a.m01 = m01;

                auto m10 = a.m10 * b.m00 + a.m11 * b.m10;
                auto m11 = a.m10 * b.m01 + a.m11 * b.m11;

                a.m10 = m10;
                a.m11 = m11;

                auto m20 = a.m20 * b.m00 + a.m21 * b.m10 + b.m20;
                auto m21 = a.m20 * b.m01 + a.m21 * b.m11 + b.m21;

                a.m20 = m20;
                a.m21 = m21;

#ifdef RM_MATH_STAT
                RM_STAT_MUL(12)
                RM_STAT_SUM(8)
#endif
            }


            template<typename T>
            inline void _mul(TMatrix4x3<T> &a, const TAffineMatrix3x3<T> &b) {

                auto m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20;
                auto m01 = a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21;
                a.m00 = m00;
                a.m01 = m01;

                auto m10 = a.m10*b.m00 + a.m11*b.m10 + a.m12*b.m20;
                auto m11 = a.m10*b.m01 + a.m11*b.m11 + a.m12*b.m21;
                a.m10 = m10;
                a.m11 = m11;

                auto m20 = a.m20*b.m00 + a.m21*b.m10 + a.m22*b.m20;
                auto m21 = a.m20*b.m01 + a.m21*b.m11 + a.m22*b.m21;
                a.m20 = m20;
                a.m21 = m21;

                auto m30 = a.m30*b.m00 + a.m31*b.m10 + a.m32*b.m20;
                auto m31 = a.m30*b.m01 + a.m31*b.m11 + a.m32*b.m21;

                a.m30 = m30;
                a.m31 = m31;

#ifdef RM_MATH_STAT
                RM_STAT_MUL(24)
                RM_STAT_SUM(16)
#endif
            }

            template<typename T>
            inline void _mul(TMatrix3x3<T> &a, const TAffineMatrix3x3<T> &b) {

                auto m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20;
                auto m01 = a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21;
                a.m00 = m00;
                a.m01 = m01;

                auto m10 = a.m10*b.m00 + a.m11*b.m10 + a.m12*b.m20;
                auto m11 = a.m10*b.m01 + a.m11*b.m11 + a.m12*b.m21;
                a.m10 = m10;
                a.m11 = m11;

                auto m20 = a.m20*b.m00 + a.m21*b.m10 + a.m22*b.m20;
                auto m21 = a.m20*b.m01 + a.m21*b.m11 + a.m22*b.m21;
                a.m20 = m20;
                a.m21 = m21;

#ifdef RM_MATH_STAT
                RM_STAT_MUL(18)
                RM_STAT_SUM(12)
#endif
            }

            template<typename T>
            inline void _mul(TMatrix2x3<T> &a, const TAffineMatrix3x3<T> &b) {

                auto m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20;
                auto m01 = a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21;
                a.m00 = m00;
                a.m01 = m01;

                auto m10 = a.m10*b.m00 + a.m11*b.m10 + a.m12*b.m20;
                auto m11 = a.m10*b.m01 + a.m11*b.m11 + a.m12*b.m21;
                a.m10 = m10;
                a.m11 = m11;

#ifdef RM_MATH_STAT
                RM_STAT_MUL(12)
                RM_STAT_SUM(8)
#endif
            }


            template<typename T>
            inline void _mul(TMatrix1x3<T> &a, const TAffineMatrix3x3<T> &b) {

                auto m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20;
                auto m01 = a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21;
                a.m00 = m00;
                a.m01 = m01;

#ifdef RM_MATH_STAT
                RM_STAT_MUL(6)
                RM_STAT_SUM(4)
#endif
            }
        }

    }
}

#endif //RMVECTORMATH_TAFFINEMATRIX3X3_FUNC_MUL_HPP
