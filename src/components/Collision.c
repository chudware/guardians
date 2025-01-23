#include <raylib.h>
#include "../components/Entity.h"
#include "../player/Player.h"
#include "../player/PlayerProjectiles.h"
#include "../entities/Enemy.h"
#include "../entities/StoneGuardianLeft.h"

#define MAX_PROJECTILES 9999

extern Entity player;
extern Entity enemies[MAX_ENEMIES];
extern Entity stoneGuardianLeft[MAX_LEFTSTONEGUARDIANS];
extern Projectile _projectiles[MAX_PROJECTILES];
extern Rectangle stoneGuardianLeftRecSrc;
extern Texture2D bagTexture;

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

    // for some reason I need to spawn at least one eye to have collision between projectiles and leftguardian work
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

            for (int j = 0; j < MAX_ENEMIES; j++)
            {
                if (!enemies[j].active)
                {
                    continue; // skip inactive enemies
                }

                Rectangle enemyRect = {
                    enemies[j].x - enemies[j].width / 2,
                    enemies[j].y - enemies[j].height / 2,
                    enemies[j].width,
                    enemies[j].height};

                if (CheckCollisionRecs(enemyRect, projectileRect))
                {
                    _projectiles[i].active = false; // deactivate projectile on collision
                    enemies[j].hp -= 10;
                    if (enemies[j].hp <= 0)
                    {
                        enemies[j].active = false; // deactivate enemy if HP is 0 or less
                        TraceLog(LOG_INFO, "Enemy killed!");
                    }
                }
                // check for left guardian collision
                for (int j = 0; j < MAX_LEFTSTONEGUARDIANS; j++)
                {
                    if (!stoneGuardianLeft[j].active)
                    {
                        continue; // skip inactive enemies
                    }

                    Rectangle stoneGuardianLeftRecSrc = {
                        stoneGuardianLeft[j].x - stoneGuardianLeft[j].width / 2,
                        stoneGuardianLeft[j].y - stoneGuardianLeft[j].height / 2,
                        stoneGuardianLeft[j].width,
                        stoneGuardianLeft[j].height};

                    if (CheckCollisionRecs(stoneGuardianLeftRecSrc, projectileRect))
                    {
                        _projectiles[i].active = false; // deactivate projectile on collision
                        stoneGuardianLeft[j].hp -= 10;
                        if (stoneGuardianLeft[j].hp <= 0)
                        {
                            DrawTexture(bagTexture, 800, 800, WHITE); // a bag with debug texture doesnt drop
                            stoneGuardianLeft[j].active = false;      // deactivate enemy if HP is 0 or less
                            TraceLog(LOG_INFO, "Enemy killed!");
                            player.xp += 10;
                        }
                    }
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