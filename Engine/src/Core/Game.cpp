#include<Core/Game.h>
#include <iostream>

Core::Game::Game() : m_isRunning(false)
{}

Core::Game::~Game()
{}

bool Core::Game::Initialize() {
	std::cout << "Game initialized." << std::endl;
	return m_isRunning;
}