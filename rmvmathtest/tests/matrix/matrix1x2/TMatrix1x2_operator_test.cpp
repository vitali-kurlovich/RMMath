//
// Created by Vitali Kurlovich on 12/25/15.
//

#include "gtest/gtest.h"

#include "../TMatrix1x2_test_types.h"

// ==

TEST(equali_op, matequal_op1x2) {
    tmat1x2i a = {
            -30, 20
    };

    tmat1x2i b = {
            -30, 20
    };

    EXPECT_EQ(a, b);
    EXPECT_EQ(b, a);
    EXPECT_EQ(a, a);
    EXPECT_EQ(b, b);
}

// !=

TEST(nequali_op, matnequal_op1x2) {
    tmat1x2i a = {
            1, 1
    };

    tmat1x2i b = {
            -1, 1
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    b = {
            1, -1
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

}