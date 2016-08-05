//
// Created by Vitali Kurlovich on 4/4/16.
//

#ifndef RMVECTORMATH_TQUATERNION_OPERATOR_MUL_HPP
#define RMVECTORMATH_TQUATERNION_OPERATOR_MUL_HPP


#include "../TQuaternion_def.hpp"
#include "../func/TQuaternion_func.hpp"

namespace rmmath {

    namespace complex {

        template<typename T>
        constexpr TQuaternion<T> operator * (const TQuaternion<T> &a, const TQuaternion<T> &b) noexcept {
            return mul(a,b);
        }

        template<typename T>
        constexpr TQuaternion<T> operator * (const TQuaternion<T> &a, const T b) noexcept {
            return mul(a,b);
        }

        template<typename T>
        constexpr TQuaternion<T> operator * (const T a, const TQuaternion<T> &b) noexcept {
            return mul(a,b);
        }
    }
}




#endif //RMVECTORMATH_TQUATERNION_OPERATOR_MUL_HPP
