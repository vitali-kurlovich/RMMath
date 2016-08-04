//
// Created by Vitali Kurlovich on 8/4/16.
//

#include "gtest/gtest.h"

#include <math/math.hpp>

using namespace rmmath;

TEST(Math, equal_to_zero) {

    EXPECT_TRUE(equal_to_zero<int>(0));
    EXPECT_FALSE(equal_to_zero<int>(1));

    EXPECT_TRUE(equal_to_zero<float>(sinf(M_PI)));
    EXPECT_TRUE(equal_to_zero<float>(cosf(M_PI/2)));

    EXPECT_TRUE(equal_to_zero<float>(sinf(M_PI/2) + cosf(M_PI)));

    EXPECT_FALSE(equal_to_zero<double>((double)sinf(M_PI)));
    EXPECT_TRUE(equal_to_zero<double>(sin(M_PI)));

 }


TEST(Math, equal_to_one) {

    EXPECT_TRUE(equal_to_one<int>(1));
    EXPECT_FALSE(equal_to_one<int>(0));

    EXPECT_TRUE(equal_to_one<float>(sinf(M_PI/2)));
    EXPECT_TRUE(equal_to_one<float>(-cosf(M_PI)));

    EXPECT_TRUE(equal_to_one<float>(logf(M_E)));
    EXPECT_TRUE(equal_to_one<double>(sin(M_PI/2)));
}



TEST(Math, equal) {

    EXPECT_TRUE(equal<int>(10, 10));

    EXPECT_TRUE(equal<float>(logf(M_E), 1.f));
    EXPECT_FALSE(logf(M_E) == 1.f);
}