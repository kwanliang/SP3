#ifndef CAPTURE_H_
#define CAPTURE_H_

#include "Camera3.h"
#include "WalkCamera.h"
#include "SeaCreature.h"

#include <vector>

class Capture
{
public:
	Capture();
	~Capture();

	static Vector3 Vacuum(SeaCreature creature, WalkCamera camera, double dt);//gameobject);
	static void AddSquad(WalkCamera camera, SeaCreature creature);//gameobject);
	
	/*void SetType(SeaCreature creature);
	void SetPos(Vector3 pos);
	void SetPercent(float percentage);*/

	/*float GetPercent();
	float GetHP();
	Vector3 GetPos();
	fish Gettype();*/
	static int GetSquadSize();
private:
	static float range;
	/*float CapturePercent;
	fish Type;
	Vector3 position;
	float hitpoints;*/
};

#endif