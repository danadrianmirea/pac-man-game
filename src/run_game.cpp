#include "main.hpp"

void run_game(Map &map, Key &key, PacMan &pacman, Cpu &cpu1, Cpu &cpu2, Cpu &cpu3)
{
	ClearBackground(BLACK);
	key.update();
	map.draw();
	
	pacman.update(map, key);
	//cpu1.update();
	//cpu2.update();
	//cpu3.update();

	pacman.draw();
	//cpu1.draw();
	//cpu2.draw();
	//cpu3.draw();
}