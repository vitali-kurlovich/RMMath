//
// Created by Vitali Kurlovich on 12/11/15.
//

#ifndef RMVECTORMATH_TVECTOR4_OPERATOR_SUM_HPP
#define RMVECTORMATH_TVECTOR4_OPERATOR_SUM_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TVector4_def.hpp"

#include "../func/TVector4_func.hpp"

namespace rmmath {

    namespace vector {

        template<typename T>
        inline TVector4<T> operator + (const TVector4<T> &a, const TVector4<T> &b) {
            return sum(a,b);
        }

        template<typename T>
        inline TVector4<T> operator + (const TVector4<T> &a, const T scalar) {
            return sum(a,scalar);
        }

        template<typename T>
        inline TVector4<T> operator + (const T scalar, const TVector4<T> &a) {
            return sum(scalar, a);
        }

        template<typename T>
        inline TVector4<T>& operator += (TVector4<T> &a, const TVector4<T> &b) {
            a.x += b.x;
            a.y += b.y;
            a.z += b.z;
            a.w += b.w;
#ifdef RM_MATH_STAT
            RM_STAT_SUM(4)
#endif
            return a;
        }

        template<typename T>
        inline TVector4<T>& operator += (TVector4<T> &a, const T scalar) {
            a.x += scalar;
            a.y += scalar;
            a.z += scalar;
            a.w += scalar;

#ifdef RM_MATH_STAT
            RM_STAT_SUM(4)
#endif
            return a;
        }


    }
}

#endif //RMVECTORMATH_TVECTOR4_OPERATOR_SUM_HPP
