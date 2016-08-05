//
// Created by Vitali Kurlovich on 12/11/15.
//

#ifndef RMVECTORMATH_TVECTOR4_DEF_HPP
#define RMVECTORMATH_TVECTOR4_DEF_HPP

#include "../../common/common.hpp"

#include "../vector3x/TVector3_def.hpp"
#include "../vector2x/TVector2_def.hpp"

#include "../affinevector4x/TAffineVector4_def.hpp"

namespace rmmath {

    namespace vector {

        template<typename T>
        struct TVector4 {
            union {
                struct {
                    T x, y, z, w;
                };

                T v[4];
                TVector3 <T> xyz;
                TVector2 <T> xy;
            };

            TVector4(const T x = 0, const T y = 0, const  T z = 0, const T w = 0)
            : x(x), y(y), z(z), w(w)
            {

            }

            TVector4(const TVector3<T>& other, const T w)
                    : x(other.x), y(other.y), z(other.z), w(w)
            {

            }

            TVector4(const TVector2<T>& other, const T z, const T w)
                    : x(other.x), y(other.y), z(z), w(w)
            {

            }

            TVector4(const TAffineVector4<T>& other)
                    : x(other.x), y(other.y), z(other.z), w(1)
            {

            }

            const T operator [] (std::size_t index) const {
                return v[index];
            }

            static const TVector4<T>& zero() {
                static TVector4<T> zero;
                return zero;
            }

        };
    }

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


#endif //RMVECTORMATH_TVECTOR4_DEF_HPP
