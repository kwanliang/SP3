#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "GameObject.h"

class Projectile : public GameObject
{
public:
    Projectile();
    Projectile(OBJECT_TYPE objectType, Vector3 pos, Vector3 vel, Vector3 scale, bool active);
    ~Projectile();
};

#endif