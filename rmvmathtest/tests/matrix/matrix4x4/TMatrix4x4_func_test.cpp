//
// Created by Vitali Kurlovich on 12/12/15.
//

#include "gtest/gtest.h"

#include "../TMatrix4x4_test_types.h"

TEST(matrix4x4, constructor) {
    tmat4x4i identity = {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
    };

    tmat4x4i a;

    EXPECT_EQ(a, identity);

    tmat4x4i num = {
            1,   2,  3, 4,
            5,   6,  7, 8,
            9,  10, 11, 12,
            13, 14, 15, 16
    };

    tmat4x4i b(1,   2,  3, 4,
               5,   6,  7, 8,
               9,  10, 11, 12,
               13, 14, 15, 16);

    EXPECT_EQ(num, b);

    EXPECT_EQ(num.row0, tvec4i(1, 2, 3, 4));
    EXPECT_EQ(num.row1, tvec4i(5, 6, 7, 8));
    EXPECT_EQ(num.row2, tvec4i(9, 10, 11, 12));
    EXPECT_EQ(num.row3, tvec4i(13, 14, 15, 16));


    tmat4x4i d( tvec4i(1, 2, 3, 4), tvec4i(5, 6, 7, 8), tvec4i(9, 10, 11, 12), tvec4i(13, 14, 15, 16));

    EXPECT_EQ(d, num);

    tmat4x4i e( tvec4i(1, 2, 3, 4));

    tmat4x4i result(1,2,3,4);

    EXPECT_EQ(e, result);




    tmat4x4i c(num);
    EXPECT_EQ(c, num);
}

// Mul

TEST(multi, matmult4x4x4x4) {

    tmat4x4i a = {
            1, 2, 3, 4,
            5, 6, 7, 8,
            9, 10, 11, 12,
            13, 14, 15, 16
    };

    tmat4x4i b = {
            16, 15, 14, 13,
            12, 11, 10, 9,
            8, 7, 6, 5,
            4, 3, 2, 1
    };

    tmat4x4i r = {
            80, 70, 60, 50,
            240, 214, 188, 162,
            400, 358, 316, 274,
            560, 502, 444, 386
    };

    MathStatistic::instance().resetAll();
    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ( MathStatistic::instance().mul(), 64);
    EXPECT_EQ( MathStatistic::instance().sum(), 48);

    EXPECT_EQ(a*b, r);

    MathStatistic::instance().resetAll();
    a*=b;
    EXPECT_EQ( MathStatistic::instance().mul(), 64);
    EXPECT_EQ( MathStatistic::instance().sum(), 48);

    EXPECT_EQ(a, r);


}


TEST(multi, matmult4x4x4x3) {

    tmat4x4i a = {
            2,  3,  5,  7,
            11, 13, 17, 19,
            23, 29, 31, 37,
            41, 43, 47, 53,
    };

    tmat4x3i b = {
            59, 61, 67,
            71, 73, 79,
            83, 89, 97,
            101, 103, 107,

    };


    tmat4x3i r = {
            1453, 1507, 1605,
            4902, 5090, 5446,
            9726, 10090, 10798,
            14726, 15282, 16374
    };

    MathStatistic::instance().resetAll();
    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ( MathStatistic::instance().mul(), 48);
    EXPECT_EQ( MathStatistic::instance().sum(), 36);

    EXPECT_EQ(a*b, r);

}

TEST(multi, matmult4x4x4x2) {

    tmat4x4i a = {
            2,  3,  5,  7,
            11, 13, 17, 19,
            23, 29, 31, 37,
            41, 43, 47, 53,
    };

    tmat4x2i b = {
            59, 61,
            71, 73,
            83, 89,
            101, 103,

    };


    tmat4x2i r = {
            1453, 1507,
            4902, 5090,
            9726, 10090,
            14726, 15282
    };

    MathStatistic::instance().resetAll();
    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ( MathStatistic::instance().mul(), 32);
    EXPECT_EQ( MathStatistic::instance().sum(), 24);

    EXPECT_EQ(a*b, r);

}

TEST(multi, matmult4x4x4x1) {

    tmat4x4i a = {
            2,  3,  5,  7,
            11, 13, 17, 19,
            23, 29, 31, 37,
            41, 43, 47, 53,
    };

    tmat4x1i b = {
            59,
            71,
            83,
            101,

    };


    tmat4x1i r = {
            1453,
            4902,
            9726,
            14726
    };

    MathStatistic::instance().resetAll();
    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ( MathStatistic::instance().mul(), 16);
    EXPECT_EQ( MathStatistic::instance().sum(), 12);
    EXPECT_EQ(a*b, r);
}



TEST(multi, matmult4x4xvec4) {

    tmat4x4i a = {
            2,  3,  5,  7,
            11, 13, 17, 19,
            23, 29, 31, 37,
            41, 43, 47, 53
    };

    tvec4i b = {
            59, 61, 71, 73
    };


    tvec4i r = {
            1167, 4036, 8028, 12248
    };

    MathStatistic::instance().resetAll();
    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ( MathStatistic::instance().mul(), 16);
    EXPECT_EQ( MathStatistic::instance().sum(), 12);

    EXPECT_EQ(a*b, r);

    r = {
            5415, 6168, 6964, 8068
    };

    EXPECT_EQ(mul(b, a), r);
    EXPECT_EQ(b*a, r);

    MathStatistic::instance().resetAll();
    b*=a;
    EXPECT_EQ(b, r);
    EXPECT_EQ( MathStatistic::instance().mul(), 16);
    EXPECT_EQ( MathStatistic::instance().sum(), 12);

}

// trans

TEST(trans, mattranspose4x4) {

    tmat4x4i a = {
            1, 2, 3, 4,
            5, 6, 7, 8,
            9, 10, 11, 12,
            13, 14, 15, 16
    };

    tmat4x4i r = {
            1, 5, 9, 13,
            2, 6, 10, 14,
            3, 7, 11, 15,
            4, 8, 12, 16
    };

    EXPECT_EQ(transpose(a), r);
}


// det

TEST(det, matdet4x4) {

    tmat4x4i a = {
            1, 2, 3, 4,
            5, 6, 7, 8,
            9, 10, 11, 12,
            13, 14, 15, 16
    };

    EXPECT_EQ(determinant(a), 0);

    tmat4x4i b = {
            1, 2, 3, 4,
            55, 76, 73, 9,
            19, 110, 141, 152,
            163, 144, 195, 169
    };

    EXPECT_EQ(determinant(b), -66416);

}

TEST(inverse, matinverse4x4) {

    tmat4x4f a = {
            1.f, 2.f, 3.f, 4.f,
            55.f, 76.f, 73.f, 9.f,
            19.f, 110.f, 141.f, 152.f,
            163.f, 144.f, 195.f, 169.f
    };

    tmat4x4f r = {
            3403.f / 1186.f, 51.f / 1186.f, -(67.f / 1186.f), -(23.f / 1186.f),
            540569.f / 33208.f, 651.f / 2372.f, -(1257.f / 4744.f), -(2683.f / 16604.f),
            -(330201.f / 16604.f), -(187.f / 593.f), 785.f / 2372.f, 788.f / 4151.f,
            104749.f / 16604.f, 105.f / 1186.f, -(241.f / 2372.f), -(471.f / 8302.f)
    };

    MathStatistic::instance().resetAll();
    bool sucess;
    EXPECT_FLOAT_EQ(inverse(a, sucess).m00, r.m00);
    EXPECT_EQ(sucess, true);
    EXPECT_EQ( MathStatistic::instance().mul(), 107);
    EXPECT_EQ( MathStatistic::instance().sum(), 23);
    EXPECT_EQ( MathStatistic::instance().sub(), 35);
    EXPECT_EQ( MathStatistic::instance().div(), 1);


    EXPECT_FLOAT_EQ(inverse(a, sucess).m01, r.m01);
    EXPECT_EQ(sucess, true);
    EXPECT_FLOAT_EQ(inverse(a, sucess).m02, r.m02);
    EXPECT_EQ(sucess, true);
    EXPECT_FLOAT_EQ(inverse(a, sucess).m03, r.m03);
    EXPECT_EQ(sucess, true);


    EXPECT_FLOAT_EQ(inverse(a, sucess).m10, r.m10);
    EXPECT_EQ(sucess, true);
    EXPECT_FLOAT_EQ(inverse(a, sucess).m11, r.m11);
    EXPECT_EQ(sucess, true);
    EXPECT_FLOAT_EQ(inverse(a, sucess).m12, r.m12);
    EXPECT_EQ(sucess, true);
    EXPECT_FLOAT_EQ(inverse(a, sucess).m13, r.m13);
    EXPECT_EQ(sucess, true);

    EXPECT_FLOAT_EQ(inverse(a, sucess).m20, r.m20);
    EXPECT_EQ(sucess, true);
    EXPECT_FLOAT_EQ(inverse(a, sucess).m21, r.m21);
    EXPECT_EQ(sucess, true);
    EXPECT_FLOAT_EQ(inverse(a, sucess).m22, r.m22);
    EXPECT_EQ(sucess, true);
    EXPECT_FLOAT_EQ(inverse(a, sucess).m23, r.m23);
    EXPECT_EQ(sucess, true);

    EXPECT_FLOAT_EQ(inverse(a, sucess).m30, r.m30);
    EXPECT_EQ(sucess, true);
    EXPECT_FLOAT_EQ(inverse(a, sucess).m31, r.m31);
    EXPECT_EQ(sucess, true);
    EXPECT_FLOAT_EQ(inverse(a, sucess).m32, r.m32);
    EXPECT_EQ(sucess, true);
    EXPECT_FLOAT_EQ(inverse(a, sucess).m33, r.m33);
    EXPECT_EQ(sucess, true);


    tmat4x4f b = {
            1, 2, 3, 4,
            5, 6, 7, 8,
            9, 10, 11, 12,
            13, 14, 15, 16
    };

    MathStatistic::instance().resetAll();
    inverse(b, sucess);
    EXPECT_EQ( MathStatistic::instance().mul(), 33);
    EXPECT_EQ( MathStatistic::instance().sum(), 8);
    EXPECT_EQ( MathStatistic::instance().sub(), 11);
    EXPECT_EQ( MathStatistic::instance().div(), 0);

    EXPECT_EQ(sucess, false);

}
