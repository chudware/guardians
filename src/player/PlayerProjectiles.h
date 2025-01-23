#ifndef PLAYERPROJECTILES_H
#define PLAYERPROJECTILES_H

#include <raylib.h>
#include "../components/Projectiles.h"

#define MAX_PROJECTILES 9999

Projectile _projectiles[MAX_PROJECTILES];

void AddPlayerProjectile(Vector2 position, Vector2 rotation);
void InitPlayerProjectiles();
void UpdatePlayerProjectiles();
void DrawPlayerProjectiles();

#endif