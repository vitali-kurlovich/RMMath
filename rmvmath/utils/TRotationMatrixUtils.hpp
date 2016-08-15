//
// Created by Vitali Kurlovich on 8/6/16.
//

#ifndef RMVECTORMATH_TROTATIONMATRIXUTILS_HPP
#define RMVECTORMATH_TROTATIONMATRIXUTILS_HPP


#include <cmath>

#include "../matrix/matrix3x3/TMatrix3x3_def.hpp"
#include "../vector/vector3x/TVector3_def.hpp"


#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

namespace rmmath {

    namespace utils {

        template<typename T>
        const matrix::TMatrix3x3<T> rotationMatrix3x3(const T angle, const vector::TVector3<T> &axis) {

            const T _sin(std::sin(angle));
            const T _cos(std::cos(angle));

            return matrix::TMatrix3x3<T>(

                    _cos + axis.x * axis.x * (1 - _cos),
                    axis.x * axis.y * (1 - _cos) - axis.z * _sin,
                    axis.x * axis.z * (1 - _cos) + axis.y * _sin,

                    axis.x * axis.y * (1 - _cos) + axis.z * _sin,
                    _cos + axis.y * axis.y * (1 - _cos),
                    axis.y * axis.z * (1 - _cos) - axis.x * _sin,

                    axis.x * axis.z * (1 - _cos) - axis.y * _sin,
                    axis.y * axis.z * (1 - _cos) + axis.x * _sin,
                    _cos + axis.z * axis.z * (1 - _cos)
            );
        }

        template<typename T>
        const matrix::TMatrix3x3<T> rotationXMatrix3x3(const T angle) {
            const T _cos(std::cos(angle));
            const T _sin(std::sin(angle));

            return matrix::TMatrix3x3<T>(
                    1, 0, 0,
                    0, _cos, -_sin,
                    0, _sin, _cos
            );
        }

        template<typename T>
        const matrix::TMatrix3x3<T> rotationYMatrix3x3(const T angle) {
            const T _cos(std::cos(angle));
            const T _sin(std::sin(angle));

            return matrix::TMatrix3x3<T>(
                    _cos, 0, _sin,
                    0, 1, 0,
                    -_sin, 0, _cos
            );
        }


        template<typename T>
        const matrix::TMatrix3x3<T> rotationZMatrix3x3(const T angle) {
            const T _cos(std::cos(angle));
            const T _sin(std::sin(angle));

            return matrix::TMatrix3x3<T>(
                    _cos, -_sin, 0,
                    _sin, _cos, 0,
                    0, 0, 1
            );
        }

        template<typename T>
        const matrix::TMatrix3x3<T> rotationXYZMatrix3x3(const T x_angle, const T y_angle, const T z_angle) {
            const T _cosa(std::cos(x_angle));
            const T _sina(std::sin(x_angle));

            const T _cosb(std::cos(y_angle));
            const T _sinb(std::sin(y_angle));

            const T _cosc(std::cos(z_angle));
            const T _sinc(std::sin(z_angle));

            return matrix::TMatrix3x3<T>(
                    _cosb * _cosc,
                    -_cosb * _sinc,
                    _sinb,

                    _cosc * _sina * _sinb + _cosa * _sinc,
                    _cosa * _cosc - _sina * _sinb * _sinc,
                    -_cosb * _sina,

                    -_cosa * _cosc * _sinb + _sina * _sinc,
                    _cosc * _sina + _cosa * _sinb * _sinc,
                    _cosa * _cosb
            );
        }


        template<typename T>
        const matrix::TMatrix3x3<T> _rotationMatrix3x3(const T angle, const vector::TVector3<T> &axis) {

            T _cos = std::cos(angle);
            T _sin = std::sin(angle);

            matrix::TMatrix3x3<T> m(

                    _cos + axis.x * axis.x * (1 - _cos),
                    axis.x * axis.y * (1 - _cos) - axis.z * _sin,
                    axis.x * axis.z * (1 - _cos) + axis.y * _sin,

                    axis.x * axis.y * (1 - _cos) + axis.z * _sin,
                    _cos + axis.y * axis.y * (1 - _cos),
                    axis.y * axis.z * (1 - _cos) - axis.x * _sin,

                    axis.x * axis.z * (1 - _cos) - axis.y * _sin,
                    axis.y * axis.z * (1 - _cos) + axis.x * _sin,
                    _cos + axis.z * axis.z * (1 - _cos)
            );

            return m;
        }
    }
}


#endif //RMVECTORMATH_TROTATIONMATRIXUTILS_HPP
