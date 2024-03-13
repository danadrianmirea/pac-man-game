#include "main.hpp"

bool run_game(Map &map, Key &key, PacMan &pacman, Cpu &cpu1, Cpu &cpu2, Cpu &cpu3, Cpu &cpu4)
{
	ClearBackground(BLACK);
	map.draw();
	key.update();

	pacman.update(map, key);
	cpu1.update(map, pacman.x, pacman.y);
	cpu2.update(map, pacman.x, pacman.y);
	cpu3.update(map, pacman.x, pacman.y);
	cpu4.update(map, pacman.x, pacman.y);

	pacman.checkScore(map);
	
	pacman.draw();
	cpu1.draw();
	cpu2.draw();
	cpu3.draw();
	cpu4.draw();

	DrawText(TextFormat("SCORE %i", pacman.getScore()), 24, 24, 20, WHITE);

	if (map.getTargets().size() == 0)
		return false;
	
	return true;
}