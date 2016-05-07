//
// Created by Vitali Kurlovich on 12/11/15.
//

#ifndef RMVECTORMATH_TVECTOR4_DEF_HPP
#define RMVECTORMATH_TVECTOR4_DEF_HPP


#include "../vector3x/TVector3_def.hpp"
#include "../vector2x/TVector2_def.hpp"

#include "../affinevector4x/TAffineVector4_def.hpp"

namespace rmmath {

    namespace vector {

        template<typename T>
        struct TVector4 {
            union {
                struct {
                    T x, y, z, w;
                };

                T v[4];
                TVector3 <T> xyz;
                TVector2 <T> xy;
            };

            TVector4(const T x = 0, const T y = 0, const  T z = 0, const T w = 0)
            : x(x), y(y), z(z), w(w)
            {

            }

            TVector4(const TVector3<T>& other, const T w)
                    : x(other.x), y(other.y), z(other.z), w(w)
            {

            }

            TVector4(const TVector2<T>& other, const T z, const T w)
                    : x(other.x), y(other.y), z(z), w(w)
            {

            }

            TVector4(const TAffineVector4<T>& other)
                    : x(other.x), y(other.y), z(other.z), w(1)
            {

            }

            static const TVector4<T>& zero() {
                static TVector4<T> zero;
                return zero;
            }

        };

    }
}


#endif //RMVECTORMATH_TVECTOR4_DEF_HPP
