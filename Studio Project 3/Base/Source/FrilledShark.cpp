#include "FrilledShark.h"

FrilledShark::FrilledShark()
{
	m_health = 1000;
	bossType = FRILLEDSHARK;
	pos = Vector3(0, 900, 0);
	vel = (0, 0, 0);
	scale = Vector3(50, 50, 50);
	active = true;
	m_node[0].pos = pos;

	m_node[1].pos = m_node[0].pos;
	m_node[1].pos.z = m_node[0].pos.z - 140;

	for (unsigned i = 2; i < 4; i++)
	{
		m_node[i].pos = m_node[i-1].pos;
		m_node[i].pos.z = m_node[i - 1].pos.z -80;

	}

	m_node[4].pos = m_node[3].pos;
	m_node[4].pos.z = m_node[3].pos.z;

}

FrilledShark::FrilledShark(int m_health,BOSS_TYPE bossType,
Vector3 pos, Vector3 vel, Vector3 scale, bool active)
{
	m_health = 1000;
	bossType = FRILLEDSHARK;
	pos = (0, 400, 0);
	vel = (0, 0, 0);
	scale = (50, 50, 50);
	active = true;
}



void FrilledShark::UpdateFrilledShark(double dt)
{


	Vector3 direction = Vector3(Math::RadianToDegree(cos(Math::DegreeToRadian(-m_node[0].yaw+90))), 0, Math::RadianToDegree(sin(Math::DegreeToRadian(-m_node[0].yaw+90))));//get vel from direction head is facing
	vel = direction.Normalized() * 10;//update belocity



	float zhead = Math::RadianToDegree(sin(Math::DegreeToRadian(-m_node[0].yaw + 90)))*0.65 ;
	float xhead = Math::RadianToDegree(cos(Math::DegreeToRadian(-m_node[0].yaw + 90)))*0.65;

	//std::cout << y << std::endl;
	//std::cout << x << std::endl;
	m_node[1].pos.x = m_node[0].pos.x  - xhead;
	m_node[1].pos.z = m_node[0].pos.z - zhead;

	for (unsigned i = 1 ; i < 5; i++)
	{

		if (m_node[i - 1].yaw - m_node[i].yaw < -15)
			m_node[i].yaw -= dt * 30;
		else if (m_node[i - 1].yaw -m_node[i].yaw > 15)
			m_node[i].yaw += dt * 30;
		

		//if (m_node[i - 1].yaw != m_node[i].yaw)
		//{
		//	if (m_node[i - 1].yaw < m_node[i].yaw )
		//	m_node[i].yaw -= dt * 5;
		//	else if (m_node[i - 1].yaw > m_node[i].yaw)
		//	m_node[i].yaw += dt * 5;

		//}

		if (i == 1)
			continue;

		float z_com = Math::RadianToDegree(sin(Math::DegreeToRadian(-m_node[i-1].yaw + 90)))*1.6;
		float x_com = Math::RadianToDegree(cos(Math::DegreeToRadian(-m_node[i-1].yaw + 90)))*1.6;

		m_node[i].pos.x = m_node[i - 1].pos.x - x_com;
		m_node[i].pos.z = m_node[i - 1].pos.z - z_com;

	}






	
	//pos += vel*dt;
	m_node[0].pos += vel*dt;


}