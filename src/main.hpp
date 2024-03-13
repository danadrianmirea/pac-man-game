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

bool run_game(Map &map, Key &key, PacMan &pacman, Cpu &cpu1, Cpu &cpu2, Cpu &cpu3, Cpu &cpu4);