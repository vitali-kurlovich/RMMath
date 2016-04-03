//
// Created by Vitali Kurlovich on 12/12/15.
//

#ifndef RMVECTORMATH_TMATRIX2X2_FUNC_H
#define RMVECTORMATH_TMATRIX2X2_FUNC_H

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TMatrix2x2_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline TMatrix2x2 <T> transpose(const TMatrix2x2 <T> &a) {
            TMatrix2x2<T> result = {
                    a.m00, a.m10,
                    a.m01, a.m11,
            };
            return result;
        }


        template<typename T>
        inline T determinant(const TMatrix2x2 <T> &a) {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(2)
            RM_STAT_SUB(1)
#endif
            return a.m00 * a.m11 - a.m01 * a.m10;
        }

        template<typename T>
        TMatrix2x2 <T> inverse(const TMatrix2x2 <T> &a, bool &sucess) {
            auto det = determinant(a);
            if (det != 0) {
                sucess = true;
                auto invdet = 1 / det;

            TMatrix2x2<T> result = {
                        a.m11 * invdet, -a.m01 * invdet,
                        -a.m10 * invdet, a.m00 * invdet
                };

#ifdef RM_MATH_STAT
                RM_STAT_DIV(1)
                RM_STAT_MUL(4)
#endif
                return result;
            }
            sucess = false;
            return a;
        }

    }
}

#endif //RMVECTORMATH_TMATRIX2X2_FUNC_H
