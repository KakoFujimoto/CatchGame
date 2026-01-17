#pragma once
#include "Scene.h"

class GameScene;

class ResultScene : public Scene
{
public:
	ResultScene(GameScene& gameScene);
	SceneId update(const Input& input) override;
	void draw(Renderer& renderer) override;
	void setScore(int score);
	void onEnter() override;

private:
	int score_ = 0;
	GameScene& gameScene_;
};