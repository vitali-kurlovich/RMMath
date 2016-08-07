//
// Created by Vitali Kurlovich on 8/7/16.
//

#ifndef RMVECTORMATH_TVECTOR2_EQUAL_HPP
#define RMVECTORMATH_TVECTOR2_EQUAL_HPP

#include "../../../common/common.hpp"
#include "../TVector2_def.hpp"

namespace rmmath {
    template <typename T>
    constexpr bool equal(const vector::TVector2<T> &a, const vector::TVector2<T> &b) noexcept {
        return &a == &b || (equal<T>(a.x, b.x) && equal<T>(a.y, b.y));
    }
}

#endif //RMVECTORMATH_TVECTOR2_EQUAL_HPP
