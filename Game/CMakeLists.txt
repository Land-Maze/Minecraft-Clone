add_executable(Game main.cpp)

target_link_libraries(Game PRIVATE Engine)
enable_edit_and_continue(Core)