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
	std::map<int, int>::iterator pacman_position;

	PacMan();
	PacMan(Color color);

	void setScore(int score);
	void increaseScore(int value);
	int getScore() const;
	void setDefaultPosition(Map &map);

	void draw();
	void updateStartPosition(Map &map);
	void checkScore(Map& map);
	void update(const Map &map, Key &key);
	bool checkBorderCollision(const Map &map, float dx, float dy);
	void movePrimaryKey(const Map &map, Key &key);
	bool moveSecondaryKey(const Map &map, Key &key);
};