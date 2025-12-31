#pragma once
#include "Scene.h"


class ResultScene : public Scene
{
public:
	SceneId update(const Input& input) override;
	void draw(Renderer& renderer) override;
};