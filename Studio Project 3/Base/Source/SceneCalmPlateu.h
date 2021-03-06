#ifndef SCENE_CALMPLATEU_H
#define SCENE_CALMPLATEU_H

#include "SceneSP3.h"
#include <vector>
#include "Mtx44.h"
#include "Pufferfish.h"
#include "CollisionManager.h"
class SceneCalmPlateu : public SceneSP3
{
public:
	SceneCalmPlateu();
	~SceneCalmPlateu();

	virtual void Init();
	virtual void Update(double dt);
	virtual void Exit();
	
	virtual void Render();
	void RenderPassGPass();
	void RenderPassMain();
	void RenderMinimap();

	void RenderWorld();
	void RenderTerrain();
	void RenderSkyPlane();
	void RenderParticles();
	void RenderPuffer(Pufferfish *fo);

	Pufferfish* FetchPuffer();
	void UpdatePuffer(double dt);

private:

    // Shadow
	
   // Light lights[2];

    bool bLightEnabled;

   // float fps;

    //Terrain
    //std::vector<unsigned char> m_heightMap;

    // Particles 
    std::vector<ParticleObject*> particleList; // Used to store
    Vector3 m_gravity;      // Gravity affecting the particles
    int m_particleCount;    // Number of particles




	//Fish test
	Capture fishy;

};








#endif