#pragma once

#include "../../lib/lib.hpp"
#include "PacMan.hpp"
#include <iostream>

class Cpu : public PacMan
{
public:
	float eyes_position[3] = {0, 2, 4};
	float eyes = eyes_position[GetRandomValue(0, 2)];

	using PacMan::PacMan;

	void draw();
};