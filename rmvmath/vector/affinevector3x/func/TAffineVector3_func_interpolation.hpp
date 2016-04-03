//
// Created by Vitali Kurlovich on 3/17/16.
//

#ifndef RMVECTORMATH_TAFFINEVECTOR3_FUNC_INTERPOLATION_HPP
#define RMVECTORMATH_TAFFINEVECTOR3_FUNC_INTERPOLATION_HPP


#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include <math.h>

#include "../TAffineVector3_def.hpp"

#include "../../vector3x/TVector3_def.hpp"

namespace rmmath {

    namespace vector {

        template<typename T>
        TVector3<T> lerp(const TAffineVector3<T> &a, const TVector3<T> &b, const T phase) {
            TVector3<T> c = {
                    a.x * (1 - phase) + b.x * phase,
                    a.y * (1 - phase) + b.y * phase,
                    (1 - phase) + b.z * phase,
            };

#ifdef RM_MATH_STAT
            RM_STAT_MUL(5)
            RM_STAT_SUM(3)
            RM_STAT_SUB(3)
#endif
            return c;
        }


        template<typename T>
        TVector3<T> lerp(const TVector3<T> &a, const TAffineVector3<T> &b, const T phase) {
            TVector3<T> c = {
                    a.x * (1 - phase) + b.x * phase,
                    a.y * (1 - phase) + b.y * phase,
                    a.z * (1 - phase) + phase,
            };

#ifdef RM_MATH_STAT
            RM_STAT_MUL(5)
            RM_STAT_SUM(3)
            RM_STAT_SUB(3)
#endif
            return c;
        }

        template<typename T>
        TAffineVector3<T> lerp(const TAffineVector3<T> &a, const TAffineVector3<T> &b, const T phase) {
            TAffineVector3<T> c = {
                    a.x * (1 - phase) + b.x * phase,
                    a.y * (1 - phase) + b.y * phase,
            };

#ifdef RM_MATH_STAT
            RM_STAT_MUL(4)
            RM_STAT_SUM(2)
            RM_STAT_SUB(2)
#endif
            return c;
        }

        template<typename T>
        TAffineVector3<T> lerpc(const TAffineVector3<T> &a, const TAffineVector3<T> &b, const T phase) {
            if (phase <= 0) {
                return a;
            }
            else if (phase >= 1) {
                return b;
            }
            TAffineVector3<T> c = {
                    a.x * (1 - phase) + b.x * phase,
                    a.y * (1 - phase) + b.y * phase,
            };

#ifdef RM_MATH_STAT
            RM_STAT_MUL(4)
            RM_STAT_SUM(2)
            RM_STAT_SUB(2)
#endif
            return c;
        }


        template<typename T>
        TVector3<T> lerpc(const TAffineVector3<T> &a, const TVector3<T> &b, const T phase) {
            if (phase <= 0) {
                TVector3<T> c = {
                        a.x, a.y, 1
                };
                return c;
            }
            else if (phase >= 1) {
                return b;
            }
            TVector3<T> c = {
                    a.x * (1 - phase) + b.x * phase,
                    a.y * (1 - phase) + b.y * phase,
                    (1 - phase) + b.z * phase
            };

#ifdef RM_MATH_STAT
            RM_STAT_MUL(5)
            RM_STAT_SUM(3)
            RM_STAT_SUB(3)
#endif
            return c;
        }


        template<typename T>
        TVector3<T> lerpc(const TVector3<T> &a, const TAffineVector3<T> &b, const T phase) {
            if (phase <= 0) {
                return a;
            }
            else if (phase >= 1) {
                TVector3<T> c = {
                        b.x, b.y, 1
                };
                return c;
            }
            TVector3<T> c = {
                    a.x * (1 - phase) + b.x * phase,
                    a.y * (1 - phase) + b.y * phase,
                    a.z * (1 - phase) + phase
            };

#ifdef RM_MATH_STAT
            RM_STAT_MUL(5)
            RM_STAT_SUM(3)
            RM_STAT_SUB(3)
#endif
            return c;
        }

    }
}



#endif //RMVECTORMATH_TAFFINEVECTOR3_FUNC_INTERPOLATION_HPP
