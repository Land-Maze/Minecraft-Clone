file(GLOB_RECURSE UTILS_SRC CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE UTILS_HDR CONFIGURE_DEPENDS include/Utils/*.h)

add_library(Utils STATIC ${UTILS_SRC} ${UTILS_HDR})
target_include_directories(Utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(Utils PRIVATE glad glfw glm stb)
enable_edit_and_continue(Utils)