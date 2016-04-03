//
// Created by Vitali Kurlovich on 1/7/16.
//

#ifndef RMVECTORMATH_TMATRIX2X3_FUNC_HPP
#define RMVECTORMATH_TMATRIX2X3_FUNC_HPP



#include "../TMatrix2x3_def.hpp"

#include "../../matrix3x2/TMatrix3x2_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline TMatrix3x2 <T> transpose(const TMatrix2x3 <T> &a) {
            TMatrix3x2<T> result = {
                    a.m00, a.m10,
                    a.m01, a.m11,
                    a.m02, a.m12
            };

            return result;
        }
    }
}


#endif //RMVECTORMATH_TMATRIX2X3_FUNC_HPP
