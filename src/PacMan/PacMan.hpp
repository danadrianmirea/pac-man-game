#pragma once

#include "../../lib/lib.hpp"
#include "../Map/Map.hpp"
#include "../Key/Key.hpp"
#include <iostream>
#include <map>

class Map;

class PacMan
{
private:
	int _score = 0;

public:
	float x;
	float y;
	float radius = OBJ_SIZE;
	int speed = PACMAN_SPEED;
	Color color;

	PacMan(Color color);

	void setScore(int score);
	void increaseScore(int value);
	int getScore() const;

	void draw();
	void updatePosition(const Map &map);
	void checkScore(Map& map);
	void update(const Map &map, Key &key);
	bool checkBorderCollision(const Map &map, float x, float y);
	void movePrimaryKey(const Map &map, Key &key, int key_pressed);
	bool moveSecondaryKey(const Map &map, Key &key, int primary_key);
};