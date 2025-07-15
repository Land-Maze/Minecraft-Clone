#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H
#pragma once

#include <fstream>
#include <sstream>
#include <filesystem>
#include <string>

namespace Utils {
	class ResourceManager {
	public:
		static std::string LoadShader(const std::string& path);
		static unsigned char* LoadTexture(const std::string& path, int* width, int* height, int* channels);
	};
};
#endif