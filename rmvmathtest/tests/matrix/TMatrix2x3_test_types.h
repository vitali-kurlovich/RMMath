//
// Created by Vitali Kurlovich on 12/23/15.
//

#ifndef RMVECTORMATH_TMATRIX2X3_TEST_TYPES_H
#define RMVECTORMATH_TMATRIX2X3_TEST_TYPES_H


#include <matrix/TMatrix2x4.hpp>
#include <matrix/TMatrix2x3.hpp>
#include <matrix/TMatrix2x2.hpp>
#include <matrix/TMatrix2x1.hpp>

#include <matrix/TMatrix3x4.hpp>
#include <matrix/TMatrix3x3.hpp>
#include <matrix/TMatrix3x2.hpp>
#include <matrix/TMatrix3x1.hpp>

#include <vector/TVector3.hpp>
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


typedef TMatrix3x4<int> tmat3x4i;
typedef TMatrix3x4<float> tmat3x4f;
typedef TMatrix3x4<double> tmat3x4d;

typedef TMatrix3x3<int> tmat3x3i;
typedef TMatrix3x3<float> tmat3x3f;
typedef TMatrix3x3<double> tmat3x3d;

typedef TMatrix3x2<int> tmat3x2i;
typedef TMatrix3x2<float> tmat3x2f;
typedef TMatrix3x2<double> tmat3x2d;

typedef TMatrix3x1<int> tmat3x1i;
typedef TMatrix3x1<float> tmat3x1f;
typedef TMatrix3x1<double> tmat3x1d;

typedef TVector3<int> tvec3i;
typedef TVector3<float> tvec3f;
typedef TVector3<double> tvec3d;

typedef TVector2<int> tvec2i;
typedef TVector2<float> tvec2f;
typedef TVector2<double> tvec2d;

#endif //RMVECTORMATH_TMATRIX2X3_TEST_TYPES_H
