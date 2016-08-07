//
// Created by Vitali Kurlovich on 8/7/16.
//

#ifndef RMVECTORMATH_TAFFINEVECTOR4_EQUAL_HPP
#define RMVECTORMATH_TAFFINEVECTOR4_EQUAL_HPP

#include "../../../common/common.hpp"

#include "../TAffineVector4_def.hpp"

namespace rmmath {
    template <typename T>
    constexpr bool equal(const vector::TAffineVector4<T> &a, const vector::TAffineVector4<T> &b) noexcept {
        return &a == &b ||
               (equal<T>(a.x, b.x) && equal<T>(a.y, b.y) && equal<T>(a.z, b.z));
    }
}

#endif //RMVECTORMATH_TAFFINEVECTOR4_EQUAL_HPP
