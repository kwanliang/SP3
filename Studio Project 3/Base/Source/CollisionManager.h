#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "Vector3.h"
#include <vector>
#include "LoadHmap.h"


struct hitbox{
	Vector3 m_position;
	Vector3 m_vecMax;
	Vector3 m_vecMin;

	Vector3 m_velocity;

	float m_height;
	float m_length;
	float m_width;

	static hitbox generatehitbox(Vector3 minValue, Vector3 maxValue){		
		
		hitbox NewBox;
		NewBox.m_vecMin = minValue;
		NewBox.m_vecMax = maxValue;
		return NewBox;
	}

	static hitbox generatehitbox(Vector3 pos, float length, float height, float width, Vector3 objectVelocity){	
		
		hitbox NewBox;

		NewBox.m_position = pos;

		NewBox.m_velocity = objectVelocity;

		NewBox.m_length = length;
		NewBox.m_height = height;
		NewBox.m_width = width;

		NewBox.m_vecMin = Vector3(
			pos.x - (length * 0.5),
			pos.y - (height * 0.5), 
			pos.z - (width * 0.5)
			);
		NewBox.m_vecMax = Vector3(
			pos.x + (length * 0.5), 
			pos.y + (height * 0.5), 
			pos.z + (width * 0.5)
			);

		return NewBox;
	}

	static void updatehitbox(hitbox &box,Vector3 newpos){

		box.m_position = newpos;

		box.m_vecMin = Vector3(
			(box.m_position.x - (box.m_length * 0.5)),
			(box.m_position.y - (box.m_height * 0.5)),
			(box.m_position.z - (box.m_width * 0.5))
			);

		box.m_vecMax = Vector3(
			(box.m_position.x + (box.m_length * 0.5)),
			(box.m_position.y + (box.m_height * 0.5)),
			(box.m_position.z + (box.m_width * 0.5))
			);
	}
};
static bool collision(const hitbox& lhsBox, const hitbox& rhsBox){		//for AABB to AABB collision
	//Check if lhsBox's max is greater than rhsBox's min and lhsBox's min is less than rhsBox's max
	if (lhsBox.m_vecMax.x > rhsBox.m_vecMin.x &&
		lhsBox.m_vecMin.x < rhsBox.m_vecMax.x &&
		lhsBox.m_vecMax.y > rhsBox.m_vecMin.y &&
		lhsBox.m_vecMin.y < rhsBox.m_vecMax.y &&
		lhsBox.m_vecMax.z > rhsBox.m_vecMin.z &&
		lhsBox.m_vecMin.z < rhsBox.m_vecMax.z){
		return true;
	}
	else
		return false;
}
static bool collision(const hitbox& hitbox, const Vector3& vecPoint){

	//Check if the point is less than max and greater than min
	if (vecPoint.x > hitbox.m_vecMin.x && vecPoint.x < hitbox.m_vecMax.x &&
		vecPoint.y > hitbox.m_vecMin.y && vecPoint.y < hitbox.m_vecMax.y &&
		vecPoint.z > hitbox.m_vecMin.z && vecPoint.z < hitbox.m_vecMax.z){
		return true;
	}
	else
		return false;

}

struct hitbox2{
	Vector3 m_position;

	Vector3 m_point[8];

	float m_height;
	float m_length;
	float m_width;



	static hitbox2 generatehitbox(Vector3 pos, float length, float height, float width)
	{

		hitbox2 NewBox;

		NewBox.m_position = pos;


		NewBox.m_length = length;
		NewBox.m_height = height;
		NewBox.m_width = width;

		NewBox.m_point[0] = Vector3(pos.x - (length * 0.5), pos.y - (height * 0.5), pos.z - (width * 0.5));
		NewBox.m_point[1] = Vector3(pos.x + (length * 0.5), pos.y - (height * 0.5), pos.z - (width * 0.5));
		NewBox.m_point[2] = Vector3(pos.x + (length * 0.5), pos.y - (height * 0.5), pos.z + (width * 0.5));
		NewBox.m_point[3] = Vector3(pos.x - (length * 0.5), pos.y - (height * 0.5), pos.z + (width * 0.5));

		NewBox.m_point[4] = Vector3(pos.x - (length * 0.5), pos.y + (height * 0.5), pos.z - (width * 0.5));
		NewBox.m_point[5] = Vector3(pos.x + (length * 0.5), pos.y + (height * 0.5), pos.z - (width * 0.5));
		NewBox.m_point[6] = Vector3(pos.x + (length * 0.5), pos.y + (height * 0.5), pos.z + (width * 0.5));
		NewBox.m_point[7] = Vector3(pos.x - (length * 0.5), pos.y + (height * 0.5), pos.z + (width * 0.5));
		return NewBox;
	}

	static void updatehitbox(hitbox2 &box, Vector3 newpos)
	{
		Vector3 displacement = box.m_position - newpos;

		box.m_position = newpos;

		for (unsigned i = 0; i < 8; i++)
		{
			box.m_point[i] -= displacement;

		}


	}

};



static bool terraincollision(const hitbox2& hitbox, std::vector<unsigned char> heightmap){



	for (unsigned i = 0; i < 8; i++)
	{
		float height = (350.f * ReadHeightMap(heightmap, hitbox.m_point[i].x / 3000.f, hitbox.m_point[i].z / 3000.f));

		if (hitbox.m_point[i].y < height)
			return true;
	}
	return false;


}































#endif;

//Updated 22/2/2016 - Randall
//Updated 8/15/2016 - Yue xian