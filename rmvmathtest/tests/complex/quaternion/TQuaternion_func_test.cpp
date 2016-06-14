//
// Created by Vitali Kurlovich on 4/4/16.
//

#include "gtest/gtest.h"

#include "../TQuaternion_test_types.h"

TEST(quaternion, constructor) {
    tqti a = {5, 3, -8, -98};
    tvec3i xyz = {3, -8, -98};

    EXPECT_EQ(a.re, 5);
    EXPECT_EQ(a.im, xyz);

    a.im = tvec3i(12, 13, 14);
    a.re = -6;

    EXPECT_EQ(a, tqti(-6, 12, 13, 14));

    EXPECT_EQ(tqti(5, tvec3i(12, 13, 14)), tqti(5, 12, 13, 14));

    EXPECT_EQ(tqti(tvec3i(12, 13, 14), 5), tqti(5, 12, 13, 14));
    EXPECT_EQ(tqti(tvec3i(12, 13, 14)), tqti(0, 12, 13, 14));

    tqti zero = {0, 0, 0, 0};
    tqti b;

    EXPECT_EQ(b, zero);

    EXPECT_NE(a, b);
    a = b;
    EXPECT_EQ(a, b);
}

TEST(quaternion_op, mul) {
    tqti a = {1, 2, 3, 4};
    tqti b = {5, 6, 7, 8};

    tqti result = {-60, 12, 30, 24};

    EXPECT_EQ(mul(a, b), result);
    EXPECT_EQ(a*b, result);

    result = {-60, 20, 14, 32};
    EXPECT_EQ(mul(b, a), result);
    EXPECT_EQ(b*a, result);

    result = {2, 4, 6, 8};

    EXPECT_EQ(mul(a,2), result);
    EXPECT_EQ(mul(2,a), result);
    EXPECT_EQ(a*2, result);
    EXPECT_EQ(2*a, result);
}


TEST(quaternion_op, div) {
    tqtf a = {2, 3, 4, 5};
    tqtf b = {3, 5, 8, 20};

    tqtf result(0.307229, -0.0823293, 0.062249, -0.0582329);

    EXPECT_NEAR(div(a, b).w, result.w, 0.000001);
    EXPECT_NEAR(div(a, b).i, result.i, 0.000001);
    EXPECT_NEAR(div(a, b).j, result.j, 0.000001);
    EXPECT_NEAR(div(a, b).k, result.k, 0.000001);

    EXPECT_NEAR((a/b).w, result.w, 0.000001);
    EXPECT_NEAR((a/b).i, result.i, 0.000001);
    EXPECT_NEAR((a/b).j, result.j, 0.000001);
    EXPECT_NEAR((a/b).k, result.k, 0.000001);


    EXPECT_NEAR(((a/b)*b).w, a.w, 0.000001);
    EXPECT_NEAR(((a/b)*b).i, a.i, 0.000001);
    EXPECT_NEAR(((a/b)*b).j, a.j, 0.000001);
    EXPECT_NEAR(((a/b)*b).k, a.k, 0.000001);


    result = {0.4, 0.6, 0.8, 1.};

    EXPECT_EQ(div(a, 5.f), result);
    EXPECT_EQ(a/5.f, result);


    result = {0.185185, -0.277778, -0.37037, -0.462963};

    EXPECT_NEAR(div(5.f, a).re, result.w, 0.000001);
    EXPECT_NEAR(div(5.f, a).i, result.i, 0.000001);
    EXPECT_NEAR(div(5.f, a).j, result.j, 0.000001);
    EXPECT_NEAR(div(5.f, a).k, result.k, 0.000001);

    EXPECT_NEAR((5.f/a).w, result.re, 0.000001);
    EXPECT_NEAR((5.f/a).i, result.i, 0.000001);
    EXPECT_NEAR((5.f/a).j, result.j, 0.000001);
    EXPECT_NEAR((5.f/a).k, result.k, 0.000001);

}


TEST(quaternion_op, sum) {
    tqti a = {2, 3, 4, 5};
    tqti b = {6, 7, 8, 9};

    tqti result = {8, 10, 12, 14};

    EXPECT_EQ(sum(a, b), result);
    EXPECT_EQ(a+b, result);

    EXPECT_EQ(sum(b, a), result);
    EXPECT_EQ(b+a, result);

    result = {7, 3, 4, 5};
    EXPECT_EQ(sum(a, 5), result);
    EXPECT_EQ(a+5, result);

    EXPECT_EQ(sum(5, a), result);
    EXPECT_EQ(5+a, result);
}

TEST(quaternion_op, sub) {
    tqti a = {2, 3, 4, 5};
    tqti b = {6, 7, 8, 9};

    tqti result = {-4, -4, -4, -4};

    EXPECT_EQ(sub(a, b), result);
    EXPECT_EQ(a-b, result);

    result = {4, 4, 4, 4};
    EXPECT_EQ(sub(b, a), result);
    EXPECT_EQ(b-a, result);

    result = {-3, 3, 4, 5};
    EXPECT_EQ(sub(a, 5), result);
    EXPECT_EQ(a-5, result);

    result = {3, -3, -4, -5};
    EXPECT_EQ(sub(5, a), result);
    EXPECT_EQ(5-a, result);
}

TEST(quaternion_op, conjugate) {
    tqti a = {5, 6, 7, 8};
    tqti result = {5, -6, -7, -8};

    EXPECT_EQ(conjugate(a), result);
}

TEST(quaternion_op, norm) {
    tqti a = {1, 2, 3, 4};

    EXPECT_EQ(norm(a), 30);
}

TEST(quaternion_op, inverse) {
    tqtf a = {25, -42, 92, -2};

    EXPECT_NEAR((inverse(a)*a).w, 1.f, 0.000001);
    EXPECT_NEAR((inverse(a)*a).i, 0.f, 0.000001);
    EXPECT_NEAR((inverse(a)*a).j, 0.f, 0.000001);
    EXPECT_NEAR((inverse(a)*a).k, 0.f, 0.000001);
}