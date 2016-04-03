//
// Created by Vitali Kurlovich on 1/7/16.
//

#ifndef RMVECTORMATH_TMATRIX2X1_FUNC_HPP
#define RMVECTORMATH_TMATRIX2X1_FUNC_HPP

#include "../TMatrix2x1_def.hpp"

#include "../../matrix1x2/TMatrix1x2_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline TMatrix1x2 <T> transpose(const TMatrix2x1 <T> &a) {
            TMatrix1x2<T> result = {
                    a.m00, a.m10
            };

            return result;
        }
    }
}



#endif //RMVECTORMATH_TMATRIX2X1_FUNC_HPP
