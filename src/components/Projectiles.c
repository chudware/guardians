#include <math.h>
#include "Projectiles.h"
#include "../player/PlayerProjectiles.h"

#define PROJECTILE_LIFESPAN 0.1f // doesnt seem to make projectiles dissapear

Texture2D projectileTexture;

Projectile CreateProjectiles(Vector2 position, float rotation)
{
    return (Projectile){
        .position = position,
        .rotation = rotation,
        .active = true,
        .creationTime = GetTime()};
}

void InitProjectiles(Projectile *projectile)
{
    projectileTexture = LoadTexture("../src/resources/ui/gear.png");
    projectile->width = 32.0f;
    projectile->height = 32.0f;
}

bool UpdateProjectiles(Projectile *projectile, float frametime, float time)
{
    // stop if not active
    if (!projectile->active)
    {
        return false;
    }

    // check lifespan left for projectiles
    if (time > projectile->creationTime + PROJECTILE_LIFESPAN)
    {
        projectile->active = false;
        return false;
    }

    projectile->position.x += projectile->direction.x * projectile->speed * frametime;
    projectile->position.y += projectile->direction.y * projectile->speed * frametime;

    return true;
}

void DrawProjectiles(Projectile projectile)
{
    if (!projectile.active)
    {
        return;
    }
    Rectangle rect = {projectile.position.x, projectile.position.y, projectile.width, projectile.height};
    Rectangle dest = {projectile.position.x, projectile.position.y, projectile.width * 6, projectile.height * 6};
    Vector2 origin = {rect.width / 2, rect.height / 2}; // try replacing rect.width with projectile.width later
    DrawRectanglePro(rect, origin, projectile.rotation, GREEN);
    DrawTexturePro(projectileTexture, rect, dest, origin, projectile.rotation, WHITE);
    // DrawTexturePro(enemyTexture, enemyRecSrc, enemyRecDest, (Vector2){0, 0}, 0, WHITE);
}