//
// Created by Vitali Kurlovich on 12/12/15.
//

#include "gtest/gtest.h"

#include "../TMatrix2x2_test_types.h"


TEST(matrix2x2, constructor) {
    tmat2x2i identity = {
            1, 0,
            0, 1
    };

    EXPECT_EQ(tmat2x2i::identity(), identity);

    tmat2x2i zero = {
            0, 0,
            0, 0

    };

    EXPECT_EQ(tmat2x2i::zero(), zero);

    tmat2x2i a;

    EXPECT_EQ(a, zero);

    tmat2x2i num = {
            1,  2,
            3,  4
    };

    tmat2x2i b(1, 2,
               3, 4);

    EXPECT_EQ(num, b);

    EXPECT_EQ(num.row[0], tvec2i(1, 2));
    EXPECT_EQ(num.row[1], tvec2i(3, 4));

    EXPECT_EQ(b[0], tvec2i(1, 2));
    EXPECT_EQ(b[1], tvec2i(3, 4));

    tmat2x2i d( tvec2i(1, 2), tvec2i(3, 4));

    EXPECT_EQ(d, num);

    tmat2x2i e(tvec2i(1, 2));
    tmat2x2i result(1,2);

    EXPECT_EQ(e, result);

    tmat2x2i c(num);
    EXPECT_EQ(c, num);
}

// Mul


TEST(multi, matmult2x2x2x4) {
    tmat2x2i a = {
            2, 3,
            5, 7
    };

    tmat2x4i b = {
            11, 13, 17, 19,
            23, 29, 31, 37
    };

    tmat2x4i r = {
            91, 113, 127, 149,
            216, 268, 302, 354
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);
}

TEST(multi, matmult2x2x2x3) {
    tmat2x2i a = {
            2, 3,
            5, 7
    };

    tmat2x3i b = {
            11, 13, 17,
            23, 29, 31
    };

    tmat2x3i r = {
            91, 113, 127,
            216, 268, 302
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);
}


TEST(multi, matmult2x2x2x2) {
    tmat2x2i a = {
            2, 3,
            5, 7
    };

    tmat2x2i b = {
            11, 13,
            23, 29
    };

    tmat2x2i r = {
            91, 113,
            216, 268
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);

    a*=b;
    EXPECT_EQ(a, r);

}


TEST(multi, matmult2x2x2x1) {
    tmat2x2i a = {
            2, 3,
            5, 7
    };

    tmat2x1i b = {
            11,
            23
    };

    tmat2x1i r = {
            91,
            216
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);
}

TEST(multi, matmult2x2xvec) {

    tmat2x2i a = {
            2,  3,
            11, 13

    };

    tvec2i b = {
            59, 61
    };


    tvec2i r = {
            301, 1442
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);


    r = {
            789, 970
    };

    EXPECT_EQ(mul(b, a), r);
    EXPECT_EQ(b*a, r);

    b*=a;
    EXPECT_EQ(b, r);
}


// mattranspose

TEST(trans, mattranspose2x2) {
    tmat2x2i a = {
            5, -6,
            3, 8
    };

    tmat2x2i r = {
            5, 3,
            -6, 8
    };

    EXPECT_EQ(transpose(a), r);
}


// det

TEST(det, matdet2x2) {

    tmat2x2i a = {
            -180, 253,
            298, -289
    };

    EXPECT_EQ(determinant(a), -23374);

    tmat2x2i b = {
            1, 2,
            2, 4
    };

    EXPECT_EQ(determinant(b), 0);

}

TEST(inverse, matinverse2x2) {

    tmat2x2f a = {
            5, -6,
            3, 8
    };

    tmat2x2f r = {
            4.f/29.f, 3.f/29.f,
            -(3.f/58.f), 5.f/58.f
    };

    bool sucess;
    EXPECT_FLOAT_EQ(inverse(a, sucess).m00, r.m00);
    EXPECT_EQ(sucess, true);
    EXPECT_FLOAT_EQ(inverse(a, sucess).m01, r.m01);
    EXPECT_EQ(sucess, true);
    EXPECT_FLOAT_EQ(inverse(a, sucess).m10, r.m10);
    EXPECT_EQ(sucess, true);
    EXPECT_FLOAT_EQ(inverse(a, sucess).m11, r.m11);
    EXPECT_EQ(sucess, true);


    tmat2x2i b = {
            1, 2,
            2, 4
    };
    inverse(b,sucess);
    EXPECT_EQ(sucess, false);
}