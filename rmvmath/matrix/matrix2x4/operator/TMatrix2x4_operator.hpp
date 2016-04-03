//
// Created by Vitali Kurlovich on 12/23/15.
//

#ifndef RMVECTORMATH_TMATRIX2X4_OPERATOR_HPP
#define RMVECTORMATH_TMATRIX2X4_OPERATOR_HPP

#include "../TMatrix2x4_def.hpp"

namespace rmmath {

    namespace matrix {

        template<typename T>
        inline bool operator==(const TMatrix2x4 <T> &a, const TMatrix2x4 <T> &b) {
            return &a == &b ||
                   (
                           a.m00 == b.m00 &&
                           a.m01 == b.m01 &&
                           a.m02 == b.m02 &&
                           a.m03 == b.m03 &&

                           a.m10 == b.m10 &&
                           a.m11 == b.m11 &&
                           a.m12 == b.m12 &&
                           a.m13 == b.m13
                   );
        }

        template<typename T>
        inline bool operator!=(const TMatrix2x4 <T> &a, const TMatrix2x4 <T> &b) {
            return !(a == b);
        }

    }
}


#endif //RMVECTORMATH_TMATRIX2X4_OPERATOR_HPP
