#pragma once

#include <iostream>
#include <unistd.h>
#include <fstream>
#include <vector>
#include <map>

#include "../lib/lib.hpp"
#include "./PacMan/PacMan.hpp"
#include "./PacMan/Cpu.hpp"
#include "./Map/Map.hpp"
#include "./Key/Key.hpp"

int RunGame(Map &map, Key &key, PacMan &pacman, Cpu &cpu1, Cpu &cpu2, Cpu &cpu3, Cpu &cpu4);
int GameStatus(Map &map, const Key &key, PacMan &pacman, Cpu &cpu1, Cpu &cpu2, Cpu &cpu3, Cpu &cpu4);
void UpdatePlayerPositions(Map &map, const Key &key, PacMan &pacman, Cpu &cpu1, Cpu &cpu2, Cpu &cpu3, Cpu &cpu4);
void StartCpuTimers(Cpu &cpu1, Cpu &cpu2, Cpu &cpu3, Cpu &cpu4);
void DrawPlayers(PacMan &pacman, const Key &key, Cpu &cpu1, Cpu &cpu2, Cpu &cpu3, Cpu &cpu4);
void SetDefaultPositions(Map &map, PacMan &pacman, Cpu &cpu1, Cpu &cpu2, Cpu &cpu3, Cpu &cpu4);

