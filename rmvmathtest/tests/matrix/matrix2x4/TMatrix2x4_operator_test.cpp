//
// Created by Vitali Kurlovich on 12/23/15.
//

#include "gtest/gtest.h"

#include "../TMatrix2x4_test_types.h"

// ==

TEST(equali_op, matequal_op2x4) {
    tmat2x4i a = {
            -30, 20, 12, 34,
            32, 54, 45, 55
    };

    tmat2x4i b = {
            -30, 20, 12, 34,
            32, 54, 45, 55
    };

    EXPECT_EQ(a, b);
    EXPECT_EQ(b, a);
    EXPECT_EQ(a, a);
    EXPECT_EQ(b, b);
}


// !=

TEST(nequali_op, matnequal_op2x4) {
    tmat2x4i a = {
            1, 1, 1, 1,
            1, 1, 1, 1
    };

    tmat2x4i b = {
            -1, 1, 1, 1,
            1, 1, 1, 1
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1, -1, 1, 1,
            1, 1, 1, 1
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1, 1, -1, 1,
            1, 1, 1, 1
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1, 1, 1, -1,
            1, 1, 1, 1
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1, 1, 1, 1,
            -1, 1, 1, 1
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    b = {
            1, 1, 1, 1,
            1, -1, 1, 1
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1, 1, 1, 1,
            1, 1,-1, 1
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1, 1, 1, 1,
            1, 1, 1,-1
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

}