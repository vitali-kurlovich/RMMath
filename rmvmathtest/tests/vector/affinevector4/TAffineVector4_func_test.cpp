//
// Created by Vitali Kurlovich on 2/20/16.
//


#include "gtest/gtest.h"

#include "TAffineVector4_test_types.h"
#include "../vector4/TVector4_test_types.h"


TEST(affinevector4, constructor) {
    tavec4i a = {3, -8, -98};
    tvec3i xyz = {3, -8, -98};
    tvec2i xy = {3, -8};

    EXPECT_EQ(a.xyz, xyz);
    EXPECT_EQ(a.xy, xy);

    a.xyz = tvec3i(3,4,5);
    EXPECT_EQ(a, tavec4i(3,4,5));

    a.xy = tvec2i(6,7);
    EXPECT_EQ(a, tavec4i(6,7,5));

    tavec4i zero = {0, 0, 0};

    EXPECT_EQ(tavec4i::zero(), zero);

    tavec4i c;
    EXPECT_EQ(c, zero);

    xy = {3, -8};
    a = tavec4i(xy, 6);
    EXPECT_EQ(a, tavec4i(3, -8, 6));

    c = a;
    EXPECT_EQ(a,c);
}


TEST(affinevector4, equal) {
    tavec4f a(5.f, -12.5f, 6.f);
    tavec4f b(5.f*logf(M_E), -12.5f*logf(M_E), 6.f*logf(M_E));

    EXPECT_NE(a,b);
    EXPECT_TRUE(equal<float>(a,b));
}

// Dot

TEST(affinedoti_nonull, dot4) {
    tavec4i a = {3, -8, -98};
    tavec4i b = {-6, 7, 3};

    EXPECT_EQ(dot(a, b), -367);

    tvec4i c = {-6, 7, 3, 8};
    EXPECT_EQ(dot(a, c), -360);
    EXPECT_EQ(dot(c, a), -360);
}


// Cross

TEST(affinecrossi, cross4_001) {
    tvec4i a = {3, -8, -98, 4};
    tvec4i b = {-6, 7, 3, 16};
    tavec4i c = {-666, 57, 63};

    tvec4i r = {79570, 1047165, -99765, -409590};

    EXPECT_EQ(cross(a,b,c),r);
}

TEST(affinecrossi, cross4_010) {
    tvec4i a = {3, -8, -98, 4};
    tavec4i b = {-6, 7, 3};
    tvec4i c = {-666, 57, 63, 12};

    tvec4i r = {-3942, 64611, -22113, -409590};

    EXPECT_EQ(cross(a,b,c),r);
}

TEST(affinecrossi, cross4_011) {
    tvec4i a = {3, -8, -98, 4};
    tavec4i b = {-6, 7, 3};
    tavec4i c = {-666, 57, 63};

    tvec4i r = {3340, 70980, -22410, -409590};

    EXPECT_EQ(cross(a,b,c),r);
}

TEST(affinecrossi, cross4_100) {
    tavec4i a = {3, -8, -98};
    tvec4i b = {-6, 7, 3, 16};
    tvec4i c = {-666, 57, 63, 6};

    tvec4i r = {77070, 1039410, -86670, -409590};

    EXPECT_EQ(cross(a,b,c),r);
}

TEST(affinecrossi, cross4_101) {
    tavec4i a = {3, -8, -98};
    tvec4i b = {-6, 7, 3, 16};
    tavec4i c = {-666, 57, 63};

    tvec4i r = {80380, 1042305, -86805, -409590};

    EXPECT_EQ(cross(a,b,c),r);
}

TEST(affinecrossi, cross4_110) {
    tavec4i a = {3, -8, -98};
    tavec4i b = {-6, 7, 3};
    tvec4i c = {-666, 57, 63, 6};

    tvec4i r = {840, 63225, -9315, -409590};

    EXPECT_EQ(cross(a,b,c),r);
}


TEST(affinecrossi, cross4_111) {
    tavec4i a = {3, -8, -98};
    tavec4i b = {-6, 7, 3};
    tavec4i c = {-666, 57, 63};

    tvec4i r = {4150, 66120, -9450, -409590};

    EXPECT_EQ(cross(a,b,c),r);
}

// Norm

TEST(affinenormf, norm4) {
    tavec4f a = {3,4,5};

    EXPECT_FLOAT_EQ(norm(a), 7.141428428542850);
}

// Normalize

TEST(affinenormalizef, normalize4) {
    tavec4f a = {-3, 5, 6};
    tvec4f r = {-0.3560344974581560, 0.5933908290969267, 0.7120689949163120, 0.1186781658193853};

    EXPECT_FLOAT_EQ(normalize(a).x, r.x);
    EXPECT_FLOAT_EQ(normalize(a).y, r.y);
    EXPECT_FLOAT_EQ(normalize(a).z, r.z);
    EXPECT_FLOAT_EQ(normalize(a).w, r.w);
}


// Mul

TEST(affinemulti, mult4) {
    tavec4i a = {3, -8, -98};
    tavec4i b = {-6, 7, 3};

    tavec4i r = {-18, -56, -294};

    EXPECT_EQ(mul(a, b), r);

}

TEST(affinemulti, mult4_) {
    tavec4i a = {3, -8, -98};
    tvec4i b = {-6, 7, 3, -43};

    tvec4i r = {-18, -56, -294, -43};

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(mul(b, a), r);
}

TEST(affinemulti, mult4_scalar) {
    tavec4i a = {3, -8, -98};

    tvec4i r = {15, -40, -490, 5};

    EXPECT_EQ(mul(a, 5), r);
    EXPECT_EQ(mul(5, a), r);
}