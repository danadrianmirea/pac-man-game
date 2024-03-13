#pragma once

#include "../../lib/lib.hpp"
#include "../Map/Map.hpp"
#include "PacMan.hpp"
#include <iostream>

class Cpu : public PacMan
{
public:
	float speed = CPU_SPEED;
	float eyes_position[3] = {0, 2, 4};
	float eyes = eyes_position[GetRandomValue(0, 2)];

	using PacMan::PacMan;

	void draw();
	void updatePosition(const Map &map);
	void update(const Map &map, int pacman_x, int pacman_y);
	void chase(const Map &map, int pacman_x, int pacman_y);
	void random(const Map &map, int pacman_x, int pacman_y);
};