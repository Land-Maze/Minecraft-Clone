file(GLOB_RECURSE CORE_SOURCES CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE CORE_HEADERS CONFIGURE_DEPENDS include/Core/*.h)

add_library(Core STATIC ${CORE_SOURCES} ${CORE_HEADERS})

target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(Core PUBLIC glfw glad glm Render)
enable_edit_and_continue(Core)