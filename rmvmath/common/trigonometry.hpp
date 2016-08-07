//
// Created by Vitali Kurlovich on 8/6/16.
//

#ifndef RMVECTORMATH_TRIGONOMETRY_HPP
#define RMVECTORMATH_TRIGONOMETRY_HPP

#include <math.h>

namespace rmmath {

    namespace math {
        template<typename T>
        constexpr T cos(T angle) noexcept {
            return cos(angle);
        }

        template<typename T>
        constexpr float cos(float angle) noexcept {
            return cosf(angle);
        }


        template<typename T>
        constexpr T sin(T angle) noexcept {
            return sin(angle);
        }

        template<typename T>
        constexpr float sin(float angle) noexcept {
            return sinf(angle);
        }

    }
}

#endif //RMVECTORMATH_TRIGONOMETRY_HPP
