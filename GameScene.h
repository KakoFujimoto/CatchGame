#pragma once
#include "Scene.h"
#include "SceneId.h"
#include "Player.h"


class Input;

class GameScene : public Scene
{
public:
	void onEnter() override;
	SceneId update(const Input& input) override;
	virtual void draw(Renderer& renderer) override;
private:
	Player player;
};