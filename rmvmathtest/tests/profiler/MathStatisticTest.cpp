//
// Created by Vitali Kurlovich on 2/24/16.
//

#include "gtest/gtest.h"

#include <profiler/MathStatistic.hpp>

using namespace rmmath;

TEST(MathStatistic, mul) {

    MathStatistic stat;

    EXPECT_EQ(stat.mul(), 0);
    stat.incMul(5);
    EXPECT_EQ(stat.mul(), 5);
    stat.incMul(20);
    EXPECT_EQ(stat.mul(), 25);

    stat.resetMul();
    EXPECT_EQ(stat.mul(), 0);

    stat.incMul(3);
    EXPECT_EQ(stat.mul(), 3);
    stat.incMul(20);
    EXPECT_EQ(stat.mul(), 23);
}

TEST(MathStatistic, div) {
    MathStatistic stat;

    EXPECT_EQ(stat.div(), 0);
    stat.incDiv(5);
    EXPECT_EQ(stat.div(), 5);
    stat.incDiv(20);
    EXPECT_EQ(stat.div(), 25);

    stat.resetDiv();
    EXPECT_EQ(stat.div(), 0);

    stat.incDiv(3);
    EXPECT_EQ(stat.div(), 3);
    stat.incDiv(20);
    EXPECT_EQ(stat.div(), 23);

}

TEST(MathStatistic, sum) {
    MathStatistic stat;

    EXPECT_EQ(stat.sum(), 0);
    stat.incSum(5);
    EXPECT_EQ(stat.sum(), 5);
    stat.incSum(20);
    EXPECT_EQ(stat.sum(), 25);

    stat.resetSum();
    EXPECT_EQ(stat.sum(), 0);

    stat.incSum(3);
    EXPECT_EQ(stat.sum(), 3);
    stat.incSum(20);
    EXPECT_EQ(stat.sum(), 23);
}

TEST(MathStatistic, sub) {
    MathStatistic stat;

    EXPECT_EQ(stat.sub(), 0);
    stat.incSub(5);
    EXPECT_EQ(stat.sub(), 5);
    stat.incSub(20);
    EXPECT_EQ(stat.sub(), 25);

    stat.resetSub();
    EXPECT_EQ(stat.sub(), 0);

    stat.incSub(3);
    EXPECT_EQ(stat.sub(), 3);
    stat.incSub(20);
    EXPECT_EQ(stat.sub(), 23);
}

TEST(MathStatistic, sqrt) {
    MathStatistic stat;

    EXPECT_EQ(stat.sqrt(), 0);
    stat.incSqrt(5);
    EXPECT_EQ(stat.sqrt(), 5);
    stat.incSqrt(20);
    EXPECT_EQ(stat.sqrt(), 25);

    stat.resetSqrt();
    EXPECT_EQ(stat.sqrt(), 0);

    stat.incSqrt(3);
    EXPECT_EQ(stat.sqrt(), 3);
    stat.incSqrt(20);
    EXPECT_EQ(stat.sqrt(), 23);
}


TEST(MathStatistic, mix) {
    MathStatistic stat;

    stat.incMul(5).incDiv(8).incSub(9).incSum(12).incSqrt(15);

    EXPECT_EQ(stat.mul(), 5);

    EXPECT_EQ(stat.div(), 8);
    EXPECT_EQ(stat.sum(), 12);
    EXPECT_EQ(stat.sub(), 9);
    EXPECT_EQ(stat.sqrt(), 15);

    stat.resetAll();
    EXPECT_EQ(stat.mul(), 0);
    EXPECT_EQ(stat.div(), 0);
    EXPECT_EQ(stat.sum(), 0);
    EXPECT_EQ(stat.sub(), 0);
    EXPECT_EQ(stat.sqrt(), 0);
}

TEST(MathStatistic, instnce) {

    MathStatistic::instance().resetAll();

    MathStatistic::instance().incMul(5).incDiv(8).incSub(9).incSum(12).incSqrt(15);

    EXPECT_EQ( MathStatistic::instance().mul(), 5);

    EXPECT_EQ( MathStatistic::instance().div(), 8);
    EXPECT_EQ( MathStatistic::instance().sum(), 12);
    EXPECT_EQ( MathStatistic::instance().sub(), 9);
    EXPECT_EQ( MathStatistic::instance().sqrt(), 15);

    MathStatistic::instance().resetAll();

    EXPECT_EQ(MathStatistic::instance().mul(), 0);
    EXPECT_EQ(MathStatistic::instance().div(), 0);
    EXPECT_EQ(MathStatistic::instance().sum(), 0);
    EXPECT_EQ(MathStatistic::instance().sub(), 0);
    EXPECT_EQ(MathStatistic::instance().sqrt(), 0);


    MathStatistic::instance().incMul(5).incDiv(8).incSub(9).incSum(12).incSqrt(15);

    MathStatistic stat = MathStatistic::instance();

    stat.incMul(5).incDiv(8).incSub(9).incSum(12).incSqrt(15);

    EXPECT_EQ(stat.mul(), 10);

    EXPECT_EQ(stat.div(), 16);
    EXPECT_EQ(stat.sum(), 24);
    EXPECT_EQ(stat.sub(), 18);
    EXPECT_EQ(stat.sqrt(), 30);
}