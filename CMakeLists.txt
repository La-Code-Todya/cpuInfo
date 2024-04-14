cmake_minimum_required(VERSION 3.19.2)
project(CPUInformation)
set(CMAKE_CXX_STANDARD 17)


include(ExternalProject)
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)

ExternalProject_Add(cpuinfo
    GIT_REPOSITORY https://github.com/pytorch/cpuinfo.git
    GIT_TAG "main"
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)
include_directories(inc ${EXTERNAL_INSTALL_LOCATION}/include)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)

add_executable(CPUInformation src/main.cpp src/cpuinformation.cpp)
add_dependencies(CPUInformation cpuinfo)
target_link_libraries(CPUInformation libcpuinfo.a)
