//
// Created by Vitali Kurlovich on 4/4/16.
//

#ifndef RMVECTORMATH_TQUATERNION_OPERATOR_MUL_HPP
#define RMVECTORMATH_TQUATERNION_OPERATOR_MUL_HPP


#include "../TQuaternion_def.hpp"
#include "../func/TQuaternion_func.hpp"

namespace rmmath {

    namespace quaternion {

        template<typename T>
        inline TQuaternion<T> operator * (const TQuaternion<T> &a, const TQuaternion<T> &b) {
            return mul(a,b);
        }

        template<typename T>
        inline TQuaternion<T> operator * (const TQuaternion<T> &a, const T b) {
            return mul(a,b);
        }

        template<typename T>
        inline TQuaternion<T> operator * (const T a, const TQuaternion<T> &b) {
            return mul(a,b);
        }
    }
}




#endif //RMVECTORMATH_TQUATERNION_OPERATOR_MUL_HPP
