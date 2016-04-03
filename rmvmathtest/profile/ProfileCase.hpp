//
// Created by Vitali Kurlovich on 3/22/16.
//

#ifndef RMVECTORMATH_PROFILECASE_HPP
#define RMVECTORMATH_PROFILECASE_HPP

#include <iostream>

namespace profiler {

    class Profiler;

    class ProfileCase {

    protected:
        std::string caseName;
        Profiler *profiler;
    public:

        ProfileCase(Profiler *profiler, const char* name);
        ProfileCase(Profiler *profiler);

    protected:
         void beginProfileCase(const char* casename) const;
         void endProfileCase(const char* casename) const;

    public:
        virtual void run() const = 0;

    public:
        const std::string& getName() const;
    };
}

#endif //RMVECTORMATH_PROFILECASE_HPP
