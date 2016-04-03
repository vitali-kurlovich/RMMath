//
// Created by Vitali Kurlovich on 12/31/15.
//

#ifndef RMVECTORMATH_TMATRIX4X3_OPERATOR_MUL_HPP
#define RMVECTORMATH_TMATRIX4X3_OPERATOR_MUL_HPP


#include "../TMatrix4x3_def.hpp"

#include "../func/TMatrix4x3_func_mul.hpp"
#include "../func/TMatrix4x3_func_mulvec.hpp"


namespace rmmath {

    namespace matrix {


        // Mul

        template<typename T>
        inline TMatrix4x4 <T> operator * (const TMatrix4x3 <T> &a, const TMatrix3x4 <T> &b) {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix4x3 <T> operator * (const TMatrix4x3 <T> &a, const TMatrix3x3 <T> &b) {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix4x2 <T> operator * (const TMatrix4x3 <T> &a, const TMatrix3x2 <T> &b) {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix4x1 <T> operator * (const TMatrix4x3 <T> &a, const TMatrix3x1 <T> &b) {
            return mul(a, b);
        }


        template<typename T>
        inline TMatrix4x3 <T> &operator *= (TMatrix4x3 <T> &a, const TMatrix3x3 <T> &b) {
            ___unsafe::_mul(a,b);
            return a;
        }

    }

    template<typename T>
    inline vector::TVector4 <T> operator * (const matrix::TMatrix4x3 <T> &a, const vector::TVector3<T> &b) {
        return mul(a, b);
    }

    template<typename T>
    inline vector::TVector3 <T> operator * (const vector::TVector4<T> &a, const matrix::TMatrix4x3 <T> &b) {
        return mul(a, b);
    }

}

#endif //RMVECTORMATH_TMATRIX4X3_OPERATOR_MUL_HPP
