#include <raylib.h>
#include <stdio.h>
#include <math.h>
#include "StoneGuardian.h"
#include "../components/_global.h"
#include "../components/Entity.h"
#include "../player/Player.h"

#define MAX_PROJECTILES 666 // Increased to allow for continuous shooting

typedef struct Projectile
{
    Vector2 position;
    Vector2 velocity;
    float radius;
    bool active;
    Color color;
} Projectile;

extern Entity player;

Entity StoneGuardian;
Texture2D StoneGuardianTexture;
Rectangle StoneGuardianTextureRecSrc;
Rectangle StoneGuardianTextureRecDest;
Vector2 guardianPosition;
Vector2 origin;
Texture2D projectileImage;
Projectile projectiles[MAX_PROJECTILES] = {0};

float projectileSpeed = 500.0f;
float projectileRadius = 5.0f;
float angles[] = {0.0f, 90.0f, 180.0f, 270.0f};
int projectileLimit = 2048;

void InitStoneGuardian()
{
    StoneGuardianTexture = LoadTexture("../src/resources/stoneguardianleft.png");
    Texture2D projectileImage = LoadTexture("../src/resources/projectile.png");
    StoneGuardianTextureRecSrc = (Rectangle){0, 0, StoneGuardianTexture.width, StoneGuardianTexture.height};
    StoneGuardianTextureRecDest = (Rectangle){0, 0, StoneGuardianTexture.width, StoneGuardianTexture.height};
    StoneGuardian.x = 256;
    StoneGuardian.y = 256;
    StoneGuardian.hp = 100.0f;
    StoneGuardian.width = 112;
    StoneGuardian.height = 112;
    guardianPosition = (Vector2){StoneGuardian.x, StoneGuardian.y};
    StoneGuardian.speed = 128.0f;
}

void UpdateStoneGuardian()
{
    float frameTime = GetFrameTime();
    if (StoneGuardian.hp > 0)
    {
        if (StoneGuardian.x <= 1024)
        {
            StoneGuardian.x += StoneGuardian.speed * frameTime;
            if (StoneGuardian.y <= 480)
                StoneGuardian.y += StoneGuardian.speed * frameTime;
        }
    }
}

int projectileCounts[4] = {0}; // track projectiles per direction

void UpdateStoneGuardianProjectiles()
{
    origin = (Vector2){StoneGuardian.x, StoneGuardian.y};
    int maxProjectilesPerDirection = MAX_PROJECTILES / 4; // distribute evenly

    for (int i = 0; i < 4; i++)
    {
        if (projectileCounts[i] < maxProjectilesPerDirection)
        {
            int projectileIndex = -1;
            for (int j = 0; j < MAX_PROJECTILES; j++)
            {
                if (!projectiles[j].active)
                {
                    projectileIndex = j;
                    break;
                }
            }

            if (projectileIndex != -1)
            {
                float angleRad = angles[i] * (PI / 180.0f);
                projectiles[projectileIndex] = (Projectile){
                    .position = origin,
                    .velocity = {projectileSpeed * cosf(angleRad), projectileSpeed * sinf(angleRad)},
                    .radius = projectileRadius,
                    .active = true,
                    .color = (i == 0) ? RED : (i == 1) ? BLUE
                                          : (i == 2)   ? PURPLE
                                                       : GREEN};
                projectileCounts[i]++;
            }
        }
    }

    // update existing active projectiles and decrement counts when projectiles go out of bounds
    for (int i = 0; i < MAX_PROJECTILES; i++)
    {
        if (projectiles[i].active)
        {
            projectiles[i].position.x += projectiles[i].velocity.x * GetFrameTime();
            projectiles[i].position.y += projectiles[i].velocity.y * GetFrameTime();

            if (projectiles[i].position.x < 0 || projectiles[i].position.x > projectileLimit ||
                projectiles[i].position.y < 0 || projectiles[i].position.y > projectileLimit)
            {
                projectiles[i].active = false;
                for (int k = 0; k < 4; k++)
                { // find which direction and decrement count
                    float angleRad = angles[k] * (PI / 180.0f);
                    if (fabs(projectiles[i].velocity.x - projectileSpeed * cosf(angleRad)) < 1 &&
                        fabs(projectiles[i].velocity.y - projectileSpeed * sinf(angleRad)) < 1)
                    {
                        projectileCounts[k]--;
                        break;
                    }
                }
            }
        }
    }
}

void DrawStoneGuardianProjectiles()
{
    if (StoneGuardian.hp > 0)
    {
        for (int i = 0; i < MAX_PROJECTILES; i++)
        {
            if (projectiles[i].active)
            {
                DrawCircle((int)projectiles[i].position.x, (int)projectiles[i].position.y, projectiles[i].radius, projectiles[i].color);
                DrawTexture(projectileImage, (int)projectiles[i].position.x - projectiles[i].radius, (int)projectiles[i].position.y - projectiles[i].radius, projectiles[i].color); // dead code, doesn't work, might fix it later
            }
        }
    }
}

void DrawStoneGuardian()
{
    if (StoneGuardian.hp > 0)
    {
        StoneGuardianTextureRecDest = (Rectangle){StoneGuardian.x - StoneGuardian.width / 2, StoneGuardian.y - StoneGuardian.height / 2, StoneGuardian.width, StoneGuardian.height};
        DrawTexturePro(StoneGuardianTexture, StoneGuardianTextureRecSrc, StoneGuardianTextureRecDest, (Vector2){0, 0}, 0, WHITE);
        DrawText(TextFormat("HP: %.0f", StoneGuardian.hp), StoneGuardian.x - 32, StoneGuardian.y - 64, 20, RED);
    }
    else
    {
        DrawText("Stone Guardian defeated!", StoneGuardian.x, StoneGuardian.y, 20, RED);
    }
}
