#ifndef PROJECTILES_H
#define PROJECTILES_H

#include <raylib.h>

typedef struct Projectile
{
    Vector2 position;
    Vector2 direction;
    float speed;
    float damage;
    float lifespan;
    float count;
    float rotation;
    float width;
    float height;
    float maxProjectiles;
    float delay;
    float creationTime;
    bool active;
} Projectile;

Projectile CreateProjectiles(Vector2 position, float rotation);
bool UpdateProjectiles(Projectile* projectile, float frametime, float time);
void DrawProjectiles(Projectile projectile);
//void DrawStoneGuardianProjectiles(Projectile projectile);

#endif