//
// Created by Vitali Kurlovich on 12/11/15.
//

#ifndef RMVECTORMATH_TVECTOR3_OPERATOR_HPP
#define RMVECTORMATH_TVECTOR3_OPERATOR_HPP


#include "../TVector3_def.hpp"

#include "TVector3_operator_sum.hpp"
#include "TVector3_operator_sub.hpp"
#include "TVector3_operator_mul.hpp"
#include "TVector3_operator_div.hpp"

namespace rmmath {

    namespace vector {

        template<typename T>
        inline bool operator == (const TVector3<T> &a, const TVector3<T> &b) {
            return &a == &b || (a.x == b.x && a.y == b.y && a.z == b.z );
        }

        template<typename T>
        inline bool operator != (const TVector3<T> &a, const TVector3<T> &b) {
            return !(a == b);
        }
    }
}



#endif //RMVECTORMATH_TVECTOR3_OPERATOR_HPP
