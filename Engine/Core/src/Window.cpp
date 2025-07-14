#include <Core/Window.h>
#include <GLFW/glfw3.h>

#include <iostream>

Core::Window::Window() : m_width(800), m_height(600), m_title("Default Window"), m_visible(false), m_windowHandle(nullptr) {
	std::cout << "[Core::Window] Window instance created." << std::endl;
}

Core::Window::~Window() {
	if (m_windowHandle) {
		glfwDestroyWindow(m_windowHandle);
	}
}

bool Core::Window::Initialize() {
	glfwInit();

	m_windowHandle = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
	if (m_windowHandle == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}

	std::cout << "[Core::Window] Window initialized successfully." << std::endl;
	m_visible = true;
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
	return m_visible;
}

GLFWwindow* Core::Window::GetWindowHandle() const {
	return m_windowHandle;
}

void Core::Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}