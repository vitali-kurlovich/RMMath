//
// Created by Vitali Kurlovich on 12/11/15.
//

#ifndef RMVECTORMATH_TVECTOR3_FUNC_HPP_H
#define RMVECTORMATH_TVECTOR3_FUNC_HPP_H

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TVector3_def.hpp"

#include <math.h>

namespace rmmath {

    namespace vector {

        template<typename T>
        constexpr
        T dot(const TVector3<T> &a, const TVector3<T> &b) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(3)
            RM_STAT_SUM(2)
#endif
            return a.x * b.x + a.y * b.y + a.z * b.z;
        }

        template<typename T>
        constexpr
        TVector3<T> cross(const TVector3<T> &a, const TVector3<T> &b) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(6)
            RM_STAT_SUB(3)
#endif
            return TVector3<T>(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
        }

        template<typename T>
        constexpr T norm(const TVector3<T> &a) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(3)
            RM_STAT_SUM(2)
            RM_STAT_SQRT(1)
#endif
            return sqrt(a.x * a.x + a.y * a.y + a.z*a.z);
        }

        template<typename T>
        inline const TVector3<T> normalize(const TVector3<T> &a) {
            auto invnorm = (T)1 / norm(a);
            TVector3<T> c = {a.x * invnorm, a.y * invnorm, a.z * invnorm};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(3)
            RM_STAT_DIV(1)
#endif
            return c;
        }

        // mul
        template<typename T>
        constexpr
        TVector3<T> mul(const TVector3<T> &a, const TVector3<T> &b) noexcept {

#ifdef RM_MATH_STAT
            RM_STAT_MUL(3)
#endif
            return TVector3<T>(a.x * b.x, a.y * b.y, a.z * b.z);
        }

        template<typename T>
        constexpr
        TVector3<T> mul(const TVector3<T> &a, const T scalar) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(3)
#endif
            return TVector3<T> (a.x * scalar, a.y * scalar,  a.z * scalar);
        }

        template<typename T>
        constexpr
        TVector3<T> mul( const T scalar, const TVector3<T> &a) noexcept {
            return mul(a, scalar);
        }

        // sum

        template<typename T>
        constexpr
        TVector3<T> sum(const TVector3<T> &a, const TVector3<T> &b) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_SUM(3)
#endif
            return TVector3<T>(a.x + b.x, a.y + b.y, a.z + b.z);
        }

        template<typename T>
        constexpr
        TVector3<T> sum(const TVector3<T> &a, const T scalar) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_SUM(3)
#endif
            return TVector3<T>(a.x + scalar, a.y + scalar, a.z + scalar);
        }

        template<typename T>
        constexpr
        TVector3<T> sum(const T scalar, const TVector3<T> &a) noexcept {
            return sum(a, scalar);
        }


        // sub

        template<typename T>
        constexpr
        TVector3<T> sub(const TVector3<T> &a, const TVector3<T> &b) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_SUB(3)
#endif
            return  TVector3<T> (a.x - b.x, a.y - b.y, a.z - b.z);
        }

        template<typename T>
        constexpr
        TVector3<T> sub(const TVector3<T> &a, const T scalar) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_SUB(3)
#endif
            return TVector3<T>(a.x - scalar, a.y - scalar, a.z - scalar);
        }

        template<typename T>
        constexpr
        TVector3<T> sub(const T scalar, const TVector3<T> &a) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_SUB(3)
#endif
            return TVector3<T>(scalar - a.x , scalar - a.y, scalar - a.z);
        }


        // div

        template<typename T>
        constexpr
        TVector3<T> div(const TVector3<T> &a, const TVector3<T> &b) {
#ifdef RM_MATH_STAT
            RM_STAT_DIV(3)
#endif
            return TVector3<T>(a.x / b.x, a.y / b.y, a.z / b.z);
        }

        template<typename T>
        inline const TVector3<T> div(const TVector3<T> &a, const T scalar) {
#ifdef RM_MATH_STAT
            RM_STAT_DIV(1)
#endif
            auto invscalar = (T)1 / scalar;
            return mul(a, invscalar);
        }

        template<typename T>
        constexpr
        TVector3<T> div(const T scalar, const TVector3<T> &a) {
#ifdef RM_MATH_STAT
            RM_STAT_DIV(3)
#endif
            return TVector3<T>(scalar / a.x , scalar / a.y, scalar / a.z);;
        }

    }
}

#endif //RMVECTORMATH_TVECTOR3_FUNC_HPP_H
