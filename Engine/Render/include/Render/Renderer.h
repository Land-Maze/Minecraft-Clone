#ifndef RENDERER_H
#define RENDERER_H
#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <Render/Shader.h>
#include <Render/Texture.h>
#include <Render/Mesh.h>

#include <glm/glm.hpp>

#include <memory>

namespace Render {
    class Renderer {
    public:
        Renderer();
        ~Renderer();

        bool Initialize();
        void Render(const glm::mat4& viewProjMatrix);
        void Shutdown();

    private:
        std::unique_ptr<Shader> m_blockShader;
        std::unique_ptr<Texture> m_blockTexture;
        std::unique_ptr<Mesh> m_blockMesh;
    };
};
#endif