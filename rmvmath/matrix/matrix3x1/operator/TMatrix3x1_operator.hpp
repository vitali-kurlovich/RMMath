//
// Created by Vitali Kurlovich on 12/22/15.
//

#ifndef RMVECTORMATH_TMATRIX3X1_OPERATOR_HPP
#define RMVECTORMATH_TMATRIX3X1_OPERATOR_HPP

#include "../TMatrix3x1_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline bool operator == (const TMatrix3x1 <T> &a, const TMatrix3x1 <T> &b) {
            return &a == &b ||
                   (a.m00 == b.m00 &&
                    a.m10 == b.m10 &&
                    a.m20 == b.m20
                   );
        }

        template<typename T>
        inline bool operator != (const TMatrix3x1 <T> &a, const TMatrix3x1 <T> &b) {
            return !(a == b);
        }

    }
}

#endif //RMVECTORMATH_TMATRIX3X1_OPERATOR_HPP
