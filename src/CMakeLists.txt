
set(EXEC_NAME Saunaklonkku)
add_executable(${EXEC_NAME} 
    main.cpp
    manager.cpp
    saunabot.cpp)

target_link_libraries(${EXEC_NAME} dpp utils)
