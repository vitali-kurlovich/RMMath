//
// Created by Vitali Kurlovich on 12/11/15.
//

#ifndef RMVECTORMATH_TVECTOR3_DEF_HPP
#define RMVECTORMATH_TVECTOR3_DEF_HPP


#include "../vector2x/TVector2_def.hpp"

#include "../affinevector3x/TAffineVector3_def.hpp"

namespace rmmath {

    namespace vector {


        template<typename T>
        struct TVector3 {
            union {
                struct {
                    T x, y, z;
                };

                TVector2 <T> xy;
            };

            TVector3(const T x = 0, const T y = 0, const  T z = 0)
                    : x(x), y(y), z(z)
            {

            }

            TVector3(const TVector3<T>& other)
                    : x(other.x), y(other.y), z(other.z)
            {

            }

            TVector3(const TAffineVector3<T>& other)
                    : x(other.x), y(other.y), z(1)
            {

            }

        };

    }
}


#endif //RMVECTORMATH_TVECTOR3_DEF_HPP
