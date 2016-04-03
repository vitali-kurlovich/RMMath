//
// Created by Vitali Kurlovich on 3/22/16.
//

#ifndef RMVECTORMATH_MT_DOUBLE_TYPE_HPP
#define RMVECTORMATH_MT_DOUBLE_TYPE_HPP

#include "../matrix/TMatrix4x4.hpp"
#include "../matrix/TMatrix3x3.hpp"
#include "../matrix/TMatrix2x2.hpp"
#include "../matrix/TMatrix1x1.hpp"

#include "../matrix/TAffineMatrix3x3.hpp"
#include "../matrix/TAffineMatrix4x4.hpp"

namespace rmmath {

    typedef matrix::TAffineMatrix4x4<double> damt4x4;
    typedef matrix::TAffineMatrix3x3<double> damt3x3;

    typedef matrix::TMatrix4x4<double> dmt4x4;
    typedef matrix::TMatrix4x3<double> dmt4x3;
    typedef matrix::TMatrix4x2<double> dmt4x2;
    typedef matrix::TMatrix4x1<double> dmt4x1;

    typedef matrix::TMatrix3x4<double> dmt3x4;
    typedef matrix::TMatrix3x3<double> dmt3x3;
    typedef matrix::TMatrix3x2<double> dmt3x2;
    typedef matrix::TMatrix3x1<double> dmt3x1;

    typedef matrix::TMatrix2x4<double> dmt2x4;
    typedef matrix::TMatrix2x3<double> dmt2x3;
    typedef matrix::TMatrix2x2<double> dmt2x2;
    typedef matrix::TMatrix2x1<double> dmt2x1;

    typedef matrix::TMatrix1x4<double> dmt1x4;
    typedef matrix::TMatrix1x3<double> dmt1x3;
    typedef matrix::TMatrix1x2<double> dmt1x2;
    typedef matrix::TMatrix1x1<double> dmt1x1;
}


#endif //RMVECTORMATH_MT_DOUBLE_TYPE_HPP
