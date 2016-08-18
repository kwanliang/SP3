#ifndef BOSS_H
#define BOSS_H

#include "GameObject.h"
#include "CollisionManager.h"

class Boss : public GameObject
{
private:
    int m_health;

public:
    enum BOSS_TYPE
    {
        GIANTSQUID = 0,
        GIANTSQUIDTENTACLE,

        TYPE_TOTAL,
    };

    BOSS_TYPE bossType;

    Boss();
    Boss(int m_health, BOSS_TYPE bossType, OBJECT_TYPE objectType, Vector3 pos, Vector3 vel, Vector3 scale, bool active);
    ~Boss();

    hitbox collision;
};

#endif