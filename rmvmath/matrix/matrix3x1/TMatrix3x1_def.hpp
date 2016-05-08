//
// Created by Vitali Kurlovich on 12/20/15.
//

#ifndef RMVECTORMATH_TMATRIX3X1_DEF_HPP
#define RMVECTORMATH_TMATRIX3X1_DEF_HPP

namespace rmmath {

    namespace matrix {

        template<typename T>
        struct TMatrix3x1 {
            union {
                T m[3*1];
                struct {
                    T m00;
                    T m10;
                    T m20;
                };
                T row[3];
            };


            TMatrix3x1(
                    const T m00 = 0,
                    const T m10 = 0,
                    const T m20 = 0)
                    : m00(m00),
                      m10(m10),
                      m20(m20)
            {

            }

            const T operator [] (std::size_t index) const {
                return row[index];
            }

            static const TMatrix3x1<T>& zero() {
                static TMatrix3x1<T> zero;
                return zero;
            }
        };

    }

}

#endif //RMVECTORMATH_TMATRIX3X1_DEF_HPP
