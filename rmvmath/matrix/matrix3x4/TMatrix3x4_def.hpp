//
// Created by Vitali Kurlovich on 12/16/15.
//

#ifndef RMVECTORMATH_TMATRIX3X4_DEF_HPP
#define RMVECTORMATH_TMATRIX3X4_DEF_HPP

namespace rmmath {

    namespace matrix {

        template<typename T>
        struct TMatrix3x4 {
            T m00, m01, m02, m03;
            T m10, m11, m12, m13;
            T m20, m21, m22, m23;
        };

    }
}

#endif //RMVECTORMATH_TMATRIX3X4_DEF_HPP
