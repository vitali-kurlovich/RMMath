//
// Created by Vitali Kurlovich on 1/8/16.
//

#ifndef RMVECTORMATH_TAFFINEMATRIX4X4_DEF_HPP
#define RMVECTORMATH_TAFFINEMATRIX4X4_DEF_HPP

namespace rmmath {

    namespace matrix {

        /*
            T m00, m01, m02, 0;
            T m10, m11, m12, 0;
            T m20, m21, m22, 0;
            T m30, m31, m32, 1;
         */

        template<typename T>
        struct TAffineMatrix4x4 {
            T m00, m01, m02;
            T m10, m11, m12;
            T m20, m21, m22;
            T m30, m31, m32;
        };


        /*

            T m00, m01, m02, m03;
            T m10, m11, m12, m13;
            T m20, m21, m22, m23;
            T   0,   0,   0,   1;

         */

        template<typename T>
        struct TTAffineMatrix4x4 {
            T m00, m01, m02, m03;
            T m10, m11, m12, m13;
            T m20, m21, m22, m23;
        };

    }
}

#endif //RMVECTORMATH_TAFFINEMATRIX4X4_DEF_HPP
