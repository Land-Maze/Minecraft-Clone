#ifndef GLADLOADER_H
#define GLADLOADER_H
#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Core {
	class GLADLoader {
	public:
		static bool loadGLAD();
	};
}

#endif