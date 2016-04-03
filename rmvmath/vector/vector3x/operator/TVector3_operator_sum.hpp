//
// Created by Vitali Kurlovich on 12/11/15.
//

#ifndef RMVECTORMATH_TVECTOR3_OPERATOR_SUM_HPP
#define RMVECTORMATH_TVECTOR3_OPERATOR_SUM_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TVector3_def.hpp"

#include "../func/TVector3_func.hpp"

namespace rmmath {

    namespace vector {

        template<typename T>
        inline TVector3<T> operator + (const TVector3<T> &a, const TVector3<T> &b) {
            return sum(a,b);
        }

        template<typename T>
        inline TVector3<T> operator + (const TVector3<T> &a, const T scalar) {
            return sum(a,scalar);
        }

        template<typename T>
        inline TVector3<T> operator + (const T scalar, const TVector3<T> &a) {
            return sum(scalar, a);
        }

        template<typename T>
        inline TVector3<T>& operator += (TVector3<T> &a, const TVector3<T> &b) {
            a.x += b.x;
            a.y += b.y;
            a.z += b.z;
#ifdef RM_MATH_STAT
            RM_STAT_SUM(3)
#endif
            return a;
        }

        template<typename T>
        inline TVector3<T>& operator += (TVector3<T> &a, const T scalar) {
            a.x += scalar;
            a.y += scalar;
            a.z += scalar;
#ifdef RM_MATH_STAT
            RM_STAT_SUM(3)
#endif
            return a;
        }


    }
}

#endif //RMVECTORMATH_TVECTOR3_OPERATOR_SUM_HPP
