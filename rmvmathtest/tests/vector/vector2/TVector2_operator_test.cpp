//
// Created by Vitali Kurlovich on 12/11/15.
//

#include "gtest/gtest.h"

#include "TVector2_test_types.h"


// []
TEST(arrayi_op, arr_op2) {
    tvec2i a = {-30, 20};

    EXPECT_EQ(a[0], -30);
    EXPECT_EQ(a[1], 20);
}

// ==

TEST(equali_op, equal_op) {
    tvec2i a = {-30, 20};
    tvec2i b = {-30, 20};

    EXPECT_EQ(a, b);
    EXPECT_EQ(b, a);
    EXPECT_EQ(a, a);
    EXPECT_EQ(b, b);
}

TEST(equalf_op, equal_op) {
    tvec2f a = {-30.4f, 20.2f};
    tvec2f b = {-30.4f, 20.2f};

    EXPECT_EQ(a, b);
    EXPECT_EQ(b, a);
    EXPECT_EQ(a, a);
    EXPECT_EQ(b, b);
}

// !=

TEST(nequali_op, nequal_op) {
    tvec2i a = {-31, 20};
    tvec2i b = {-30, 20};

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    a = {-30, 20};
    b = {-30, 21};

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);
}

TEST(nequalf_op, nequal_op) {
    tvec2f a = {-30.4f, 20.1f};
    tvec2f b = {-30.4f, 20.2f};

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    a = b;
    EXPECT_EQ(a, b);
    EXPECT_EQ(b, a);
}

// +

TEST(sumi_op, sum_op) {
    tvec2i a = {-30, 20};
    tvec2i b = {10, 50};

    tvec2i c = a + b;
    EXPECT_EQ(c.x, -20);
    EXPECT_EQ(c.y, 70);

    c = a + 1;

    EXPECT_EQ(c.x, -29);
    EXPECT_EQ(c.y, 21);

    c = 1 + a;
    EXPECT_EQ(c.x, -29);
    EXPECT_EQ(c.y, 21);
}

TEST(sumf_op, sum_op) {
    tvec2f a = {-10.5f, 2.5f};
    tvec2f b = {1.5f, 5.f};

    tvec2f c = a + b;
    EXPECT_FLOAT_EQ(c.x, (-10.5f + 1.5f));
    EXPECT_FLOAT_EQ(c.y, (2.5f + 5.f));

    c = a + 3.5f;

    EXPECT_FLOAT_EQ(c.x, (-10.5f + 3.5f));
    EXPECT_FLOAT_EQ(c.y, (2.5f + 3.5f));

    c = 3.5f + a;
    EXPECT_FLOAT_EQ(c.x, (-10.5f + 3.5f));
    EXPECT_FLOAT_EQ(c.y, (2.5f + 3.5f));

    a = {1.4f, 1.8f};
    b = {2.f, 3.f};
    a += b;

    EXPECT_FLOAT_EQ(a.x, (1.4f + 2.f));
    EXPECT_FLOAT_EQ(a.y, (1.8f + 3.f));

    a = {1.4f, 1.8f};

    a += 1.f;
    EXPECT_FLOAT_EQ(a.x, (1.4f + 1.f));
    EXPECT_FLOAT_EQ(a.y, (1.8f + 1.f));
}


// Sub

TEST(subf_op, sub_op) {
    tvec2f a = {-10.5f, 2.5f};
    tvec2f b = {1.5f, 5.f};

    tvec2f c = a - b;
    EXPECT_FLOAT_EQ(c.x, (-10.5f - 1.5f));
    EXPECT_FLOAT_EQ(c.y, (2.5f - 5.f));

    c = a - 3.5f;

    EXPECT_FLOAT_EQ(c.x, (-10.5f - 3.5f));
    EXPECT_FLOAT_EQ(c.y, (2.5f - 3.5f));

    c = 3.5f - a;
    EXPECT_FLOAT_EQ(c.x, (3.5f - (-10.5f)));
    EXPECT_FLOAT_EQ(c.y, (3.5f - 2.5f));

    a = {1.4f, 1.8f};
    b = {2.f, 3.f};
    a -= b;

    EXPECT_FLOAT_EQ(a.x, (1.4f - 2.f));
    EXPECT_FLOAT_EQ(a.y, (1.8f - 3.f));

    a = {1.4f, 1.8f};

    a -= 1.f;
    EXPECT_FLOAT_EQ(a.x, (1.4f - 1.f));
    EXPECT_FLOAT_EQ(a.y, (1.8f - 1.f));
}

// Mul

TEST(mulf_op, mul_op) {
    tvec2f a = {-10.5f, 2.5f};
    tvec2f b = {1.5f, 5.f};

    tvec2f c = a * b;
    EXPECT_FLOAT_EQ(c.x, (-10.5f * 1.5f));
    EXPECT_FLOAT_EQ(c.y, (2.5f * 5.f));

    c = a * 3.5f;

    EXPECT_FLOAT_EQ(c.x, (-10.5f * 3.5f));
    EXPECT_FLOAT_EQ(c.y, (2.5f * 3.5f));

    c = 3.5f * a;
    EXPECT_FLOAT_EQ(c.x, (3.5f * (-10.5f)));
    EXPECT_FLOAT_EQ(c.y, (3.5f * 2.5f));

    a = {1.4f, 1.8f};
    b = {2.f, 3.f};
    a *= b;

    EXPECT_FLOAT_EQ(a.x, (1.4f * 2.f));
    EXPECT_FLOAT_EQ(a.y, (1.8f * 3.f));

    a = {1.4f, 1.8f};

    a *= 3.f;
    EXPECT_FLOAT_EQ(a.x, (1.4f * 3.f));
    EXPECT_FLOAT_EQ(a.y, (1.8f * 3.f));
}


// Div

TEST(divf_op, div_op) {
    tvec2f a = {-10.5f, 2.5f};
    tvec2f b = {1.5f, 5.f};

    tvec2f c = a / b;
    EXPECT_FLOAT_EQ(c.x, (-10.5f / 1.5f));
    EXPECT_FLOAT_EQ(c.y, (2.5f / 5.f));

    a = {-10.5f, 2.5f};
    c = a / 3.5f;

    EXPECT_FLOAT_EQ(c.x, -10.5f / 3.5f);
    EXPECT_FLOAT_EQ(c.y, 2.5f / 3.5f);

    c = 3.5f / a;
    EXPECT_FLOAT_EQ(c.x, (3.5f / (-10.5f)));
    EXPECT_FLOAT_EQ(c.y, (3.5f / 2.5f));

    a = {1.4f, 1.8f};
    b = {2.f, 3.f};
    a /= b;

    EXPECT_FLOAT_EQ(a.x, (1.4f / 2.f));
    EXPECT_FLOAT_EQ(a.y, (1.8f / 3.f));

    a = {1.4f, 1.8f};

    a /= 3.f;

    EXPECT_FLOAT_EQ(a.x, 1.4f / 3.f);
    EXPECT_FLOAT_EQ(a.y, 1.8f / 3.f);
}