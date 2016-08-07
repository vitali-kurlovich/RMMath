//
// Created by Vitali Kurlovich on 1/10/16.
//

#ifndef RMVECTORMATH_TAFFINEMATRIX4X4_FUNC_HPP
#define RMVECTORMATH_TAFFINEMATRIX4X4_FUNC_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TAffineMatrix4x4_def.hpp"

#include "../../matrix4x4/TMatrix4x4_def.hpp"

#include "../../../common/common.hpp"

namespace rmmath {

    namespace matrix {

        template<typename T>
        inline const TMatrix4x4 <T> transpose(const TAffineMatrix4x4 <T> &a) noexcept {
            TMatrix4x4 <T> result (
                    a.m00, a.m10, a.m20, a.m30,
                    a.m01, a.m11, a.m21, a.m31,
                    a.m02, a.m12, a.m22, a.m32,
                    0,     0,     0,     1
            );

            return result;
        }


        template<typename T>
        const T determinant(const TAffineMatrix4x4 <T> &a) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(9)
            RM_STAT_SUM(2)
            RM_STAT_SUB(3)
#endif
            return a.m02*(a.m10*a.m21 - a.m11*a.m20) + a.m01*(a.m12*a.m20 - a.m10*a.m22) + a.m00*(a.m11*a.m22 - a.m12*a.m21);
        }
        
        template<typename T>
        const TAffineMatrix4x4 <T> inverse(const TAffineMatrix4x4 <T> &a, bool *sucess) noexcept {

            auto v3 = a.m10 * a.m21 - a.m11 * a.m20;
            auto v6 = a.m01 * a.m20 - a.m00 * a.m21;
            auto v7 = a.m00 * a.m11 - a.m01 * a.m10;

            auto det = a.m02 * v3 + a.m12 * v6 + a.m22 * v7;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(9)
            RM_STAT_SUM(2)
            RM_STAT_SUB(3)
#endif

            if (!equal_to_zero<T>(det) ) {
                *sucess = true;
                auto invdet = 1 / det;

                auto t2 = a.m02 * a.m21 - a.m01 * a.m22;
                auto t7 = a.m00 * a.m22 - a.m02 * a.m20;

                auto t5 = a.m01 * a.m12 - a.m02 * a.m11;
                auto t9 = a.m02 * a.m10 - a.m00 * a.m12;

                auto v4 = a.m12 * a.m21 - a.m11 * a.m22;
                auto v5 = a.m10 * a.m22 - a.m12 * a.m20;
                auto n3 = a.m30 * v4 + a.m31 * v5 - a.m32 * v3;

                TAffineMatrix4x4<T> result = {
                        -v4 * invdet,
                        t2 * invdet,
                        t5 * invdet,

                        -v5 * invdet,
                        t7 * invdet,
                        t9 * invdet,

                        v3 * invdet,
                        v6 * invdet,
                        v7 * invdet,

                        n3 * invdet,
                        - (a.m30 * t2 + a.m31 * t7 + a.m32 * v6) * invdet,
                        - (a.m30 * t5 + a.m31 * t9 + a.m32 * v7) * invdet
                };

#ifdef RM_MATH_STAT
                RM_STAT_MUL(33)
                RM_STAT_SUM(5)
                RM_STAT_SUB(7)
                RM_STAT_DIV(1)
#endif
                return result;
            }
            *sucess = false;
            return a;
        }
    }
}

#endif //RMVECTORMATH_TAFFINEMATRIX4X4_FUNC_HPP
