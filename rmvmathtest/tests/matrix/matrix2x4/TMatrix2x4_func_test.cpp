//
// Created by Vitali Kurlovich on 12/24/15.
//

#include "gtest/gtest.h"

#include "../TMatrix2x4_test_types.h"



TEST(matrix2x4, constructor) {

    tmat2x4i zero = {
            0, 0, 0, 0,
            0, 0, 0, 0
    };

    EXPECT_EQ(tmat2x4i::zero(), zero);

    tmat2x4i a;

    EXPECT_EQ(a, zero);

    tmat2x4i num = {
            1,  2,  3, 4,
            5,  6,  7, 8
    };

    tmat2x4i b(1,   2,  3, 4,
               5,   6,  7, 8);

    EXPECT_EQ(num, b);

    EXPECT_EQ(num.row[0], tvec4i(1, 2, 3, 4));
    EXPECT_EQ(num.row[1], tvec4i(5, 6, 7, 8));

    EXPECT_EQ(b[0], tvec4i(1, 2, 3, 4));
    EXPECT_EQ(b[1], tvec4i(5, 6, 7, 8));


    tmat2x4i d( tvec4i(1, 2, 3, 4), tvec4i(5, 6, 7, 8));

    EXPECT_EQ(d, num);

    tmat2x4i e(tvec4i(1, 2, 3, 4));

    tmat2x4i result(1,2,3,4);

    EXPECT_EQ(e, result);

    tmat2x4i c(num);
    EXPECT_EQ(c, num);
}



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