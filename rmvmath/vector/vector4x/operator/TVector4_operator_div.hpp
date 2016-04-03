//
// Created by Vitali Kurlovich on 12/11/15.
//

#ifndef RMVECTORMATH_TVECTOR4_OPERATOR_DIV_HPP
#define RMVECTORMATH_TVECTOR4_OPERATOR_DIV_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TVector4_def.hpp"

#include "../func/TVector4_func.hpp"

namespace rmmath {

    namespace vector {

        template<typename T>
        inline TVector4<T> operator / (const TVector4<T> &a, const TVector4<T> &b) {
            return div(a,b);
        }

        template<typename T>
        inline TVector4<T> operator / (const TVector4<T> &a, const T scalar) {
            return div(a,scalar);
        }

        template<typename T>
        inline TVector4<T> operator / (const T scalar, const TVector4<T> &a) {
            return div(scalar, a);
        }

        template<typename T>
        inline TVector4<T>& operator /= (TVector4<T> &a, const TVector4<T> &b) {
            a.x /= b.x;
            a.y /= b.y;
            a.z /= b.z;
            a.w /= b.w;
#ifdef RM_MATH_STAT
            RM_STAT_DIV(4)
#endif
            return a;
        }

        template<typename T>
        inline TVector4<T>& operator /= (TVector4<T> &a, const T scalar) {
            auto invscalar = 1/scalar;
            a.x *= invscalar;
            a.y *= invscalar;
            a.z *= invscalar;
            a.w *= invscalar;

#ifdef RM_MATH_STAT
            RM_STAT_DIV(1)
            RM_STAT_MUL(4)
#endif
            return a;
        }
    }
}

#endif //RMVECTORMATH_TVector4_OPERATOR_DIV_HPP
