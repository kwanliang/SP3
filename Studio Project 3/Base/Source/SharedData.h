#ifndef SHARED_DATA_H
#define SHARED_DATA_H

#include "Vector3.h"

class SharedData
{
public:
    static SharedData* GetInstance()
    {
        static SharedData data;
        return &data;
    }

    Vector3 PlayerPos;

private:
    SharedData(){};
};

#endif