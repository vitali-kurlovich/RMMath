//
// Created by Vitali Kurlovich on 12/19/15.
//

#ifndef RMVECTORMATH_TMATRIX4X2_OPERATOR_HPP
#define RMVECTORMATH_TMATRIX4X2_OPERATOR_HPP


#include "../TMatrix4x2_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline bool operator==(const TMatrix4x2 <T> &a, const TMatrix4x2 <T> &b) {
            return &a == &b ||
                   (a.m00 == b.m00 &&
                    a.m01 == b.m01 &&

                    a.m10 == b.m10 &&
                    a.m11 == b.m11 &&

                    a.m20 == b.m20 &&
                    a.m21 == b.m21 &&

                    a.m30 == b.m30 &&
                    a.m31 == b.m31
                   );
        }

        template<typename T>
        inline bool operator!=(const TMatrix4x2 <T> &a, const TMatrix4x2 <T> &b) {
            return !(a == b);
        }


    }
}


#endif //RMVECTORMATH_TMATRIX4X2_OPERATOR_HPP
