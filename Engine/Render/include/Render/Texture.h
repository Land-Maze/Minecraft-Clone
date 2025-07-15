#ifndef TEXTURE_H  
#define TEXTURE_H  
#pragma once  
  
#include <glad/glad.h>  
#include <GLFW/glfw3.h>  
  
#include <glm/glm.hpp>  
#include <string>  
  
#include <Utils/ResourceManager.h>  
  
namespace Render {  
    class Texture {  
    public:  
        Texture(const std::string& path);  
        ~Texture();  
  
        void Bind(GLuint slot = 0) const;  
        void Unbind() const;  
  
    private:  
        GLuint m_textureID = 0;  
    };  
};  
#endif