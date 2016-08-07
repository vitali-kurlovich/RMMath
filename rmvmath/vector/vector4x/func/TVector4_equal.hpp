//
// Created by Vitali Kurlovich on 8/7/16.
//

#ifndef RMVECTORMATH_TVECTOR4_EQUAL_HPP
#define RMVECTORMATH_TVECTOR4_EQUAL_HPP

#include "../../../common/common.hpp"
#include "../TVector4_def.hpp"
#include "../../affinevector4x/TAffineVector4_def.hpp"

namespace rmmath {

    template <typename T>
    constexpr bool equal(const vector::TVector4<T> &a, const vector::TVector4<T> &b) noexcept {
        return &a == &b ||
               (equal<T>(a.x, b.x) && equal<T>(a.y, b.y) && equal<T>(a.z, b.z) && equal<T>(a.w, b.w));
    }

    template <typename T>
    constexpr bool equal(const vector::TAffineVector4<T> &a, const vector::TVector4<T> &b) noexcept {
        return equal_to_one<T>(b.w) && equal<T>(a.x, b.x) && equal<T>(a.y, b.y) && equal<T>(a.z, b.z);
    }

    template <typename T>
    constexpr bool equal(const vector::TVector4<T> &a, const vector::TAffineVector4<T> &b) noexcept {
        return equal<T>(b, a);
    }
}

#endif //RMVECTORMATH_TVECTOR4_EQUAL_HPP
