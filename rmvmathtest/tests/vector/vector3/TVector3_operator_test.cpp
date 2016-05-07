//
// Created by Vitali Kurlovich on 12/12/15.
//

#include "gtest/gtest.h"

#include "TVector3_test_types.h"

// []
TEST(arrayi_op, arr_op3) {
    tvec3i a = {-30, 20, -4};

    EXPECT_EQ(a[0], -30);
    EXPECT_EQ(a[1], 20);
    EXPECT_EQ(a[2], -4);
}

// ==

TEST(equali_op, equal_op3) {
    tvec3i a = {-30, 20, -4};
    tvec3i b = {-30, 20, -4};

    EXPECT_EQ(a, b);
    EXPECT_EQ(b, a);
    EXPECT_EQ(a, a);
    EXPECT_EQ(b, b);
}

TEST(equalf_op, equal_op3) {
    tvec3f a = {-30.4f, 20.2f, -6.3f};
    tvec3f b = {-30.4f, 20.2f, -6.3f};

    EXPECT_EQ(a, b);
    EXPECT_EQ(b, a);
    EXPECT_EQ(a, a);
    EXPECT_EQ(b, b);
}


// !=

TEST(nequali_op, nequal_op3) {
    tvec3i a = {-31, 20, 6};
    tvec3i b = {-30, 20, 6};

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

     a = {-30, 20, 6};
     b = {-30, 21, 6};

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    a = {-30, 20, 6};
    b = {-30, 20, 5};

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);
}

TEST(nequalf_op, nequal_op3) {
    tvec3f a = {-30.4f, 20.1f, 0.4f};
    tvec3f b = {-30.4f, 20.2f, 0.4f};

    EXPECT_NE(a, b);
    EXPECT_NE(b, a);

    a = b;
    EXPECT_EQ(a, b);
    EXPECT_EQ(b, a);
}



// +

TEST(sumi_op, sum_op3) {
    tvec3i a = {-30, 20, 3};
    tvec3i b = {10, 50, -5};

    tvec3i r = {-20, 70, -2};

    EXPECT_EQ(a+b, r);

    r = {-29, 21, 4};

    EXPECT_EQ(a + 1, r);
    EXPECT_EQ(1 + a, r);
}


TEST(sumf_op, sum_op3) {
    tvec3f a = {-10.5f, 2.5f, 8.3f};
    tvec3f b = {1.5f, 5.f, 5.6f};

    tvec3f r = {-10.5f+1.5f, 2.5f+5.f, 8.3f+5.6f};

    EXPECT_EQ(a+b, r);

    a = {-10.5f, 2.5f, 8.3f};
    r = {-10.5f+3.5f, 2.5f+3.5f, 8.3f+3.5f};

    EXPECT_EQ(a+3.5f, r);
    EXPECT_EQ(3.5f+a, r);

    a = {1.4f, 1.8f, 5.6f};
    b = {2.f, 3.f, 2.6f};
    a += b;

    r = {1.4f + 2.f, 1.8f + 3.f, 5.6f + 2.6f};

    EXPECT_EQ(a, r);

    a = {1.4f, 1.8f, 5.6f};
    a += 1.f;

    r = {1.4f + 1.f, 1.8f + 1.f, 5.6f + 1.f};
    EXPECT_EQ(a, r);
}


// Sub

TEST(subf_op, sub_op3) {
    tvec3f a = {-10.5f, 2.5f, 8.3f};
    tvec3f b = {1.5f, 5.f, 5.6f};

    tvec3f r = {-10.5f-1.5f, 2.5f-5.f, 8.3f-5.6f};

    EXPECT_EQ(a-b, r);

    r = {-10.5f-3.5f, 2.5f-3.5f, 8.3f-3.5f};

    EXPECT_EQ(a-3.5f, r);

    r = {3.5f+10.5f, 3.5f-2.5f, 3.5f-8.3f};
    EXPECT_EQ(3.5f-a, r);

    a = {1.4f, 1.8f, 5.6f};
    b = {2.f, 3.f, 2.6f};
    a -= b;

    r = {1.4f-2.f, 1.8f-3.f, 5.6f-2.6f};

    EXPECT_EQ(a, r);

    a = {1.4f, 1.8f, 5.6f};

    a -= 1.f;
    r = {1.4f-1.f, 1.8f-1.f, 5.6f-1.f};

    EXPECT_EQ(a, r);
}

// Mul

TEST(mulf_op, mul_op3) {
    tvec3f a = {-10.5f, 2.5f, 8.3f};
    tvec3f b = {1.5f, 5.f, 5.6};
    tvec3f r = {-10.5f*1.5f, 2.5f*5.f, 8.3f*5.6f};

    EXPECT_EQ(a*b, r);

    a = {-10.5f, 2.5f, 8.3f};
    r = {-10.5f*3.5f, 2.5f*3.5f, 8.3f*3.5f};

    EXPECT_EQ(a*3.5f, r);
    EXPECT_EQ(3.5f*a, r);

    a = {1.4f, 1.8f, 5.6f};
    b = {2.f, 3.f, 2.6f};
    a *= b;

    r = {1.4f*2.f, 1.8f*3.f, 5.6f*2.6f};
    EXPECT_EQ(a, r);

    a = {1.4f, 1.8f, 5.6f};

    a *= 2.f;
    r = {1.4f*2.f, 1.8f*2.f, 5.6f*2.f};
    EXPECT_EQ(a, r);
}


// Div

TEST(divf_op, div_op3) {
    tvec3f a = {-10.5f, 2.5f, 8.3f};
    tvec3f b = {1.5f, 5.f, 5.6};

    tvec3f r = {-10.5f/1.5f, 2.5f/5.f, 8.3f/5.6f};

    EXPECT_EQ(a/b, r);

    a = {-10.5f, 2.5f, 8.3f};
    r = {-10.5f*(1.f/3.5f), 2.5f*(1.f/3.5f), 8.3f*(1.f/3.5f)};

    EXPECT_EQ(a/3.5f, r);

    r = {3.5f/-10.5f, 3.5f/2.5f, 3.5f/8.3f};
    EXPECT_EQ(3.5f/a, r);

    a = {1.4f, 1.8f, 5.6f};
    b = {2.f, 3.f, 2.6f};

    a /= b;
    r = {1.4f/2.f, 1.8f/3.f, 5.6f/2.6f};
    EXPECT_EQ(a, r);


    a = {1.4f, 1.8f, 5.6f};

    a /= 2.f;
    r = {1.4f/2.f, 1.8f/2.f, 5.6f/2.f};
    EXPECT_EQ(a, r);
}

