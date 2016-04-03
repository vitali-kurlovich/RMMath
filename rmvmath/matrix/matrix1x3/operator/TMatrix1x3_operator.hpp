//
// Created by Vitali Kurlovich on 12/23/15.
//

#ifndef RMVECTORMATH_TMATRIX1X3_OPERATOR_HPP
#define RMVECTORMATH_TMATRIX1X3_OPERATOR_HPP

#include "../TMatrix1x3_def.hpp"

namespace rmmath {

    namespace matrix {

        template<typename T>
        inline bool operator==(const TMatrix1x3 <T> &a, const TMatrix1x3 <T> &b) {
            return &a == &b ||
                   (a.m00 == b.m00 &&
                    a.m01 == b.m01 &&
                    a.m02 == b.m02
                   );
        }

        template<typename T>
        inline bool operator!=(const TMatrix1x3 <T> &a, const TMatrix1x3 <T> &b) {
            return !(a == b);
        }

    }
}


#endif //RMVECTORMATH_TMATRIX1X3_OPERATOR_HPP
