#include "SeaCreature.h"

SeaCreature::SeaCreature()
    : m_health(0)
    , seaType(MINNOW)
    , GameObject(SEACREATURE, Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(1, 1, 1), false)
{

}

SeaCreature::SeaCreature(int m_health, SEACREATURE_TYPE seaType, OBJECT_TYPE objectType, Vector3 pos, Vector3 vel, Vector3 scale, bool active)
    : m_health(m_health)
    , seaType(seaType)
    , GameObject(objectType, pos, vel, scale, active)
{

}

SeaCreature::~SeaCreature()
{

}

int SeaCreature::getHealth()
{
    return this->m_health;
}

void SeaCreature::setHealth(int m_health)
{
    this->m_health = m_health;
}