#include "Capture.h"
#include <math.h>


Capture::Capture()
{
	hitpoints = 50;
	Type = FISHTYPE;
	position= (Vector3(0,0,0));
}


Capture::~Capture()
{
}



Vector3 Capture::Vacuum(Capture fish, WalkCamera camera, double dt)//, gameobject)
{
	if (true)//if (	(camera.GetEye() - camera.GetPos()) == ((camera.GetPos() - objectposition)*-1)//camera.target * range && gameobject == fish
	{
		//translate fish pos towards player position 
		
			Vector3 view = (fish.GetPos() - camera.GetPos()).Normalized();
			if (fish.GetPos().x - camera.GetPos().x >= 1)
			{
				fish.SetPos(Vector3((fish.GetPos().x - (view.x / fabs(fish.GetPos().x - camera.GetPos().x)*500/fish.GetHP())), (fish.GetPos().y), (fish.GetPos().z)));
			}
			if (fish.GetPos().y - camera.GetPos().y >= 1)
			{
				fish.SetPos(Vector3(fish.GetPos().x, (fish.GetPos().y - (view.y / fabs(fish.GetPos().y - camera.GetPos().y) * 500 / fish.GetHP())), (fish.GetPos().z)));
			}
			if (fish.GetPos().z - camera.GetPos().z >= 1)
			{
				fish.SetPos(Vector3(fish.GetPos().x, (fish.GetPos().y), (fish.GetPos().z - (view.z / fabs(fish.GetPos().z - camera.GetPos().z) * 500 / fish.GetHP()))));
			}
		
		//AddSquad(camera);
	}	
	return fish.GetPos();
}

void Capture::AddSquad(WalkCamera camera, Capture fish)//, gameobject)
{
	if (camera.GetPos() == fish.GetPos())
	{
		std::cout << "true" << std::endl;
		//SquadSize.push_back(temp);
		//std::cout << GetSquadSize() << std::endl;
	}

}


//int Capture::GetSquadSize()
//{
//	return SquadSize.size();
//}

void Capture::SetType(Capture::fish type)
{
	this->Type = type;
}

Capture::fish Capture::Gettype()
{
	return this->Type;
}

void Capture::SetPos(Vector3 pos)
{
	this->position = pos;
}

Vector3 Capture::GetPos()
{
	return this->position;
}

float Capture::GetHP()
{
	return this->hitpoints;
}

void Capture::SetPercent(float percentage)
{
	this->CapturePercent = percentage;
}


float Capture::GetPercent()
{
	return this->CapturePercent;
}