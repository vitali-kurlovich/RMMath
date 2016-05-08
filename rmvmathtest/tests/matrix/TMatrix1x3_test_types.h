//
// Created by Vitali Kurlovich on 12/25/15.
//

#ifndef RMVECTORMATH_TMATRIX1X3_TEST_TYPES_H
#define RMVECTORMATH_TMATRIX1X3_TEST_TYPES_H

#include <matrix/TMatrix1x4.hpp>
#include <matrix/TMatrix1x3.hpp>
#include <matrix/TMatrix1x2.hpp>
#include <matrix/TMatrix1x1.hpp>

#include <matrix/TMatrix3x4.hpp>
#include <matrix/TMatrix3x3.hpp>
#include <matrix/TMatrix3x2.hpp>
#include <matrix/TMatrix3x1.hpp>

#include <vector/TVector3.hpp>

using namespace rmmath::matrix;
using namespace rmmath::vector;

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

#endif //RMVECTORMATH_TMATRIX1X3_TEST_TYPES_H
