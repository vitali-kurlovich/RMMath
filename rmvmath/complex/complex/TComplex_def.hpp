//
// Created by Vitali Kurlovich on 5/15/16.
//

#ifndef RMVECTORMATH_TCOMPLEX_DEF_HPP
#define RMVECTORMATH_TCOMPLEX_DEF_HPP

#include "vector/vector3x/TVector3_def.hpp"

namespace rmmath {

    namespace complex {

        template<typename T>
        struct TComplex {

            union {
                struct {
                    T w, i;
                };

                struct {
                    T re;
                    T im;
                };
            };

            TComplex( const T w = 0, const T i = 0)
                    : w(w), i(i)
            {}

        };
    }
}



#endif //RMVECTORMATH_TCOMPLEX_DEF_HPP
