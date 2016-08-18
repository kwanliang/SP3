#ifndef GIANTSQUIDTENTACLE_H
#define GIANTSQUIDTENTACLE_H

#include "Vector3.h"
#include "CollisionManager.h"

class GiantSquidTentacle
{
private:
    Vector3 m_TentaclePos;
    float m_TentacleInitialRotate;
    float m_TentacleAnimateRotate;

    int m_health;

public:
    GiantSquidTentacle();
    ~GiantSquidTentacle();

    Vector3 getTentaclePos();
    void setTentaclePos(Vector3 m_TentaclePos);

    float getTentacleInitialRotate();
    void setTentacleInitialRotate(float m_TentacleInitialRotate);

    float getTentacleAnimateRotate();
    void setTentacleAnimateRotate(float m_TentacleAnimateRotate);

    int getHealth();
    void setHealth(int m_health);

    hitbox collision;
};

#endif