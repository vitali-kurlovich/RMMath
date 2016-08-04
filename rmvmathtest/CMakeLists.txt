project(rmvmathtest)

add_definitions(-std=c++11)

add_subdirectory(libs/googletest)
add_subdirectory(tests)
add_subdirectory(profile)