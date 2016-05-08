//
// Created by Vitali Kurlovich on 12/19/15.
//

#ifndef RMVECTORMATH_TMATRIX4X1_DEF_HPP
#define RMVECTORMATH_TMATRIX4X1_DEF_HPP

#include "../../vector/vector4x/TVector4_def.hpp"

namespace rmmath {

    namespace matrix {

        template<typename T>

        struct TMatrix4x1 {
            union {
                T m[4*1];
                struct {
                    T m00;
                    T m10;
                    T m20;
                    T m30;
                };
                T row[4];
            };


            TMatrix4x1(
                    const T m00 = 0,
                    const T m10 = 0,
                    const T m20 = 0,
                    const T m30 = 0)
                    : m00(m00),
                      m10(m10),
                      m20(m20),
                      m30(m30)
            {

            }

            const T operator [] (std::size_t index) const {
                return row[index];
            }

            static const TMatrix4x1<T>& zero() {
                static TMatrix4x1<T> zero;
                return zero;
            }

        };

    }
}

/*

 {{m00},
 {m10},
 {m20},
 {m30}}

 */

#endif //RMVECTORMATH_TMATRIX4X1_DEF_HPP
