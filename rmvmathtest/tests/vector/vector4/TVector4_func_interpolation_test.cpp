//
// Created by Vitali Kurlovich on 12/11/15.
//

#include "gtest/gtest.h"

#include "TVector4_test_types.h"


// Lerp

TEST(lerpf, lerp4) {

    tvec4f a = {7,8,5,9};
    tvec4f b = {-6,3,9,99};

    EXPECT_FLOAT_EQ(lerp(a,b,0.f).x, a.x);
    EXPECT_FLOAT_EQ(lerp(a,b,0.f).y, a.y);
    EXPECT_FLOAT_EQ(lerp(a,b,0.f).z, a.z);
    EXPECT_FLOAT_EQ(lerp(a,b,0.f).w, a.w);

    EXPECT_FLOAT_EQ(lerp(a,b,1.f).x, b.x);
    EXPECT_FLOAT_EQ(lerp(a,b,1.f).y, b.y);
    EXPECT_FLOAT_EQ(lerp(a,b,1.f).z, b.z);
    EXPECT_FLOAT_EQ(lerp(a,b,1.f).w, b.w);

    a = {7,8,5,9};
    b = {-6,3,9,99};

    EXPECT_NE(lerp(a,b,-0.5f).x, a.x);
    EXPECT_NE(lerp(a,b,-0.5f).y, a.y);
    EXPECT_NE(lerp(a,b,-0.5f).z, a.z);
    EXPECT_NE(lerp(a,b,-0.5f).w, a.w);

    EXPECT_FLOAT_EQ(lerp(a,b,0.5f).x, (a.x+b.x)*0.5f);
    EXPECT_FLOAT_EQ(lerp(a,b,0.5f).y, (a.y+b.y)*0.5f);
    EXPECT_FLOAT_EQ(lerp(a,b,0.5f).z, (a.z+b.z)*0.5f);
    EXPECT_FLOAT_EQ(lerp(a,b,0.5f).w, (a.w+b.w)*0.5f);

}

// Lerpc

TEST(lerpcf, lerpc4) {

    tvec4f a = {7,8,5,9};
    tvec4f b = {-6,3,9,99};

    EXPECT_FLOAT_EQ(lerpc(a,b,0.f).x, a.x);
    EXPECT_FLOAT_EQ(lerpc(a,b,0.f).y, a.y);
    EXPECT_FLOAT_EQ(lerpc(a,b,0.f).z, a.z);
    EXPECT_FLOAT_EQ(lerpc(a,b,0.f).w, a.w);

    EXPECT_FLOAT_EQ(lerpc(a,b,1.f).x, b.x);
    EXPECT_FLOAT_EQ(lerpc(a,b,1.f).y, b.y);
    EXPECT_FLOAT_EQ(lerpc(a,b,1.f).z, b.z);
    EXPECT_FLOAT_EQ(lerpc(a,b,1.f).w, b.w);

    a = {7,8,5,9};
    b = {-6,3,9,99};

    EXPECT_FLOAT_EQ(lerpc(a,b,-0.5f).x, a.x);
    EXPECT_FLOAT_EQ(lerpc(a,b,-0.5f).y, a.y);
    EXPECT_FLOAT_EQ(lerpc(a,b,-0.5f).z, a.z);
    EXPECT_FLOAT_EQ(lerpc(a,b,-0.5f).w, a.w);


    EXPECT_FLOAT_EQ(lerpc(a,b,10.5f).x, b.x);
    EXPECT_FLOAT_EQ(lerpc(a,b,10.5f).y, b.y);
    EXPECT_FLOAT_EQ(lerpc(a,b,10.5f).z, b.z);
    EXPECT_FLOAT_EQ(lerpc(a,b,10.5f).w, b.w);

    EXPECT_FLOAT_EQ(lerpc(a,b,0.5f).x, (a.x+b.x)*0.5f);
    EXPECT_FLOAT_EQ(lerpc(a,b,0.5f).y, (a.y+b.y)*0.5f);
    EXPECT_FLOAT_EQ(lerpc(a,b,0.5f).z, (a.z+b.z)*0.5f);
    EXPECT_FLOAT_EQ(lerpc(a,b,0.5f).w, (a.w+b.w)*0.5f);

}
