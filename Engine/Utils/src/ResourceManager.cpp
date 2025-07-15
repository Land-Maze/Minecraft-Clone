#include <Utils/ResourceManager.h>

#include <stb/stb_image.h>

std::string Utils::ResourceManager::LoadShader(const std::string& path) {
    std::ifstream file(path);
    
    if (!file.is_open()) {
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    std::string source = buffer.str();
    if (source.empty()) {
        // FIXME: Put log here
    }
    else {
        // FIXME: Put log here
    }
    return source;
}

unsigned char* Utils::ResourceManager::LoadTexture(const std::string& path, int* width, int* height, int* channels) {
    unsigned char* data = stbi_load(path.c_str(), width, height, channels, 0);
    if (!data) {
        return nullptr;
    }
    return data;
}