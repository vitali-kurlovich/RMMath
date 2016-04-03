//
// Created by Vitali Kurlovich on 1/13/16.
//

#include "gtest/gtest.h"

#include "../TAffineMatrix3x3_test_types.h"


// ==

TEST(equali_op, matequal_opa3x3) {
    tamat3x3i a = {
            -30, 20,
            32, 54,
            77, 88

    };

    tmat3x3i b = {
            -30, 20, 0,
            32, 54, 0,
            77, 88, 1
    };

    EXPECT_EQ(a, b);
    EXPECT_EQ(b, a);
    EXPECT_EQ(a, a);
    EXPECT_EQ(b, b);


    tamat3x3i c = {
            -30, 20,
            32, 54,
            77, 88

    };

    EXPECT_EQ(a, c);
    EXPECT_EQ(c, a);
}

