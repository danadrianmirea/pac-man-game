#pragma once

#include "../../lib/lib.hpp"
#include "../Map/Map.hpp"
#include "../Key/Key.hpp"
#include <iostream>
#include <map>

class PacMan
{
private:
	PacMan();
	int _target_points = 0;

public:
	float x;
	float y;
	float radius = PACMAN_SIZE;
	int speed = PACMAN_SPEED;
	Color color;

	PacMan(float x, float y, int speed, Color color);

	void setTargetPoints(int target);
	int getTargetPoints() const;
	void draw();
	void update(const Map &map, Key &key);
	bool checkBorderCollision(const Map &map, float x, float y) const;
};