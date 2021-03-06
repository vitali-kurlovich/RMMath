//
// Created by Vitali Kurlovich on 12/25/15.
//

#ifndef RMVECTORMATH_TMATRIX1X1_TEST_TYPES_H
#define RMVECTORMATH_TMATRIX1X1_TEST_TYPES_H

#include <matrix/TMatrix1x4.hpp>
#include <matrix/TMatrix1x3.hpp>
#include <matrix/TMatrix1x2.hpp>
#include <matrix/TMatrix1x1.hpp>


using namespace rmmath::matrix;

typedef TMatrix1x4<int> tmat1x4i;
typedef TMatrix1x4<float> tmat1x4f;
typedef TMatrix1x4<double> tmat1x4d;

typedef TMatrix1x3<int> tmat1x3i;
typedef TMatrix1x3<float> tmat1x3f;
typedef TMatrix1x3<double> tmat1x3d;

typedef TMatrix1x2<int> tmat1x2i;
typedef TMatrix1x2<float> tmat1x2f;
typedef TMatrix1x2<double> tmat1x2d;

typedef TMatrix1x1<int> tmat1x1i;
typedef TMatrix1x1<float> tmat1x1f;
typedef TMatrix1x1<double> tmat1x1d;


#endif //RMVECTORMATH_TMATRIX1X1_TEST_TYPES_H
