//
// Created by Vitali Kurlovich on 12/20/15.
//

#ifndef RMVECTORMATH_TMATRIX4X3_FUNC_HPP
#define RMVECTORMATH_TMATRIX4X3_FUNC_HPP


#include "../TMatrix4x3_def.hpp"

#include "../../matrix3x4/TMatrix3x4_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline TMatrix3x4 <T> transpose(const TMatrix4x3 <T> &a) {
            TMatrix3x4<T> result = {
                    a.m00, a.m10, a.m20, a.m30,
                    a.m01, a.m11, a.m21, a.m31,
                    a.m02, a.m12, a.m22, a.m32
            };

            return result;
        }


    }
}

#endif //RMVECTORMATH_TMATRIX4X3_FUNC_HPP
