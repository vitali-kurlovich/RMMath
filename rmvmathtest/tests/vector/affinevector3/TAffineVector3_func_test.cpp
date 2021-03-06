//
// Created by Vitali Kurlovich on 2/21/16.
//

#include "gtest/gtest.h"

#include "TAffineVector3_test_types.h"
#include "../vector3/TVector3_test_types.h"


TEST(affinevector3, constructor) {
    tavec3i a = {3, -8};
    tvec2i xy = {3, -8};

    EXPECT_EQ(a.xy, xy);

    a.xy = tvec2i(3,2);
    EXPECT_EQ(a, tavec3i(3,2));

    tavec3i zero = {0, 0};

    EXPECT_EQ(tavec3i::zero(), zero);

    tavec3i c;
    EXPECT_EQ(c, zero);

    a = tavec3i(3);
    EXPECT_EQ(a, tavec3i(3, 0));

    c = a;
    EXPECT_EQ(a,c);
}


TEST(affinevector3, equal) {
    tavec3f a(5.f, -12.5f);
    tavec3f b(5.f*logf(M_E), -12.5f*logf(M_E));

    EXPECT_NE(a,b);
    EXPECT_TRUE(equal<float>(a,b));
}

// Dot

TEST(affinedoti_nonull, dot3) {
    tavec3i a = {2, 3};
    tavec3i b = {7, 11};

    EXPECT_EQ(dot(a, b), 48);

    tvec3i c = {13, 17, 23};
    EXPECT_EQ(dot(a, c), 100);
    EXPECT_EQ(dot(c, a), 100);
}


// Cross

TEST(affinecrossi, cross3) {
    tavec3i a = {3, 5};
    tavec3i b = {7, 11};
    tvec3i r = {-6, 4, -2};

    EXPECT_EQ(cross(a,b),r);
}

TEST(affinecrossi, cross3_) {
    tavec3i a = {3, 5};
    tvec3i b = {7, 11, 17};
    tvec3i r = {74, -44, -2};

    EXPECT_EQ(cross(a,b),r);

    r = {-74, 44, 2};
    EXPECT_EQ(cross(b,a),r);
}


// Norm

TEST(affinenormf, norm3) {
    tavec3f a = {27, 11};

    EXPECT_FLOAT_EQ(norm(a), 29.17190429162964);
}

// Normalize

TEST(affinenormalizef, normalize3) {
    tavec3f a = {-3, 5};
    tvec3f r = {-0.5070925528371099, 0.8451542547285166, 0.1690308509457033};

    EXPECT_FLOAT_EQ(normalize(a).x, r.x);
    EXPECT_FLOAT_EQ(normalize(a).y, r.y);
    EXPECT_FLOAT_EQ(normalize(a).z, r.z);
}


// Mul

TEST(affinemulti, mult3) {
    tavec3i a = {3, -8};
    tavec3i b = {-6, 7};

    tavec3i r = {-18, -56};

    EXPECT_EQ(mul(a, b), r);
}

TEST(affinemulti, mult3_) {
    tavec3i a = {3, -8};
    tvec3i b = {-6, 7, 3};

    tvec3i r = {-18, -56, 3};

    EXPECT_EQ(mul(a, b), r);
    EXPECT_EQ(mul(b, a), r);
}

TEST(affinemulti, mult3_scalar) {
    tavec3i a = {3, -8};

    tvec3i r = {15, -40, 5};

    EXPECT_EQ(mul(a, 5), r);
    EXPECT_EQ(mul(5, a), r);
}