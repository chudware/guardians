#include <raylib.h>
#include "World1.h"
#include "_global.h"
#include "../player/Player.h"
#include "../player/PlayerProjectiles.h"

Texture2D world1;
Rectangle world1RecSrc;
Rectangle world1RecDest;

int world1Rotation;

void InitWorld1()
{
    world1 = LoadTexture("../Src/maps/world1.png");
    world1RecSrc = (Rectangle){0, 0, world1.width, world1.height};
    world1RecDest = (Rectangle){0, 0, world1.width * worldUpscale, world1.height * worldUpscale};
    world1Rotation = 0;
}

void UpdateWorld1()
{
}

void DrawWorld1()
{
    DrawTexturePro(world1, world1RecSrc, world1RecDest, (Vector2){0, 0}, world1Rotation, WHITE);
}