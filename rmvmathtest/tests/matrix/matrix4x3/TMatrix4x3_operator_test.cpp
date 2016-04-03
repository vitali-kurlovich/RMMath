//
// Created by Vitali Kurlovich on 12/16/15.
//

#include "gtest/gtest.h"

#include "../TMatrix4x3_test_types.h"

// ==

TEST(equali_op, matequal_op4x3) {
    tmat4x3i a = {
            -30, 20, 55,
            32, 54, 66,
            77, 88, 99,
            1,2,3
    };

    tmat4x3i b = {
            -30, 20, 55,
            32, 54, 66,
            77, 88, 99,
            1,2,3
    };

    EXPECT_EQ(a, b);
    EXPECT_EQ(b, a);
    EXPECT_EQ(a, a);
    EXPECT_EQ(b, b);
}


// !=

TEST(nequali_op, matnequal_op4x3) {
    tmat4x3i a = {
            1, 1, 1,
            1, 1, 1,
            1, 1, 1,
            1, 1, 1,
    };

    tmat4x3i b = {
            -1,1, 1,
            1, 1, 1,
            1, 1, 1,
            1, 1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1,-1, 1,
            1, 1, 1,
            1, 1, 1,
            1, 1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    b = {
            1, 1,-1,
            1, 1, 1,
            1, 1, 1,
            1, 1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);





    b = {
            1, 1, 1,
            -1,1, 1,
            1, 1, 1,
            1, 1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);



    b = {
            1, 1, 1,
            1,-1, 1,
            1, 1, 1,
            1, 1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    b = {
            1, 1, 1,
            1, 1,-1,
            1, 1, 1,
            1, 1, 1,

    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);



    b = {
            1, 1, 1,
            1, 1, 1,
            -1,1, 1,
            1, 1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);



    b = {
            1, 1, 1,
            1, 1, 1,
            1,-1, 1,
            1, 1, 1,

    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    b = {
            1, 1, 1,
            1, 1, 1,
            1, 1,-1,
            1, 1, 1,


    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    b = {
            1, 1, 1,
            1, 1, 1,
            1, 1, 1,
            -1,1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);



    b = {
            1, 1, 1,
            1, 1, 1,
            1, 1, 1,
            1,-1, 1,


    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    b = {
            1, 1, 1,
            1, 1, 1,
            1, 1, 1,
            1, 1,-1,

    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

}