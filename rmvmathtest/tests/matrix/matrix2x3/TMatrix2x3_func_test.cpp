//
// Created by Vitali Kurlovich on 12/24/15.
//

#include "gtest/gtest.h"

#include "../TMatrix2x3_test_types.h"


// Mul


TEST(multi, matmult2x3x3x4) {
    tmat2x3i a = {
            2,  3,  5,
            11, 13, 17
    };

    tmat3x4i b = {
            29, 31, 37, 41,
            43, 47, 53, 59,
            61, 67, 71, 73
    };

    tmat2x4i r = {
             492,  538,  588,  624,
            1915, 2091, 2303, 2459
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);
}

TEST(multi, matmult2x3x3x3) {
    tmat2x3i a = {
            2,  3,  5,
            11, 13, 17
    };

    tmat3x3i b = {
            29, 31, 37,
            43, 47, 53,
            61, 67, 71
    };

    tmat2x3i r = {
            492,  538,  588,
            1915, 2091, 2303
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);

    a*=b;
    EXPECT_EQ(a, r);
}

TEST(multi, matmult2x3x3x2) {
    tmat2x3i a = {
            2,  3,  5,
            11, 13, 17
    };

    tmat3x2i b = {
            29, 31,
            43, 47,
            61, 67
    };

    tmat2x2i r = {
             492,  538,
            1915, 2091
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);
}


TEST(multi, matmult2x3x3x1) {
    tmat2x3i a = {
            2,  3,  5,
            11, 13, 17
    };

    tmat3x1i b = {
            29,
            43,
            61
    };

    tmat2x1i r = {
            492,
            1915
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);
}


TEST(multi, matmult2x3xvec) {

    tmat2x3i a = {
            2, 3, 5,
            11, 13, 17,

    };

    tvec3i b = {
            59, 61, 71
    };


    tvec2i r = {
            656, 2649
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);

    tvec2i c = {
            59, 61
    };


    tvec3i r1 = {
            789, 970, 1332
    };

    EXPECT_EQ(mul(c, a), r1);
    EXPECT_EQ(c*a, r1);
}

// trans

TEST(trans, mattranspose2x3) {

    tmat2x3i a = {
            2,  3,  5,
            11, 13, 17
    };

    tmat3x2i b = {
            2, 11,
            3, 13,
            5, 17

    };

    EXPECT_EQ(transpose(a),b);
}