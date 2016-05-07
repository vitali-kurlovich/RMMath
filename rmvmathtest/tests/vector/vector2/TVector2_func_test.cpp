//
// Created by Vitali Kurlovich on 12/11/15.
//

#include "gtest/gtest.h"

#include "TVector2_test_types.h"



TEST(vector2, constructor) {
    tvec2i a = {3, -8};

    tvec2i zero = {0, 0};

    EXPECT_EQ(tvec2i::zero(), zero);

    tvec2i c;
    EXPECT_EQ(c, zero);

    c = a;
    EXPECT_EQ(a,c);
}


// Dot

TEST(doti_0, dot) {
    tvec2i a = {0,8};
    tvec2i b = {-6,0};

    EXPECT_EQ(dot(a,b), 0);
}

TEST(dotf_0, dot) {
    tvec2f a = {0,10};
    tvec2f b = {-12,0};

    EXPECT_EQ(dot(a,b), 0);
}

TEST(dotd_0, dot) {
    tvec2d a = {0,15};
    tvec2d b = {-51,0};

    EXPECT_EQ(dot(a,b), 0);
}

TEST(doti_nonull, dot) {
    tvec2i a = {3,-8};
    tvec2i b = {-6,7};

    int r = 3*(-6) + (-8)*7;

    EXPECT_EQ(dot(a,b), r);
}

TEST(dotf_nonull, dot) {
    tvec2f a = {3.3f,-8.8f};
    tvec2f b = {-6.2f,7.2f};

    float r = 3.3f*(-6.2f) + (-8.8f)*7.2f;

    EXPECT_EQ(dot(a,b), r);
}

TEST(dotd_nonull, dot) {
    tvec2d a = {3.5,-8.2};
    tvec2d b = {-6.6,7.4};

    double r = 3.5*(-6.6) + (-8.2)*7.4;

    EXPECT_EQ(dot(a,b), r);
}


// Cross

TEST(crossi, cross) {
    tvec2i a = {0,8};
    tvec2i r = cross(a);

    EXPECT_EQ(r.x, -8);
    EXPECT_EQ(r.y, 0);

     a = {-10,-6};
     r = cross(a);

    EXPECT_EQ(r.x, 6);
    EXPECT_EQ(r.y, -10);
}

TEST(crossf, cross) {
    tvec2f a = {0.2f,8.4f};
    tvec2f r = cross(a);

    EXPECT_EQ(r.x, -8.4f);
    EXPECT_EQ(r.y, 0.2f);

    a = {-10.1f,-6.5f};
    r = cross(a);

    EXPECT_EQ(r.x, 6.5f);
    EXPECT_EQ(r.y, -10.1f);
}

TEST(crossd, cross) {
    tvec2d a = {0.2,8.4};
    tvec2d r = cross(a);

    EXPECT_EQ(r.x, -8.4);
    EXPECT_EQ(r.y, 0.2);

    a = {-10.1,-6.5};
    r = cross(a);

    EXPECT_EQ(r.x, 6.5);
    EXPECT_EQ(r.y, -10.1);
}


// Norm

TEST(normi, norm) {
    tvec2i a = {-3,4};
    EXPECT_EQ(norm(a), 5);

    a = {0,-4};
    EXPECT_EQ(norm(a), 4);

    a = {-4,0};
    EXPECT_EQ(norm(a), 4);
}

TEST(normf, norm) {
    tvec2f a = {-3.f,4.f};
    EXPECT_EQ(norm(a), 5.f);

    a = {0,-4.f};
    EXPECT_EQ(norm(a), 4.f);

    a = {-4,0};
    EXPECT_EQ(norm(a), 4.f);
}

TEST(normd, norm) {
    tvec2d a = {-3.,4.};
    EXPECT_EQ(norm(a), 5.);

    a = {0,-4.f};
    EXPECT_EQ(norm(a), 4.);

    a = {-4,0};
    EXPECT_EQ(norm(a), 4.);
}


// Normalize
TEST(normalizef, norm) {
    tvec2f a = {0,4.f};

    EXPECT_EQ(normalize(a).x, 0);
    EXPECT_EQ(normalize(a).y, 1.f);

    a = {-16.f,0};

    EXPECT_EQ(normalize(a).x, -1.f);
    EXPECT_EQ(normalize(a).y, 0);

    a = {-16.5f,-6.4f};
    auto len = norm(a);

    tvec2f r = {-16.5f/len, -6.4f/len};

    EXPECT_EQ(normalize(a).x, r.x);
    EXPECT_EQ(normalize(a).y, r.y);
}

TEST(normalized, norm) {
    tvec2d a = {0,4.};

    EXPECT_EQ(normalize(a).x, 0);
    EXPECT_EQ(normalize(a).y, 1.);

    a = {-16.,0};

    EXPECT_EQ(normalize(a).x, -1.);
    EXPECT_EQ(normalize(a).y, 0);

    a = {-16.5,-6.4};
    auto len = norm(a);

    tvec2d r = {-16.5/len, -6.4/len};

    EXPECT_EQ(normalize(a).x, r.x);
    EXPECT_EQ(normalize(a).y, r.y);
}


// Mul

TEST(multi, mult) {
    tvec2i a = {5,-6};

    EXPECT_EQ(mul(a,2).x, 10);
    EXPECT_EQ(mul(2,a).x, 10);

    EXPECT_EQ(mul(a,-2).y, 12);
    EXPECT_EQ(mul(-2,a).y, 12);

    tvec2i b = {-3,4};

    EXPECT_EQ(mul(a,b).x, 5*(-3));
    EXPECT_EQ(mul(b,a).x, -3*5);

    EXPECT_EQ(mul(a,b).y, -6*4);
    EXPECT_EQ(mul(b,a).y, -6*4);

}

TEST(multf, mult) {
    tvec2f a = {5.f,-6.f};

    EXPECT_EQ(mul(a,2.f).x, 10.f);
    EXPECT_EQ(mul(2.f,a).x, 10.f);

    EXPECT_EQ(mul(a,-2.f).y, 12.f);
    EXPECT_EQ(mul(-2.f,a).y, 12.f);

    tvec2f b = {-3.f,4.f};

    EXPECT_EQ(mul(a,b).x, 5.f*(-3.f));
    EXPECT_EQ(mul(b,a).x, -3.f*5.f);

    EXPECT_EQ(mul(a,b).y, -6.f*4.f);
    EXPECT_EQ(mul(b,a).y, -6.f*4.f);

}


// Div

TEST(divf, div) {
    tvec2f a = {5.f,-6.f};
    tvec2f b = {-3.f,4.f};

    EXPECT_EQ(div(a,2.f).x, 5.f/2.f);
    EXPECT_EQ(div(2.f,a).x, 2.f/5.f);

    EXPECT_EQ(div(a,-2.f).y, -6.f/-2.f);
    EXPECT_EQ(div(-2.f,a).y, -2.f/-6.f);

    a = {5.f,-6.f};
    b = {-3.f,4.f};

    EXPECT_EQ(div(a,b).x, 5.f/-3.f);
    EXPECT_EQ(div(b,a).x, -3.f/5.f);

    EXPECT_EQ(div(a,b).y, -6.f/4.f);
    EXPECT_EQ(div(b,a).y, 4.f/-6.f);
}



// Sum

TEST(sumi, sum) {
    tvec2i a = {5,-6};

    EXPECT_EQ(sum(a,2).x, 7);
    EXPECT_EQ(sum(2,a).x, 7);

    EXPECT_EQ(sum(a,-2).y, -8);
    EXPECT_EQ(sum(-2,a).y, -8);

    tvec2i b = {-3,4};

    EXPECT_EQ(sum(a,b).x, 5-3);
    EXPECT_EQ(sum(b,a).x, 5-3);

    EXPECT_EQ(sum(a,b).y, -2);
    EXPECT_EQ(sum(b,a).y, -2);
}

// Sub

TEST(subi, sub) {
    tvec2i a = {5,-6};

    EXPECT_EQ(sub(a,2).x, 5-2);
    EXPECT_EQ(sub(2,a).x, 2-5);

    EXPECT_EQ(sub(a,-2).y, -6 - (-2));
    EXPECT_EQ(sub(-2,a).y, -2-(-6));

    tvec2i b = {-3,4};

    EXPECT_EQ(sub(a,b).x, 5 - (-3));
    EXPECT_EQ(sub(b,a).x, -3-5);

    EXPECT_EQ(sub(a,b).y, -6-4);
    EXPECT_EQ(sub(b,a).y, 4-(-6));
}

