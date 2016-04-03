//
// Created by Vitali Kurlovich on 12/23/15.
//

#ifndef RMVECTORMATH_TMATRIX1X1_OPERATOR_HPP
#define RMVECTORMATH_TMATRIX1X1_OPERATOR_HPP

#include "../TMatrix1x1_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline bool operator == (const TMatrix1x1 <T> &a, const TMatrix1x1 <T> &b) {
            return &a == &b || (a.m00 == b.m00);
        }

        template<typename T>
        inline bool operator != (const TMatrix1x1 <T> &a, const TMatrix1x1 <T> &b) {
            return !(a == b);
        }

    }
}

#endif //RMVECTORMATH_TMATRIX1X1_OPERATOR_HPP
