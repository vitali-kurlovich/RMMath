//
// Created by Vitali Kurlovich on 12/22/15.
//

#include "gtest/gtest.h"

#include "../TMatrix3x2_test_types.h"


// Mul

TEST(multi, matmult3x2x2x4) {

    tmat3x2i a = {
            2,  3,
            7, 11,
            17, 19,
    };

    tmat2x4i b = {
            29, 31, 37, 41,
            43, 47, 53, 59,
    };

    tmat3x4i r = {
            187, 203, 233, 259,
            676, 734, 842, 936,
            1310, 1420, 1636, 1818
    };

    EXPECT_EQ(mul(a, b), r);

    EXPECT_EQ(a*b, r);
}

TEST(multi, matmult3x2x2x3) {

    tmat3x2i a = {
            2,  3,
            7, 11,
            17, 19,
    };

    tmat2x3i b = {
            29, 31, 37,
            43, 47, 53,
    };

    tmat3x3i r = {
            187, 203, 233,
            676, 734, 842,
            1310, 1420, 1636
    };

    EXPECT_EQ(mul(a, b), r);

    EXPECT_EQ(a*b, r);
}

TEST(multi, matmult3x2x2x2) {

    tmat3x2i a = {
            2,  3,
            7, 11,
            17, 19,
    };

    tmat2x2i b = {
            29, 31,
            43, 47,
    };

    tmat3x2i r = {
            187, 203,
            676, 734,
            1310, 1420
    };

    EXPECT_EQ(mul(a, b), r);

    EXPECT_EQ(a*b, r);

    a*=b;
    EXPECT_EQ(a, r);
}


TEST(multi, matmult3x2x2x1) {

    tmat3x2i a = {
            2,  3,
            7, 11,
            17, 19,
    };

    tmat2x1i b = {
            29,
            43,
    };

    tmat3x1i r = {
            187,
            676,
            1310
    };

    EXPECT_EQ(mul(a, b), r);

    EXPECT_EQ(a*b, r);
}


TEST(multi, matmult3x2xvec) {

    tmat3x2i a = {
            2,  3,
            11, 13,
            23, 29,
    };

    tvec2i b = {
            59, 61
    };


    tvec3i r = {
            301, 1442, 3126
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);


    tvec3i c = {
            59, 61, 71
    };


    tvec2i r1 = {
            2422, 3029
    };

    EXPECT_EQ(mul(c, a), r1);
    EXPECT_EQ(c*a, r1);

}


// trans

TEST(trans, mattranspose3x2) {

    tmat3x2i a = {
            59, 61,
            73, 79,
            97, 101
    };

    tmat2x3i b = {
            59, 73, 97,
            61, 79, 101
    };

    EXPECT_EQ(transpose(a),b);
}