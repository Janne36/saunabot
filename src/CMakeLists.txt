
set(EXEC_NAME Saunaklonkku)
add_executable(${EXEC_NAME}
    main.cpp
    manager.cpp
    saunabot.cpp
    eventHandler.cpp
    logger.cpp
    utils/utils.cpp
    config/configHandler.cpp)

if(NOT TARGET spdlog)
    find_package(spdlog REQUIRED)
endif()

add_library(config++ SHARED IMPORTED )
set_target_properties(config++ PROPERTIES IMPORTED_LOCATION /usr/local/lib/libconfig++.so)

target_link_libraries(${EXEC_NAME} PUBLIC spdlog::spdlog config++ dpp)
target_include_directories(${EXEC_NAME} PUBLIC ${SRC_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
