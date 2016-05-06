//
// Created by Vitali Kurlovich on 1/20/16.
//

#ifndef RMVECTORMATH_TAFFINEVECTOR4_DEF_HPP
#define RMVECTORMATH_TAFFINEVECTOR4_DEF_HPP


#include "../vector3x/TVector3_def.hpp"
#include "../vector2x/TVector2_def.hpp"

namespace rmmath {

    namespace vector {

        /*
         * T x, y, z, 1;
         */

        template<typename T>
        struct TAffineVector4 {
            union {
                struct {
                    T x, y, z;
                };

                TVector3 <T> xyz;
                TVector2 <T> xy;
            };


            TAffineVector4(const T x = 0, const T y = 0, const  T z = 0)
                    : x(x), y(y), z(z)
            {

            }


            TAffineVector4(const TVector2<T>& other, const T z)
                    : x(other.x), y(other.y), z(z)
            {

            }
        };

    }
}

#endif //RMVECTORMATH_TAFFINEVECTOR4_DEF_HPP
