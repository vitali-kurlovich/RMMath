//
// Created by Vitali Kurlovich on 1/10/16.
//

#ifndef RMVECTORMATH_TAFFINEMATRIX4X4_OPERATOR_HPP
#define RMVECTORMATH_TAFFINEMATRIX4X4_OPERATOR_HPP


#include "../TAffineMatrix4x4_def.hpp"

#include "../../matrix4x4/TMatrix4x4_def.hpp"

namespace rmmath {

    namespace matrix {

        template<typename T>
        inline bool operator == (const TAffineMatrix4x4 <T> &a, const TAffineMatrix4x4 <T> &b) {
            return &a == &b ||
                   (a.m00 == b.m00 &&
                    a.m01 == b.m01 &&
                    a.m02 == b.m02 &&

                    a.m10 == b.m10 &&
                    a.m11 == b.m11 &&
                    a.m12 == b.m12 &&

                    a.m20 == b.m20 &&
                    a.m21 == b.m21 &&
                    a.m22 == b.m22 &&

                    a.m30 == b.m30 &&
                    a.m31 == b.m31 &&
                    a.m32 == b.m32
                   );
        }


        template<typename T>
        inline bool operator == (const TMatrix4x4 <T> &a, const TAffineMatrix4x4 <T> &b) {
            return
                    a.m03 == 0 &&
                    a.m13 == 0 &&
                    a.m23 == 0 &&
                    a.m33 == 1 &&

                    a.m00 == b.m00 &&
                    a.m01 == b.m01 &&
                    a.m02 == b.m02 &&

                    a.m10 == b.m10 &&
                    a.m11 == b.m11 &&
                    a.m12 == b.m12 &&

                    a.m20 == b.m20 &&
                    a.m21 == b.m21 &&
                    a.m22 == b.m22 &&

                    a.m30 == b.m30 &&
                    a.m31 == b.m31 &&
                    a.m32 == b.m32;
        }

        template<typename T>
        inline bool operator==(const TAffineMatrix4x4 <T> &a, const TMatrix4x4 <T> &b) {
            return b == a;
        }


        template<typename T>
        inline bool operator!=(const TAffineMatrix4x4 <T> &a, const TAffineMatrix4x4 <T> &b) {
            return !(a == b);
        }

        template<typename T>
        inline bool operator!=(const TMatrix4x4 <T> &a, const TAffineMatrix4x4 <T> &b) {
            return !(a == b);
        }

        template<typename T>
        inline bool operator!=(const TAffineMatrix4x4 <T> &a, const TMatrix4x4 <T> &b) {
            return !(a == b);
        }
    }

}


#endif //RMVECTORMATH_TAFFINEMATRIX4X4_OPERATOR_HPP
