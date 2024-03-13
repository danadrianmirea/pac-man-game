#include "Map.hpp"

Map::Map(std::string map_path)
{
	std::fstream file;
	std::string line;
	float x = _x;
	float y = _y;

	file.open(map_path);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == '1')
					_borders.insert(std::pair<int, int>(x, y));
				else if (line[i] == '0')
					_targets.insert(std::pair<int, int>(x + BLOCK_SIZE / 2 - TARGETS_SIZE / 2, y + BLOCK_SIZE / 2 - TARGETS_SIZE / 2));
				else if (line[i] == 'C')
					_cpu_pos.insert(std::pair<int, int>(x + BLOCK_SIZE / 2, y + BLOCK_SIZE / 2));
				else if (line[i] == 'P')
					_pacman_pos[x + BLOCK_SIZE / 2] =  y + BLOCK_SIZE / 2;

				x += BLOCK_SIZE;
			}

			y += BLOCK_SIZE;
			x = MAP_X_START;
		}

		file.close();
	}

	setCpuPositionIterator(_cpu_pos.begin());
	setPacmanPositionIterator(_pacman_pos.begin());
}

std::multimap<int, int> Map::getBorders() const
{
	return _borders;
}

std::multimap<int, int>& Map::getTargets()
{
	return _targets;
}

std::map<int, int>::iterator Map::getPacmanPosition()
{
	if (_pacman_pos_it != _pacman_pos.end())
        return _pacman_pos_it++;
	else
	{
		_pacman_pos_it = _pacman_pos.begin();
		return _pacman_pos_it++;
	}
}

std::multimap<int, int>::iterator Map::getCpuPosition()
{
	if (_cpu_pos_it != _cpu_pos.end())
        return _cpu_pos_it++;
	else
	{
		_cpu_pos_it = _cpu_pos.begin();
		return _cpu_pos_it++;
	}
}

Rectangle Map::getRec(float x, float y) const
{
	return Rectangle{x, y, BLOCK_SIZE, BLOCK_SIZE};
}

void Map::setPacmanPositionIterator(std::map<int, int>::iterator pacman_it)
{
	this->_pacman_pos_it = pacman_it;
}

void Map::setCpuPositionIterator(std::multimap<int, int>::iterator cpu_it)
{
	this->_cpu_pos_it = cpu_it;
}

void Map::draw()
{
	std::multimap<int, int>::iterator borders_it;
	std::multimap<int, int>::iterator targets_it;

	for (borders_it = _borders.begin(); borders_it != _borders.end(); borders_it++)
		DrawRectangle(borders_it->first, borders_it->second, BLOCK_SIZE, BLOCK_SIZE, DARKBLUE);

	for (targets_it = _targets.begin(); targets_it != _targets.end(); targets_it++)
		DrawRectangle(targets_it->first, targets_it->second, TARGETS_SIZE, TARGETS_SIZE, WHITE);
}