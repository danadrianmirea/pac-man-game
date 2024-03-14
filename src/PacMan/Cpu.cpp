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
	Map &non_const_map = const_cast<Map &>(map);
	std::multimap<int, int>::const_iterator cpu_it = non_const_map.getCpuPosition();

	this->x = cpu_it->first;
	this->y = cpu_it->second;
}

void Cpu::update(const Map &map, int pacman_x, int pacman_y)
{
	if (y > pacman_y && !checkBorderCollision(map, 0, -speed))
		this->y -= speed;
	else if (y < pacman_y && !checkBorderCollision(map, 0, speed))
		this->y += speed;
	else if (x > pacman_x && !checkBorderCollision(map, -speed, 0))
		this->x -= speed;
	else if (x < pacman_x && !checkBorderCollision(map, speed, 0))
		this->x += speed;
}

void Cpu::random(const Map &map)
{
	int *options = testOtherDirections(map);

	if (options != NULL)
	{
		moveNewDirection(map, options);
		delete[] options;
	}
	else
		moveInCurrentDirection(map);
}

int *Cpu::testOtherDirections(const Map &map)
{
	int options = howManyOptions(map);

	if (!options)
		return NULL;

	int *options_array = new int[options];
	int i = 0;

	if (current_direction != KEY_DOWN && !checkBorderCollision(map, 0, -speed))
		options_array[i++] = KEY_UP;
	if (current_direction != KEY_UP && !checkBorderCollision(map, 0, speed))
		options_array[i++] = KEY_DOWN;
	if (current_direction != KEY_RIGHT && !checkBorderCollision(map, -speed, 0))
		options_array[i++] = KEY_LEFT;
	if (current_direction != KEY_LEFT && !checkBorderCollision(map, speed, 0))
		options_array[i++] = KEY_RIGHT;

	return options_array;
}

int Cpu::howManyOptions(const Map &map)
{
	int counter = 0;

	if (current_direction != KEY_DOWN && !checkBorderCollision(map, 0, -speed))
		counter++;
	if (current_direction != KEY_UP && !checkBorderCollision(map, 0, speed))
		counter++;
	if (current_direction != KEY_RIGHT && !checkBorderCollision(map, -speed, 0))
		counter++;
	if (current_direction != KEY_LEFT && !checkBorderCollision(map, speed, 0))
		counter++;

	return counter;
}

void Cpu::moveInCurrentDirection(const Map &map)
{
	int dx = 0;
	int dy = 0;

	switch (current_direction)
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
		x -= dx;
		y -= dy;
		oppositeDirection();
	}
}

void Cpu::moveNewDirection(const Map &map, int *options)
{
	int new_direction = options[GetRandomValue(0, howManyOptions(map) - 1)];

	current_direction = new_direction;
	moveInCurrentDirection(map);
}

void Cpu::oppositeDirection()
{
	if (current_direction == KEY_UP)
		current_direction = KEY_DOWN;
	else if (current_direction == KEY_DOWN)
		current_direction = KEY_UP;
	else if (current_direction == KEY_LEFT)
		current_direction = KEY_RIGHT;
	else if (current_direction == KEY_RIGHT)
		current_direction = KEY_LEFT;
}