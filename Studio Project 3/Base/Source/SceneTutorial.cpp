#include "SceneTutorial.h"
#include "GL\glew.h"
#include "Application.h"
#include <sstream>

SceneTutorial::SceneTutorial()
{

}

SceneTutorial::~SceneTutorial()
{

}

void SceneTutorial::Init()
{
	SceneSP3::Init();
	currentCam = &walkCam;
	walkCam.Init(
		Vector3(325, 604, 700),
		Vector3(0, 0, -10),
		Vector3(0, 1, 0),
		60
		);
	//m_travelzone = hitbox::generatehitbox(Vector3(0,500,0),600,500,600,0);

    InitGiantSquid();
}

void SceneTutorial::ReInit()
{

	//walkCam.Init(
	//	Vector3(325, 604, 700),
	//	Vector3(0, 0, -10),
	//	Vector3(0, 1, 0),
	//	60
	//	);
	walkCam.SetPos(Vector3(325, 604, 700));
	std::cout << "shit" << std::endl;

	//SharedData::GetInstance()->SD_Travel = true;

	m_travelzonedown = hitbox::generatehitbox(Vector3(52, 579, 1310), 600, 500, 600, 0);

	std::cout << "tut" << std::endl;
}

void SceneTutorial::InitGiantSquid()
{
    giantSquid = new GiantSquid();
    giantSquid->active = true;
    giantSquid->objectType = GameObject::BOSS;
    giantSquid->bossType = Boss::GIANTSQUID;
    giantSquid->state = GiantSquid::IDLE;
    giantSquid->scale.Set(30, 30, 30);
    giantSquid->pos.Set(0, 500, 0);
    giantSquid->vel.Set(0, 0, 0);
    giantSquid->rotateTentacle = 0.f;
    giantSquid->isTentacleUp = false;
    giantSquid->translateSquid = 0.f;
    giantSquid->isSquidUp = false;
    giantSquid->collision = hitbox::generatehitbox(giantSquid->pos + Vector3(0, 80, 0), 55, 150, 55, 0);

    giantSquid->tentacle1_1.setTentaclePos(Vector3(-.25f, .1f, -.15f));
    giantSquid->tentacle1_2.setTentaclePos(Vector3(0, -1.f, 0));
    giantSquid->tentacle1_3.setTentaclePos(Vector3(0, -1.f, 0));
    giantSquid->tentacle1_4.setTentaclePos(Vector3(0, -1.f, 0));
    giantSquid->tentacle1_1.setTentacleInitialRotate(135.f);
    giantSquid->tentacle1_1.setHealth(400);
    giantSquid->tentacle1_2.setHealth(200);
    giantSquid->tentacle1_3.setHealth(100);
    giantSquid->tentacle1_4.setHealth(50);
    giantSquid->tentacle1_1.collision = hitbox::generatehitbox(giantSquid->tentacle1_1.getTentaclePos() + Vector3(0, 80, 0), 55, 150, 55, 0);

    giantSquid->tentacle2_1.setTentaclePos(Vector3(-.25f, .1f, .15f));
    giantSquid->tentacle2_2.setTentaclePos(Vector3(0, -1.f, 0));
    giantSquid->tentacle2_3.setTentaclePos(Vector3(0, -1.f, 0));
    giantSquid->tentacle2_4.setTentaclePos(Vector3(0, -1.f, 0));
    giantSquid->tentacle2_1.setTentacleInitialRotate(225.f);
    giantSquid->tentacle2_1.setHealth(400);
    giantSquid->tentacle2_2.setHealth(200);
    giantSquid->tentacle2_3.setHealth(100);
    giantSquid->tentacle2_4.setHealth(50);

    giantSquid->tentacle3_1.setTentaclePos(Vector3(.15f, .1f, -.15f));
    giantSquid->tentacle3_2.setTentaclePos(Vector3(0, -1.f, 0));
    giantSquid->tentacle3_3.setTentaclePos(Vector3(0, -1.f, 0));
    giantSquid->tentacle3_4.setTentaclePos(Vector3(0, -1.f, 0));
    giantSquid->tentacle3_1.setTentacleInitialRotate(45.f);
    giantSquid->tentacle3_1.setHealth(400);
    giantSquid->tentacle3_2.setHealth(200);
    giantSquid->tentacle3_3.setHealth(100);
    giantSquid->tentacle3_4.setHealth(50);

    giantSquid->tentacle4_1.setTentaclePos(Vector3(.15f, .1f, .15f));
    giantSquid->tentacle4_2.setTentaclePos(Vector3(0, -1.f, 0));
    giantSquid->tentacle4_3.setTentaclePos(Vector3(0, -1.f, 0));
    giantSquid->tentacle4_4.setTentaclePos(Vector3(0, -1.f, 0));
    giantSquid->tentacle4_1.setTentacleInitialRotate(-45.f);
    giantSquid->tentacle4_1.setHealth(400);
    giantSquid->tentacle4_2.setHealth(200);
    giantSquid->tentacle4_3.setHealth(100);
    giantSquid->tentacle4_4.setHealth(50);

    giantSquid->tentacle5_1.setTentaclePos(Vector3(-.05f, .1f, -.35f));
    giantSquid->tentacle5_2.setTentaclePos(Vector3(0, -1.f, 0));
    giantSquid->tentacle5_3.setTentaclePos(Vector3(0, -1.f, 0));
    giantSquid->tentacle5_4.setTentaclePos(Vector3(0, -1.f, 0));
    giantSquid->tentacle5_1.setTentacleInitialRotate(90.f);
    giantSquid->tentacle5_1.setHealth(400);
    giantSquid->tentacle5_2.setHealth(200);
    giantSquid->tentacle5_3.setHealth(100);
    giantSquid->tentacle5_4.setHealth(50);

    giantSquid->tentacle6_1.setTentaclePos(Vector3(-.05f, .1f, .35f));
    giantSquid->tentacle6_2.setTentaclePos(Vector3(0, -1.f, 0));
    giantSquid->tentacle6_3.setTentaclePos(Vector3(0, -1.f, 0));
    giantSquid->tentacle6_4.setTentaclePos(Vector3(0, -1.f, 0));
    giantSquid->tentacle6_1.setTentacleInitialRotate(-90.f);
    giantSquid->tentacle6_1.setHealth(400);
    giantSquid->tentacle6_2.setHealth(200);
    giantSquid->tentacle6_3.setHealth(100);
    giantSquid->tentacle6_4.setHealth(50);

    m_goList.push_back(giantSquid);
}

void SceneTutorial::RenderTerrain()
{
	modelStack.PushMatrix();
	modelStack.Scale(3000.f, 350.0f, 3000.f);
	RenderMesh(meshList[GEO_TERRAIN0], true);
	modelStack.PopMatrix();

}

void SceneTutorial::RenderSkyPlane()
{
	modelStack.PushMatrix();
	modelStack.Translate(0, 2000, 0);
	modelStack.Rotate(rotateSky, 0, 1, 0);
	RenderMesh(meshList[GEO_SKYPLANE], true);
	modelStack.PopMatrix();
}

void SceneTutorial::RenderParticles()
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

void SceneTutorial::RenderBO(Boss* bo)
{
    if (giantSquid)
    {
        modelStack.PushMatrix();
        modelStack.Translate(giantSquid->pos.x, giantSquid->pos.y, giantSquid->pos.z);
        modelStack.Scale(giantSquid->scale.x, giantSquid->scale.y, giantSquid->scale.z);
        RenderMesh(meshList[GEO_SQUIDBODY], false);

        // Part 1
        if (giantSquid->tentacle1_1.getHealth() > 0)
        {
            modelStack.PushMatrix();
            modelStack.Translate(giantSquid->tentacle1_1.getTentaclePos().x, giantSquid->tentacle1_1.getTentaclePos().y, giantSquid->tentacle1_1.getTentaclePos().z);
            modelStack.Rotate(giantSquid->tentacle1_1.getTentacleInitialRotate(), 0, 1, 0);
            modelStack.Rotate(giantSquid->tentacle1_1.getTentacleAnimateRotate(), 0, 0, 1);
            RenderMesh(meshList[GEO_SQUIDTENTACLENODE], false);

            if (giantSquid->tentacle1_2.getHealth() > 0)
            {
                modelStack.PushMatrix();
                modelStack.Translate(giantSquid->tentacle1_2.getTentaclePos().x, giantSquid->tentacle1_2.getTentaclePos().y, giantSquid->tentacle1_2.getTentaclePos().z);
                modelStack.Rotate(giantSquid->tentacle1_2.getTentacleAnimateRotate(), 0, 0, 1);
                RenderMesh(meshList[GEO_SQUIDTENTACLENODE], false);

                if (giantSquid->tentacle1_3.getHealth() > 0)
                {
                    modelStack.PushMatrix();
                    modelStack.Translate(giantSquid->tentacle1_3.getTentaclePos().x, giantSquid->tentacle1_3.getTentaclePos().y, giantSquid->tentacle1_3.getTentaclePos().z);
                    modelStack.Rotate(giantSquid->tentacle1_3.getTentacleAnimateRotate(), 0, 0, 1);
                    RenderMesh(meshList[GEO_SQUIDTENTACLENODE], false);

                    if (giantSquid->tentacle1_4.getHealth() > 0)
                    {
                        modelStack.PushMatrix();
                        modelStack.Translate(giantSquid->tentacle1_4.getTentaclePos().x, giantSquid->tentacle1_4.getTentaclePos().y, giantSquid->tentacle1_4.getTentaclePos().z);
                        modelStack.Rotate(giantSquid->tentacle1_4.getTentacleAnimateRotate(), 0, 0, 1);
                        RenderMesh(meshList[GEO_SQUIDTENTACLEEND], false);
                        
                        modelStack.PopMatrix();
                    }
                    modelStack.PopMatrix();
                }
                modelStack.PopMatrix();
            }
            modelStack.PopMatrix();
        }

        // Part 2
        if (giantSquid->tentacle2_1.getHealth() > 0)
        {
            modelStack.PushMatrix();
            modelStack.Translate(giantSquid->tentacle2_1.getTentaclePos().x, giantSquid->tentacle2_1.getTentaclePos().y, giantSquid->tentacle2_1.getTentaclePos().z);
            modelStack.Rotate(giantSquid->tentacle2_1.getTentacleInitialRotate(), 0, 1, 0);
            modelStack.Rotate(giantSquid->tentacle2_1.getTentacleAnimateRotate(), 0, 0, 1);
            RenderMesh(meshList[GEO_SQUIDTENTACLENODE], false);

            if (giantSquid->tentacle2_2.getHealth() > 0)
            {
                modelStack.PushMatrix();
                modelStack.Translate(giantSquid->tentacle2_2.getTentaclePos().x, giantSquid->tentacle2_2.getTentaclePos().y, giantSquid->tentacle2_2.getTentaclePos().z);
                modelStack.Rotate(giantSquid->tentacle2_2.getTentacleAnimateRotate(), 0, 0, 1);
                RenderMesh(meshList[GEO_SQUIDTENTACLENODE], false);

                if (giantSquid->tentacle2_3.getHealth() > 0)
                {
                    modelStack.PushMatrix();
                    modelStack.Translate(giantSquid->tentacle2_3.getTentaclePos().x, giantSquid->tentacle2_3.getTentaclePos().y, giantSquid->tentacle2_3.getTentaclePos().z);
                    modelStack.Rotate(giantSquid->tentacle2_3.getTentacleAnimateRotate(), 0, 0, 1);
                    RenderMesh(meshList[GEO_SQUIDTENTACLENODE], false);

                    if (giantSquid->tentacle2_4.getHealth() > 0)
                    {
                        modelStack.PushMatrix();
                        modelStack.Translate(giantSquid->tentacle2_4.getTentaclePos().x, giantSquid->tentacle2_4.getTentaclePos().y, giantSquid->tentacle2_4.getTentaclePos().z);
                        modelStack.Rotate(giantSquid->tentacle2_4.getTentacleAnimateRotate(), 0, 0, 1);
                        RenderMesh(meshList[GEO_SQUIDTENTACLEEND], false);

                        modelStack.PopMatrix();
                    }
                    modelStack.PopMatrix();
                }
                modelStack.PopMatrix();
            }
            modelStack.PopMatrix();
        }

        // Part 3
        if (giantSquid->tentacle3_1.getHealth() > 0)
        {
            modelStack.PushMatrix();
            modelStack.Translate(giantSquid->tentacle3_1.getTentaclePos().x, giantSquid->tentacle3_1.getTentaclePos().y, giantSquid->tentacle3_1.getTentaclePos().z);
            modelStack.Rotate(giantSquid->tentacle3_1.getTentacleInitialRotate(), 0, 1, 0);
            modelStack.Rotate(giantSquid->tentacle3_1.getTentacleAnimateRotate(), 0, 0, 1);
            RenderMesh(meshList[GEO_SQUIDTENTACLENODE], false);

            if (giantSquid->tentacle3_2.getHealth() > 0)
            {
                modelStack.PushMatrix();
                modelStack.Translate(giantSquid->tentacle3_2.getTentaclePos().x, giantSquid->tentacle3_2.getTentaclePos().y, giantSquid->tentacle3_2.getTentaclePos().z);
                modelStack.Rotate(giantSquid->tentacle3_2.getTentacleAnimateRotate(), 0, 0, 1);
                RenderMesh(meshList[GEO_SQUIDTENTACLENODE], false);

                if (giantSquid->tentacle3_3.getHealth() > 0)
                {
                    modelStack.PushMatrix();
                    modelStack.Translate(giantSquid->tentacle3_3.getTentaclePos().x, giantSquid->tentacle3_3.getTentaclePos().y, giantSquid->tentacle3_3.getTentaclePos().z);
                    modelStack.Rotate(giantSquid->tentacle3_3.getTentacleAnimateRotate(), 0, 0, 1);
                    RenderMesh(meshList[GEO_SQUIDTENTACLENODE], false);

                    if (giantSquid->tentacle3_4.getHealth() > 0)
                    {
                        modelStack.PushMatrix();
                        modelStack.Translate(giantSquid->tentacle3_4.getTentaclePos().x, giantSquid->tentacle3_4.getTentaclePos().y, giantSquid->tentacle3_4.getTentaclePos().z);
                        modelStack.Rotate(giantSquid->tentacle3_4.getTentacleAnimateRotate(), 0, 0, 1);
                        RenderMesh(meshList[GEO_SQUIDTENTACLEEND], false);

                        modelStack.PopMatrix();
                    }
                    modelStack.PopMatrix();
                }
                modelStack.PopMatrix();
            }
            modelStack.PopMatrix();
        }

        // Part 4
        if (giantSquid->tentacle4_1.getHealth() > 0)
        {
            modelStack.PushMatrix();
            modelStack.Translate(giantSquid->tentacle4_1.getTentaclePos().x, giantSquid->tentacle4_1.getTentaclePos().y, giantSquid->tentacle4_1.getTentaclePos().z);
            modelStack.Rotate(giantSquid->tentacle4_1.getTentacleInitialRotate(), 0, 1, 0);
            modelStack.Rotate(giantSquid->tentacle4_1.getTentacleAnimateRotate(), 0, 0, 1);
            RenderMesh(meshList[GEO_SQUIDTENTACLENODE], false);

            if (giantSquid->tentacle4_2.getHealth() > 0)
            {
                modelStack.PushMatrix();
                modelStack.Translate(giantSquid->tentacle4_2.getTentaclePos().x, giantSquid->tentacle4_2.getTentaclePos().y, giantSquid->tentacle4_2.getTentaclePos().z);
                modelStack.Rotate(giantSquid->tentacle4_2.getTentacleAnimateRotate(), 0, 0, 1);
                RenderMesh(meshList[GEO_SQUIDTENTACLENODE], false);

                if (giantSquid->tentacle4_3.getHealth() > 0)
                {
                    modelStack.PushMatrix();
                    modelStack.Translate(giantSquid->tentacle4_3.getTentaclePos().x, giantSquid->tentacle4_3.getTentaclePos().y, giantSquid->tentacle4_3.getTentaclePos().z);
                    modelStack.Rotate(giantSquid->tentacle4_3.getTentacleAnimateRotate(), 0, 0, 1);
                    RenderMesh(meshList[GEO_SQUIDTENTACLENODE], false);

                    if (giantSquid->tentacle4_4.getHealth() > 0)
                    {
                        modelStack.PushMatrix();
                        modelStack.Translate(giantSquid->tentacle4_4.getTentaclePos().x, giantSquid->tentacle4_4.getTentaclePos().y, giantSquid->tentacle4_4.getTentaclePos().z);
                        modelStack.Rotate(giantSquid->tentacle4_4.getTentacleAnimateRotate(), 0, 0, 1);
                        RenderMesh(meshList[GEO_SQUIDTENTACLEEND], false);

                        modelStack.PopMatrix();
                    }
                    modelStack.PopMatrix();
                }
                modelStack.PopMatrix();
            }
            modelStack.PopMatrix();
        }

        // Part 5
        if (giantSquid->tentacle5_1.getHealth() > 0)
        {
            modelStack.PushMatrix();
            modelStack.Translate(giantSquid->tentacle5_1.getTentaclePos().x, giantSquid->tentacle5_1.getTentaclePos().y, giantSquid->tentacle5_1.getTentaclePos().z);
            modelStack.Rotate(giantSquid->tentacle5_1.getTentacleInitialRotate(), 0, 1, 0);
            modelStack.Rotate(giantSquid->tentacle5_1.getTentacleAnimateRotate(), 0, 0, 1);
            RenderMesh(meshList[GEO_SQUIDTENTACLENODE], false);

            if (giantSquid->tentacle5_2.getHealth() > 0)
            {
                modelStack.PushMatrix();
                modelStack.Translate(giantSquid->tentacle5_2.getTentaclePos().x, giantSquid->tentacle5_2.getTentaclePos().y, giantSquid->tentacle5_2.getTentaclePos().z);
                modelStack.Rotate(giantSquid->tentacle5_2.getTentacleAnimateRotate(), 0, 0, 1);
                RenderMesh(meshList[GEO_SQUIDTENTACLENODE], false);

                if (giantSquid->tentacle5_3.getHealth() > 0)
                {
                    modelStack.PushMatrix();
                    modelStack.Translate(giantSquid->tentacle5_3.getTentaclePos().x, giantSquid->tentacle5_3.getTentaclePos().y, giantSquid->tentacle5_3.getTentaclePos().z);
                    modelStack.Rotate(giantSquid->tentacle5_3.getTentacleAnimateRotate(), 0, 0, 1);
                    RenderMesh(meshList[GEO_SQUIDTENTACLENODE], false);

                    if (giantSquid->tentacle5_4.getHealth() > 0)
                    {
                        modelStack.PushMatrix();
                        modelStack.Translate(giantSquid->tentacle5_4.getTentaclePos().x, giantSquid->tentacle5_4.getTentaclePos().y, giantSquid->tentacle5_4.getTentaclePos().z);
                        modelStack.Rotate(giantSquid->tentacle5_4.getTentacleAnimateRotate(), 0, 0, 1);
                        RenderMesh(meshList[GEO_SQUIDTENTACLEEND], false);

                        modelStack.PopMatrix();
                    }
                    modelStack.PopMatrix();
                }
                modelStack.PopMatrix();
            }
            modelStack.PopMatrix();
        }

        // Part 6
        if (giantSquid->tentacle6_1.getHealth() > 0)
        {
            modelStack.PushMatrix();
            modelStack.Translate(giantSquid->tentacle6_1.getTentaclePos().x, giantSquid->tentacle6_1.getTentaclePos().y, giantSquid->tentacle6_1.getTentaclePos().z);
            modelStack.Rotate(giantSquid->tentacle6_1.getTentacleInitialRotate(), 0, 1, 0);
            modelStack.Rotate(giantSquid->tentacle6_1.getTentacleAnimateRotate(), 0, 0, 1);
            RenderMesh(meshList[GEO_SQUIDTENTACLENODE], false);

            if (giantSquid->tentacle6_2.getHealth() > 0)
            {
                modelStack.PushMatrix();
                modelStack.Translate(giantSquid->tentacle6_2.getTentaclePos().x, giantSquid->tentacle6_2.getTentaclePos().y, giantSquid->tentacle6_2.getTentaclePos().z);
                modelStack.Rotate(giantSquid->tentacle6_2.getTentacleAnimateRotate(), 0, 0, 1);
                RenderMesh(meshList[GEO_SQUIDTENTACLENODE], false);

                if (giantSquid->tentacle6_3.getHealth() > 0)
                {
                    modelStack.PushMatrix();
                    modelStack.Translate(giantSquid->tentacle6_3.getTentaclePos().x, giantSquid->tentacle6_3.getTentaclePos().y, giantSquid->tentacle6_3.getTentaclePos().z);
                    modelStack.Rotate(giantSquid->tentacle6_3.getTentacleAnimateRotate(), 0, 0, 1);
                    RenderMesh(meshList[GEO_SQUIDTENTACLENODE], false);

                    if (giantSquid->tentacle6_4.getHealth() > 0)
                    {
                        modelStack.PushMatrix();
                        modelStack.Translate(giantSquid->tentacle6_4.getTentaclePos().x, giantSquid->tentacle6_4.getTentaclePos().y, giantSquid->tentacle6_4.getTentaclePos().z);
                        modelStack.Rotate(giantSquid->tentacle6_4.getTentacleAnimateRotate(), 0, 0, 1);
                        RenderMesh(meshList[GEO_SQUIDTENTACLEEND], false);

                        modelStack.PopMatrix();
                    }
                    modelStack.PopMatrix();
                }
                modelStack.PopMatrix();
            }
            modelStack.PopMatrix();
        }

        modelStack.PopMatrix();
    }
}

void SceneTutorial::RenderWorld()
{
	RenderTerrain();
	RenderSkyPlane();
	modelStack.PushMatrix();
	modelStack.Translate(playerpos.x, playerpos.y+5, playerpos.z);
	modelStack.Rotate(90 + fishRot.y, 0, 1, 0);
	modelStack.Rotate(0 + fishRot.x, 1, 0, 0);
	modelStack.Scale(15,15,15);
	RenderMesh(meshList[GEO_FISHMODEL], true);
	modelStack.PushMatrix();
	modelStack.Scale(1, 1, 1);
	modelStack.Translate(0,-0.02,-1.2);
	modelStack.Rotate(fish_tailrot, 0, 1, 0);

	RenderMesh(meshList[GEO_FISHTAIL], true);
	modelStack.PopMatrix();
	modelStack.PopMatrix();
}

void SceneTutorial::RenderPassGPass()
{
	m_renderPass = RENDER_PASS_PRE;
	m_lightDepthFBO.BindForWriting();

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glClear(GL_DEPTH_BUFFER_BIT);

	glUseProgram(m_gPassShaderID);
	RenderWorld();
	//these matrices define shadows from light position/direction
	//if (lights[0].type == Light::LIGHT_DIRECTIONAL)
	//	m_lightDepthProj.SetToOrtho(-1000, 1000, -1000, 1000, -8000, 8000);
	//else
	//	m_lightDepthProj.SetToPerspective(90, 1.f, 0.1, 20);

	//m_lightDepthView.SetToLookAt(lights[0].position.x, lights[0].position.y, lights[0].position.z, 0, 0, 0, 0, 1, 0);


}

void SceneTutorial::RenderPassMain()
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
	glUniform1i(m_parameters[U_FOG_ENABLE], 1);
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
	RenderWorld();
	/*if (lights[0].type == Light::LIGHT_DIRECTIONAL)
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
*/
	glEnable(GL_SAMPLE_ALPHA_TO_COVERAGE);

	for (std::vector<GameObject *>::iterator it = m_goList.begin(); it != m_goList.end(); ++it)
	{
		GameObject *go = (GameObject*)*it;
		if (go->objectType == GameObject::SEACREATURE)
		{
			Minnow *fo = (Minnow*)*it;
			if (fo->active)
			{
				RenderFO(fo);
                //modelStack.PushMatrix();
                //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);	//set to line
                //modelStack.Translate(fo->pos.x, fo->pos.y, fo->pos.z);
                //modelStack.Scale(fo->collision.m_width, fo->collision.m_height, fo->collision.m_length);
                //RenderMesh(meshList[GEO_CUBE], false);
                //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	//set back to fill
                //modelStack.PopMatrix();
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
        else if (go->objectType == GameObject::BOSS)
        {
            Boss *bo = (Boss*)*it;
            if (bo->active)
            {
                RenderBO(bo);

                modelStack.PushMatrix();
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);	//set to line
                modelStack.Translate(bo->collision.m_position.x, bo->collision.m_position.y, bo->collision.m_position.z);
                modelStack.Scale(bo->collision.m_width, bo->collision.m_height, bo->collision.m_length);
                RenderMesh(meshList[GEO_CUBE], false);
                glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	//set back to fill
                modelStack.PopMatrix();

                //modelStack.PushMatrix();
                //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);	//set to line
                //modelStack.Translate(bo->giantSquid->tentacle1_1.collision.m_position.x, bo->collision.m_position.y, bo->collision.m_position.z);
                //modelStack.Scale(bo->collision.m_width, bo->collision.m_height, bo->collision.m_length);
                //RenderMesh(meshList[GEO_CUBE], false);
                //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	//set back to fill
                //modelStack.PopMatrix();

                //modelStack.PushMatrix();
                //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);	//set to line
                //modelStack.Translate(bo->collision.m_position.x, bo->collision.m_position.y, bo->collision.m_position.z);
                //modelStack.Scale(bo->collision.m_width, bo->collision.m_height, bo->collision.m_length);
                //RenderMesh(meshList[GEO_CUBE], false);
                //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	//set back to fill
                //modelStack.PopMatrix();

                //modelStack.PushMatrix();
                //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);	//set to line
                //modelStack.Translate(bo->collision.m_position.x, bo->collision.m_position.y, bo->collision.m_position.z);
                //modelStack.Scale(bo->collision.m_width, bo->collision.m_height, bo->collision.m_length);
                //RenderMesh(meshList[GEO_CUBE], false);
                //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	//set back to fill
                //modelStack.PopMatrix();

                //modelStack.PushMatrix();
                //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);	//set to line
                //modelStack.Translate(bo->collision.m_position.x, bo->collision.m_position.y, bo->collision.m_position.z);
                //modelStack.Scale(bo->collision.m_width, bo->collision.m_height, bo->collision.m_length);
                //RenderMesh(meshList[GEO_CUBE], false);
                //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	//set back to fill
                //modelStack.PopMatrix();
            }
        }
	}

    //modelStack.PushMatrix();
    //modelStack.Translate(0, 300, 0);
    //modelStack.Rotate(Math::RadianToDegree(sin(rotater)), 0, 1, 0);
    //modelStack.Scale(50, 50, 50);
    //RenderMesh(meshList[GEO_CUBE], false);
    //modelStack.PopMatrix();

	// Render the crosshair
	glUniform1i(m_parameters[U_IS_GUI], 1);
	RenderMeshIn2D(meshList[GEO_CROSSHAIR], false, 10.0f);
	RenderMesh(meshList[GEO_AXES], false);
	glUniform1i(m_parameters[U_IS_GUI], 0);
	std::ostringstream ss;
	ss.precision(3);
	ss << "FPS: " << fps;
	RenderTextOnScreen(meshList[GEO_TEXT], ss.str(), Color(0, 1, 0), 3, 2, 3);
	glUniform1i(m_parameters[U_FOG_ENABLE], 0);
	RenderMinimap();
	glUniform1i(m_parameters[U_FOG_ENABLE], 1);

	modelStack.PushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);	//set to line
	modelStack.Translate(m_travelzonedown.m_position.x, m_travelzonedown.m_position.y, m_travelzonedown.m_position.z);
	modelStack.Scale(m_travelzonedown.m_width, m_travelzonedown.m_height, m_travelzonedown.m_length);
	RenderMesh(meshList[GEO_CUBE], false);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	//set back to fill
	modelStack.PopMatrix();


	modelStack.PushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);	//set to line
	modelStack.Translate(m_travelzoneup.m_position.x, m_travelzoneup.m_position.y, m_travelzoneup.m_position.z);
	modelStack.Scale(m_travelzoneup.m_width, m_travelzoneup.m_height, m_travelzoneup.m_length);
	RenderMesh(meshList[GEO_CUBE], false);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	//set back to fill
	modelStack.PopMatrix();


}

void SceneTutorial::RenderMinimap()
{
	const float scale = 0.1f;
	const float range = 14.f;

	Vector2 mPos;
	mPos.Set(80 - 16 - 4, -60 + 16 + 4);

	float angle = 90 + Math::RadianToDegree(atan2(walkCam.GetDir().z, walkCam.GetDir().x));

	RenderMeshIn2D(meshList[GEO_MINIMAP], false, 20,
		mPos.x, mPos.y, angle);

	for (auto it : m_goList)
	{
		if (!it->active) continue;
		
		if (it->objectType == GameObject::SEACREATURE)
		{
			auto o1 = (SeaCreature *)it;

			if (o1->seaType == SeaCreature::MINNOW)
			{

				Vector3 op1 = o1->pos - playerpos;
				Mtx44 rot;
				rot.SetToRotation(angle, 0, 1, 0);
				op1 = rot * op1;

				Vector2 op2;
				op2.Set(op1.x * scale, -op1.z * scale);


				if (op2.LengthSquared() <= range * range)
				RenderMeshIn2D(meshList[GEO_MINIMAP_MINNOW], false, 1,
					mPos.x + op2.x, mPos.y + op2.y);
			}
		}
	}

	/*{
		static float s = 1;
		s += 0.5f;
		RenderTextOnScreen(meshList[GEO_TEXT], "FUCK YOU", (1, 1, 1), max(5, 10 * cos(s)), 0, 0);
	}*/

	RenderMeshIn2D(meshList[GEO_MINIMAP_AVATAR], false, 3.f,
		mPos.x, mPos.y);
}

void SceneTutorial::Render()
{
	// PRE RENDER PASS
	RenderPassGPass();

	// MAIN RENDER PASS
	RenderPassMain();

}

void SceneTutorial::Update(double dt)
{
	//std::cout << SharedData::GetInstance() ->SD_Travel << std::endl;
	SceneSP3::Update(dt);
	if (Application::IsKeyPressed('C'))
		std::cout << playerpos << std::endl;

    giantSquid->Animate();
    hitbox::updatehitbox(giantSquid->collision, giantSquid->collision.m_position);
}

void SceneTutorial::Exit()
{
	SceneSP3::Exit();
}