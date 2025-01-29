#include <raylib.h>
#include "../components/_global.h"
#include "../components/Entity.h"
#include "Player.h"
#include "PlayerController.h"

Entity player;

Texture2D playerTexture;
Texture2D playerUp;
Texture2D playerFacingUpTexture;
Texture2D playerFacingDownTexture;
Texture2D playerFacingRightTexture;
Texture2D playerFacingLeftTexture;
Rectangle playerTextureRecSrc;
Rectangle playerTextureRecDest;

void InitPlayer()
{
    playerTexture = LoadTexture("../src/resources/priestFacingUp.png");
    playerUp = LoadTexture("../src/resources/debug/debugPriest.png");
    playerFacingUpTexture = LoadTexture("../src/resources/priestFacingUp.png");
    playerFacingDownTexture = LoadTexture("../src/resources/priestFacingDown.png");
    playerFacingRightTexture = LoadTexture("../src/resources/priestFacingRight.png");
    playerFacingLeftTexture = LoadTexture("../src/resources/priestFacingLeft.png");
    playerTextureRecSrc = (Rectangle){0, 0, playerTexture.width, playerTexture.height};
    playerTextureRecDest = (Rectangle){0, 0, playerTexture.width, playerTexture.height};
    player.x = 840;
    player.y = 800;
    player.position = (Vector2){player.x, player.y};
    player.width = 50.0f;
    player.height = 50.0f;
    player.speed = 200.0f;
    player.lvl = 0.0f;
    player.maxlvl = 0.0f;
    player.xp = 20.0f;
    player.maxxp = 96.0f;
    player.hp = 20.0f;
    player.maxhp = 120.0f;
    player.mp = 120.0f;
    player.maxmp = 120.0f;
    player.rotation = 0.0f;
    player.damage = 10.0f;
}

void UpdatePlayer()
{
    ControlPlayer();
}

void DrawPlayer()
{
    Rectangle playerTextureRecDest = (Rectangle){player.position.x - player.width / 2, player.position.y - player.height / 2, player.width, player.height};

    float frameTime = GetFrameTime();

    // WASD
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
    {
        player.right = false;
        DrawTexturePro(playerFacingLeftTexture, playerTextureRecSrc, playerTextureRecDest, (Vector2){0, 0}, player.rotation, WHITE);
    }
    else if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        player.right = true;
        DrawTexturePro(playerFacingRightTexture, playerTextureRecSrc, playerTextureRecDest, (Vector2){0, 0}, player.rotation, WHITE);
    }
    else if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
    {
        player.up = true;
        DrawTexturePro(playerFacingUpTexture, playerTextureRecSrc, playerTextureRecDest, (Vector2){0, 0}, player.rotation, WHITE);
    }
    else if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
    {
        player.up = false;
        DrawTexturePro(playerFacingDownTexture,playerTextureRecSrc, playerTextureRecDest, (Vector2){0, 0}, player.rotation, WHITE);
    }
    else{
         DrawTexturePro(playerFacingDownTexture,playerTextureRecSrc, playerTextureRecDest, (Vector2){0, 0}, player.rotation, WHITE);
    }
}