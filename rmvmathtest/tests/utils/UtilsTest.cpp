//
// Created by Vitali Kurlovich on 8/6/16.
//

#include "gtest/gtest.h"


#include <complex/TQuaternion.hpp>
#include <utils/TQuaternionUtils.hpp>
#include <utils/TRotationMatrixUtils.hpp>

#include "../matrix/TMatrix3x3_test_types.h"
#include "../matrix/TAffineMatrix4x4_test_types.h"

#include <vector/TVector3.hpp>

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

    EXPECT_TRUE(equal<float>(rotationXYZMatrix3x3<float>(1.f,2.f,3.f),
                             rotationXMatrix3x3<float>(1.f)*
                             rotationYMatrix3x3<float>(2.f)*
                             rotationZMatrix3x3<float>(3.f)
    ));


    tmat3x3f rotZ = rotationMatrix3x3<float>(1.f, TVector3<float>(0.f,0.f,1.f));


    EXPECT_TRUE(equal<float>(rotationMatrix3x3<float>(1.f, TVector3<float>(0.f,0.f,1.f)),
                             rotationZMatrix3x3<float>(1.f)));

    tmat3x3f axisMatrix = rotationMatrix3x3<float>(2.f, normalize(TVector3<float>(2.f,3.f,4.f)));

    tmat3x3f resultAxis (
                    -0.220816238403, -0.382413275495, 0.897218075823,
                    0.968405069928, 0.0233470092778, 0.248287208077,
                    -0.115895683245, 0.923696380789, 0.365175556031
    );


    EXPECT_TRUE(equal<float>(axisMatrix, resultAxis));
}


TEST(Utils, quaternion) {
    TQuaternion<float> qr = rotationQuaternion<float>(2.f, normalize(TVector3<float>(2.f,3.f,4.f)));

    tmat3x3f axisMatrix = rotationMatrix3x3<float>(qr);

    tmat3x3f resultAxis (
            -0.220816238403, -0.382413275495, 0.897218075823,
            0.968405069928, 0.0233470092778, 0.248287208077,
            -0.115895683245, 0.923696380789, 0.365175556031
    );

    EXPECT_TRUE(equal<float>(axisMatrix, resultAxis));

}



TEST(Utils, affineTransform) {

    TQuaternion<float> qr = rotationQuaternion<float>(2.f, normalize(TVector3<float>(2.f,3.f,4.f)));
    TVector3<float> pos(12.f, 34.f, 22.f);

    auto transform = affineTRSMatrix4x4(pos, qr);

    tamat4x4f result(
            -0.220816238403, -0.382413275495, 0.897218075823,
            0.968405069928, 0.0233470092778, 0.248287208077,
            -0.115895683245, 0.923696380789, 0.365175556031,
            27.7262724853, 16.5261593869, 27.2422442172
    );

    EXPECT_TRUE(equal<float>(transform, result));

    TVector3<float> scale(7.f, -5.f, -8.f);
    transform = affineTRSMatrix4x4(pos, qr, scale);

    result = tamat4x4f(
            -1.54571366882, 1.91206637748, -7.17774460658,
            6.77883548950,-0.116735046389, -1.98629766462,
            -0.811269782714, -4.61848190395, -2.92140444824,
            194.083907397, -82.6307969343, -217.937953737
    );

    EXPECT_TRUE(equal<float>(transform, result));
}

TEST(Utils, inverseAffineTransform) {

    TQuaternion<float> qr = rotationQuaternion<float>(2.f, normalize(TVector3<float>(2.f,3.f,4.f)));
    TVector3<float> pos(12.f, 34.f, 22.f);

    auto transform = affineTRSMatrix4x4(pos, qr);
    auto invtransform = inverseAffineTRSMatrix4x4(pos, qr);

    EXPECT_TRUE(equal<float>(transform*invtransform,  TAffineMatrix4x4<float>::identity()));


    TVector3<float> scale(7.f, -5.f, -8.f);
    transform = affineTRSMatrix4x4(pos, qr, scale);
    invtransform = inverseAffineTRSMatrix4x4(pos, qr, scale);

    EXPECT_TRUE(equal<float>(transform*invtransform,  TAffineMatrix4x4<float>::identity()));
}