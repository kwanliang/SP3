#ifndef GIANTSQUID_H
#define GIANTSQUID_H

#include "Boss.h"
#include "Mtx44.h"
#include "GiantSquidTentacle.h"

class GiantSquid : public Boss
{
private:


public:
    enum GIANTSQUID_BEHAVIORSTATE
    {
        IDLE,
        MOVEUP,
        MOVEDOWN,
        ATTACK,
        INK,

        STATE_TOTAL,
    };
    GIANTSQUID_BEHAVIORSTATE state;

    // Animation
    float rotateTentacle;
    bool isTentacleUp;

    float translateSquid;
    bool isSquidUp;

    GiantSquid();
    GiantSquid(float m_bounceTime, bool m_isBounceUp, GIANTSQUID_BEHAVIORSTATE state, int m_health, BOSS_TYPE bossType, OBJECT_TYPE objectType, Vector3 pos, Vector3 vel, Vector3 scale, bool active);
    ~GiantSquid();

    void Animate();
    Mtx44 LookAtPlayer(Vector3 playerPos);

    GiantSquidTentacle tentacle1_1;
    GiantSquidTentacle tentacle1_2;
    GiantSquidTentacle tentacle1_3;
    GiantSquidTentacle tentacle1_4;

    GiantSquidTentacle tentacle2_1;
    GiantSquidTentacle tentacle2_2;
    GiantSquidTentacle tentacle2_3;
    GiantSquidTentacle tentacle2_4;

    GiantSquidTentacle tentacle3_1;
    GiantSquidTentacle tentacle3_2;
    GiantSquidTentacle tentacle3_3;
    GiantSquidTentacle tentacle3_4;

    GiantSquidTentacle tentacle4_1;
    GiantSquidTentacle tentacle4_2;
    GiantSquidTentacle tentacle4_3;
    GiantSquidTentacle tentacle4_4;

    GiantSquidTentacle tentacle5_1;
    GiantSquidTentacle tentacle5_2;
    GiantSquidTentacle tentacle5_3;
    GiantSquidTentacle tentacle5_4;

    GiantSquidTentacle tentacle6_1;
    GiantSquidTentacle tentacle6_2;
    GiantSquidTentacle tentacle6_3;
    GiantSquidTentacle tentacle6_4;
};

#endif