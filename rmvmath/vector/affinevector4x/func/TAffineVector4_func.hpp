//
// Created by Vitali Kurlovich on 1/23/16.
//

#ifndef RMVECTORMATH_TAFFINEVECTOR4_FUNC_HPP
#define RMVECTORMATH_TAFFINEVECTOR4_FUNC_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include <math.h>

#include "../TAffineVector4_def.hpp"

#include "../../vector4x/TVector4_def.hpp"

namespace rmmath {

    namespace vector {

        template<typename T>
        inline T dot(const TAffineVector4 <T> &a, const TAffineVector4 <T> &b) {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(3)
            RM_STAT_SUM(3)
#endif
            return a.x * b.x + a.y * b.y + a.z * b.z + 1;
        }

        template<typename T>
        inline T dot(const TAffineVector4 <T> &a, const TVector4 <T> &b) {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(3)
            RM_STAT_SUM(3)
#endif
            return a.x * b.x + a.y * b.y + a.z * b.z + b.w;
        }

        template<typename T>
        inline T dot(const TVector4 <T> &a, const TAffineVector4 <T> &b) {
            return dot(b, a);
        }


        template<typename T>
        inline TVector4<T> cross(const TVector4<T> &a, const TVector4<T> &b, const TAffineVector4<T> &c ) {
            TVector4<T> result = { a.z * b.y - a.y * b.z - a.z * b.w * c.y + a.w * b.z * c.y + a.y * b.w * c.z - a.w * b.y * c.z,
                                   a.x * b.z - a.z * b.x + a.z * b.w * c.x - a.w * b.z * c.x - a.x * b.w * c.z + a.w * b.x * c.z,
                                   a.y * b.x - a.x * b.y - a.y * b.w * c.x + a.w * b.y * c.x + a.x * b.w * c.y - a.w * b.x * c.y,
                                   a.y * b.z * c.x - a.z * b.y * c.x + a.z * b.x * c.y - a.x * b.z * c.y - a.y * b.x * c.z + a.x * b.y * c.z};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(42)
            RM_STAT_SUM(8)
            RM_STAT_SUB(12)
#endif
            return result;
        }

        template<typename T>
        inline TVector4<T> cross(const TVector4<T> &a, const TAffineVector4<T> &b, const TVector4<T> &c ) {
            TVector4<T> result = { a.z * b.y * c.w - a.y * b.z * c.w - a.z * c.y + a.w * b.z * c.y + a.y * c.z - a.w * b.y * c.z,
                                   a.x * b.z * c.w - a.z * b.x * c.w + a.z * c.x - a.w * b.z * c.x - a.x * c.z + a.w * b.x * c.z,
                                   a.y * b.x * c.w - a.x * b.y * c.w - a.y * c.x + a.w * b.y * c.x + a.x * c.y - a.w * b.x * c.y,
                                   a.y * b.z * c.x - a.z * b.y * c.x + a.z * b.x * c.y - a.x * b.z * c.y - a.y * b.x * c.z + a.x * b.y * c.z};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(42)
            RM_STAT_SUM(8)
            RM_STAT_SUB(12)
#endif
            return result;
        }


        template<typename T>
        inline TVector4<T> cross(const TVector4<T> &a, const TAffineVector4<T> &b, const TAffineVector4<T> &c ) {
            TVector4<T> result = { a.z * b.y - a.y * b.z - a.z * c.y + a.w * b.z * c.y + a.y * c.z - a.w * b.y * c.z,
                                   a.x * b.z - a.z * b.x + a.z * c.x - a.w * b.z * c.x - a.x * c.z + a.w * b.x * c.z,
                                   a.y * b.x - a.x * b.y - a.y * c.x + a.w * b.y * c.x + a.x * c.y - a.w * b.x * c.y,
                                   a.y * b.z * c.x - a.z * b.y * c.x + a.z * b.x * c.y - a.x * b.z * c.y - a.y * b.x * c.z + a.x * b.y * c.z};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(36)
            RM_STAT_SUM(8)
            RM_STAT_SUB(12)
#endif
            return result;
        }


        template<typename T>
        inline TVector4<T> cross(const TAffineVector4<T> &a, const TVector4<T> &b, const TVector4<T> &c ) {
            TVector4<T> result = { a.z * b.y * c.w - a.y * b.z * c.w - a.z * b.w * c.y + b.z * c.y + a.y * b.w * c.z - b.y * c.z,
                                   a.x * b.z * c.w - a.z * b.x * c.w + a.z * b.w * c.x - b.z * c.x - a.x * b.w * c.z + b.x * c.z,
                                   a.y * b.x * c.w - a.x * b.y * c.w - a.y * b.w * c.x + b.y * c.x + a.x * b.w * c.y - b.x * c.y,
                                   a.y * b.z * c.x - a.z * b.y * c.x + a.z * b.x * c.y - a.x * b.z * c.y - a.y * b.x * c.z + a.x * b.y * c.z};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(42)
            RM_STAT_SUM(8)
            RM_STAT_SUB(12)
#endif
            return result;
        }

        template<typename T>
        inline TVector4<T> cross(const TAffineVector4<T> &a, const TVector4<T> &b, const TAffineVector4<T> &c ) {
            TVector4<T> result = {a.z * b.y - a.y * b.z - a.z * b.w * c.y + b.z * c.y + a.y * b.w * c.z - b.y * c.z,
                                  a.x * b.z - a.z * b.x + a.z * b.w * c.x - b.z * c.x - a.x * b.w * c.z + b.x * c.z,
                                  a.y * b.x - a.x * b.y - a.y * b.w * c.x + b.y * c.x + a.x * b.w * c.y - b.x * c.y,
                                  a.y * b.z * c.x - a.z * b.y * c.x  + a.z * b.x * c.y - a.x * b.z * c.y - a.y * b.x * c.z + a.x * b.y * c.z};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(36)
            RM_STAT_SUM(8)
            RM_STAT_SUB(12)
#endif
            return result;
        }


        template<typename T>
        inline TVector4<T> cross(const TAffineVector4<T> &a, const TAffineVector4<T> &b, const TVector4<T> &c ) {
            TVector4<T> result = { a.z * b.y * c.w - a.y * b.z * c.w - a.z * c.y + b.z * c.y + a.y * c.z - b.y * c.z,
                                   a.x * b.z * c.w -a.z * b.x * c.w + a.z * c.x - b.z * c.x - a.x * c.z + b.x * c.z,
                                   a.y * b.x * c.w - a.x * b.y * c.w - a.y * c.x + b.y * c.x + a.x * c.y - b.x * c.y,
                                   a.y * b.z * c.x - a.z * b.y * c.x + a.z * b.x * c.y - a.x * b.z * c.y - a.y * b.x * c.z + a.x * b.y * c.z};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(36)
            RM_STAT_SUM(8)
            RM_STAT_SUB(12)
#endif
            return result;
        }


        template<typename T>
        inline TVector4<T> cross(const TAffineVector4<T> &a, const TAffineVector4<T> &b, const TAffineVector4<T> &c ) {
            TVector4<T> result = {a.z * b.y - a.y * b.z - a.z * c.y + b.z * c.y + a.y * c.z - b.y * c.z,
                                  a.x * b.z - a.z * b.x + a.z * c.x - b.z * c.x - a.x * c.z + b.x * c.z,
                                  a.y * b.x - a.x * b.y - a.y * c.x + b.y * c.x + a.x * c.y - b.x * c.y,
                                  a.y * b.z * c.x - a.z * b.y * c.x + a.z * b.x * c.y - a.x * b.z * c.y - a.y * b.x * c.z + a.x * b.y * c.z};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(30)
            RM_STAT_SUM(8)
            RM_STAT_SUB(12)
#endif
            return result;

            }


        template<typename T>
        inline T norm(const TAffineVector4<T> &a) {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(3)
            RM_STAT_SUM(3)
            RM_STAT_SQRT(1)
#endif
            return sqrt(a.x * a.x + a.y * a.y + a.z*a.z + 1);
        }

        template<typename T>
        inline TVector4<T> normalize(const TAffineVector4<T> &a) {
            auto invnorm = 1 / norm(a);
            TVector4<T> c = {a.x * invnorm, a.y * invnorm, a.z * invnorm, invnorm};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(3)
            RM_STAT_DIV(1)
#endif
            return c;
        }


        // sum

        template<typename T>
        inline TVector4<T> sum(const TAffineVector4<T> &a, const TAffineVector4<T> &b) {
            TVector4<T> c = {a.x + b.x, a.y + b.y, a.z + b.z, 1 + 1};
#ifdef RM_MATH_STAT
            RM_STAT_SUM(3)
#endif
            return c;
        }

        template<typename T>
        inline TVector4<T> sum(const TAffineVector4<T> &a, const TVector4<T> &b) {
            TVector4<T> c = {a.x + b.x, a.y + b.y, a.z + b.z, 1 + b.w};
#ifdef RM_MATH_STAT
            RM_STAT_SUM(4)
#endif
            return c;
        }

        template<typename T>
        inline TVector4<T> sum(const TVector4<T> &a, const TAffineVector4<T> &b) {
            TVector4<T> c = {a.x + b.x, a.y + b.y, a.z + b.z, a.w + 1};
#ifdef RM_MATH_STAT
            RM_STAT_SUM(4)
#endif
            return c;
        }

        template<typename T>
        inline TVector4<T> sum(const TAffineVector4<T> &a, const T scalar) {
            TVector4<T> c = {a.x + scalar, a.y + scalar, a.z + scalar, 1 + scalar};
#ifdef RM_MATH_STAT
            RM_STAT_SUM(4)
#endif
            return c;
        }

        template<typename T>
        inline TVector4<T> sum(const T scalar, const TAffineVector4<T> &a) {
            return sum(a, scalar);
        }




        // sub

        template<typename T>
        inline TVector4<T> sub(const TAffineVector4<T> &a, const TAffineVector4<T> &b) {
            TVector4<T> c = {a.x - b.x, a.y - b.y, a.z - b.z, 1 - 1};
#ifdef RM_MATH_STAT
            RM_STAT_SUB(3)
#endif
            return c;
        }

        template<typename T>
        inline TVector4<T> sub(const TAffineVector4<T> &a, const TVector4<T> &b) {
            TVector4<T> c = {a.x - b.x, a.y - b.y, a.z - b.z, 1 - b.w};
#ifdef RM_MATH_STAT
            RM_STAT_SUB(4)
#endif
            return c;
        }

        template<typename T>
        inline TVector4<T> sub(const TVector4<T> &a, const TAffineVector4<T> &b) {
            TVector4<T> c = {a.x - b.x, a.y - b.y, a.z - b.z, a.w - 1};
#ifdef RM_MATH_STAT
            RM_STAT_SUB(4)
#endif
            return c;
        }

        template<typename T>
        inline TVector4<T> sub(const TAffineVector4<T> &a, const T scalar) {
            TVector4<T> c = {a.x - scalar, a.y - scalar, a.z - scalar, 1 - scalar};
#ifdef RM_MATH_STAT
            RM_STAT_SUB(4)
#endif
            return c;
        }

        template<typename T>
        inline TVector4<T> sub(const T scalar, const TAffineVector4<T> &a) {
            TVector4<T> c = {scalar - a.x, scalar - a.y, scalar - a.z, scalar - 1};
#ifdef RM_MATH_STAT
            RM_STAT_SUB(4)
#endif
            return c;

        }

        // mul
        template<typename T>
        inline TAffineVector4<T> mul(const TAffineVector4<T> &a, const TAffineVector4<T> &b) {
            TAffineVector4<T> c = {a.x * b.x, a.y * b.y, a.z * b.z};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(3)
#endif
            return c;
        }

        template<typename T>
        inline TVector4<T> mul(const TAffineVector4<T> &a, const TVector4<T> &b) {
            TVector4<T> c = {a.x * b.x, a.y * b.y, a.z * b.z, b.w};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(3)
#endif
            return c;
        }

        template<typename T>
        inline TVector4<T> mul(const TVector4<T> &a, const TAffineVector4<T> &b) {
            return mul(b,a);
        }

        template<typename T>
        inline TVector4<T> mul(const TAffineVector4<T> &a, const T scalar) {
            TVector4<T> c = {a.x * scalar, a.y * scalar,  a.z * scalar, scalar};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(3)
#endif
            return c;
        }

        template<typename T>
        inline TVector4<T> mul( const T scalar, const TAffineVector4<T> &a) {
            return mul(a, scalar);
        }


        // Div
        template<typename T>
        inline TAffineVector4<T> div(const TAffineVector4<T> &a, const TAffineVector4<T> &b) {
            TAffineVector4<T> c = {a.x / b.x, a.y / b.y, a.z / b.z};
#ifdef RM_MATH_STAT
            RM_STAT_DIV(3)
#endif
            return c;
        }

        template<typename T>
        inline TVector4<T> div(const TAffineVector4<T> &a, const TVector4<T> &b) {
            TVector4<T> c = {a.x / b.x, a.y / b.y, a.z / b.z, 1/b.w};
#ifdef RM_MATH_STAT
            RM_STAT_DIV(4)
#endif
            return c;
        }

        template<typename T>
        inline TVector4<T> div(const TVector4<T> &a, const TAffineVector4<T> &b) {

            TVector4<T> c = {a.x / b.x, a.y / b.y, a.z / b.z, a.w};
#ifdef RM_MATH_STAT
            RM_STAT_DIV(3)
#endif
            return c;
        }

        template<typename T>
        inline TVector4<T> div(const TAffineVector4<T> &a, const T scalar) {
            T invScalar = 1/scalar;
            TVector4<T> c = {a.x * invScalar, a.y * invScalar, a.z * invScalar, invScalar};
#ifdef RM_MATH_STAT
            RM_STAT_DIV(1)
            RM_STAT_MUL(3)
#endif
            return c;
        }

        template<typename T>
        inline TVector4<T> div( const T scalar, const TAffineVector4<T> &a) {

            TVector4<T> c = {scalar / a.x, scalar/a.y, scalar/a.z, scalar};
#ifdef RM_MATH_STAT
            RM_STAT_DIV(3)
#endif
            return c;
        }
    }
}

#endif //RMVECTORMATH_TAFFINEVECTOR4_FUNC_HPP
