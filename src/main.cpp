#include "main.hpp"

const int screenWidth = 552;
const int screenHeight = 552;

int main(void)
{
	InitWindow(screenWidth, screenHeight, "Pac-Man Game");
	InitAudioDevice();
	SetTargetFPS(60);

	PacMan pacman(YELLOW);
	Cpu cpu1(BLUE, 2);
	Cpu cpu2(RED, 0);
	Cpu cpu3(PINK, 4);
	Cpu cpu4(ORANGE, 6);

	Key key;
	Map map("./maps/map.txt");

	SetDefaultPositions(map, pacman, cpu1, cpu2, cpu3, cpu4);
	UpdatePlayerPositions(map, key, pacman, cpu1, cpu2, cpu3, cpu4);
	StartTimer(map.map_init_timer, 5);
	PlaySound(map.intro);

	while (!WindowShouldClose())
	{
		BeginDrawing();

		if (RunGame(map, key, pacman, cpu1, cpu2, cpu3, cpu4) == -1)
			break ;

		EndDrawing();
	}

	CloseAudioDevice();
	CloseWindow();
	
	return 0;
}