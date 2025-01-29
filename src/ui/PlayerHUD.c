#include <raylib.h>
#include "PlayerHUD.h"
#include "../components/_global.h"
#include "../components/Entity.h"
#include "../player/Player.h"

extern Entity player;
extern Entity StoneGuardian;
Texture2D stats;
Texture2D gear;

void InitPlayerHUD()
{
    stats = LoadTexture("../src/resources/ui/stats.png");
    gear = LoadTexture("../src/resources/ui/gear.png");
}

void UpdatePlayerHUD()
{
}

void DrawPlayerHUD()
{
    DrawTexture(stats, screenWidth - stats.width, screenHeight - stats.height, WHITE);
    DrawTexture(gear, 0, screenHeight - gear.height, WHITE);

    // display player stats with stat bars
    DrawRectangle(screenWidth - 330, screenHeight - 36, player.xp, 10, ORANGE);
    DrawRectangle(screenWidth - 162, screenHeight - 36, player.hp, 10, RED);
    DrawRectangle(screenWidth - 162, screenHeight - 50, player.mp, 10, BLUE);

    // draw hp bar
    float stoneGuardianHP = StoneGuardian.hp;
    if (stoneGuardianHP > 0)
    {
        DrawRectangle(screenWidth / 2 - 45000 / 100 / 2 - 1, 15, 45000 / 100 + 2, 18, BLACK);             // bar outline
        DrawRectangle(screenWidth / 2 - 45000 / 100 / 2, 16, 45000 / 100, 16, RED);                       // empty bar color
        DrawRectangle(screenWidth / 2 - stoneGuardianHP / 100 / 2, 16, stoneGuardianHP / 100, 16, GREEN); // health bar
    }
}