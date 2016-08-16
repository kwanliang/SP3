#ifndef CAPTURE_H_
#define CAPTURE_H_

#include "Camera3.h"
#include "WalkCamera.h"
#include "SharedData.h"

#include <vector>

class Capture
{
public:
	Capture();
	~Capture();

	enum fish
	{
		FISHTYPE = 0,
		FISH
	};

	static Vector3 Vacuum(Capture fish, WalkCamera camera, double dt);//gameobject);
	static void AddSquad(WalkCamera camera, Capture fish);//gameobject);
	
	void SetType(fish type);
	void SetPos(Vector3 pos);
	void SetPercent(float percentage);

	float GetPercent();
	float GetHP();
	Vector3 GetPos();
	fish Gettype();
	static int GetSquadSize();
private:
	float CapturePercent;
	static float range;
	fish Type;
	Vector3 position;
	float hitpoints;
};

#endif