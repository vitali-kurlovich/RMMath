//
// Created by Vitali Kurlovich on 12/12/15.
//

#ifndef RMVECTORMATH_TMATRIX2X2_TEST_TYPES_H
#define RMVECTORMATH_TMATRIX2X2_TEST_TYPES_H

#include <matrix/TMatrix2x4.hpp>
#include <matrix/TMatrix2x3.hpp>
#include <matrix/TMatrix2x2.hpp>
#include <matrix/TMatrix2x1.hpp>


#include <vector/TVector2.hpp>

using namespace rmmath;
using namespace rmmath::matrix;
using namespace rmmath::vector;

typedef TMatrix2x4<int> tmat2x4i;
typedef TMatrix2x4<float> tmat2x4f;
typedef TMatrix2x4<double> tmat2x4d;

typedef TMatrix2x3<int> tmat2x3i;
typedef TMatrix2x3<float> tmat2x3f;
typedef TMatrix2x3<double> tmat2x3d;

typedef TMatrix2x2<int> tmat2x2i;
typedef TMatrix2x2<float> tmat2x2f;
typedef TMatrix2x2<double> tmat2x2d;

typedef TMatrix2x1<int> tmat2x1i;
typedef TMatrix2x1<float> tmat2x1f;
typedef TMatrix2x1<double> tmat2x1d;


typedef TVector2<int> tvec2i;
typedef TVector2<float> tvec2f;
typedef TVector2<double> tvec2d;

#endif //RMVECTORMATH_TMATRIX2X2_TEST_TYPES_H
