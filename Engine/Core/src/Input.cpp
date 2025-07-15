#include <core/Input.h>

Core::Input::Input() {
    m_keys.fill(false);
    m_mouseButtons.fill(false);
    m_mousePos = glm::vec2(0.0f);
    m_lastMousePos = glm::vec2(0.0f);
}

bool Core::Input::IsKeyPressed(int key) const {
    if (key < 0 || key > GLFW_KEY_LAST) return false;
    return m_keys[key];
}

bool Core::Input::IsMouseButtonPressed(int button) const {
    if (button < 0 || button > GLFW_MOUSE_BUTTON_LAST) return false;
    return m_mouseButtons[button];
}

glm::vec2 Core::Input::GetMousePosition() const {
    return m_mousePos;
}

glm::vec2 Core::Input::GetMouseDelta() const {
    return m_mousePos - m_lastMousePos;
}

void Core::Input::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key < 0 || key > GLFW_KEY_LAST) return;

    if (action == GLFW_PRESS) {
        m_keys[key] = true;
    }

    else if (action == GLFW_RELEASE) {
        m_keys[key] = false;
    }
}

void Core::Input::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if (button < 0 || button > GLFW_MOUSE_BUTTON_LAST) return;
    if (action == GLFW_PRESS) {
        m_mouseButtons[button] = true;
    }
    else if (action == GLFW_RELEASE) {
        m_mouseButtons[button] = false;
    }
}

void Core::Input::MousePositionCallback(GLFWwindow* window, double xpos, double ypos) {
    m_lastMousePos = m_mousePos;
    m_mousePos = glm::vec2(static_cast<float>(xpos), static_cast<float>(ypos));
}