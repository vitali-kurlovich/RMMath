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
        inline T dot(const TAffineVector3<T> &a, const TAffineVector3<T> &b) {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(2)
            RM_STAT_SUM(2)
#endif
            return a.x * b.x + a.y * b.y + 1;
        }

        template<typename T>
        inline T dot(const TAffineVector3<T> &a, const TVector3<T> &b) {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(2)
            RM_STAT_SUM(2)
#endif
            return a.x * b.x + a.y * b.y + b.z;
        }

        template<typename T>
        inline T dot(const TVector3<T> &a, const TAffineVector3<T> &b) {
            return dot(b,a);
        }

        template<typename T>
        inline TVector3 <T> cross(const TAffineVector3 <T> &a, const TAffineVector3 <T> &b) {
            TVector3 <T> result = { a.y - b.y, b.x - a.x, a.x * b.y - a.y * b.x};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(2)
            RM_STAT_SUB(3)
#endif
            return result;
        }

        template<typename T>
        inline TVector3<T> cross(const TVector3<T> &a, const TAffineVector3<T> &b) {
            TVector3<T> result = {a.y - a.z*b.y, a.z*b.x - a.x, a.x*b.y - a.y*b.x};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(4)
            RM_STAT_SUB(3)
#endif
            return result;
        }

        template<typename T>
        inline TVector3<T> cross(const TAffineVector3<T> &a, const TVector3<T> &b) {
            TVector3<T> result = {a.y*b.z - b.y, b.x - a.x*b.z, a.x*b.y - a.y*b.x};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(4)
            RM_STAT_SUB(3)
#endif
            return result;
        }

        template<typename T>
        inline T norm(const TAffineVector3 <T> &a) {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(2)
            RM_STAT_SUM(2)
            RM_STAT_SQRT(1)
#endif
            return sqrt(a.x * a.x + a.y * a.y + 1);
        }

        template<typename T>
        inline TVector3<T> normalize(const TAffineVector3<T> &a) {
            auto invnorm = 1 / norm(a);
            TVector3<T> c = {a.x * invnorm, a.y * invnorm, invnorm};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(2)
            RM_STAT_DIV(1)
#endif
            return c;
        }


        // mul
        template<typename T>
        inline TAffineVector3<T> mul(const TAffineVector3<T> &a, const TAffineVector3<T> &b) {
            TAffineVector3<T> c = {a.x * b.x, a.y * b.y};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(2)
#endif
            return c;
        }

        template<typename T>
        inline TVector3<T> mul(const TAffineVector3<T> &a, const TVector3<T> &b) {
            TVector3<T> c = {a.x * b.x, a.y * b.y, b.z};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(2)
#endif
            return c;
        }

        template<typename T>
        inline TVector3<T> mul(const TVector3<T> &a, const TAffineVector3<T> &b) {
            return mul(b,a);
        }

        template<typename T>
        inline TVector3<T> mul(const TAffineVector3<T> &a, const T scalar) {
            TVector3<T> c = {a.x * scalar, a.y * scalar, scalar};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(2)
#endif
            return c;
        }

        template<typename T>
        inline TVector3<T> mul( const T scalar, const TAffineVector3<T> &a) {
            return mul(a, scalar);
        }

        // sum

        template<typename T>
        inline TVector3<T> sum(const TAffineVector3<T> &a, const TAffineVector3<T> &b) {
            TVector3<T> c = {a.x + b.x, a.y + b.y, 1 + 1};
#ifdef RM_MATH_STAT
            RM_STAT_SUM(2)
#endif
            return c;
        }

        template<typename T>
        inline TVector3<T> sum(const TAffineVector3<T> &a, const TVector3<T> &b) {
            TVector3<T> c = {a.x + b.x, a.y + b.y, 1 + b.z};
#ifdef RM_MATH_STAT
            RM_STAT_SUM(3)
#endif
            return c;
        }

        template<typename T>
        inline TVector3<T> sum(const TVector3<T> &a, const TAffineVector3<T> &b) {
            TVector3<T> c = {a.x + b.x, a.y + b.y, a.z + 1};
#ifdef RM_MATH_STAT
            RM_STAT_SUM(3)
#endif
            return c;
        }

        template<typename T>
        inline TVector3<T> sum(const TAffineVector3<T> &a, const T scalar) {
            TVector3<T> c = {a.x + scalar, a.y + scalar, 1 + scalar};
#ifdef RM_MATH_STAT
            RM_STAT_SUM(3)
#endif
            return c;
        }

        template<typename T>
        inline TVector3<T> sum(const T scalar, const TAffineVector3<T> &a) {
            return sum(a, scalar);
        }


        // sub

        template<typename T>
        inline TVector3<T> sub(const TAffineVector3<T> &a, const TAffineVector3<T> &b) {
            TVector3<T> c = {a.x - b.x, a.y - b.y, 0};
#ifdef RM_MATH_STAT
            RM_STAT_SUM(2)
#endif
            return c;
        }

        template<typename T>
        inline TVector3<T> sub(const TAffineVector3<T> &a, const TVector3<T> &b) {
            TVector3<T> c = {a.x - b.x, a.y - b.y, 1 - b.z};
#ifdef RM_MATH_STAT
            RM_STAT_SUM(3)
#endif
            return c;
        }

        template<typename T>
        inline TVector3<T> sub(const TVector3<T> &a, const TAffineVector3<T> &b) {
            TVector3<T> c = {a.x - b.x, a.y - b.y, a.z - 1};
#ifdef RM_MATH_STAT
            RM_STAT_SUM(3)
#endif
            return c;
        }


        template<typename T>
        inline TVector3<T> sub(const TAffineVector3<T> &a, const T scalar) {
            TVector3<T> c = {a.x - scalar, a.y - scalar, 1 - scalar};
#ifdef RM_MATH_STAT
            RM_STAT_SUB(3)
#endif
            return c;
        }

        template<typename T>
        inline TVector3<T> sub(const T scalar, const TAffineVector3<T> &a) {
            TVector3<T> c = {scalar - a.x , scalar - a.y, scalar - 1};
#ifdef RM_MATH_STAT
            RM_STAT_SUB(3)
#endif
            return c;
        }


        // Div
        template<typename T>
        inline TAffineVector3<T> div(const TAffineVector3<T> &a, const TAffineVector3<T> &b) {
            TAffineVector3<T> c = {a.x / b.x, a.y / b.y};
#ifdef RM_MATH_STAT
            RM_STAT_DIV(2)
#endif
            return c;
        }

        template<typename T>
        inline TVector3<T> div(const TAffineVector3<T> &a, const TVector3<T> &b) {
            TVector3<T> c = {a.x / b.x, a.y / b.y, 1/b.z};
#ifdef RM_MATH_STAT
            RM_STAT_DIV(3)
#endif
            return c;
        }

        template<typename T>
        inline TVector3<T> div(const TVector3<T> &a, const TAffineVector3<T> &b) {

            TVector3<T> c = {a.x / b.x, a.y / b.y, a.z};
#ifdef RM_MATH_STAT
            RM_STAT_DIV(2)
#endif
            return c;
        }

        template<typename T>
        inline TVector3<T> div(const TAffineVector3<T> &a, const T scalar) {
            T invScalar = 1/scalar;
            TVector3<T> c = {a.x * invScalar, a.y * invScalar, invScalar};
#ifdef RM_MATH_STAT
            RM_STAT_DIV(1)
            RM_STAT_MUL(2)
#endif
            return c;
        }

        template<typename T>
        inline TVector3<T> div( const T scalar, const TAffineVector3<T> &a) {

            TVector3<T> c = {scalar / a.x , scalar/a.y , scalar};
#ifdef RM_MATH_STAT
            RM_STAT_DIV(2)
#endif
            return c;
        }
    }
}

#endif //RMVECTORMATH_TAFFINEVECTOR3_FUNC_HPP
