#include "GameScene.h"
#include "Input.h"
#include "Renderer.h"
#include "SceneId.h"
#include <DxLib.h>

void GameScene::onEnter()
{

}

SceneId GameScene::update(const Input& input)
{
	return SceneId::None;
}

void GameScene::draw(Renderer& renderer)
{
	renderer.drawText(200, 200, "GAME SCENE");
}