//
// Created by Vitali Kurlovich on 8/8/16.
//

#ifndef RMVECTORMATH_TAFFINEMATRIX4X4_EQUAL_HPP
#define RMVECTORMATH_TAFFINEMATRIX4X4_EQUAL_HPP

#include "../../../common/common.hpp"

#include "../../affinematrix4x4/TAffineMatrix4x4_def.hpp"

namespace rmmath {

    template<typename T>
    constexpr
    bool equal(const matrix::TAffineMatrix4x4 <T> &a, const matrix::TAffineMatrix4x4 <T> &b) noexcept {
        return &a == &b ||
               (
                       equal<T>(a.m11, b.m11) &&

                       equal<T>(a.m30, b.m30) &&  equal<T>(a.m31, b.m31) && equal<T>(a.m32, b.m32) &&
                       equal<T>(a.m00, b.m00) &&  equal<T>(a.m01, b.m01) && equal<T>(a.m02, b.m02) &&
                       equal<T>(a.m10, b.m10) &&  equal<T>(a.m12, b.m12) &&
                       equal<T>(a.m20, b.m20) &&  equal<T>(a.m21, b.m21) && equal<T>(a.m22, b.m22)
               );
    }

}

#endif //RMVECTORMATH_TAFFINEMATRIX4X4_EQUAL_HPP
