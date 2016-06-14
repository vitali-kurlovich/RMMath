//
// Created by Vitali Kurlovich on 5/15/16.
//

#ifndef RMVECTORMATH_TIDENTITYQUATERNION_DEF_HPP
#define RMVECTORMATH_TIDENTITYQUATERNION_DEF_HPP

#include "vector/vector3x/TVector3_def.hpp"

namespace rmmath {

    namespace complex {

        template<typename T>
        struct TIdentityQuaternion {

            union {
                struct {
                    const T w, i, j, k;
                };

                struct {
                    const T re;
                    const vector::TVector3 <T> im;
                };
            };

            TIdentityQuaternion( const T w = 0, const T i = 0, const T j = 0, const T k = 0 )
                    : w(w), i(i), j(j), k(k)
            {
                assert(abs(w*w + i*i + j*j + k*k - 1) < 0.0001);
            }

            TIdentityQuaternion( const T w, const vector::TVector3<T>& vec )
                    : re(w), im(vec)
            {
                assert(abs(w*w + i*i + j*j + k*k - 1) < 0.0001);
            }

            TIdentityQuaternion( const vector::TVector3<T>& vec)
                    : re(0), im(vec)
            {
                assert(abs(w*w + i*i + j*j + k*k - 1) < 0.0001);
            }

            static const TIdentityQuaternion<T>& identity() {
                static TIdentityQuaternion<T> identity(0, 1, 0, 0);
                return identity;
            }

            TIdentityQuaternion()
            :re(0), im(TIdentityQuaternion::identity().im)
            {

            }
        };
    }
}


#endif //RMVECTORMATH_TIDENTITYQUATERNION_DEF_HPP
