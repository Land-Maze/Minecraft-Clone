cmake_minimum_required(VERSION 3.16)
project(Minecraft-Clone)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

function(enable_edit_and_continue target)
    if(MSVC AND CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_compile_options(${target} PRIVATE /Zi)
        target_link_options(${target} PRIVATE /INCREMENTAL)
    endif()
endfunction()

find_package(OpenGL REQUIRED)

add_subdirectory(External)
add_subdirectory(Engine)
add_subdirectory(Game)


# Move assets to the build
file(COPY ${CMAKE_SOURCE_DIR}/Assets DESTINATION ${CMAKE_BINARY_DIR}/bin)