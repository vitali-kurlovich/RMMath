//
// Created by Vitali Kurlovich on 12/11/15.
//

#include "gtest/gtest.h"

#include "TVector3_test_types.h"


// Lerp

TEST(lerpf, lerp3) {

    tvec3f a = {0,8,5};
    tvec3f b = {-6,0,9};

    EXPECT_FLOAT_EQ(lerp(a,b,0.f).x, a.x);
    EXPECT_FLOAT_EQ(lerp(a,b,0.f).y, a.y);
    EXPECT_FLOAT_EQ(lerp(a,b,0.f).z, a.z);

    EXPECT_FLOAT_EQ(lerp(a,b,1.f).x, b.x);
    EXPECT_FLOAT_EQ(lerp(a,b,1.f).y, b.y);
    EXPECT_FLOAT_EQ(lerp(a,b,1.f).z, b.z);



    a = {10.2f,8.3f, -6.4f};
    b = {-6.4f,0.5f, 0.3f};

    EXPECT_EQ(lerp(a,b,0.f).x, a.x);
    EXPECT_EQ(lerp(a,b,0.f).y, a.y);
    EXPECT_EQ(lerp(a,b,0.f).z, a.z);

    EXPECT_NE(lerp(a,b,-0.5f).x, a.x);
    EXPECT_NE(lerp(a,b,-0.5f).y, a.y);
    EXPECT_NE(lerp(a,b,-0.5f).z, a.z);

    EXPECT_EQ(lerp(a,b,1.f).x, b.x);
    EXPECT_EQ(lerp(a,b,1.f).y, b.y);
    EXPECT_EQ(lerp(a,b,1.f).z, b.z);

    EXPECT_FLOAT_EQ(lerp(a,b,0.5f).x, (a.x+b.x)*0.5f);
    EXPECT_FLOAT_EQ(lerp(a,b,0.5f).y, (a.y+b.y)*0.5f);
    EXPECT_FLOAT_EQ(lerp(a,b,0.5f).z, (a.z+b.z)*0.5f);

}

// Lerpc

TEST(lerpcf, lerpc3) {

    tvec3f a = {0,8,5};
    tvec3f b = {-6,0,9};

    EXPECT_FLOAT_EQ(lerpc(a,b,0.f).x, a.x);
    EXPECT_FLOAT_EQ(lerpc(a,b,0.f).y, a.y);
    EXPECT_FLOAT_EQ(lerpc(a,b,0.f).z, a.z);

    EXPECT_FLOAT_EQ(lerpc(a,b,1.f).x, b.x);
    EXPECT_FLOAT_EQ(lerpc(a,b,1.f).y, b.y);
    EXPECT_FLOAT_EQ(lerpc(a,b,1.f).z, b.z);


    a = {10.2f,8.3f, -6.4f};
    b = {-6.4f,0.5f, 0.3f};

    EXPECT_EQ(lerpc(a,b,0.f).x, a.x);
    EXPECT_EQ(lerpc(a,b,0.f).y, a.y);
    EXPECT_EQ(lerpc(a,b,0.f).z, a.z);

    EXPECT_FLOAT_EQ(lerpc(a,b,-0.5f).x, a.x);
    EXPECT_FLOAT_EQ(lerpc(a,b,-0.5f).y, a.y);
    EXPECT_FLOAT_EQ(lerpc(a,b,-0.5f).z, a.z);

    EXPECT_FLOAT_EQ(lerpc(a,b,10.f).x, b.x);
    EXPECT_FLOAT_EQ(lerpc(a,b,10.f).y, b.y);
    EXPECT_FLOAT_EQ(lerpc(a,b,10.f).z, b.z);

    EXPECT_FLOAT_EQ(lerpc(a,b,0.5f).x, (a.x+b.x)*0.5f);
    EXPECT_FLOAT_EQ(lerpc(a,b,0.5f).y, (a.y+b.y)*0.5f);
    EXPECT_FLOAT_EQ(lerpc(a,b,0.5f).z, (a.z+b.z)*0.5f);

}
