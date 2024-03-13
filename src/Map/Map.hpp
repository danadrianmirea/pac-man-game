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
	std::multimap<int, int> _lifes;
	std::multimap<int, int> _borders;
	std::multimap<int, int> _targets;
	std::multimap<int, int> _cpu_pos;
	std::map<int, int> _pacman_pos;
	std::multimap<int, int>::iterator _cpu_pos_it;
	std::map<int, int>::iterator _pacman_pos_it;
	float _x = MAP_X_START;
	float _y = MAP_Y_START;
	int lifes = 3;

public:
	Map(std::string map_path);

	std::multimap<int, int> getBorders() const;
	std::multimap<int, int>& getTargets();
	std::map<int, int>::iterator getPacmanPosition();
	std::multimap<int, int>::iterator getCpuPosition();
	void setPacmanPositionIterator(std::map<int, int>::iterator pacman_it);
	void setCpuPositionIterator(std::multimap<int, int>::iterator cpu_it);
	Rectangle getRec(float x, float y) const;
	void draw();
};