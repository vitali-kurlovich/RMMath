//
// Created by Vitali Kurlovich on 12/12/15.
//

#ifndef RMVECTORMATH_TMATRIX2X2_OPERATOR_HPP
#define RMVECTORMATH_TMATRIX2X2_OPERATOR_HPP

#include "../TMatrix2x2_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline bool operator == (const TMatrix2x2<T> &a, const TMatrix2x2<T> &b) {
            return &a == &b ||
                   (a.m00 == b.m00 &&
                    a.m01 == b.m01 &&
                    a.m10 == b.m10 &&
                    a.m11 == b.m11
                   );
        }

        template<typename T>
        inline bool operator != (const TMatrix2x2<T> &a, const TMatrix2x2<T> &b) {
            return !(a == b);
        }


    }
}

#endif //RMVECTORMATH_TMATRIX2X2_OPERATOR_HPP
