//
// Created by Vitali Kurlovich on 4/4/16.
//

#ifndef RMVECTORMATH_TQUATERNION_DEF_HPP
#define RMVECTORMATH_TQUATERNION_DEF_HPP


#include "vector/TVector3.hpp"
#include "vector/TVector4.hpp"

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
                     vector::TVector3<T> im;
                };

                vector::TVector4<T> wijk;
            };

            constexpr
            TQuaternion( const T w = 0, const T i = 0, const T j = 0, const T k = 0 ) noexcept
                    : w(w), i(i), j(j), k(k)
            {}

            constexpr
            TQuaternion( const T w, const vector::TVector3<T>& vec )  noexcept
                    : re(w), im(vec)
            {}

            constexpr
            TQuaternion( const vector::TVector3<T>& vec, const T w = 0 ) noexcept
                    : re(w), im(vec)
            {}

            constexpr
            TQuaternion(const TIdentityQuaternion<T>& iquat) noexcept
            :re(iquat.re), im(iquat.im)
            {}

            static const TQuaternion<T>& zero() {
                static TQuaternion<T> zero;
                return zero;
            }


            static const TQuaternion<T>& identity() {
                static TQuaternion<T> identity(0, 1, 0, 0);
                return identity;
            }
        };
    }
}

#endif //RMVECTORMATH_TQUATERNION_DEF_HPP
