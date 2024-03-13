#include "PacMan.hpp"

PacMan::PacMan(Color color)
{
	this->color = color;
}

void PacMan::setScore(int score)
{
	this->_score = score;
}

void PacMan::increaseScore(int value)
{
	this->_score += value;
}

int PacMan::getScore() const
{
	return _score;
}

void PacMan::draw()
{
	DrawCircle(x, y, radius, color);
}

void PacMan::updatePosition(const Map &map)
{
	Map& non_const_map = const_cast<Map&>(map);
	std::map<int, int>::iterator pacman_it = non_const_map.getPacmanPosition();

	this->x = pacman_it->first;
	this->y = pacman_it->second;
}

void PacMan::checkScore(Map &map)
{
	std::multimap<int, int>& targets = map.getTargets();
	std::multimap<int, int>::iterator it = targets.begin();
	Rectangle pacman = {this->x - BLOCK_SIZE / 2, this->y - BLOCK_SIZE / 2, BLOCK_SIZE, BLOCK_SIZE};

	for (; it != targets.end();)
	{
		if (CheckCollisionRecs(pacman, Rectangle{(float)it->first, (float)it->second, TARGETS_SIZE, TARGETS_SIZE}))
		{
			it = targets.erase(it);
			increaseScore(10);
		}
		else
			it++;
	}
}

void PacMan::update(const Map &map, Key &key)
{
	if (key.getCurrentKey() == KEY_UP)
	{
		if (!moveSecondaryKey(map, key, KEY_UP))
			movePrimaryKey(map, key, KEY_UP);
	}
	else if (key.getCurrentKey() == KEY_DOWN)
	{
		if (!moveSecondaryKey(map, key, KEY_DOWN))
			movePrimaryKey(map, key, KEY_DOWN);
	}
	else if (key.getCurrentKey() == KEY_LEFT)
	{
		if (!moveSecondaryKey(map, key, KEY_LEFT))
			movePrimaryKey(map, key, KEY_LEFT);
	}
	else if (key.getCurrentKey() == KEY_RIGHT)
	{
		if (!moveSecondaryKey(map, key, KEY_RIGHT))
			movePrimaryKey(map, key, KEY_RIGHT);
	}
}

bool PacMan::checkBorderCollision(const Map &map, float x, float y)
{
	auto borders = map.getBorders();
	std::multimap<int, int>::const_iterator it = borders.begin();
	Rectangle pacman = {x - BLOCK_SIZE / 2, y - BLOCK_SIZE / 2, BLOCK_SIZE, BLOCK_SIZE};

	for (; it != borders.end(); it++)
	{
		if (CheckCollisionRecs(pacman, map.getRec(it->first, it->second)))
			return true;
	}

	return false;
}

void PacMan::movePrimaryKey(const Map &map, Key &key, int key_pressed)
{
	if (key_pressed == KEY_UP)
	{
		if (!checkBorderCollision(map, x, y - speed))
			y -= speed;
		else
		{
			key.setCurrentKey(0);
			key.setQueueKey(0);
		}
	}
	else if (key_pressed == KEY_DOWN)
	{
		if (!checkBorderCollision(map, x, y + speed))
			y += speed;
		else
		{
			key.setCurrentKey(0);
			key.setQueueKey(0);
		}
	}
	else if (key_pressed == KEY_LEFT)
	{
		if (!checkBorderCollision(map, x - speed, y))
			x -= speed;
		else
		{
			key.setCurrentKey(0);
			key.setQueueKey(0);
		}
	}
	else if (key_pressed == KEY_RIGHT)
	{
		if (!checkBorderCollision(map, x + speed, y))
			x += speed;
		else
		{
			key.setCurrentKey(0);
			key.setQueueKey(0);
		}
	}
}

bool PacMan::moveSecondaryKey(const Map &map, Key &key, int primary_key)
{
	bool result = true;

	if (key.getQueueKey() == KEY_UP && key.getQueueKey() != primary_key)
	{
		if (!checkBorderCollision(map, x, y - speed))
		{
			y -= speed;
			key.setCurrentKey(KEY_UP);
			key.setQueueKey(0);
		}
		else
			movePrimaryKey(map, key, primary_key);
	}
	else if (key.getQueueKey() == KEY_DOWN && key.getQueueKey() != primary_key)
	{
		if (!checkBorderCollision(map, x, y + speed))
		{
			y += speed;
			key.setCurrentKey(KEY_DOWN);
			key.setQueueKey(0);
		}
		else
			movePrimaryKey(map, key, primary_key);
	}
	else if (key.getQueueKey() == KEY_RIGHT && key.getQueueKey() != primary_key)
	{
		if (!checkBorderCollision(map, x + speed, y))
		{
			x += speed;
			key.setCurrentKey(KEY_RIGHT);
			key.setQueueKey(0);
		}
		else
			movePrimaryKey(map, key, primary_key);
	}
	else if (key.getQueueKey() == KEY_LEFT && key.getQueueKey() != primary_key)
	{
		if (!checkBorderCollision(map, x - speed, y))
		{
			x -= speed;
			key.setCurrentKey(KEY_LEFT);
			key.setQueueKey(0);
		}
		else
			movePrimaryKey(map, key, primary_key);
	}
	else
		result = false;

	return result;
}