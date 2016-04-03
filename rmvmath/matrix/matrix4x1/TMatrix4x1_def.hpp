//
// Created by Vitali Kurlovich on 12/19/15.
//

#ifndef RMVECTORMATH_TMATRIX4X1_DEF_HPP
#define RMVECTORMATH_TMATRIX4X1_DEF_HPP


namespace rmmath {

    namespace matrix {

        template<typename T>
        struct TMatrix4x1 {
            T m00;
            T m10;
            T m20;
            T m30;
        };

    }
}

/*

 {{m00},
 {m10},
 {m20},
 {m30}}

 */

#endif //RMVECTORMATH_TMATRIX4X1_DEF_HPP
