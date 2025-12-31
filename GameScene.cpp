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
	player.update(input);

	gameTimer.update();
	bool canSpawn = !gameTimer.isTimeUp();
	fallingObjectManager.update(canSpawn);

	return SceneId::None;
}

void GameScene::draw(Renderer& renderer)
{
	player.draw(renderer);
	fallingObjectManager.draw(renderer);
}