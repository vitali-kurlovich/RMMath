//
// Created by Vitali Kurlovich on 12/11/15.
//

#include "gtest/gtest.h"

#include "TVector3_test_types.h"


TEST(vector3, constructor) {
    tvec3i a = {3, -8, -98};
    tvec2i xy = {3, -8};


    EXPECT_EQ(a.xy, xy);

    a.xy = tvec2i(4,8);
    EXPECT_EQ(a, tvec3i(4, 8, -98));

    tvec3i zero = {0, 0, 0};

    tvec3i c;
    EXPECT_EQ(c, zero);

    c = a;
    EXPECT_EQ(a,c);

    xy = {3, -8};
    EXPECT_EQ(tvec3i(3,-8,4),tvec3i(xy,4));

    tavec3i affine = {2,3};

    c = affine;

    EXPECT_EQ(c, tvec3i(2,3,1));
}



// Dot

TEST(doti_0, dot3) {
    tvec3i a = {0, 0, 2};
    tvec3i b = {-6, 3, 0};

    EXPECT_EQ(dot(a, b), 0);

    a = {10, 0, 2};
    b = {0, 3, 0};
    EXPECT_EQ(dot(a, b), 0);

}


TEST(doti_nonull, dot3) {
    tvec3i a = {3, -8, -8};
    tvec3i b = {-6, 7, 3};

    int r = 3 * (-6) + (-8) * 7 + 3 * -8;

    EXPECT_EQ(dot(a, b), r);
}

// Cross

TEST(crossi, cross3) {
    tvec3i a = {2, -6, -17};
    tvec3i b = {24, -56, 89};

    tvec3i r = cross(a, b);

    EXPECT_EQ(r.x, -1486);
    EXPECT_EQ(r.y, -586);
    EXPECT_EQ(r.z, 32);
}

// Norm

TEST(normi, norm3) {
    tvec3i a = {-3, 4, 0};
    EXPECT_EQ(norm(a), 5);

    a = {0, 4, 3};
    EXPECT_EQ(norm(a), 5);

    a = {3, 0, -4};
    EXPECT_EQ(norm(a), 5);
}

// Normalize

TEST(normalizef, normalize3) {
    tvec3f a = {34, 64, -14};

    EXPECT_FLOAT_EQ(normalize(a).x, 0.4606386424128941);
    EXPECT_FLOAT_EQ(normalize(a).y, 0.8670845033654477);
    EXPECT_FLOAT_EQ(normalize(a).z, -0.1896747351111917);
}

// Mul

TEST(multi, mult3) {
    tvec3i a = {5, -6, -9};
    tvec3i b = {-3, 4};

    EXPECT_EQ(mul(a, 2).x, 5 * 2);
    EXPECT_EQ(mul(2, a).x, 2 * 5);

    EXPECT_EQ(mul(a, -2).y, -2 * -6);
    EXPECT_EQ(mul(-2, a).y, -2 * -6);

    EXPECT_EQ(mul(a, -2).z, -9 * -2);
    EXPECT_EQ(mul(-2, a).z, -9 * -2);

    b = {-3, 4, 7};
    a = {5, -6, -9};

    EXPECT_EQ(mul(a, b).x, 5 * (-3));
    EXPECT_EQ(mul(b, a).x, -3 * 5);

    EXPECT_EQ(mul(a, b).y, -6 * 4);
    EXPECT_EQ(mul(b, a).y, -6 * 4);


    EXPECT_EQ(mul(a, b).z, -9 * 7);
    EXPECT_EQ(mul(b, a).z, -9 * 7);

}

TEST(multf, mult3) {
    tvec3f a = {5.f, -6.f, 4.f};
    tvec3f b = {-3.f, 4.f, 12.f};

    EXPECT_FLOAT_EQ(mul(a, 2.f).x, 2.f * 5.f);
    EXPECT_FLOAT_EQ(mul(2.f, a).x, 2.f * 5.f);

    EXPECT_FLOAT_EQ(mul(a, -2.f).y, -2.f * -6.f);
    EXPECT_FLOAT_EQ(mul(-2.f, a).y, -2.f * -6.f);

    a = {5.f, -6.f, 4.f};
    b = {-3.f, 4.f, 12.f};

    EXPECT_FLOAT_EQ(mul(a, b).x, 5.f * (-3.f));
    EXPECT_FLOAT_EQ(mul(b, a).x, -3.f * 5.f);

    EXPECT_FLOAT_EQ(mul(a, b).y, -6.f * 4.f);
    EXPECT_FLOAT_EQ(mul(b, a).y, -6.f * 4.f);

    EXPECT_FLOAT_EQ(mul(a, b).z, 4.f * 12.f);
    EXPECT_FLOAT_EQ(mul(b, a).z, 4.f * 12.f);

}

// Div

TEST(divf, div3) {
    tvec3f a = {5.f, -6.f, 9.4f};
    tvec3f b = {-3.f, 4.f, 23.5f};

    EXPECT_FLOAT_EQ(div(a, 2.f).x, 5.f / 2.f);
    EXPECT_FLOAT_EQ(div(2.f, a).x, 2.f / 5.f);

    EXPECT_FLOAT_EQ(div(a, -2.f).y, -6.f / -2.f);
    EXPECT_FLOAT_EQ(div(-2.f, a).y, -2.f / -6.f);

    EXPECT_FLOAT_EQ(div(a, -2.f).z, 9.4f / -2.f);
    EXPECT_FLOAT_EQ(div(-2.f, a).z, -2.f / 9.4f);

    a = {5.f, -6.f, 9.4f};
    b = {-3.f, 4.f, 23.5f};

    EXPECT_FLOAT_EQ(div(a, b).x, 5.f / -3.f);
    EXPECT_FLOAT_EQ(div(b, a).x, -3.f / 5.f);

    EXPECT_FLOAT_EQ(div(a, b).y, -6.f / 4.f);
    EXPECT_FLOAT_EQ(div(b, a).y, 4.f / -6.f);

    EXPECT_FLOAT_EQ(div(a, b).z, 9.4f / 23.5f);
    EXPECT_FLOAT_EQ(div(b, a).z, 23.5f / 9.4f);
}

// Sum

TEST(sumi, sum3) {
    tvec3i a = {5, -6, 4};
    tvec3i b = {-3, 4, 10};

    EXPECT_EQ(sum(a, 2).x, 5 + 2);
    EXPECT_EQ(sum(2, a).x, 2 + 5);

    EXPECT_EQ(sum(a, -2).y, -6 - 2);
    EXPECT_EQ(sum(-2, a).y, -2 + (-6));

    EXPECT_EQ(sum(a, -2).z, 4 - 2);
    EXPECT_EQ(sum(-2, a).z, -2 + 4);

    a = {5, -6, 4};
    b = {-3, 4, 10};

    EXPECT_EQ(sum(a, b).x, 5 - 3);
    EXPECT_EQ(sum(b, a).x, 5 - 3);

    EXPECT_EQ(sum(a, b).y, -6 + 4);
    EXPECT_EQ(sum(b, a).y, 4 - 6);

    EXPECT_EQ(sum(a, b).z, 4 + 10);
    EXPECT_EQ(sum(b, a).z, 10 + 4);
}


// Sub

TEST(subi, sub3) {
    tvec3i a = {5, -6, 21};
    tvec3i b = {-3, 4, 7};

    EXPECT_EQ(sub(a, 2).x, 5 - 2);
    EXPECT_EQ(sub(2, a).x, 2 - 5);

    EXPECT_EQ(sub(a, -2).y, -6 - (-2));
    EXPECT_EQ(sub(-2, a).y, -2 - (-6));

    EXPECT_EQ(sub(a, -2).z, 21 - (-2));
    EXPECT_EQ(sub(-2, a).z, -2 - 21);

    a = {5, -6, 21};
    b = {-3, 4, 7};

    EXPECT_EQ(sub(a, b).x, 5 - (-3));
    EXPECT_EQ(sub(b, a).x, -3 - 5);

    EXPECT_EQ(sub(a, b).y, -6 - 4);
    EXPECT_EQ(sub(b, a).y, 4 - (-6));

    EXPECT_EQ(sub(a, b).z, 21 - 7);
    EXPECT_EQ(sub(b, a).z, 7 - 21);
}

