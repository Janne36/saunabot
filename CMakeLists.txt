cmake_minimum_required(VERSION 3.13)
project(discortBot)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set_property(GLOBAL PROPERTY SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

enable_testing()

add_subdirectory(src)
add_subdirectory(test_src)

#add_custom_command(build_tests SHARED)

include(InstallRequiredSystemLibraries)

set(CPACK_PACKAGE_NAME "saunabot")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENCE")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_SOURCE_GENERATOR "TGZ")

set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Gollum")
#set(CPACK_DEBIAN_PACKAGE_DEPENDS "spdlog, dpp")

include(CPack)
