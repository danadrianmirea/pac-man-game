#pragma once

#include "raylib.hpp"
#include "raymath.hpp"
#include "rlgl.hpp"
#include <stdio.h>

typedef struct Timer {
    double startTime;   // Start time (seconds)
    double lifeTime;    // Lifetime (seconds)
} Timer;

#define HERE printf("I am here!\n")
#define HERE2 printf("I am here to!\n")

#define OBJ_SIZE		10
#define PACMAN_SPEED	2
#define CPU_SPEED		2
#define BLOCK_SIZE		24
#define MAP_X_START		0.0f
#define MAP_Y_START		72.0f
#define TARGETS_SIZE	3

void StartTimer(Timer &timer, double lifetime);
bool TimerDone(Timer timer);
double GetElapsed(Timer timer);