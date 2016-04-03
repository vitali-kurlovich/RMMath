//
// Created by Vitali Kurlovich on 12/11/15.
//

#ifndef RMVECTORMATH_TVECTOR2_FUNC_HPP_H
#define RMVECTORMATH_TVECTOR2_FUNC_HPP_H

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TVector2_def.hpp"

#include <math.h>

namespace rmmath {

    namespace vector {


        template<typename T>
        inline T dot(const TVector2<T> &a, const TVector2<T> &b) {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(2)
            RM_STAT_SUM(1)
#endif
            return a.x * b.x + a.y * b.y;
        }

        template<typename T>
        inline TVector2<T> cross(const TVector2<T> &a) {
            TVector2<T> result = {-a.y, a.x};
            return result;
        }

        template<typename T>
        inline T norm(const TVector2<T> &a) {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(2)
            RM_STAT_SUM(1)
            RM_STAT_SQRT(1)
#endif
            return sqrt(a.x * a.x + a.y * a.y);
        }



        template<typename T>
        inline TVector2<T> normalize(const TVector2<T> &a) {
            auto invnorm = 1 / norm(a);
            TVector2<T> c = {a.x * invnorm, a.y * invnorm};

#ifdef RM_MATH_STAT
            RM_STAT_MUL(2)
            RM_STAT_DIV(1)
#endif
            return c;
        }

        // mul
        template<typename T>
        inline TVector2<T> mul(const TVector2<T> &a, const TVector2<T> &b) {
            TVector2<T> c = {a.x * b.x, a.y * b.y};
#ifdef RM_MATH_STAT
            RM_STAT_MUL(2)
#endif
            return c;
        }


        // sum

        template<typename T>
        inline TVector2<T> sum(const TVector2<T> &a, const TVector2<T> &b) {
            TVector2<T> c = {a.x + b.x, a.y + b.y};
#ifdef RM_MATH_STAT
            RM_STAT_SUM(2)
#endif
            return c;
        }


        // sub

        template<typename T>
        inline TVector2<T> sub(const TVector2<T> &a, const TVector2<T> &b) {
            TVector2<T> c = {a.x - b.x, a.y - b.y};
#ifdef RM_MATH_STAT
            RM_STAT_SUB(2)
#endif
            return c;
        }



        // div

        template<typename T>
        inline TVector2<T> div(const TVector2<T> &a, const TVector2<T> &b) {
            TVector2<T> c = {a.x / b.x, a.y / b.y};
#ifdef RM_MATH_STAT
            RM_STAT_DIV(2)
#endif
            return c;
        }



    }
}



#endif //RMVECTORMATH_TVECTOR2_FUNC_HPP_H
