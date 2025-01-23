#ifndef STONEGUARDIANLEFTPROJECTILES_H
#define STONEGUARDIANLEFTPROJECTILES_H

#include <raylib.h>
#include "../components/Projectiles.h"

#define MAX_PROJECTILES 9999

Projectile _projectiles[MAX_PROJECTILES];

void AddStoneGuardianLeftProjectile(Vector2 position, Vector2 rotation);
void InitStoneGuardianLeftProjectiles();
void UpdateStoneGuardianLeftProjectiles();
void DrawStoneGuardianLeftProjectiles();

#endif