//
// Created by Vitali Kurlovich on 1/7/16.
//

#ifndef RMVECTORMATH_TMATRIX4X1_FUNC_HPP
#define RMVECTORMATH_TMATRIX4X1_FUNC_HPP

#include "../TMatrix4x1_def.hpp"

#include "../../matrix1x4/TMatrix1x4_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline TMatrix1x4 <T> transpose(const TMatrix4x1 <T> &a) {
            TMatrix1x4<T> result = {
                    a.m00, a.m10, a.m20, a.m30
            };

            return result;
        }
    }
}


#endif //RMVECTORMATH_TMATRIX4X1_FUNC_HPP
