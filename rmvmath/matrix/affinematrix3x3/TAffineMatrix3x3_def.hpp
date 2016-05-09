//
// Created by Vitali Kurlovich on 1/10/16.
//

#ifndef RMVECTORMATH_TAFFINEMATRIX3X3_DEF_HPP
#define RMVECTORMATH_TAFFINEMATRIX3X3_DEF_HPP

#include "../../vector/vector2x/TVector2_def.hpp"

namespace rmmath {

    namespace matrix {

        /*
            T m00, m01, 0;
            T m10, m11, 0;
            T m20, m21, 1;

         */

        template<typename T>
        struct TAffineMatrix3x3 {
            union {
                T m[3*2];
                struct {
                    T m00, m01;
                    T m10, m11;
                    T m20, m21;
                };
                vector::TVector2<T> row[3];
            };

            TAffineMatrix3x3(
                    const T m00 = 0, const T m01 = 0,
                    const T m10 = 0, const T m11 = 0,
                    const T m20 = 0, const T m21 = 0)
                    : m00(m00), m01(m01),
                      m10(m10), m11(m11),
                      m20(m20), m21(m21)
            {

            }

            TAffineMatrix3x3(const vector::TVector2<T>& row0,
                       const vector::TVector2<T>& row1 = vector::TVector2<T>(0, 0),
                       const vector::TVector2<T>& row2 = vector::TVector2<T>(0, 0))
            {
                row[0] = row0;
                row[1] = row1;
                row[2] = row2;
            }



            const vector::TVector2<T>& operator [] (std::size_t index) const {
                return row[index];
            }

            static const TAffineMatrix3x3<T>& zero() {
                static TAffineMatrix3x3<T> zero;
                return zero;
            }

        };

    }
}


#endif //RMVECTORMATH_TAFFINEMATRIX3X3_DEF_HPP
