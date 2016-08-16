#include "Skipper.h"

Skipper::Skipper()
    : m_health(0)
    , GameObject(PLAYER, Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(1, 1, 1), false)
{

}

Skipper::Skipper(int m_health, OBJECT_TYPE objectType, Vector3 pos, Vector3 vel, Vector3 scale, bool active)
    : m_health(m_health)
    , GameObject(objectType, pos, vel, scale, active)
{

}

Skipper::~Skipper()
{

}

int Skipper::getHealth()
{
    return m_health;
}

void Skipper::setHealth(int m_health)
{
    this->m_health = m_health;
}