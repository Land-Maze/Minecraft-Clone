file(GLOB CORE_SOURCES CONFIGURE_DEPENDS *.cpp)

add_library(Core STATIC ${CORE_SOURCES})

target_include_directories(Core PUBLIC
    ${CMAKE_SOURCE_DIR}/Engine/include
)

target_link_libraries(Core
    PUBLIC
        glfw
        glad
        glm::glm
)
