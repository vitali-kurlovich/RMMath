//
// Created by Vitali Kurlovich on 3/17/16.
//

#include "gtest/gtest.h"

#include "TAffineVector4_test_types.h"

#include "../vector4/TVector4_test_types.h"

// ==

TEST(equali_op, equal_affineop4) {
    tavec4i a = {-30, 20, 4};
    tavec4i b = {-30, 20, 4};
    tvec4i c = {-30, 20, 4, 1};

    EXPECT_EQ(a, b);
    EXPECT_EQ(b, a);
    EXPECT_EQ(a, a);
    EXPECT_EQ(b, b);

    EXPECT_EQ(a, c);
    EXPECT_EQ(c, a);
}

// !=

TEST(nequali_op, nequal_affineop4) {
    tavec4i a = {-31, 20, 4};
    tavec4i b = {-30, 20, 4};
    tvec4i c = {-31, 20, 4, -1};

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    EXPECT_NE(a, c);
    EXPECT_NE(c, a);

    a = {-30, 21, 4};
    b = {-30, 20, 4};

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    c = {-30, 20, 4, 1};

    EXPECT_NE(a, c);
    EXPECT_NE(c, a);

    c = {-30, 21, 5, 1};

    EXPECT_NE(a, c);
    EXPECT_NE(c, a);
}


// Sum

TEST(sumi_op, sum_affineop4) {
    tavec4i a = {-30, 20, 10};
    tavec4i b = {10, 50, 5};
    tvec4i c = {5, 6, 7, 8};

    tvec4i r = {-20, 70, 15 ,2};

    EXPECT_EQ(a+b, r);

    r = {-25, 26, 17, 9};

    EXPECT_EQ(a+c, r);
    EXPECT_EQ(c+a, r);


    r = {-29, 21, 11, 2};

    EXPECT_EQ(a + 1, r);
    EXPECT_EQ(1 + a, r);
}

// Sub

TEST(sumi_op, sub_affineop4) {
    tavec4i a = {-30, 20, 60};
    tavec4i b = {10, 50, 40};
    tvec4i c = {50, 60, 70, 80};

    tvec4i r = {-40, -30, 20, 0};

    EXPECT_EQ(a-b, r);

    r = {-80, -40, -10, -79};

    EXPECT_EQ(a-c, r);

    r = {80, 40, 10, 79};
    EXPECT_EQ(c-a, r);

    r = {-32, 18, 58, -1};

    EXPECT_EQ(a - 2, r);

    r = {32, -18, -58, 1};
    EXPECT_EQ(2 - a, r);
}



// Mul

TEST(mulf_op, mul_affineop4) {
    tavec4i a = {10, 20, 30};
    tavec4i b = {2, 3, 4};
    tavec4i r = {20, 60, 120};

    EXPECT_EQ(a*b, r);

    tvec4i r1 = {30, 60, 90, 3};

    EXPECT_EQ(a*3, r1);
    EXPECT_EQ(3*a, r1);


    tvec4i c = {2, 3, 4, 5};
    r1 = {20, 60, 120, 5};

    EXPECT_EQ(a*c, r1);
    EXPECT_EQ(c*a, r1);
}


TEST(mulf_op,div_affineop4) {
    tavec4f a = {-10.5f, 2.5f, 8.f};
    tavec4f b = {1.5f, 5.f, 6.f};

    tavec4f r = {-10.5f*(1/1.5f), 2.5f*(1/5.f), 8.f*(1/6.f)};

    EXPECT_EQ(a/b, r);

    tvec4f r1 = {-10.5f*(1/3.5f), 2.5f*(1/3.5f), 8.f*(1/3.5f), 1/3.5f};

    EXPECT_EQ(a/3.5f, r1);
    r1 = {3.5f/-10.5f, 3.5f/2.5f,3.5f/8.f, 3.5f};
    EXPECT_EQ(3.5f/a, r1);

    a = {1.4f, 1.8f, 2.2f};
    tvec4f c = {1.5f, 5.f, 10.f, 3.f};

    r1 = {1.4f/1.5f, 1.8f/5.f,  2.2f/10.f, 1/3.f};

    EXPECT_EQ(a/c, r1);

    r1 = {1.5f/1.4f, 5.f/1.8f, 10.f/2.2f, 3.f};
    EXPECT_EQ(c/a, r1);
}