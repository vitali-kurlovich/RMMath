//
// Created by Vitali Kurlovich on 3/17/16.
//

#include "gtest/gtest.h"

#include "TAffineVector3_test_types.h"

#include "../vector3/TVector3_test_types.h"

// []
TEST(affine_arrayi_op, arr_op3) {
    tavec3i a = {-30, 20};

    EXPECT_EQ(a[0], -30);
    EXPECT_EQ(a[1], 20);
    EXPECT_EQ(a[2], 1);
}



// ==

TEST(equali_op, equal_affineop3) {
    tavec3i a = {-30, 20};
    tavec3i b = {-30, 20};
    tvec3i c = {-30, 20, 1};

    EXPECT_EQ(a, b);
    EXPECT_EQ(b, a);
    EXPECT_EQ(a, a);
    EXPECT_EQ(b, b);

    EXPECT_EQ(a, c);
    EXPECT_EQ(c, a);
}

// !=

TEST(nequali_op, nequal_affineop3) {
    tavec3i a = {-31, 20};
    tavec3i b = {-30, 20};
    tvec3i c = {-31, 20, 7};

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    EXPECT_NE(a, c);
    EXPECT_NE(c, a);

     a = {-30, 21};
     b = {-30, 20};

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    c = {-30, 20, 1};

    EXPECT_NE(a, c);
    EXPECT_NE(c, a);
}


// Sum

TEST(sumi_op, sum_affineop3) {
    tavec3i a = {-30, 20};
    tavec3i b = {10, 50};
    tvec3i c = {5, 6, 7};

    tvec3i r = {-20, 70, 2};

    EXPECT_EQ(a+b, r);

    r = {-25, 26, 8};

    EXPECT_EQ(a+c, r);
    EXPECT_EQ(c+a, r);


    r = {-29, 21, 2};

    EXPECT_EQ(a + 1, r);
    EXPECT_EQ(1 + a, r);
}


// Sub

TEST(sumi_op, sub_affineop3) {
    tavec3i a = {-30, 20};
    tavec3i b = {10, 50};
    tvec3i c = {5, 6, 7};

    tvec3i r = {-40, -30, 0};

    EXPECT_EQ(a-b, r);

    r = {-35, 14, -6};

    EXPECT_EQ(a-c, r);

    r = {35, -14, 6};
    EXPECT_EQ(c-a, r);


    r = {-32, 18, -1};

    EXPECT_EQ(a - 2, r);

    r = {32, -18, 1};
    EXPECT_EQ(2 - a, r);
}


// Mul

TEST(mulf_op, mul_affineop3) {
    tavec3f a = {-10.5f, 2.5f};
    tavec3f b = {1.5f, 5.f};
    tavec3f r = {-10.5f*1.5f, 2.5f*5.f};

    EXPECT_EQ(a*b, r);


    tvec3f r1 = {-10.5f*3.5f, 2.5f*3.5f, 3.5f};

    EXPECT_EQ(a*3.5f, r1);
    EXPECT_EQ(3.5f*a, r1);

    a = {1.4f, 1.8f};
    tvec3f c = {1.5f, 5.f, 10.f};
    r1 = {1.4f*1.5f, 1.8f*5.f,  10.f};

    EXPECT_EQ(a*c, r1);
    EXPECT_EQ(c*a, r1);
}

// Div

TEST(mulf_op,div_affineop3) {
    tavec3f a = {-10.5f, 2.5f};
    tavec3f b = {1.5f, 5.f};

    tavec3f r = {-10.5f*(1/1.5f), 2.5f*(1/5.f)};

    EXPECT_EQ(a/b, r);

    tvec3f r1 = {-10.5f*(1/3.5f), 2.5f*(1/3.5f), 1/3.5f};

    EXPECT_EQ(a/3.5f, r1);
    r1 = {3.5f/-10.5f, 3.5f/2.5f, 3.5f};
    EXPECT_EQ(3.5f/a, r1);

    a = {1.4f, 1.8f};
    tvec3f c = {1.5f, 5.f, 10.f};

    r1 = {1.4f/1.5f, 1.8f/5.f,  1/10.f};

    EXPECT_EQ(a/c, r1);

    r1 = {1.5f/1.4f, 5.f/1.8f, 10.f};
    EXPECT_EQ(c/a, r1);
}