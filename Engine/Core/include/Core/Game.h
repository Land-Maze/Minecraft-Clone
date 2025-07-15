#ifndef GAME_H
#define GAME_H
#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <memory>
#include <iostream>

#include <Core/GLADLoader.h>
#include <Core/Input.h>
#include <Core/Window.h>
#include <Core/Camera.h>
#include <Render/Renderer.h>

namespace Core {
	class Game
	{
	public:
		Game();
		~Game() = default;

		bool Initialize();
		void Run();
		void Shutdown();

	private:
		bool m_isRunning;
		std::unique_ptr<Core::Window> m_window;
		std::shared_ptr<Core::Input> m_input;
		std::unique_ptr<Render::Renderer> m_renderer;
		std::unique_ptr<Core::Camera> m_camera;
	};
};
#endif