//
// Created by Vitali Kurlovich on 1/20/16.
//

#ifndef RMVECTORMATH_TAFFINEVECTOR3_DEF_HPP
#define RMVECTORMATH_TAFFINEVECTOR3_DEF_HPP

#include "../vector2x/TVector2_def.hpp"

namespace rmmath {

    namespace vector {

        /*
         *  T x, y, 1;
         */


        template<typename T>
        struct TAffineVector3 {
            union {
                struct {
                    T x, y;
                };

                T v[2];
                TVector2 <T> xy;
            };


            constexpr
            TAffineVector3(const T x = 0, const T y = 0) noexcept
                    : x(x), y(y)
            {}

            const T operator [] (std::size_t index) const {
                return index != 2 ? v[index] : 1;
            }

            static const TAffineVector3<T>& zero() {
                static TAffineVector3<T> zero;
                return zero;
            }

        };
    }
}


#endif //RMVECTORMATH_TAFFINEVECTOR3_DEF_HPP
