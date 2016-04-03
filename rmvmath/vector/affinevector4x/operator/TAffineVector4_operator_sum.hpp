//
// Created by Vitali Kurlovich on 3/17/16.
//

#ifndef RMVECTORMATH_TAFFINEVECTOR4_OPERATOR_SUM_HPP
#define RMVECTORMATH_TAFFINEVECTOR4_OPERATOR_SUM_HPP

#include "../TAffineVector4_def.hpp"

#include "../func/TAffineVector4_func.hpp"

namespace rmmath {

    namespace vector {

        template<typename T>
        inline TVector4<T> operator + (const TAffineVector4<T> &a, const TAffineVector4<T> &b) {
            return sum(a,b);
        }

        template<typename T>
        inline TVector4<T> operator + (const TVector4<T> &a, const TAffineVector4<T> &b) {
            return sum(a,b);
        }

        template<typename T>
        inline TVector4<T> operator + (const TAffineVector4<T> &a, const TVector4<T> &b) {
            return sum(a,b);
        }

        template<typename T>
        inline TVector4<T> operator + (const TAffineVector4<T> &a, const T scalar) {
            return sum(a,scalar);
        }

        template<typename T>
        inline TVector4<T> operator + (const T scalar, const TAffineVector4<T> &a) {
            return sum(scalar, a);
        }

    }
}



#endif //RMVECTORMATH_TAFFINEVECTOR4_OPERATOR_SUM_HPP
