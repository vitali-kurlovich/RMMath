//
// Created by Vitali Kurlovich on 3/17/16.
//

#ifndef RMVECTORMATH_TAFFINEVECTOR3_OPERATOR_DIV_HPP
#define RMVECTORMATH_TAFFINEVECTOR3_OPERATOR_DIV_HPP


#include "../TAffineVector3_def.hpp"

#include "../func/TAffineVector3_func.hpp"

namespace rmmath {

    namespace vector {

        template<typename T>
        inline TAffineVector3<T> operator / (const TAffineVector3<T> &a, const TAffineVector3<T> &b) {
            return div(a, b);
        }

        template<typename T>
        inline TVector3<T> operator / (const TAffineVector3<T> &a, const TVector3<T> &b) {
            return div(a, b);
        }

        template<typename T>
        inline TVector3<T> operator / (const TVector3<T> &a, const TAffineVector3<T> &b) {
            return div(a, b);
        }

        template<typename T>
        inline TVector3<T> operator / (const TAffineVector3<T> &a, const T scalar) {
            return div(a, scalar);
        }

        template<typename T>
        inline TVector3<T> operator / (const T scalar, const TAffineVector3<T> &a) {
            return div(scalar, a);
        }
    }
}


#endif //RMVECTORMATH_TAFFINEVECTOR3_OPERATOR_DIV_HPP
