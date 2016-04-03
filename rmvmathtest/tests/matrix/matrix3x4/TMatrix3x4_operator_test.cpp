//
// Created by Vitali Kurlovich on 12/18/15.
//

#include "gtest/gtest.h"

#include "../TMatrix4x3_test_types.h"

// ==

TEST(equali_op, matequal_op3x4) {
    tmat3x4i a = {
            -30, 20, 55, 32,
            54, 66, 77, 88,
            99,1,2,3
    };

    tmat3x4i b = {
            -30, 20, 55, 32,
            54, 66, 77, 88,
            99, 1,2,3
    };

    EXPECT_EQ(a, b);
    EXPECT_EQ(b, a);
    EXPECT_EQ(a, a);
    EXPECT_EQ(b, b);
}
