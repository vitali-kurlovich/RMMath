//
// Created by Vitali Kurlovich on 4/9/16.
//

#ifndef RMVECTORMATH_TQUATERNION_OPERATOR_SUB_HPP
#define RMVECTORMATH_TQUATERNION_OPERATOR_SUB_HPP


#include "../TQuaternion_def.hpp"
#include "../func/TQuaternion_func.hpp"

namespace rmmath {

    namespace complex {

        template<typename T>
        inline TQuaternion<T> operator - (const TQuaternion<T> &a, const TQuaternion<T> &b) {
            return sub(a,b);
        }

        template<typename T>
        inline TQuaternion<T> operator - (const TQuaternion<T> &a, const T b) {
            return sub(a,b);
        }

        template<typename T>
        inline TQuaternion<T> operator - (const T a, const TQuaternion<T> &b) {
            return sub(a,b);
        }
    }
}



#endif //RMVECTORMATH_TQUATERNION_OPERATOR_SUB_HPP
