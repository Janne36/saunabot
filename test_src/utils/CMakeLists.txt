include(GoogleTest)

find_package(GTest REQUIRED)

add_executable(utilsTest utilsTests.cpp)
target_link_libraries(utilsTest GTest::GTest GTest::Main)
target_include_directories(utilsTest PRIVATE  ${CMAKE_SOURCE_DIR}/src/utils)

gtest_discover_tests(utilsTest)
