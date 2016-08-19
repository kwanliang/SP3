/******************************************************************************/
/*!
\file	GiantSquid.h
\author Lee Kwan Liang
\par	email: 155117G@mymail.nyp.edu.sg
\brief
Class to define boss, Giant Squid
*/
/******************************************************************************/

#include "GiantSquid.h"

/******************************************************************************/
/*!
\brief
GiantSquid default constructor
*/
/******************************************************************************/

GiantSquid::GiantSquid()
    : state(IDLE)
    , Boss(0, GIANTSQUID, BOSS, Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(1, 1, 1), false)
{

}

/******************************************************************************/
/*!
\brief
GiantSquid overloaded constructor
*/
/******************************************************************************/

GiantSquid::GiantSquid(float m_bounceTime, bool m_isBounceUp, GIANTSQUID_BEHAVIORSTATE state, int m_health, BOSS_TYPE bossType, OBJECT_TYPE objectType, Vector3 pos, Vector3 vel, Vector3 scale, bool active)
    : state(state)
    , Boss(m_health, bossType, objectType, pos, vel, scale, active)
{

}

/******************************************************************************/
/*!
\brief
GiantSquid default deconstructor
*/
/******************************************************************************/

GiantSquid::~GiantSquid()
{

}

void GiantSquid::AnimateIdle()
{
    if (!m_animateATTACK)
    {
        if (m_rotateTentacle < 45.f && !m_isTentacleUp)
            m_rotateTentacle += 0.5f;
        else
            m_isTentacleUp = true;

        if (m_rotateTentacle > 0.f && m_isTentacleUp)
            m_rotateTentacle -= 0.5f;
        else
            m_isTentacleUp = false;


        if (m_translateSquid > -90.f && !m_isSquidUp)
        {
            this->pos.y -= 1.f;
            m_translateSquid -= 1.f;
            this->collision.m_position.y -= 1.f;
            this->tentacle1_1.collision.m_position.y -= 1.f;
            this->tentacle1_2.collision.m_position.y -= 1.f;
            this->tentacle1_3.collision.m_position.y -= 1.f;
            this->tentacle1_4.collision.m_position.y -= 1.f;
        }
        else
            m_isSquidUp = true;

        if (m_translateSquid < 0.f && m_isSquidUp)
        {
            this->pos.y += 1.f;
            m_translateSquid += 1.f;
            this->collision.m_position.y += 1.f;
            this->tentacle1_1.collision.m_position.y += 1.f;
            this->tentacle1_2.collision.m_position.y += 1.f;
            this->tentacle1_3.collision.m_position.y += 1.f;
            this->tentacle1_4.collision.m_position.y += 1.f;
        }
        else
        {
            m_isSquidUp = false;
            this->m_animateIDLE = false;
        }

        tentacle1_1.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle1_2.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle1_3.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle1_4.setTentacleAnimateRotate(m_rotateTentacle);

        tentacle2_1.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle2_2.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle2_3.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle2_4.setTentacleAnimateRotate(m_rotateTentacle);

        tentacle3_1.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle3_2.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle3_3.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle3_4.setTentacleAnimateRotate(m_rotateTentacle);

        tentacle4_1.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle4_2.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle4_3.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle4_4.setTentacleAnimateRotate(m_rotateTentacle);

        tentacle5_1.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle5_2.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle5_3.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle5_4.setTentacleAnimateRotate(m_rotateTentacle);

        tentacle6_1.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle6_2.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle6_3.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle6_4.setTentacleAnimateRotate(m_rotateTentacle);
    }
}

void GiantSquid::AnimateAttack()
{
    if (!m_animateIDLE)
    {
        if (m_rotateTentacle < 45.f && !m_isTentacleUp)
            m_rotateTentacle += 0.5f;
        else
            m_isTentacleUp = true;


        if (m_rotateSquid < 720.f && m_isTentacleUp && !m_rotateComplete)
            m_rotateSquid += 10.f;
        else
        {
            m_rotateComplete = true;
            m_rotateSquid = 0.f;
        }

        if (m_rotateTentacle > 0.f && m_isTentacleUp && m_rotateComplete)
            m_rotateTentacle -= 0.5f;
        else
        {
            m_isTentacleUp = false;
            m_rotateComplete = false;
            this->m_animateATTACK = false;
        }

        tentacle1_1.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle1_2.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle1_3.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle1_4.setTentacleAnimateRotate(m_rotateTentacle);

        tentacle2_1.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle2_2.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle2_3.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle2_4.setTentacleAnimateRotate(m_rotateTentacle);

        tentacle3_1.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle3_2.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle3_3.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle3_4.setTentacleAnimateRotate(m_rotateTentacle);

        tentacle4_1.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle4_2.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle4_3.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle4_4.setTentacleAnimateRotate(m_rotateTentacle);

        tentacle5_1.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle5_2.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle5_3.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle5_4.setTentacleAnimateRotate(m_rotateTentacle);

        tentacle6_1.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle6_2.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle6_3.setTentacleAnimateRotate(m_rotateTentacle);
        tentacle6_4.setTentacleAnimateRotate(m_rotateTentacle);
    }
}

float GiantSquid::LookAtPlayer(Vector3 playerPos)
{
    Vector3 initView(-1, 0, 0);
    Vector3 wantView(playerPos - this->pos);
    Vector3 normal(0, 1, 0);

    if (this->pos != (0, 0, 0))
        wantView.Normalize();

    this->m_SquidView = Math::RadianToDegree(acos(initView.Dot(wantView)));
    Vector3 Crossed = initView.Cross(wantView);
    if (Crossed.Dot(normal) < 0)
    {
        this->m_SquidView *= -1;
    }
    return m_SquidView;
}

void GiantSquid::ChasePlayer(Vector3 playerPos)
{
    std::cout << m_isTentacleUp << m_rotateComplete << std::endl;
    Vector3 DirVec = playerPos - this->pos;
    if (playerPos != this->pos && !DirVec.IsZero())
    {
        DirVec.Normalize();
        if ((playerPos - this->pos).LengthSquared() > distFromPlayer * distFromPlayer)
        {
            if (m_isTentacleUp && !m_rotateComplete)
            {
                this->pos += DirVec * 2.f;
                this->collision.m_position += DirVec * 2.f;
            }
            else
            {
                this->pos += DirVec * .5f;
                this->collision.m_position += DirVec * .5f;
            }
        }
    }
}

float GiantSquid::getSquidView()
{
    return this->m_SquidView;
}

void GiantSquid::setSquidView(float m_SquidView)
{
    this->m_SquidView = m_SquidView;
}