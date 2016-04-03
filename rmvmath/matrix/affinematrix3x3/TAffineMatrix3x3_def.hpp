//
// Created by Vitali Kurlovich on 1/10/16.
//

#ifndef RMVECTORMATH_TAFFINEMATRIX3X3_DEF_HPP
#define RMVECTORMATH_TAFFINEMATRIX3X3_DEF_HPP

namespace rmmath {

    namespace matrix {

        /*
            T m00, m01, 0;
            T m10, m11, 0;
            T m20, m21, 1;

         */

        template<typename T>
        struct TAffineMatrix3x3 {
            T m00, m01;
            T m10, m11;
            T m20, m21;
        };

    }
}


#endif //RMVECTORMATH_TAFFINEMATRIX3X3_DEF_HPP
