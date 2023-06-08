set(BINARY Saunaklonkku)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.hpp *.cpp)

add_executable(${BINARY} ${SOURCES})

if(NOT TARGET spdlog)
    find_package(spdlog REQUIRED)
endif()

add_library(config++ SHARED IMPORTED)
set_target_properties(config++
    PROPERTIES IMPORTED_LOCATION /usr/local/lib/libconfig++.so
)
target_link_libraries(${BINARY}
    PUBLIC spdlog::spdlog config++ dpp
)
target_include_directories(${BINARY}
    PUBLIC ${SRC_DIR} ${CMAKE_CURRENT_SOURCE_DIR}
)

include(GNUInstallDirs)
# This will install all runtime dependencies to /usr/local/lib
install(TARGETS ${BINARY}
    CONFIGURATIONS Release
    COMPONENT binary
    RUNTIME_DEPENDENCIES
)
install(FILES ${CMAKE_SOURCE_DIR}/config.cfg
    DESTINATION etc/saunabot
    COMPONENT config
)
