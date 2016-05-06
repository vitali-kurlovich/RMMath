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

                struct {
                    T m00, m01, m02, m03;
                    T m10, m11, m12, m13;
                    T m20, m21, m22, m23;
                    T m30, m31, m32, m33;
                };

                struct {
                    vector::TVector4<T> row0;
                    vector::TVector4<T> row1;
                    vector::TVector4<T> row2;
                    vector::TVector4<T> row3;
                };
            };

            TMatrix4x4(
                    const T m00 = 1, const T m01 = 0, const T m02 = 0, const T m03 = 0,
                    const T m10 = 0, const T m11 = 1, const T m12 = 0, const T m13 = 0,
                    const T m20 = 0, const T m21 = 0, const T m22 = 1, const T m23 = 0,
                    const T m30 = 0, const T m31 = 0, const T m32 = 0, const T m33 = 1)
            : m00(m00), m01(m01), m02(m02), m03(m03),
              m10(m10), m11(m11), m12(m12), m13(m13),
              m20(m20), m21(m21), m22(m22), m23(m23),
              m30(m30), m31(m31), m32(m32), m33(m33)
            {

            }

            TMatrix4x4(const vector::TVector4<T>& row0,
                       const vector::TVector4<T>& row1 = vector::TVector4<T>(0, 1, 0, 0),
                       const vector::TVector4<T>& row2 = vector::TVector4<T>(0, 0, 1, 0),
                       const vector::TVector4<T>& row3 = vector::TVector4<T>(0, 0, 0, 1))
            : row0(row0), row1(row1),row2(row2),row3(row3)
            {

            }

        };

    }
}

#endif //RMVECTORMATH_TMATRIX4X4_DEF_HPP
