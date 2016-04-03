//
// Created by Vitali Kurlovich on 12/12/15.
//

#ifndef RMVECTORMATH_TMATRIX3X3_OPERATOR_HPP
#define RMVECTORMATH_TMATRIX3X3_OPERATOR_HPP

#include "../TMatrix3x3_def.hpp"


namespace rmmath {

    namespace matrix {

        template<typename T>
        inline bool operator == (const TMatrix3x3<T> &a, const TMatrix3x3<T> &b) {
            return &a == &b ||
                   (a.m00 == b.m00 &&
                    a.m01 == b.m01 &&
                    a.m02 == b.m02 &&

                    a.m10 == b.m10 &&
                    a.m11 == b.m11 &&
                    a.m12 == b.m12 &&

                    a.m20 == b.m20 &&
                    a.m21 == b.m21 &&
                    a.m22 == b.m22
                   );
        }

        template<typename T>
        inline bool operator != (const TMatrix3x3<T> &a, const TMatrix3x3<T> &b) {
            return !(a == b);
        }


    }
}

#endif //RMVECTORMATH_TMATRIX3X3_OPERATOR_HPP
