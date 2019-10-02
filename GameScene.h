#pragma once
#include "Scene.h"
#include "Types.h"
#include "Sprite.h"
#include "Camera.h"
#include "Fog.h"
#include "MiniMap.h"
class GameScene :
	public Scene
{
public:
	void Init() override;
	void Update() override;
	void OnExit() override;

	Sprite* s;
	Fog* f;
	vector2 campos;

	Sprite* z;
	MiniMap* m;
	static vector2 hi;
};

