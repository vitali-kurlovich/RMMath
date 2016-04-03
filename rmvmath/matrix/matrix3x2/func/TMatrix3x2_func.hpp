//
// Created by Vitali Kurlovich on 1/7/16.
//

#ifndef RMVECTORMATH_TMATRIX3X2_FUNC_HPP
#define RMVECTORMATH_TMATRIX3X2_FUNC_HPP


#include "../TMatrix3x2_def.hpp"

#include "../../matrix2x3/TMatrix2x3_def.hpp"

namespace rmmath {

    namespace matrix {

        template<typename T>
        inline TMatrix2x3 <T> transpose(const TMatrix3x2 <T> &a) {
            TMatrix2x3<T> result = {
                    a.m00, a.m10, a.m20,
                    a.m01, a.m11, a.m21
            };

            return result;
        }
    }
}


#endif //RMVECTORMATH_TMATRIX3X2_FUNC_HPP
