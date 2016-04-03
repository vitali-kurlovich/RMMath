//
// Created by Vitali Kurlovich on 12/11/15.
//

#include "gtest/gtest.h"

#include "TVector2_test_types.h"


// Lerp

TEST(lerpf, lerp) {

    tvec2f a = {0,8};
    tvec2f b = {-6,0};

    EXPECT_EQ(lerp(a,b,0.f).x, a.x);
    EXPECT_EQ(lerp(a,b,0.f).y, a.y);

    EXPECT_EQ(lerp(a,b,1.f).x, b.x);
    EXPECT_EQ(lerp(a,b,1.f).y, b.y);

     a = {10.2f,8.3f};
     b = {-6.4f,0.5f};

    EXPECT_EQ(lerp(a,b,0.f).x, a.x);
    EXPECT_EQ(lerp(a,b,0.f).y, a.y);

    EXPECT_NE(lerp(a,b,-0.5f).x, a.x);
    EXPECT_NE(lerp(a,b,-0.5f).y, a.y);

    EXPECT_EQ(lerp(a,b,1.f).x, b.x);
    EXPECT_EQ(lerp(a,b,1.f).y, b.y);

    EXPECT_EQ(lerp(a,b,0.5f).x, (a.x+b.x)*0.5f);
    EXPECT_EQ(lerp(a,b,0.5f).y, (a.y+b.y)*0.5f);

}

// Lerpc

TEST(lerpcf, lerpc) {

    tvec2f a = {0,8};
    tvec2f b = {-6,0};

    EXPECT_EQ(lerpc(a,b,0.f).x, a.x);
    EXPECT_EQ(lerpc(a,b,0.f).y, a.y);

    EXPECT_EQ(lerpc(a,b,1.f).x, b.x);
    EXPECT_EQ(lerpc(a,b,1.f).y, b.y);

    EXPECT_EQ(lerpc(a,b,-10.f).x, a.x);
    EXPECT_EQ(lerpc(a,b,-10.f).y, a.y);

    EXPECT_EQ(lerpc(a,b,10.f).x, b.x);
    EXPECT_EQ(lerpc(a,b,10.f).y, b.y);


    a = {10.2f,8.3f};
    b = {-6.4f,0.5f};

    EXPECT_EQ(lerpc(a,b,0.f).x, a.x);
    EXPECT_EQ(lerpc(a,b,0.f).y, a.y);

    EXPECT_EQ(lerpc(a,b,1.f).x, b.x);
    EXPECT_EQ(lerpc(a,b,1.f).y, b.y);

    EXPECT_EQ(lerpc(a,b,0.5f).x, (a.x+b.x)*0.5f);
    EXPECT_EQ(lerpc(a,b,0.5f).y, (a.y+b.y)*0.5f);

}

