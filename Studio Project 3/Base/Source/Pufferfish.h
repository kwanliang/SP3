#ifndef PUFFERFISH_H
#define PUFFERFISH_H

#include "SeaCreature.h"

class Pufferfish : public SeaCreature
{
public:
    Pufferfish();
    ~Pufferfish();

    void expand();
};

#endif