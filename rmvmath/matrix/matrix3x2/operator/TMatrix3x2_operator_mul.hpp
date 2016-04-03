//
// Created by Vitali Kurlovich on 12/31/15.
//

#ifndef RMVECTORMATH_TMATRIX3X2_OPERATOR_MUL_HPP
#define RMVECTORMATH_TMATRIX3X2_OPERATOR_MUL_HPP

#include "../TMatrix3x2_def.hpp"

#include "../func/TMatrix3x2_func_mul.hpp"
#include "../func/TMatrix3x2_func_mulvec.hpp"


namespace rmmath {

    namespace matrix {

        // Mul


        template<typename T>
        inline TMatrix3x4 <T> operator * (const TMatrix3x2 <T> &a, const TMatrix2x4 <T> &b) {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix3x3 <T> operator * (const TMatrix3x2 <T> &a, const TMatrix2x3 <T> &b) {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix3x2 <T> operator * (const TMatrix3x2 <T> &a, const TMatrix2x2 <T> &b) {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix3x1 <T> operator * (const TMatrix3x2 <T> &a, const TMatrix2x1 <T> &b) {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix3x2 <T> &operator *= (TMatrix3x2 <T> &a, const TMatrix2x2 <T> &b) {
            ___unsafe::_mul(a,b);
            return a;
        }
    }

    template<typename T>
    inline vector::TVector3 <T> operator * (const matrix::TMatrix3x2 <T> &a, const vector::TVector2<T> &b) {
        return mul(a, b);
    }

    template<typename T>
    inline vector::TVector2 <T> operator * (const vector::TVector3<T> &a, const matrix::TMatrix3x2 <T> &b) {
        return mul(a, b);
    }
}

#endif //RMVECTORMATH_TMATRIX3X2_OPERATOR_MUL_HPP
