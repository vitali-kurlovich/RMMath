//
// Created by Vitali Kurlovich on 1/15/16.
//

#ifndef RMVECTORMATH_TAFFINEMATRIX3X3_FUNC_HPP
#define RMVECTORMATH_TAFFINEMATRIX3X3_FUNC_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TAffineMatrix3x3_def.hpp"

#include "../../matrix3x3/TMatrix3x3_def.hpp"

namespace rmmath {

    namespace matrix {

        template<typename T>
        inline TMatrix3x3 <T> transpose(const TAffineMatrix3x3 <T> &a) {
            TMatrix3x3 <T> result = {
                    a.m00, a.m10, a.m20,
                    a.m01, a.m11, a.m21,
                        0,     0,     1
            };

            return result;
        }


        template<typename T>
        T determinant(const TAffineMatrix3x3 <T> &a) {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(2)
            RM_STAT_SUB(1)
#endif
            return  a.m00*a.m11 - a.m01*a.m10;
        }


        template<typename T>
        TAffineMatrix3x3 <T> inverse(const TAffineMatrix3x3 <T> &a, bool &sucess) {

            auto det = a.m00*a.m11 - a.m01*a.m10;
#ifdef RM_MATH_STAT
            RM_STAT_MUL(2)
            RM_STAT_SUB(1)
#endif
            if (det != 0) {
                sucess = true;
                auto invdet = 1 / det;

                TAffineMatrix3x3<T> result = {
                        a.m11 * invdet,
                        -a.m01 * invdet,

                        -a.m10 * invdet,
                        a.m00 * invdet,

                        (a.m10 * a.m21 - a.m11 * a.m20) * invdet,
                        (a.m01 * a.m20 - a.m00 * a.m21) * invdet
                };

#ifdef RM_MATH_STAT
                RM_STAT_MUL(10)
                RM_STAT_SUB(2)
#endif

                return result;
            }
            sucess = false;
            return a;
        }

    }
}

#endif //RMVECTORMATH_TAFFINEMATRIX3X3_FUNC_HPP
