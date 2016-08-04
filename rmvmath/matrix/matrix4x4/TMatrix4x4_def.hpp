//
// Created by Vitali Kurlovich on 12/12/15.
//

#ifndef RMVECTORMATH_TMATRIX4X4_DEF_HPP
#define RMVECTORMATH_TMATRIX4X4_DEF_HPP

#include "../../vector/vector4x/TVector4_def.hpp"

namespace rmmath {

    namespace matrix {

        template<typename T>
        struct TMatrix4x4 {
            union {

                T m[4*4];
                struct {
                    T m00, m01, m02, m03;
                    T m10, m11, m12, m13;
                    T m20, m21, m22, m23;
                    T m30, m31, m32, m33;
                };
                vector::TVector4<T> row[4];
            };

            constexpr
            TMatrix4x4(
                    const T m00 = 0, const T m01 = 0, const T m02 = 0, const T m03 = 0,
                    const T m10 = 0, const T m11 = 0, const T m12 = 0, const T m13 = 0,
                    const T m20 = 0, const T m21 = 0, const T m22 = 0, const T m23 = 0,
                    const T m30 = 0, const T m31 = 0, const T m32 = 0, const T m33 = 0) noexcept
            : m00(m00), m01(m01), m02(m02), m03(m03),
              m10(m10), m11(m11), m12(m12), m13(m13),
              m20(m20), m21(m21), m22(m22), m23(m23),
              m30(m30), m31(m31), m32(m32), m33(m33)
            {
            }

            constexpr
            TMatrix4x4(const vector::TVector4<T>& row0,
                       const vector::TVector4<T>& row1 = vector::TVector4<T>::zero(),
                       const vector::TVector4<T>& row2 = vector::TVector4<T>::zero(),
                       const vector::TVector4<T>& row3 = vector::TVector4<T>::zero()) noexcept
            : row{row0, row1, row2, row3}
            {
            }

            constexpr
            const vector::TVector4<T>& operator [] (std::size_t index) const noexcept {
                return row[index];
            }

            static const TMatrix4x4<T>& zero() noexcept {
                static TMatrix4x4<T> zero(
                        0, 0, 0, 0,
                        0, 0, 0, 0,
                        0, 0, 0, 0,
                        0, 0, 0, 0);
                return zero;
            }

            static const TMatrix4x4<T>& identity() noexcept {
                static TMatrix4x4<T> identity(
                        1, 0, 0, 0,
                        0, 1, 0, 0,
                        0, 0, 1, 0,
                        0, 0, 0, 1
                );
                return identity;
            }

        };

    }
}

#endif //RMVECTORMATH_TMATRIX4X4_DEF_HPP
