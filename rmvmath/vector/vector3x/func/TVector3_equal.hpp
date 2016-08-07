//
// Created by Vitali Kurlovich on 8/7/16.
//

#ifndef RMVECTORMATH_TVECTOR3_EQUAL_HPP
#define RMVECTORMATH_TVECTOR3_EQUAL_HPP

#include "../../../common/common.hpp"
#include "../TVector3_def.hpp"

namespace rmmath {
    template <typename T>
    constexpr bool equal(const vector::TVector3<T> &a, const vector::TVector3<T> &b) noexcept {
        return &a == &b || (equal<T>(a.x, b.x) && equal<T>(a.y, b.y) && equal<T>(a.z, b.z));
    }

    template <typename T>
    constexpr bool equal(const vector::TAffineVector3<T> &a, const vector::TVector3<T> &b) noexcept {
        return equal_to_one<T>(b.z) && equal<T>(a.x, b.x) && equal<T>(a.y, b.y);
    }

    template <typename T>
    constexpr bool equal(const vector::TVector3<T> &a, const vector::TAffineVector3<T> &b) noexcept {
        return equal<T>(b, a);
    }
}

#endif //RMVECTORMATH_TVECTOR3_EQUAL_HPP
