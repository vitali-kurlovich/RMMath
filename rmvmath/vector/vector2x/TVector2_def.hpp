//
// Created by Vitali Kurlovich on 12/11/15.
//

#ifndef RMVECTORMATH_TVECTOR2_DEF_HPP
#define RMVECTORMATH_TVECTOR2_DEF_HPP


namespace rmmath {

    namespace vector {

        template<typename T>
        struct TVector2 {
            union {
                struct {
                    T x, y;
                };
                T v[2];
            };

            TVector2(const T x = 0, const T y = 0)
                    : x(x), y(y)
            {

            }


            const T operator [] (std::size_t index) const {
                return v[index];
            }

            static const TVector2<T>& zero() {
                static TVector2<T> zero;
                return zero;
            }

        };

    }
}


#endif //RMVECTORMATH_TVECTOR2_DEF_HPP
