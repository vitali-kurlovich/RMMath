//
// Created by Vitali Kurlovich on 12/20/15.
//

#include "gtest/gtest.h"

#include "../TMatrix4x2_test_types.h"


// Mul

TEST(multi, matmult4x2x2x4) {

    tmat4x2i a = {
            1, 2,
            5, 6,
            9, 10,
            13, 14,
    };

    tmat2x4i b = {
            16, 15, 14, 12,
            11, 10, 8, 7,

    };

    tmat4x4i r = {
            38, 35, 30, 26,
            146, 135, 118, 102,
            254, 235, 206, 178,
            362, 335, 294, 254
    };

    EXPECT_EQ(mul(a, b), r);

    EXPECT_EQ(a * b, r);
}


TEST(multi, matmult4x2x2x3) {

    tmat4x2i a = {
            1, 2,
            5, 6,
            9, 10,
            13, 14,
    };

    tmat2x3i b = {
            16, 15, 14,
            11, 10, 8,

    };

    tmat4x3i r = {
            38, 35, 30,
            146, 135, 118,
            254, 235, 206,
            362, 335, 294
    };

    EXPECT_EQ(mul(a, b), r);

    EXPECT_EQ(a * b, r);
}


TEST(multi, matmult4x2x2x2) {

    tmat4x2i a = {
            1, 2,
            5, 6,
            9, 10,
            13, 14,
    };

    tmat2x2i b = {
            16, 15,
            11, 10,

    };

    tmat4x2i r = {
            38, 35,
            146, 135,
            254, 235,
            362, 335
    };

    EXPECT_EQ(mul(a, b), r);

    EXPECT_EQ(a * b, r);

    a*=b;
    EXPECT_EQ(a, r);
}


TEST(multi, matmult4x2x2x1) {

    tmat4x2i a = {
            1, 2,
            5, 6,
            9, 10,
            13, 14,
    };

    tmat2x1i b = {
            16,
            11,

    };

    tmat4x1i r = {
            38,
            146,
            254,
            362
    };

    EXPECT_EQ(mul(a, b), r);

    EXPECT_EQ(a * b, r);
}


TEST(multi, matmult4x2xvec) {

    tmat4x2i a = {
            2,  3,
            11, 13,
            23, 29,
            41, 43
    };

    tvec2i b = {
            59, 61,
    };


    tvec4i r = {
            301, 1442, 3126, 5042
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);

    tvec4i c = {
            59, 61, 71, 73
    };


    tvec2i r1 = {
            5415, 6168
    };

    EXPECT_EQ(mul(c, a), r1);
    EXPECT_EQ(c*a, r1);
}


// trans

TEST(trans, mattranspose4x2) {

    tmat4x2i a = {
            1, 2,
            5, 6,
            9, 10,
            13, 14
    };

    tmat2x4i b = {
            1, 5, 9, 13,
            2, 6, 10, 14
    };

    EXPECT_EQ(transpose(a),b);
}