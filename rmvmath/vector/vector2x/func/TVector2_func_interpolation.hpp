//
// Created by Vitali Kurlovich on 12/11/15.
//

#ifndef RMVECTORMATH_TVECTOR2_FUNC_INTERPOLATION_HPP
#define RMVECTORMATH_TVECTOR2_FUNC_INTERPOLATION_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TVector2_def.hpp"


namespace rmmath {

    namespace vector {

        template<typename T>
        TVector2<T> lerp(const TVector2<T> &a, const TVector2<T> &b, const T phase) {
            TVector2<T> c = {
                    a.x * (1 - phase) + b.x * phase,
                    a.y * (1 - phase) + b.y * phase
            };

#ifdef RM_MATH_STAT
            RM_STAT_MUL(4)
            RM_STAT_SUM(2)
            RM_STAT_SUB(2)
#endif
            return c;
        }

        template<typename T>
        TVector2<T> lerpc(const TVector2<T> &a, const TVector2<T> &b, const T phase) {
            if (phase <= 0) {
                return a;
            }
            else if (phase >= 1) {
                return b;
            }
            TVector2<T> c = {
                    a.x * (1 - phase) + b.x * phase,
                    a.y * (1 - phase) + b.y * phase
            };

#ifdef RM_MATH_STAT
            RM_STAT_MUL(4)
            RM_STAT_SUM(2)
            RM_STAT_SUB(2)
#endif
            return c;
        }

    }
}



#endif //RMVECTORMATH_TVECTOR2_FUNC_INTERPOLATION_HPP
