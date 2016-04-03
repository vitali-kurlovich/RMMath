//
// Created by Vitali Kurlovich on 12/25/15.
//

#include "gtest/gtest.h"

#include "../TMatrix1x1_test_types.h"

// ==

TEST(equali_op, matequal_op1x1) {
    tmat1x1i a = {
            -30
    };

    tmat1x1i b = {
            -30
    };

    EXPECT_EQ(a, b);
    EXPECT_EQ(b, a);
    EXPECT_EQ(a, a);
    EXPECT_EQ(b, b);
}


// !=

TEST(nequali_op, matnequal_op1x1) {
    tmat1x1i a = {
            1
    };

    tmat1x1i b = {
            -1
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

}