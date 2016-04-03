//
// Created by Vitali Kurlovich on 12/11/15.
//

#ifndef RMVECTORMATH_TVECTOR4_FUNC_HPP_H
#define RMVECTORMATH_TVECTOR4_FUNC_HPP_H

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TVector4_def.hpp"

#include <math.h>

namespace rmmath {

    namespace vector {

        template<typename T>
        inline T dot(const TVector4<T> &a, const TVector4<T> &b) {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(4)
            RM_STAT_SUM(3)
#endif
            return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
        }

        template<typename T>
        inline TVector4<T> cross(const TVector4<T> &a, const TVector4<T> &b, const TVector4<T> &c ) {
            TVector4<T> result = {
                    a.z * b.y * c.w - a.y * b.z * c.w - a.z * b.w * c.y + a.w * b.z * c.y + a.y * b.w * c.z - a.w * b.y * c.z,
                    a.x * b.z * c.w - a.z * b.x * c.w + a.z * b.w * c.x - a.w * b.z * c.x - a.x * b.w * c.z + a.w * b.x * c.z,
                    a.y * b.x * c.w - a.x * b.y * c.w - a.y * b.w * c.x + a.w * b.y * c.x + a.x * b.w * c.y - a.w * b.x * c.y,
                    a.y * b.z * c.x - a.z * b.y * c.x + a.z * b.x * c.y - a.x * b.z * c.y - a.y * b.x * c.z + a.x * b.y * c.z
            };
#ifdef RM_MATH_STAT
            RM_STAT_MUL(48)
            RM_STAT_SUM(8)
            RM_STAT_SUB(12)
#endif
            return result;
        }

        template<typename T>
        inline T norm(const TVector4<T> &a) {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(4)
            RM_STAT_SUM(3)
            RM_STAT_SQRT(1)
#endif
            return sqrt(a.x * a.x + a.y * a.y + a.z*a.z + a.w*a.w);
        }

        template<typename T>
        inline TVector4<T> normalize(const TVector4<T> &a) {
            auto invnorm = 1 / norm(a);
            TVector4<T> c = {a.x * invnorm, a.y * invnorm, a.z * invnorm, a.w * invnorm};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(4)
            RM_STAT_DIV(1)
#endif
            return c;
        }

        // mul
        template<typename T>
        inline TVector4<T> mul(const TVector4<T> &a, const TVector4<T> &b) {
            TVector4<T> c = {a.x * b.x, a.y * b.y, a.z * b.z, a.w*b.w};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(4)
#endif
            return c;
        }

        template<typename T>
        inline TVector4<T> mul(const TVector4<T> &a, const T scalar) {
            TVector4<T> c = {a.x * scalar, a.y * scalar,  a.z * scalar, a.w * scalar};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(4)
#endif
            return c;
        }

        template<typename T>
        inline TVector4<T> mul( const T scalar, const TVector4<T> &a) {
            return mul(a, scalar);
        }

        // sum

        template<typename T>
        inline TVector4<T> sum(const TVector4<T> &a, const TVector4<T> &b) {
            TVector4<T> c = {a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
#ifdef RM_MATH_STAT
            RM_STAT_SUM(4)
#endif
            return c;
        }

        template<typename T>
        inline TVector4<T> sum(const TVector4<T> &a, const T scalar) {
            TVector4<T> c = {a.x + scalar, a.y + scalar, a.z + scalar, a.w + scalar};
#ifdef RM_MATH_STAT
            RM_STAT_SUM(4)
#endif
            return c;
        }

        template<typename T>
        inline TVector4<T> sum(const T scalar, const TVector4<T> &a) {
            return sum(a, scalar);
        }


        // sub

        template<typename T>
        inline TVector4<T> sub(const TVector4<T> &a, const TVector4<T> &b) {
            TVector4<T> c = {a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};
#ifdef RM_MATH_STAT
            RM_STAT_SUB(4)
#endif
            return c;
        }

        template<typename T>
        inline TVector4<T> sub(const TVector4<T> &a, const T scalar) {
            TVector4<T> c = {a.x - scalar, a.y - scalar, a.z - scalar, a.w - scalar};
#ifdef RM_MATH_STAT
            RM_STAT_SUB(4)
#endif
            return c;
        }

        template<typename T>
        inline TVector4<T> sub(const T scalar, const TVector4<T> &a) {
            TVector4<T> c = {scalar - a.x , scalar - a.y, scalar - a.z, scalar - a.w};
#ifdef RM_MATH_STAT
            RM_STAT_SUB(4)
#endif
            return c;
        }

        // div
        template<typename T>
        inline TVector4<T> div(const TVector4<T> &a, const TVector4<T> &b) {
            TVector4<T> c = {a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w};
#ifdef RM_MATH_STAT
            RM_STAT_DIV(4)
#endif
            return c;
        }

        template<typename T>
        inline TVector4<T> div(const TVector4<T> &a, const T scalar) {
            auto invscalar = 1 / scalar;
#ifdef RM_MATH_STAT
            RM_STAT_DIV(1)
#endif
            return mul(a, invscalar);
        }

        template<typename T>
        inline TVector4<T> div(const T scalar, const TVector4<T> &a) {
            TVector4<T> c = {scalar / a.x , scalar / a.y, scalar / a.z, scalar / a.w};
#ifdef RM_MATH_STAT
            RM_STAT_DIV(4)
#endif
            return c;
        }

    }
}

#endif //RMVECTORMATH_TVECTOR4_FUNC_HPP_H
