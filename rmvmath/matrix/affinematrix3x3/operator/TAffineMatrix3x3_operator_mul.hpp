//
// Created by Vitali Kurlovich on 1/13/16.
//

#ifndef RMVECTORMATH_TAFFINEMATRIX3X3_OPERATOR_MUL_HPP
#define RMVECTORMATH_TAFFINEMATRIX3X3_OPERATOR_MUL_HPP


#include "../TAffineMatrix3x3_def.hpp"

#include "../func/TAffineMatrix3x3_func_mul.hpp"
#include "../func/TAffineMatrix3x3_func_mulvec.hpp"


namespace rmmath {

    namespace matrix {

        // Mul

        template<typename T>
        inline TAffineMatrix3x3 <T> operator*(const TAffineMatrix3x3 <T> &a, const TAffineMatrix3x3 <T> &b) {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix3x4 <T> operator*(const TAffineMatrix3x3 <T> &a, const TMatrix3x4 <T> &b) {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix4x3 <T> operator*(const TMatrix4x3 <T> &a, const TAffineMatrix3x3 <T> &b) {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix3x3 <T> operator*(const TAffineMatrix3x3 <T> &a, const TMatrix3x3 <T> &b) {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix3x3 <T> operator*(const TMatrix3x3 <T> &a, const TAffineMatrix3x3 <T> &b) {
            return mul(a, b);
        }


        template<typename T>
        inline TMatrix3x2 <T> operator*(const TAffineMatrix3x3 <T> &a, const TMatrix3x2 <T> &b) {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix2x3 <T> operator*(const TMatrix2x3 <T> &a, const TAffineMatrix3x3 <T> &b) {
            return mul(a, b);
        }


        template<typename T>
        inline TMatrix3x1 <T> operator*(const TAffineMatrix3x3 <T> &a, const TMatrix3x1 <T> &b) {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix1x3 <T> operator*(const TMatrix1x3 <T> &a, const TAffineMatrix3x3 <T> &b) {
            return mul(a, b);
        }



        template<typename T>
        inline TAffineMatrix3x3 <T> &operator*=(TAffineMatrix3x3 <T> &a, const TAffineMatrix3x3 <T> &b) {
            ___unsafe::_mul(a, b);
            return a;
        }


        template<typename T>
        inline TMatrix4x3 <T> &operator*=(TMatrix4x3 <T> &a, const TAffineMatrix3x3 <T> &b) {
            ___unsafe::_mul(a, b);
            return a;
        }

        template<typename T>
        inline TMatrix3x3 <T> &operator*=(TMatrix3x3 <T> &a, const TAffineMatrix3x3 <T> &b) {
            ___unsafe::_mul(a, b);
            return a;
        }

        template<typename T>
        inline TMatrix2x3 <T> &operator*=(TMatrix2x3 <T> &a, const TAffineMatrix3x3 <T> &b) {
            ___unsafe::_mul(a, b);
            return a;
        }

        template<typename T>
        inline TMatrix1x3 <T> &operator*=(TMatrix1x3 <T> &a, const TAffineMatrix3x3 <T> &b) {
            ___unsafe::_mul(a, b);
            return a;
        }
    }

    template<typename T>
    inline vector::TVector3 <T> operator * (const matrix::TAffineMatrix3x3 <T> &a, const vector::TVector3<T> &b) {
        return mul(a, b);
    }

    template<typename T>
    inline vector::TVector3 <T> operator * (const vector::TVector3<T> &a, const matrix::TAffineMatrix3x3 <T> &b) {
        return mul(a, b);
    }

    template<typename T>
    inline vector::TVector3 <T> &operator *= (vector::TVector3 <T> &a, const matrix::TAffineMatrix3x3 <T> &b) {
        ___unsafe::_mul(a,b);
        return a;
    }



    template<typename T>
    inline vector::TVector3 <T> operator * (const matrix::TAffineMatrix3x3 <T> &a, const vector::TAffineVector3<T> &b) {
        return mul(a, b);
    }

    template<typename T>
    inline vector::TAffineVector3 <T> operator * (const vector::TAffineVector3<T> &a, const matrix::TAffineMatrix3x3 <T> &b) {
        return mul(a, b);
    }

    template<typename T>
    inline vector::TAffineVector3 <T> &operator *= (vector::TAffineVector3 <T> &a, const matrix::TAffineMatrix3x3 <T> &b) {
        ___unsafe::_mul(a,b);
        return a;
    }
}


#endif //RMVECTORMATH_TAFFINEMATRIX3X3_OPERATOR_MUL_HPP
