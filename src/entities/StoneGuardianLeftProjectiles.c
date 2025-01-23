#include <stdlib.h>
#include <stdio.h>
#include <raylib.h>
#include <raymath.h>
#include "../components/_global.h"
#include "../components/Projectiles.h"
#include "../components/Entity.h"
#include "../player/Player.h"
#include "../player/PlayerCamera.h"
#include "StoneGuardianLeft.h"
#include "StoneGuardianLeftProjectiles.h"

extern Entity stoneGuardianLeft[MAX_LEFTSTONEGUARDIANS];
Projectile _projectiles[MAX_PROJECTILES];

void AddStoneGuardianLeftProjectile(Vector2 position, Vector2 target)
{
    bool created = false;

    for (int i = 0; i < MAX_PROJECTILES; i++)
    {
        if (_projectiles[i].active)
        {
            continue;
        }

        // convert mouse position to world2 coordinates
        Vector2 worldMousePosition = GetScreenToWorld2D(target, cam);
        Vector2 direction = Vector2Normalize(Vector2Subtract(worldMousePosition, position));
        _projectiles[i] = CreateProjectiles(stoneGuardianLeft[i].position, 0.0f);
        _projectiles[i].direction = direction;
        _projectiles[i].speed = 1200.0f;
        _projectiles[i].lifespan = 2.0f;
        _projectiles[i].width = 10.0f;
        _projectiles[i].height = 20.0f;
        _projectiles[i].active = true;
        _projectiles[i].rotation = atan2f(direction.y, direction.x) * (180.0f / PI) - 90.0f; // set rotation based on direction
        created = true;
        break;
    }

    if (!created)
    {
        TraceLog(LOG_ERROR, "Failed to create the Left Guardian's projectile! (NO INACTIVE SPOTS IN THE ARRAY!)");
        return;
    }
}

void InitStoneGuardianLeftProjectiles()
{
    for (int i = 0; i < MAX_PROJECTILES; i++)
    {
        _projectiles[i].active = false;
        _projectiles[i].delay = 0.1f; // Set a default delay value
        _projectiles[i].lifespan = 0.1f; // Set a default delay value
    }
}

void UpdateStoneGuardianLeftProjectiles()
{
    float frameTime = GetFrameTime();

    for (int i = 0; i < MAX_PROJECTILES; i++)
    {
        if (_projectiles[i].active)
        {
            _projectiles[i].position.x += _projectiles[i].direction.x * _projectiles[i].speed * frameTime;
            _projectiles[i].position.y += _projectiles[i].direction.y * _projectiles[i].speed * frameTime;

            // update rotation based on direction
            _projectiles[i].rotation = atan2f(_projectiles[i].direction.y, _projectiles[i].direction.x) * (180.0f / PI) - 90.0f;

            // decrease lifespan
            _projectiles[i].lifespan -= frameTime;

            // deactivate the projectile if it goes off the map or its lifespan reaches zero
            if (_projectiles[i].position.x < -9999 || _projectiles[i].position.x > 9999 ||
                _projectiles[i].position.y < -9999 || _projectiles[i].position.y > 9999 ||
                _projectiles[i].lifespan <= 0.0f)
            {
                _projectiles[i].active = false;
            }
        }
    }
}

void DrawStoneGuardianLeftProjectiles()
{
    for (int i = 0; i < MAX_PROJECTILES; i++)
    {
        if (_projectiles[i].active)
        {
            DrawProjectiles(_projectiles[i]);
            DrawStoneGuardianProjectiles(_projectiles[i]);
        }
    }
}