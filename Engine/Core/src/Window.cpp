#include <Core/Window.h>

static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (auto* input = static_cast<Core::Input*>(glfwGetWindowUserPointer(window))) {
		input->KeyCallback(window, key, scancode, action, mods);
	}
}

static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	if (auto* input = static_cast<Core::Input*>(glfwGetWindowUserPointer(window))) {
		input->MouseButtonCallback(window, button, action, mods);
	}
}

static void MousePositionCallback(GLFWwindow* window, double xpos, double ypos) {
	if (auto* input = static_cast<Core::Input*>(glfwGetWindowUserPointer(window))) {
		input->MousePositionCallback(window, xpos, ypos);
	}
}

Core::Window::Window() : m_width(800), m_height(600), m_title("Default Window"), m_isVisible(false), m_windowHandle(nullptr), m_isMouseUnlocked(false) {}

Core::Window::~Window() {
	Shutdown();
}

bool Core::Window::Initialize() {
	if (!glfwInit()) {
		return false;
	}

	m_windowHandle = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
	if (m_windowHandle == NULL) {
		glfwTerminate();
		return false;
	}

	glfwSetInputMode(m_windowHandle, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glfwSwapInterval(1);

	m_isVisible = true;
	return true;
}

void Core::Window::SetTitle(const std::string& title) {
	m_title = title;
}

void Core::Window::Resize(int width, int height) {
	m_width = width;
	m_height = height;
}

void Core::Window::Show() {

}
void Core::Window::Hide() {

}

int Core::Window::GetWidth() const {  
    return m_width;  
}
int Core::Window::GetHeight() const {
	return m_height;
}
const std::string& Core::Window::GetTitle() const {
	return m_title;
}
bool Core::Window::IsVisible() const {
	return m_isVisible;
}

GLFWwindow* Core::Window::GetWindowHandle() const {
	return m_windowHandle;
}

void Core::Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Core::Window::SetInput(std::shared_ptr<Input> input) {
	m_input = input;
	if (m_windowHandle) {
		glfwSetWindowUserPointer(m_windowHandle, m_input.get());
		glfwSetKeyCallback(m_windowHandle, KeyCallback);
		glfwSetMouseButtonCallback(m_windowHandle, MouseButtonCallback);
		glfwSetCursorPosCallback(m_windowHandle, MousePositionCallback);
	}
}

void Core::Window::Shutdown() {
	if (m_windowHandle) {
		glfwDestroyWindow(m_windowHandle);
		m_windowHandle = nullptr;
	}
	glfwTerminate(); // NOTE: This will destroy all windows, I will leave this till I introduce multiple window
}

bool Core::Window::ShouldClose() const {
	return m_windowHandle && glfwWindowShouldClose(m_windowHandle);
}

void Core::Window::PollEvents() {
	glfwPollEvents();
}

void Core::Window::SwapBuffers() {
	if (m_windowHandle) {
		glfwSwapBuffers(m_windowHandle);
	}
}

void Core::Window::GetWindowSize(int& width, int& height) const {
	glfwGetWindowSize(m_windowHandle, &width, &height);
}