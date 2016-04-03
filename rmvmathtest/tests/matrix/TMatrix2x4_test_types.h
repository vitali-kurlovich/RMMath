//
// Created by Vitali Kurlovich on 12/23/15.
//

#ifndef RMVECTORMATH_TMATRIX2X4_TEST_TYPES_H
#define RMVECTORMATH_TMATRIX2X4_TEST_TYPES_H


#include <matrix/TMatrix2x4.hpp>
#include <matrix/TMatrix2x3.hpp>
#include <matrix/TMatrix2x2.hpp>
#include <matrix/TMatrix2x1.hpp>

#include <matrix/TMatrix4x4.hpp>
#include <matrix/TMatrix4x3.hpp>
#include <matrix/TMatrix4x2.hpp>
#include <matrix/TMatrix4x1.hpp>

#include <vector/TVector4.hpp>
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

typedef TVector4<int> tvec4i;
typedef TVector4<float> tvec4f;
typedef TVector4<double> tvec4d;

typedef TVector2<int> tvec2i;
typedef TVector2<float> tvec2f;
typedef TVector2<double> tvec2d;

#endif //RMVECTORMATH_TMATRIX2X4_TEST_TYPES_H
