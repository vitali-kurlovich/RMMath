//
// Created by Vitali Kurlovich on 12/12/15.
//

#include "gtest/gtest.h"

#include "../TMatrix3x3_test_types.h"


TEST(matrix3x3, constructor) {
    tmat3x3i identity = {
            1, 0, 0,
            0, 1, 0,
            0, 0, 1

    };

    EXPECT_EQ(tmat3x3i::identity(), identity);

    tmat3x3i zero = {
            0, 0, 0,
            0, 0, 0,
            0, 0, 0
    };

    EXPECT_EQ(tmat3x3i::zero(), zero);

    tmat3x3i a;

    EXPECT_EQ(a, zero);

    tmat3x3i num = {
            1,   2,  3,
            4,   5,  6,
            7,   8,  9

    };

    tmat3x3i b(1,   2,  3,
               4,   5,  6,
               7,   8,  9);

    EXPECT_EQ(num, b);

    EXPECT_EQ(num.row[0], tvec3i(1, 2, 3));
    EXPECT_EQ(num.row[1], tvec3i(4, 5, 6));
    EXPECT_EQ(num.row[2], tvec3i(7, 8, 9));


    EXPECT_EQ(b[0], tvec3i(1, 2, 3));
    EXPECT_EQ(b[1], tvec3i(4, 5, 6));
    EXPECT_EQ(b[2], tvec3i(7, 8, 9));


    tmat3x3i d( tvec3i(1, 2, 3), tvec3i(4, 5, 6), tvec3i(7, 8, 9));

    EXPECT_EQ(d, num);

    tmat3x3i e(tvec3i(1, 2, 3));
    tmat3x3i result(1,2,3);

    EXPECT_EQ(e, result);

    tmat3x3i c(num);
    EXPECT_EQ(c, num);
}




// Mul

TEST(multi, matmult3x3x3x4) {

    tmat3x3i a = {
             2,  3,  5,
             7, 11, 13,
            17, 19, 23
    };

    tmat3x4i b = {

            29, 31, 37, 41,
            43, 47, 53, 59,
            61, 67, 71, 73

    };

    tmat3x4i r = {
             492,  538,  588, 624,
            1469, 1605, 1765, 1885,
            2713, 2961, 3269, 3497
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);
}

TEST(multi, matmult3x3x3x3) {

    tmat3x3i a = {
            1, 2, 3,
            4, 5, 6,
            7, 8, 9
    };

    tmat3x3i b = {
            9, 8, 7,
            6, 5, 4,
            3, 2, 1

    };

    tmat3x3i r = {
            30, 24, 18,
            84, 69, 54,
            138, 114, 90
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);

    a*=b;
    EXPECT_EQ(a, r);

}


TEST(multi, matmult3x3x3x2) {

    tmat3x3i a = {
            2,  3,  5,
            7, 11, 13,
            17, 19, 23
    };

    tmat3x2i b = {

            29, 31,
            43, 47,
            61, 67

    };

    tmat3x2i r = {
             492, 538,
            1469, 1605,
            2713, 2961
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);
}

TEST(multi, matmult3x3x3x1) {

    tmat3x3i a = {
            2,  3,  5,
            7, 11, 13,
            17, 19, 23
    };

    tmat3x1i b = {
            29,
            43,
            61
    };

    tmat3x1i r = {
            492,
            1469,
            2713
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);
}


TEST(multi, matmult3x3xvec) {

    tmat3x3i a = {
            2,  3,  5,
            11, 13, 17,
            23, 29, 31,
    };

    tvec3i b = {
            59, 61, 71
    };


    tvec3i r = {
            656, 2649, 5327
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);


    r = {
            2422, 3029, 3533
    };

    EXPECT_EQ(mul(b, a), r);
    EXPECT_EQ(b*a, r);

    b*=a;
    EXPECT_EQ(b, r);
}


// trans

TEST(trans, mattranspose3x3) {
    tmat3x3i a = {
            1, 2, 3,
            4, 5, 6,
            7, 8, 9
    };

    tmat3x3i r = {
            1, 4, 7,
            2, 5, 8,
            3, 6, 9
    };

    EXPECT_EQ(transpose(a), r);
}


// det

TEST(det, matdet3) {

    tmat3x3i a = {
            1, 2, 3,
            4, 5, 6,
            7, 8, 9
    };

    EXPECT_EQ(determinant(a), 0);


    tmat3x3i b = {
            2, 4, 6,
            8, 18, 15,
            7, 14, 16
    };

    EXPECT_EQ(determinant(b), -20);


}

TEST(inverse, matinverse3) {

    tmat3x3f a = {
            2.f, 4.f, 6.f,
            8.f, 18.f, 15.f,
            7.f, 14.f, 16.f
    };

    tmat3x3f r = {
            -(39.f / 10.f), -1.f, 12.f / 5.f,
            23.f / 20.f, 1.f / 2.f, -(9.f / 10.f),
            7.f / 10.f, 0.f, -(1.f / 5.f)
    };


    bool sucess;
    EXPECT_FLOAT_EQ(inverse(a, sucess).m00, r.m00);
    EXPECT_EQ(sucess, true);
    EXPECT_FLOAT_EQ(inverse(a, sucess).m01, r.m01);
    EXPECT_EQ(sucess, true);
    EXPECT_FLOAT_EQ(inverse(a, sucess).m02, r.m02);
    EXPECT_EQ(sucess, true);

    EXPECT_FLOAT_EQ(inverse(a, sucess).m10, r.m10);
    EXPECT_EQ(sucess, true);
    EXPECT_FLOAT_EQ(inverse(a, sucess).m11, r.m11);
    EXPECT_EQ(sucess, true);
    EXPECT_FLOAT_EQ(inverse(a, sucess).m12, r.m12);
    EXPECT_EQ(sucess, true);

    EXPECT_FLOAT_EQ(inverse(a, sucess).m20, r.m20);
    EXPECT_EQ(sucess, true);
    EXPECT_FLOAT_EQ(inverse(a, sucess).m21, r.m21);
    EXPECT_EQ(sucess, true);
    EXPECT_FLOAT_EQ(inverse(a, sucess).m22, r.m22);
    EXPECT_EQ(sucess, true);


    tmat3x3i b = {
            1, 2, 3,
            4, 5, 6,
            7, 8, 9
    };

    inverse(b, sucess);
    EXPECT_EQ(sucess, false);

}
