#include "main.hpp"

const int screenWidth = 552;
const int screenHeight = 552;

int main(void)
{
	InitWindow(screenWidth, screenHeight, "Pac-Man Game");
	SetTargetFPS(60);

	PacMan pacman(YELLOW);
	Cpu cpu1(BLUE, 3);
	Cpu cpu2(RED, 0);
	Cpu cpu3(PINK, 7);
	Cpu cpu4(ORANGE, 10);

	Key key;
	Map map("/Users/mariohenriques/Documents/42/personal_projects/pac-man-game/maps/map.txt");

	SetDefaultPositions(map, pacman, cpu1, cpu2, cpu3, cpu4);
	UpdatePlayerPositions(map, pacman, cpu1, cpu2, cpu3, cpu4);
	StartTimer(map.map_init_timer, 5);

	while (!WindowShouldClose())
	{
		BeginDrawing();

		if (RunGame(map, key, pacman, cpu1, cpu2, cpu3, cpu4) == -1)
			break ;

		EndDrawing();
	}

	CloseWindow();
	return 0;
}