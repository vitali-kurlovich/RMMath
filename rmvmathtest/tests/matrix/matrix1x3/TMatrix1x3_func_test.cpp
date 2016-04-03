//
// Created by Vitali Kurlovich on 12/25/15.
//

#include "gtest/gtest.h"

#include "../TMatrix1x3_test_types.h"

// Mul


TEST(multi, matmult1x3x3x4) {
    tmat1x3i a = {
            2,  3,  5,
    };

    tmat3x4i b = {
            29, 31, 37, 41,
            43, 47, 53, 59,
            61, 67, 71, 73
    };

    tmat1x4i r = {
            492, 538, 588, 624
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);
}

TEST(multi, matmult1x3x3x3) {
    tmat1x3i a = {
            2,  3,  5,
    };

    tmat3x3i b = {
            29, 31, 37,
            43, 47, 53,
            61, 67, 71
    };

    tmat1x3i r = {
            492, 538, 588
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);

    a*=b;
    EXPECT_EQ(a, r);
}

TEST(multi, matmult1x3x3x2) {
    tmat1x3i a = {
            2,  3,  5,
    };

    tmat3x2i b = {
            29, 31,
            43, 47,
            61, 67
    };

    tmat1x2i r = {
            492, 538
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);
}

TEST(multi, matmult1x3x3x1) {
    tmat1x3i a = {
            2,  3,  5,
    };

    tmat3x1i b = {
            29,
            43,
            61
    };

    tmat1x1i r = {
            492
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);
}


// trans

TEST(trans, mattranspose1x3) {

    tmat1x3i a = {
            2,  3,  5
    };

    tmat3x1i b = {
            2,
            3,
            5
    };

    EXPECT_EQ(transpose(a),b);
}