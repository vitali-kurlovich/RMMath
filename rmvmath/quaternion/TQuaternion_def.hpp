//
// Created by Vitali Kurlovich on 4/4/16.
//

#ifndef RMVECTORMATH_TQUATERNION_DEF_HPP
#define RMVECTORMATH_TQUATERNION_DEF_HPP


namespace rmmath {

    namespace quaternion {

        template<typename T>
        struct TQuaternion {
            T w, x, y, z;

            TQuaternion( const T w = 0, const T x = 0, const T y = 0, const T z = 0  ) :
                    w(w), x(x), y(y), z(z)
            {}


            TQuaternion( const TQuaternion& other ) :
                    w(other.w), x(other.x), y(other.y), z(other.z)
            {}

        };
    }
}

#endif //RMVECTORMATH_TQUATERNION_DEF_HPP
