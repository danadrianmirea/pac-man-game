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
	Map &non_const_map = const_cast<Map &>(map);
	std::map<int, int>::iterator pacman_it = non_const_map.getPacmanPosition();

	this->x = pacman_it->first;
	this->y = pacman_it->second;
}

void PacMan::checkScore(Map &map)
{
	std::multimap<int, int> &targets = map.getTargets();
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
	if (!moveSecondaryKey(map, key))
		movePrimaryKey(map, key);
}

bool PacMan::checkBorderCollision(const Map &map, float dx, float dy)
{
	auto borders = map.getBorders();
	std::multimap<int, int>::const_iterator it = borders.begin();
	Rectangle pacman = {x + dx - BLOCK_SIZE / 2, y + dy - BLOCK_SIZE / 2, BLOCK_SIZE, BLOCK_SIZE};

	for (; it != borders.end(); it++)
	{
		if (CheckCollisionRecs(pacman, map.getRec(it->first, it->second)))
			return true;
	}

	return false;
}

void PacMan::movePrimaryKey(const Map &map, Key &key)
{
	float dx = 0;
	float dy = 0;

	switch (key.getCurrentKey())
	{
		case KEY_UP:
			dy = -speed;
			break;
		case KEY_DOWN:
			dy = speed;
			break;
		case KEY_LEFT:
			dx = -speed;
			break;
		case KEY_RIGHT:
			dx = speed;
			break;
	}

	if (!checkBorderCollision(map, dx, dy))
	{
		x += dx;
		y += dy;
	}
	else
	{
		key.setCurrentKey(0);
		key.setQueueKey(0);
	}
}

bool PacMan::moveSecondaryKey(const Map &map, Key &key)
{
	if (key.getQueueKey() == key.getCurrentKey() || key.getQueueKey() == 0)
		return false;

	float dx = 0;
	float dy = 0;

	switch (key.getQueueKey())
	{
		case KEY_UP:
			dy = -speed;
			break;
		case KEY_DOWN:
			dy = speed;
			break;
		case KEY_LEFT:
			dx = -speed;
			break;
		case KEY_RIGHT:
			dx = speed;
			break;
	}

	if (!checkBorderCollision(map, dx, dy))
	{
		x += dx;
		y += dy;
		key.setCurrentKey(key.getQueueKey());
		key.setQueueKey(0);
		return true;
	}

	return false;
}