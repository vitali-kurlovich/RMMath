//
// Created by Vitali Kurlovich on 12/12/15.
//

#ifndef RMVECTORMATH_TMATRIX4X4_FUNC_H
#define RMVECTORMATH_TMATRIX4X4_FUNC_H

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TMatrix4x4_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
         const TMatrix4x4 <T> transpose(const TMatrix4x4 <T> &a) noexcept {
             TMatrix4x4<T> result (
                    a.m00, a.m10, a.m20, a.m30,
                    a.m01, a.m11, a.m21, a.m31,
                    a.m02, a.m12, a.m22, a.m32,
                    a.m03, a.m13, a.m23, a.m33
            );

            return result;
        }


        template<typename T>
        const T determinant(const TMatrix4x4 <T> &a) noexcept {

            auto v0 = a.m12 * a.m23 - a.m13 * a.m22;
            auto v1 = a.m13 * a.m21 - a.m11 * a.m23;
            auto v2 = a.m10 * a.m23 - a.m13 * a.m20;
            auto v3 = a.m10 * a.m21 - a.m11 * a.m20;
            auto v4 = a.m12 * a.m21 - a.m11 * a.m22;
            auto v5 = a.m10 * a.m22 - a.m12 * a.m20;
            auto v6 = a.m01 * a.m20 - a.m00 * a.m21;
            auto v7 = a.m00 * a.m11 - a.m01 * a.m10;

            auto n0 = a.m31 * v0 + a.m32 * v1;
            auto n1 = a.m32 * v2 - a.m30 * v0;
            auto n2 = a.m33 * v3 - (a.m30 * v1 + a.m31 * v2);
            auto n3 = a.m30 * v4 + a.m31 * v5 - a.m32 * v3;

#ifdef RM_MATH_STAT
            RM_STAT_SUM(8)
            RM_STAT_SUB(11)
            RM_STAT_MUL(33)
#endif
            return
                    a.m00 * n0 +
                    a.m01 * n1 +
                    a.m02 * n2 +
                    a.m03 * n3 +
                    a.m33 * (a.m12 * v6 + a.m22 * v7);

        }

        template<typename T>
        const TMatrix4x4 <T> inverse(const TMatrix4x4 <T> &a, bool &sucess) noexcept {

            /*
             * mul:107
             * +:23
             * -:35
             * div:1
             */

            auto v0 = a.m12 * a.m23 - a.m13 * a.m22;
            auto v1 = a.m13 * a.m21 - a.m11 * a.m23;
            auto v2 = a.m10 * a.m23 - a.m13 * a.m20;
            auto v3 = a.m10 * a.m21 - a.m11 * a.m20;
            auto v4 = a.m12 * a.m21 - a.m11 * a.m22;
            auto v5 = a.m10 * a.m22 - a.m12 * a.m20;
            auto v6 = a.m01 * a.m20 - a.m00 * a.m21;
            auto v7 = a.m00 * a.m11 - a.m01 * a.m10;

            auto n0 = a.m31 * v0 + a.m32 * v1;
            auto n1 = a.m32 * v2 - a.m30 * v0;
            auto n2 = a.m33 * v3 - (a.m30 * v1 + a.m31 * v2);
            auto n3 = a.m30 * v4 + a.m31 * v5 - a.m32 * v3;

            auto det =
                    a.m00 * n0 +
                    a.m01 * n1 +
                    a.m02 * n2 +
                    a.m03 * n3 +
                    a.m33 * (a.m12 * v6 + a.m22 * v7);
#ifdef RM_MATH_STAT
            RM_STAT_SUM(8)
            RM_STAT_SUB(11)
            RM_STAT_MUL(33)
#endif
            if (det != 0) {
                sucess = true;
                auto invdet = 1 / det;

#ifdef RM_MATH_STAT
                RM_STAT_DIV(1)
#endif

                auto t0 = a.m03 * a.m22 - a.m02 * a.m23;
                auto t1 = a.m01 * a.m23 - a.m03 * a.m21;
                auto t2 = a.m02 * a.m21 - a.m01 * a.m22;
                auto t3 = a.m02 * a.m13 - a.m03 * a.m12;
                auto t4 = a.m03 * a.m11 - a.m01 * a.m13;
                auto t5 = a.m01 * a.m12 - a.m02 * a.m11;
                auto t6 = a.m03 * a.m20 - a.m00 * a.m23;
                auto t7 = a.m00 * a.m22 - a.m02 * a.m20;
                auto t8 = a.m00 * a.m13 - a.m03 * a.m10;
                auto t9 = a.m02 * a.m10 - a.m00 * a.m12;

                TMatrix4x4<T> result = {
                        (n0 - a.m33 * v4) * invdet,
                        (a.m31 * t0 + a.m32 * t1 + a.m33 * t2) * invdet,
                        (a.m31 * t3 + a.m32 * t4 + a.m33 * t5) * invdet,
                        (a.m21 * t3 + a.m22 * t4 + a.m23 * t5) * -invdet,

                        (n1 - a.m33 * v5) * invdet,
                        (a.m32 * t6 + a.m33 * t7 - a.m30 * t0) * invdet,
                        (a.m32 * t8 + a.m33 * t9 - a.m30 * t3) * invdet,
                        (a.m20 * t3 - a.m22 * t8 - a.m23 * t9) * invdet,

                        n2 * invdet,
                        (a.m33 * v6 - a.m30 * t1 - a.m31 * t6) * invdet,
                        (a.m33 * v7 - a.m30 * t4 - a.m31 * t8) * invdet,
                        (a.m20 * t4 + a.m21 * t8 - a.m23 * v7) * invdet,

                        n3 * invdet,
                        - (a.m30 * t2 + a.m31 * t7 + a.m32 * v6) * invdet,
                        - (a.m30 * t5 + a.m31 * t9 + a.m32 * v7) * invdet,
                        (a.m20 * t5 + a.m21 * t9 + a.m22 * v7) * invdet
                };

#ifdef RM_MATH_STAT
                RM_STAT_MUL(74)
                RM_STAT_SUM(15)
                RM_STAT_SUB(24)
#endif
                return result;
            }
            sucess = false;
            return a;
        }
    }
}


#endif //RMVECTORMATH_TMATRIX4X4_FUNC_H
