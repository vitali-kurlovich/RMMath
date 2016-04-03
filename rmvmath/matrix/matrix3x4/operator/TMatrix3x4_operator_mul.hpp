//
// Created by Vitali Kurlovich on 12/31/15.
//

#ifndef RMVECTORMATH_TMATRIX3X4_OPERATOR_MUL_HPP
#define RMVECTORMATH_TMATRIX3X4_OPERATOR_MUL_HPP


#include "../TMatrix3x4_def.hpp"

#include "../func/TMatrix3x4_func_mul.hpp"
#include "../func/TMatrix3x4_func_mulvec.hpp"


namespace rmmath {

    namespace matrix {


        // Mul

        template<typename T>
        inline TMatrix3x4 <T> operator * (const TMatrix3x4 <T> &a, const TMatrix4x4 <T> &b) {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix3x3 <T> operator * (const TMatrix3x4 <T> &a, const TMatrix4x3 <T> &b) {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix3x2 <T> operator * (const TMatrix3x4 <T> &a, const TMatrix4x2 <T> &b) {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix3x1 <T> operator * (const TMatrix3x4 <T> &a, const TMatrix4x1 <T> &b) {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix3x4 <T> &operator *= (TMatrix3x4 <T> &a, const TMatrix4x4 <T> &b) {
            ___unsafe::_mul(a,b);
            return a;
        }
    }

    template<typename T>
    inline vector::TVector3 <T> operator * (const matrix::TMatrix3x4 <T> &a, const vector::TVector4<T> &b) {
        return mul(a, b);
    }

    template<typename T>
    inline vector::TVector4 <T> operator * (const vector::TVector3<T> &a, const matrix::TMatrix3x4 <T> &b) {
        return mul(a, b);
    }
}

#endif //RMVECTORMATH_TMATRIX3X4_OPERATOR_MUL_HPP
