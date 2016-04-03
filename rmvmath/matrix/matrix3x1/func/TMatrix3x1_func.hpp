//
// Created by Vitali Kurlovich on 1/7/16.
//

#ifndef RMVECTORMATH_TMATRIX3X1_FUNC_HPP
#define RMVECTORMATH_TMATRIX3X1_FUNC_HPP

#include "../TMatrix3x1_def.hpp"

#include "../../matrix1x3/TMatrix1x3_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline TMatrix1x3 <T> transpose(const TMatrix3x1 <T> &a) {
            TMatrix1x3<T> result = {
                    a.m00, a.m10, a.m20
            };

            return result;
        }
    }
}


#endif //RMVECTORMATH_TMATRIX3X1_FUNC_HPP
