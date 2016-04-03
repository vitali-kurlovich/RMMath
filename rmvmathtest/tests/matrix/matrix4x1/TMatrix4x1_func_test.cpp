//
// Created by Vitali Kurlovich on 12/30/15.
//

#include "gtest/gtest.h"

#include "../TMatrix4x1_test_types.h"

// Mul

TEST(multi, matmult4x1x1x4) {

    tmat4x1i a = {
            2,
            3,
            5,
            7
    };

    tmat1x4i b = {
            11, 13, 17, 19
    };

    tmat4x4i r = {
            22, 26, 34, 38,
            33, 39, 51, 57,
            55, 65, 85, 95,
            77, 91, 119, 133
    };

    EXPECT_EQ(mul(a, b), r);

    EXPECT_EQ(a * b, r);
}


TEST(multi, matmult4x1x1x3) {

    tmat4x1i a = {
            2,
            3,
            5,
            7
    };

    tmat1x3i b = {
            11, 13, 17
    };

    tmat4x3i r = {
            22, 26, 34,
            33, 39, 51,
            55, 65, 85,
            77, 91, 119
    };

    EXPECT_EQ(mul(a, b), r);

    EXPECT_EQ(a * b, r);
}


TEST(multi, matmult4x1x1x2) {

    tmat4x1i a = {
            2,
            3,
            5,
            7
    };

    tmat1x2i b = {
            11, 13
    };

    tmat4x2i r = {
            22, 26,
            33, 39,
            55, 65,
            77, 91
    };

    EXPECT_EQ(mul(a, b), r);

    EXPECT_EQ(a * b, r);
}

TEST(multi, matmult4x1x1x1) {

    tmat4x1i a = {
            2,
            3,
            5,
            7
    };

    tmat1x1i b = {
            11
    };

    tmat4x1i r = {
            22,
            33,
            55,
            77
    };

    EXPECT_EQ(mul(a, b), r);

    EXPECT_EQ(a * b, r);

    a *= b;
    EXPECT_EQ(a, r);
}

TEST(multi, matmult4x1xvec) {

    tmat4x1i a = {
            2,
            11,
            23,
            41,
    };

    int b =59;

    tvec4i r = {
            118, 649, 1357, 2419
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);

    tvec4i c = {
            59, 61, 71, 73
    };

    EXPECT_EQ(mul(c, a), 5415);
    EXPECT_EQ(c*a, 5415);
}


// trans

TEST(trans, mattranspose4x1) {

    tmat4x1i a = {
            1,
            5,
            9,
            13
    };

    tmat1x4i b = {
            1, 5, 9, 13
    };

    EXPECT_EQ(transpose(a),b);
}