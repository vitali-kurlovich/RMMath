//
// Created by Vitali Kurlovich on 12/16/15.
//

#ifndef RMVECTORMATH_TMATRIX4x3_3X4_TEST_TYPES_H
#define RMVECTORMATH_TMATRIX4x3_3X4_TEST_TYPES_H

#include <matrix/TMatrix4x4.hpp>
#include <matrix/TMatrix4x3.hpp>
#include <matrix/TMatrix4x2.hpp>
#include <matrix/TMatrix4x1.hpp>

#include <matrix/TMatrix3x4.hpp>
#include <matrix/TMatrix3x3.hpp>
#include <matrix/TMatrix3x2.hpp>
#include <matrix/TMatrix3x1.hpp>


#include <vector/TVector4.hpp>
#include <vector/TVector3.hpp>

using namespace rmmath;
using namespace rmmath::matrix;
using namespace rmmath::vector;

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

typedef TVector4<int> tvec4i;
typedef TVector4<float> tvec4f;
typedef TVector4<double> tvec4d;

#endif //RMVECTORMATH_TMATRIX4x3_3X4_TEST_TYPES_H
