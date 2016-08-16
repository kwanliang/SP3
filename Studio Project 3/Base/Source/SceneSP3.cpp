#include "SceneSP3.h"
#include "GL\glew.h"

#include <sstream>
#include "shader.hpp"
#include "MeshBuilder.h"
#include "Application.h"
#include "Utility.h"
#include "LoadTGA.h"
#include "LoadHmap.h"
#include "HitBox.h"

using std::cout;
using std::endl;

//SpriteAnimation *SPRITENAME;

SceneSP3::SceneSP3()
{
}

SceneSP3::~SceneSP3()
{
}

void SceneSP3::Init()
{
    // Black background
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

    glEnable(GL_CULL_FACE);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glGenVertexArrays(1, &m_vertexArrayID);
    glBindVertexArray(m_vertexArrayID);

    // Frame buffers

    // Shadow
    m_lightDepthFBO.Init(4096, 4096);

    m_gPassShaderID = LoadShaders("Shader//GPass.vertexshader", "Shader//GPass.fragmentshader");
    m_parameters[U_LIGHT_DEPTH_MVP_GPASS] = glGetUniformLocation(m_gPassShaderID, "lightDepthMVP");

    m_programID = LoadShaders("Shader//Shadow.vertexshader", "Shader//Shadow.fragmentshader");
    m_parameters[U_LIGHT_DEPTH_MVP] = glGetUniformLocation(m_programID, "lightDepthMVP");

    m_parameters[U_SHADOW_MAP] = glGetUniformLocation(m_programID, "shadowMap");

    // Get a handle for our uniform
    m_parameters[U_MVP] = glGetUniformLocation(m_programID, "MVP");
    //m_parameters[U_MODEL] = glGetUniformLocation(m_programID, "M");
    //m_parameters[U_VIEW] = glGetUniformLocation(m_programID, "V");
    m_parameters[U_MODELVIEW] = glGetUniformLocation(m_programID, "MV");
    m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE] = glGetUniformLocation(m_programID, "MV_inverse_transpose");
    m_parameters[U_MATERIAL_AMBIENT] = glGetUniformLocation(m_programID, "material.kAmbient");
    m_parameters[U_MATERIAL_DIFFUSE] = glGetUniformLocation(m_programID, "material.kDiffuse");
    m_parameters[U_MATERIAL_SPECULAR] = glGetUniformLocation(m_programID, "material.kSpecular");
    m_parameters[U_MATERIAL_SHININESS] = glGetUniformLocation(m_programID, "material.kShininess");
    m_parameters[U_LIGHTENABLED] = glGetUniformLocation(m_programID, "lightEnabled");
    m_parameters[U_NUMLIGHTS] = glGetUniformLocation(m_programID, "numLights");

    // Directional light for shadows
    m_parameters[U_LIGHT0_TYPE] = glGetUniformLocation(m_programID, "lights[0].type");
    m_parameters[U_LIGHT0_POSITION] = glGetUniformLocation(m_programID, "lights[0].position_cameraspace");
    m_parameters[U_LIGHT0_COLOR] = glGetUniformLocation(m_programID, "lights[0].color");
    m_parameters[U_LIGHT0_POWER] = glGetUniformLocation(m_programID, "lights[0].power");
    m_parameters[U_LIGHT0_KC] = glGetUniformLocation(m_programID, "lights[0].kC");
    m_parameters[U_LIGHT0_KL] = glGetUniformLocation(m_programID, "lights[0].kL");
    m_parameters[U_LIGHT0_KQ] = glGetUniformLocation(m_programID, "lights[0].kQ");
    m_parameters[U_LIGHT0_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[0].spotDirection");
    m_parameters[U_LIGHT0_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[0].cosCutoff");
    m_parameters[U_LIGHT0_COSINNER] = glGetUniformLocation(m_programID, "lights[0].cosInner");
    m_parameters[U_LIGHT0_EXPONENT] = glGetUniformLocation(m_programID, "lights[0].exponent");

    // Directional light for scene
    m_parameters[U_LIGHT1_TYPE] = glGetUniformLocation(m_programID, "lights[1].type");
    m_parameters[U_LIGHT1_POSITION] = glGetUniformLocation(m_programID, "lights[1].position_cameraspace");
    m_parameters[U_LIGHT1_COLOR] = glGetUniformLocation(m_programID, "lights[1].color");
    m_parameters[U_LIGHT1_POWER] = glGetUniformLocation(m_programID, "lights[1].power");
    m_parameters[U_LIGHT1_KC] = glGetUniformLocation(m_programID, "lights[1].kC");
    m_parameters[U_LIGHT1_KL] = glGetUniformLocation(m_programID, "lights[1].kL");
    m_parameters[U_LIGHT1_KQ] = glGetUniformLocation(m_programID, "lights[1].kQ");
    m_parameters[U_LIGHT1_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[1].spotDirection");
    m_parameters[U_LIGHT1_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[1].cosCutoff");
    m_parameters[U_LIGHT1_COSINNER] = glGetUniformLocation(m_programID, "lights[1].cosInner");
    m_parameters[U_LIGHT1_EXPONENT] = glGetUniformLocation(m_programID, "lights[1].exponent");

    // Spotlight campfire
    m_parameters[U_LIGHT2_TYPE] = glGetUniformLocation(m_programID, "lights[2].type");
    m_parameters[U_LIGHT2_POSITION] = glGetUniformLocation(m_programID, "lights[2].position_cameraspace");
    m_parameters[U_LIGHT2_COLOR] = glGetUniformLocation(m_programID, "lights[2].color");
    m_parameters[U_LIGHT2_POWER] = glGetUniformLocation(m_programID, "lights[2].power");
    m_parameters[U_LIGHT2_KC] = glGetUniformLocation(m_programID, "lights[2].kC");
    m_parameters[U_LIGHT2_KL] = glGetUniformLocation(m_programID, "lights[2].kL");
    m_parameters[U_LIGHT2_KQ] = glGetUniformLocation(m_programID, "lights[2].kQ");
    m_parameters[U_LIGHT2_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[2].spotDirection");
    m_parameters[U_LIGHT2_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[2].cosCutoff");
    m_parameters[U_LIGHT2_COSINNER] = glGetUniformLocation(m_programID, "lights[2].cosInner");
    m_parameters[U_LIGHT2_EXPONENT] = glGetUniformLocation(m_programID, "lights[2].exponent");

    // Get a handle for our "colorTexture" uniform
    m_parameters[U_COLOR_TEXTURE_ENABLED] = glGetUniformLocation(m_programID, "colorTextureEnabled[0]");
    m_parameters[U_COLOR_TEXTURE] = glGetUniformLocation(m_programID, "colorTexture[0]");
    m_parameters[U_COLOR_TEXTURE_ENABLED1] = glGetUniformLocation(m_programID, "colorTextureEnabled[1]");
    m_parameters[U_COLOR_TEXTURE1] = glGetUniformLocation(m_programID, "colorTexture[1]");
    // Get a handle for our "textColor" uniform
    m_parameters[U_TEXT_ENABLED] = glGetUniformLocation(m_programID, "textEnabled");
    m_parameters[U_TEXT_COLOR] = glGetUniformLocation(m_programID, "textColor");

    // Get a handle for our "fog" uniform
    m_parameters[U_FOG_COLOR] = glGetUniformLocation(m_programID, "fogParam.color");
    m_parameters[U_FOG_START] = glGetUniformLocation(m_programID, "fogParam.start");
    m_parameters[U_FOG_END] = glGetUniformLocation(m_programID, "fogParam.end");
    m_parameters[U_FOG_THICKNESS] = glGetUniformLocation(m_programID, "fogParam.thickness");
    m_parameters[U_FOG_DENSITY] = glGetUniformLocation(m_programID, "fogParam.density");
    m_parameters[U_FOG_TYPE] = glGetUniformLocation(m_programID, "fogParam.type");
    m_parameters[U_FOG_ENABLE] = glGetUniformLocation(m_programID, "fogParam.enabled");

    // Get a handle for our "shadow" uniform
    m_parameters[U_SHADOW_COLOR_TEXTURE_ENABLED] = glGetUniformLocation(m_gPassShaderID, "colorTextureEnabled[0]");
    m_parameters[U_SHADOW_COLOR_TEXTURE] = glGetUniformLocation(m_gPassShaderID, "colorTexture[0]");
    m_parameters[U_SHADOW_COLOR_TEXTURE_ENABLED1] = glGetUniformLocation(m_gPassShaderID, "colorTextureEnabled[1]");
    m_parameters[U_SHADOW_COLOR_TEXTURE1] = glGetUniformLocation(m_gPassShaderID, "colorTexture[1]");
    m_parameters[U_SHADOW_COLOR_TEXTURE_ENABLED2] = glGetUniformLocation(m_gPassShaderID, "colorTextureEnabled[2]");
    m_parameters[U_SHADOW_COLOR_TEXTURE2] = glGetUniformLocation(m_gPassShaderID, "colorTexture[2]");

    m_parameters[U_TEXTURE_BLEND_ENABLE] = glGetUniformLocation(m_programID, "blendParam.blendEnabled");
    m_parameters[U_TEXTURE_BLEND_FACTOR] = glGetUniformLocation(m_programID, "blendParam.blendFactor");

    // Use our shader
    glUseProgram(m_programID);

    lights[0].type = Light::LIGHT_DIRECTIONAL;
    lights[0].position.Set(0, 100, 50);
    lights[0].color.Set(1, 1, 1);
    lights[0].power = 3.0f;
    lights[0].kC = 1.f;
    lights[0].kL = 0.01f;
    lights[0].kQ = 0.001f;
    lights[0].cosCutoff = cos(Math::DegreeToRadian(45));
    lights[0].cosInner = cos(Math::DegreeToRadian(30));
    lights[0].exponent = 3.f;

    //lights[1].type = Light::LIGHT_DIRECTIONAL;
    //lights[1].position.Set(0, 100, 50);
    //lights[1].color.Set(1, 1, 1);
    //lights[1].power = 1.0f;
    //lights[1].kC = 1.f;
    //lights[1].kL = 0.01f;
    //lights[1].kQ = 0.001;
    //lights[1].cosCutoff = cos(Math::DegreeToRadian(45));
    //lights[1].cosInner = cos(Math::DegreeToRadian(30));
    //lights[1].exponent = 3.f;

    //lights[2].type = Light::LIGHT_SPOT;
    //lights[2].position.Set(-80.f, 100.f, 0.f);
    //lights[2].color.Set(1, 1, 1);
    //lights[2].power = 30.f;
    //lights[2].kC = 1.f;
    //lights[2].kL = 0.01f;
    //lights[2].kQ = 0.001f;
    //lights[2].spotDirection.Set(0.f, 1.f, 0.f);
    //lights[2].cosCutoff = cos(Math::DegreeToRadian(120));
    //lights[2].cosInner = cos(Math::DegreeToRadian(0));
    //lights[2].exponent = 3.f;

    glUniform1i(m_parameters[U_NUMLIGHTS], 1);
    glUniform1i(m_parameters[U_TEXT_ENABLED], 0);

    glUniform1i(m_parameters[U_LIGHT0_TYPE], lights[0].type);
    glUniform3fv(m_parameters[U_LIGHT0_COLOR], 1, &lights[0].color.r);
    glUniform1f(m_parameters[U_LIGHT0_POWER], lights[0].power);
    glUniform1f(m_parameters[U_LIGHT0_KC], lights[0].kC);
    glUniform1f(m_parameters[U_LIGHT0_KL], lights[0].kL);
    glUniform1f(m_parameters[U_LIGHT0_KQ], lights[0].kQ);
    glUniform1f(m_parameters[U_LIGHT0_COSCUTOFF], lights[0].cosCutoff);
    glUniform1f(m_parameters[U_LIGHT0_COSINNER], lights[0].cosInner);
    glUniform1f(m_parameters[U_LIGHT0_EXPONENT], lights[0].exponent);

    glUniform1i(m_parameters[U_LIGHT1_TYPE], lights[1].type);
    glUniform3fv(m_parameters[U_LIGHT1_COLOR], 1, &lights[1].color.r);
    glUniform1f(m_parameters[U_LIGHT1_POWER], lights[1].power);
    glUniform1f(m_parameters[U_LIGHT1_KC], lights[1].kC);
    glUniform1f(m_parameters[U_LIGHT1_KL], lights[1].kL);
    glUniform1f(m_parameters[U_LIGHT1_KQ], lights[1].kQ);
    glUniform1f(m_parameters[U_LIGHT1_COSCUTOFF], lights[1].cosCutoff);
    glUniform1f(m_parameters[U_LIGHT1_COSINNER], lights[1].cosInner);
    glUniform1f(m_parameters[U_LIGHT1_EXPONENT], lights[1].exponent);

    glUniform1i(m_parameters[U_LIGHT2_TYPE], lights[2].type);
    glUniform3fv(m_parameters[U_LIGHT2_COLOR], 1, &lights[2].color.r);
    glUniform1f(m_parameters[U_LIGHT2_POWER], lights[2].power);
    glUniform1f(m_parameters[U_LIGHT2_KC], lights[2].kC);
    glUniform1f(m_parameters[U_LIGHT2_KL], lights[2].kL);
    glUniform1f(m_parameters[U_LIGHT2_KQ], lights[2].kQ);
    glUniform1f(m_parameters[U_LIGHT2_COSCUTOFF], lights[2].cosCutoff);
    glUniform1f(m_parameters[U_LIGHT2_COSINNER], lights[2].cosInner);
    glUniform1f(m_parameters[U_LIGHT2_EXPONENT], lights[2].exponent);

    Color fogColor(0.2f, 0.2f, 0.2f);
    glUniform3fv(m_parameters[U_FOG_COLOR], 1, &fogColor.r);
    glUniform1f(m_parameters[U_FOG_START], 10);
    glUniform1f(m_parameters[U_FOG_END], 1000);
    glUniform1f(m_parameters[U_FOG_THICKNESS], 0.1f);
    glUniform1f(m_parameters[U_FOG_DENSITY], 0.0f);
    glUniform1f(m_parameters[U_FOG_TYPE], 1);
    glUniform1f(m_parameters[U_FOG_ENABLE], 0);


    //camera.Init(Vector3(0, 70, 10), Vector3(0, 70, 0), Vector3(0, 1, 0));
	walkCam.Init(
		Vector3(0, 70, 10),
		Vector3(0, 0, -10),
		Vector3(0, 1, 0),
		500
	);
	currentCam = &walkCam;

    for (int i = 0; i < NUM_GEOMETRY; ++i)
    {
        meshList[i] = NULL;
    }
	meshList[GEO_CUBE] = MeshBuilder::GenerateCube("cube", Color(1,0,0),1.f );
    meshList[GEO_AXES] = MeshBuilder::GenerateAxes("reference");//, 1000, 1000, 1000);
    meshList[GEO_CROSSHAIR] = MeshBuilder::GenerateCrossHair("crosshair");
    meshList[GEO_TEXT] = MeshBuilder::GenerateText("text", 16, 16);
    meshList[GEO_TEXT]->textureID = LoadTGA("Image//calibri.tga");
    meshList[GEO_TEXT]->material.kAmbient.Set(1, 0, 0);

    meshList[GEO_SKYPLANE] = MeshBuilder::GenerateSkyPlane("skyplane", Color(1, 1, 1), 128, 200.0f, 2000.0f, 1.0f, 1.0f);
    meshList[GEO_SKYPLANE]->textureArray[0] = LoadTGA("Image//sky.tga");
    meshList[GEO_SKYPLANE]->textureArray[1] = LoadTGA("Image//night.tga");

    meshList[GEO_TERRAIN] = MeshBuilder::GenerateTerrain("terrain", "Image//heightmap2.raw", m_heightMap);
    meshList[GEO_TERRAIN]->textureArray[0] = LoadTGA("Image//rock.tga");
    //meshList[GEO_TERRAIN]->textureArray[1] = LoadTGA("Image//ForestMurky.tga");

	meshList[GEO_FISHMODEL] = MeshBuilder::GenerateOBJ("fishModel", "Models//OBJ//FishModel.obj");

    meshList[GEO_BALL] = MeshBuilder::GenerateSphere("ball", Color(1, 1, 1), 16, 16, 1.f);
    meshList[GEO_BALL2] = MeshBuilder::GenerateSphere("ball", Color(1, 0, 0), 16, 16, 1.f);

    // Object
    //meshList[OBJ_NAME] = MeshBuilder::GenerateOBJ("", "OBJ//.obj");
    //meshList[OBJ_NAME]->textureArray[0] = LoadTGA("Image//.tga");

    // Particles
    //meshList[PARTICLE_NAME] = MeshBuilder::GenerateQuad("", Color(1, .5f, 0), 1.f);

    // Shadow
    meshList[GEO_LIGHT_DEPTH_QUAD] = MeshBuilder::GenerateQuad("Shadow Test", 1, 1);
    meshList[GEO_LIGHT_DEPTH_QUAD]->textureArray[0] = m_lightDepthFBO.GetTexture();

    // Sprite
    //meshList[SPRITE_NAME] = MeshBuilder::GenerateSpriteAnimation("", 1, 5);
    //meshList[SPRITE_NAME]->textureArray[0] = LoadTGA("");

    //SPRITENAME = dynamic_cast<SpriteAnimation*>(meshList[SPRITE_NAME]);

	playerpos = Vector3(0, 300, 0);
	player_box = hitbox::generatehitbox(playerpos, 20, 30, 20, NULL);
    //if (SPRITENAME)
    //{
    //    SPRITENAME->m_anim = new Animation();
    //    SPRITENAME->m_anim->Set(0, 4, 0, 1.f, true);
    //    SPRITENAME->SpritePos = Vector3(-80.f, 15.f + 350.f * ReadHeightMap(m_heightMap, -80.f / 3000.f, 0.f / 3000.f), 0.f);
    //    SPRITENAME->m_anim->moveable = true;
    //}

    // Projection matrix : 45� Field of View, 4:3 ratio, display range : 0.1 unit <-> 1000 units
    //Mtx44 perspective;
    //perspective.SetToPerspective(45.0f, 4.0f / 3.0f, 0.1f, 10000.0f);
    //perspective.SetToOrtho(-80, 80, -60, 60, -1000, 1000);
   // projectionStack.LoadMatrix(perspective);

    rotateSky = 0.f;
    fogThickness = 0.f;
    blendFactor = 0.f;

    bLightEnabled = true;

    m_particleCount = 0;
    m_gravity.Set(0, -9.8f, 0);

	fishy.SetPos(Vector3(0, 300, 0));
	fishy.SetType(Capture::FISH);
	
	walkCam.yOffset = 100;

    for (int i = 0; i < 30; i++)
    {
        Minnow *fo = FetchFO();
        fo->active = true;
        fo->objectType = GameObject::SEACREATURE;
        fo->seaType = SeaCreature::MINNOW;
        fo->state = Minnow::FLOCK;
        fo->scale.Set(1, 1, 5);
        fo->pos.Set(Math::RandFloatMinMax(-100, 100), Math::RandFloatMinMax(-400,600 ), Math::RandFloatMinMax(-100, 100));
        fo->vel.Set(Math::RandFloatMinMax(-10, 10), 0, Math::RandFloatMinMax(-10, 10));
    }
}

Minnow* SceneSP3::FetchFO()
{
    for (std::vector<GameObject *>::iterator it = m_goList.begin(); it != m_goList.end(); ++it)
    {
        Minnow *go = (Minnow *)*it;
        if (!go->active)
        {
            go->active = true;
            //++m_objectCount;
            return go;
        }
    }
    for (unsigned i = 0; i < 10; ++i)
    {
        Minnow *go = new Minnow();
        go->objectType = GameObject::SEACREATURE;
        m_goList.push_back(go);
    }
    Minnow *go = (Minnow *)m_goList.back();
    go->active = true;
    //++m_objectCount;
    return go;
}

Projectile* SceneSP3::FetchPO()
{
    for (std::vector<GameObject *>::iterator it = m_goList.begin(); it != m_goList.end(); ++it)
    {
        Projectile *go = (Projectile *)*it;
        if (!go->active)
        {
            go->active = true;
            //++m_objectCount;
            return go;
        }
    }
    for (unsigned i = 0; i < 10; ++i)
    {
        Projectile *go = new Projectile();
        go->objectType = GameObject::PROJECTILE;
        m_goList.push_back(go);
    }
    Projectile *go = (Projectile *)m_goList.back();
    go->active = true;
    //++m_objectCount;
    return go;
}

void SceneSP3::UpdateMinnow(double dt)
{
    // Minnow loop
    for (std::vector<GameObject *>::iterator it = m_goList.begin(); it != m_goList.end(); ++it)
    {
        GameObject *go = (GameObject *)*it;
        if (go->active)
        {
            if (go->objectType == GameObject::SEACREATURE)
            {
                Minnow *fo = (Minnow *)*it;
                if (fo->seaType == SeaCreature::MINNOW)
                {
                    if (fo->state == Minnow::FLOCK)
                        fo->pos += fo->vel * dt;
                    else
                        fo->pos += fo->vel * dt * 10;

                    Vector3 tempCentreOfMass(0, 0, 0);
                    Vector3 tempRepelVector(0, 0, 0);
                    Vector3 tempForceVector(0, 0, 0);

                    int neightbourCount = 0;

                    for (std::vector<GameObject *>::iterator it2 = m_goList.begin(); it2 != m_goList.end(); ++it2)
                    {
                        Minnow *other = (Minnow *)*it2;

                        if (other->active && fo != other && fo->seaType == SeaCreature::MINNOW)
                        {
                            neightbourCount++;

                            if ((other->pos - fo->pos).LengthSquared() < distFromSeperation)
                            {
                                tempRepelVector = fo->pos - other->pos;
                                fo->vel += fo->seperation(tempRepelVector);
                            }

                            tempCentreOfMass += other->pos;

                            if ((other->pos - fo->pos).LengthSquared() < distFromAlignment)
                                tempForceVector += other->vel;
                        }
                    }

                    if (fo->state == Minnow::FLOCK)
                        fo->vel += fo->alignment(tempCentreOfMass, neightbourCount) + fo->cohesion(tempCentreOfMass, neightbourCount) * 1.5;
                    else
                        fo->vel += fo->seperation(tempCentreOfMass) * 2;
                    //cout << tempCentreOfMass << endl;

                    // Cap velocity
                    if (go->vel.x > 20)
                        go->vel.x = 20;
                    if (go->vel.y > 20)
                        go->vel.y = 20;
                    if (go->vel.z > 20)
                        go->vel.z = 20;
                    if (go->vel.x < -20)
                        go->vel.x = -20;
                    if (go->vel.y < -20)
                        go->vel.y = -20;
                    if (go->vel.z < -20)
                        go->vel.z = -20;

                    if (fo->state == Minnow::FLEE && fo->getpanicTime() < 3.f)
                    {
                        fo->setpanicTime(fo->getpanicTime() + dt);
                    }

                    if (fo->state == Minnow::FLEE && fo->getpanicTime() >= 3.f)
                    {
                        fo->state = Minnow::FLOCK;
                        fo->setpanicTime(0.f);
                    }
                }
            }
            else if (go->objectType == GameObject::PROJECTILE)
            {
                Projectile *po = (Projectile *)*it;
                po->pos += po->vel * dt * 500;

                if (go->pos.y < -1000)
                    po->active = false;
                else if (go->pos.y > 1000)
                    po->active = false;

                if (go->pos.x < -1000)
                    po->active = false;
                else if (go->pos.x > 1000)
                    po->active = false;

                if (go->pos.z < -1000)
                    po->active = false;
                else if (go->pos.z > 1000)
                    po->active = false;

                for (std::vector<GameObject *>::iterator it2 = m_goList.begin(); it2 != m_goList.end(); ++it2)
                {
                    Minnow *other = (Minnow *)*it2;
                    if (other->active && go != other && other->state == Minnow::FLOCK && other->seaType == SeaCreature::MINNOW)
                    {
                        if ((other->pos - po->pos).LengthSquared() < po->scale.z + other->scale.z + 50)
                        {
                            for (std::vector<GameObject *>::iterator it3 = m_goList.begin(); it3 != m_goList.end(); ++it3)
                            {
                                Minnow *other2 = (Minnow *)*it3;
                                if (other2->active && go != other2 && other2->state == Minnow::FLOCK && other2->seaType == SeaCreature::MINNOW)
                                {
                                    other2->state = Minnow::FLEE;
                                }
                            }
                        }
                        if ((other->pos - po->pos).LengthSquared() < po->scale.z + other->scale.z)
                        {
                            po->active = false;
                            other->active = false;
                            cout << "dead" << endl;
                        }
                    }
                }
            }
        }
    }
}

void SceneSP3::Update(double dt)
{
    if (Application::IsKeyPressed('1'))
        glEnable(GL_CULL_FACE);
    if (Application::IsKeyPressed('2'))
        glDisable(GL_CULL_FACE);
    if (Application::IsKeyPressed('3'))
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    if (Application::IsKeyPressed('4'))
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    if (Application::IsKeyPressed('I'))
        lights[0].position.z -= (float)(100.f * dt);
    if (Application::IsKeyPressed('K'))
        lights[0].position.z += (float)(100.f * dt);
    if (Application::IsKeyPressed('J'))
        lights[0].position.x -= (float)(100.f * dt);
    if (Application::IsKeyPressed('L'))
        lights[0].position.x += (float)(100.f * dt);
    if (Application::IsKeyPressed('O'))
        lights[0].position.y -= (float)(100.f * dt);
    if (Application::IsKeyPressed('P'))
        lights[0].position.y += (float)(100.f * dt);

    //camera.Update(dt);
    fps = (float)(1. / dt);

	{
		Vector3 right = walkCam.GetDir().Cross(walkCam.GetUp());
		right.Normalize();

		if (Application::IsKeyPressed('W'))
		{
			walkCam.Move(100 * (float)dt * walkCam.GetDir());
		}
		if (Application::IsKeyPressed('S'))
		{
			walkCam.Move(-100 * (float)dt * walkCam.GetDir());
		}

		if (Application::IsKeyPressed('A'))
		{
			walkCam.Move(-100.f * (float)dt * right);
		}
		if (Application::IsKeyPressed('D'))
		{
			walkCam.Move(100.f * (float)dt * right);
		}
	}

	if (Application::camera_yaw != 0)
	{
		walkCam.Turn(Math::RadianToDegree(-(float)Application::camera_yaw * 0.5f));
	}

	if (Application::camera_pitch != 0)
	{
		walkCam.Pitch(Math::RadianToDegree(-(float)Application::camera_pitch * 0.5f));
	}

	//float tH = (350.f * ReadHeightMap(m_heightMap, walkCam.GetPos().x / 3000.f, walkCam.GetPos().z / 3000.f)) + 20.f;
	//float diff = tH - walkCam.GetPos().y;

	//if (diff != 0)
		//walkCam.Move(0, 0, diff);


	//orientate fish
	{
		Vector3 camDir = walkCam.GetDir();
		if (camDir.x != 0 || camDir.z != 0)
			fishRot.y = Math::RadianToDegree(atan2(-camDir.z, camDir.x));

		fishRot.x = 90 - Math::RadianToDegree(acos(-camDir.y));
	}



    //camera.TerrainHeight = (350.f * ReadHeightMap(m_heightMap, camera.position.x / 3000.f, camera.position.z / 3000.f)) + 20.f;

    rotateSky += .05f;

 //   // Fog & Blending
	//if (blendFactor < 1.0f)
	//	blendFactor = 1.f;
	//else
 //       blendFactor = 0;

    //glUniform1f(m_parameters[U_TEXTURE_BLEND_FACTOR], blendFactor);

    //    fogThickness += (1.f / 100.f);

    //glUniform1f(m_parameters[U_FOG_THICKNESS], fogThickness);
    //fogThickness = 0;

    // Sprite
    //SPRITENAME = dynamic_cast<SpriteAnimation*>(meshList[SPRITE_NAME]);

    //SPRITENAME->Update(dt);
    //SPRITENAME->m_anim->animActive = true;

    // Particles
    //UpdateParticles(dt);

    UpdateMinnow(dt);
	if (Application::IsKeyPressed('M'))
	{
		fishy.SetPos(Capture::Vacuum(fishy, walkCam, dt));
		
	}
}

static const float SKYBOXSIZE = 1000.f;

void SceneSP3::RenderText(Mesh* mesh, std::string text, Color color)
{
    if (!mesh || mesh->textureID <= 0)
        return;

    glDisable(GL_DEPTH_TEST);
    glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
    glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &color.r);
    glUniform1i(m_parameters[U_LIGHTENABLED], 0);
    glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, mesh->textureID);
    glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
    for (unsigned i = 0; i < text.length(); ++i)
    {
        Mtx44 characterSpacing;
        characterSpacing.SetToTranslation(i * 1.0f, 0, 0); //1.0f is the spacing of each character, you may change this value
        Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
        glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

        mesh->Render((unsigned)text[i] * 6, 6);
    }
    glBindTexture(GL_TEXTURE_2D, 0);
    glUniform1i(m_parameters[U_TEXT_ENABLED], 0);
    glEnable(GL_DEPTH_TEST);
}

void SceneSP3::RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y)
{
    if (!mesh || mesh->textureID <= 0)
        return;

    glDisable(GL_DEPTH_TEST);
    Mtx44 ortho;
    ortho.SetToOrtho(0, 80, 0, 60, -10, 10);
    projectionStack.PushMatrix();
    projectionStack.LoadMatrix(ortho);
    viewStack.PushMatrix();
    viewStack.LoadIdentity();
    modelStack.PushMatrix();
    modelStack.LoadIdentity();
    modelStack.Translate(x, y, 0);
    modelStack.Scale(size, size, size);
    glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
    glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &color.r);
    glUniform1i(m_parameters[U_LIGHTENABLED], 0);
    glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, mesh->textureID);
    glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
    for (unsigned i = 0; i < text.length(); ++i)
    {
        Mtx44 characterSpacing;
        characterSpacing.SetToTranslation(i * 1.0f + 0.5f, 0.5f, 0); //1.0f is the spacing of each character, you may change this value
        Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
        glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

        mesh->Render((unsigned)text[i] * 6, 6);
    }
    glBindTexture(GL_TEXTURE_2D, 0);
    glUniform1i(m_parameters[U_TEXT_ENABLED], 0);
    modelStack.PopMatrix();
    viewStack.PopMatrix();
    projectionStack.PopMatrix();
    glEnable(GL_DEPTH_TEST);
}

void SceneSP3::RenderMeshIn2D(Mesh *mesh, bool enableLight, float size, float x, float y)
{
    Mtx44 ortho;
    ortho.SetToOrtho(-80, 80, -60, 60, -10, 10);
    projectionStack.PushMatrix();
    projectionStack.LoadMatrix(ortho);
    viewStack.PushMatrix();
    viewStack.LoadIdentity();
    modelStack.PushMatrix();
    modelStack.LoadIdentity();
    modelStack.Scale(size, size, size);
    modelStack.Translate(x, y, 0);

    Mtx44 MVP, modelView, modelView_inverse_transpose;

    MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
    glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
    if (mesh->textureID > 0)
    {
        glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, mesh->textureID);
        glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
    }
    else
    {
        glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 0);
    }
    mesh->Render();
    if (mesh->textureID > 0)
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    modelStack.PopMatrix();
    viewStack.PopMatrix();
    projectionStack.PopMatrix();
}

void SceneSP3::RenderMesh(Mesh *mesh, bool enableLight)
{
    Mtx44 MVP, modelView, modelView_inverse_transpose;

    //For Gpass/shadow textures
    if (m_renderPass == RENDER_PASS_PRE)
    {

        for (int i = 0; i < Mesh::MAX_TEXTURES; ++i)
        {
            if (mesh->textureArray[i] > 0)
            {
                glUniform1i(m_parameters[U_SHADOW_COLOR_TEXTURE_ENABLED + i], 1);
                glActiveTexture(GL_TEXTURE0 + i);
                glBindTexture(GL_TEXTURE_2D, mesh->textureArray[i]);
                glUniform1i(m_parameters[U_SHADOW_COLOR_TEXTURE + i], i);
            }
            else
            {
                glUniform1i(m_parameters[U_SHADOW_COLOR_TEXTURE_ENABLED + i], 0);
            }
        }

        Mtx44 lightDepthMVP = m_lightDepthProj * m_lightDepthView * modelStack.Top();
        glUniformMatrix4fv(m_parameters[U_LIGHT_DEPTH_MVP_GPASS], 1, GL_FALSE, &lightDepthMVP.a[0]);

        mesh->Render();
        return;
    }

    MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
    glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
    modelView = viewStack.Top() * modelStack.Top();
    glUniformMatrix4fv(m_parameters[U_MODELVIEW], 1, GL_FALSE, &modelView.a[0]);

    if (enableLight && bLightEnabled)
    {
        glUniform1i(m_parameters[U_LIGHTENABLED], 1);
        modelView_inverse_transpose = modelView.GetInverse().GetTranspose();
        glUniformMatrix4fv(m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE], 1, GL_FALSE, &modelView.a[0]);

        //Shadow
        Mtx44 lightDepthMVP = m_lightDepthProj * m_lightDepthView * modelStack.Top();

        glUniformMatrix4fv(m_parameters[U_LIGHT_DEPTH_MVP], 1, GL_FALSE, &lightDepthMVP.a[0]);

        //load material
        glUniform3fv(m_parameters[U_MATERIAL_AMBIENT], 1, &mesh->material.kAmbient.r);
        glUniform3fv(m_parameters[U_MATERIAL_DIFFUSE], 1, &mesh->material.kDiffuse.r);
        glUniform3fv(m_parameters[U_MATERIAL_SPECULAR], 1, &mesh->material.kSpecular.r);
        glUniform1f(m_parameters[U_MATERIAL_SHININESS], mesh->material.kShininess);
    }
    else
    {
        glUniform1i(m_parameters[U_LIGHTENABLED], 0);
    }

    for (int i = 0; i < Mesh::MAX_TEXTURES; ++i)
    {
        if (mesh->textureArray[i] > 0)
        {
            glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED + i], 1);
            glActiveTexture(GL_TEXTURE0 + i);
            glBindTexture(GL_TEXTURE_2D, mesh->textureArray[i]);
            glUniform1i(m_parameters[U_COLOR_TEXTURE + i], i);
        }
        else
        {
            glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED + i], 0);
        }
    }

    mesh->Render();
}

void SceneSP3::RenderSkyPlane()
{
    modelStack.PushMatrix();
    modelStack.Translate(0, 2000, 0);
    modelStack.Rotate(rotateSky, 0, 1, 0);
    RenderMesh(meshList[GEO_SKYPLANE], true);
    modelStack.PopMatrix();
}

void SceneSP3::RenderTerrain()
{
    glUniform1i(m_parameters[U_TEXTURE_BLEND_ENABLE], 1);
    glUniform1i(m_parameters[U_TEXTURE_BLEND_ENABLE], 0);

    modelStack.PushMatrix();
    modelStack.Scale(3000.f, 350.0f, 3000.f);
    RenderMesh(meshList[GEO_TERRAIN], false);
    modelStack.PopMatrix();
}

void SceneSP3::RenderSprite()
{
    //modelStack.PushMatrix();
    //modelStack.Translate(SPRITENAME->SpritePos.x, SPRITENAME->SpritePos.y, SPRITENAME->SpritePos.z);
    //modelStack.Rotate(SPRITENAME->SpriteAngle, 0, 1, 0);
    //modelStack.Scale(30, 30, 30);
    //RenderMesh(meshList[SPRITE_NAME], false);
    //modelStack.PopMatrix();
}

void SceneSP3::RenderOBJ()
{

}

ParticleObject* SceneSP3::GetParticle_NAME()
{
//    for (auto it : particleList)
//    {
//        ParticleObject *particle = (ParticleObject *)it;
//        if (!particle->active)
//        {
//            particle->active = true;
//            m_particleCount++;
//            return particle;
//        }
//    }
//
//    for (unsigned i = 0; i <= 1; ++i)
//    {
//        ParticleObject *particle = new ParticleObject(PARTICLEOBJECT_TYPE::P_NAME);
//        particleList.push_back(particle);
//    }
//
//    ParticleObject *particle = particleList.back();
//    particle->active = true;
//    m_particleCount++;
//
//    return particle;
    return 0;
}

void SceneSP3::UpdateParticles(double dt)
{
    //ParticleObject* P_NAME = GetParticle_NAME();
    //P_NAME->type = PARTICLEOBJECT_TYPE::P_NAME;
    //P_NAME->scale.Set(1.5f, 1.5f, 1.5f);
    //P_NAME->vel.Set(Math::RandFloatMinMax(-3.f, 3.f), Math::RandFloatMinMax(0, 8.f), Math::RandFloatMinMax(-3.f, 3.f));
    //P_NAME->rotateSpeed = Math::RandFloatMinMax(20.f, 40.f);
    //P_NAME->pos.Set(0, 0, 0);

    //for (auto it : particleList)
    //{
    //    ParticleObject* particle = (ParticleObject*)it;
    //    if (particle->active)
    //    {
    //        if (particle->type == PARTICLEOBJECT_TYPE::P_NAME)
    //        {
    //            particle->vel += m_gravity * (float)dt;
    //            particle->pos += particle->vel  * (float)dt * 10.f;
    //            particle->rotation = Math::RadianToDegree(atan2(camera.position.x - particle->pos.x, camera.position.z - particle->pos.z));
    //            particle->scale -= Vector3(.01f, .01f, .01f);
    //        }

    //        if (particle->scale.x <= 0 ||
    //            particle->scale.y <= 0 ||
    //            particle->scale.z <= 0)
    //        {
    //            particle->active = false;
    //            m_particleCount--;
    //        }

    //        // If particle reaches below terrain
    //        if (particle->pos.y < (350.f * ReadHeightMap(m_heightMap, particle->pos.x / 4000.0f, particle->pos.z / 4000.0f)))
    //        {
    //            particle->active = false;
    //            m_particleCount--;
    //        }
    //    }
    //}
}

void SceneSP3::RenderParticles()
{
    //for (auto it : particleList)
    //{
    //    ParticleObject* particle = (ParticleObject*)it;
    //    if (particle->active)
    //    {
    //        if (particle->type == PARTICLEOBJECT_TYPE::P_NAME)
    //        {
    //            modelStack.PushMatrix();
    //            modelStack.Translate(particle->pos.x, particle->pos.y, particle->pos.z);
    //            modelStack.Rotate(particle->rotation, 0, 1, 0);
    //            modelStack.Scale(particle->scale.x, particle->scale.y, particle->scale.z);
    //            RenderMesh(meshList[PARTICLE_NAME], false);
    //            modelStack.PopMatrix();
    //        }
    //    }
    //}
}

void SceneSP3::RenderWorld()
{
    //glUniform1i(m_parameters[U_FOG_ENABLE], 1);
   // glUniform1i(m_parameters[U_TEXTURE_BLEND_ENABLE], 1);
   // RenderSkyPlane();
    //glUniform1i(m_parameters[U_TEXTURE_BLEND_ENABLE], 0);
    RenderTerrain();
    //RenderSprite();
    RenderOBJ();
    RenderParticles();
	modelStack.PushMatrix();
	{
		Vector3 p = walkCam.GetPos();
		modelStack.Translate(p.x, p.y, p.z);
		modelStack.Rotate(90 + fishRot.y, 0, 1, 0);
		modelStack.Rotate(0 + fishRot.x, 1, 0, 0);
		modelStack.Scale(3, 3, 3);
		RenderMesh(meshList[GEO_FISHMODEL], true);
	}
	modelStack.PopMatrix();
    //glUniform1i(m_parameters[U_FOG_ENABLE], 0);
}

void SceneSP3::RenderFO(Minnow *fo)
{
    switch (fo->seaType)
    {
    case SeaCreature::MINNOW:
    {
        float rotate = 0;
        rotate = Math::RadianToDegree(atan2(fo->vel.z, fo->vel.x));
        modelStack.PushMatrix();
        modelStack.Translate(fo->pos.x, fo->pos.y, fo->pos.z);
        modelStack.Rotate(rotate, 0, 1, 0);
        modelStack.Scale(fo->scale.x, fo->scale.y, fo->scale.z);
        RenderMesh(meshList[GEO_BALL], false);
        modelStack.PopMatrix();
        break;
    }
    }
}

void SceneSP3::RenderPO(Projectile *po)
{
    modelStack.PushMatrix();
    modelStack.Translate(po->pos.x, po->pos.y, po->pos.z);
    modelStack.Scale(po->scale.x, po->scale.y, po->scale.z);
    RenderMesh(meshList[GEO_BALL], false);
    modelStack.PopMatrix();
}

void SceneSP3::RenderPassGPass()
{
    m_renderPass = RENDER_PASS_PRE;
    m_lightDepthFBO.BindForWriting();

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glClear(GL_DEPTH_BUFFER_BIT);

    glUseProgram(m_gPassShaderID);

    //these matrices define shadows from light position/direction
    if (lights[0].type == Light::LIGHT_DIRECTIONAL)
        m_lightDepthProj.SetToOrtho(-1000, 1000, -1000, 1000, -8000, 8000);
    else
        m_lightDepthProj.SetToPerspective(90, 1.f, 0.1, 20);

    m_lightDepthView.SetToLookAt(lights[0].position.x, lights[0].position.y, lights[0].position.z, 0, 0, 0, 0, 1, 0);

    RenderWorld();
}

void SceneSP3::RenderPassMain()
{
    m_renderPass = RENDER_PASS_MAIN;

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glViewport(0, 0, Application::GetWindowWidth(), Application::GetWindowHeight());

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(m_programID);

    // Shadow - pass light depth texture
    m_lightDepthFBO.BindForReading(GL_TEXTURE8);

    glUniform1i(m_parameters[U_SHADOW_MAP], 8);

    //Mtx44 perspective;
    //perspective.SetToPerspective(45.0f, 4.0f / 3.0f, 0.1f, 10000.0f);
    ////perspective.SetToOrtho(-80, 80, -60, 60, -1000, 1000);
    //projectionStack.LoadMatrix(perspective);

    // Camera matrix
    /*viewStack.LoadIdentity();
    viewStack.LookAt(
        camera.position.x, camera.position.y, camera.position.z,
        camera.target.x, camera.target.y, camera.target.z,
        camera.up.x, camera.up.y, camera.up.z
        );*/
	projectionStack.LoadMatrix(currentCam->GetProjection());
	viewStack.LoadMatrix(currentCam->GetView());
    // Model matrix : an identity matrix (model will be at the origin)
    modelStack.LoadIdentity();

    if (lights[0].type == Light::LIGHT_DIRECTIONAL)
    {
        Vector3 lightDir(lights[0].position.x, lights[0].position.y, lights[0].position.z);
        Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
        glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightDirection_cameraspace.x);
    }
    else if (lights[0].type == Light::LIGHT_SPOT)
    {
        Position lightPosition_cameraspace = viewStack.Top() * lights[0].position;
        glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);
        Vector3 spotDirection_cameraspace = viewStack.Top() * lights[0].spotDirection;
        glUniform3fv(m_parameters[U_LIGHT0_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
    }
    else
    {
        Position lightPosition_cameraspace = viewStack.Top() * lights[0].position;
        glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);
    }

    if (lights[1].type == Light::LIGHT_DIRECTIONAL)
    {
        Vector3 lightDir(lights[1].position.x, lights[1].position.y, lights[1].position.z);
        Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
        glUniform3fv(m_parameters[U_LIGHT1_POSITION], 1, &lightDirection_cameraspace.x);
    }


    if (lights[2].type == Light::LIGHT_SPOT)
    {
        Position lightPosition_cameraspace = viewStack.Top() * lights[2].position;
        glUniform3fv(m_parameters[U_LIGHT2_POSITION], 1, &lightPosition_cameraspace.x);
        Vector3 spotDirection_cameraspace = viewStack.Top() * lights[2].spotDirection;
        glUniform3fv(m_parameters[U_LIGHT2_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
    }

    glEnable(GL_SAMPLE_ALPHA_TO_COVERAGE);
    RenderWorld();

    for (std::vector<GameObject *>::iterator it = m_goList.begin(); it != m_goList.end(); ++it)
    {
        GameObject *go = (GameObject*)*it;
        if (go->objectType == GameObject::SEACREATURE)
        {
            Minnow *fo = (Minnow*)*it;
            if (fo->active)
            {
                RenderFO(fo);
            }
        }
        else if (go->objectType == GameObject::PROJECTILE)
        {
            Projectile *po = (Projectile*)*it;
            if (po->active)
            {
                RenderPO(po);
            }
        }
    }

    // Render the crosshair
    RenderMeshIn2D(meshList[GEO_CROSSHAIR], false, 10.0f);
	RenderMesh(meshList[GEO_AXES], false);
    std::ostringstream ss;
    ss.precision(3);
    ss << "FPS: " << fps;
    RenderTextOnScreen(meshList[GEO_TEXT], ss.str(), Color(0, 1, 0), 3, 2, 3);
	
	modelStack.PushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);	//set to line
	modelStack.Translate(player_box.m_position.x, player_box.m_position.y, player_box.m_position.z);
	modelStack.Scale(player_box.m_width, player_box.m_height, player_box.m_length);
	RenderMesh(meshList[GEO_CUBE], false);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	//set back to fill
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(fishy.GetPos().x, fishy.GetPos().y, fishy.GetPos().z);
	modelStack.Scale(10, 10, 10);
	RenderMesh(meshList[GEO_CUBE], false);
	modelStack.PopMatrix();
}

void SceneSP3::Render()
{
    // PRE RENDER PASS
    RenderPassGPass();

    // MAIN RENDER PASS
    RenderPassMain();
}

void SceneSP3::Exit()
{
    // Cleanup VBO
    for (int i = 0; i < NUM_GEOMETRY; ++i)
    {
        if (meshList[i])
            delete meshList[i];
    }

    while (particleList.size() > 0)
    {
        ParticleObject *particle = particleList.back();
        delete particle;
        particleList.pop_back();
    }
    glDeleteProgram(m_programID);
    glDeleteProgram(m_gPassShaderID);
    glDeleteVertexArrays(1, &m_vertexArrayID);
}
