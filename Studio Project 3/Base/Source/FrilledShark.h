#ifndef FRILLEDSHARK_H
#define	FRILLEDSHARK_H


#include "Boss.h"


class FrilledShark :public Boss
{
public:
	struct FSnode
	{
		Vector3 pos;
		float yaw = 0;
		float pitch = 0;

	};


	FrilledShark();
	FrilledShark(int m_health ,  BOSS_TYPE bossType, 
					Vector3 pos, Vector3 vel, Vector3 scale, bool active);
	~FrilledShark();
	
	void UpdateFrilledShark(double);


	FSnode m_node[5];

	

private:










};













#endif;