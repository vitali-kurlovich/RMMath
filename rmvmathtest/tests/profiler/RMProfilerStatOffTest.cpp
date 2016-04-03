//
// Created by Vitali Kurlovich on 3/3/16.
//

#include "gtest/gtest.h"

#include <profiler/MathStatistic.hpp>

#undef RM_MATH_STAT
#include <profiler/profiler.hpp>


using namespace rmmath;

TEST(ProfilerStatOff, mul) {

    MathStatistic::instance().resetAll();

    RM_STAT_MUL(6);

    EXPECT_EQ(MathStatistic::instance().mul(), 0);

    RM_STAT_MUL(10);

    EXPECT_EQ(MathStatistic::instance().mul(), 0);
}