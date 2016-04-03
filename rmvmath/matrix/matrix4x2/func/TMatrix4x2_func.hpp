//
// Created by Vitali Kurlovich on 1/7/16.
//

#ifndef RMVECTORMATH_TMATRIX4X2_FUNC_HPP
#define RMVECTORMATH_TMATRIX4X2_FUNC_HPP

#include "../TMatrix4x2_def.hpp"

#include "../../matrix2x4/TMatrix2x4_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline TMatrix2x4 <T> transpose(const TMatrix4x2 <T> &a) {
            TMatrix2x4<T> result = {
                    a.m00, a.m10, a.m20, a.m30,
                    a.m01, a.m11, a.m21, a.m31
            };

            return result;
        }
    }
}


#endif //RMVECTORMATH_TMATRIX4X2_FUNC_HPP
