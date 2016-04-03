//
// Created by Vitali Kurlovich on 12/23/15.
//

#include "gtest/gtest.h"

#include "../TMatrix2x3_test_types.h"

// ==

TEST(equali_op, matequal_op2x3) {
    tmat2x3i a = {
            -30, 20, 12,
            32, 54, 45,
    };

    tmat2x3i b = {
            -30, 20, 12,
            32, 54, 45,
    };

    EXPECT_EQ(a, b);
    EXPECT_EQ(b, a);
    EXPECT_EQ(a, a);
    EXPECT_EQ(b, b);
}


// !=

TEST(nequali_op, matnequal_op2x3) {
    tmat2x3i a = {
            1, 1, 1,
            1, 1, 1,
    };

    tmat2x3i b = {
            -1, 1, 1,
             1, 1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1 -1, 1,
            1, 1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1, 1,-1,
            1, 1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);



    b = {
             1, 1, 1,
            -1, 1, 1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    b = {
            1, 1, 1,
            1,-1, 1
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1, 1, 1,
            1, 1,-1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

}