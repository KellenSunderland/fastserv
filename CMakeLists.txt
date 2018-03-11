# CMake 3.1 required for the Hunter package manager.
cmake_minimum_required(VERSION 3.1)

# Setup Hunter package manager.
include("cmake/HunterGate.cmake")

# Pin a version of the Hunter package manager.
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.20.15.tar.gz"
    SHA1 "bcdc0b23f0428187a5dadd99b2ac3a47b2274c2d")

project(fastserv)

# Add gflags for CLI argument handling.
hunter_add_package(gflags)
find_package(gflags CONFIG REQUIRED)

# Add glog for project logging.
hunter_add_package(glog)
find_package(glog CONFIG REQUIRED)

# Add GTest for unit tests.
hunter_add_package(GTest)
find_package(GMock CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(WITH_LIBEVENT true)
set(BUILD_COMPILER true)

add_executable(fastserv main.cpp)
target_link_libraries(fastserv
    gflags
    glog::glog
    GMock::main)
