include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicMathTests
        vector/vector2/TVector2_func_test.cpp
        vector/vector2/TVector2_func_interpolation_test.cpp
        vector/vector2/TVector2_operator_test.cpp

        vector/vector3/TVector3_func_test.cpp
        vector/vector3/TVector3_func_interpolation_test.cpp
        vector/vector3/TVector3_operator_test.cpp

        vector/vector4/TVector4_func_test.cpp
        vector/vector4/TVector4_func_interpolation_test.cpp
        vector/vector4/TVector4_operator_test.cpp

        vector/affinevector3/TAffineVector3_func_test.cpp
        vector/affinevector4/TAffineVector4_func_test.cpp

        matrix/matrix1x1/TMatrix1x1_func_test.cpp
        matrix/matrix1x1/TMatrix1x1_operator_test.cpp

        matrix/matrix1x2/TMatrix1x2_func_test.cpp
        matrix/matrix1x2/TMatrix1x2_operator_test.cpp

        matrix/matrix1x3/TMatrix1x3_func_test.cpp
        matrix/matrix1x3/TMatrix1x3_operator_test.cpp

        matrix/matrix1x4/TMatrix1x4_func_test.cpp
        matrix/matrix1x4/TMatrix1x4_operator_test.cpp

        matrix/matrix2x1/TMatrix2x1_func_test.cpp
        matrix/matrix2x1/TMatrix2x1_operator_test.cpp

        matrix/matrix2x2/TMatrix2x2_func_test.cpp
        matrix/matrix2x2/TMatrix2x2_operator_test.cpp

        matrix/matrix2x3/TMatrix2x3_func_test.cpp
        matrix/matrix2x3/TMatrix2x3_operator_test.cpp

        matrix/matrix2x4/TMatrix2x4_func_test.cpp
        matrix/matrix2x4/TMatrix2x4_operator_test.cpp


        matrix/matrix3x1/TMatrix3x1_func_test.cpp
        matrix/matrix3x1/TMatrix3x1_operator_test.cpp

        matrix/matrix3x2/TMatrix3x2_func_test.cpp
        matrix/matrix3x2/TMatrix3x2_operator_test.cpp

        matrix/matrix3x3/TMatrix3x3_func_test.cpp
        matrix/matrix3x3/TMatrix3x3_operator_test.cpp

        matrix/matrix3x4/TMatrix3x4_operator_test.cpp
        matrix/matrix3x4/TMatrix3x4_func_test.cpp


        matrix/matrix4x4/TMatrix4x4_func_test.cpp
        matrix/matrix4x4/TMatrix4x4_operator_test.cpp

        matrix/matrix4x3/TMatrix4x3_operator_test.cpp
        matrix/matrix4x3/TMatrix4x3_func_test.cpp

        matrix/matrix4x2/TMatrix4x2_operator_test.cpp
        matrix/matrix4x2/TMatrix4x2_func_test.cpp

        matrix/matrix4x1/TMatrix4x1_operator_test.cpp
        matrix/matrix4x1/TMatrix4x1_func_test.cpp


        matrix/affinematrix4x4/TAffineMatrix4x4_operator_test.cpp
        matrix/affinematrix4x4/TAffineMatrix4x4_func_test.cpp


        matrix/affinematrix3x3/TAffineMatrix3x3_operator_test.cpp
        matrix/affinematrix3x3/TAffineMatrix3x3_func_test.cpp

        vector/affinevector4/TAffineVector4_func_test.cpp
        vector/affinevector3/TAffineVector3_test_types.h
        vector/affinevector3/TAffineVector3_func_test.cpp

        vector/affinevector4/TAffineVector4_operator_test.cpp
        vector/affinevector3/TAffineVector3_operator_test.cpp


        profiler/MathStatisticTest.cpp
        profiler/RMProfilerTest.cpp
        profiler/RMProfilerStatOffTest.cpp

        quaternion/TQuaternion_operator_test.cpp

        )


target_link_libraries(runBasicMathTests gtest gtest_main)
