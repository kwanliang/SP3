#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Vector3.h"

struct GameObject
{
    enum OBJECT_TYPE
    {
        PLAYER,
        SEACREATURE,
        PROJECTILE,

        TYPE_TOTAL
    };
    OBJECT_TYPE objectType;

	Vector3 pos;
	Vector3 vel;
	Vector3 scale;
	bool active;

    GameObject();
    GameObject(OBJECT_TYPE objectType, Vector3 pos, Vector3 vel, Vector3 scale, bool active);
	~GameObject();
};

#endif