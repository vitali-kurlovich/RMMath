//
// Created by Vitali Kurlovich on 1/10/16.
//

#include "gtest/gtest.h"

#include "../TAffineMatrix4x4_test_types.h"


// ==

TEST(equali_op, matequal_opa4x4) {
    tamat4x4i a = {
            -30, 20, 55,
            32, 54, 66,
            77, 88, 99,
            1, 2, 3
    };

    tmat4x4i b = {
            -30, 20, 55, 0,
            32, 54, 66, 0,
            77, 88, 99, 0,
            1, 2, 3, 1
    };

    EXPECT_EQ(a, b);
    EXPECT_EQ(b, a);
    EXPECT_EQ(a, a);
    EXPECT_EQ(b, b);


    tamat4x4i c = {
            -30, 20, 55,
            32, 54, 66,
            77, 88, 99,
            1, 2, 3
    };

    EXPECT_EQ(a, c);
    EXPECT_EQ(c, a);
}



// !=

TEST(nequali_op, matnequal_opa4x4) {
    tamat4x4i a = {
            1, 1, 1,
            1, 1, 1,
            1, 1, 1,
            1, 1, 1,
    };

    tamat4x4i b = {
            -1, 1, 1,
             1, 1, 1,
             1, 1, 1,
             1, 1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1,-1, 1,
            1, 1, 1,
            1, 1, 1,
            1, 1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1, 1,-1,
            1, 1, 1,
            1, 1, 1,
            1, 1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    b = {
            1, 1, 1,
            -1,1, 1,
            1, 1, 1,
            1, 1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    b = {
            1, 1, 1,
            1,-1, 1,
            1, 1, 1,
            1, 1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    b = {
            1, 1, 1,
            1, 1,-1,
            1, 1, 1,
            1, 1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);



    b = {
            1, 1, 1,
            1, 1, 1,
            -1,1, 1,
            1, 1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    b = {
            1, 1, 1,
            1, 1, 1,
            1,-1, 1,
            1, 1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1, 1, 1,
            1, 1, 1,
            1, 1,-1,
            1, 1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1, 1, 1,
            1, 1, 1,
            1, 1, 1,
            -1,1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    b = {
            1, 1, 1,
            1, 1, 1,
            1, 1, 1,
            1,-1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    b = {
            1, 1, 1,
            1, 1, 1,
            1, 1, 1,
            1, 1,-1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);
}