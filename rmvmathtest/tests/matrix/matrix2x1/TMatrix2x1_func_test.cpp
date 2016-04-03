//
// Created by Vitali Kurlovich on 12/31/15.
//

#include "gtest/gtest.h"

#include "../TMatrix2x1_test_types.h"

// Mul

// 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139,

TEST(multi, matmult2x1x1x4) {

    tmat2x1i a = {
            2,
            3
    };

    tmat1x4i b = {
            11, 13, 17, 19
    };

    tmat2x4i r = {
            22, 26, 34, 38,
            33, 39, 51, 57
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);
}


TEST(multi, matmult2x1x1x3) {

    tmat2x1i a = {
            2,
            3
    };

    tmat1x3i b = {
            11, 13, 17
    };

    tmat2x3i r = {
            22, 26, 34,
            33, 39, 51
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);
}


TEST(multi, matmult2x1x1x2) {

    tmat2x1i a = {
            2,
            3
    };

    tmat1x2i b = {
            11, 13
    };

    tmat2x2i r = {
            22, 26,
            33, 39
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);
}


TEST(multi, matmult2x1x1x1) {

    tmat2x1i a = {
            2,
            3
    };

    tmat1x1i b = {
            11
    };

    tmat2x1i r = {
            22,
            33
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);

    a*=b;
    EXPECT_EQ(a, r);
}

TEST(multi, matmult2x1xvec) {

    tmat2x1i a = {
            2,
            11

    };

    int b = 59;

    tvec2i r = {
            118, 649
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);

    tvec2i c = {
            59, 61
    };

    EXPECT_EQ(mul(c, a), 789);
    EXPECT_EQ(c*a, 789);
}


// trans

TEST(trans, mattranspose2x1) {

    tmat2x1i a = {
            2,
            11
    };

    tmat1x2i b = {
            2, 11
    };

    EXPECT_EQ(transpose(a),b);
}