#include "Chimera.h"

Chimera::Chimera()
{
	SeaCreature(0, CHIMERA, SEACREATURE, Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(1, 1, 1), false);
	rotate = Math::RandFloatMinMax(-20, 20);
	chstate = IDLE;
}

Chimera::Chimera(Vector3 pos)
{
	SeaCreature(0, CHIMERA, SEACREATURE, pos, Vector3(0, 0, 0), Vector3(1, 1, 1), false);
	flip[0].rotation = 20;
	flip[1].rotation = 27;
	flip[2].rotation = 10;
	rotate = Math::RandFloatMinMax(-20, 20);
	chstate = IDLE;
}

Chimera::~Chimera()
{

}

void Chimera::UpdateChimera(double dt)
{
	switch (chstate)
	{
	case (IDLE):
	{
		rotate += 15 * dt;
		//std::cout << rotate << std::endl;
		Vector3 direction = Vector3(Math::RadianToDegree(cos(Math::DegreeToRadian(rotate + 90))), Math::Clamp(vel.y, 0.f, 20.f), Math::RadianToDegree(sin(Math::DegreeToRadian(rotate + 90))));
		vel = direction.Normalized() * 80;
	}




	}
	

	if (pos.y > 700)//height limit
	{
		pos.y -= 5;
		vel.y = -vel.y;
	}





	//animation
	for (unsigned i = 0; i < 4; ++i)
	{
		if (!flip[i].flipper_max)
		{
			if (flip[i].rotation < 40)
				flip[i].rotation += 100 * dt;
			else
				flip[i].flipper_max = true;
		}
		else
		{

			if (flip[i].rotation > -40)
				flip[i].rotation -= 100 * dt;
			else
				flip[i].flipper_max = false;
		}
	}

	
	pos += vel*dt;
}