//
// Created by Vitali Kurlovich on 1/23/16.
//

#ifndef RMVECTORMATH_TAFFINEVECTOR4_OPERATOR_HPP
#define RMVECTORMATH_TAFFINEVECTOR4_OPERATOR_HPP


#include "../TAffineVector4_def.hpp"

#include "../../vector4x/TVector4_def.hpp"

namespace rmmath {

    namespace vector {

        template<typename T>
        inline bool operator == (const TAffineVector4<T> &a, const TAffineVector4<T> &b) {
            return &a == &b || (a.x == b.x && a.y == b.y && a.z == b.z);
        }

        template<typename T>
        inline bool operator != (const TAffineVector4<T> &a, const TAffineVector4<T> &b) {
            return !(a == b);
        }

        template<typename T>
        inline bool operator == (const TAffineVector4<T> &a, const TVector4<T> &b) {
            return (b.w == 1 && a.x == b.x && a.y == b.y && a.z == b.z);
        }


        template<typename T>
        inline bool operator != (const TAffineVector4<T> &a, const TVector4<T> &b) {
            return !(a == b);
        }


        template<typename T>
        inline bool operator == (const TVector4<T> &a, const TAffineVector4<T> &b) {
            return  (a.w == 1 && a.x == b.x && a.y == b.y && a.z == b.z);
        }

        template<typename T>
        inline bool operator != (const TVector4<T> &a, const TAffineVector4<T> &b) {
            return !(a == b);
        }


    }
}


#endif //RMVECTORMATH_TAFFINEVECTOR4_OPERATOR_HPP
