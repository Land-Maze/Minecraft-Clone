#ifndef SHADER_H
#define SHADER_H
#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <string>
#include <glm/gtc/type_ptr.hpp>

#include <Utils/ResourceManager.h>

namespace Render {
    class Shader {
    public:
        Shader(const std::string& vertexPath, const std::string& fragmentPath);
        ~Shader();

        void Bind() const;
        void Unbind() const;

        void SetMat4(const std::string& name, const glm::mat4& matrix) const;
        void SetInt(const std::string& name, int value) const;

    private:
        GLuint m_programID = 0;

        GLuint CompileShader(GLenum type, const std::string& source);
    };
};
#endif