//
// Created by Vitali Kurlovich on 3/3/16.
//

#include "gtest/gtest.h"

#include <profiler/MathStatistic.hpp>

#define RM_MATH_STAT 1
#include <profiler/profiler.hpp>

using namespace rmmath;

TEST(ProfilerStat, mul) {

    MathStatistic::instance().resetAll();

    RM_STAT_MUL(5)
    RM_STAT_DIV(6)
    RM_STAT_SUB(7)
    RM_STAT_SUM(8);

    EXPECT_EQ(MathStatistic::instance().mul(), 5);
    EXPECT_EQ(MathStatistic::instance().div(), 6);
    EXPECT_EQ(MathStatistic::instance().sub(), 7);
    EXPECT_EQ(MathStatistic::instance().sum(), 8);
}

#undef RM_MATH_STAT