//
// Created by Vitali Kurlovich on 12/11/15.
//

#include "gtest/gtest.h"

#include "TVector4_test_types.h"

// Dot

TEST(doti_nonull, dot4) {
    tvec4i a = {3, -8, -98, 4};
    tvec4i b = {-6, 7, 3, 16};

    EXPECT_EQ(dot(a, b), -304);
}



// Cross

TEST(crossi, cross4) {
    tvec4i a = {3, -8, -98, 4};
    tvec4i b = {-6, 7, 3, 16};
    tvec4i c = {-666, 57, 63, 6};

    tvec4i r = cross(a, b, c);

    EXPECT_EQ(r.x, 76260);
    EXPECT_EQ(r.y, 1044270);
    EXPECT_EQ(r.z, -99630);
    EXPECT_EQ(r.w, -409590);

}

// Norm

TEST(normf, norm4) {
    tvec4f a = {-666, 57, 63, 6};

    EXPECT_FLOAT_EQ(norm(a), 671.42386016584188709982429614817f);
}



// Normalize

TEST(normalizef, normalize4) {
    tvec4f a = {-666, 57, 63, 6};

    EXPECT_FLOAT_EQ(normalize(a).x, -0.9919218537087702065360);
    EXPECT_FLOAT_EQ(normalize(a).y, 0.08489421270480465731614);
    EXPECT_FLOAT_EQ(normalize(a).z, 0.09383044562109988440205);
    EXPECT_FLOAT_EQ(normalize(a).w, 0.008936232916295227085910);
}


// Mul

TEST(multi, mult4) {
    tvec4i a = {3, -8, -98, 4};

    tvec4i r = {6, -16, -98*2, 8};

    EXPECT_EQ(mul(a, 2), r);
    EXPECT_EQ(mul(2, a), r);

    tvec4i b = {-6, 7, 3, 16};

    r = {-18, -56, -294, 64};

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(mul(b, a), r);
}

// Div

TEST(divf, div4) {
    tvec4f a = {3, -8, -98, 4};
    tvec4f b = {-6, 7, 3, 16};

    EXPECT_FLOAT_EQ(div(a, 2.f).x, 3 / 2.f);
    EXPECT_FLOAT_EQ(div(2.f, a).x, 2.f / 3);

    EXPECT_FLOAT_EQ(div(a, -2.f).y, -8 / -2.f);
    EXPECT_FLOAT_EQ(div(-2.f, a).y, -2.f / -8);

    EXPECT_FLOAT_EQ(div(a, -2.f).z, -98 / -2.f);
    EXPECT_FLOAT_EQ(div(-2.f, a).z, -2.f / -98);

    EXPECT_FLOAT_EQ(div(a, -2.f).w, 4 / -2.f);
    EXPECT_FLOAT_EQ(div(-2.f, a).w, -2.f / 4);

    tvec4f r = {-(1.f/2.f), -(8.f/7.f), -(98.f/3.f), 1.f/4.f};

    EXPECT_FLOAT_EQ(div(a, b).x, r.x);
    EXPECT_FLOAT_EQ(div(a, b).y, r.y);
    EXPECT_FLOAT_EQ(div(a, b).z, r.z);
    EXPECT_FLOAT_EQ(div(a, b).w, r.w);
}

// Sum

TEST(sumi, sum4) {
    tvec4i a = {3, -8, -98, 4};
    tvec4i b = {-6, 7, 3, 16};

    EXPECT_EQ(sum(a, 2).x, 3 + 2);
    EXPECT_EQ(sum(2, a).x, 2 + 3);

    EXPECT_EQ(sum(a, -2).y, -8 - 2);
    EXPECT_EQ(sum(-2, a).y, -2 + (-8));

    EXPECT_EQ(sum(a, -2).z, -98 + (-2));
    EXPECT_EQ(sum(-2, a).z, -2 + (-98));

    EXPECT_EQ(sum(a, -2).w, 4 + (- 2));
    EXPECT_EQ(sum(-2, a).w, -2 + 4);

    tvec4i r = {-3, -1, -95, 20};


    EXPECT_EQ(sum(a, b).x, r.x);
    EXPECT_EQ(sum(a, b).y, r.y);
    EXPECT_EQ(sum(a, b).z, r.z);
    EXPECT_EQ(sum(a, b).w, r.w);
}


// Sub

TEST(subi, sub4) {
    tvec4i a = {3, -8, -98, 4};
    tvec4i b = {-6, 7, 3, 16};

    EXPECT_EQ(sub(a, 2).x, 3 - 2);
    EXPECT_EQ(sub(2, a).x, 2 - 3);

    EXPECT_EQ(sub(a, -2).y, -8 - (-2));
    EXPECT_EQ(sub(-2, a).y, -2 - (-8));

    EXPECT_EQ(sub(a, -2).z, -98 - (-2));
    EXPECT_EQ(sub(-2, a).z, -2 - (-98));

    EXPECT_EQ(sub(a, -2).w, 4 - (-2));
    EXPECT_EQ(sub(-2, a).w, -2 - 4);

    tvec4i r = {9, -15, -101, -12};

    EXPECT_EQ(sub(a, b).x, r.x);
    EXPECT_EQ(sub(a, b).y, r.y);
    EXPECT_EQ(sub(a, b).z, r.z);
    EXPECT_EQ(sub(a, b).w, r.w);

}
