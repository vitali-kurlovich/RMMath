//
// Created by Vitali Kurlovich on 12/11/15.
//

#ifndef RMVECTORMATH_TVECTOR3_OPERATOR_DIV_HPP
#define RMVECTORMATH_TVECTOR3_OPERATOR_DIV_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TVector3_def.hpp"

#include "../func/TVector3_func.hpp"

namespace rmmath {

    namespace vector {

        template<typename T>
        inline TVector3<T> operator / (const TVector3<T> &a, const TVector3<T> &b) {
            return div(a,b);
        }

        template<typename T>
        inline TVector3<T> operator / (const TVector3<T> &a, const T scalar) {
            return div(a,scalar);
        }

        template<typename T>
        inline TVector3<T> operator / (const T scalar, const TVector3<T> &a) {
            return div(scalar, a);
        }

        template<typename T>
        inline TVector3<T>& operator /= (TVector3<T> &a, const TVector3<T> &b) {
            a.x /= b.x;
            a.y /= b.y;
            a.z /= b.z;
#ifdef RM_MATH_STAT
            RM_STAT_DIV(3)
#endif
            return a;
        }

        template<typename T>
        inline TVector3<T>& operator /= (TVector3<T> &a, const T scalar) {
            auto invscalar = 1/scalar;
            a.x *= invscalar;
            a.y *= invscalar;
            a.z *= invscalar;

#ifdef RM_MATH_STAT
            RM_STAT_DIV(1)
            RM_STAT_MUL(3)
#endif
            return a;
        }
    }
}

#endif //RMVECTORMATH_TVector3_OPERATOR_DIV_HPP
