#include <raylib.h>
#include "../components/Entity.h"
#include "../components/Projectiles.h"
#include "PlayerController.h"
#include "PlayerProjectiles.h"

extern Entity player;

static float shootCooldownTimer = 0.0f;

void ControlPlayer()
{
    // get frameTime for proper speed when unlimited fps
    float frameTime = GetFrameTime();

    // WASD
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
    {
        player.position.x -= player.speed * frameTime;
    }
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        player.position.x += player.speed * frameTime;
    }
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
    {
        player.position.y -= player.speed * frameTime;
    }
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
    {
        player.position.y += player.speed * frameTime;
    }

    // shoot projectiles towards the mouse click location
    shootCooldownTimer -= frameTime;

    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && shootCooldownTimer <= 0.0f)
    {
        Vector2 mousePosition = GetMousePosition();
        AddPlayerProjectile(player.position, mousePosition);

        // find the first inactive projectile to get its delay value
        for (int i = 0; i < MAX_PROJECTILES; i++)
        {
            if (!_projectiles[i].active)
            {
                shootCooldownTimer = _projectiles[i].delay; // use the delay value from the projectile
                break;
            }
        }
    }

    // use mana to heal
    if (IsKeyPressed(KEY_SPACE) && player.mp >= 20.0f){
        player.mp -= 10.0f;
        player.hp += 20.0f;
        if( player.hp >= player.maxhp)
        {
            player.hp = player.maxhp;
        }
    }

    // remove hp from player
     if (IsKeyPressed(KEY_N)){
        player.hp -= 30.0f;
    }
}