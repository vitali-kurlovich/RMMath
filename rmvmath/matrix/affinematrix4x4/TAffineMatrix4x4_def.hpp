//
// Created by Vitali Kurlovich on 1/8/16.
//

#ifndef RMVECTORMATH_TAFFINEMATRIX4X4_DEF_HPP
#define RMVECTORMATH_TAFFINEMATRIX4X4_DEF_HPP

#include "../../vector/vector3x/TVector3_def.hpp"

namespace rmmath {

    namespace matrix {

        /*
            T m00, m01, m02, 0;
            T m10, m11, m12, 0;
            T m20, m21, m22, 0;
            T m30, m31, m32, 1;
         */

        template<typename T>
        struct TAffineMatrix4x4 {
            union {
                T m[4*3];
                struct {
                    T m00, m01, m02;
                    T m10, m11, m12;
                    T m20, m21, m22;
                    T m30, m31, m32;
                };
                vector::TVector3<T> row[4];
            };


            TAffineMatrix4x4(
                    const T m00 = 0, const T m01 = 0, const T m02 = 0,
                    const T m10 = 0, const T m11 = 0, const T m12 = 0,
                    const T m20 = 0, const T m21 = 0, const T m22 = 0,
                    const T m30 = 0, const T m31 = 0, const T m32 = 0) noexcept
                    : m00(m00), m01(m01), m02(m02),
                      m10(m10), m11(m11), m12(m12),
                      m20(m20), m21(m21), m22(m22),
                      m30(m30), m31(m31), m32(m32)
            {

            }

            TAffineMatrix4x4(const vector::TVector3<T>& row0,
                       const vector::TVector3<T>& row1 = vector::TVector3<T>(0, 0, 0),
                       const vector::TVector3<T>& row2 = vector::TVector3<T>(0, 0, 0),
                       const vector::TVector3<T>& row3 = vector::TVector3<T>(0, 0, 0)) noexcept
            {
                row[0] = row0;
                row[1] = row1;
                row[2] = row2;
                row[3] = row3;
            }


            const vector::TVector3<T>& operator [] (std::size_t index) const noexcept {
                return row[index];
            }

            static const TAffineMatrix4x4<T>& zero() noexcept {
                static TAffineMatrix4x4<T> zero;
                return zero;
            }

            static const TAffineMatrix4x4<T>& identity() noexcept {
                static TAffineMatrix4x4<T> identity(
                        1, 0, 0,
                        0, 1, 0,
                        0, 0, 1,
                        0, 0, 0
                );
                return identity;
            }

        };

    }
}

#endif //RMVECTORMATH_TAFFINEMATRIX4X4_DEF_HPP
