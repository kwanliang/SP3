#ifndef PUFFERFISH_H
#define PUFFERFISH_H

#include "SeaCreature.h"

class Pufferfish : public SeaCreature
{
public:
    Pufferfish();
	Pufferfish(Vector3 pos);
    ~Pufferfish();

    void expand();

private:
	
};

#endif