
enable_testing()

find_package(GTest REQUIRED)
add_library(gtestBase OBJECT EXCLUDE_FROM_ALL main.cpp)
target_link_libraries(gtestBase GTest::GTest GTest::gmock GTest::Main)

if(NOT TARGET spdlog)
    find_package(spdlog REQUIRED)
endif()

add_library(config++ SHARED IMPORTED )
set_target_properties(config++ PROPERTIES IMPORTED_LOCATION /usr/local/lib/libconfig++.so)

# -- EventHandlerTests --
set(BINARY eventHandlerTests)
set(TEST_SOURCES
    eventHandlerTests.cpp
    ${CMAKE_SOURCE_DIR}/src/eventHandler/eventHandler.cpp
    ${CMAKE_SOURCE_DIR}/src/config/configHandler.cpp
    ${CMAKE_SOURCE_DIR}/tst/stubs/loggerStub.cpp
)
set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} EXCLUDE_FROM_ALL ${TEST_SOURCES})
add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC gtestBase spdlog::spdlog config++ dpp)
target_include_directories(${BINARY} PUBLIC ${SRC_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

# -- End --
