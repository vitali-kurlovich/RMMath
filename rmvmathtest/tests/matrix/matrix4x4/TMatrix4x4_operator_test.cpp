//
// Created by Vitali Kurlovich on 12/14/15.
//


#include "gtest/gtest.h"

#include "../TMatrix4x4_test_types.h"


// ==

TEST(equali_op, matequal_op4) {
    tmat4x4i a = {
            -30, 20, 55, 45,
            32, 54, 66, 112,
            77, 88, 99, 11,
            1,2,3,4
    };

    tmat4x4i b = {
            -30, 20, 55, 45,
            32, 54, 66, 112,
            77, 88, 99, 11,
            1,2,3,4
    };

    EXPECT_EQ(a, b);
    EXPECT_EQ(b, a);
    EXPECT_EQ(a, a);
    EXPECT_EQ(b, b);
}

// !=

TEST(nequali_op, matnequal_op4) {
    tmat4x4i a = {
            1, 1, 1, 1,
            1, 1, 1, 1,
            1, 1, 1, 1,
            1, 1, 1, 1,
    };

    tmat4x4i b = {
            -1,1, 1, 1,
            1, 1, 1, 1,
            1, 1, 1, 1,
            1, 1, 1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1,-1, 1, 1,
            1, 1, 1, 1,
            1, 1, 1, 1,
            1, 1, 1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    b = {
            1, 1,-1, 1,
            1, 1, 1, 1,
            1, 1, 1, 1,
            1, 1, 1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1, 1, 1,-1,
            1, 1, 1, 1,
            1, 1, 1, 1,
            1, 1, 1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1, 1, 1, 1,
            -1,1, 1, 1,
            1, 1, 1, 1,
            1, 1, 1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);



    b = {
            1, 1, 1, 1,
            1,-1, 1, 1,
            1, 1, 1, 1,
            1, 1, 1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    b = {
            1, 1, 1, 1,
            1, 1,-1, 1,
            1, 1, 1, 1,
            1, 1, 1, 1,

    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1, 1, 1, 1,
            1, 1, 1,-1,
            1, 1, 1, 1,
            1, 1, 1, 1,

    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1, 1, 1, 1,
            1, 1, 1, 1,
           -1,1, 1, 1,
            1, 1, 1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);



    b = {
            1, 1, 1, 1,
            1, 1, 1, 1,
            1,-1, 1, 1,
            1, 1, 1, 1,

    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    b = {
            1, 1, 1, 1,
            1, 1, 1, 1,
            1, 1,-1, 1,
            1, 1, 1, 1,


    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1, 1, 1, 1,
            1, 1, 1, 1,
            1, 1, 1,-1,
            1, 1, 1, 1,


    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1, 1, 1, 1,
            1, 1, 1, 1,
            1, 1, 1, 1,
            -1,1, 1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);



    b = {
            1, 1, 1, 1,
            1, 1, 1, 1,
            1, 1, 1, 1,
            1,-1, 1, 1,


    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    b = {
            1, 1, 1, 1,
            1, 1, 1, 1,
            1, 1, 1, 1,
            1, 1,-1, 1,

    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1, 1, 1, 1,
            1, 1, 1, 1,
            1, 1, 1, 1,
            1, 1, 1,-1,

    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


}