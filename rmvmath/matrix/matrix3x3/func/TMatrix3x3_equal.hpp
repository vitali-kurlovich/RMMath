//
// Created by Vitali Kurlovich on 8/7/16.
//

#ifndef RMVECTORMATH_TMATRIX3X3_EQUAL_HPP
#define RMVECTORMATH_TMATRIX3X3_EQUAL_HPP

#include "../../../common/common.hpp"

#include "../../affinematrix3x3/TAffineMatrix3x3_def.hpp"

namespace rmmath {

    template<typename T>
    constexpr
    bool equal(const matrix::TMatrix3x3 <T> &a, const matrix::TMatrix3x3 <T> &b) noexcept {
        return &a == &b ||
               (
                       equal<T>(a.m00, b.m00) &&  equal<T>(a.m01, b.m01) &&  equal<T>(a.m02, b.m02) &&
                       equal<T>(a.m10, b.m10) &&  equal<T>(a.m11, b.m11) &&  equal<T>(a.m12, b.m12) &&
                       equal<T>(a.m20, b.m20) &&  equal<T>(a.m21, b.m21) &&  equal<T>(a.m22, b.m22)
               );
    }


    template<typename T>
    constexpr
    bool equal(const matrix::TAffineMatrix3x3 <T> &a, const matrix::TMatrix3x3 <T> &b) noexcept {
        return &a == &b ||
               (
                       equal_to_one<T>(b.m22) &&
                       equal_to_zero<T>(b.m02) &&
                       equal_to_zero<T>(b.m12) &&
                       equal<T>(a.m00, b.m00) &&  equal<T>(a.m01, b.m01) &&
                       equal<T>(a.m10, b.m10) &&  equal<T>(a.m11, b.m11) &&
                       equal<T>(a.m20, b.m20) &&  equal<T>(a.m21, b.m21)
               );
    }

    template<typename T>
    constexpr
    bool equal( const matrix::TMatrix3x3 <T> &b, const matrix::TAffineMatrix3x3 <T> &a) noexcept {
        return &a == &b ||
               (
                       equal_to_one<T>(b.m22) &&
                       equal_to_zero<T>(b.m02) &&
                       equal_to_zero<T>(b.m12) &&
                       equal<T>(a.m00, b.m00) &&  equal<T>(a.m01, b.m01) &&
                       equal<T>(a.m10, b.m10) &&  equal<T>(a.m11, b.m11) &&
                       equal<T>(a.m20, b.m20) &&  equal<T>(a.m21, b.m21)
               );
    }


}

#endif //RMVECTORMATH_TMATRIX3X3_EQUAL_HPP
