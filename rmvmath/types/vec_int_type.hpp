//
// Created by Vitali Kurlovich on 3/22/16.
//

#ifndef RMVECTORMATH_VEC_INT_TYPE_HPP
#define RMVECTORMATH_VEC_INT_TYPE_HPP

#include "../vector/TVector2.hpp"
#include "../vector/TVector3.hpp"
#include "../vector/TVector4.hpp"

#include "../vector/TAffineVector3.hpp"
#include "../vector/TAffineVector4.hpp"

namespace rmmath {

    typedef vector::TVector2<int> ivec2;
    typedef vector::TVector3<int> ivec3;
    typedef vector::TVector4<int> ivec4;

    typedef vector::TAffineVector3<int> iavec3;
    typedef vector::TAffineVector4<int> iavec4;
}


#endif //RMVECTORMATH_VEC_INT_TYPE_HPP
