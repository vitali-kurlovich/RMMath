//
// Created by Vitali Kurlovich on 12/12/15.
//

#ifndef RMVECTORMATH_TMATRIX4X4_DEF_HPP
#define RMVECTORMATH_TMATRIX4X4_DEF_HPP

namespace rmmath {

    namespace matrix {

        template<typename T>
        struct TMatrix4x4 {
            T m00, m01, m02, m03;
            T m10, m11, m12, m13;
            T m20, m21, m22, m23;
            T m30, m31, m32, m33;
        };

    }
}

#endif //RMVECTORMATH_TMATRIX4X4_DEF_HPP
