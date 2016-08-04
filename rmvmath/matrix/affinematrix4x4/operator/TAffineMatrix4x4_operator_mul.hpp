//
// Created by Vitali Kurlovich on 1/10/16.
//

#ifndef RMVECTORMATH_TAFFINEMATRIX4X4_OPERATOR_MUL_HPP
#define RMVECTORMATH_TAFFINEMATRIX4X4_OPERATOR_MUL_HPP


#include "../TAffineMatrix4x4_def.hpp"

#include "../func/TAffineMatrix4x4_func_mul.hpp"
#include "../func/TAffineMatrix4x4_func_mulvec.hpp"

#include "../func/TAffineMatrix4x4_func_mulaffinevec.hpp"

namespace rmmath {

    namespace matrix {

        // Mul

        template<typename T>
        inline TAffineMatrix4x4 <T> operator*(const TAffineMatrix4x4 <T> &a, const TAffineMatrix4x4 <T> &b) noexcept {
            return mul(a, b);
        }

        template<typename T>
        inline TAffineMatrix4x4 <T> &operator *= (TAffineMatrix4x4 <T> &a, const TAffineMatrix4x4 <T> &b) noexcept {
            ___unsafe::_mul(a,b);
            return a;
        }

        template<typename T>
        inline TMatrix4x4 <T> operator*(const TAffineMatrix4x4 <T> &a, const TMatrix4x4 <T> &b) noexcept {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix4x4 <T> operator*(const TMatrix4x4 <T> &a, const TAffineMatrix4x4 <T> &b) noexcept {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix4x4 <T> &operator *= (TMatrix4x4 <T> &a, const TAffineMatrix4x4 <T> &b) noexcept {
            ___unsafe::_mul(a,b);
            return a;
        }


        template<typename T>
        inline TMatrix4x3 <T> operator*(const TAffineMatrix4x4 <T> &a, const TMatrix4x3 <T> &b) noexcept {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix3x4 <T> operator*(const TMatrix3x4 <T> &a, const TAffineMatrix4x4 <T> &b) noexcept {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix3x4 <T> &operator *= (TMatrix3x4 <T> &a, const TAffineMatrix4x4 <T> &b) noexcept {
            ___unsafe::_mul(a,b);
            return a;
        }


        template<typename T>
        inline TMatrix4x2 <T> operator*(const TAffineMatrix4x4 <T> &a, const TMatrix4x2 <T> &b) noexcept {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix2x4 <T> operator*(const TMatrix2x4 <T> &a, const TAffineMatrix4x4 <T> &b) noexcept {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix2x4 <T> &operator *= (TMatrix2x4 <T> &a, const TAffineMatrix4x4 <T> &b) noexcept {
            ___unsafe::_mul(a,b);
            return a;
        }


        template<typename T>
        inline TMatrix4x1 <T> operator*(const TAffineMatrix4x4 <T> &a, const TMatrix4x1 <T> &b) noexcept {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix1x4 <T> operator*(const TMatrix1x4 <T> &a, const TAffineMatrix4x4 <T> &b) noexcept {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix1x4 <T> &operator *= (TMatrix1x4 <T> &a, const TAffineMatrix4x4 <T> &b) noexcept {
            ___unsafe::_mul(a,b);
            return a;
        }
    }


    template<typename T>
    inline vector::TVector4 <T> operator * (const matrix::TAffineMatrix4x4 <T> &a, const vector::TVector4<T> &b) noexcept {
        return mul(a, b);
    }

    template<typename T>
    inline vector::TVector4 <T> operator * (const vector::TVector4<T> &a, const matrix::TAffineMatrix4x4 <T> &b) noexcept {
        return mul(a, b);
    }

    template<typename T>
    inline vector::TVector4 <T> &operator *= (vector::TVector4 <T> &a, const matrix::TAffineMatrix4x4 <T> &b) noexcept {
        ___unsafe::_mul(a,b);
        return a;
    }


    template<typename T>
    inline vector::TVector4 <T> operator * (const matrix::TAffineMatrix4x4 <T> &a, const vector::TAffineVector4<T> &b) noexcept {
        return mul(a, b);
    }

    template<typename T>
    inline vector::TAffineVector4 <T> operator * (const vector::TAffineVector4<T> &a, const matrix::TAffineMatrix4x4 <T> &b) noexcept {
        return mul(a, b);
    }

    template<typename T>
    inline vector::TAffineVector4 <T> &operator *= (vector::TAffineVector4 <T> &a, const matrix::TAffineMatrix4x4 <T> &b) noexcept {
        ___unsafe::_mul(a,b);
        return a;
    }

}


#endif //RMVECTORMATH_TAFFINEMATRIX4X4_OPERATOR_MUL_HPP
