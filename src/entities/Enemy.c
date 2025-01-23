#include <raylib.h>
#include "../components/_global.h"
#include "../components/Entity.h"
#include "Enemy.h"

extern Entity player;
Entity enemies[MAX_ENEMIES];

Texture2D enemyTexture;
Texture2D beholderOutlineTexture;
Rectangle enemyRecSrc;
Rectangle enemyRecDest;

void InitEnemy()
{
    enemyTexture = LoadTexture("../src/resources/debug/eye.png");
    enemyRecSrc = (Rectangle){0, 0, enemyTexture.width, enemyTexture.height};
    enemyRecDest = (Rectangle){0, 0, enemyTexture.width, enemyTexture.height}; // 6x the 16x16 texture

    beholderOutlineTexture = LoadTexture("../src/resources/debug/eyeOutline.png");

    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        enemies[i].x = -12800.0f + i * 160.0f; // position enemies with some spacing
        enemies[i].y = 128.0f;
        enemies[i].width = 8.0f * entityUpscale * upscale16x16;
        enemies[i].height = 8.0f * entityUpscale * upscale16x16;
        enemies[i].speed = 4.0f;
        enemies[i].hp = 100.0f;
        enemies[i].active = true;
    }
}

void UpdateEnemy()
{
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        if (enemies[i].hp <= 0)
        {
            enemies[i].active = false; // deactivate enemy if HP is 0 or less
        }
    }
}

void DrawEnemy()
{
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        if (!enemies[i].active)
        {
            continue; // skip drawing inactive enemies
        }

        int enemyHP = enemies[i].hp; // converts to int to display proper number instead of 0

        // draw outline for beholder
        DrawTexture(beholderOutlineTexture, enemies[i].x - enemies[i].width / 2 - 1, enemies[i].y - enemies[i].height / 2 - 1, WHITE);
        // draw the enemy texture
        Rectangle enemyRecDest = (Rectangle){enemies[i].x - enemies[i].width / 2, enemies[i].y - enemies[i].height / 2, enemies[i].width, enemies[i].height};

        // draw the enemy HP
        DrawText(TextFormat("%d", enemyHP), enemies[i].x - enemies[i].width / 2 - 1, enemies[i].y + enemies[i].height / 2 - 1, 22, BLACK);
        DrawText(TextFormat("%d", enemyHP), enemies[i].x - enemies[i].width / 2, enemies[i].y + enemies[i].height / 2, 20, WHITE);
        // draw the enemy rectangle
        // DrawRectangleLines(enemies[i].x - enemies[i].width / 2, enemies[i].y - enemies[i].height / 2, enemies[i].width, enemies[i].height, ORANGE);
    }
}