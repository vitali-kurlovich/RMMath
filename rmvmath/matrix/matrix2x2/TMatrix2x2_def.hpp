//
// Created by Vitali Kurlovich on 12/12/15.
//

#ifndef RMVECTORMATH_TMATRIX2X2_DEF_HPP
#define RMVECTORMATH_TMATRIX2X2_DEF_HPP

#include "../../vector/TVector2.hpp"

namespace rmmath {

    namespace matrix {

        template<typename T>
        struct TMatrix2x2 {
            union {
                T m[2*2];
                struct {
                    T m00, m01;
                    T m10, m11;
                };
                vector::TVector2<T> row[2];
            };


            TMatrix2x2(
                    const T m00 = 0, const T m01 = 0,
                    const T m10 = 0, const T m11 = 0)
                    : m00(m00), m01(m01),
                      m10(m10), m11(m11)
            {

            }

            TMatrix2x2(const vector::TVector2<T>& row0,
                       const vector::TVector2<T>& row1 = vector::TVector2<T>::zero())
            {
                row[0] = row0;
                row[1] = row1;
            }

            const vector::TVector2<T>& operator [] (std::size_t index) const {
                return row[index];
            }

            static const TMatrix2x2<T>& zero() {
                static TMatrix2x2<T> zero;
                return zero;
            }

            static const TMatrix2x2<T>& identity() {
                static TMatrix2x2<T> identity(
                        1, 0,
                        0, 1
                );
                return identity;
            }
        };
    }
}

#endif //RMVECTORMATH_TMATRIX2X2_DEF_HPP
