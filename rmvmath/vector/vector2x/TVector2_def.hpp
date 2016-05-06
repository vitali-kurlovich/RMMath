//
// Created by Vitali Kurlovich on 12/11/15.
//

#ifndef RMVECTORMATH_TVECTOR2_DEF_HPP
#define RMVECTORMATH_TVECTOR2_DEF_HPP


namespace rmmath {

    namespace vector {

        template<typename T>
        struct TVector2 {
            T x, y;


            TVector2(const T x = 0, const T y = 0)
                    : x(x), y(y)
            {

            }

            TVector2(const TVector2<T>& other)
                    : x(other.x), y(other.y)
            {

            }

        };

    }
}


#endif //RMVECTORMATH_TVECTOR2_DEF_HPP
