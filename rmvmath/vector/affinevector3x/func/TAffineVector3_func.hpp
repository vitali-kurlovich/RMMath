//
// Created by Vitali Kurlovich on 2/21/16.
//

#ifndef RMVECTORMATH_TAFFINEVECTOR3_FUNC_HPP
#define RMVECTORMATH_TAFFINEVECTOR3_FUNC_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include <math.h>

#include "../TAffineVector3_def.hpp"

#include "../../vector3x/TVector3_def.hpp"


namespace rmmath {

    namespace vector {

        template<typename T>
        constexpr
        T dot(const TAffineVector3<T> &a, const TAffineVector3<T> &b) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(2)
            RM_STAT_SUM(2)
#endif
            return a.x * b.x + a.y * b.y + 1;
        }

        template<typename T>
        constexpr
        T dot(const TAffineVector3<T> &a, const TVector3<T> &b) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(2)
            RM_STAT_SUM(2)
#endif
            return a.x * b.x + a.y * b.y + b.z;
        }

        template<typename T>
        constexpr T dot(const TVector3<T> &a, const TAffineVector3<T> &b) noexcept {
            return dot(b,a);
        }

        template<typename T>
        constexpr
        TVector3 <T> cross(const TAffineVector3 <T> &a, const TAffineVector3 <T> &b) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(2)
            RM_STAT_SUB(3)
#endif
            return TVector3<T>(a.y - b.y, b.x - a.x, a.x * b.y - a.y * b.x);
        }

        template<typename T>
        constexpr
        TVector3<T> cross(const TVector3<T> &a, const TAffineVector3<T> &b) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(4)
            RM_STAT_SUB(3)
#endif
            return TVector3<T>(a.y - a.z*b.y, a.z*b.x - a.x, a.x*b.y - a.y*b.x);
        }

        template<typename T>
        constexpr
        TVector3<T> cross(const TAffineVector3<T> &a, const TVector3<T> &b) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(4)
            RM_STAT_SUB(3)
#endif
            return TVector3<T>(a.y*b.z - b.y, b.x - a.x*b.z, a.x*b.y - a.y*b.x);
        }

        template<typename T>
        constexpr
        T norm(const TAffineVector3 <T> &a) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(2)
            RM_STAT_SUM(2)
            RM_STAT_SQRT(1)
#endif
            return sqrt(a.x * a.x + a.y * a.y + 1);
        }

        template<typename T>
        TVector3<T> normalize(const TAffineVector3<T> &a) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(2)
            RM_STAT_DIV(1)
#endif
            auto invnorm = 1 / norm(a);
            return TVector3<T>(a.x * invnorm, a.y * invnorm, invnorm);
        }


        // mul
        template<typename T>
        constexpr
        TAffineVector3<T> mul(const TAffineVector3<T> &a, const TAffineVector3<T> &b) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(2)
#endif
            return TAffineVector3<T>(a.x * b.x, a.y * b.y);;
        }

        template<typename T>
        constexpr
        TVector3<T> mul(const TAffineVector3<T> &a, const TVector3<T> &b) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(2)
#endif
            return TVector3<T>(a.x * b.x, a.y * b.y, b.z);
        }

        template<typename T>
        constexpr
        TVector3<T> mul(const TVector3<T> &a, const TAffineVector3<T> &b) noexcept {
            return mul(b,a);
        }

        template<typename T>
        constexpr
        TVector3<T> mul(const TAffineVector3<T> &a, const T scalar) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(2)
#endif
            return  TVector3<T>(a.x * scalar, a.y * scalar, scalar);;
        }

        template<typename T>
        constexpr
        TVector3<T> mul( const T scalar, const TAffineVector3<T> &a) noexcept {
            return mul(a, scalar);
        }

        // sum

        template<typename T>
        constexpr TVector3<T> sum(const TAffineVector3<T> &a, const TAffineVector3<T> &b) noexcept {

#ifdef RM_MATH_STAT
            RM_STAT_SUM(2)
#endif
            return TVector3<T>(a.x + b.x, a.y + b.y, 1 + 1);
        }

        template<typename T>
        constexpr TVector3<T> sum(const TAffineVector3<T> &a, const TVector3<T> &b) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_SUM(3)
#endif
            return TVector3<T>(a.x + b.x, a.y + b.y, 1 + b.z);;
        }

        template<typename T>
        constexpr TVector3<T> sum(const TVector3<T> &a, const TAffineVector3<T> &b) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_SUM(3)
#endif
            return TVector3<T>(a.x + b.x, a.y + b.y, a.z + 1);
        }

        template<typename T>
        constexpr TVector3<T> sum(const TAffineVector3<T> &a, const T scalar) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_SUM(3)
#endif
            return TVector3<T>(a.x + scalar, a.y + scalar, 1 + scalar);
        }

        template<typename T>
        constexpr TVector3<T> sum(const T scalar, const TAffineVector3<T> &a) noexcept {
            return sum(a, scalar);
        }


        // sub

        template<typename T>
        constexpr TVector3<T> sub(const TAffineVector3<T> &a, const TAffineVector3<T> &b) noexcept {

#ifdef RM_MATH_STAT
            RM_STAT_SUM(2)
#endif
            return TVector3<T>(a.x - b.x, a.y - b.y, 0);
        }

        template<typename T>
        constexpr TVector3<T> sub(const TAffineVector3<T> &a, const TVector3<T> &b) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_SUM(3)
#endif
            return TVector3<T>(a.x - b.x, a.y - b.y, 1 - b.z);;
        }

        template<typename T>
        constexpr TVector3<T> sub(const TVector3<T> &a, const TAffineVector3<T> &b) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_SUM(3)
#endif
            return TVector3<T>(a.x - b.x, a.y - b.y, a.z - 1);
        }


        template<typename T>
        constexpr TVector3<T> sub(const TAffineVector3<T> &a, const T scalar) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_SUB(3)
#endif
            return TVector3<T>(a.x - scalar, a.y - scalar, 1 - scalar);
        }

        template<typename T>
        constexpr TVector3<T> sub(const T scalar, const TAffineVector3<T> &a) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_SUB(3)
#endif
            return TVector3<T>(scalar - a.x , scalar - a.y, scalar - 1);;
        }


        // Div
        template<typename T>
        constexpr TAffineVector3<T> div(const TAffineVector3<T> &a, const TAffineVector3<T> &b) {
#ifdef RM_MATH_STAT
            RM_STAT_DIV(2)
#endif
            return TAffineVector3<T>(a.x / b.x, a.y / b.y);
        }

        template<typename T>
        constexpr TVector3<T> div(const TAffineVector3<T> &a, const TVector3<T> &b) {
#ifdef RM_MATH_STAT
            RM_STAT_DIV(3)
#endif
            return TVector3<T>(a.x / b.x, a.y / b.y, 1/b.z);
        }

        template<typename T>
        constexpr TVector3<T> div(const TVector3<T> &a, const TAffineVector3<T> &b) {
#ifdef RM_MATH_STAT
            RM_STAT_DIV(2)
#endif
            return TVector3<T>(a.x / b.x, a.y / b.y, a.z);;
        }

        template<typename T>
        TVector3<T> div(const TAffineVector3<T> &a, const T scalar) {
#ifdef RM_MATH_STAT
            RM_STAT_DIV(1)
            RM_STAT_MUL(2)
#endif
            T invScalar = 1/scalar;
            return TVector3<T>(a.x * invScalar, a.y * invScalar, invScalar);
        }

        template<typename T>
        constexpr TVector3<T> div( const T scalar, const TAffineVector3<T> &a) {
#ifdef RM_MATH_STAT
            RM_STAT_DIV(2)
#endif
            return TVector3<T>(scalar / a.x , scalar/a.y , scalar);
        }
    }
}

#endif //RMVECTORMATH_TAFFINEVECTOR3_FUNC_HPP
