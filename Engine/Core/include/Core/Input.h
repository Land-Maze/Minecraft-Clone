#ifndef INPUT_H
#define INPUT_H
#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <array>
#include <glm/glm.hpp>

namespace Core {
    class Input {
    public:
        Input();
        ~Input() = default;

        bool IsKeyPressed(int key) const;
        bool IsMouseButtonPressed(int button) const;
        glm::vec2 GetMousePosition() const;
        glm::vec2 GetMouseDelta() const;

        void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
        void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
        void MousePositionCallback(GLFWwindow* window, double xpos, double ypos);

        void Input::Update();
    private:
        std::array<bool, GLFW_KEY_LAST + 1> m_keys;
        std::array<bool, GLFW_MOUSE_BUTTON_LAST + 1> m_mouseButtons;
        glm::vec2 m_mousePos;
        glm::vec2 m_lastMousePos;
        glm::vec2 m_mouseDelta;
    };
};

#endif