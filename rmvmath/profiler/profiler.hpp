//
// Created by Vitali Kurlovich on 3/3/16.
//

#ifdef RM_MATH_STAT
#import "MathStatistic.hpp"
#endif

#ifdef RM_MATH_STAT
#define RM_STAT_MUL(mul) MathStatistic::instance().incMul(mul);
#define RM_STAT_DIV(div) MathStatistic::instance().incDiv(div);

#define RM_STAT_SUM(sum) MathStatistic::instance().incSum(sum);
#define RM_STAT_SUB(sub) MathStatistic::instance().incSub(sub);

#define RM_STAT_SQRT(sqrt) MathStatistic::instance().incSqrt(sqrt);

#define RM_STAT_CALLS(calls) MathStatistic::instance().incCalls(calls);

#else
#define RM_STAT_MUL(mul) /* MULs:  mul */
#define RM_STAT_DIV(div) /* DIVs:  div */

#define RM_STAT_SUM(sum) /* SUMs:  sum */
#define RM_STAT_SUB(sub) /* SUBs:  sub */

#define RM_STAT_SQRT(sub) /* SQRTs:  sqrt */
#define RM_STAT_CALLS(calls) /* CALLs: call */
#endif


