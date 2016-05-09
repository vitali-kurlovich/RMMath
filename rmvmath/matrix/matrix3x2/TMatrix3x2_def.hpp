//
// Created by Vitali Kurlovich on 12/19/15.
//

#ifndef RMVECTORMATH_TMATRIX3X2_DEF_HPP
#define RMVECTORMATH_TMATRIX3X2_DEF_HPP

#include "../../vector/vector2x/TVector2_def.hpp"

namespace rmmath {

    namespace matrix {

        template<typename T>
        struct TMatrix3x2 {
            union {
                T m[3*2];
                struct {
                    T m00, m01;
                    T m10, m11;
                    T m20, m21;
                };
                vector::TVector2<T> row[3];
            };


            TMatrix3x2(
                    const T m00 = 0, const T m01 = 0,
                    const T m10 = 0, const T m11 = 0,
                    const T m20 = 0, const T m21 = 0)
                    : m00(m00), m01(m01),
                      m10(m10), m11(m11),
                      m20(m20), m21(m21)
            {

            }

            TMatrix3x2(const vector::TVector2<T>& row0,
                       const vector::TVector2<T>& row1 = vector::TVector2<T>::zero(),
                       const vector::TVector2<T>& row2 = vector::TVector2<T>::zero())
                    : row{row0, row1, row2}
            {

            }



            const vector::TVector2<T>& operator [] (std::size_t index) const {
                return row[index];
            }

            static const TMatrix3x2<T>& zero() {
                static TMatrix3x2<T> zero;
                return zero;
            }


        };

    }

}

#endif //RMVECTORMATH_TMATRIX3X2_DEF_HPP
