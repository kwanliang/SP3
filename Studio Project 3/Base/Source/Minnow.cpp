#include "Minnow.h"

Minnow::Minnow()
    : state(FLOCK)
    , panicTime(0.f)
    , SeaCreature(0, MINNOW, SEACREATURE, Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(1, 1, 1), false)
{

}

Minnow::Minnow(MINNOW_BEHAVIORSTATE state, float panicTime, int m_health, SEACREATURE_TYPE seaType, OBJECT_TYPE objectType, Vector3 pos, Vector3 vel, Vector3 scale, bool active)
    : state(state)
    , panicTime(panicTime)
    , SeaCreature(m_health, seaType, objectType, pos, vel, scale, active)
{

}

Minnow::~Minnow()
{

}

Vector3 Minnow::cohesion(Vector3 centreOfMassVector, int neighbourCount)
{
    if (!centreOfMassVector.IsZero())
    {
        centreOfMassVector.x /= neighbourCount;
        centreOfMassVector.y /= neighbourCount;
        centreOfMassVector.z /= neighbourCount;

        return (centreOfMassVector - this->pos).Normalized();
    }
    return Vector3(0, 0, 0);
}

Vector3 Minnow::seperation(Vector3 repelVector)
{
    float tempIntensity = 0.f;

    if (!repelVector.IsZero())
    {
        tempIntensity = 1 - (repelVector.LengthSquared() / 100);
        repelVector = repelVector.Normalized();
        repelVector = Vector3(repelVector.x / tempIntensity, repelVector.y / tempIntensity, repelVector.z / tempIntensity);

        return repelVector;
    }
    return Vector3(0, 0, 0);
}

Vector3 Minnow::alignment(Vector3 forceVector, int neighbourCount)
{

    // Alignment
    if (!forceVector.IsZero())
    {
        forceVector.x /= neighbourCount;
        forceVector.y /= neighbourCount;
        forceVector.z /= neighbourCount;

        return forceVector.Normalized();
    }
    return Vector3(0, 0, 0);
}

float Minnow::getpanicTime()
{
    return this->panicTime;
}

void Minnow::setpanicTime(float panicTime)
{
    this->panicTime = panicTime;
}