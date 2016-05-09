//
// Created by Vitali Kurlovich on 1/12/16.
//

#include "gtest/gtest.h"

#include "../TAffineMatrix3x3_test_types.h"
#include "../../vector/affinevector3/TAffineVector3_test_types.h"


TEST(affinematrix3x3, constructor) {
    tamat3x3i zero = {
            0, 0,
            0, 0,
            0, 0
    };

    EXPECT_EQ(tamat3x3i::zero(), zero);

    tamat3x3i a;

    EXPECT_EQ(a, zero);

    tamat3x3i num = {
            1,  2,
            3,  4,
            5,  6
    };

    tamat3x3i b(1,  2,
               3,  4,
               5,  6);

    EXPECT_EQ(num, b);

    EXPECT_EQ(num.row[0], tvec2i( 1,  2));
    EXPECT_EQ(num.row[1], tvec2i( 3,  4));
    EXPECT_EQ(num.row[2], tvec2i( 5,  6));


    EXPECT_EQ(b[0], tvec2i( 1,  2));
    EXPECT_EQ(b[1], tvec2i( 3,  4));
    EXPECT_EQ(b[2], tvec2i( 5,  6));

}




// Mul

TEST(multi, matmulta3x3xa3x3) {

    tamat3x3i a = {
            11, 13,
            19, 23,
            31, 37
    };

    tamat3x3i b = {
            61, 67,
            73, 79,
            89, 97
    };

    tamat3x3i r = {
            1620, 1764,
            2838, 3090,
            4681, 5097
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a * b, r);

    a*=b;
    EXPECT_EQ(a, r);
}

TEST(multi, matmulta3x3x3x4) {

    tamat3x3i a = {
            2,  3,
            7, 11,
            17, 19
    };

    tmat3x4i b = {

            29, 31, 37, 41,
            43, 47, 53, 59,
            61, 67, 71, 73

    };

    tmat3x4i r = {
            187, 203, 233, 259,
            676, 734, 842, 936,
            1371, 1487, 1707, 1891
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);
}

TEST(multi, matmulta3x3x3x3) {

    tamat3x3i a = {
            2,  3,
            7, 11,
            17, 19
    };

    tmat3x3i b = {

            29, 31, 37,
            43, 47, 53,
            61, 67, 71

    };

    tmat3x3i r = {
            187, 203, 233,
            676, 734, 842,
            1371, 1487, 1707
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);
}

TEST(multi, matmulta3x3x3x2) {

    tamat3x3i a = {
            2,  3,
            7, 11,
            17, 19
    };

    tmat3x2i b = {

            29, 31,
            43, 47,
            61, 67

    };

    tmat3x2i r = {
            187, 203,
            676, 734,
            1371, 1487
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);
}

TEST(multi, matmulta3x3x3x1) {

    tamat3x3i a = {
            2,  3,
            7, 11,
            17, 19
    };

    tmat3x1i b = {

            29,
            43,
            61

    };

    tmat3x1i r = {
            187,
            676,
            1371
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);
}


TEST(multi, matmult4x3xa3x3) {

    tmat4x3i a = {
            29, 31, 37,
            41, 43, 47,
            53, 59, 61,
            67, 71, 73
    };

    tamat3x3i b = {
            2,  3,
            7, 11,
            17, 19
    };


    tmat4x3i r = {
            904, 1131, 37,
            1182, 1489, 47,
            1556, 1967, 61,
            1872, 2369, 73
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);

    a*=b;
    EXPECT_EQ(a, r);
}


TEST(multi, matmult3x3xa3x3) {

    tmat3x3i a = {
            29, 31, 37,
            41, 43, 47,
            53, 59, 61
    };

    tamat3x3i b = {
            2,  3,
            7, 11,
            17, 19
    };


    tmat3x3i r = {
            904, 1131, 37,
            1182, 1489, 47,
            1556, 1967, 61
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);

    a*=b;
    EXPECT_EQ(a, r);
}

TEST(multi, matmult2x3xa3x3) {

    tmat2x3i a = {
            29, 31, 37,
            41, 43, 47
    };

    tamat3x3i b = {
            2,  3,
            7, 11,
            17, 19
    };


    tmat2x3i r = {
            904, 1131, 37,
            1182, 1489, 47
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);

    a*=b;
    EXPECT_EQ(a, r);
}


TEST(multi, matmult1x3xa3x3) {

    tmat1x3i a = {
            29, 31, 37
    };

    tamat3x3i b = {
            2,  3,
            7, 11,
            17, 19
    };


    tmat1x3i r = {
            904, 1131, 37
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);

    a*=b;
    EXPECT_EQ(a, r);
}


TEST(multi, matmulta3x3xvec3) {

    tamat3x3i a = {
             2,  3,
            11, 13,
            23, 29
    };

    tvec3i b = {
            59, 61, 71
    };


    tvec3i r = {
            301, 1442, 3197
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);

    r = {
            2422, 3029, 71
    };

    EXPECT_EQ(mul(b, a), r);
    EXPECT_EQ(b*a, r);

    b*=a;
    EXPECT_EQ(b, r);
}



TEST(multi, matmulta3x3xavec3) {

    tamat3x3i a = {
            2,  3,
            11, 13,
            23, 29
    };

    tavec3i b = {
            59, 61
    };


    tvec3i r = {
            301, 1442, 3127
    };

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(a*b, r);

    tavec3i rs = {
            812, 999
    };

    EXPECT_EQ(mul(b, a), rs);
    EXPECT_EQ(b*a, rs);

    b*=a;
    EXPECT_EQ(b, rs);
}

// det

TEST(det, matdeta3x3) {

    tamat3x3i a = {
            29, 31,
            41, 43,
            53, 59
    };
    EXPECT_EQ(determinant(a), -24);
}


// trans

TEST(trans, mattransposeaa3x3) {

    tamat3x3i a = {
            29, 31,
            41, 43,
            53, 59
    };

    tmat3x3i r = {
            29, 41, 53,
            31, 43, 59,
            0, 0, 1
    };

    EXPECT_EQ(transpose(a), r);
}


TEST(inverse, matinversea3x3) {

    tamat3x3f a = {
            29.f, 31.f,
            41.f, 43.f,
            53.f, 59.f
    };

    tamat3x3f r = {
            -(43.f/24.f), 31.f/24.f,
            41.f/24.f, -(29.f/24.f),
            -(35.f/6.f), 17.f/6.f
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

    EXPECT_FLOAT_EQ(inverse(a, sucess).m20, r.m20);
    EXPECT_EQ(sucess, true);
    EXPECT_FLOAT_EQ(inverse(a, sucess).m21, r.m21);
    EXPECT_EQ(sucess, true);

    tamat3x3f b = {
            29, 31,
            58, 62,
            53, 59
    };

    inverse(b, sucess);
    EXPECT_EQ(sucess, false);
}