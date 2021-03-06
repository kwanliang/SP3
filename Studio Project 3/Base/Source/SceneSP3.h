#ifndef SCENE_SP3_H
#define SCENE_SP3_H

#include <vector>
#include "Scene.h"
#include "Mtx44.h"
#include "Camera3.h"
#include "CameraV2.h"
#include "WalkCamera.h"
#include "Mesh.h"
#include "MatrixStack.h"
#include "Light.h"
#include "Particle.h"
#include "DepthFBO.h"
#include "CollisionManager.h"
#include "Minnow.h"
#include "Projectile.h"
#include "Capture.h"
#include "SharedData.h"
#include "LoadHmap.h"
#include "Skipper.h"

static int g_MinnowLeaderCount = 0;
static int g_MinnowCount = 0;

class SceneSP3 : public Scene
{
 
public:
    SceneSP3();
    virtual ~SceneSP3();

    virtual void Init();
    virtual void Update(double dt);
    virtual void Render();
    virtual void Exit();

	virtual void RenderPassGPass() = 0;
    virtual void RenderPassMain() = 0;
    virtual void RenderWorld() = 0;
	virtual void RenderMinimap();

	void UpdateTravel();
    void UpdateLoop(double dt);
	void UpdatePuffer(double dt);
	void UpdateCaptured(double dt);
	void UpdateProjectile(double dt);
	void UpdateSquadFire(double dt);

    void RenderText(Mesh* mesh, std::string text, Color color);
    void RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y);
    void RenderMeshIn2D(Mesh *mesh, bool enableLight, float size = 1.0f, float x = 0.0f, float y = 0.0f, float rot = 0.f);
    void RenderMesh(Mesh *mesh, bool enableLight);

    void UpdateParticles(double dt);
    ParticleObject* GetParticle_NAME();
    void RenderParticles();

    Minnow* FetchFO();
    Projectile* FetchPO();
    DamageText* FetchTO();
    void RenderFO(Minnow *fo);
    void RenderPO(Projectile *po);
    void RenderTO(DamageText *to);

    float LookAtPlayer(Vector3 playerpos, Vector3 otherpos);

    float rotateSky;

    float fogThickness;
    float blendFactor;

private:

    // Shadow
    //DepthFBO m_lightDepthFBO;
    //Mtx44 m_lightDepthProj;
    //Mtx44 m_lightDepthView;
 
    bool bLightEnabled;

    //Terrain
    // Particles 
    std::vector<ParticleObject*> particleList; // Used to store
    Vector3 m_gravity;      // Gravity affecting the particles
    int m_particleCount;    // Number of particles
 
	//Fish test
	Capture fishy;

<<<<<<< ac2da7b4730664dbbe61626a68895adf2d9c0cab
protected:
	enum UNIFORM_TYPE
	{
		U_MVP = 0,
		U_MODELVIEW,
		U_MODELVIEW_INVERSE_TRANSPOSE,
		U_MATERIAL_AMBIENT,
		U_MATERIAL_DIFFUSE,
		U_MATERIAL_SPECULAR,
		U_MATERIAL_SHININESS,
		U_LIGHTENABLED,
		U_NUMLIGHTS,

		U_LIGHT0_TYPE,
		U_LIGHT0_POSITION,
		U_LIGHT0_COLOR,
		U_LIGHT0_POWER,
		U_LIGHT0_KC,
		U_LIGHT0_KL,
		U_LIGHT0_KQ,
		U_LIGHT0_SPOTDIRECTION,
		U_LIGHT0_COSCUTOFF,
		U_LIGHT0_COSINNER,
		U_LIGHT0_EXPONENT,

		U_LIGHT1_TYPE,
		U_LIGHT1_POSITION,
		U_LIGHT1_COLOR,
		U_LIGHT1_POWER,
		U_LIGHT1_KC,
		U_LIGHT1_KL,
		U_LIGHT1_KQ,
		U_LIGHT1_SPOTDIRECTION,
		U_LIGHT1_COSCUTOFF,
		U_LIGHT1_COSINNER,
		U_LIGHT1_EXPONENT,

		U_LIGHT2_TYPE,
		U_LIGHT2_POSITION,
		U_LIGHT2_COLOR,
		U_LIGHT2_POWER,
		U_LIGHT2_KC,
		U_LIGHT2_KL,
		U_LIGHT2_KQ,
		U_LIGHT2_SPOTDIRECTION,
		U_LIGHT2_COSCUTOFF,
		U_LIGHT2_COSINNER,
		U_LIGHT2_EXPONENT,

		U_COLOR_TEXTURE_ENABLED,
		U_COLOR_TEXTURE_ENABLED1,
		U_COLOR_TEXTURE,
		U_COLOR_TEXTURE1,
		U_IS_GUI,
		U_TEXT_COLOR,
		U_FOG_COLOR,
		U_FOG_START,
		U_FOG_END,
		U_FOG_THICKNESS,
		U_FOG_DENSITY,
		U_FOG_TYPE,
		U_FOG_ENABLE,

		U_LIGHT_DEPTH_MVP_GPASS,
		U_LIGHT_DEPTH_MVP,
		U_SHADOW_MAP,

		U_SHADOW_COLOR_TEXTURE_ENABLED,
		U_SHADOW_COLOR_TEXTURE,
		U_SHADOW_COLOR_TEXTURE_ENABLED1,
		U_SHADOW_COLOR_TEXTURE1,
		U_SHADOW_COLOR_TEXTURE_ENABLED2,
		U_SHADOW_COLOR_TEXTURE2,

		U_TEXTURE_BLEND_ENABLE,
		U_TEXTURE_BLEND_FACTOR,

		U_TOTAL,
	};
	enum GEOMETRY_TYPE
	{
		GEO_AXES,
		GEO_CUBE,
		GEO_CROSSHAIR,
		GEO_TEXT,
		GEO_BALL,
		GEO_BALL2,
		GEO_SKYPLANE,
		GEO_TERRAIN0,
		GEO_TERRAIN1,
		GEO_TERRAIN2,
		GEO_TERRAIN3,
		GEO_TERRAIN4,
		GEO_MINIMAP,
		GEO_MINIMAP_AVATAR,
		GEO_MINIMAP_MINNOW,
		GEO_FISHMODEL,
		GEO_FISHTAIL,

		GEO_SQUIDBODY,
		GEO_SQUIDTENTACLENODE,
		GEO_SQUIDTENTACLEEND,

		GEO_FSHARK_LJAW,
		GEO_FSHARK_UJAW,
		GEO_FSHARK_NODE,
		GEO_FSHARK_TAIL,

		GEO_CHIMERA_BODY,
		GEO_CHIMERA_FFLIP,
		GEO_CHIMERA_BFLIP,
		
		GEO_MINNOW,
		GEO_PUFFER,

		GEO_FCRABBODY,
		GEO_FCRABLEG,
		GEO_FCRABCLAW,




		SPRITE_NAME,
		PARTICLE_NAME,
		GEO_LIGHT_DEPTH_QUAD,
		NUM_GEOMETRY,
	};
	enum RENDER_PASS
	{
		RENDER_PASS_PRE,
		RENDER_PASS_MAIN,
	};
=======
	protected:


		enum UNIFORM_TYPE
		{
			U_MVP = 0,
			U_MODELVIEW,
			U_MODELVIEW_INVERSE_TRANSPOSE,
			U_MATERIAL_AMBIENT,
			U_MATERIAL_DIFFUSE,
			U_MATERIAL_SPECULAR,
			U_MATERIAL_SHININESS,
			U_LIGHTENABLED,
			U_NUMLIGHTS,

			U_LIGHT0_TYPE,
			U_LIGHT0_POSITION,
			U_LIGHT0_COLOR,
			U_LIGHT0_POWER,
			U_LIGHT0_KC,
			U_LIGHT0_KL,
			U_LIGHT0_KQ,
			U_LIGHT0_SPOTDIRECTION,
			U_LIGHT0_COSCUTOFF,
			U_LIGHT0_COSINNER,
			U_LIGHT0_EXPONENT,

			U_LIGHT1_TYPE,
			U_LIGHT1_POSITION,
			U_LIGHT1_COLOR,
			U_LIGHT1_POWER,
			U_LIGHT1_KC,
			U_LIGHT1_KL,
			U_LIGHT1_KQ,
			U_LIGHT1_SPOTDIRECTION,
			U_LIGHT1_COSCUTOFF,
			U_LIGHT1_COSINNER,
			U_LIGHT1_EXPONENT,

			U_LIGHT2_TYPE,
			U_LIGHT2_POSITION,
			U_LIGHT2_COLOR,
			U_LIGHT2_POWER,
			U_LIGHT2_KC,
			U_LIGHT2_KL,
			U_LIGHT2_KQ,
			U_LIGHT2_SPOTDIRECTION,
			U_LIGHT2_COSCUTOFF,
			U_LIGHT2_COSINNER,
			U_LIGHT2_EXPONENT,

			U_COLOR_TEXTURE_ENABLED,
			U_COLOR_TEXTURE_ENABLED1,
			U_COLOR_TEXTURE,
			U_COLOR_TEXTURE1,
			U_IS_GUI,
			U_TEXT_COLOR,
			U_FOG_COLOR,
			U_FOG_START,
			U_FOG_END,
			U_FOG_THICKNESS,
			U_FOG_DENSITY,
			U_FOG_TYPE,
			U_FOG_ENABLE,

			U_LIGHT_DEPTH_MVP_GPASS,
			U_LIGHT_DEPTH_MVP,
			U_SHADOW_MAP,

			U_SHADOW_COLOR_TEXTURE_ENABLED,
			U_SHADOW_COLOR_TEXTURE,
			U_SHADOW_COLOR_TEXTURE_ENABLED1,
			U_SHADOW_COLOR_TEXTURE1,
			U_SHADOW_COLOR_TEXTURE_ENABLED2,
			U_SHADOW_COLOR_TEXTURE2,

			U_TEXTURE_BLEND_ENABLE,
			U_TEXTURE_BLEND_FACTOR,

			U_TOTAL,
		};
		enum GEOMETRY_TYPE
		{
			GEO_AXES,
			GEO_CUBE,
			GEO_CROSSHAIR,
			GEO_TEXT,
			GEO_BALL,
			GEO_BALL2,
			GEO_SKYPLANE,
			GEO_TERRAIN0,
			GEO_TERRAIN1,
			GEO_TERRAIN2,
			GEO_TERRAIN3,
			GEO_TERRAIN4,
			GEO_MINIMAP,
			GEO_MINIMAP_AVATAR,
			GEO_MINIMAP_MINNOW,
			GEO_FISHMODEL,
			GEO_FISHTAIL,
			GEO_SQUIDBODY,
			GEO_SQUIDTENTACLENODE,
			GEO_SQUIDTENTACLEEND,

			GEO_MINNOW,

			GEO_CRAB_BODY,
			GEO_CRAB_ARM_UPPER,
			GEO_CRAB_ARM_MID,
			GEO_CRAB_ARM_LOWER,
			GEO_CRAB_LEG_UPPER,
			GEO_CRAB_LEG_LOWER,

			SPRITE_NAME,
			PARTICLE_NAME,
			GEO_LIGHT_DEPTH_QUAD,
			NUM_GEOMETRY,
		};
		enum RENDER_PASS
		{
			RENDER_PASS_PRE,
			RENDER_PASS_MAIN,
		};


>>>>>>> b6ac7e6782d14609d66ecfa2dc56e0e57c035abe

	// Game Object
	std::vector<GameObject*> m_goList;
	CameraV2 *currentCam;
	WalkCamera walkCam;


	//ligts and rendering
	MS modelStack;
	MS viewStack;
	MS projectionStack;
	DepthFBO m_lightDepthFBO;
	Mtx44 m_lightDepthProj;
	Mtx44 m_lightDepthView;
	RENDER_PASS m_renderPass;
	Light lights[1];
	unsigned m_vertexArrayID;
	Mesh* meshList[NUM_GEOMETRY];
	unsigned m_programID;
	unsigned m_gPassShaderID;
	unsigned m_parameters[U_TOTAL];

	//level stuff
	hitbox m_travelzonedown;
	hitbox m_travelzoneup;

	std::vector<unsigned char> m_heightMap[5];
	float fps;
	//player test stuff
	Vector3 playerpos;
	hitbox2 player_box;
	float val = 0;
	Vector3 fishRot;
	float	fish_tailrot;
	bool	fish_tailmax;
	Vector3 fishVel;
    //Minnow* minnowLeader;

    Skipper* skipper;

    // Spawner
    Spawner MinnowLeaderSpawner;
    Spawner MinnowSpawner;

    //DamageText text;
    std::vector<DamageText*> m_textList;
};

#endif