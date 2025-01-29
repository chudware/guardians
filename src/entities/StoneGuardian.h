#ifndef STONEGUARDIAN_H
#define STONEGUARDIAN_H

extern Rectangle StoneGuardianTextureRecDest;

void ShootStoneGuardianProjectile(float directionX, float directionY);
void InitStoneGuardian();
void UpdateStoneGuardian();
void UpdateStoneGuardianProjectiles();
void DrawStoneGuardian();
void DrawStoneGuardianProjectiles();

#endif