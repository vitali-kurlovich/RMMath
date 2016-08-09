//
// Created by Vitali Kurlovich on 8/8/16.
//

#include "gtest/gtest.h"

#include "TTransform3dTest.h"

TEST(Transform3d, constructor) {

    TestTTransform3d tm;

    EXPECT_EQ(tm.getParent(), nullptr);
    EXPECT_FALSE(tm.hasParent());

    EXPECT_FALSE(tm.test_isPositionNeedsUpdate());
    EXPECT_FALSE(tm.test_isRotationNeedsUpdate());
    EXPECT_FALSE(tm.test_isScaleNeedsUpdate());
    EXPECT_FALSE(tm.test_isTransformNeedsUpdate());
    EXPECT_FALSE(tm.test_isGlobalTransformNeedsUpdate());


    rmmath::vector::TVector3<float> pos(1,2,3);
    tm.setPosition(pos);

    EXPECT_TRUE(tm.test_isPositionNeedsUpdate());
    EXPECT_FALSE(tm.test_isRotationNeedsUpdate());
    EXPECT_FALSE(tm.test_isScaleNeedsUpdate());
    EXPECT_TRUE(tm.test_isTransformNeedsUpdate());
    EXPECT_TRUE(tm.test_isGlobalTransformNeedsUpdate());


    auto m = tm.getTransform();

    EXPECT_FALSE(tm.test_isPositionNeedsUpdate());
    EXPECT_FALSE(tm.test_isRotationNeedsUpdate());
    EXPECT_FALSE(tm.test_isScaleNeedsUpdate());
    EXPECT_FALSE(tm.test_isTransformNeedsUpdate());
    EXPECT_TRUE(tm.test_isGlobalTransformNeedsUpdate());


    rmmath::complex::TQuaternion<float>  rot(0,0,1,0);
    tm.setRotation(rot);

    EXPECT_FALSE(tm.test_isPositionNeedsUpdate());
    EXPECT_TRUE(tm.test_isRotationNeedsUpdate());
    EXPECT_FALSE(tm.test_isScaleNeedsUpdate());
    EXPECT_TRUE(tm.test_isTransformNeedsUpdate());
    EXPECT_TRUE(tm.test_isGlobalTransformNeedsUpdate());

    m = tm.getTransform();

    EXPECT_FALSE(tm.test_isPositionNeedsUpdate());
    EXPECT_FALSE(tm.test_isRotationNeedsUpdate());
    EXPECT_FALSE(tm.test_isScaleNeedsUpdate());
    EXPECT_FALSE(tm.test_isTransformNeedsUpdate());
    EXPECT_TRUE(tm.test_isGlobalTransformNeedsUpdate());


    rmmath::vector::TVector3<float> scale(10,20,30);
    tm.setScale(scale);

    EXPECT_FALSE(tm.test_isPositionNeedsUpdate());
    EXPECT_FALSE(tm.test_isRotationNeedsUpdate());
    EXPECT_TRUE(tm.test_isScaleNeedsUpdate());
    EXPECT_TRUE(tm.test_isTransformNeedsUpdate());
    EXPECT_TRUE(tm.test_isGlobalTransformNeedsUpdate());

    m = tm.getTransform();

    EXPECT_FALSE(tm.test_isPositionNeedsUpdate());
    EXPECT_FALSE(tm.test_isRotationNeedsUpdate());
    EXPECT_FALSE(tm.test_isScaleNeedsUpdate());
    EXPECT_FALSE(tm.test_isTransformNeedsUpdate());
    EXPECT_TRUE(tm.test_isGlobalTransformNeedsUpdate());

    pos = rmmath::vector::TVector3<float>(2,2,3);
    rot = rmmath::complex::TQuaternion<float>(0,1,0,0);
    scale = rmmath::vector::TVector3<float>(10,26,30);

    tm.setTransform(pos, rot, scale);

    EXPECT_TRUE(tm.test_isPositionNeedsUpdate());
    EXPECT_TRUE(tm.test_isRotationNeedsUpdate());
    EXPECT_TRUE(tm.test_isScaleNeedsUpdate());
    EXPECT_TRUE(tm.test_isTransformNeedsUpdate());
    EXPECT_TRUE(tm.test_isGlobalTransformNeedsUpdate());


    m = tm.getTransform();

    EXPECT_FALSE(tm.test_isPositionNeedsUpdate());
    EXPECT_FALSE(tm.test_isRotationNeedsUpdate());
    EXPECT_FALSE(tm.test_isScaleNeedsUpdate());
    EXPECT_FALSE(tm.test_isTransformNeedsUpdate());
    EXPECT_TRUE(tm.test_isGlobalTransformNeedsUpdate());
}
