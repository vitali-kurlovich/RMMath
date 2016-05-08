//
// Created by Vitali Kurlovich on 12/19/15.
//

#ifndef RMVECTORMATH_TMATRIX2X3_DEF_HPP
#define RMVECTORMATH_TMATRIX2X3_DEF_HPP


#include "../../vector/vector3x/TVector3_def.hpp"

namespace rmmath {

    namespace matrix {

        template<typename T>
        struct TMatrix2x3 {
            union {
                T m[2 * 3];
                struct {
                    T m00, m01, m02;
                    T m10, m11, m12;
                };
                vector::TVector3 <T> row[2];
            };


            TMatrix2x3(
                    const T m00 = 0, const T m01 = 0, const T m02 = 0,
                    const T m10 = 0, const T m11 = 0, const T m12 = 0)
                    : m00(m00), m01(m01), m02(m02),
                      m10(m10), m11(m11), m12(m12) {

            }

            TMatrix2x3(const vector::TVector3 <T> &row0,
                       const vector::TVector3 <T> &row1 = vector::TVector3<T>(0, 0, 0)) {
                row[0] = row0;
                row[1] = row1;
            }

            const vector::TVector3 <T> &operator[](std::size_t index) const {
                return row[index];
            }

            static const TMatrix2x3<T> &zero() {
                static TMatrix2x3<T> zero;
                return zero;
            }
        };

    }
}



#endif //RMVECTORMATH_TMATRIX2X3_DEF_HPP
