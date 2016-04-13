//
// Created by Vitali Kurlovich on 4/4/16.
//

#ifndef RMVECTORMATH_TQUATERNION_DEF_HPP
#define RMVECTORMATH_TQUATERNION_DEF_HPP


namespace rmmath {

    namespace quaternion {

        template<typename T>
        struct TQuaternion {
            T q, x, y, z;

            TQuaternion( const T q = 0, const T x = 0, const T y = 0, const T z = 0  ) :
                    q(q), x(x), y(y), z(z)
            {}


            TQuaternion( const TQuaternion& other ) :
                    q(other.q), x(other.x), y(other.y), z(other.z)
            {}

        };
    }
}

#endif //RMVECTORMATH_TQUATERNION_DEF_HPP
