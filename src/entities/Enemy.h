#ifndef ENEMY_H
#define ENEMY_H

#define MAX_ENEMIES 1

#include "../components/Entity.h"

extern Entity enemies[MAX_ENEMIES];
extern int worldUpscale;
extern int upscale16x16;

void InitEnemy();
void UpdateEnemy();
void DrawEnemy();

#endif