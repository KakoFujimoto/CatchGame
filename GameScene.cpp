#include "GameScene.h"
#include "Input.h"
#include "Renderer.h"
#include "SceneId.h"
#include <DxLib.h>

void GameScene::onEnter()
{
	player.initialize(400, 500);
}

SceneId GameScene::update(const Input& input)
{
	player.update(input);
	return SceneId::None;
}

void GameScene::draw(Renderer& renderer)
{
	player.draw(renderer);
}