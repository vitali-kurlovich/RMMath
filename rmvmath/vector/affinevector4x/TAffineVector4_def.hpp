//
// Created by Vitali Kurlovich on 1/20/16.
//

#ifndef RMVECTORMATH_TAFFINEVECTOR4_DEF_HPP
#define RMVECTORMATH_TAFFINEVECTOR4_DEF_HPP

#include "../../common/common.hpp"
#include "../vector3x/TVector3_def.hpp"
#include "../vector2x/TVector2_def.hpp"

namespace rmmath {

    namespace vector {

        /*
         * T x, y, z, 1;
         */

        template<typename T>
        struct TAffineVector4 {
            union {
                struct {
                    T x, y, z;
                };

                T v[3];
                TVector3 <T> xyz;
                TVector2 <T> xy;
            };


            constexpr TAffineVector4(const T x = 0, const T y = 0, const  T z = 0) noexcept
                    : x(x), y(y), z(z)
            {

            }


            constexpr TAffineVector4(const TVector2<T>& other, const T z) noexcept
                    : x(other.x), y(other.y), z(z)
            {
            }

            const T operator [] (std::size_t index) const {
                return index != 3 ? v[index] : 1;
            }

            static const TAffineVector4<T>& zero() noexcept {
                static TAffineVector4<T> zero;
                return zero;
            }
        };
    }

    template <typename T>
    constexpr bool equal(const vector::TAffineVector4<T> &a, const vector::TAffineVector4<T> &b) noexcept {
        return &a == &b ||
               (equal<T>(a.x, b.x) && equal<T>(a.y, b.y) && equal<T>(a.z, b.z));
    }

}

#endif //RMVECTORMATH_TAFFINEVECTOR4_DEF_HPP
