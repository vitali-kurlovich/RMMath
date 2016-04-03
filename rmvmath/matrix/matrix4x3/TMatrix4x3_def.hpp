//
// Created by Vitali Kurlovich on 12/16/15.
//

#ifndef RMVECTORMATH_TMATRIX4X3_DEF_HPP
#define RMVECTORMATH_TMATRIX4X3_DEF_HPP

namespace rmmath {

    namespace matrix {

        template<typename T>
        struct TMatrix4x3 {
            T m00, m01, m02;
            T m10, m11, m12;
            T m20, m21, m22;
            T m30, m31, m32;
        };

    }
}

/*

 {{m00, m01, m02},
 {m10, m11, m12},
 {m20, m21, m22},
 {m30, m31, m32}}

 */


#endif //RMVECTORMATH_TMATRIX4X3_DEF_HPP
