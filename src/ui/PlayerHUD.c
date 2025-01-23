#include <raylib.h>
#include "PlayerHUD.h"
#include "../components/_global.h"
#include "../components/Entity.h"
#include "../player/Player.h"

extern Entity player;
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
}