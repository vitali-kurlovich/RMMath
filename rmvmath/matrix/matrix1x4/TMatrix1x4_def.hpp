//
// Created by Vitali Kurlovich on 12/19/15.
//

#ifndef RMVECTORMATH_TMATRIX1X4_DEF_HPP
#define RMVECTORMATH_TMATRIX1X4_DEF_HPP

#include "../../vector/vector4x/TVector4_def.hpp"

namespace rmmath {

    namespace matrix {

        template<typename T>
        struct TMatrix1x4 {
            union {
                T m[1*4];
                struct {
                    T m00, m01, m02, m03;
                };
                vector::TVector4<T> row[1];
            };


            TMatrix1x4(const T m00 = 0, const T m01 = 0, const T m02 = 0, const T m03 = 0)
                    : m00(m00), m01(m01), m02(m02), m03(m03)
            {

            }

            TMatrix1x4(const vector::TVector4<T>& row0)
            {
                row[0] = row0;
            }

            const vector::TVector4<T>& operator [] (std::size_t index) const {
                return row[index];
            }

            static const TMatrix1x4<T>& zero() {
                static TMatrix1x4<T> zero;
                return zero;
            }

        };

    }
}


#endif //RMVECTORMATH_TMATRIX1X4_DEF_HPP
