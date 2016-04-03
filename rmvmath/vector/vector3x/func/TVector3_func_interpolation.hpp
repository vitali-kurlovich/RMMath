//
// Created by Vitali Kurlovich on 12/11/15.
//

#ifndef RMVECTORMATH_TVECTOR3_FUNC_INTERPOLATION_HPP
#define RMVECTORMATH_TVECTOR3_FUNC_INTERPOLATION_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TVector3_def.hpp"


namespace rmmath {

    namespace vector {

        template<typename T>
        TVector3<T> lerp(const TVector3<T> &a, const TVector3<T> &b, const T phase) {
            TVector3<T> c = {
                    a.x * (1 - phase) + b.x * phase,
                    a.y * (1 - phase) + b.y * phase,
                    a.z * (1 - phase) + b.z * phase,
            };

#ifdef RM_MATH_STAT
            RM_STAT_MUL(6)
            RM_STAT_SUM(3)
            RM_STAT_SUB(3)
#endif
            return c;
        }

        template<typename T>
        TVector3<T> lerpc(const TVector3<T> &a, const TVector3<T> &b, const T phase) {
            if (phase <= 0) {
                return a;
            }
            else if (phase >= 1) {
                return b;
            }
            TVector3<T> c = {
                    a.x * (1 - phase) + b.x * phase,
                    a.y * (1 - phase) + b.y * phase,
                    a.z * (1 - phase) + b.z * phase
            };

#ifdef RM_MATH_STAT
            RM_STAT_MUL(6)
            RM_STAT_SUM(3)
            RM_STAT_SUB(3)
#endif
            return c;
        }

    }
}



#endif //RMVECTORMATH_TVECTOR3_FUNC_INTERPOLATION_HPP
