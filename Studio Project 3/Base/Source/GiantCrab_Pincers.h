#pragma once

#include "Vector3.h"
#include "CollisionManager.h"

class GiantCrab_Pincers
{
private:

public:
	GiantCrab_Pincers();
	~GiantCrab_Pincers();

	float animationTime;

	float GetAnimationVal();
};