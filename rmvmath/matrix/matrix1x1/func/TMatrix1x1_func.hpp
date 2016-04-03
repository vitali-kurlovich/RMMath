//
// Created by Vitali Kurlovich on 1/7/16.
//

#ifndef RMVECTORMATH_TMATRIX1X1_FUNC_HPP
#define RMVECTORMATH_TMATRIX1X1_FUNC_HPP

#include "../TMatrix1x1_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline TMatrix1x1 <T> transpose(const TMatrix1x1 <T> &a) {
            TMatrix1x1<T> result = {
                    a.m00
            };

            return result;
        }

        template<typename T>
        inline T determinant(const TMatrix1x1 <T> &a) {
            return a.m00;
        }

        template<typename T>
        TMatrix1x1 <T> inverse(const TMatrix1x1 <T> &a, bool &sucess) {

            if (a.m00 != 0) {
                sucess = true;

                TMatrix1x1<T> result = {
                        1/a.m00
                };
                return result;
            }
            sucess = false;
            return a;
        }

    }
}

#endif //RMVECTORMATH_TMATRIX1X1_FUNC_HPP
