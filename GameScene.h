#pragma once
#include "Scene.h"
#include "SceneId.h"
#include "Player.h"
#include "GameTimer.h"
#include "FallingObjectManager.h"
#include "Score.h"

class Input;

class GameScene : public Scene
{
public:
	void onEnter() override;
	SceneId update(const Input& input) override;
	virtual void draw(Renderer& renderer) override;
	int getScore() const;
private:
	Player player;
	FallingObjectManager fallingObjectManager;
	GameTimer gameTimer;
	Score score;
};