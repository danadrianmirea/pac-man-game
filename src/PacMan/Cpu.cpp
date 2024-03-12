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