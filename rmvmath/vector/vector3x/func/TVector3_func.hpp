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
        inline T dot(const TVector3<T> &a, const TVector3<T> &b) {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(3)
            RM_STAT_SUM(2)
#endif
            return a.x * b.x + a.y * b.y + a.z * b.z;
        }

        template<typename T>
        inline TVector3<T> cross(const TVector3<T> &a, const TVector3<T> &b) {
            TVector3<T> result = {a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(6)
            RM_STAT_SUB(3)
#endif
            return result;
        }

        template<typename T>
        inline T norm(const TVector3<T> &a) {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(3)
            RM_STAT_SUM(2)
            RM_STAT_SQRT(1)
#endif
            return sqrt(a.x * a.x + a.y * a.y + a.z*a.z);
        }

        template<typename T>
        inline TVector3<T> normalize(const TVector3<T> &a) {
            auto invnorm = 1 / norm(a);
            TVector3<T> c = {a.x * invnorm, a.y * invnorm, a.z * invnorm};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(3)
            RM_STAT_DIV(1)
#endif
            return c;
        }

        // mul
        template<typename T>
        inline TVector3<T> mul(const TVector3<T> &a, const TVector3<T> &b) {
            TVector3<T> c = {a.x * b.x, a.y * b.y, a.z * b.z};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(3)
#endif
            return c;
        }

        template<typename T>
        inline TVector3<T> mul(const TVector3<T> &a, const T scalar) {
            TVector3<T> c = {a.x * scalar, a.y * scalar,  a.z * scalar};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(3)
#endif
            return c;
        }

        template<typename T>
        inline TVector3<T> mul( const T scalar, const TVector3<T> &a) {
            return mul(a, scalar);
        }

        // sum

        template<typename T>
        inline TVector3<T> sum(const TVector3<T> &a, const TVector3<T> &b) {
            TVector3<T> c = {a.x + b.x, a.y + b.y, a.z + b.z};
#ifdef RM_MATH_STAT
            RM_STAT_SUM(3)
#endif
            return c;
        }

        template<typename T>
        inline TVector3<T> sum(const TVector3<T> &a, const T scalar) {
            TVector3<T> c = {a.x + scalar, a.y + scalar, a.z + scalar};
#ifdef RM_MATH_STAT
            RM_STAT_SUM(3)
#endif
            return c;
        }

        template<typename T>
        inline TVector3<T> sum(const T scalar, const TVector3<T> &a) {
            return sum(a, scalar);
        }


        // sub

        template<typename T>
        inline TVector3<T> sub(const TVector3<T> &a, const TVector3<T> &b) {
            TVector3<T> c = {a.x - b.x, a.y - b.y, a.z - b.z};
#ifdef RM_MATH_STAT
            RM_STAT_SUB(3)
#endif
            return c;
        }

        template<typename T>
        inline TVector3<T> sub(const TVector3<T> &a, const T scalar) {
            TVector3<T> c = {a.x - scalar, a.y - scalar, a.z - scalar};
#ifdef RM_MATH_STAT
            RM_STAT_SUB(3)
#endif
            return c;
        }

        template<typename T>
        inline TVector3<T> sub(const T scalar, const TVector3<T> &a) {
            TVector3<T> c = {scalar - a.x , scalar - a.y, scalar - a.z};
#ifdef RM_MATH_STAT
            RM_STAT_SUB(3)
#endif
            return c;
        }


        // div

        template<typename T>
        inline TVector3<T> div(const TVector3<T> &a, const TVector3<T> &b) {
            TVector3<T> c = {a.x / b.x, a.y / b.y, a.z / b.z};
#ifdef RM_MATH_STAT
            RM_STAT_DIV(3)
#endif
            return c;
        }

        template<typename T>
        inline TVector3<T> div(const TVector3<T> &a, const T scalar) {
            auto invscalar = 1 / scalar;
#ifdef RM_MATH_STAT
            RM_STAT_DIV(1)
#endif
            return mul(a, invscalar);
        }

        template<typename T>
        inline TVector3<T> div(const T scalar, const TVector3<T> &a) {
            TVector3<T> c = {scalar / a.x , scalar / a.y, scalar / a.z};
#ifdef RM_MATH_STAT
            RM_STAT_DIV(3)
#endif
            return c;
        }

    }
}

#endif //RMVECTORMATH_TVECTOR3_FUNC_HPP_H
