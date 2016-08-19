/******************************************************************************/
/*!
\file	GiantSquid.h
\author Lee Kwan Liang
\par	email: 155117G@mymail.nyp.edu.sg
\brief
Class to define boss, Giant Squid
*/
/******************************************************************************/

#ifndef GIANTSQUID_H
#define GIANTSQUID_H

#include "Boss.h"
#include "Mtx44.h"
#include "GiantSquidTentacle.h"

static float distFromPlayer = 100.f;

/******************************************************************************/
/*!
Class GiantSquid:
\brief
Defines the Boss and its methods
*/
/******************************************************************************/

class GiantSquid : public Boss
{
private:
    float m_SquidView;

public:
    enum GIANTSQUID_BEHAVIORSTATE
    {
        IDLE,
        ATTACK,
        INK,

        STATE_TOTAL,
    };
    GIANTSQUID_BEHAVIORSTATE state;

    // Animation
    float m_rotateTentacle;
    bool m_isTentacleUp;

    float m_translateSquid;
    bool m_isSquidUp;

    float m_rotateSquid;
    bool m_rotateComplete;

    bool m_animateIDLE;
    bool m_animateATTACK;

    GiantSquid();
    GiantSquid(float m_bounceTime, bool m_isBounceUp, GIANTSQUID_BEHAVIORSTATE state, int m_health, BOSS_TYPE bossType, OBJECT_TYPE objectType, Vector3 pos, Vector3 vel, Vector3 scale, bool active);
    ~GiantSquid();

    void AnimateIdle();
    void AnimateAttack();
    float LookAtPlayer(Vector3 playerPos);
    void ChasePlayer(Vector3 playerPos);

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

    float getSquidView();
    void setSquidView(float m_SquidView);
};

#endif