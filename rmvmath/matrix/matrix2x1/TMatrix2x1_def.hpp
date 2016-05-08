//
// Created by Vitali Kurlovich on 12/20/15.
//

#ifndef RMVECTORMATH_TMATRIX2X1_DEF_HPP
#define RMVECTORMATH_TMATRIX2X1_DEF_HPP


namespace rmmath {

    namespace matrix {

        template<typename T>
        struct TMatrix2x1 {
            union {
                T m[2*1];
                struct {
                    T m00;
                    T m10;
                };
                T row[2];
            };


            TMatrix2x1(
                    const T m00 = 0,
                    const T m10 = 0)
                    : m00(m00),
                      m10(m10)
            {

            }

            const T operator [] (std::size_t index) const {
                return row[index];
            }

            static const TMatrix2x1<T>& zero() {
                static TMatrix2x1<T> zero;
                return zero;
            }
        };

    }
}

#endif //RMVECTORMATH_TMATRIX2X1_DEF_HPP
