//
// Created by Vitali Kurlovich on 3/22/16.
//

#ifndef RMVECTORMATH_PROFILER_HPP
#define RMVECTORMATH_PROFILER_HPP


#include <vector>
#include <stack>
#include <chrono>

#include "ProfileCase.hpp"
#include <profiler/MathStatistic.hpp>



namespace profiler {

    class Profiler {

    protected:
        std::vector<const ProfileCase*> profileCases;
        std::stack<std::chrono::steady_clock::time_point> timestack;
        bool _blockCout{false};

    public:
        void addProfileCases(const ProfileCase* profileCase ) {
            profileCases.push_back(profileCase);
        }

        void run() {
            std::cout << "Start profiling..." <<  std::endl;
            std::vector<const ProfileCase*>::iterator i;

            _blockCout = true;
            for (u_int32_t iter = 0; iter < 10; iter++) {
                for (i = profileCases.begin(); i != profileCases.end(); ++i) {
                    rmmath::MathStatistic::instance().resetAll();
                    (*i)->run();
                }
            }

            _blockCout = false;
            for (i = profileCases.begin(); i!= profileCases.end(); ++i) {
                printProfileCaseHeader(*i);
                rmmath::MathStatistic::instance().resetAll();
                (*i)->run();
            }
        }

    public:
        void beginProfileCase(const char* casename) {
            if (_blockCout)
                return;
            printBeginProfileCase(casename);
            rmmath::MathStatistic::instance().resetAll();
            auto now = std::chrono::steady_clock::now();
            timestack.push(now);
        }

        void endProfileCase(const char* casename) {
            if (_blockCout)
                return;
            auto now = std::chrono::steady_clock::now();
            auto begintime = timestack.top();
            timestack.pop();

            std::cout << "Duration: " <<  std::chrono::duration_cast<std::chrono::milliseconds>(now - begintime).count() << "ms" << std::endl;

            printMathStatistic();
        }

    protected:
        void printProfileCaseHeader(const ProfileCase* profileCase) {
            std::cout << "[--- " << profileCase->getName() << " ---]" << std::endl;
        }

        void printMathStatistic() {
            bool show = false;
            auto mul = rmmath::MathStatistic::instance().mul();
            show |= (mul > 0);

            auto div = rmmath::MathStatistic::instance().div();
            show |= (div > 0);

            auto sum = rmmath::MathStatistic::instance().sum();
            show |= (sum > 0);

            auto sub = rmmath::MathStatistic::instance().sub();
            show |= (sub > 0);

            auto sqrt = rmmath::MathStatistic::instance().sqrt();
            show |= (sqrt > 0);

            if (!show)
                return;

                std::cout << "[ Math Statistic ]" << std::endl;

                if (sum > 0) {
                    std::cout << " Sum: " << sum <<std::endl;
                }

                if (sub > 0) {
                    std::cout << " Sub: " << sub <<std::endl;
                }

                if (mul > 0) {
                    std::cout << " Mul: " << mul <<std::endl;
                }

                if (div > 0) {
                    std::cout << " Div: " << div <<std::endl;
                }

                if (sqrt > 0) {
                    std::cout << " Sqrt: " << sqrt <<std::endl;
                }

                std::cout << "[ -------------- ]" << std::endl;



        }

        void printBeginProfileCase(const char* casename) {

            std::cout << "+++ " << casename << " +++" << std::endl;
        }
    };
}

#endif //RMVECTORMATH_PROFILER_HPP
