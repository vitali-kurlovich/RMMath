//
// Created by Vitali Kurlovich on 12/22/15.
//

#ifndef RMVECTORMATH_TMATRIX3X1_FUNC_MUL_HPP
#define RMVECTORMATH_TMATRIX3X1_FUNC_MUL_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include "../TMatrix3x1_def.hpp"

#include "../../matrix3x4/TMatrix3x4_def.hpp"
#include "../../matrix3x3/TMatrix3x3_def.hpp"
#include "../../matrix3x2/TMatrix3x2_def.hpp"
#include "../../matrix3x1/TMatrix3x1_def.hpp"

#include "../../matrix1x4/TMatrix1x4_def.hpp"
#include "../../matrix1x3/TMatrix1x3_def.hpp"
#include "../../matrix1x2/TMatrix1x2_def.hpp"
#include "../../matrix1x1/TMatrix1x1_def.hpp"

#include "../../matrix3x4/TMatrix3x4_def.hpp"
#include "../../matrix3x3/TMatrix3x3_def.hpp"
#include "../../matrix3x2/TMatrix3x2_def.hpp"
#include "../../matrix3x1/TMatrix3x1_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline TMatrix3x4 <T> mul(const TMatrix3x1 <T> &a, const TMatrix1x4 <T> &b) {
            TMatrix3x4<T> c;

            c.m00 = a.m00 * b.m00;
            c.m01 = a.m00 * b.m01;
            c.m02 = a.m00 * b.m02;
            c.m03 = a.m00 * b.m03;

            c.m10 = a.m10 * b.m00;
            c.m11 = a.m10 * b.m01;
            c.m12 = a.m10 * b.m02;
            c.m13 = a.m10 * b.m03;

            c.m20 = a.m20 * b.m00;
            c.m21 = a.m20 * b.m01;
            c.m22 = a.m20 * b.m02;
            c.m23 = a.m20 * b.m03;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(12)
#endif
            return c;
        }

        template<typename T>
        inline TMatrix3x3 <T> mul(const TMatrix3x1 <T> &a, const TMatrix1x3 <T> &b) {
            TMatrix3x3<T> c;

            c.m00 = a.m00 * b.m00;
            c.m01 = a.m00 * b.m01;
            c.m02 = a.m00 * b.m02;

            c.m10 = a.m10 * b.m00;
            c.m11 = a.m10 * b.m01;
            c.m12 = a.m10 * b.m02;

            c.m20 = a.m20 * b.m00;
            c.m21 = a.m20 * b.m01;
            c.m22 = a.m20 * b.m02;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(9)
#endif
            return c;
        }


        template<typename T>
        inline TMatrix3x2 <T> mul(const TMatrix3x1 <T> &a, const TMatrix1x2 <T> &b) {
            TMatrix3x2<T> c;

            c.m00 = a.m00 * b.m00;
            c.m01 = a.m00 * b.m01;

            c.m10 = a.m10 * b.m00;
            c.m11 = a.m10 * b.m01;

            c.m20 = a.m20 * b.m00;
            c.m21 = a.m20 * b.m01;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(6)
#endif
            return c;
        }

        template<typename T>
        inline TMatrix3x1 <T> mul(const TMatrix3x1 <T> &a, const TMatrix1x1 <T> &b) {
            TMatrix3x1<T> c;
            c.m00 = a.m00 * b.m00;
            c.m10 = a.m10 * b.m00;
            c.m20 = a.m20 * b.m00;

#ifdef RM_MATH_STAT
            RM_STAT_MUL(3)
#endif

            return c;
        }


        namespace ___unsafe {
            template<typename T>
            inline void _mul(TMatrix3x1 <T> &a, const TMatrix1x1 <T> &b) {

                a.m00 *= b.m00;
                a.m10 *= b.m00;
                a.m20 *= b.m00;

#ifdef RM_MATH_STAT
                RM_STAT_MUL(3)
#endif
            }
        }
    }
}


#endif //RMVECTORMATH_TMATRIX3X1_FUNC_MUL_HPP
