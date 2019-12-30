#include "Game.h"
#include <SFML/Graphics.hpp>  
#include <string>

/*
TODO:
-A way to get just the player entity
-Camera class
-Set sprite of the player based on state (This can change the collision box)
-Have a chain of player state classes with a pointer to state in the player system/controller
-Have a pointer to the level in World
-Way to get specific tile with (x, y)
-Find way to delete components of a deleted entity
*/

int main() {

	Game game;
	game.start();

	return 0;
}