//
// Created by Vitali Kurlovich on 4/4/16.
//

#ifndef RMVECTORMATH_TQUATERNION_DEF_HPP
#define RMVECTORMATH_TQUATERNION_DEF_HPP


#include "../vector/vector3x/TVector3_def.hpp"

namespace rmmath {

    namespace quaternion {

        template<typename T>
        struct TQuaternion {

            union {
                struct {
                    T w, x, y, z;
                };

                struct {
                    T real;
                    vector::TVector3 <T> xyz;
                };

            };


            TQuaternion( const T w = 0, const T x = 0, const T y = 0, const T z = 0 )
                    : w(w), x(x), y(y), z(z)
            {}

            TQuaternion( const T w, const vector::TVector3<T>& vec )
                    : w(w), x(vec.x), y(vec.y), z(vec.z)
            {}

            TQuaternion( const vector::TVector3<T>& vec, const T w = 0 )
                    : w(w), x(vec.x), y(vec.y), z(vec.z)
            {}
        };
    }
}

#endif //RMVECTORMATH_TQUATERNION_DEF_HPP
