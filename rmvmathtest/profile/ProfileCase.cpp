//
// Created by Vitali Kurlovich on 4/3/16.
//

#include "ProfileCase.hpp"

#include "Profiler.hpp"

namespace profiler {

    ProfileCase::ProfileCase(Profiler *profiler, const char* name)
    : caseName(name)  {
            this->profiler=profiler;
    }

    ProfileCase::ProfileCase(Profiler *profiler) :
    ProfileCase(profiler, nullptr) {
}

    void ProfileCase::beginProfileCase(const char* casename) const {
        if (profiler ) {
            profiler->beginProfileCase(casename);
        }
    }

    void ProfileCase::endProfileCase(const char* casename) const  {
        if (profiler) {
            profiler->endProfileCase(casename);
        }
    }


    const std::string& ProfileCase::getName() const {
        return caseName;
    }





}