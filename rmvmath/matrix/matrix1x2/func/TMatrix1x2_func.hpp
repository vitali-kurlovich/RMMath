//
// Created by Vitali Kurlovich on 1/7/16.
//

#ifndef RMVECTORMATH_TMATRIX1X2_FUNC_HPP
#define RMVECTORMATH_TMATRIX1X2_FUNC_HPP

#include "../TMatrix1x2_def.hpp"

#include "../../matrix2x1/TMatrix2x1_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline TMatrix2x1 <T> transpose(const TMatrix1x2 <T> &a) {
            TMatrix2x1<T> result = {
                    a.m00,
                    a.m01
            };

            return result;
        }
    }
}


#endif //RMVECTORMATH_TMATRIX1X2_FUNC_HPP
