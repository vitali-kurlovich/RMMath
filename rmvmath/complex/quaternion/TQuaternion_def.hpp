//
// Created by Vitali Kurlovich on 4/4/16.
//

#ifndef RMVECTORMATH_TQUATERNION_DEF_HPP
#define RMVECTORMATH_TQUATERNION_DEF_HPP


#include "vector/vector3x/TVector3_def.hpp"

#include "../iquaternion/TIdentityQuaternion_def.hpp"

namespace rmmath {

    namespace complex {

        template<typename T>
        struct TQuaternion {

            union {
                struct {
                    T w, i, j, k;
                };

                struct {
                     T re;
                     vector::TVector3 <T> im;
                };
            };

            TQuaternion( const T w = 0, const T i = 0, const T j = 0, const T k = 0 )
                    : w(w), i(i), j(j), k(k)
            {}

            TQuaternion( const T w, const vector::TVector3<T>& vec )
                    : re(w), im(vec)
            {}

            TQuaternion( const vector::TVector3<T>& vec, const T w = 0 )
                    : re(w), im(vec)
            {}

            TQuaternion(const TIdentityQuaternion<T>& iquat)
            :re(iquat.re), im(iquat.im)
            {

            }

            static const TQuaternion<T>& zero() {
                static TQuaternion<T> zero;
                return zero;
            }
        };
    }
}

#endif //RMVECTORMATH_TQUATERNION_DEF_HPP
