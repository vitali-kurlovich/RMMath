//
// Created by Vitali Kurlovich on 1/7/16.
//

#ifndef RMVECTORMATH_TMATRIX2X4_FUNC_HPP
#define RMVECTORMATH_TMATRIX2X4_FUNC_HPP


#include "../TMatrix2x4_def.hpp"

#include "../../matrix4x2/TMatrix4x2_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline TMatrix4x2 <T> transpose(const TMatrix2x4 <T> &a) {
            TMatrix4x2<T> result = {
                    a.m00, a.m10,
                    a.m01, a.m11,
                    a.m02, a.m12,
                    a.m03, a.m13
            };

            return result;
        }
    }
}


#endif //RMVECTORMATH_TMATRIX2X4_FUNC_HPP
