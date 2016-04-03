//
// Created by Vitali Kurlovich on 12/14/15.
//

#include "gtest/gtest.h"

#include "../TMatrix3x3_test_types.h"


// *

TEST(muli_op, matmul_op3) {
    tmat3x3i a = {
            -30, 20, 45,
            32, 54, 67,
            77, 88, 99
    };

    tmat3x3i b = {
            -3, 23, 42,
            26, -48, -7,
            4, 54, -3
    };


    tmat3x3i rab = {
            790, 780, -1535,
            1576, 1762, 765,
            2453, 2893, 2321
    };

    tmat3x3i rba = {
            4060, 4878, 5564,
            -2855, -2688, -2739,
            1377, 2732, 3501
    };

    EXPECT_EQ(a*b , rab);
    EXPECT_EQ(b*a , rba);

    a *= b;
    EXPECT_EQ(a , rab);
}


// ==

TEST(equali_op, matequal_op3) {
    tmat3x3i a = {
            -30, 20, 55,
            32, 54, 66,
            77, 88, 99
    };

    tmat3x3i b = {
            -30, 20, 55,
            32, 54, 66,
            77, 88, 99
    };

    EXPECT_EQ(a, b);
    EXPECT_EQ(b, a);
    EXPECT_EQ(a, a);
    EXPECT_EQ(b, b);
}


// !=

TEST(nequali_op, matnequal_op3) {
    tmat3x3i a = {
            1, 1, 1,
            1, 1, 1,
            1, 1, 1
    };

    tmat3x3i b = {
            -1,  1,  1,
             1,  1,  1,
             1,  1,  1
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    b = {
            1, -1,  1,
            1,  1,  1,
            1,  1,  1
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    b = {
            1,  1, -1,
            1,  1,  1,
            1,  1,  1
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    b = {
             1,  1,  1,
            -1,  1,  1,
             1,  1,  1
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1,  1,  1,
            1, -1,  1,
            1,  1,  1
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1,  1,  1,
            1,  1, -1,
            1,  1,  1
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    b = {
            1,  1,  1,
            1,  1,  1,
           -1,  1,  1
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
             1,  1,  1,
             1,  1,  1,
             1, -1,  1
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1,  1,  1,
            1,  1,  1,
            1,  1, -1
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);
}
