#include <stdio.h>
#include <stdbool.h>
#include "raylib.h"
#include "../components/_global.h"
#include "../components/Entity.h"
#include "Player.h"
#include "PlayerCamera.h"

extern Entity player;
Camera2D cam = {0};

void InitCam()
{
    cam.rotation = 0.0f;
    cam.zoom = 1.0f;
}

void UpdateCam()
{
    // set offsets
    Vector2 defaultCameraOffset = (Vector2){screenWidth / 2.0f, screenHeight / 2.0f};
    Vector2 distantCameraOffset = (Vector2){screenWidth / 2.0f, screenHeight / 3.0f * 2};

    // Initialize the camera
    cam.target = player.position;
    cam.offset = defaultCameraOffset;

    // toggle camera offset
    if (IsKeyPressed(KEY_X))
    {
        if (cam.offset.x == distantCameraOffset.x && cam.offset.y == distantCameraOffset.y)
        {
            cam.offset = defaultCameraOffset;
        }
        else
        {
            cam.offset = distantCameraOffset;
        }
    }
}