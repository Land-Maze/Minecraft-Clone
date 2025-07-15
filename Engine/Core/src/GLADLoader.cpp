#include <Core/GLADLoader.h>

bool Core::GLADLoader::loadGLAD() {
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		return false;
	else
		return true;
};