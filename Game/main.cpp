#include <iostream>
#include <Core/Game.h>

int main(int argc, char* argv[]) {
	Core::Game game;

	if (game.Initialize() == false) {
		return -1;
	}
	
	game.Run();
	
	return 0;
}