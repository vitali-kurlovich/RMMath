//
// Created by Vitali Kurlovich on 12/20/15.
//

#include "gtest/gtest.h"

#include "../TMatrix4x1_test_types.h"

// ==

TEST(equali_op, matequal_op4x1) {
    tmat4x1i a = {
            -30,
            32,
            77,
            1
    };

    tmat4x1i b = {
            -30,
            32,
            77,
            1,
    };

    EXPECT_EQ(a, b);
    EXPECT_EQ(b, a);
    EXPECT_EQ(a, a);
    EXPECT_EQ(b, b);
}



// !=

TEST(nequali_op, matnequal_op4x1) {
    tmat4x1i a = {
            1,
            1,
            1,
            1,
    };

    tmat4x1i b = {
            -1,
            1,
            1,
            1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1,
            -1,
            1,
            1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1,
            1,
            -1,
            1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);



    b = {
            1,
            1,
            1,
            -1,
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

}