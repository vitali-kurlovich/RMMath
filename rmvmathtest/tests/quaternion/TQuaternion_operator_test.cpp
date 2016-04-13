//
// Created by Vitali Kurlovich on 4/4/16.
//

#include "gtest/gtest.h"

#include "TQuaternion_test_types.h"

// ==

TEST(quaternion_op, equal) {
    tqti a = {-30, 20, -4, 3};
    tqti b = {-30, 20, -4, 3};

    EXPECT_EQ(a, b);
    EXPECT_EQ(b, a);
    EXPECT_EQ(a, a);
    EXPECT_EQ(b, b);
}


// !=

TEST(quaternion_op, nequal) {
    tqti a = {-30, 20, -4, 3};
    tqti b = {-31, 20, -4, 3};

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    a = {-30, 20, -4, 3};
    b = {-30, 21, -4, 3};

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    a = {-30, 20, -4, 3};
    b = {-30, 20, -5, 3};

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    a = {-30, 20, -4, 3};
    b = {-30, 20, -4, 4};

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);
}

