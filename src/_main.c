#include <raylib.h>
#include "components/_global.h"
#include "components/Collision.h"
#include "components/Debug.h"
#include "components/Projectiles.h"
#include "components/World1.h"
#include "ui/PlayerHUD.h"
#include "player/Player.h"
#include "player/PlayerCamera.h"
#include "player/PlayerController.h"
#include "player/PlayerProjectiles.h"
#include "entities/Enemy.h"
#include "entities/StoneGuardianLeft.h"
#include "entities/StoneGuardianLeftProjectiles.h"

int main(void)
{
    // init
    InitWindow(screenWidth, screenHeight, gameName);
    SetTargetFPS(2048);
    InitAudioDevice();
    InitWorld1();
    InitPlayerHUD();
    InitPlayerProjectiles();
    InitPlayer();
    InitEnemy();
    InitStoneGuardianLeftProjectiles();
    InitStoneGuardianLeft();
    InitDebug();
    InitCam();

    while (!WindowShouldClose())
    {
        // updates
        UpdateCollision();
        UpdatePlayerProjectiles();
        UpdatePlayer();
        UpdateEnemy();
        UpdateStoneGuardianLeftProjectiles();
        UpdateStoneGuardianLeft();
        UpdateDebug();
        UpdatePlayerHUD();
        UpdateCam();

        // drawing
        BeginDrawing();
        ClearBackground(SKYBLUE);
        BeginMode2D(cam);
        DrawWorld1();
        // DrawCollision();
        DrawDebug();
        DrawPlayerProjectiles();
        DrawPlayer();
        DrawEnemy();
        DrawStoneGuardianLeftProjectiles();
        DrawStoneGuardianLeft();
        DrawDebug();
        EndMode2D();
        DrawDebugHUD();
        DrawPlayerHUD();
        DrawStoneGuardianLeftHPBar();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}