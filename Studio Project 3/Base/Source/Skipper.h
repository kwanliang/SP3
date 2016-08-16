#ifndef SKIPPER_H
#define SKIPPER_H

#include "GameObject.h"

class Skipper : public GameObject
{
private:
    int m_health;

public:
    Skipper();
    Skipper(int m_health, OBJECT_TYPE objectType, Vector3 pos, Vector3 vel, Vector3 scale, bool active);
    ~Skipper();

    int getHealth();
    void setHealth(int m_health);
};

#endif