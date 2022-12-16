# CMakeList.txt : CMake project for sequential_version, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8 FATAL_ERROR)

project ("sequential_version")


# TODO: Add tests and install targets if needed.


OPTION(BUILD_WITH_OPENMP "Build with OPENMP" OFF)
IF(BUILD_WITH_OPENMP)
# to set the /openmp switch
find_package(OpenMP REQUIRED)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
ENDIF(BUILD_WITH_OPENMP)


SET(sequential_version-src 
sequential_version.cpp
)

SET(sequential_version-header
)

ADD_EXECUTABLE(
    sequential_version
${sequential_version-src} 
${sequential_version-header}
)

IF(BUILD_WITH_OPENMP)
set_target_properties(sequential_version PROPERTIES OUTPUT_NAME "sequential_version_omp")
ENDIF(BUILD_WITH_OPENMP)

