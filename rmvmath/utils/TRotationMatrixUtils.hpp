//
// Created by Vitali Kurlovich on 8/6/16.
//

#ifndef RMVECTORMATH_TROTATIONMATRIXUTILS_HPP
#define RMVECTORMATH_TROTATIONMATRIXUTILS_HPP

#include "../matrix/matrix3x3/TMatrix3x3_def.hpp"
#include "../vector/vector3x/TVector3_def.hpp"

#include <math.h>

#include "../common/trigonometry.hpp"

namespace rmmath {

    template <typename T>
    const matrix::TMatrix3x3<T> rotationMatrix3x3(const T angle, const vector::TVector3<T> &axis) {

        const T _cos(math::cos<T>(angle));
        const T _1_cos(1 - _cos);
        const T _x1_cos(axis.x*_1_cos);
        const T _xy1_cos(axis.y*_x1_cos);

        const T _sin(math::sin<T>(angle));
        const T _sinx(axis.x*_sin);
        const T _siny(axis.y*_sin);
        const T _sinz(axis.z*_sin);

        return matrix::TMatrix3x3<T>(

                _cos + axis.x*_x1_cos,
                _xy1_cos - _sinz,
                axis.z*_x1_cos +_siny,

                _xy1_cos + _sinz,
                axis.y*_xy1_cos + _cos ,
                _xy1_cos*axis.z - _sinx,

                axis.z*_x1_cos - _siny,
                axis.z*_xy1_cos + _sinx,
                _cos + axis.z*axis.z*_1_cos
        );
    }



    template <typename T>
    const matrix::TMatrix3x3<T> rotationXMatrix3x3(const T angle) {
        const T _cos(math::cos<T>(angle));
        const T _sin(math::sin<T>(angle));

        return matrix::TMatrix3x3<T>(
                1, 0, 0,
                0, _cos, -_sin,
                0, _sin, _cos
        );
    }

    template <typename T>
    const matrix::TMatrix3x3<T> rotationYMatrix3x3(const T angle) {
        const T _cos(math::cos<T>(angle));
        const T _sin(math::sin<T>(angle));

        return matrix::TMatrix3x3<T>(
                 _cos, 0, _sin,
                    0, 1,    0,
                -_sin, 0, _cos
        );
    }


    template <typename T>
    const matrix::TMatrix3x3<T> rotationZMatrix3x3(const T angle) {
        const T _cos(math::cos<T>(angle));
        const T _sin(math::sin<T>(angle));

        return matrix::TMatrix3x3<T>(
                _cos, -_sin, 0,
                _sin, _cos, 0,
                0, 0, 1
        );
    }

    template <typename T>
    const matrix::TMatrix3x3<T> rotationXYZMatrix3x3(const T x_angle, const T y_angle, const T z_angle) {
        const T _cosa(math::cos<T>(x_angle));
        const T _sina(math::sin<T>(x_angle));

        const T _cosb(math::cos<T>(y_angle));
        const T _sinb(math::sin<T>(y_angle));

        const T _cosc(math::cos<T>(z_angle));
        const T _sinc(math::sin<T>(z_angle));

        return matrix::TMatrix3x3<T>(
                _cosb*_cosc,
                -_cosb*_sinc,
                _sinb,

                _cosc*_sina*_sinb + _cosa*_sinc,
                _cosa*_cosc - _sina*_sinb*_sinc,
                -_cosb*_sina,

                -_cosa*_cosc*_sinb + _sina*_sinc,
                _cosc*_sina +_cosa*_sinb*_sinc,
                _cosa*_cosb
        );
    }


    template <typename T>
    const matrix::TMatrix3x3<T> _rotationMatrix3x3(const T angle, const vector::TVector3<T> &axis) {

        T _cos = cos(angle);
        T _sin = sin(angle);

        matrix::TMatrix3x3<T> m (

                _cos + axis.x*axis.x*(1 - _cos),
                axis.x*axis.y*(1 - _cos) - axis.z*_sin,
                axis.x*axis.z*(1 - _cos) + axis.y*_sin,

                axis.x*axis.y*(1 - _cos) + axis.z*_sin,
                _cos + axis.y*axis.y*(1 - _cos),
                axis.y*axis.z*(1 - _cos) - axis.x*_sin,

                axis.x*axis.z*(1 - _cos) - axis.y*_sin,
                axis.y*axis.z*(1 - _cos) + axis.x*_sin,
                _cos + axis.z*axis.z*(1 - _cos)
        );

        return m;
    }
}


#endif //RMVECTORMATH_TROTATIONMATRIXUTILS_HPP
