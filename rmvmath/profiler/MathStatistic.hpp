//
// Created by Vitali Kurlovich on 2/24/16.
//

#ifndef RMVECTORMATH_MATHSTATISTIC_HPP
#define RMVECTORMATH_MATHSTATISTIC_HPP

namespace rmmath {

    class MathStatistic {

    private:
        int32_t _mul;
        int32_t _div;
        int32_t _sum;
        int32_t _sub;

        int32_t _sqrt;

    public: MathStatistic() :
               _mul(0), _div(0), _sum(0), _sub(0), _sqrt(0) {
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

        MathStatistic& incMul(int32_t count) {
            _mul += count;
            return *this;
        }

        MathStatistic& incDiv(int32_t count) {
            _div += count;
            return *this;
        }

        MathStatistic& incSum(int32_t count) {
            _sum += count;
            return *this;
        }

        MathStatistic& incSub(int32_t count) {
            _sub += count;
            return *this;
        }

        MathStatistic& incSqrt(int32_t count) {
            _sqrt += count;
            return *this;
        }

        void resetAll() {
            resetMul();
            resetDiv();
            resetSum();
            resetSub();
            resetSqrt();
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
    };

}

#endif //RMVECTORMATH_MATHSTATISTIC_HPP
