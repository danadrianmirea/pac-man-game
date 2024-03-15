#include "main.hpp"

void SetDefaultPositions(Map &map, PacMan &pacman, Cpu &cpu1, Cpu &cpu2, Cpu &cpu3, Cpu &cpu4)
{
	pacman.setDefaultPosition(map);
	cpu1.setDefaultPosition(map);
	cpu2.setDefaultPosition(map);
	cpu3.setDefaultPosition(map);
	cpu4.setDefaultPosition(map);
}

void UpdatePlayerPositions(Map &map, PacMan &pacman, Cpu &cpu1, Cpu &cpu2, Cpu &cpu3, Cpu &cpu4)
{
	pacman.updateStartPosition(map);
	cpu1.updateStartPosition(map);
	cpu2.updateStartPosition(map);
	cpu3.updateStartPosition(map);
	cpu4.updateStartPosition(map);
	DrawPlayers(pacman, cpu1, cpu2, cpu3, cpu4);
}

void StartCpuTimers(Cpu &cpu1, Cpu &cpu2, Cpu &cpu3, Cpu &cpu4)
{
	cpu1.startTimer();
	cpu2.startTimer();
	cpu3.startTimer();
	cpu4.startTimer();
}

void DrawPlayers(PacMan &pacman, Cpu &cpu1, Cpu &cpu2, Cpu &cpu3, Cpu &cpu4)
{
	pacman.draw();
	cpu1.draw();
	cpu2.draw();
	cpu3.draw();
	cpu4.draw();
}

void CheckCoallision(Map &map, PacMan &pacman, Cpu &cpu1, Cpu &cpu2, Cpu &cpu3, Cpu &cpu4)
{
	cpu1.checkCollisionPacmanCpu(map, pacman);
	cpu2.checkCollisionPacmanCpu(map, pacman);
	cpu3.checkCollisionPacmanCpu(map, pacman);
	cpu4.checkCollisionPacmanCpu(map, pacman);
}