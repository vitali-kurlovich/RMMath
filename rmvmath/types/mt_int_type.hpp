//
// Created by Vitali Kurlovich on 3/22/16.
//

#ifndef RMVECTORMATH_MT_INT_TYPE_HPP
#define RMVECTORMATH_MT_INT_TYPE_HPP

#include "../matrix/TMatrix4x4.hpp"
#include "../matrix/TMatrix3x3.hpp"
#include "../matrix/TMatrix2x2.hpp"
#include "../matrix/TMatrix1x1.hpp"

#include "../matrix/TAffineMatrix3x3.hpp"
#include "../matrix/TAffineMatrix4x4.hpp"

namespace rmmath {

    typedef matrix::TAffineMatrix4x4<int> iamt4x4;
    typedef matrix::TAffineMatrix3x3<int> iamt3x3;

    typedef matrix::TMatrix4x4<int> imt4x4;
    typedef matrix::TMatrix4x3<int> imt4x3;
    typedef matrix::TMatrix4x2<int> imt4x2;
    typedef matrix::TMatrix4x1<int> imt4x1;

    typedef matrix::TMatrix3x4<int> imt3x4;
    typedef matrix::TMatrix3x3<int> imt3x3;
    typedef matrix::TMatrix3x2<int> imt3x2;
    typedef matrix::TMatrix3x1<int> imt3x1;

    typedef matrix::TMatrix2x4<int> imt2x4;
    typedef matrix::TMatrix2x3<int> imt2x3;
    typedef matrix::TMatrix2x2<int> imt2x2;
    typedef matrix::TMatrix2x1<int> imt2x1;

    typedef matrix::TMatrix1x4<int> imt1x4;
    typedef matrix::TMatrix1x3<int> imt1x3;
    typedef matrix::TMatrix1x2<int> imt1x2;
    typedef matrix::TMatrix1x1<int> imt1x1;
}


#endif //RMVECTORMATH_MT_INT_TYPE_HPP
