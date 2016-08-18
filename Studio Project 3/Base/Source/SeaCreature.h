#ifndef SEACREATURE_H
#define SEACREATURE_H

#include "GameObject.h"
#include "Vector3.h"
#include "CollisionManager.h"

class SeaCreature : public GameObject
{
private:
    int m_health;
	Vector3 m_position;

public:
    enum SEACREATURE_TYPE
    {
        MINNOW = 0,
		PUFFER,

        TYPE_TOTAL,
    };
    SEACREATURE_TYPE seaType;

    SeaCreature();
    SeaCreature(int m_health, SEACREATURE_TYPE seaType, OBJECT_TYPE objectType, Vector3 pos, Vector3 vel, Vector3 scale, bool active);
    ~SeaCreature();

    int getHealth();

	void setPos(Vector3 pos);
    void setHealth(int m_health);

    hitbox2 collision;
};

#endif