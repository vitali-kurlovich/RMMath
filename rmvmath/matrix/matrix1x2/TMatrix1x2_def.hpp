//
// Created by Vitali Kurlovich on 12/12/15.
//

#ifndef RMVECTORMATH_TMATRIX1X2_DEF_HPP
#define RMVECTORMATH_TMATRIX1X2_DEF_HPP

#include "../../vector/vector2x/TVector2_def.hpp"

namespace rmmath {

    namespace matrix {

        template<typename T>
        struct TMatrix1x2 {
            union {
                T m[1*2];
                struct {
                    T m00, m01;
                };
                vector::TVector2<T> row[1];
            };


            TMatrix1x2(const T m00 = 0, const T m01 = 0)
                    : m00(m00), m01(m01)
            {

            }

            TMatrix1x2(const vector::TVector2<T>& row0)
            {
                row[0] = row0;
            }

            const vector::TVector2<T>& operator [] (std::size_t index) const {
                return row[index];
            }

            static const TMatrix1x2<T>& zero() {
                static TMatrix1x2<T> zero;
                return zero;
            }

        };

    }
}

#endif //RMVECTORMATH_TMATRIX1X2_DEF_HPP
