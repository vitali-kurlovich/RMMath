//
// Created by Vitali Kurlovich on 12/11/15.
//

#ifndef RMVECTORMATH_TVECTOR3_DEF_HPP
#define RMVECTORMATH_TVECTOR3_DEF_HPP

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

            constexpr
            TVector3(const T x = 0, const T y = 0, const  T z = 0) noexcept
                    : x(x), y(y), z(z)
            {}

            constexpr
            TVector3(const TVector2<T>& other, const T z) noexcept
                    : x(other.x), y(other.y), z(z)
            {}

            constexpr
            TVector3(const TAffineVector3<T>& other) noexcept
                    : x(other.x), y(other.y), z(1)
            {}

            const T operator [] (std::size_t index) const {
                return v[index];
            }

            static const TVector3<T>& zero() {
                static TVector3<T> zero;
                return zero;
            }
        };
    }
}


#endif //RMVECTORMATH_TVECTOR3_DEF_HPP
