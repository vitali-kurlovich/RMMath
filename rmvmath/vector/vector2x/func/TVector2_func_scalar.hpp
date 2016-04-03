//
// Created by Vitali Kurlovich on 12/12/15.
//

#ifndef RMVECTORMATH_TVECTOR2_FUNC_SCALAR_HPP
#define RMVECTORMATH_TVECTOR2_FUNC_SCALAR_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TVector2_def.hpp"


namespace rmmath {

    namespace vector {

        // Mul

        template<typename T>
        inline TVector2<T> mul(const TVector2 <T> &a, const T scalar) {
            TVector2<T> c = {a.x * scalar, a.y * scalar};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(2)
#endif
            return c;
        }

        template<typename T>
        inline TVector2<T> mul(const T scalar, const TVector2 <T> &a) {
            return mul(a, scalar);
        }

        // Sum

        template<typename T>
        inline TVector2<T> sum(const TVector2<T> &a, const T scalar) {
            TVector2<T> c = {a.x + scalar, a.y + scalar};
#ifdef RM_MATH_STAT
            RM_STAT_SUM(2)
#endif
            return c;
        }

        template<typename T>
        inline TVector2<T> sum(const T scalar, const TVector2<T> &a) {
            return sum(a, scalar);
        }


        // Sub

        template<typename T>
        inline TVector2<T> sub(const TVector2<T> &a, const T scalar) {
            TVector2<T> c = {a.x - scalar, a.y - scalar};
#ifdef RM_MATH_STAT
            RM_STAT_SUB(2)
#endif
            return c;
        }

        template<typename T>
        inline TVector2<T> sub(const T scalar, const TVector2<T> &a) {
            TVector2<T> c = {scalar - a.x , scalar - a.y};
#ifdef RM_MATH_STAT
            RM_STAT_SUB(2)
#endif
            return c;
        }

        // Div

        template<typename T>
        inline TVector2<T> div(const TVector2<T> &a, const T scalar) {
            auto invscalar = 1 / scalar;
#ifdef RM_MATH_STAT
            RM_STAT_DIV(1)
#endif
            return mul(a, invscalar);
        }

        template<typename T>
        inline TVector2<T> div(const T scalar, const TVector2<T> &a) {
            TVector2<T> c = {scalar / a.x , scalar / a.y};
#ifdef RM_MATH_STAT
            RM_STAT_DIV(2)
#endif
            return c;
        }

    }
}


#endif //RMVECTORMATH_TVECTOR2_FUNC_SCALAR_HPP
