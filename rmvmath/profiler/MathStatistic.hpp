//
// Created by Vitali Kurlovich on 2/24/16.
//

#ifndef RMVECTORMATH_MATHSTATISTIC_HPP
#define RMVECTORMATH_MATHSTATISTIC_HPP

namespace rmmath {

    class MathStatistic {

    private:
        int32_t _mul{0};
        int32_t _div{0};
        int32_t _sum{0};
        int32_t _sub{0};

        int32_t _sqrt{0};
        int32_t _calls{0};

    public: MathStatistic() :
               _mul(0), _div(0), _sum(0), _sub(0), _sqrt(0), _calls(0) {
        }

    public:
        static MathStatistic& instance() {
            static MathStatistic *instance = new MathStatistic();
            return *instance;
        }

    public:
        void resetMul() { _mul = 0;}
        void resetDiv() { _div = 0;}
        void resetSum() { _sum = 0;}
        void resetSub() { _sub = 0;}
        void resetSqrt() { _sqrt = 0;}
        void resetCalls() { _calls = 0;}

        MathStatistic& incMul(int32_t count = 1) {
            _mul += count;
            return *this;
        }

        MathStatistic& incDiv(int32_t count = 1) {
            _div += count;
            return *this;
        }

        MathStatistic& incSum(int32_t count = 1) {
            _sum += count;
            return *this;
        }

        MathStatistic& incSub(int32_t count = 1) {
            _sub += count;
            return *this;
        }

        MathStatistic& incSqrt(int32_t count = 1) {
            _sqrt += count;
            return *this;
        }

        MathStatistic& incCalls(int32_t count = 1) {
            _calls += count;
            return *this;
        }

        void resetAll() {
            resetMul();
            resetDiv();
            resetSum();
            resetSub();
            resetSqrt();
            resetCalls();
        }

    public:
        const int32_t mul() const {
            return _mul;
        }

        const int32_t div() const {
            return _div;
        }

        const int32_t sum() const {
            return _sum;
        }

        const int32_t sub() const {
            return _sub;
        }

        const int32_t sqrt() const {
            return _sqrt;
        }

        const int32_t calls() const {
            return _calls;
        }
    };

}

#endif //RMVECTORMATH_MATHSTATISTIC_HPP
