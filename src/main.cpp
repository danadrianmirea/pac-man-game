#include "main.hpp"

const int screenWidth = 552;
const int screenHeight = 552;

int main(void)
{
	InitWindow(screenWidth, screenHeight, "Pac-Man Game");
	SetTargetFPS(60);

	PacMan pacman(YELLOW);
	Cpu cpu1(RED);
	Cpu cpu2(BLUE);
	Cpu cpu3(PINK);
	Cpu cpu4(ORANGE);

	Key key;
	Map map("/Users/mariohenriques/Documents/42/personal_projects/pac-man-game/maps/map.txt");

	pacman.updatePosition(map);
	cpu1.updatePosition(map);
	cpu2.updatePosition(map);
	cpu3.updatePosition(map);
	cpu4.updatePosition(map);

	while (!WindowShouldClose())
	{
		BeginDrawing();

		run_game(map, key, pacman, cpu1, cpu2, cpu3, cpu4);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}