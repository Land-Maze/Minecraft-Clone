#ifndef MESH_H
#define MESH_H
#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <vector>

struct Vertex {
    glm::vec3 position;
    glm::vec2 texCoord;
};

namespace Render {
    class Mesh {
    public:
        Mesh(const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices);
        ~Mesh();

        void Draw() const;

    private:
        GLuint m_vao = 0, m_vbo = 0, m_ebo = 0;
        GLsizei m_indexCount = 0;
    };
};
#endif