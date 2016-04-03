//
// Created by Vitali Kurlovich on 12/23/15.
//

#ifndef RMVECTORMATH_TMATRIX2X1_OPERATOR_HPP
#define RMVECTORMATH_TMATRIX2X1_OPERATOR_HPP

#include "../TMatrix2x1_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline bool operator == (const TMatrix2x1 <T> &a, const TMatrix2x1 <T> &b) {
            return &a == &b ||
                   (a.m00 == b.m00 &&
                    a.m10 == b.m10
                   );
        }

        template<typename T>
        inline bool operator != (const TMatrix2x1 <T> &a, const TMatrix2x1 <T> &b) {
            return !(a == b);
        }

    }
}

#endif //RMVECTORMATH_TMATRIX2X1_OPERATOR_HPP
