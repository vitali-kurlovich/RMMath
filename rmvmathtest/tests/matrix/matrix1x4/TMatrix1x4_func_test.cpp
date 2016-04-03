//
// Created by Vitali Kurlovich on 12/25/15.
//

#include "gtest/gtest.h"

#include "../TMatrix1x4_test_types.h"


/*

 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107

 */



// Mul


TEST(multi, matmult1x4x4x4) {
    tmat1x4i a = {
            2,  3,  5,  7
    };

    tmat4x4i b = {
            29, 31, 37, 41,
            43, 47, 53, 59,
            61, 67, 71, 73,
            79, 83, 89, 97
    };

    tmat1x4i r = {
            1045, 1119, 1211, 1303
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);

    a*=b;
    EXPECT_EQ(a, r);
}


TEST(multi, matmult1x4x4x3) {
    tmat1x4i a = {
            2,  3,  5,  7
    };

    tmat4x3i b = {
            29, 31, 37,
            43, 47, 53,
            61, 67, 71,
            79, 83, 89
    };

    tmat1x3i r = {
            1045, 1119, 1211
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);
}

TEST(multi, matmult1x4x4x2) {
    tmat1x4i a = {
            2,  3,  5,  7
    };

    tmat4x2i b = {
            29, 31,
            43, 47,
            61, 67,
            79, 83
    };

    tmat1x2i r = {
            1045, 1119
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);
}


TEST(multi, matmult1x4x4x1) {
    tmat1x4i a = {
            2,  3,  5,  7
    };

    tmat4x1i b = {
            29,
            43,
            61,
            79
    };

    tmat1x1i r = {
            1045
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);
}

// trans

TEST(trans, mattranspose1x4) {

    tmat1x4i a = {
            2,  3,  5,  7,
    };

    tmat4x1i b = {
            2,
            3,
            5,
            7
    };

    EXPECT_EQ(transpose(a),b);
}