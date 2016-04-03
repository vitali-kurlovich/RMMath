//
// Created by Vitali Kurlovich on 12/25/15.
//

#include "gtest/gtest.h"

#include "../TMatrix1x1_test_types.h"


// Mul


TEST(multi, matmult1x1x1x4) {
    tmat1x1i a = {
            2,
    };

    tmat1x4i b = {
            29, 31, 37, 41
    };

    tmat1x4i r = {
            58, 62, 74, 82
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a * b, r);
}


TEST(multi, matmult1x1x1x3) {
    tmat1x1i a = {
            2,
    };

    tmat1x3i b = {
            29, 31, 37
    };

    tmat1x3i r = {
            58, 62, 74
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a * b, r);
}


TEST(multi, matmult1x1x1x2) {
    tmat1x1i a = {
            2,
    };

    tmat1x2i b = {
            29, 31
    };

    tmat1x2i r = {
            58, 62
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a * b, r);
}


TEST(multi, matmult1x1x1x1) {
    tmat1x1i a = {
            2,
    };

    tmat1x1i b = {
            29
    };

    tmat1x1i r = {
            58
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a * b, r);

    a *= b;
    EXPECT_EQ(a, r);

}

// trans

TEST(trans, mattranspose1x1) {

    tmat1x1i a = {
            2
    };

    tmat1x1i b = {
            2
    };

    EXPECT_EQ(transpose(a),b);
}

// det

TEST(det, matdet1x1) {

    tmat1x1i a = {
            -180
    };

    EXPECT_EQ(determinant(a), -180);

    tmat1x1i b = {
           0
    };

    EXPECT_EQ(determinant(b), 0);

}

TEST(inverse, matinverse1x1) {

    tmat1x1f a = {
            10.f
    };

    tmat1x1f r = {
            1.f/10.0f
    };

    bool sucess;
    EXPECT_EQ(inverse(a, sucess), r);
    EXPECT_EQ(sucess, true);

    tmat1x1i b = {
            0
    };
    inverse(b,sucess);
    EXPECT_EQ(sucess, false);
}