#include "DXUT.h"
#include "GameScene.h"

vector2 GameScene::hi = { 1,1 };

void GameScene::Init()
{
	s = new Sprite;
	s->Create(L"a.png");
	s->_position = { 0,0 };

	z = new Sprite;
	z->Create(L"z.png");
	z->_pivot = { 0,0 };
	z->_position = { 0,0 };
	z->_layer = 5;

	f = new Fog;

	m = new MiniMap;

	Camera::GetInstance()->CameraInit();
	campos = { 0,0 };
}

void GameScene::Update()
{
	Camera::GetInstance()->SetPos(campos);
	Camera::GetInstance()->Update();
	s->_position = Director::GetInstance()->GetMousePos() * Camera::GetInstance()->_CameraSize;
	s->_position -= {640 * Camera::GetInstance()->_CameraSize - campos.x, 360 * Camera::GetInstance()->_CameraSize - campos.y};

	if (Director::GetInstance()->OnMouseDown())
	{
		z->_position = Director::GetInstance()->GetMousePos() * Camera::GetInstance()->_CameraSize;
		z->_position -= {640 * Camera::GetInstance()->_CameraSize - campos.x, 360 * Camera::GetInstance()->_CameraSize - campos.y};
	}
	else if (Director::GetInstance()->OnMouse())
	{
		vector2 v = Director::GetInstance()->GetMousePos() * Camera::GetInstance()->_CameraSize;
		v -= vector2(640 * Camera::GetInstance()->_CameraSize - campos.x, 360 * Camera::GetInstance()->_CameraSize - campos.y);
		vector2 v2 = v - z->_position;
		z->_scale = v2 / 30;
	}
	else if (Director::GetInstance()->OnMouseUp())
	{
		z->_scale = { 0.1,0.1 };
	}
	hi = s->_position;
	static float t = 1;
	t -= Time::deltaTime;
	if (t < 0)
	{
		f->SetFog(s->_position);
		t = 0.001;
	}


	campos = Director::GetInstance()->GetMousePos() * 5;
}

void GameScene::OnExit()
{

}
