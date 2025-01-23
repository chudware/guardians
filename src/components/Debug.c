#include <raylib.h>
#include "Debug.h"
#include "../components/Entity.h"
#include "../player/Player.h"

extern Entity player;

void InitDebug()
{
}

void UpdateDebug()
{
    if (IsKeyPressed(KEY_R))
    {
        player.position.x = 640;
        player.position.y = 640;
    }
}

void DrawDebug()
{
}

void DrawDebugHUD()
{
}