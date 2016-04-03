//
// Created by Vitali Kurlovich on 2/21/16.
//

#ifndef RMVECTORMATH_TAFFINEVECTOR3_OPERATOR_HPP
#define RMVECTORMATH_TAFFINEVECTOR3_OPERATOR_HPP

#include "../TAffineVector3_def.hpp"

#include "../../vector3x/TVector3_def.hpp"


namespace rmmath {

    namespace vector {

        template<typename T>
        inline bool operator == (const TAffineVector3<T> &a, const TAffineVector3<T> &b) {
            return &a == &b || (a.x == b.x && a.y == b.y);
        }

        template<typename T>
        inline bool operator != (const TAffineVector3<T> &a, const TAffineVector3<T> &b) {
            return !(a == b);
        }

        template<typename T>
        inline bool operator == (const TAffineVector3<T> &a, const TVector3<T> &b) {
            return (b.z == 1 && a.x == b.x && a.y == b.y);
        }

        template<typename T>
        inline bool operator != (const TAffineVector3<T> &a, const TVector3<T> &b) {
            return !(a == b);
        }

        template<typename T>
        inline bool operator == (const TVector3<T> &a, const TAffineVector3<T> &b) {
            return  (a.z == 1 && a.x == b.x && a.y == b.y);
        }

        template<typename T>
        inline bool operator != (const TVector3<T> &a, const TAffineVector3<T> &b) {
            return !(a == b);
        }
    }
}


#endif //RMVECTORMATH_TAFFINEVECTOR3_OPERATOR_HPP
