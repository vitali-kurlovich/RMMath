//
// Created by Vitali Kurlovich on 1/4/16.
//

#ifndef RMVECTORMATH_TMATRIX2X1_OPERATOR_MUL_HPP
#define RMVECTORMATH_TMATRIX2X1_OPERATOR_MUL_HPP

#include "../TMatrix2x1_def.hpp"

#include "../func/TMatrix2x1_func_mul.hpp"
#include "../func/TMatrix2x1_func_mulvec.hpp"

namespace rmmath {

    namespace matrix {


        // Mul

        template<typename T>
        inline TMatrix2x4 <T> operator * (const TMatrix2x1 <T> &a, const TMatrix1x4 <T> &b) {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix2x3 <T> operator * (const TMatrix2x1 <T> &a, const TMatrix1x3 <T> &b) {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix2x2 <T> operator * (const TMatrix2x1 <T> &a, const TMatrix1x2 <T> &b) {
            return mul(a, b);
        }


        template<typename T>
        inline TMatrix2x1 <T> operator * (const TMatrix2x1 <T> &a, const TMatrix1x1 <T> &b) {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix2x1 <T> &operator *= (TMatrix2x1 <T> &a, const TMatrix1x1 <T> &b) {
            ___unsafe::_mul(a,b);
            return a;
        }
    }

    template<typename T>
    inline vector::TVector2 <T> operator * (const matrix::TMatrix2x1 <T> &a, T b) {
        return mul(a, b);
    }

    template<typename T>
    inline  T operator * (const vector::TVector2<T> &a, const matrix::TMatrix2x1 <T> &b) {
        return mul(a, b);
    }
}


#endif //RMVECTORMATH_TMATRIX2X1_OPERATOR_MUL_HPP
