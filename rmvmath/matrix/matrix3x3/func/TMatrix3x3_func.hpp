//
// Created by Vitali Kurlovich on 12/12/15.
//

#ifndef RMVECTORMATH_TMATRIX3X3_FUNC_H
#define RMVECTORMATH_TMATRIX3X3_FUNC_H

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TMatrix3x3_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline TMatrix3x3 <T> transpose(const TMatrix3x3 <T> &a) {
            TMatrix3x3<T> result = {
                    a.m00, a.m10, a.m20,
                    a.m01, a.m11, a.m21,
                    a.m02, a.m12, a.m22,
            };

            return result;
        }


        template<typename T>
        T determinant(const TMatrix3x3 <T> &a) {
            auto v0 = a.m01 * a.m12 - a.m02 * a.m11;
            auto v1 = a.m02 * a.m10 - a.m00 * a.m12;
            auto v2 = a.m00 * a.m11 - a.m01 * a.m10;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(9)
            RM_STAT_SUM(2)
            RM_STAT_SUB(3)
#endif
            return  a.m20*v0 + a.m21*v1 + a.m22*v2;
        }


        template<typename T>
        TMatrix3x3 <T> inverse(const TMatrix3x3 <T> &a, bool &sucess) {

            auto v0 = a.m01 * a.m12 - a.m02 * a.m11;
            auto v1 = a.m02 * a.m10 - a.m00 * a.m12;
            auto v2 = a.m00 * a.m11 - a.m01 * a.m10;

            auto det = a.m20*v0 + a.m21*v1 + a.m22*v2;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(9)
            RM_STAT_SUM(2)
            RM_STAT_SUB(3)
#endif
            if (det != 0) {
                sucess = true;
                auto invdet = 1 / det;

                TMatrix3x3<T> result = {
                        (a.m11 * a.m22 - a.m12 * a.m21) * invdet,
                        (a.m02 * a.m21 - a.m01 * a.m22) * invdet,
                        v0 * invdet,

                        (a.m12 * a.m20 - a.m10 * a.m22) * invdet,
                        (a.m00 * a.m22 - a.m02 * a.m20) * invdet,
                        v1 * invdet,

                        (a.m10 * a.m21 - a.m11 * a.m20) * invdet,
                        (a.m01 * a.m20 - a.m00 * a.m21) * invdet,
                        v2 * invdet
                };

#ifdef RM_MATH_STAT
                RM_STAT_MUL(21)
                RM_STAT_SUB(6)
                RM_STAT_DIV(1)
#endif
                return result;
            }
            sucess = false;
            return a;
        }

    }
}

#endif //RMVECTORMATH_TMATRIX3X3_FUNC_H
