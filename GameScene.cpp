#include "GameScene.h"
#include "Input.h"
#include "Renderer.h"
#include "SceneId.h"
#include <DxLib.h>

void GameScene::onEnter()
{
	player.initialize(400, 500);
	// ç°ÇÕâºÇ≈êßå¿éûä‘5ïb
	gameTimer.start(60 * 5);
}

SceneId GameScene::update(const Input& input)
{
	gameTimer.update();
	bool timeUp = gameTimer.isTimeUp();

	if (!timeUp)
	{
		player.update(input);
	}

	fallingObjectManager.update(!timeUp);

	if (timeUp)
	{
		return SceneId::Result;
	}
	return SceneId::None;
}

void GameScene::draw(Renderer& renderer)
{
	player.draw(renderer);
	fallingObjectManager.draw(renderer);
	gameTimer.draw(renderer);
}