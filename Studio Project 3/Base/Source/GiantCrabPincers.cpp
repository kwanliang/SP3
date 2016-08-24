#include "GiantCrab_Pincers.h"

GiantCrab_Pincers::GiantCrab_Pincers() : animationTime(0)
{

}

GiantCrab_Pincers::~GiantCrab_Pincers()
{

}

float GiantCrab_Pincers::GetAnimationVal()
{
	return sin(animationTime);
}