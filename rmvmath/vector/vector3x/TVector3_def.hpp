//
// Created by Vitali Kurlovich on 12/11/15.
//

#ifndef RMVECTORMATH_TVECTOR3_DEF_HPP
#define RMVECTORMATH_TVECTOR3_DEF_HPP

#include "../../common/common.hpp"

#include "../vector2x/TVector2_def.hpp"
#include "../affinevector3x/TAffineVector3_def.hpp"


namespace rmmath {

    namespace vector {

        template<typename T>
        struct TVector3 {
            union {
                struct {
                    T x, y, z;
                };

                T v[3];
                TVector2 <T> xy;
            };

            TVector3(const T x = 0, const T y = 0, const  T z = 0)
                    : x(x), y(y), z(z)
            {

            }

            TVector3(const TVector2<T>& other, const T z)
                    : x(other.x), y(other.y), z(z)
            {

            }

            TVector3(const TAffineVector3<T>& other)
                    : x(other.x), y(other.y), z(1)
            {

            }

            const T operator [] (std::size_t index) const {
                return v[index];
            }

            static const TVector3<T>& zero() {
                static TVector3<T> zero;
                return zero;
            }
        };
    }

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


#endif //RMVECTORMATH_TVECTOR3_DEF_HPP
