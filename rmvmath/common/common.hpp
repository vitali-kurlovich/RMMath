//
// Created by Vitali Kurlovich on 8/5/16.
//

#ifndef RMVECTORMATH_COMMON_HPP
#define RMVECTORMATH_COMMON_HPP

namespace rmmath {

    template <typename T>
    constexpr bool equal_to_zero(const T value) noexcept {
        return 0 == value;
    }

    template <typename T>
    constexpr bool equal_to_zero(const T value, const T precision) noexcept {
        return  value > -precision && value < precision;
    }

    template <typename T>
    constexpr bool equal_to_zero(const float value) noexcept {
        return  equal_to_zero(value, 0.000476838f);
    }


    template <typename T>
    constexpr bool equal_to_zero(const double value) noexcept {
        return  equal_to_zero(value, 1.332268e-16);
    }

    template <typename T>
    constexpr bool equal_to_one(const T value) noexcept {
        return 1 == value;
    }

    template <typename T>
    constexpr bool equal_to_one(const float value) noexcept {
        return  value > 1.f - 0.0000476838f && value < 1.0000476838f;
    }

    template <typename T>
    constexpr bool equal_to_one(const double value) noexcept {
        return  value > 1 - 1.332268e-16 && value < 1 + 1.332268e-16;
    }


    template <typename TA, typename TB>
    constexpr bool equal(const TA a, const TB b) noexcept {
        return a == b;
    }

    template <typename T>
    constexpr bool equal(const T a, const T b) noexcept {
        return a == b;
    }

    template <typename T>
    constexpr bool equal(const T a, const T b, const T precision) noexcept {
        return equal_to_zero<T>(a-b, precision);
    }


    template <typename T>
    constexpr bool equal(const float a, const float b) noexcept {
        return equal_to_zero<float>(a-b);
    }

    template <typename T>
    constexpr bool equal(const double a, const double b) noexcept {
        return equal_to_zero<double>(a-b);
    }

    template <typename T>
    constexpr bool equal(const float a, const double b) noexcept {
        return equal_to_zero<float>((float)a-b);
    }

    template <typename T>
    constexpr bool equal(const double a, const float b) noexcept {
        return equal_to_zero<float>((float)a-b);
    }

}

#endif //RMVECTORMATH_COMMON_HPP
