//
// Created by Vitali Kurlovich on 12/12/15.
//

#ifndef RMVECTORMATH_TMATRIX1X2_OPERATOR_HPP
#define RMVECTORMATH_TMATRIX1X2_OPERATOR_HPP

#include "../TMatrix1x2_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline bool operator == (const TMatrix1x2<T> &a, const TMatrix1x2<T> &b) {
            return &a == &b ||
                   (a.m00 == b.m00 &&
                    a.m01 == b.m01
                   );
        }

        template<typename T>
        inline bool operator != (const TMatrix1x2<T> &a, const TMatrix1x2<T> &b) {
            return !(a == b);
        }


    }
}

#endif //RMVECTORMATH_TMATRIX1X2_OPERATOR_HPP
