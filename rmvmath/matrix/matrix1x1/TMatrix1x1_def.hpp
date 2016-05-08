//
// Created by Vitali Kurlovich on 12/20/15.
//

#ifndef RMVECTORMATH_TMATRIX1X1_DEF_HPP
#define RMVECTORMATH_TMATRIX1X1_DEF_HPP


namespace rmmath {

    namespace matrix {

        template<typename T>
        struct TMatrix1x1 {
            union {
                T m[1*1];
                struct {
                    T m00;
                };
                T row[1];
            };


            TMatrix1x1(const T m00 = 0)
                    : m00(m00)
            {

            }

            const T operator [] (std::size_t index) const {
                return row[index];
            }

            static const TMatrix1x1<T>& zero() {
                static TMatrix1x1<T> zero;
                return zero;
            }

            static const TMatrix1x1<T>& identity() {
                static TMatrix1x1<T> identity(1);
                return identity;
            }
        };

    }
}

#endif //RMVECTORMATH_TMATRIX1X1_DEF_HPP
