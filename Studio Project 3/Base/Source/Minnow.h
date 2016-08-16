#ifndef MINNOW_H
#define MINNOW_H

#include "SeaCreature.h"

static float distFromSeperation = 50.f;
static float distFromAlignment = 400.f;

class Minnow : public SeaCreature
{
private:
    float panicTime;

public:
    enum MINNOW_BEHAVIORSTATE
    {
        FLOCK,
        FLEE,

        STATE_TOTAL,
    };
    MINNOW_BEHAVIORSTATE state;

    Minnow();
    Minnow(MINNOW_BEHAVIORSTATE state, float panicTime, int m_health, SEACREATURE_TYPE seaType, OBJECT_TYPE objectType, Vector3 pos, Vector3 vel, Vector3 scale, bool active);
    ~Minnow();

    Vector3 cohesion(Vector3 CentreOfMass, int neighbourCount);
    Vector3 seperation(Vector3 repelVector);
    Vector3 alignment(Vector3 forceVector, int neighbourCount);

    float getpanicTime();
    void setpanicTime(float panicTime);

};

#endif