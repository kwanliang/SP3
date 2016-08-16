#ifndef SEACREATURE_H
#define SEACREATURE_H

#include "GameObject.h"

class SeaCreature : public GameObject
{
private:
    int m_health;
public:
    enum SEACREATURE_TYPE
    {
        MINNOW = 0,

        TYPE_TOTAL,
    };
    SEACREATURE_TYPE seaType;

    SeaCreature();
    SeaCreature(int m_health, SEACREATURE_TYPE seaType, OBJECT_TYPE objectType, Vector3 pos, Vector3 vel, Vector3 scale, bool active);
    ~SeaCreature();

    int getHealth();

    void setHealth(int m_health);
};

#endif