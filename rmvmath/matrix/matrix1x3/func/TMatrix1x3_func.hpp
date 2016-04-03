//
// Created by Vitali Kurlovich on 1/7/16.
//

#ifndef RMVECTORMATH_TMATRIX1X3_FUNC_HPP
#define RMVECTORMATH_TMATRIX1X3_FUNC_HPP

#include "../TMatrix1x3_def.hpp"

#include "../../matrix3x1/TMatrix3x1_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline TMatrix3x1 <T> transpose(const TMatrix1x3 <T> &a) {
            TMatrix3x1<T> result = {
                    a.m00,
                    a.m01,
                    a.m02
            };

            return result;
        }
    }
}


#endif //RMVECTORMATH_TMATRIX1X3_FUNC_HPP
