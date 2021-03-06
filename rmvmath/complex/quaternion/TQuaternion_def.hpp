//
// Created by Vitali Kurlovich on 4/4/16.
//

#ifndef RMVECTORMATH_TQUATERNION_DEF_HPP
#define RMVECTORMATH_TQUATERNION_DEF_HPP

#include "../../common/common.hpp"

#include "../../vector/vector3x/TVector3_def.hpp"
#include "../../vector/vector4x/TVector4_def.hpp"


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
                    rmmath::vector::TVector3<T> im;
                };

                rmmath::vector::TVector4<T> wijk;
            };

            constexpr
            TQuaternion( const T w = 0, const T i = 0, const T j = 0, const T k = 0 ) noexcept
                    : w(w), i(i), j(j), k(k)
            {}

            constexpr
            TQuaternion( const T w, const rmmath::vector::TVector3<T>& vec )  noexcept
                    : re(w), im(vec)
            {}

            constexpr
            TQuaternion( const rmmath::vector::TVector3<T>& vec, const T w = 0 ) noexcept
                    : re(w), im(vec)
            {}

            static const TQuaternion<T>& zero() {
                static TQuaternion<T> zero;
                return zero;
            }


            static const TQuaternion<T>& identity() {
                static TQuaternion<T> identity(1, 0, 0, 0);
                return identity;
            }
        };
    }

    template <typename T>
    constexpr bool equal(const complex::TQuaternion<T> &a, const complex::TQuaternion<T> &b) noexcept {
        return &a == &b ||
               (equal<T>(a.w, b.w) && equal<T>(a.i, b.i) && equal<T>(a.j, b.j) && equal<T>(a.k, b.k));
    }

}

#endif //RMVECTORMATH_TQUATERNION_DEF_HPP
