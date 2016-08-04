project(rmvmathprofile)
add_definitions(-std=c++14)


set(SOURCE_FILES  profiler.cpp ProfileCase.cpp)

add_executable(rmvecmathProfileRun ${SOURCE_FILES})
