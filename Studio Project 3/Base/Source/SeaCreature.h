#ifndef SEACREATURE_H
#define SEACREATURE_H

#include "GameObject.h"
#include "Vector3.h"
#include "CollisionManager.h"

static float distFromSeperation = 200.f;
static float distFromSeperationIntensity = 400.f;
static float distFromAlignment = 400.f;

class SeaCreature : public GameObject
{
protected:
    int m_health;
	Vector3 m_position;

public:
    enum SEACREATURE_TYPE
    {
        MINNOW = 0,
		PUFFER,
		FCRAB,
        TYPE_TOTAL,
    };
    SEACREATURE_TYPE seaType;

    SeaCreature();
    SeaCreature(int m_health, SEACREATURE_TYPE seaType, OBJECT_TYPE objectType, Vector3 pos, Vector3 vel, Vector3 scale, bool active);
    ~SeaCreature();

	Vector3 cohesion(Vector3 playerpos, Vector3 playertarget);
	Vector3 seperation(Vector3 repelVector);
	Vector3 alignment(Vector3 forceVector);

    int getHealth();

	void setPos(Vector3 pos);
    void setHealth(int m_health);

    hitbox2 collision;
};

#endif