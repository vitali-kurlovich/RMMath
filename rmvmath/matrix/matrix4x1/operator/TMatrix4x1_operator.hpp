//
// Created by Vitali Kurlovich on 12/19/15.
//

#ifndef RMVECTORMATH_TMATRIX4X1_OPERATOR_HPP
#define RMVECTORMATH_TMATRIX4X1_OPERATOR_HPP

#include "../TMatrix4x1_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline bool operator==(const TMatrix4x1 <T> &a, const TMatrix4x1 <T> &b) {
            return &a == &b ||
                   (a.m00 == b.m00 &&
                    a.m10 == b.m10 &&
                    a.m20 == b.m20 &&
                    a.m30 == b.m30
                   );
        }

        template<typename T>
        inline bool operator!=(const TMatrix4x1 <T> &a, const TMatrix4x1 <T> &b) {
            return !(a == b);
        }


    }
}


#endif //RMVECTORMATH_TMATRIX4X1_OPERATOR_HPP
