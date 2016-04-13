//
// Created by Vitali Kurlovich on 4/4/16.
//

#ifndef RMVECTORMATH_TQUATERNION_OPERATOR_HPP
#define RMVECTORMATH_TQUATERNION_OPERATOR_HPP


#include "../TQuaternion_def.hpp"


namespace rmmath {

    namespace quaternion {

        template<typename T>
        inline bool operator == (const TQuaternion<T> &a, const TQuaternion<T> &b) {
            return &a == &b || (a.w == b.w && a.x == b.x && a.y == b.y && a.z == b.z);
        }

        template<typename T>
        inline bool operator != (const TQuaternion<T> &a, const TQuaternion<T> &b) {
            return !(a == b);
        }
    }
}


#endif //RMVECTORMATH_TQUATERNION_OPERATOR_HPP
