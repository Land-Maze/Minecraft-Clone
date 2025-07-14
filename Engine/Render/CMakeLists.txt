file(GLOB_RECURSE RENDER_SRC CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE RENDER_HDR CONFIGURE_DEPENDS include/Render/*.h)

add_library(Render STATIC ${RENDER_SRC} ${RENDER_HDR})
target_include_directories(Render PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(Render PRIVATE glad glfw)
