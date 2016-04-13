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

    namespace quaternion {

        template<typename T>
        inline TQuaternion<T> mul(const TQuaternion<T> &a, const TQuaternion<T> &b) {
            TQuaternion<T> c = {
                            a.w*b.w - a.x*b.x - a.y*b.y - a.z*b.z,
                            a.x*b.w + a.w*b.x - a.z*b.y + a.y*b.z,
                            a.y*b.w + a.z*b.x + a.w*b.y - a.x*b.z,
                            a.z*b.w - a.y*b.x + a.x*b.y + a.w*b.z
                    };
#ifdef RM_MATH_STAT
            RM_STAT_MUL(16)
            RM_STAT_SUM(6)
            RM_STAT_SUB(6)
#endif
            return c;
        }

        template<typename T>
        inline TQuaternion<T> mul(const TQuaternion<T> &a, const T b) {
            TQuaternion<T> c = { a.w*b, a.x*b, a.y*b, a.z*b };
#ifdef RM_MATH_STAT
            RM_STAT_MUL(4)
#endif
            return c;
        }

        template<typename T>
        inline TQuaternion<T> mul(const T b, const TQuaternion<T> &a) {
            return mul(a,b);
        }


        template<typename T>
        inline TQuaternion<T> div(const TQuaternion<T> &a, const TQuaternion<T> &b) {
            auto invnorm = 1/(b.w*b.w + b.x*b.x + b.y*b.y + b.z*b.z);

            TQuaternion<T> c = { (a.w*b.w + a.x*b.x + a.y*b.y + a.z*b.z)*invnorm,
                                 (a.x*b.w - a.w*b.x + a.z*b.y - a.y*b.z)*invnorm,
                                 (a.y*b.w - a.z*b.x - a.w*b.y + a.x*b.z)*invnorm,
                                 (a.z*b.w + a.y*b.x - a.x*b.y - a.w*b.z)*invnorm};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(24)
            RM_STAT_DIV(1)
            RM_STAT_SUM(9)
            RM_STAT_SUB(6)
#endif
            return c;
        }


        template<typename T>
        inline TQuaternion<T> div(const TQuaternion<T> &a, const T b) {
            auto invb = 1/b;
            TQuaternion<T> c = { a.w*invb, a.x*invb, a.y*invb, a.z*invb};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(4)
            RM_STAT_DIV(1)
#endif
            return c;
        }


        template<typename T>
        inline TQuaternion<T> div(const T a, const TQuaternion<T> &b) {

            auto sinvnorm = a/(b.w*b.w + b.x*b.x + b.y*b.y + b.z*b.z);
            TQuaternion<T> c = { b.w*sinvnorm, -b.x*sinvnorm, -b.y*sinvnorm, -b.z*sinvnorm};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(8)
            RM_STAT_DIV(1)
#endif
            return c;
        }




        template<typename T>
        inline TQuaternion<T> sum(const TQuaternion<T> &a, const TQuaternion<T> &b) {
            TQuaternion<T> c = {
                    a.w + b.w, a.x + b.x, a.y + b.y, a.z + b.z
            };
#ifdef RM_MATH_STAT
            RM_STAT_SUM(4)
#endif
            return c;
        }

        template<typename T>
        inline TQuaternion<T> sum(const TQuaternion<T> &a, const T b) {
            TQuaternion<T> c = {
                    a.w + b, a.x, a.y, a.z
            };
#ifdef RM_MATH_STAT
            RM_STAT_SUM(1)
#endif
            return c;
        }


        template<typename T>
        inline TQuaternion<T> sum(const T a, const TQuaternion<T> &b) {
            return sum(b, a);
        }



        template<typename T>
        inline TQuaternion<T> sub(const TQuaternion<T> &a, const TQuaternion<T> &b) {
            TQuaternion<T> c = {
                    a.w - b.w, a.x - b.x, a.y - b.y, a.z - b.z
            };
#ifdef RM_MATH_STAT
            RM_STAT_SUB(4)
#endif
            return c;
        }


        template<typename T>
        inline TQuaternion<T> sub(const TQuaternion<T> &a, const T b) {
            TQuaternion<T> c = { a.w - b, a.x, a.y, a.z };
#ifdef RM_MATH_STAT
            RM_STAT_SUB(1)
#endif
            return c;
        }

        template<typename T>
        inline TQuaternion<T> sub(const T a, const TQuaternion<T> &b) {
            TQuaternion<T> c = { a - b.w, -b.x, -b.y, -b.z };
#ifdef RM_MATH_STAT
            RM_STAT_SUB(1)
#endif
            return c;
        }


        template<typename T>
        inline TQuaternion<T> conjugate(const TQuaternion<T> &a) {
            TQuaternion<T> c = {a.w, -a.x, -a.y, -a.z};
            return c;
        }

        template<typename T>
        inline T norm(const TQuaternion<T> &a) {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(4)
            RM_STAT_SUM(3)
#endif
            return a.w*a.w + a.x*a.x + a.y*a.y + a.z*a.z;
        }


        template<typename T>
        inline TQuaternion<T> inverse(const TQuaternion<T> &a) {
            auto invnorm = 1/norm(a);
            TQuaternion<T> c = {a.w*invnorm, -a.x*invnorm, -a.y*invnorm, -a.z*invnorm};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(4)
            RM_STAT_DIV(1)
#endif
            return c;
        }
    }
}



#endif //RMVECTORMATH_TQUATERNION_FUNC_HPP
