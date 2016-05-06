//
// Created by Vitali Kurlovich on 1/20/16.
//

#ifndef RMVECTORMATH_TAFFINEVECTOR3_DEF_HPP
#define RMVECTORMATH_TAFFINEVECTOR3_DEF_HPP

#include "../vector2x/TVector2_def.hpp"

namespace rmmath {

    namespace vector {

        /*
         *  T x, y, 1;
         */


        template<typename T>
        struct TAffineVector3 {
            union {
                struct {
                    T x, y;
                };

                TVector2 <T> xy;
            };


            TAffineVector3(const T x = 0, const T y = 0)
                    : x(x), y(y)
            {

            }

        };

    }
}


#endif //RMVECTORMATH_TAFFINEVECTOR3_DEF_HPP
