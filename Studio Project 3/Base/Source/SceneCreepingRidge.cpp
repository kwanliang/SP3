#include "SceneCreepingRidge.h"
#include "GL\glew.h"
#include "Application.h"
#include <sstream>


SceneCreepingRidge::SceneCreepingRidge()
{

}

SceneCreepingRidge::~SceneCreepingRidge()
{

}

void SceneCreepingRidge::Init()
{
	SceneSP3::Init();
	walkCam.SetPos(Vector3(0, 400, 0));
	//m_travelzonedown = hitbox::generatehitbox(Vector3(52,579,1310),600,500,600,0);

	c = FetchFcrab();
	c->active = true;
	c->objectType = GameObject::SEACREATURE;
	c->seaType = SeaCreature::FCRAB;
	//c->Cstate = Pufferfish::IDLE;
	c->scale.Set(5, 5, 5);
	c->pos.Set(0, 500, 0);
	c->vel.Set(0,0,0);
	//p->collision = hitbox2::generatehitbox(p->pos, 8, 8, 8);
	//p->setHealth(200);
}

void SceneCreepingRidge::ReInit()
{
	if (SharedData::GetInstance()->SD_Down)
	{
		walkCam.Init(
			Vector3(0, 800, 0),
			Vector3(0, 0, -10),
			Vector3(0, 1, 0),
			60
			);
	}
	else
	{
		walkCam.Init(
			Vector3(0, 800, -17),
			Vector3(0, 0, -10),
			Vector3(0, 1, 0),
			60
			);
	}
	

	m_travelzonedown = hitbox::generatehitbox(Vector3(52, 579, 1310), 600, 500, 600, 0);
	m_travelzoneup = hitbox::generatehitbox(Vector3(-1258, 389, -1221), 500, 700, 500, 0);



	std::cout << "creep" << std::endl;
}


void SceneCreepingRidge::RenderFcrab()
{
	modelStack.PushMatrix();
	modelStack.Translate(c->pos.x,c->pos.y,c->pos.z);
	//modelStack.Rotate(1 , 0, 1, 0);
	modelStack.Scale(c->scale.x,c->scale.x ,c->scale.x);
	RenderMesh(meshList[GEO_FCRABBODY], false);

	modelStack.PushMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0.15,0,-0.17);
	modelStack.Rotate(c->Crableg[0].rotate, 1, 0, 0);
	RenderMesh(meshList[GEO_FCRABLEG], false);//leg1
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-0.15,0,-0.17);
	modelStack.Rotate(c->Crableg[1].rotate, 1, 0, 0);
	RenderMesh(meshList[GEO_FCRABLEG], false);//leg2
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-0.45, 0, -0.17);
	modelStack.Rotate(c->Crableg[2].rotate, 1, 0, 0);
	RenderMesh(meshList[GEO_FCRABLEG], false);//leg3
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Rotate(180, 0, 1,0 );

	modelStack.PushMatrix();
	modelStack.Translate(-0.15, 0, -0.17);
	modelStack.Rotate(c->Crableg[3].rotate, 1, 0, 0);
	RenderMesh(meshList[GEO_FCRABLEG], false);//leg4
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0.15, 0,- 0.17);
	modelStack.Rotate(c->Crableg[4].rotate, 1, 0, 0);
	RenderMesh(meshList[GEO_FCRABLEG], false);//leg5
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0.45, 0, -0.17);
	modelStack.Rotate(c->Crableg[5].rotate, 1, 0, 0);
	RenderMesh(meshList[GEO_FCRABLEG], false);//leg6
	modelStack.PopMatrix();

	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0.17, 0, -0.35);
	modelStack.Rotate(-55, 0, 1, 0);
	RenderMesh(meshList[GEO_FCRABCLAW], false);
	modelStack.PopMatrix();

	modelStack.PopMatrix();
}

void SceneCreepingRidge::RenderTerrain()
{
	modelStack.PushMatrix();
	modelStack.Scale(3000.f, 350.0f, 3000.f);
	RenderMesh(meshList[GEO_TERRAIN2], true);
	modelStack.PopMatrix();

}

void SceneCreepingRidge::RenderSkyPlane()
{
	modelStack.PushMatrix();
	modelStack.Translate(0, 2000, 0);
	modelStack.Rotate(rotateSky, 0, 1, 0);
	RenderMesh(meshList[GEO_SKYPLANE], true);
	modelStack.PopMatrix();
}

void SceneCreepingRidge::RenderParticles()
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

void SceneCreepingRidge::RenderWorld()
{
	RenderTerrain();
	RenderSkyPlane();

	RenderFcrab();

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

void SceneCreepingRidge::RenderPassGPass()
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

	//RenderWorld();
}

void SceneCreepingRidge::RenderPassMain()
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
	//RenderWorld();

	//for (std::vector<GameObject *>::iterator it = m_goList.begin(); it != m_goList.end(); ++it)
	//{
	//	GameObject *go = (GameObject*)*it;
	//	if (go->objectType == GameObject::SEACREATURE)
	//	{
	//		Minnow *fo = (Minnow*)*it;
	//		if (fo->active)
	//		{
	//			RenderFO(fo);
	//		}
	//	}
	//	else if (go->objectType == GameObject::PROJECTILE)
	//	{
	//		Projectile *po = (Projectile*)*it;
	//		if (po->active)
	//		{
	//			RenderPO(po);
	//		}
	//	}
	//}

	// Render the crosshair
	RenderMeshIn2D(meshList[GEO_CROSSHAIR], false, 10.0f);
	RenderMesh(meshList[GEO_AXES], false);
	//std::ostringstream ss;
	//ss.precision(3);
	//ss << "FPS: " << fps;
	//RenderTextOnScreen(meshList[GEO_TEXT], ss.str(), Color(0, 1, 0), 3, 2, 3);

	//modelStack.PushMatrix();
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);	//set to line
	//modelStack.Translate(m_travelzonedown.m_position.x,m_travelzonedown.m_position.y,m_travelzonedown.m_position.z);
	//modelStack.Scale(m_travelzonedown.m_width,m_travelzonedown.m_height,m_travelzonedown.m_length);
	//RenderMesh(meshList[GEO_CUBE], false);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	//set back to fill
	//modelStack.PopMatrix();


	//modelStack.PushMatrix();
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);	//set to line
	//modelStack.Translate(m_travelzoneup.m_position.x, m_travelzoneup.m_position.y, m_travelzoneup.m_position.z);
	//modelStack.Scale(m_travelzoneup.m_width, m_travelzoneup.m_height, m_travelzoneup.m_length);
	//RenderMesh(meshList[GEO_CUBE], false);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	//set back to fill
	//modelStack.PopMatrix();

}

void SceneCreepingRidge::Render()
{
	// PRE RENDER PASS
	RenderPassGPass();

	// MAIN RENDER PASS
	RenderPassMain();

}

void SceneCreepingRidge::RenderMinimap()
{

}

void SceneCreepingRidge::Update(double dt)
{
	SceneSP3::Update(dt);
	c->UpdateFcrab(dt);
}


Fcrab*  SceneCreepingRidge::FetchFcrab()
{
	for (std::vector<GameObject *>::iterator it = m_goList.begin(); it != m_goList.end(); ++it)
	{
		Fcrab *go = (Fcrab *)*it;
		if (!go->active)
		{
			go->active = true;
			//++m_objectCount;
			return go;
		}

	}
	for (unsigned i = 0; i < 10; ++i)
	{
		Fcrab *go = new Fcrab();
		go->objectType = GameObject::SEACREATURE;
		go->seaType = SeaCreature::FCRAB;
		m_goList.push_back(go);
	}
	Fcrab *go = (Fcrab *)m_goList.back();
	go->active = true;
	//++m_objectCount;
	return go;
}

void SceneCreepingRidge::Exit()
{
	SceneSP3::Exit();
}