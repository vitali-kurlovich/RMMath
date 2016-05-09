//
// Created by Vitali Kurlovich on 12/19/15.
//

#ifndef RMVECTORMATH_TMATRIX1X3_DEF_HPP
#define RMVECTORMATH_TMATRIX1X3_DEF_HPP

#include "../../vector/vector3x/TVector3_def.hpp"

namespace rmmath {

    namespace matrix {

        template<typename T>
        struct TMatrix1x3 {
            union {
                T m[1*3];
                struct {
                    T m00, m01, m02;
                };
                vector::TVector3<T> row[1];
            };


            TMatrix1x3(const T m00 = 0, const T m01 = 0, const T m02 = 0)
                    : m00(m00), m01(m01), m02(m02)
            {

            }

            TMatrix1x3(const vector::TVector3<T>& row0)
                    : row{row0}
            {

            }

            const vector::TVector3<T>& operator [] (std::size_t index) const {
                return row[index];
            }

            static const TMatrix1x3<T>& zero() {
                static TMatrix1x3<T> zero;
                return zero;
            }

        };

    }
}



#endif //RMVECTORMATH_TMATRIX1X3_DEF_HPP
