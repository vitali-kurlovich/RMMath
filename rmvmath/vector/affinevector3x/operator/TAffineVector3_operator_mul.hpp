//
// Created by Vitali Kurlovich on 3/17/16.
//

#ifndef RMVECTORMATH_TAFFINEVECTOR3_OPERATOR_MUL_HPP
#define RMVECTORMATH_TAFFINEVECTOR3_OPERATOR_MUL_HPP


#include "../TAffineVector3_def.hpp"

#include "../func/TAffineVector3_func.hpp"

namespace rmmath {

    namespace vector {

        template<typename T>
        constexpr TAffineVector3<T> operator * (const TAffineVector3<T> &a, const TAffineVector3<T> &b) noexcept {
            return mul(a, b);
        }

        template<typename T>
        constexpr TVector3<T> operator * (const TAffineVector3<T> &a, const TVector3<T> &b) noexcept {
            return mul(a, b);
        }

        template<typename T>
        constexpr TVector3<T> operator * (const TVector3<T> &a, const TAffineVector3<T> &b) noexcept {
            return mul(a, b);
        }

        template<typename T>
        constexpr TVector3<T> operator * (const TAffineVector3<T> &a, const T scalar) noexcept {
            return mul(a, scalar);
        }

        template<typename T>
        constexpr TVector3<T> operator * (const T scalar, const TAffineVector3<T> &a) noexcept {
            return mul(scalar, a);
        }
    }
}


#endif //RMVECTORMATH_TAFFINEVECTOR3_OPERATOR_MUL_HPP
