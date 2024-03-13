#include "Cpu.hpp"

void Cpu::draw()
{
	DrawCircle(x, y, radius, color);
	DrawRectangle(x - radius, y, radius * 2, radius, color);
	DrawEllipse(x - 4, y - 2, 3, 4, WHITE);
	DrawEllipse(x + 4, y - 2, 3, 4, WHITE);
	DrawCircle(x - 4, y - eyes, 1.75, BLACK);
	DrawCircle(x + 4, y - eyes, 1.75, BLACK);
}

void Cpu::updatePosition(const Map &map)
{
	Map& non_const_map = const_cast<Map&>(map);
	std::multimap<int, int>::const_iterator cpu_it = non_const_map.getCpuPosition();

	this->x = cpu_it->first;
	this->y = cpu_it->second;
}

void Cpu::update(const Map &map, int pacman_x, int pacman_y)
{
	if (y > pacman_y && !checkBorderCollision(map, x, y - speed))
		this->y -= speed;
	else if (y < pacman_y && !checkBorderCollision(map, x, y + speed))
		this->y += speed;
	else if (x > pacman_x && !checkBorderCollision(map, x - speed, y))
		this->x -= speed;
	else if (x < pacman_x && !checkBorderCollision(map, x + speed, y))
		this->x += speed;
}

void Cpu::random(const Map &map, int pacman_x, int pacman_y)
{
	if (y > pacman_y && !checkBorderCollision(map, x, y - speed))
		this->y -= speed;
	else if (y < pacman_y && !checkBorderCollision(map, x, y + speed))
		this->y += speed;
	else if (x > pacman_x && !checkBorderCollision(map, x - speed, y))
		this->x -= speed;
	else if (x < pacman_x && !checkBorderCollision(map, x + speed, y))
		this->x += speed;
}