#include "Camera3.h"
#include "Application.h"
#include "Mtx44.h"
#include "LoadHmap.h"
#include "SharedData.h"
#include "MeshBuilder.h"

Camera3::Camera3()
{
}

Camera3::~Camera3()
{
}

void Camera3::Init(const Vector3& pos, const Vector3& target, const Vector3& up)
{
	JumpDelay = 0;
	JumpedUp = false;
	JumpedDown = false;

	this->position = defaultPosition = pos;
	this->target = defaultTarget = target;
	Vector3 view = (target - position).Normalized();
	Vector3 right = view.Cross(up);
	right.y = 0;
	right.Normalize();
	this->up = defaultUp = right.Cross(view).Normalized();
}


void Camera3::Update(double dt)
{
	static const float CAMERA_SPEED = 200.f;

	if(Application::IsKeyPressed('A'))
	{
		Vector3 view = (target - position).Normalized();
		Vector3 right = view.Cross(up);
		right.y = 0;
		right.Normalize();
		position.x -= right.x * CAMERA_SPEED * (float)dt;
		position.z -= right.z * CAMERA_SPEED * (float)dt;
		target.x -= right.x * CAMERA_SPEED * (float)dt;
		target.z -= right.z * CAMERA_SPEED * (float)dt;

        if (TerrainHeight > position.y)
        {
            target.y += TerrainHeight - position.y;
        }
        else
        {
            target.y -= position.y - TerrainHeight;
        }
        position.y = TerrainHeight;
	}
	if(Application::IsKeyPressed('D'))
	{
		Vector3 view = (target - position).Normalized();
		Vector3 right = view.Cross(up);
		right.y = 0;
		right.Normalize();
		position.x += right.x * CAMERA_SPEED * (float)dt;
		position.z += right.z * CAMERA_SPEED * (float)dt;
		target.x += right.x * CAMERA_SPEED * (float)dt;
		target.z += right.z * CAMERA_SPEED * (float)dt;

        if (TerrainHeight > position.y)
        {
            target.y += TerrainHeight - position.y;
        }
        else
        {
            target.y -= position.y - TerrainHeight;
        }
        position.y = TerrainHeight;
	}
	if(Application::IsKeyPressed('W'))
	{
		Vector3 view = (target - position).Normalized();
		position.x += view.x * CAMERA_SPEED * (float)dt;
		position.z += view.z * CAMERA_SPEED * (float)dt;
		target.x += view.x * CAMERA_SPEED * (float)dt;
		target.z += view.z * CAMERA_SPEED * (float)dt;

        if (TerrainHeight > position.y)
        {
            target.y += TerrainHeight - position.y;
        }
        else
        {
            target.y -= position.y - TerrainHeight;
        }
        position.y = TerrainHeight;
	}
	if(Application::IsKeyPressed('S'))
	{
		Vector3 view = (target - position).Normalized();
		position.x -= view.x * CAMERA_SPEED * (float)dt;
		position.z -= view.z * CAMERA_SPEED * (float)dt;
		target.x -= view.x * CAMERA_SPEED * (float)dt;
		target.z -= view.z * CAMERA_SPEED * (float)dt;

        if (TerrainHeight > position.y)
        {
            target.y += TerrainHeight - position.y;
        }
        else
        {
            target.y -= position.y - TerrainHeight;
        }
        position.y = TerrainHeight;
	}

    SharedData::GetInstance()->PlayerPos = position;

	if(Application::IsKeyPressed(VK_LEFT))
	{
		Vector3 view = (target - position).Normalized();
		float yaw = (float)(CAMERA_SPEED * (float)dt);
		Mtx44 rotation;
		rotation.SetToRotation(yaw, 0, 1, 0);
		view = rotation * view;
		target = position + view;
		Vector3 right = view.Cross(up);
		right.y = 0;
		right.Normalize();
		up = right.Cross(view).Normalized();
	}
	if(Application::IsKeyPressed(VK_RIGHT))
	{
		Vector3 view = (target - position).Normalized();
		float yaw = (float)(-CAMERA_SPEED * (float)dt);
		Mtx44 rotation;
		rotation.SetToRotation(yaw, 0, 1, 0);
		view = rotation * view;
		target = position + view;
		Vector3 right = view.Cross(up);
		right.y = 0;
		right.Normalize();
		up = right.Cross(view).Normalized();
	}
	if(Application::IsKeyPressed(VK_UP))
	{
		float pitch = (float)(CAMERA_SPEED * (float)dt);
		Vector3 view = (target - position).Normalized();
		Vector3 right = view.Cross(up);
		right.y = 0;
		right.Normalize();
		up = right.Cross(view).Normalized();
		Mtx44 rotation;
		rotation.SetToRotation(pitch, right.x, right.y, right.z);
		view = rotation * view;
		target = position + view;
	}
	if(Application::IsKeyPressed(VK_DOWN))
	{
		float pitch = (float)(-CAMERA_SPEED * (float)dt);
		Vector3 view = (target - position).Normalized();
		Vector3 right = view.Cross(up);
		right.y = 0;
		right.Normalize();
		up = right.Cross(view).Normalized();
		Mtx44 rotation;
		rotation.SetToRotation(pitch, right.x, right.y, right.z);
		view = rotation * view;
		target = position + view;
	}
	//Update the camera direction based on mouse move
	// left-right rotate
	{
		Vector3 view = (target - position).Normalized();
		float yaw = (float)(-CAMERA_SPEED * Application::camera_yaw * (float)dt);
		Mtx44 rotation;
		rotation.SetToRotation(yaw, 0, 1, 0);
		view = rotation * view;
		target = position + view;
		Vector3 right = view.Cross(up);
		right.y = 0;
		right.Normalize();
		up = right.Cross(view).Normalized();
	}
	{
		float pitch = (float)(-CAMERA_SPEED * Application::camera_pitch * (float)dt);
		Vector3 view = (target - position).Normalized();
		Vector3 right = view.Cross(up);
		right.y = 0;
		right.Normalize();
		up = right.Cross(view).Normalized();
		Mtx44 rotation;
		rotation.SetToRotation(pitch, right.x, right.y, right.z);
		view = rotation * view;
		if (view.y <= 0.9f && view.y >= -0.6f)
		{
			target = position + view;
		}
	}
	if(Application::IsKeyPressed('R'))
	{
		Reset();
	}
}

void Camera3::Reset()
{
	position = defaultPosition;
	target = defaultTarget;
	up = defaultUp;
}