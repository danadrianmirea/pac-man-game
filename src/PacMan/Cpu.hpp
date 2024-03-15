#pragma once

#include "../../lib/lib.hpp"
#include "../Map/Map.hpp"
#include "PacMan.hpp"
#include <iostream>

class Cpu : public PacMan
{
public:
	Timer cpu_timer;
	int timer;
	float speed = CPU_SPEED;
	int directions[5] = {KEY_UP, KEY_UP, KEY_UP, KEY_LEFT, KEY_RIGHT};
	int current_direction = KEY_UP;
	std::multimap<int, int>::iterator cpu_position;

	Cpu();
	Cpu(Color color, int timer);

	void draw();
	void updateStartPosition(Map &map);
	void random(const Map &map);
	int *testOtherDirections(const Map &map);
	void moveInCurrentDirection(const Map &map);
	void moveNewDirection(const Map &map, int *options);
	int howManyOptions(const Map &map);
	void oppositeDirection();
	void checkCollisionPacmanCpu(Map &map, PacMan &pacman);
	void startTimer();
	void setTimer(int timer);
	void setDefaultPosition(Map &map);
};