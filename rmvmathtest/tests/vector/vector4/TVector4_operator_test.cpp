//
// Created by Vitali Kurlovich on 12/12/15.
//

#include "gtest/gtest.h"

#include "TVector4_test_types.h"

// []
TEST(arrayi_op, arr_op4) {
    tvec4i a = {-30, 20, -4, 888};


    EXPECT_EQ(a[0], -30);
    EXPECT_EQ(a[1], 20);
    EXPECT_EQ(a[2], -4);
    EXPECT_EQ(a[3], 888);
}

// ==

TEST(equali_op, equal_op4) {
    tvec4i a = {-30, 20, -4, 888};
    tvec4i b = {-30, 20, -4, 888};

    EXPECT_EQ(a, b);
    EXPECT_EQ(b, a);
    EXPECT_EQ(a, a);
    EXPECT_EQ(b, b);
}


// !=

TEST(nequali_op, nequal_op4) {
    tvec4i a = {5, 1, 1, 1};
    tvec4i b = {1, 1, 1, 1};

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    a = {1, 5, 1, 1};
    b = {1, 1, 1, 1};

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);


    a = {1, 1, 5, 1};
    b = {1, 1, 1, 1};

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    a = {1, 1, 1, 5};
    b = {1, 1, 1, 1};

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

}



// +

TEST(sumi_op, sum_op4) {
    tvec4i a = {-30, 20, 3, 44};
    tvec4i b = {10, 50, -5, 32};

    tvec4i r = {-20, 70, -2, 76};

    EXPECT_EQ(a+b, r);

    r = {-20, 30, 13, 54};

    EXPECT_EQ(a + 10, r);
    EXPECT_EQ(10 + a, r);

    a += 10;
    EXPECT_EQ(a, r);
}


// -

TEST(subi_op, sub_op3) {
    tvec4i a = {-30, 20, 3, 44};
    tvec4i b = {10, 50, -5, 32};

    tvec4i r = {-40, -30, 8, 12};

    EXPECT_EQ(a - b, r);

    r = {-40, 10, -7, 34};

    EXPECT_EQ(a - 10, r);

    r = {40, -10, 7, -34};
    EXPECT_EQ(10 - a, r);

    a -= 10;
    r = {-40, 10, -7, 34};
    EXPECT_EQ(a, r);
}


// *

TEST(mulf_op, mul_op4) {

    tvec4i a = {-30, 20, 3, 44};
    tvec4i b = {10, 50, -5, 32};

    tvec4i r = {-300, 1000, -15, 1408};

    EXPECT_EQ(a * b, r);
    r = {-690, 460, 69, 1012};
    EXPECT_EQ(a * 23, r);
    EXPECT_EQ(23 * a, r);

    a *= 23;
    EXPECT_EQ(a, r);

}


// /

TEST(divf_op, div_op4) {
    tvec4f a = {-30, 20, 3, 44};
    tvec4f b = {10, 50, -5, 32};

    tvec4f r = {-3.f, 2.f/5.f, -(3.f/5.f), 11.f/8.f};
    EXPECT_EQ(a / b, r);

    r = {-(15.f/4.f), 5.f/2.f, 3.f/8.f, 11.f/2.f};
    EXPECT_EQ(a / 8.f, r);

    r = {-(4.f/15.f), 2.f/5.f, 8.f/3.f, 2.f/11.f};
    EXPECT_EQ(8.f/a , r);

    r = {-(15.f/4.f), 5.f/2.f, 3.f/8.f, 11.f/2.f};

    a /= 8.f;
    EXPECT_EQ(a , r);

}
