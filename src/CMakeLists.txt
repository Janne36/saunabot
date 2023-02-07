
set(EXEC_NAME Saunaklonkku)
add_executable(${EXEC_NAME}
    main.cpp
    manager.cpp
    saunabot.cpp
    eventHandler.cpp
    logger.cpp)

if(NOT TARGET spdlog)
    find_package(spdlog REQUIRED)
endif()

target_link_libraries(${EXEC_NAME} dpp utils spdlog::spdlog)
