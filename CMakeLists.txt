cmake_minimum_required(VERSION 3.13)
project(discortBot)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/release)

set_property(GLOBAL PROPERTY SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

#enable_testing()
include_directories(src)

add_subdirectory(src)
add_subdirectory(tst)

#add_custom_target(unit_tests SHARED)
include(InstallRequiredSystemLibraries)

set(CPACK_PACKAGE_NAME "saunabot")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENCE")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_SOURCE_GENERATOR "TGZ;DEB")
set(CPACK_INSTALL_CMAKE_PROJECTS "src;Saunaklonkku;ALL;/")

set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Gollum")
#set(CPACK_DEBIAN_PACKAGE_DEPENDS "spdlog, dpp")

include(CPack)
