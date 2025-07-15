include(FetchContent)

# --- IMGUI ---
FetchContent_Declare(
	imgui
	GIT_REPOSITORY https://github.com/ocornut/imgui.git
	GIT_TAG        master
)

FetchContent_MakeAvailable(imgui)

add_library(imgui STATIC
	${imgui_SOURCE_DIR}/imgui.cpp
	${imgui_SOURCE_DIR}/imgui_draw.cpp
	${imgui_SOURCE_DIR}/imgui_tables.cpp
	${imgui_SOURCE_DIR}/imgui_widgets.cpp
	${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
	${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
)

target_include_directories(imgui PUBLIC
	${imgui_SOURCE_DIR}
	${imgui_SOURCE_DIR}/backends
)

target_link_libraries(imgui PUBLIC glfw)

# --- GLFW ---
FetchContent_Declare(
	glfw
	GIT_REPOSITORY https://github.com/glfw/glfw.git
	GIT_TAG        3.4
)

FetchContent_MakeAvailable(glfw)

# --- GLM ---
FetchContent_Declare(
	glm
	GIT_REPOSITORY https://github.com/g-truc/glm
)

FetchContent_MakeAvailable(glm)

# --- GLAD ---
add_library(glad
	glad/src/glad.c
)

target_include_directories(glad PUBLIC
	glad/include
)

# --- STB ---
add_library(stb stb/stb_image.cpp stb/stb_image.h)

target_include_directories(stb PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})