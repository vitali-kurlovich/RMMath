//
// Created by Vitali Kurlovich on 8/7/16.
//

#ifndef RMVECTORMATH_TAFFINEVECTOR3_EQUAL_HPP
#define RMVECTORMATH_TAFFINEVECTOR3_EQUAL_HPP


#include "../../../common/common.hpp"

#include "../TAffineVector3_def.hpp"

namespace rmmath {
    template <typename T>
    constexpr bool equal(const vector::TAffineVector3<T> &a, const vector::TAffineVector3<T> &b) noexcept {
        return &a == &b || (equal<T>(a.x, b.x) && equal<T>(a.y, b.y));
    }
}

#endif //RMVECTORMATH_TAFFINEVECTOR3_EQUAL_HPP
