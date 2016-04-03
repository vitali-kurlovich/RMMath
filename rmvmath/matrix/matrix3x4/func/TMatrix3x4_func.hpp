//
// Created by Vitali Kurlovich on 1/7/16.
//

#ifndef RMVECTORMATH_TMATRIX3X4_FUNC_HPP
#define RMVECTORMATH_TMATRIX3X4_FUNC_HPP

#include "../TMatrix3x4_def.hpp"

#include "../../matrix4x3/TMatrix4x3_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline TMatrix4x3 <T> transpose(const TMatrix3x4 <T> &a) {
            TMatrix4x3<T> result = {
                    a.m00, a.m10, a.m20,
                    a.m01, a.m11, a.m21,
                    a.m02, a.m12, a.m22,
                    a.m03, a.m13, a.m23
            };

            return result;
        }
    }
}


#endif //RMVECTORMATH_TMATRIX3X4_FUNC_HPP
