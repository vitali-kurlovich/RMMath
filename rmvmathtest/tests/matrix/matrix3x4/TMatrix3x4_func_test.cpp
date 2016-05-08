//
// Created by Vitali Kurlovich on 12/20/15.
//

#include "gtest/gtest.h"

#include "../TMatrix3x4_test_types.h"


TEST(matrix3x4, constructor) {

    tmat3x4i zero = {
            0, 0, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0
    };

    EXPECT_EQ(tmat3x4i::zero(), zero);

    tmat3x4i a;

    EXPECT_EQ(a, zero);

    tmat3x4i num = {
            1,   2,  3, 4,
            5,   6,  7, 8,
            9,  10, 11, 12
    };

    tmat3x4i b(1,   2,  3, 4,
               5,   6,  7, 8,
               9,  10, 11, 12);

    EXPECT_EQ(num, b);

    EXPECT_EQ(num.row[0], tvec4i(1, 2, 3, 4));
    EXPECT_EQ(num.row[1], tvec4i(5, 6, 7, 8));
    EXPECT_EQ(num.row[2], tvec4i(9, 10, 11, 12));

    
    EXPECT_EQ(b[0], tvec4i(1, 2, 3, 4));
    EXPECT_EQ(b[1], tvec4i(5, 6, 7, 8));
    EXPECT_EQ(b[2], tvec4i(9, 10, 11, 12));


    tmat3x4i d( tvec4i(1, 2, 3, 4), tvec4i(5, 6, 7, 8), tvec4i(9, 10, 11, 12));

    EXPECT_EQ(d, num);

    tmat3x4i e(tvec4i(1, 2, 3, 4));

    tmat3x4i result(1,2,3,4);

    EXPECT_EQ(e, result);

    tmat3x4i c(num);
    EXPECT_EQ(c, num);
}



TEST(multi, matmult3x4x4x4) {

    tmat3x4i a = {
            59, 61, 67, 71,
            73, 79, 83, 89,
            97, 101, 103, 107
    };

    tmat4x4i b = {
            2, 3, 5, 7,
            11, 13, 17, 19,
            23, 29, 31, 37,
            41, 43, 47, 53
    };


    tmat3x4i r = {
            5241, 5966, 6746, 7814,
            6573, 7480, 8464, 9800,
            8061, 9192, 10424, 12080
    };


    EXPECT_EQ(mul(a, b), r);

    EXPECT_EQ(a*b, r);

    a*=b;
    EXPECT_EQ(a, r);
}

TEST(multi, matmult3x4x4x3) {


    tmat3x4i a = {
            16, 15, 14, 12,
            11, 10, 8, 7,
            6, 4, 3, 2,
    };

    tmat4x3i b = {
            1, 2, 3,
            5, 6, 7,
            9, 10, 11,
            13, 14, 15,
    };


    tmat3x3i r = {

            373, 430, 487,
            224, 260, 296,
            79, 94, 109

    };

    EXPECT_EQ(mul(a, b), r);

    EXPECT_EQ(a*b, r);
}


TEST(multi, matmult3x4x4x2) {


    tmat3x4i a = {
            16, 15, 14, 12,
            11, 10, 8, 7,
            6, 4, 3, 2,
    };

    tmat4x2i b = {
            1, 2,
            5, 6,
            9, 10,
            13, 14,
    };


    tmat3x2i r = {
            373, 430,
            224, 260,
             79,  94
    };

    EXPECT_EQ(mul(a, b), r);

    EXPECT_EQ(a*b, r);
}


TEST(multi, matmult3x4x4x1) {

    tmat3x4i a = {
            16, 15, 14, 12,
            11, 10, 8, 7,
            6, 4, 3, 2,
    };

    tmat4x1i b = {
            1,
            5,
            9,
            13,
    };


    tmat3x1i r = {
            373,
            224,
            79,
    };

    EXPECT_EQ(mul(a, b), r);

    EXPECT_EQ(a*b, r);
}

TEST(multi, matmult3x4xvec) {

    tmat3x4i a = {
            2, 3, 5, 7,
            11, 13, 17, 19,
            23, 29, 31, 37
    };

    tvec4i b = {
            59, 61, 71, 73
    };


    tvec3i r = {
            1167, 4036, 8028
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);

    tvec3i c = {
            59, 61, 71
    };


    tvec4i r1 = {
            2422, 3029, 3533, 4199
    };

    EXPECT_EQ(mul(c, a), r1);
    EXPECT_EQ(c*a, r1);
}

// trans

TEST(trans, mattranspose3x4) {

    tmat3x4i a = {
            59, 61, 67, 71,
            73, 79, 83, 89,
            97, 101, 103, 107
    };

    tmat4x3i b = {
            59, 73, 97,
            61, 79, 101,
            67, 83, 103,
            71, 89, 107
    };

    EXPECT_EQ(transpose(a),b);
}