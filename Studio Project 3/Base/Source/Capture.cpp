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



Vector3 Capture::Vacuum(SeaCreature creature, WalkCamera camera, double dt)//, gameobject)
{
	if (true)//if (	(camera.GetEye() - camera.GetPos()) == ((camera.GetPos() - objectposition)*-1)//camera.target * range && gameobject == creature
	{
		//translate creature pos towards player position
		
			Vector3 view = (creature.pos - camera.GetPos()).Normalized();
			if (creature.pos.x - camera.GetPos().x >= 1)
			{
				creature.setPos(Vector3((creature.pos.x - (view.x / fabs(creature.pos.x - camera.GetPos().x)*500/creature.getHealth())), (creature.pos.y), (creature.pos.z)));
			}
			if (creature.pos.y - camera.GetPos().y >= 1)
			{
				creature.setPos(Vector3(creature.pos.x, (creature.pos.y - (view.y / fabs(creature.pos.y - camera.GetPos().y) * 500 / creature.getHealth())), (creature.pos.z)));
			}
			if (creature.pos.z - camera.GetPos().z >= 1)
			{
				creature.setPos(Vector3(creature.pos.x, (creature.pos.y), (creature.pos.z - (view.z / fabs(creature.pos.z - camera.GetPos().z) * 500 / creature.getHealth()))));
			}
		
		AddSquad(camera,creature);
	}	
	return creature.pos;
}

void Capture::AddSquad(WalkCamera camera, SeaCreature creature)//, gameobject)
{
	if (camera.GetPos() == creature.pos)
	{
		if (creature.pos.x - camera.GetPos().x <= 1 && creature.pos.y - camera.GetPos().y <= 1 && creature.pos.z - camera.GetPos().z <= 1)
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