#pragma once
#include "Scene.h"


class TitleScene : public Scene
{
public:
	SceneId update(const Input& input) override;
	void draw(Renderer& renderer) override;
};