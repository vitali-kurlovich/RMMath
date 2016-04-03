//
// Created by Vitali Kurlovich on 1/4/16.
//

#ifndef RMVECTORMATH_TMATRIX1X4_OPERATOR_MUL_HPP
#define RMVECTORMATH_TMATRIX1X4_OPERATOR_MUL_HPP

#include "../TMatrix1x4_def.hpp"

#include "../func/TMatrix1x4_func_mul.hpp"
//#include "../func/TMatrix1x4_func_mulvec.hpp"

namespace rmmath {

    namespace matrix {

        // Mul

        template<typename T>
        inline TMatrix1x4 <T> operator * (const TMatrix1x4 <T> &a, const TMatrix4x4 <T> &b) {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix1x3 <T> operator * (const TMatrix1x4 <T> &a, const TMatrix4x3 <T> &b) {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix1x2 <T> operator * (const TMatrix1x4 <T> &a, const TMatrix4x2 <T> &b) {
            return mul(a, b);
        }

        template<typename T>
        inline TMatrix1x1 <T> operator * (const TMatrix1x4 <T> &a, const TMatrix4x1 <T> &b) {
            return mul(a, b);
        }


        template<typename T>
        inline TMatrix1x4 <T> &operator *= (TMatrix1x4 <T> &a, const TMatrix4x4 <T> &b) {
            ___unsafe::_mul(a,b);
            return a;
        }
    }
}


#endif //RMVECTORMATH_TMATRIX1X4_OPERATOR_MUL_HPP
