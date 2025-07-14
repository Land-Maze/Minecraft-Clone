#ifndef GAME_H
#define GAME_H
#pragma once

#include <core/Window.h>
#include <memory>
#include <glad/glad.h>
#include <GLFW/glfw3.h>  
#include <iostream>

namespace Core {
class Game
{
	public:
		Game();
		~Game();

		bool Initialize();
		void Run();
		void Shutdown();

	private:
		bool m_isRunning;
		std::unique_ptr<Window> m_window;
};
}
#endif