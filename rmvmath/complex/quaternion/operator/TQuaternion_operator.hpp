//
// Created by Vitali Kurlovich on 4/4/16.
//

#ifndef RMVECTORMATH_TQUATERNION_OPERATOR_HPP
#define RMVECTORMATH_TQUATERNION_OPERATOR_HPP


#include "../TQuaternion_def.hpp"


namespace rmmath {

    namespace complex {

        template<typename T>
        inline bool operator == (const TQuaternion<T> &a, const TQuaternion<T> &b) {
            return &a == &b || (a.w == b.w && a.i == b.i && a.j == b.j && a.k == b.k);
        }

        template<typename T>
        inline bool operator != (const TQuaternion<T> &a, const TQuaternion<T> &b) {
            return !(a == b);
        }
    }
}


#endif //RMVECTORMATH_TQUATERNION_OPERATOR_HPP
