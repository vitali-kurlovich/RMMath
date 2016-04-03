//
// Created by Vitali Kurlovich on 1/7/16.
//

#ifndef RMVECTORMATH_TMATRIX2X1_FUNC_MULVEC_HPP
#define RMVECTORMATH_TMATRIX2X1_FUNC_MULVEC_HPP

#include "../TMatrix2x1_def.hpp"

#include "../../../vector/vector2x/TVector2_def.hpp"


namespace rmmath {

    template<typename T>
    inline vector::TVector2<T> mul(const matrix::TMatrix2x1<T> &a, T b) {
        vector::TVector2<T> c;

        c.x = a.m00*b;
        c.y = a.m10*b;

        return c;
    }


    template<typename T>
    inline T mul(const vector::TVector2 <T> &b, const matrix::TMatrix2x1<T> &a) {
        return a.m00*b.x + a.m10*b.y;
    }

}

#endif //RMVECTORMATH_TMATRIX2X1_FUNC_MULVEC_HPP
