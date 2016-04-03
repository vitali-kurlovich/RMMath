//
// Created by Vitali Kurlovich on 3/22/16.
//

#ifndef RMVECTORMATH_MT_FLOAT_TYPE_HPP
#define RMVECTORMATH_MT_FLOAT_TYPE_HPP

#include "../matrix/TMatrix4x4.hpp"
#include "../matrix/TMatrix3x3.hpp"
#include "../matrix/TMatrix2x2.hpp"
#include "../matrix/TMatrix1x1.hpp"

#include "../matrix/TAffineMatrix3x3.hpp"
#include "../matrix/TAffineMatrix4x4.hpp"

namespace rmmath {

    typedef matrix::TAffineMatrix4x4<float> famt4x4;
    typedef matrix::TAffineMatrix3x3<float> famt3x3;

    typedef matrix::TMatrix4x4<float> fmt4x4;
    typedef matrix::TMatrix4x3<float> fmt4x3;
    typedef matrix::TMatrix4x2<float> fmt4x2;
    typedef matrix::TMatrix4x1<float> fmt4x1;

    typedef matrix::TMatrix3x4<float> fmt3x4;
    typedef matrix::TMatrix3x3<float> fmt3x3;
    typedef matrix::TMatrix3x2<float> fmt3x2;
    typedef matrix::TMatrix3x1<float> fmt3x1;

    typedef matrix::TMatrix2x4<float> fmt2x4;
    typedef matrix::TMatrix2x3<float> fmt2x3;
    typedef matrix::TMatrix2x2<float> fmt2x2;
    typedef matrix::TMatrix2x1<float> fmt2x1;

    typedef matrix::TMatrix1x4<float> fmt1x4;
    typedef matrix::TMatrix1x3<float> fmt1x3;
    typedef matrix::TMatrix1x2<float> fmt1x2;
    typedef matrix::TMatrix1x1<float> fmt1x1;

}


#endif //RMVECTORMATH_MT_FLOAT_TYPE_HPP
