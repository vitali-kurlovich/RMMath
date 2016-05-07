//
// Created by Vitali Kurlovich on 12/16/15.
//

#include "gtest/gtest.h"

#include "../TMatrix4x3_test_types.h"

TEST(matrix4x3, constructor) {
    tmat4x3i zero = {
            0, 0, 0,
            0, 0, 0,
            0, 0, 0,
            0, 0, 0
    };

    tmat4x3i a;

    EXPECT_EQ(a, zero);

    tmat4x3i num = {
             1,  2,  3,
             4,  5,  6,
             7,  8,  9,
            10, 11, 12
    };

    tmat4x3i b(1,  2,  3,
               4,  5,  6,
               7,  8,  9,
               10, 11, 12);

    EXPECT_EQ(num, b);

    EXPECT_EQ(num.row[0], tvec3i( 1,  2,  3));
    EXPECT_EQ(num.row[1], tvec3i( 4,  5,  6));
    EXPECT_EQ(num.row[2], tvec3i( 7,  8,  9));
    EXPECT_EQ(num.row[3], tvec3i(10, 11, 12));

    EXPECT_EQ(b[0], tvec3i( 1,  2,  3));
    EXPECT_EQ(b[1], tvec3i( 4,  5,  6));
    EXPECT_EQ(b[2], tvec3i( 7,  8,  9));
    EXPECT_EQ(b[3], tvec3i(10, 11, 12));

//
//    tmat4x4i d( tvec4i(1, 2, 3, 4), tvec4i(5, 6, 7, 8), tvec4i(9, 10, 11, 12), tvec4i(13, 14, 15, 16));
//
//    EXPECT_EQ(d, num);
//
//    tmat4x4i e( tvec4i(1, 2, 3, 4));
//
//    tmat4x4i result(1,2,3,4);
//
//    EXPECT_EQ(e, result);
//
//    tmat4x4i c(num);
//    EXPECT_EQ(c, num);
}


// Mul

TEST(multi, matmult4x3x3x4) {

    tmat4x3i a = {
            1, 2, 3,
            5, 6, 7,
            9, 10, 11,
            13, 14, 15,
    };

    tmat3x4i b = {
            16, 15, 14, 12,
            11, 10, 8, 7,
            6, 4, 3, 2,
    };

    tmat4x4i r = {

                    56, 47, 39, 32,
                    188, 163, 139, 116,
                    320, 279, 239, 200,
                    452, 395, 339, 284

    };

    EXPECT_EQ(mul(a, b), r);

    EXPECT_EQ(a*b, r);
    
}


TEST(multi, matmult4x3x3x3) {

    tmat4x3i a = {
            1, 2, 3,
            5, 6, 7,
            9, 10, 11,
            13, 14, 15,
    };

    tmat3x3i b = {
            16, 15, 14,
            11, 10, 8,
             6,  4, 3,
    };

    tmat4x3i r = {
            56, 47, 39,
            188, 163, 139,
            320, 279, 239,
            452, 395, 339
    };

    EXPECT_EQ(mul(a, b), r);

    EXPECT_EQ(a*b, r);

    a*=b;
    EXPECT_EQ(a, r);

}


TEST(multi, matmult4x3x3x2) {

    tmat4x3i a = {
            1, 2, 3,
            5, 6, 7,
            9, 10, 11,
            13, 14, 15,
    };

    tmat3x2i b = {
            16, 15,
            11, 10,
            6,  4,
    };

    tmat4x2i r = {

            56, 47,
            188, 163,
            320, 279,
            452, 395

    };

    EXPECT_EQ(mul(a, b), r);

    EXPECT_EQ(a*b, r);

}

TEST(multi, matmult4x3x3x1) {

    tmat4x3i a = {
            1, 2, 3,
            5, 6, 7,
            9, 10, 11,
            13, 14, 15,
    };

    tmat3x1i b = {
            16,
            11,
            6,
    };

    tmat4x1i r = {

             56,
            188,
            320,
            452,

    };

    EXPECT_EQ(mul(a, b), r);

    EXPECT_EQ(a*b, r);

}

TEST(multi, matmult4x3xvec) {

    tmat4x3i a = {
            2,  3,  5,
            11, 13, 17,
            23, 29, 31,
            41, 43, 47
    };

    tvec3i b = {
            59, 61, 71
    };


    tvec4i r = {
            656, 2649, 5327, 8379
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);

    tvec4i c = {
            59, 61, 71, 73
    };


    tvec3i r1 = {
            5415, 6168, 6964
    };

    EXPECT_EQ(mul(c, a), r1);
    EXPECT_EQ(c*a, r1);
}

// trans

TEST(trans, mattranspose4x3) {

    tmat4x3i a = {
            1, 2, 3,
            5, 6, 7,
            9, 10, 11,
            13, 14, 15,
    };

    tmat3x4i b = {
            1, 5, 9, 13,
            2, 6, 10, 14,
            3, 7, 11, 15
    };

    EXPECT_EQ(transpose(a),b);
}