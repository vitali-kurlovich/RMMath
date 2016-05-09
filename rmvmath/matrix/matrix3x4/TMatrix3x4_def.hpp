//
// Created by Vitali Kurlovich on 12/16/15.
//

#ifndef RMVECTORMATH_TMATRIX3X4_DEF_HPP
#define RMVECTORMATH_TMATRIX3X4_DEF_HPP


#include "../../vector/vector4x/TVector4_def.hpp"

namespace rmmath {

    namespace matrix {

        template<typename T>
        struct TMatrix3x4 {

            union {
                T m[3*4];
                struct {
                    T m00, m01, m02, m03;
                    T m10, m11, m12, m13;
                    T m20, m21, m22, m23;
                };
                vector::TVector4<T> row[3];
            };

            TMatrix3x4(
                    const T m00 = 0, const T m01 = 0, const T m02 = 0, const T m03 = 0,
                    const T m10 = 0, const T m11 = 0, const T m12 = 0, const T m13 = 0,
                    const T m20 = 0, const T m21 = 0, const T m22 = 0, const T m23 = 0)
                    : m00(m00), m01(m01), m02(m02), m03(m03),
                      m10(m10), m11(m11), m12(m12), m13(m13),
                      m20(m20), m21(m21), m22(m22), m23(m23)
            {

            }

            TMatrix3x4(const vector::TVector4<T>& row0,
                       const vector::TVector4<T>& row1 = vector::TVector4<T>::zero(),
                       const vector::TVector4<T>& row2 = vector::TVector4<T>::zero())
            {
                row[0] = row0;
                row[1] = row1;
                row[2] = row2;
            }

            const vector::TVector4<T>& operator [] (std::size_t index) const {
                return row[index];
            }

            static const TMatrix3x4<T>& zero() {
                static TMatrix3x4<T> zero;
                return zero;
            }


        };

    }
}

#endif //RMVECTORMATH_TMATRIX3X4_DEF_HPP
