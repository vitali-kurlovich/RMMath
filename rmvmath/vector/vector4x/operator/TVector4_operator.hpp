//
// Created by Vitali Kurlovich on 12/11/15.
//

#ifndef RMVECTORMATH_TVECTOR4_OPERATOR_HPP
#define RMVECTORMATH_TVECTOR4_OPERATOR_HPP


#include "../TVector4_def.hpp"

#include "TVector4_operator_sum.hpp"
#include "TVector4_operator_sub.hpp"
#include "TVector4_operator_mul.hpp"
#include "TVector4_operator_div.hpp"

#include "../../../matrix/matrix1x4/TMatrix1x4_def.hpp"
#include "../../../matrix/matrix4x1/TMatrix4x1_def.hpp"

namespace rmmath {

    namespace vector {

        template<typename T>
        inline bool operator == (const TVector4<T> &a, const TVector4<T> &b) {
            return &a == &b || (a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w);
        }

        template<typename T>
        inline bool operator != (const TVector4<T> &a, const TVector4<T> &b) {
            return !(a == b);
        }
    }
}



#endif //RMVECTORMATH_TVECTOR4_OPERATOR_HPP
