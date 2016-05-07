//
// Created by Vitali Kurlovich on 12/16/15.
//

#ifndef RMVECTORMATH_TMATRIX4X3_DEF_HPP
#define RMVECTORMATH_TMATRIX4X3_DEF_HPP


#include "../../vector/vector3x/TVector3_def.hpp"

namespace rmmath {

    namespace matrix {

        template<typename T>
        struct TMatrix4x3 {
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

            TMatrix4x3(
                    const T m00 = 0, const T m01 = 0, const T m02 = 0,
                    const T m10 = 0, const T m11 = 0, const T m12 = 0,
                    const T m20 = 0, const T m21 = 0, const T m22 = 0,
                    const T m30 = 0, const T m31 = 0, const T m32 = 0)
                    : m00(m00), m01(m01), m02(m02),
                      m10(m10), m11(m11), m12(m12),
                      m20(m20), m21(m21), m22(m22),
                      m30(m30), m31(m31), m32(m32)
            {

            }

            TMatrix4x3(const vector::TVector3<T>& row0,
                       const vector::TVector3<T>& row1 = vector::TVector3<T>(0, 0, 0),
                       const vector::TVector3<T>& row2 = vector::TVector3<T>(0, 0, 0),
                       const vector::TVector3<T>& row3 = vector::TVector3<T>(0, 0, 0))
            {
                row[0] = row0;
                row[1] = row1;
                row[2] = row2;
                row[3] = row3;
            }


            const vector::TVector3<T>& operator [] (std::size_t index) const {
                return row[index];
            }

            static const TMatrix4x3<T>& zero() {
                static TMatrix4x3<T> zero;
                return zero;
            }

        };

    }
}




#endif //RMVECTORMATH_TMATRIX4X3_DEF_HPP
