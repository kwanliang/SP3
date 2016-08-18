#include "Boss.h"

Boss::Boss()
    : m_health(0)
    , bossType(GIANTSQUID)
    , GameObject(BOSS, Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(1, 1, 1), false)
{

}

Boss::Boss(int m_health, BOSS_TYPE bossType, OBJECT_TYPE objectType, Vector3 pos, Vector3 vel, Vector3 scale, bool active)
    : m_health(m_health)
    , bossType(bossType)
    , GameObject(objectType, pos, vel, scale, active)
{

}

Boss::~Boss()
{

}