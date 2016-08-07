//
// Created by Vitali Kurlovich on 8/6/16.
//

#include "gtest/gtest.h"


#include <complex/TQuaternion.hpp>
#include <utils/TQuaternionUtils.hpp>
#include <utils/TRotationMatrixUtils.hpp>

#include "../matrix/TMatrix3x3_test_types.h"

using namespace rmmath;
using namespace rmmath::matrix;
using namespace rmmath::complex;


TEST(Utils, rotation) {

    tmat3x3f rot = rotationXYZMatrix3x3<float>(1.f,2.f,3.f);
    tmat3x3f result(
            0.411982245666f, 0.0587266449276f, 0.909297426826f,
            -0.681242720256f, -0.642872836135f, 0.350175488374f,
            0.605127247241f, -0.763718336650f, -0.224845095366f
    );

    EXPECT_TRUE(equal<float>(rot, result));
}