#pragma once

#include "../../lib/lib.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>

class Map
{
private:
	Map();
	std::vector<std::string> _map;
	std::multimap<int, int> _borders;
	std::multimap<int, int> _targets;
	float _x = MAP_X_START;
	float _y = MAP_Y_START;

public:

	Map(std::string map_path);

	std::vector<std::string> getMap() const;
	std::multimap<int, int> getBorders() const;
	std::multimap<int, int> getTargets() const;
	Rectangle getRec(float x, float y) const;
	void draw();
};