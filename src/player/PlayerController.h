#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "../components/Projectiles.h"

#define MAX_PROJECTILES 9999

extern Projectile _projectiles[MAX_PROJECTILES];

void ControlPlayer();

#endif