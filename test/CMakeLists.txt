cmake_minimum_required(VERSION 3.19.2)
project(cpuinformation_test)
set(CMAKE_CXX_STANDARD 17)
include(ExternalProject)
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/test/external)

# ExternalProject_Add(googletest
#     GIT_REPOSITORY https://github.com/google/googletest
#     GIT_TAG "main"
#     CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
# )

ExternalProject_Add(cpuinfo
    GIT_REPOSITORY https://github.com/pytorch/cpuinfo.git
    GIT_TAG "main"
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)

include_directories(../inc test/inc ${EXTERNAL_INSTALL_LOCATION}/include)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)

set(BINARY cpuinformation_test)

add_executable(${BINARY} main.cpp cpuinformation_test.cpp ../src/cpuinformation.cpp)
add_dependencies(${BINARY} cpuinfo)
add_test(NAME ${BINARY} COMMAND ${BINARY})

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    target_link_libraries(${BINARY} gtest.lib cpuinfo.lib)
else()
target_link_libraries(${BINARY} libgtest.a libcpuinfo.a)
endif()
