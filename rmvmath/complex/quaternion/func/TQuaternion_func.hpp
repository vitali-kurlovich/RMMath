//
// Created by Vitali Kurlovich on 4/4/16.
//

#ifndef RMVECTORMATH_TQUATERNION_FUNC_HPP
#define RMVECTORMATH_TQUATERNION_FUNC_HPP


#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TQuaternion_def.hpp"

namespace rmmath {

    namespace complex {

        template<typename T>
        inline TQuaternion <T> mul(const TQuaternion <T> &a, const TQuaternion <T> &b) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(16)
            RM_STAT_SUM(6)
            RM_STAT_SUB(6)
#endif
            return TQuaternion<T>(a.w * b.w - a.i * b.i - a.j * b.j - a.k * b.k,
                                  a.i * b.w + a.w * b.i - a.k * b.j + a.j * b.k,
                                  a.j * b.w + a.k * b.i + a.w * b.j - a.i * b.k,
                                  a.k * b.w - a.j * b.i + a.i * b.j + a.w * b.k);
        }

        template<typename T>
        inline TQuaternion <T> mul(const TQuaternion <T> &a, const T b) noexcept {

#ifdef RM_MATH_STAT
            RM_STAT_MUL(4)
#endif
            return TQuaternion<T>(a.w * b, a.i * b, a.j * b, a.k * b);;
        }

        template<typename T>
        inline TQuaternion <T> mul(const T b, const TQuaternion <T> &a) noexcept {
            return mul(a, b);
        }


        template<typename T>
        inline TQuaternion <T> div(const TQuaternion <T> &a, const TQuaternion <T> &b) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(24)
            RM_STAT_DIV(1)
            RM_STAT_SUM(9)
            RM_STAT_SUB(6)
#endif
            auto invnorm = 1 / (b.w * b.w + b.i * b.i + b.j * b.j + b.k * b.k);
            return TQuaternion<T>((a.w * b.w + a.i * b.i + a.j * b.j + a.k * b.k) * invnorm,
                                  (a.i * b.w - a.w * b.i + a.k * b.j - a.j * b.k) * invnorm,
                                  (a.j * b.w - a.k * b.i - a.w * b.j + a.i * b.k) * invnorm,
                                  (a.k * b.w + a.j * b.i - a.i * b.j - a.w * b.k) * invnorm);
        }


        template<typename T>
        inline TQuaternion <T> div(const TQuaternion <T> &a, const T b) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(4)
            RM_STAT_DIV(1)
#endif
            auto invb = 1 / b;
            return TQuaternion<T>(a.w * invb, a.i * invb, a.j * invb, a.k * invb);
        }


        template<typename T>
        inline TQuaternion <T> div(const T a, const TQuaternion <T> &b) noexcept {

            auto sinvnorm = a / (b.w * b.w + b.i * b.i + b.j * b.j + b.k * b.k);
            TQuaternion<T> c = {b.w * sinvnorm, -b.i * sinvnorm, -b.j * sinvnorm, -b.k * sinvnorm};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(8)
            RM_STAT_DIV(1)
#endif
            return c;
        }


        template<typename T>
        inline TQuaternion <T> sum(const TQuaternion <T> &a, const TQuaternion <T> &b) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_SUM(4)
#endif
            return TQuaternion<T>(a.w + b.w, a.i + b.i, a.j + b.j, a.k + b.k);
        }

        template<typename T>
        inline TQuaternion <T> sum(const TQuaternion <T> &a, const T b) noexcept {

#ifdef RM_MATH_STAT
            RM_STAT_SUM(1)
#endif
            return TQuaternion<T>(a.w + b, a.i, a.j, a.k);
        }


        template<typename T>
        inline TQuaternion <T> sum(const T a, const TQuaternion <T> &b) noexcept {
            return sum(b, a);
        }


        template<typename T>
        inline TQuaternion <T> sub(const TQuaternion <T> &a, const TQuaternion <T> &b) noexcept {
            TQuaternion<T> c = {
                    a.w - b.w, a.i - b.i, a.j - b.j, a.k - b.k
            };
#ifdef RM_MATH_STAT
            RM_STAT_SUB(4)
#endif
            return c;
        }


        template<typename T>
        inline TQuaternion <T> sub(const TQuaternion <T> &a, const T b) noexcept {
            TQuaternion<T> c = {a.w - b, a.i, a.j, a.k};
#ifdef RM_MATH_STAT
            RM_STAT_SUB(1)
#endif
            return c;
        }

        template<typename T>
        inline TQuaternion <T> sub(const T a, const TQuaternion <T> &b) noexcept {
            TQuaternion<T> c = {a - b.w, -b.i, -b.j, -b.k};
#ifdef RM_MATH_STAT
            RM_STAT_SUB(1)
#endif
            return c;
        }

        template<typename T>
        inline TQuaternion <T> conjugate(const TQuaternion <T> &a) noexcept {
            TQuaternion<T> c = {a.w, -a.i, -a.j, -a.k};
            return c;
        }

        template<typename T>
        inline T norm(const TQuaternion <T> &a) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(4)
            RM_STAT_SUM(3)
#endif
            return a.w * a.w + a.i * a.i + a.j * a.j + a.k * a.k;
        }


        template<typename T>
        inline TQuaternion <T> inverse(const TQuaternion <T> &a) noexcept {
            auto invnorm = 1 / norm(a);
            TQuaternion<T> c{a.w * invnorm, -a.i * invnorm, -a.j * invnorm, -a.k * invnorm};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(4)
            RM_STAT_DIV(1)
#endif
            return c;
        }
    }
}


#endif //RMVECTORMATH_TQUATERNION_FUNC_HPP
