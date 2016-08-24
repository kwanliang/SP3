#include "GiantCrab.h"

GiantCrab::GiantCrab()
	: state(GiantCrab::STATE_IDLE)
{

}

GiantCrab::~GiantCrab()
{

}

GiantCrab::CrabState GiantCrab::GetState() const
{
	return state;
}

void GiantCrab::SetState(const GiantCrab::CrabState &state)
{
	this->state = state;
}