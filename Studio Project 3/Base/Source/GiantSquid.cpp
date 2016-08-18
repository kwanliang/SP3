#include "GiantSquid.h"

GiantSquid::GiantSquid()
    : state(IDLE)
    , Boss(0, GIANTSQUID, BOSS, Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(1, 1, 1), false)
{

}

GiantSquid::GiantSquid(float m_bounceTime, bool m_isBounceUp, GIANTSQUID_BEHAVIORSTATE state, int m_health, BOSS_TYPE bossType, OBJECT_TYPE objectType, Vector3 pos, Vector3 vel, Vector3 scale, bool active)
    : state(state)
    , Boss(m_health, bossType, objectType, pos, vel, scale, active)
{

}

GiantSquid::~GiantSquid()
{

}

void GiantSquid::Animate()
{
    if (rotateTentacle < 45.f && !isTentacleUp)
        rotateTentacle += 0.5f;
    else
        isTentacleUp = true;

    if (rotateTentacle > 0.f && isTentacleUp)
        rotateTentacle -= 0.5f;
    else
        isTentacleUp = false;


    if (translateSquid > -90.f && !isSquidUp)
    {
        this->pos.y -= 1.f;
        translateSquid -= 1.f;
        this->collision.m_position.y -= 1.f;
    }
    else
        isSquidUp = true;

    if (translateSquid < 0.f && isSquidUp)
    {
        this->pos.y += 1.f;
        translateSquid += 1.f;
        this->collision.m_position.y += 1.f;
    }
    else
        isSquidUp = false;

    tentacle1_1.setTentacleAnimateRotate(rotateTentacle);
    tentacle1_2.setTentacleAnimateRotate(rotateTentacle);
    tentacle1_3.setTentacleAnimateRotate(rotateTentacle);
    tentacle1_4.setTentacleAnimateRotate(rotateTentacle);

    tentacle2_1.setTentacleAnimateRotate(rotateTentacle);
    tentacle2_2.setTentacleAnimateRotate(rotateTentacle);
    tentacle2_3.setTentacleAnimateRotate(rotateTentacle);
    tentacle2_4.setTentacleAnimateRotate(rotateTentacle);

    tentacle3_1.setTentacleAnimateRotate(rotateTentacle);
    tentacle3_2.setTentacleAnimateRotate(rotateTentacle);
    tentacle3_3.setTentacleAnimateRotate(rotateTentacle);
    tentacle3_4.setTentacleAnimateRotate(rotateTentacle);

    tentacle4_1.setTentacleAnimateRotate(rotateTentacle);
    tentacle4_2.setTentacleAnimateRotate(rotateTentacle);
    tentacle4_3.setTentacleAnimateRotate(rotateTentacle);
    tentacle4_4.setTentacleAnimateRotate(rotateTentacle);

    tentacle5_1.setTentacleAnimateRotate(rotateTentacle);
    tentacle5_2.setTentacleAnimateRotate(rotateTentacle);
    tentacle5_3.setTentacleAnimateRotate(rotateTentacle);
    tentacle5_4.setTentacleAnimateRotate(rotateTentacle);

    tentacle6_1.setTentacleAnimateRotate(rotateTentacle);
    tentacle6_2.setTentacleAnimateRotate(rotateTentacle);
    tentacle6_3.setTentacleAnimateRotate(rotateTentacle);
    tentacle6_4.setTentacleAnimateRotate(rotateTentacle);
}

Mtx44 GiantSquid::LookAtPlayer(Vector3 playerPos)
{
    Vector3 view(0, 0, 0);
    view = (playerPos - this->pos).Normalized();
    Mtx44 rotate;
    rotate.SetToRotation(Math::RadianToDegree(atan2(view.z, view.x)), 0, 1, 0);

    return rotate;
}