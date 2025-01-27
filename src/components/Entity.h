#ifndef ENTITY_H
#define ENTITY_H

#include <raylib.h>

typedef struct Entity
{
    Vector2 position;
    Vector2 velocity;
    bool active;
    bool right;
    bool up;
    float x;
    float y;
    float width;
    float height;
    float speed;
    float lvl;
    float maxlvl;
    float xp;
    float maxxp;
    float hp;
    float maxhp;
    float mp;
    float maxmp;
    float rotation;
    float timer;
    float lastDirectionChange;
} Entity;

#endif