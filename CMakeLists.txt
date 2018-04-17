cmake_minimum_required (VERSION 2.6)
ENABLE_LANGUAGE(CXX)
set(CMAKE_BUILD_TYPE Release)

project (CppGameOfLife)

set(PROJECT_SRC ${CppGameOfLife_SOURCE_DIR}/src)
include_directories(${CppGameOfLife_SOURCE_DIR}/src)
include_directories(${CppGameOfLife_SOURCE_DIR}/test)
include_directories(${PROJECT_SRC})

file(GLOB SRC_FILES ${PROJECT_SRC}/*.h ${PROJECT_SRC}/*.hpp ${PROJECT_SRC}/*.cpp)

add_library(gameOfLifeLib SHARED  ${SRC_FILES})
SET_TARGET_PROPERTIES(gameOfLifeLib PROPERTIES LINKER_LANGUAGE CXX)

set(GTEST_DIR ${CppGameOfLife_SOURCE_DIR}/test/gtest/gtest-1.7.0)
set(GTEST_INCLUDE_DIRECTORIES ${GTEST_DIR}/include ${GTEST_DIR} ${GTEST_DIR}/src)
MESSAGE( "Attempt to build gtest. gtest directory: " ${GTEST_DIR})
include_directories(${GTEST_INCLUDE_DIRECTORIES})
add_library(gtest_170_lib ${GTEST_DIR}/src/gtest-all.cc)
set_target_properties(gtest_170_lib PROPERTIES COMPILE_DEFINITIONS "GTEST_HAS_RTTI=0")

file(GLOB TEST_SRC_FILES "test/*.cpp")

SET(CMAKE_CXX_FLAGS "-Wall -Wno-sign-compare -rdynamic -Wunused -std=c++11 -pthread -D_GLIBCXX_USE_NANOSLEEP")
add_executable(UnitTestRunner ${TEST_SRC_FILES} )
target_link_libraries(UnitTestRunner gameOfLifeLib gtest_170_lib)

add_executable(CppGameOfLife ${CppGameOfLife_SOURCE_DIR}/main.cpp)
target_link_libraries(CppGameOfLife gameOfLifeLib)

