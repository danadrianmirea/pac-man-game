#include "PacMan.hpp"

PacMan::PacMan(float x, float y, int speed, Color color)
{
	this->x = x;
	this->y = y;
	this->speed = speed;
	this->color = color;
}

void PacMan::setTargetPoints(int target)
{
	this->_target_points = target;
}

int PacMan::getTargetPoints() const
{
	return _target_points;
}

void PacMan::draw()
{
	DrawCircle(x, y, radius, color);
}

void PacMan::update(const Map &map, Key &key)
{
	std::cout << "key: " << key.getCurrentKey() << std::endl;
	std::cout << "last key: " << key.getQueueKey() << std::endl;

	if (key.getCurrentKey() == KEY_UP)
	{
		if (key.getQueueKey() == KEY_DOWN)
		{
			if (!checkBorderCollision(map, x, y + speed))
				y += speed;
		}
		else if (key.getQueueKey() == KEY_LEFT)
		{
			if (!checkBorderCollision(map, x - speed, y))
				x -= speed;
		}
		else if (key.getQueueKey() == KEY_RIGHT)
		{
			if (!checkBorderCollision(map, x + speed, y))
				x += speed;
		}
		else
		{
			if (!checkBorderCollision(map, x, y - speed))
				y -= speed;
			else
			{
				key.setCurrentKey(0);
				key.setQueueKey(0);
			}
		}
	}
	else if (key.getCurrentKey() == KEY_DOWN)
	{
		if (key.getQueueKey() == KEY_UP)
		{
			if (!checkBorderCollision(map, x, y - speed))
				y -= speed;
		}
		else if (key.getQueueKey() == KEY_LEFT)
		{
			if (!checkBorderCollision(map, x - speed, y))
				x -= speed;
		}
		else if (key.getQueueKey() == KEY_RIGHT)
		{
			if (!checkBorderCollision(map, x + speed, y))
				x += speed;
		}
		else
		{
			if (!checkBorderCollision(map, x, y + speed))
				y += speed;
			else
			{
				key.setCurrentKey(0);
				key.setQueueKey(0);
			}
		}
	}
	else if (key.getCurrentKey() == KEY_LEFT)
	{
		if (key.getQueueKey() == KEY_UP)
		{
			if (!checkBorderCollision(map, x, y - speed))
				y -= speed;
		}
		else if (key.getQueueKey() == KEY_DOWN)
		{
			if (!checkBorderCollision(map, x, y + speed))
				y += speed;
		}
		else if (key.getQueueKey() == KEY_RIGHT)
		{
			if (!checkBorderCollision(map, x + speed, y))
				x += speed;
		}
		else
		{
			if (!checkBorderCollision(map, x - speed, y))
				x -= speed;
			else
			{
				key.setCurrentKey(0);
				key.setQueueKey(0);
			}
		}
	}
	else if (key.getCurrentKey() == KEY_RIGHT)
	{
		if (key.getQueueKey() == KEY_UP)
		{
			if (!checkBorderCollision(map, x, y - speed))
				y -= speed;
		}
		else if (key.getQueueKey() == KEY_DOWN)
		{
			if (!checkBorderCollision(map, x, y + speed))
				y += speed;
		}
		else if (key.getQueueKey() == KEY_LEFT)
		{
			if (!checkBorderCollision(map, x - speed, y))
				x -= speed;
		}
		else
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
}

bool PacMan::checkBorderCollision(const Map &map, float x, float y) const
{
	std::multimap<int, int> borders = map.getBorders();
	std::multimap<int, int>::iterator it = borders.begin();

	for (; it != borders.end(); it++)
	{
		if (CheckCollisionCircleRec(Vector2{x, y}, radius, map.getRec(it->first, it->second)))
			return true;
	}

	return false;
}