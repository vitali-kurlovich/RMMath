//
// Created by Vitali Kurlovich on 1/7/16.
//

#ifndef RMVECTORMATH_TMATRIX1X4_FUNC_HPP
#define RMVECTORMATH_TMATRIX1X4_FUNC_HPP


#include "../TMatrix1x4_def.hpp"

#include "../../matrix4x1/TMatrix4x1_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline TMatrix4x1 <T> transpose(const TMatrix1x4 <T> &a) {
            TMatrix4x1<T> result = {
                    a.m00,
                    a.m01,
                    a.m02,
                    a.m03
            };

            return result;
        }
    }
}


#endif //RMVECTORMATH_TMATRIX1X4_FUNC_HPP
