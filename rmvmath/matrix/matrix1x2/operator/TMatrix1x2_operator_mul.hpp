//
// Created by Vitali Kurlovich on 1/4/16.
//

#ifndef RMVECTORMATH_TMATRIX1X2_OPERATOR_MUL_HPP
#define RMVECTORMATH_TMATRIX1X2_OPERATOR_MUL_HPP


#include "../TMatrix1x2_def.hpp"

#include "../func/TMatrix1x2_func_mul.hpp"


namespace rmmath {

    namespace matrix {

        // Mul

        template<typename T>
        inline TMatrix1x4 <T> operator * (const TMatrix1x2 <T> &a, const TMatrix2x4 <T> &b) {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix1x3 <T> operator * (const TMatrix1x2 <T> &a, const TMatrix2x3 <T> &b) {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix1x2 <T> operator * (const TMatrix1x2 <T> &a, const TMatrix2x2 <T> &b) {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix1x1 <T> operator * (const TMatrix1x2 <T> &a, const TMatrix2x1 <T> &b) {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix1x2 <T> &operator *= (TMatrix1x2 <T> &a, const TMatrix2x2 <T> &b) {
            ___unsafe::_mul(a,b);
            return a;
        }
    }
}


#endif //RMVECTORMATH_TMATRIX1X2_OPERATOR_MUL_HPP
