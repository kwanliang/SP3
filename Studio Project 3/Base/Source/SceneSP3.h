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
#include "HitBox.h"
#include "Minnow.h"
#include "Projectile.h"
#include "Capture.h"



class SceneSP3 : public Scene
{
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
        U_TEXT_ENABLED,
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
		GEO_TERRAIN,
		GEO_FISHMODEL,
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
public:
    SceneSP3();
    ~SceneSP3();

    virtual void Init();
    virtual void Update(double dt);
    virtual void Render();
    virtual void Exit();

    void RenderPassGPass();
    void RenderPassMain();
    void RenderWorld();

    void UpdateMinnow(double dt);
	void UpdatePuffer(double dt);

    void RenderText(Mesh* mesh, std::string text, Color color);
    void RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y);
    void RenderMeshIn2D(Mesh *mesh, bool enableLight, float size = 1.0f, float x = 0.0f, float y = 0.0f);
    void RenderMesh(Mesh *mesh, bool enableLight);




    void RenderSkyPlane();
    void RenderTerrain();
    void RenderOBJ();
    void RenderSprite();

    void UpdateParticles(double dt);
    ParticleObject* GetParticle_NAME();
    void RenderParticles();

    Minnow* FetchFO();
    Projectile* FetchPO();
    void RenderFO(Minnow *fo);
    void RenderPO(Projectile *po);

    float rotateSky;

    float fogThickness;
    float blendFactor;

private:
    unsigned m_vertexArrayID;
    Mesh* meshList[NUM_GEOMETRY];
    unsigned m_programID;
    unsigned m_parameters[U_TOTAL];

    // Shadow
    unsigned m_gPassShaderID;
    DepthFBO m_lightDepthFBO;
    Mtx44 m_lightDepthProj;
    Mtx44 m_lightDepthView;
    RENDER_PASS m_renderPass;

    //Camera3 camera;
	CameraV2 *currentCam;

	WalkCamera walkCam;

    MS modelStack;
    MS viewStack;
    MS projectionStack;

    Light lights[1];

    bool bLightEnabled;

    float fps;

    //Terrain
    std::vector<unsigned char> m_heightMap;

    // Particles 
    std::vector<ParticleObject*> particleList; // Used to store
    Vector3 m_gravity;      // Gravity affecting the particles
    int m_particleCount;    // Number of particles

    // Game Object
    std::vector<GameObject*> m_goList;

	//player test stuff
	Vector3 playerpos;
	hitbox player_box;

	Vector3 fishRot;

	//Fish test
	Capture fishy;
};

#endif