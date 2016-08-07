//
// Created by Vitali Kurlovich on 1/10/16.
//

#include "gtest/gtest.h"

#include "../TAffineMatrix4x4_test_types.h"
#include "../../vector/affinevector4/TAffineVector4_test_types.h"


TEST(affinematrix4x4, constructor) {
    tamat4x4i identity = {
            1, 0, 0,
            0, 1, 0,
            0, 0, 1,
            0, 0, 0
    };

    EXPECT_EQ(tamat4x4i::identity(), identity);

    tamat4x4i zero = {
            0, 0, 0,
            0, 0, 0,
            0, 0, 0,
            0, 0, 0
    };

    EXPECT_EQ(tamat4x4i::zero(), zero);

    tamat4x4i a;
    EXPECT_EQ(a, zero);

    tamat4x4i num = {
             1,  2,  3,
             4,  5,  6,
             7,  8,  9,
            10, 11, 12
    };

    tamat4x4i b(1,  2,  3,
                4,  5,  6,
                7,  8,  9,
                10, 11, 12);

    EXPECT_EQ(num, b);

    EXPECT_EQ(num.row[0], tvec3i(1, 2, 3));
    EXPECT_EQ(num.row[1], tvec3i(4, 5, 6));
    EXPECT_EQ(num.row[2], tvec3i(7, 8, 9));
    EXPECT_EQ(num.row[3], tvec3i(10, 11, 12));



    EXPECT_EQ(b[0], tvec3i(1, 2, 3));
    EXPECT_EQ(b[1], tvec3i(4, 5, 6));
    EXPECT_EQ(b[2], tvec3i(7, 8, 9));
    EXPECT_EQ(b[3], tvec3i(10, 11, 12));

    tamat4x4i d( tvec3i(1, 2, 3), tvec3i(4, 5, 6), tvec3i(7, 8, 9), tvec3i(10, 11, 12));

    EXPECT_EQ(d, num);

    tamat4x4i e(tvec3i(1, 2, 3));

    tamat4x4i result(1, 2, 3);

    EXPECT_EQ(e, result);

    tamat4x4i c(num);
    EXPECT_EQ(c, num);

}


// Mul

TEST(multi, matmulta4x4xa4x4) {

    tamat4x4i a = {
            11,13,17,
            19,23,29,
            31,37,41,
            43,47,53
    };

    tamat4x4i b = {
            61, 67, 71,
            73, 79, 83,
            89, 97, 101,
            103,107,109
    };

    tamat4x4i r = {
            3133, 3413, 3577,
            5419, 5903, 6187,
            8241, 8977, 9413,
            10874, 11842, 12416
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a * b, r);

    a*=b;
    EXPECT_EQ(a, r);
}

/*

 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163,167, 173, 179, 181, 191, 193, 197


 */

TEST(multi, matmulta4x4x4x4) {

    tamat4x4i a = {
            11,13,17,
            19,23,29,
            31,37,41,
            43,47,53
    };

    tmat4x4i b = {
            59, 61, 67, 71,
            73, 79, 83, 89,
            97, 101,103,107,
            109,113,127,131

    };

    tmat4x4i r = {
            3247, 3415, 3567, 3757,
            5613, 5905, 6169, 6499,
            8507, 8955, 9371, 9881,
            11218, 11802, 12368, 13038
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a * b, r);
}

TEST(multi, matmult4x4xa4x4) {

    tmat4x4i a = {
            59, 61, 67, 71,
            73, 79, 83, 89,
            97, 101,103,107,
            109,113,127,131

    };

    tamat4x4i b = {
            11,13,17,
            19,23,29,
            31,37,41,
            43,47,53
    };

    tmat4x4i r = {
            6938, 7986, 9282, 71,
            8704, 10020, 11652, 89,
            10780, 12424, 14472, 107,
            12916, 14872, 17280, 131
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a * b, r);

    a*=b;
    EXPECT_EQ(a, r);
}


TEST(multi, matmulta4x4x4x3) {

    tamat4x4i a = {
            11,13,17,
            19,23,29,
            31,37,41,
            43,47,53
    };

    tmat4x3i b = {
            59, 61, 67,
            73, 79, 83,
            97, 101,103,
            109,113,127

    };

    tmat4x3i r = {
            3247, 3415, 3567,
            5613, 5905, 6169,
            8507, 8955, 9371,
            11218, 11802, 12368
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a * b, r);
}


TEST(multi, matmult3x4xa4x4) {
    tmat3x4i a = {
            59, 61, 67, 73,
            79, 83, 97, 101,
            103,109,113,127
    };

    tamat4x4i b = {
            11,13,17,
            19,23,29,
            31,37,41,
            43,47,53
    };

    tmat3x4i r = {
            7024, 8080, 9388, 73,
            9796, 11272, 13080, 101,
            12168, 13996, 16276, 127
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a * b, r);

    a*=b;
    EXPECT_EQ(a, r);
}


TEST(multi, matmulta4x4x4x2) {

    tamat4x4i a = {
            11,13,17,
            19,23,29,
            31,37,41,
            43,47,53
    };

    tmat4x2i b = {
            59, 61,
            73, 79,
            97, 101,
            109,113

    };

    tmat4x2i r = {
            3247, 3415,
            5613, 5905,
            8507, 8955,
            11218, 11802
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a * b, r);
}


TEST(multi, matmult2x4xa4x4) {
    tmat2x4i a = {
            59, 61, 67, 73,
            79, 83, 97, 101
    };

    tamat4x4i b = {
            11,13,17,
            19,23,29,
            31,37,41,
            43,47,53
    };

    tmat2x4i r = {
            7024, 8080, 9388, 73,
            9796, 11272, 13080, 101
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a * b, r);

    a*=b;
    EXPECT_EQ(a, r);
}


TEST(multi, matmulta4x4x4x1) {

    tamat4x4i a = {
            11,13,17,
            19,23,29,
            31,37,41,
            43,47,53
    };

    tmat4x1i b = {
            59,
            73,
            97,
            109

    };

    tmat4x1i r = {
            3247,
            5613,
            8507,
            11218
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a * b, r);
}


TEST(multi, matmult1x4xa4x4) {
    tmat1x4i a = {
            59, 61, 67, 73
    };

    tamat4x4i b = {
            11,13,17,
            19,23,29,
            31,37,41,
            43,47,53
    };

    tmat1x4i r = {
            7024, 8080, 9388, 73
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a * b, r);

    a*=b;
    EXPECT_EQ(a, r);
}



TEST(multi, matmulta4x4xvec4) {

    tamat4x4i a = {
             2,  3,  5,
            11, 13, 17,
            23, 29, 31,
            41, 43, 47
    };

    tvec4i b = {
            59, 61, 71, 73
    };


    tvec4i r = {
            656, 2649, 5327, 8452
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);

    r = {
            5415, 6168, 6964, 73
    };

    EXPECT_EQ(mul(b, a), r);
    EXPECT_EQ(b*a, r);

    b*=a;
    EXPECT_EQ(b, r);
}


TEST(multi, matmulta4x4xavec4) {

    tamat4x4i a = {
            2, 3, 5,
            11, 13, 17,
            23, 29, 31,
            41, 43, 47
    };

    tavec4i b = {
            59, 61, 7
    };

    tvec4i r = {
            336, 1561, 3343, 5372
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a * b, r);

    tavec4i rs = {
            991, 1216, 1596
    };

    EXPECT_EQ(mul(b, a), rs);
    EXPECT_EQ(b * a, rs);

    b *= a;
    EXPECT_EQ(b, rs);
}

// trans

TEST(trans, mattransposeaa4x4) {

    tamat4x4i a = {
            11, 13, 17,
            19, 23, 29,
            31, 37, 41,
            43, 47, 53
    };

    tmat4x4i r = {
            11, 19, 31, 43,
            13, 23, 37, 47,
            17, 29, 41, 53,
            0, 0, 0, 1
    };

    EXPECT_EQ(transpose(a), r);
}


// det

TEST(det, matdeta4x4) {

    tamat4x4i a = {
            11, 13, 17,
            19, 23, 29,
            31, 37, 41,
            43, 47, 53
    };

    EXPECT_EQ(determinant(a), -40);
}

TEST(inverse, matinversea4x4) {

    tamat4x4f a = {
            11.f, 13.f, 17.f,
            19.f, 23.f, 29.f,
            31.f, 37.f, 41.f,
            43.f, 47.f, 53.f
    };

    tamat4x4f r = {

            13.f/4.f, -(12.f/5.f), 7.f/20.f,
              -3.f, 19.f/10.f, -(1.f/10.f),
            1.f/4.f, 1.f/10.f, -(3.f/20.f),
                    -12.f, 43.f/5.f, -(12.f/5.f)

    };

    bool sucess;
    EXPECT_FLOAT_EQ(inverse(a, &sucess).m00, r.m00);
    EXPECT_EQ(sucess, true);
    EXPECT_FLOAT_EQ(inverse(a, &sucess).m01, r.m01);
    EXPECT_EQ(sucess, true);
    EXPECT_FLOAT_EQ(inverse(a, &sucess).m02, r.m02);
    EXPECT_EQ(sucess, true);

    EXPECT_FLOAT_EQ(inverse(a, &sucess).m10, r.m10);
    EXPECT_EQ(sucess, true);
    EXPECT_FLOAT_EQ(inverse(a, &sucess).m11, r.m11);
    EXPECT_EQ(sucess, true);
    EXPECT_FLOAT_EQ(inverse(a, &sucess).m12, r.m12);
    EXPECT_EQ(sucess, true);

    EXPECT_FLOAT_EQ(inverse(a, &sucess).m20, r.m20);
    EXPECT_EQ(sucess, true);
    EXPECT_FLOAT_EQ(inverse(a, &sucess).m21, r.m21);
    EXPECT_EQ(sucess, true);
    EXPECT_FLOAT_EQ(inverse(a, &sucess).m22, r.m22);
    EXPECT_EQ(sucess, true);

    EXPECT_FLOAT_EQ(inverse(a, &sucess).m30, r.m30);
    EXPECT_EQ(sucess, true);
    EXPECT_FLOAT_EQ(inverse(a, &sucess).m31, r.m31);
    EXPECT_EQ(sucess, true);
    EXPECT_FLOAT_EQ(inverse(a, &sucess).m32, r.m32);
    EXPECT_EQ(sucess, true);


    tamat4x4f b = {
            1, 2, 3,
            4, 8, 12,
            12, 16, 24,
            13, 14, 15,
    };

    inverse(b, &sucess);
    EXPECT_FALSE(sucess);

}
