//
// Created by Vitali Kurlovich on 12/22/15.
//

#include "gtest/gtest.h"

#include "../TMatrix3x1_test_types.h"


TEST(matrix3x1, constructor) {
    tmat3x1i zero = {
            0,
            0,
            0
    };

    EXPECT_EQ(tmat3x1i::zero(), zero);

    tmat3x1i a;

    EXPECT_EQ(a, zero);

    tmat3x1i num = {
            1,
            2,
            3
    };

    tmat3x1i b(1,
               2,
               3);

    EXPECT_EQ(num, b);

    EXPECT_EQ(num.row[0], 1);
    EXPECT_EQ(num.row[1], 2);
    EXPECT_EQ(num.row[2], 3);


    EXPECT_EQ(b[0], 1);
    EXPECT_EQ(b[1], 2);
    EXPECT_EQ(b[2], 3);

}



// Mul

TEST(multi, matmult3x1x1x4) {

    tmat3x1i a = {
            2,
            3,
            5
    };

    tmat1x4i b = {
            11, 13, 17, 19
    };

    tmat3x4i r = {
            22, 26, 34, 38,
            33, 39, 51, 57,
            55, 65, 85, 95
    };

    EXPECT_EQ(mul(a, b), r);

    EXPECT_EQ(a*b, r);
}


TEST(multi, matmult3x1x1x3) {

    tmat3x1i a = {
            2,
            3,
            5
    };

    tmat1x3i b = {
            11, 13, 17
    };

    tmat3x3i r = {
            22, 26, 34,
            33, 39, 51,
            55, 65, 85
    };

    EXPECT_EQ(mul(a, b), r);

    EXPECT_EQ(a*b, r);
}


TEST(multi, matmult3x1x1x2) {

    tmat3x1i a = {
            2,
            3,
            5
    };

    tmat1x2i b = {
            11, 13
    };

    tmat3x2i r = {
            22, 26,
            33, 39,
            55, 65
    };

    EXPECT_EQ(mul(a, b), r);

    EXPECT_EQ(a*b, r);
}


TEST(multi, matmult3x1x1x1) {

    tmat3x1i a = {
            2,
            3,
            5
    };

    tmat1x1i b = {
            11
    };

    tmat3x1i r = {
            22,
            33,
            55
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);

    a*=b;
    EXPECT_EQ(a, r);
}


TEST(multi, matmult3x1xvec) {

    tmat3x1i a = {
            2,
            11,
            23,

    };

    int b = 59;

    tvec3i r = {
            118, 649, 1357
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);

    tvec3i c = {
            59, 61, 71
    };

    EXPECT_EQ(mul(c, a), 2422);
    EXPECT_EQ(c*a, 2422);
}


// trans

TEST(trans, mattranspose3x1) {

    tmat3x1i a = {
            59,
            73,
            97
    };

    tmat1x3i b = {
            59, 73, 97
    };

    EXPECT_EQ(transpose(a),b);
}