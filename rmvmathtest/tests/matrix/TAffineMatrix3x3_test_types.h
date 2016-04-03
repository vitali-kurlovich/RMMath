//
// Created by Vitali Kurlovich on 1/12/16.
//

#ifndef RMVECTORMATH_TAFFINEMATRIX3X3_TEST_TYPES_H
#define RMVECTORMATH_TAFFINEMATRIX3X3_TEST_TYPES_H

#include <matrix/TAffineMatrix3x3.hpp>

#include <matrix/TMatrix3x4.hpp>
#include <matrix/TMatrix3x3.hpp>
#include <matrix/TMatrix3x2.hpp>
#include <matrix/TMatrix3x1.hpp>

#include <matrix/TMatrix4x3.hpp>
#include <matrix/TMatrix3x3.hpp>
#include <matrix/TMatrix2x3.hpp>
#include <matrix/TMatrix1x3.hpp>


#include <vector/TVector3.hpp>

using namespace rmmath;
using namespace rmmath::matrix;
using namespace rmmath::vector;


typedef TAffineMatrix3x3<int> tamat3x3i;
typedef TAffineMatrix3x3<float> tamat3x3f;
typedef TAffineMatrix3x3<double> tamat3x3d;

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


typedef TMatrix4x3<int> tmat4x3i;
typedef TMatrix4x3<float> tmat4x3f;
typedef TMatrix4x3<double> tmat4x3d;

typedef TMatrix2x3<int> tmat2x3i;
typedef TMatrix2x3<float> tmat2x3f;
typedef TMatrix2x3<double> tmat2x3d;

typedef TMatrix1x3<int> tmat1x3i;
typedef TMatrix1x3<float> tmat1x3f;
typedef TMatrix1x3<double> tmat1x3d;


typedef TVector3<int> tvec3i;
typedef TVector3<float> tvec3f;
typedef TVector3<double> tvec3d;

#endif //RMVECTORMATH_TAFFINEMATRIX3X3_TEST_TYPES_H
