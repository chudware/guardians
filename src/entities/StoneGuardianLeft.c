#include <raylib.h>
#include <math.h>
#include "../components/_global.h"
#include "../components/Entity.h"
#include "StoneGuardianLeft.h"

extern Entity player;
Entity stoneGuardianLeft[MAX_LEFTSTONEGUARDIANS];

Texture2D stoneGuardianLeftTexture;
Texture2D beholderOutlineTexture;
Rectangle stoneGuardianLeftRecSrc;
Rectangle stoneGuardianLeftRecDest;

// bag
Texture2D bagTexture;

void InitStoneGuardianLeft()
{
    // set stone guardian stats and textures
    stoneGuardianLeftTexture = LoadTexture("../src/resources/stoneguardianleft.png");
    stoneGuardianLeftRecSrc = (Rectangle){0, 0, stoneGuardianLeftTexture.width, stoneGuardianLeftTexture.height};
    stoneGuardianLeftRecDest = (Rectangle){0, 0, stoneGuardianLeftTexture.width, stoneGuardianLeftTexture.height};

    for (int i = 0; i < MAX_LEFTSTONEGUARDIANS; i++)
    {
        stoneGuardianLeft[i].x = 836.0f + i * 160.0f;
        stoneGuardianLeft[i].y = 640.0f;
        stoneGuardianLeft[i].width = 112.0f;
        stoneGuardianLeft[i].height = 112.0f;
        stoneGuardianLeft[i].speed = 80.0f;
        stoneGuardianLeft[i].hp = 45000.0f;
        stoneGuardianLeft[i].active = true;
    }

    // set textures for dropped bag
    bagTexture = LoadTexture("../src/resources/stoneguardianleft.png");
}

void UpdateStoneGuardianLeft()
{
    float deltaTime = GetFrameTime();
    for (int i = 0; i < MAX_LEFTSTONEGUARDIANS; i++)
    {
        if (stoneGuardianLeft[i].hp <= 0)
        {
            stoneGuardianLeft[i].active = false;
        }
    }
    // change left guardian position
    /*
    if (stoneGuardianLeft->y <= 640)
    {
        stoneGuardianLeft->y = stoneGuardianLeft->y + stoneGuardianLeft->speed * deltaTime;



    }*/
    for (int i = 0; i < MAX_LEFTSTONEGUARDIANS; i++)
    {
        if (stoneGuardianLeft[i].hp >= 0 && (GetTime() - stoneGuardianLeft[i].lastDirectionChange >= 1.0f))
        {
            // Generate random direction
            float randomAngle = GetRandomValue(0, 360) * (PI / 180.0f); // Convert to radians
            float speed = 100.0f;                                       // Movement speed

            // Update player position
            stoneGuardianLeft[i].x += cos(randomAngle) * speed;
            stoneGuardianLeft[i].y += sin(randomAngle) * speed;

            // Update the last direction change time
            stoneGuardianLeft[i].lastDirectionChange = GetTime();
        }
    }
}

void DrawStoneGuardianLeft()
{
    for (int i = 0; i < MAX_LEFTSTONEGUARDIANS; i++)
    {
        if (!stoneGuardianLeft[i].active)
        {
            continue; // skip drawing inactive stoneGuardianLeft
        }

        int stoneGuardianLeftHP = stoneGuardianLeft[i].hp;

        // draw guardian
        DrawTexture(stoneGuardianLeftTexture, stoneGuardianLeft[i].x - stoneGuardianLeft[i].width / 2, stoneGuardianLeft[i].y - stoneGuardianLeft[i].height / 2, WHITE);
    }
}

void DrawStoneGuardianLeftHPBar()
{
    for (int i = 0; i < MAX_LEFTSTONEGUARDIANS; i++)
    {
        int stoneGuardianLeftHP = stoneGuardianLeft[i].hp;
        if (stoneGuardianLeftHP > 0)
        {
            DrawRectangle(screenWidth / 2 - 45000 / 100 / 2 - 1, 15, 45000 / 100 + 2, 18, BLACK);                 // bar outline
            DrawRectangle(screenWidth / 2 - 45000 / 100 / 2,  16, 45000 / 100, 16, RED);                               // empty bar color
            DrawRectangle(screenWidth / 2 - stoneGuardianLeftHP / 100 / 2, 16, stoneGuardianLeftHP / 100, 16, GREEN); // health bar
        }
    }
}