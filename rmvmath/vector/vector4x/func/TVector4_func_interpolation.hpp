//
// Created by Vitali Kurlovich on 12/11/15.
//

#ifndef RMVECTORMATH_TVECTOR4_FUNC_INTERPOLATION_HPP
#define RMVECTORMATH_TVECTOR4_FUNC_INTERPOLATION_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TVector4_def.hpp"

namespace rmmath {

    namespace vector {

        template<typename T>
        TVector4<T> lerp(const TVector4<T> &a, const TVector4<T> &b, const T phase) {
            TVector4<T> c = {
                    a.x * (1 - phase) + b.x * phase,
                    a.y * (1 - phase) + b.y * phase,
                    a.z * (1 - phase) + b.z * phase,
                    a.w * (1 - phase) + b.w * phase
            };
#ifdef RM_MATH_STAT
            RM_STAT_MUL(8)
            RM_STAT_SUM(4)
            RM_STAT_SUB(4)
#endif
            return c;
        }

        template<typename T>
        TVector4<T> lerpc(const TVector4<T> &a, const TVector4<T> &b, const T phase) {
            if (phase <= 0) {
                return a;
            }
            else if (phase >= 1) {
                return b;
            }
            TVector4<T> c = {
                    a.x * (1 - phase) + b.x * phase,
                    a.y * (1 - phase) + b.y * phase,
                    a.z * (1 - phase) + b.z * phase,
                    a.w * (1 - phase) + b.w * phase
            };
#ifdef RM_MATH_STAT
            RM_STAT_MUL(8)
            RM_STAT_SUM(4)
            RM_STAT_SUB(4)
#endif
            return c;
        }

    }
}



#endif //RMVECTORMATH_TVECTOR4_FUNC_INTERPOLATION_HPP
