#ifndef STONEGUARDIANLEFT_H
#define STONEGUARDIANLEFT_H

#include "../components/Entity.h"

#define MAX_LEFTSTONEGUARDIANS 1

extern Entity stoneGuardianLeft[MAX_LEFTSTONEGUARDIANS];
extern int worldUpscale;
extern int upscale16x16;
extern Texture2D bagTexture;

void InitStoneGuardianLeft();
void UpdateStoneGuardianLeft();
void DrawStoneGuardianLeft();
void DrawStoneGuardianLeftHPBar();

#endif