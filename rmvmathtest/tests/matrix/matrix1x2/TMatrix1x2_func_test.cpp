//
// Created by Vitali Kurlovich on 12/25/15.
//

#include "gtest/gtest.h"

#include "../TMatrix1x2_test_types.h"



TEST(matrix1x2, constructor) {

    tmat1x2i zero = {
            0, 0
    };

    EXPECT_EQ(tmat1x2i::zero(), zero);

    tmat1x2i a;

    EXPECT_EQ(a, zero);

    tmat1x2i num = {
            1,  2
    };

    tmat1x2i b(1, 2);

    EXPECT_EQ(num, b);

    EXPECT_EQ(num.row[0], tvec2i(1, 2));

    EXPECT_EQ(b[0], tvec2i(1, 2));

    tmat1x2i d( tvec2i(1, 2));

    EXPECT_EQ(d, num);

    tmat1x2i e(tvec2i(1, 2));

    tmat1x2i result(1, 2);

    EXPECT_EQ(e, result);

    tmat1x2i c(num);
    EXPECT_EQ(c, num);
}


// Mul

TEST(multi, matmult1x2x2x4) {
    tmat1x2i a = {
            2,  3,
    };

    tmat2x4i b = {
            29, 31, 37, 41,
            43, 47, 53, 59

    };

    tmat1x4i r = {
            187, 203, 233, 259
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);
}

TEST(multi, matmult1x2x2x3) {
    tmat1x2i a = {
            2,  3,
    };

    tmat2x3i b = {
            29, 31, 37,
            43, 47, 53

    };

    tmat1x3i r = {
            187, 203, 233
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);
}


TEST(multi, matmult1x2x2x2) {
    tmat1x2i a = {
            2,  3,
    };

    tmat2x2i b = {
            29, 31,
            43, 47

    };

    tmat1x2i r = {
            187, 203
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);

    a*=b;
    EXPECT_EQ(a, r);
}

TEST(multi, matmult1x2x2x1) {
    tmat1x2i a = {
            2,  3,
    };

    tmat2x1i b = {
            29,
            43

    };

    tmat1x1i r = {
            187
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);
}

// trans

TEST(trans, mattranspose1x2) {

    tmat1x2i a = {
            2,  3
    };

    tmat2x1i b = {
            2,
            3
    };

    EXPECT_EQ(transpose(a),b);
}