#include "Projectile.h"

Projectile::Projectile()
    : GameObject(PROJECTILE, Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(1, 1, 1), false)
{

}

Projectile::Projectile(OBJECT_TYPE objectType, Vector3 pos, Vector3 vel, Vector3 scale, bool active)
    : GameObject(objectType, pos, vel, scale, active)
{

}

Projectile::~Projectile()
{

}