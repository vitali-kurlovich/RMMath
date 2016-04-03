//
// Created by Vitali Kurlovich on 12/24/15.
//

#include "gtest/gtest.h"

#include "../TMatrix2x4_test_types.h"


/*

 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107

 */

// Mul


TEST(multi, matmult2x4x4x4) {
    tmat2x4i a = {
            2,  3,  5,  7,
            11, 13, 17, 19,
    };

    tmat4x4i b = {
            29, 31, 37, 41,
            43, 47, 53, 59,
            61, 67, 71, 73,
            79, 83, 89, 97
    };

    tmat2x4i r = {
            1045, 1119, 1211, 1303,
            3416, 3668, 3994, 4302
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);


    a*=b;
    EXPECT_EQ(a, r);
}

TEST(multi, matmult2x4x4x3) {
    tmat2x4i a = {
            2,  3,  5,  7,
            11, 13, 17, 19,
    };

    tmat4x3i b = {
            29, 31, 37,
            43, 47, 53,
            61, 67, 71,
            79, 83, 89
    };

    tmat2x3i r = {
            1045, 1119, 1211,
            3416, 3668, 3994
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);
}

TEST(multi, matmult2x4x4x2) {
    tmat2x4i a = {
            2,  3,  5,  7,
            11, 13, 17, 19,
    };

    tmat4x2i b = {
            29, 31,
            43, 47,
            61, 67,
            79, 83
    };

    tmat2x2i r = {
            1045, 1119,
            3416, 3668
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);
}


TEST(multi, matmult2x4x4x1) {
    tmat2x4i a = {
            2,  3,  5,  7,
            11, 13, 17, 19,
    };

    tmat4x1i b = {
            29,
            43,
            61,
            79
    };

    tmat2x1i r = {
            1045,
            3416
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);
}


TEST(multi, matmult2x4xvec) {

    tmat2x4i a = {
            2, 3, 5, 7,
            11, 13, 17, 19
    };

    tvec4i b = {
            59, 61, 71, 73
    };


    tvec2i r = {
            1167, 4036
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);

    tvec2i c = {
            59, 61
    };


    tvec4i r1 = {
            789, 970, 1332, 1572
    };

    EXPECT_EQ(mul(c, a), r1);
    EXPECT_EQ(c*a, r1);
}

// trans

TEST(trans, mattranspose2x4) {

    tmat2x4i a = {
            2,  3,  5,  7,
            11, 13, 17, 19
    };

    tmat4x2i b = {
            2, 11,
            3, 13,
            5, 17,
            7, 19

    };

    EXPECT_EQ(transpose(a),b);
}