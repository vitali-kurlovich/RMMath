//
// Created by Vitali Kurlovich on 1/7/16.
//

#ifndef RMVECTORMATH_TMATRIX2X2_FUNC_MULVEC_HPP
#define RMVECTORMATH_TMATRIX2X2_FUNC_MULVEC_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif


#include "../TMatrix2x2_def.hpp"

#include "../../../vector/vector2x/TVector2_def.hpp"

namespace rmmath {

    template<typename T>
    inline vector::TVector2<T> mul(const matrix::TMatrix2x2<T> &a, const vector::TVector2<T> &b) {
        vector::TVector2<T> c;

        c.x = a.m00*b.x + a.m01*b.y;
        c.y = a.m10*b.x + a.m11*b.y;

#ifdef RM_MATH_STAT
        RM_STAT_MUL(4)
        RM_STAT_SUM(2)
#endif
        return c;
    }


    template<typename T>
    inline vector::TVector2<T> mul(const vector::TVector2<T> &b, const matrix::TMatrix2x2<T> &a) {
        vector::TVector2<T> c;

        c.x = a.m00*b.x + a.m10*b.y;
        c.y = a.m01*b.x + a.m11*b.y;

#ifdef RM_MATH_STAT
        RM_STAT_MUL(4)
        RM_STAT_SUM(2)
#endif
        return c;
    }

    namespace ___unsafe {
        template<typename T>
        inline void _mul(vector::TVector2 <T> &b, const matrix::TMatrix2x2 <T> &a) {

            auto x = a.m00*b.x + a.m10*b.y;
            auto y = a.m01*b.x + a.m11*b.y;

            b.x = x;
            b.y = y;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(4)
            RM_STAT_SUM(2)
#endif
        }
    }
}



#endif //RMVECTORMATH_TMATRIX2X2_FUNC_MULVEC_HPP
