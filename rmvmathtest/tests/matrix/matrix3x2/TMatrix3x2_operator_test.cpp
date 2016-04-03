//
// Created by Vitali Kurlovich on 12/22/15.
//

#include "gtest/gtest.h"

#include "../TMatrix3x2_test_types.h"

// ==

TEST(equali_op, matequal_op3x2) {
tmat3x2i a = {
        -30, 20,
        32, 54,
        77, 88
};

tmat3x2i b = {
        -30, 20,
        32, 54,
        77, 88
};

EXPECT_EQ(a, b);
EXPECT_EQ(b, a);
EXPECT_EQ(a, a);
EXPECT_EQ(b, b);
}

// !=

TEST(nequali_op, matnequal_op3x2) {
    tmat3x2i a = {
            1, 1,
            1, 1,
            1, 1
    };

    tmat3x2i b = {
            -1, 1,
            1, 1,
            1, 1
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    b = {
            1,-1,
            1, 1,
            1, 1
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1, 1,
            -1, 1,
            1, 1
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1, 1,
            1, -1,
            1, 1
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    b = {
            1, 1,
            1, 1,
            -1, 1
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    b = {
            1, 1,
            1, 1,
            1, -1
    };

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

}