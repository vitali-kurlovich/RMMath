//
// Created by Vitali Kurlovich on 12/19/15.
//

#ifndef RMVECTORMATH_TMATRIX4X2_DEF_HPP
#define RMVECTORMATH_TMATRIX4X2_DEF_HPP

#include "../../vector/vector2x/TVector2_def.hpp"

namespace rmmath {

    namespace matrix {

        template<typename T>
        struct TMatrix4x2 {
            union {
                T m[4*2];
                struct {
                    T m00, m01;
                    T m10, m11;
                    T m20, m21;
                    T m30, m31;
                };
                vector::TVector2<T> row[4];
            };


            TMatrix4x2(
                    const T m00 = 0, const T m01 = 0,
                    const T m10 = 0, const T m11 = 0,
                    const T m20 = 0, const T m21 = 0,
                    const T m30 = 0, const T m31 = 0)
                    : m00(m00), m01(m01),
                      m10(m10), m11(m11),
                      m20(m20), m21(m21),
                      m30(m30), m31(m31)
            {

            }

            TMatrix4x2(const vector::TVector2<T>& row0,
                       const vector::TVector2<T>& row1 = vector::TVector2<T>(0, 0),
                       const vector::TVector2<T>& row2 = vector::TVector2<T>(0, 0),
                       const vector::TVector2<T>& row3 = vector::TVector2<T>(0, 0))
            {
                row[0] = row0;
                row[1] = row1;
                row[2] = row2;
                row[3] = row3;
            }



            const vector::TVector2<T>& operator [] (std::size_t index) const {
                return row[index];
            }

            static const TMatrix4x2<T>& zero() {
                static TMatrix4x2<T> zero;
                return zero;
            }



        };

    }
}

/*

 {{m00, m01},
 {m10, m11},
 {m20, m21},
 {m30, m31}}

 */

#endif //RMVECTORMATH_TMATRIX4X2_DEF_HPP
