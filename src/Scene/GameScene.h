#pragma once
#include "Scene.h"
#include "SceneId.h"
#include "UI/Player.h"
#include "System/GameTimer.h"
#include "FallingObject/FallingObjectManager.h"
#include "System/Score.h"

class Input;
class ImageStore;
class FallingObjectImages;
class PlayerImages;

class GameScene : public Scene
{
public:
	GameScene(
		const ImageStore& imageStore,
		const FallingObjectImages& fallingObjectimages,
		const PlayerImages& playerImages
	);
	void onEnter() override;
	SceneId update(const Input& input) override;
	virtual void draw(Renderer& renderer) override;
	int getScore() const;

private:
	Player player;
	FallingObjectManager fallingObjectManager;
	GameTimer gameTimer;
	Score score;
	const ImageStore& imageStore_;
	const FallingObjectImages& fallingObjectimages_;
	const PlayerImages& playerImages_;
};