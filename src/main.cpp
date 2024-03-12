#include "main.hpp"

const int screenWidth = 625;
const int screenHeight = 625;

int main(void)
{
	InitWindow(screenWidth, screenHeight, "Pac-Man Game");
	SetTargetFPS(60);

	Map map("/Users/mariohenriques/Documents/42/personal_projects/pac-man-game/maps/level1.pacman");
	Key key;
	PacMan pacman(screenWidth / 2, screenHeight / 2 - 50, PACMAN_SPEED, YELLOW);
	Cpu cpu1(screenWidth / 2 - 50, screenHeight / 2, CPU_SPEED, RED);
	Cpu cpu2(screenWidth / 2, screenHeight / 2, CPU_SPEED, BLUE);
	Cpu cpu3(screenWidth / 2 + 50, screenHeight / 2, CPU_SPEED, ORANGE);

	while (!WindowShouldClose())
	{
		BeginDrawing();

		run_game(map, key, pacman, cpu1, cpu2, cpu3);
		
		EndDrawing();
	}

	CloseWindow();
	return 0;
}