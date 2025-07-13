#ifndef GAME_H
#define GAME_H
#pragma once

#include <core/Window.h>

namespace Core {
class Game
{
	public:
		Game();
		~Game();

		bool Initialize();
		bool Run();
		bool Shutdown();

	private:
		bool m_isRunning;
		//Window m_window;
};
}
#endif