#include <raylib.h>
#include "../components/Entity.h"
#include "../entities/Enemy.h"
#include "../entities/StoneGuardian.h"
#include "../player/Player.h"
#include "../player/PlayerProjectiles.h"

#define MAX_PROJECTILES 9999

extern Entity player;
extern Projectile _projectiles[MAX_PROJECTILES];
extern Rectangle StoneGuardianRecSrc;
extern Texture2D bagTexture;
extern Entity StoneGuardian;
extern Rectangle StoneGuardianTextureRecDest;

Rectangle topCollisionRect = {144, 144, 1392, 48};     // top
Rectangle bottomCollisionRect = {144, 1104, 1392, 48}; // bottom
Rectangle left1CollisionRect = {144, 0, 48, 1152};     // left 1
Rectangle right1CollisionRect = {1488, 0, 48, 1152};   // right 1
Rectangle playerRect;

void UpdateCollision()
{
    float frameTime = GetFrameTime();
    Rectangle playerRect = (Rectangle){player.position.x - player.width / 2, player.position.y - player.height / 2, player.width, player.height};
    // wall collision
    if (CheckCollisionRecs(playerRect, topCollisionRect))
    {
        player.position.y += player.speed * frameTime;
    }
    if (CheckCollisionRecs(playerRect, bottomCollisionRect))
    {
        player.position.y -= player.speed * frameTime;
    }
    if (CheckCollisionRecs(playerRect, left1CollisionRect))
    {
        player.position.x += player.speed * frameTime;
    }
    if (CheckCollisionRecs(playerRect, right1CollisionRect))
    {
        player.position.x -= player.speed * frameTime;
    }

    StoneGuardianTextureRecDest = (Rectangle){StoneGuardian.x - StoneGuardian.width / 2, StoneGuardian.y - StoneGuardian.height / 2, StoneGuardian.width, StoneGuardian.height};

    // check collision between enemies and player projectiles
    for (int i = 0; i < MAX_PROJECTILES; i++)
    {
        if (_projectiles[i].active)
        {
            Rectangle projectileRect = {
                _projectiles[i].position.x - _projectiles[i].width / 2,
                _projectiles[i].position.y - _projectiles[i].height / 2,
                _projectiles[i].width,
                _projectiles[i].height};

            // check for guardian collision
            Rectangle StoneGuardianRecSrc = {
                StoneGuardian.x - StoneGuardian.width / 2,
                StoneGuardian.y - StoneGuardian.height / 2,
                StoneGuardian.width,
                StoneGuardian.height};

            if (CheckCollisionRecs(StoneGuardianRecSrc, projectileRect))
            {
                _projectiles[i].active = false; // deactivate projectile on collision
                StoneGuardian.hp -= 10;
                if (StoneGuardian.hp <= 0)
                {
                    StoneGuardian.active = false; // deactivate enemy if HP is 0 or less
                }
            }
        }
    }
}

void DrawCollision()
{
    DrawRectangle(144, 144, 1392, 48, RED);     // top
    DrawRectangle(144, 1104, 1392, 48, YELLOW); // bottom
    DrawRectangle(144, 0, 48, 1152, DARKBLUE);  // left 1
    DrawRectangle(1488, 0, 48, 1152, PURPLE);   // right 1
}