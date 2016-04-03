//
// Created by Vitali Kurlovich on 1/12/16.
//

#ifndef RMVECTORMATH_TAFFINEMATRIX3X3_OPERATOR_HPP
#define RMVECTORMATH_TAFFINEMATRIX3X3_OPERATOR_HPP

#include "../TAffineMatrix3x3_def.hpp"

#include "../../matrix3x3/TMatrix3x3_def.hpp"

namespace rmmath {

    namespace matrix {

        template<typename T>
        inline bool operator==(const TAffineMatrix3x3 <T> &a, const TAffineMatrix3x3 <T> &b) {
            return &a == &b ||
                   (a.m00 == b.m00 &&
                    a.m01 == b.m01 &&

                    a.m10 == b.m10 &&
                    a.m11 == b.m11 &&

                    a.m20 == b.m20 &&
                    a.m21 == b.m21
                   );
        }

        template<typename T>
        inline bool operator==(const TAffineMatrix3x3 <T> &a, const TMatrix3x3 <T> &b) {
            return
                    b.m02 == 0 &&
                    b.m12 == 0 &&
                    b.m22 == 1 &&

                    a.m00 == b.m00 &&
                    a.m01 == b.m01 &&

                    a.m10 == b.m10 &&
                    a.m11 == b.m11 &&

                    a.m20 == b.m20 &&
                    a.m21 == b.m21;
        }

        template<typename T>
        inline bool operator==(const TMatrix3x3 <T> &a, const TAffineMatrix3x3 <T> &b) {
            return b == a;
        }


        template<typename T>
        inline bool operator!=(const TAffineMatrix3x3 <T> &a, const TAffineMatrix3x3 <T> &b) {
            return !(a == b);
        }

        template<typename T>
        inline bool operator!=(const TMatrix3x3 <T> &a, const TAffineMatrix3x3 <T> &b) {
            return !(a == b);
        }

        template<typename T>
        inline bool operator!=(const TAffineMatrix3x3 <T> &a, const TMatrix3x3 <T> &b) {
            return !(a == b);
        }
    }
}

#endif //RMVECTORMATH_TAFFINEMATRIX3X3_OPERATOR_HPP
