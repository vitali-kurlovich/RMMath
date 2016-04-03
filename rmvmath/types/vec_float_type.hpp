//
// Created by Vitali Kurlovich on 3/22/16.
//

#ifndef RMVECTORMATH_VEC_FLOAT_TYPE_HPP
#define RMVECTORMATH_VEC_FLOAT_TYPE_HPP

#include "../vector/TVector2.hpp"
#include "../vector/TVector3.hpp"
#include "../vector/TVector4.hpp"

#include "../vector/TAffineVector3.hpp"
#include "../vector/TAffineVector4.hpp"

namespace rmmath {
    typedef vector::TVector2<float> fvec2;
    typedef vector::TVector3<float> fvec3;
    typedef vector::TVector4<float> fvec4;

    typedef vector::TAffineVector3<float> favec3;
    typedef vector::TAffineVector4<float> favec4;
}


#endif //RMVECTORMATH_VEC_FLOAT_TYPE_HPP
