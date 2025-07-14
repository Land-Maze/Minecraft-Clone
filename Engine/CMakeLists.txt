add_subdirectory(Core)
add_subdirectory(Render)

add_library(Engine INTERFACE)

target_link_libraries(Engine
    INTERFACE
        Core
        Render
)
