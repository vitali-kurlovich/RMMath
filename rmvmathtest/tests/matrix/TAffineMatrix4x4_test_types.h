//
// Created by Vitali Kurlovich on 1/10/16.
//

#ifndef RMVECTORMATH_TAFFINEMATRIX4X4_TEST_TYPES_H
#define RMVECTORMATH_TAFFINEMATRIX4X4_TEST_TYPES_H


#include <matrix/TAffineMatrix4x4.hpp>

#include <matrix/TMatrix4x4.hpp>
#include <matrix/TMatrix4x3.hpp>
#include <matrix/TMatrix4x2.hpp>
#include <matrix/TMatrix4x1.hpp>

#include <matrix/TMatrix3x4.hpp>
#include <matrix/TMatrix2x4.hpp>
#include <matrix/TMatrix1x4.hpp>

#include <vector/TVector4.hpp>
#include <vector/TVector3.hpp>

using namespace rmmath;
using namespace rmmath::matrix;
using namespace rmmath::vector;


typedef TAffineMatrix4x4<int> tamat4x4i;
typedef TAffineMatrix4x4<float> tamat4x4f;
typedef TAffineMatrix4x4<double> tamat4x4d;

typedef TMatrix4x4<int> tmat4x4i;
typedef TMatrix4x4<float> tmat4x4f;
typedef TMatrix4x4<double> tmat4x4d;

typedef TMatrix4x3<int> tmat4x3i;
typedef TMatrix4x3<float> tmat4x3f;
typedef TMatrix4x3<double> tmat4x3d;

typedef TMatrix4x2<int> tmat4x2i;
typedef TMatrix4x2<float> tmat4x2f;
typedef TMatrix4x2<double> tmat4x2d;

typedef TMatrix4x1<int> tmat4x1i;
typedef TMatrix4x1<float> tmat4x1f;
typedef TMatrix4x1<double> tmat4x1d;

typedef TMatrix3x4<int> tmat3x4i;
typedef TMatrix3x4<float> tmat3x4f;
typedef TMatrix3x4<double> tmat3x4d;

typedef TMatrix2x4<int> tmat2x4i;
typedef TMatrix2x4<float> tmat2x4f;
typedef TMatrix2x4<double> tmat2x4d;

typedef TMatrix1x4<int> tmat1x4i;
typedef TMatrix1x4<float> tmat1x4f;
typedef TMatrix1x4<double> tmat1x4d;

typedef TVector4<int> tvec4i;
typedef TVector4<float> tvec4f;
typedef TVector4<double> tvec4d;

typedef TVector3<int> tvec3i;
typedef TVector3<float> tvec3f;
typedef TVector3<double> tvec3d;

#endif //RMVECTORMATH_TAFFINEMATRIX4X4_TEST_TYPES_H
