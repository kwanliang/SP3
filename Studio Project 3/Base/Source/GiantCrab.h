#pragma once
#include "Boss.h"
#include "GiantCrab_Pincers.h"

class GiantCrab : public Boss
{
public:
	GiantCrab();
	~GiantCrab();

	enum CrabState
	{
		STATE_IDLE = 0,
		STATE_MOVE,
		STATE_ATTACK,
		STATE_GRAB,
		STATE_AGGRESSIVE,
	};

	CrabState GetState() const;
	void SetState(const CrabState &state);

	GiantCrab_Pincers pincers[2];

private:
	CrabState state;
};