//
// Created by Vitali Kurlovich on 12/12/15.
//

#ifndef RMVECTORMATH_TMATRIX3X3_DEF_HPP
#define RMVECTORMATH_TMATRIX3X3_DEF_HPP

namespace rmmath {

    namespace matrix {

        template<typename T>
        struct TMatrix3x3 {
            T m00, m01, m02;
            T m10, m11, m12;
            T m20, m21, m22;
        };

    }
}

#endif //RMVECTORMATH_TMATRIX3X3_DEF_HPP
