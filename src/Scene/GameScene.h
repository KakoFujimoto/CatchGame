#pragma once
#include "Scene.h"
#include "SceneId.h"
#include "UI/Player.h"
#include "System/GameTimer.h"
#include "FallingObject/FallingObjectManager.h"
#include "System/Score.h"

class Input;
class ImageLoader;

class GameScene : public Scene
{
public:
	void onEnter(const ImageLoader& imageLoader);
	SceneId update(const Input& input) override;
	virtual void draw(Renderer& renderer) override;
	int getScore() const;
private:
	Player player;
	FallingObjectManager fallingObjectManager;
	GameTimer gameTimer;
	Score score;
	const ImageLoader* imageLoader_ = nullptr;
};