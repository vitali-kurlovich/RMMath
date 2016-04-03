//
// Created by Vitali Kurlovich on 12/23/15.
//

#ifndef RMVECTORMATH_TMATRIX2X1_FUNC_MUL_HPP
#define RMVECTORMATH_TMATRIX2X1_FUNC_MUL_HPP


#include "../TMatrix2x1_def.hpp"

#include "../../matrix2x4/TMatrix2x4_def.hpp"
#include "../../matrix2x3/TMatrix2x3_def.hpp"
#include "../../matrix2x2/TMatrix2x2_def.hpp"
#include "../../matrix2x1/TMatrix2x1_def.hpp"

#include "../../matrix1x4/TMatrix1x4_def.hpp"
#include "../../matrix1x3/TMatrix1x3_def.hpp"
#include "../../matrix1x2/TMatrix1x2_def.hpp"
#include "../../matrix1x1/TMatrix1x1_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline TMatrix2x4 <T> mul(const TMatrix2x1 <T> &a, const TMatrix1x4 <T> &b) {
            TMatrix2x4<T> c;

            c.m00 = a.m00 * b.m00;
            c.m01 = a.m00 * b.m01;
            c.m02 = a.m00 * b.m02;
            c.m03 = a.m00 * b.m03;

            c.m10 = a.m10 * b.m00;
            c.m11 = a.m10 * b.m01;
            c.m12 = a.m10 * b.m02;
            c.m13 = a.m10 * b.m03;

            return c;
        }

        template<typename T>
        inline TMatrix2x3 <T> mul(const TMatrix2x1 <T> &a, const TMatrix1x3 <T> &b) {
            TMatrix2x3<T> c;

            c.m00 = a.m00 * b.m00;
            c.m01 = a.m00 * b.m01;
            c.m02 = a.m00 * b.m02;

            c.m10 = a.m10 * b.m00;
            c.m11 = a.m10 * b.m01;
            c.m12 = a.m10 * b.m02;

            return c;
        }


        template<typename T>
        inline TMatrix2x2 <T> mul(const TMatrix2x1 <T> &a, const TMatrix1x2 <T> &b) {
            TMatrix2x2<T> c;

            c.m00 = a.m00 * b.m00;
            c.m01 = a.m00 * b.m01;

            c.m10 = a.m10 * b.m00;
            c.m11 = a.m10 * b.m01;

            return c;
        }

        template<typename T>
        inline TMatrix2x1 <T> mul(const TMatrix2x1 <T> &a, const TMatrix1x1 <T> &b) {
            TMatrix2x1<T> c;
            c.m00 = a.m00 * b.m00;
            c.m10 = a.m10 * b.m00;
            return c;
        }

        namespace ___unsafe {
            template<typename T>
            inline void _mul(TMatrix2x1 <T> &a, const TMatrix1x1 <T> &b) {
                a.m00 *= b.m00;
                a.m10 *= b.m00;
            }
        }

    }
}

#endif //RMVECTORMATH_TMATRIX2X1_FUNC_MUL_HPP
