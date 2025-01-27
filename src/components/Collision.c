#include <raylib.h>
#include "../components/Entity.h"
#include "../player/Player.h"
#include "../player/PlayerProjectiles.h"

#define MAX_PROJECTILES 9999

extern Entity player;
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
}

void DrawCollision()
{
    DrawRectangle(144, 144, 1392, 48, RED);     // top
    DrawRectangle(144, 1104, 1392, 48, YELLOW); // bottom
    DrawRectangle(144, 0, 48, 1152, DARKBLUE);  // left 1
    DrawRectangle(1488, 0, 48, 1152, PURPLE);   // right 1
}