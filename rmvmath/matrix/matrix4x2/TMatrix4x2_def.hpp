//
// Created by Vitali Kurlovich on 12/19/15.
//

#ifndef RMVECTORMATH_TMATRIX4X2_DEF_HPP
#define RMVECTORMATH_TMATRIX4X2_DEF_HPP


namespace rmmath {

    namespace matrix {

        template<typename T>
        struct TMatrix4x2 {
            T m00, m01;
            T m10, m11;
            T m20, m21;
            T m30, m31;
        };

    }
}

/*

 {{m00, m01},
 {m10, m11},
 {m20, m21},
 {m30, m31}}

 */

#endif //RMVECTORMATH_TMATRIX4X2_DEF_HPP
