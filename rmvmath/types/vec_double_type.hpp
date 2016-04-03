//
// Created by Vitali Kurlovich on 3/22/16.
//

#ifndef RMVECTORMATH_VEC_DOUBLE_TYPE_HPP
#define RMVECTORMATH_VEC_DOUBLE_TYPE_HPP

#include "../vector/TVector2.hpp"
#include "../vector/TVector3.hpp"
#include "../vector/TVector4.hpp"

#include "../vector/TAffineVector3.hpp"
#include "../vector/TAffineVector4.hpp"

namespace rmmath {

    typedef vector::TVector2<double> dvec2;
    typedef vector::TVector3<double> dvec3;
    typedef vector::TVector4<double> dvec4;

    typedef vector::TAffineVector3<double> davec3;
    typedef vector::TAffineVector4<double> davec4;
}


#endif //RMVECTORMATH_VEC_DOUBLE_TYPE_HPP
