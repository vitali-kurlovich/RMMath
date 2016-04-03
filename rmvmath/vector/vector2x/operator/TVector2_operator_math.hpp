//
// Created by Vitali Kurlovich on 12/13/15.
//

#ifndef RMVECTORMATH_TVECTOR2_OPERATOR_MATH_HPP
#define RMVECTORMATH_TVECTOR2_OPERATOR_MATH_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TVector2_def.hpp"

#include "../func/TVector2_func.hpp"

namespace rmmath {

    namespace vector {

        // Sum

        template<typename T>
        inline TVector2<T> operator + (const TVector2<T> &a, const TVector2<T> &b) {
            return sum(a,b);
        }


        template<typename T>
        inline TVector2<T>& operator += (TVector2<T> &a, const TVector2<T> &b) {
            a.x += b.x;
            a.y += b.y;
#ifdef RM_MATH_STAT
            RM_STAT_SUM(2)
#endif
            return a;
        }


        // Sub

        template<typename T>
        inline TVector2<T> operator - (const TVector2<T> &a, const TVector2<T> &b) {
            return sub(a,b);
        }


        template<typename T>
        inline TVector2<T>& operator -= (TVector2<T> &a, const TVector2<T> &b) {
            a.x -= b.x;
            a.y -= b.y;
#ifdef RM_MATH_STAT
            RM_STAT_SUB(2)
#endif
            return a;
        }


        // Mul

        template<typename T>
        inline TVector2<T> operator * (const TVector2<T> &a, const TVector2<T> &b) {
            return mul(a,b);
        }


        template<typename T>
        inline TVector2<T>& operator *= (TVector2<T> &a, const TVector2<T> &b) {
            a.x *= b.x;
            a.y *= b.y;
#ifdef RM_MATH_STAT
            RM_STAT_MUL(2)
#endif
            return a;
        }


        // Div

        template<typename T>
        inline TVector2<T> operator / (const TVector2<T> &a, const TVector2<T> &b) {
            return div(a,b);
        }

        template<typename T>
        inline TVector2<T>& operator /= (TVector2<T> &a, const TVector2<T> &b) {
            a.x /= b.x;
            a.y /= b.y;
#ifdef RM_MATH_STAT
            RM_STAT_DIV(2)
#endif
            return a;
        }
    }
}

#endif //RMVECTORMATH_TVECTOR2_OPERATOR_MATH_HPP
