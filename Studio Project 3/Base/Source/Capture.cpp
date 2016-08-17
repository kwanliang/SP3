#include "Capture.h"
#include <math.h>


Capture::Capture()
{
	/*hitpoints = 50;
	Type = FISHTYPE;
	position= (Vector3(0,0,0));*/
}


Capture::~Capture()
{
}



Vector3 Capture::Vacuum(SeaCreature creature, Vector3 playerpos, double dt)
{
	if (true)//if (	(camera.GetEye() - camera.GetPos()) == ((camera.GetPos() - objectposition)*-1)//camera.target * range && gameobject == creature
	{
		//translate creature pos towards player position
		
			Vector3 view = (creature.pos - playerpos).Normalized();
			if (fabs(creature.pos.x - playerpos.x) >= 1)
			{
				creature.setPos(Vector3((creature.pos.x - (view.x / fabs(creature.pos.x - playerpos.x)*500/creature.getHealth())), (creature.pos.y), (creature.pos.z)));
			}
			if (fabs(creature.pos.y - playerpos.y) >= 1)
			{
				creature.setPos(Vector3(creature.pos.x, (creature.pos.y - (view.y / fabs(creature.pos.y - playerpos.y) * 500 / creature.getHealth())), (creature.pos.z)));
			}
			if (fabs(creature.pos.z - playerpos.z) >= 1)
			{
				creature.setPos(Vector3(creature.pos.x, (creature.pos.y), (creature.pos.z - (view.z / fabs(creature.pos.z - playerpos.z) * 500 / creature.getHealth()))));
			}
		
		AddSquad(playerpos,creature);
	}	
	return creature.pos;
}

void Capture::AddSquad(Vector3 playerpos, SeaCreature creature)//, gameobject)
{
	if (playerpos == creature.pos)
	{
		if (creature.pos.x - playerpos.x <= 1 && creature.pos.y - playerpos.y <= 1 && creature.pos.z - playerpos.z <= 1)
		{
			std::cout << "true" << std::endl;
		}
		//SquadSize.push_back(temp);
		//std::cout << GetSquadSize() << std::endl;
	}

}


//int Capture::GetSquadSize()
//{
//	return SquadSize.size();
//}

//void Capture::SetType(Capture::fish type)
//{
//	this->Type = type;
//}
//
//Capture::fish Capture::Gettype()
//{
//	return this->Type;
//}
//
//void Capture::SetPos(Vector3 pos)
//{
//	this->position = pos;
//}
//
//Vector3 Capture::GetPos()
//{
//	return this->position;
//}
//
//float Capture::GetHP()
//{
//	return this->hitpoints;
//}
//
//void Capture::SetPercent(float percentage)
//{
//	this->CapturePercent = percentage;
//}
//
//
//float Capture::GetPercent()
//{
//	return this->CapturePercent;
//}