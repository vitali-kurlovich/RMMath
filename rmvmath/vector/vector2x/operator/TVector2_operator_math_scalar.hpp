//
// Created by Vitali Kurlovich on 12/13/15.
//

#ifndef RMVECTORMATH_TVECTOR2_OPERATOR_SCALAR_H
#define RMVECTORMATH_TVECTOR2_OPERATOR_SCALAR_H

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TVector2_def.hpp"

#include "../func/TVector2_func_scalar.hpp"

namespace rmmath {

    namespace vector {


        // Mul
        template<typename T>
        inline TVector2<T> operator * (const TVector2<T> &a, const T scalar) {
            return mul(a,scalar);
        }

        template<typename T>
        inline TVector2<T> operator * (const T scalar, const TVector2<T> &a) {
            return mul(scalar, a);
        }

        template<typename T>
        inline TVector2<T>& operator *= (TVector2<T> &a, const T scalar) {
            a.x *= scalar;
            a.y *= scalar;
#ifdef RM_MATH_STAT
            RM_STAT_MUL(2)
#endif
            return a;
        }


        // Sum

        template<typename T>
        inline TVector2<T> operator + (const TVector2<T> &a, const T scalar) {
            return sum(a,scalar);
        }

        template<typename T>
        inline TVector2<T> operator + (const T scalar, const TVector2<T> &a) {
            return sum(scalar, a);
        }

        template<typename T>
        inline TVector2<T>& operator += (TVector2<T> &a, const T scalar) {
            a.x += scalar;
            a.y += scalar;
#ifdef RM_MATH_STAT
            RM_STAT_SUM(2)
#endif
            return a;
        }

        // Sub

        template<typename T>
        inline TVector2<T> operator - (const TVector2<T> &a, const T scalar) {
            return sub(a,scalar);
        }

        template<typename T>
        inline TVector2<T> operator - (const T scalar, const TVector2<T> &a) {
            return sub(scalar, a);
        }


        template<typename T>
        inline TVector2<T>& operator -= (TVector2<T> &a, const T scalar) {
            a.x -= scalar;
            a.y -= scalar;
#ifdef RM_MATH_STAT
            RM_STAT_SUB(2)
#endif
            return a;
        }

        // Div

        template<typename T>
        inline TVector2<T> operator / (const TVector2<T> &a, const T scalar) {
            return div(a,scalar);
        }

        template<typename T>
        inline TVector2<T> operator / (const T scalar, const TVector2<T> &a) {
            return div(scalar, a);
        }

        template<typename T>
        inline TVector2<T>& operator /= (TVector2<T> &a, const T scalar) {
            auto invscalar = 1/scalar;
            a.x *= invscalar;
            a.y *= invscalar;
#ifdef RM_MATH_STAT
            RM_STAT_MUL(2)
            RM_STAT_DIV(1)
#endif
            return a;
        }
    }
}


#endif //RMVECTORMATH_TVECTOR2_OPERATOR_SCALAR_H
