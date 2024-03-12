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
			_map.push_back(line);
			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == '1')
					_borders.insert(std::pair<int, int>(x, y));
				else if (line[i] == '0')
					_targets.insert(std::pair<int, int>(x + BLOCK_SIZE / 2, y + BLOCK_SIZE / 2));

				x += BLOCK_SIZE;
			}

			y += BLOCK_SIZE;
			x = MAP_X_START;
		}

		file.close();
	}
}

std::vector<std::string> Map::getMap() const
{
	return _map;
}

std::multimap<int, int> Map::getBorders() const
{
	return _borders;
}

std::multimap<int, int> Map::getTargets() const
{
	return _targets;
}

Rectangle Map::getRec(float x, float y) const
{
	return Rectangle{x, y, BLOCK_SIZE, BLOCK_SIZE};
}

void Map::draw()
{
	std::multimap<int, int>::iterator borders_it;
	std::multimap<int, int>::iterator targets_it;


	for (borders_it = _borders.begin(); borders_it != _borders.end(); borders_it++)
		DrawRectangle(borders_it->first, borders_it->second, BLOCK_SIZE, BLOCK_SIZE, DARKBLUE);

	 for (targets_it = _targets.begin(); targets_it != _targets.end(); targets_it++)
		DrawCircle(targets_it->first, targets_it->second, TARGET_SIZE, WHITE);
}
