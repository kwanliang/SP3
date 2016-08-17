#ifndef SCENE_UTORIAL_H
#define SCENE_TUTORIAL_H

#include "SceneSP3.h"
#include <vector>
#include "Mtx44.h"


class SceneTutorial : public SceneSP3
{
public:
	SceneTutorial();
	~SceneTutorial();

	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();
	void RenderPassGPass();
	void RenderPassMain();

	void RenderWorld();
	void RenderTerrain();
	void RenderSkyPlane();
	void RenderParticles();



private:

    // Shadow
	
 


   // Light lights[2];

    bool bLightEnabled;

    float fps;

    //Terrain
    std::vector<unsigned char> m_heightMap;

    // Particles 
    std::vector<ParticleObject*> particleList; // Used to store
    Vector3 m_gravity;      // Gravity affecting the particles
    int m_particleCount;    // Number of particles




	//Fish test
	Capture fishy;

};








#endif