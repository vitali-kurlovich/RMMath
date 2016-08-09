//
// Created by Vitali Kurlovich on 8/9/16.
//

#ifndef RMVECTORMATH_ARITHMETIC_HPP
#define RMVECTORMATH_ARITHMETIC_HPP

#include <math.h>

namespace rmmath {

    namespace math {
        template<typename T>
        constexpr T sqrt(T value) noexcept {
            return sqrt(value);
        }

        template<typename T>
        constexpr float sqrt(float value) noexcept {
            return sqrtf(value);
        }
    }
}



#endif //RMVECTORMATH_ARITHMETIC_HPP
