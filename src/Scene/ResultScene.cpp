#include "ResultScene.h"
#include "System/Input.h"
#include "Graphic/Renderer.h"
#include "SceneId.h"
#include "GameScene.h"
#include <DxLib.h>

ResultScene::ResultScene(GameScene& gameScene)
	: gameScene_(gameScene)
{
};

SceneId ResultScene::update(const Input& input)
{
	if (input.isTriggered(GameKey::Enter))
	{
		return SceneId::Game;
	}
	return SceneId::None;
}

void ResultScene::draw(Renderer& renderer)
{
	auto score = std::to_string(score_);
	renderer.drawText(
		GameConfig::ResultSceneConfig::DisplayMarginX,
		GameConfig::ResultSceneConfig::ResultDisplayMarginY,
		"RESULT : " + score
	);
	renderer.drawText(
		GameConfig::ResultSceneConfig::DisplayMarginX,
		GameConfig::ResultSceneConfig::ReplayDisplayMarginY,
		"ENTER TO REPLAY"
	);
}

void ResultScene::setScore(int score)
{
	score_ = score;
}

void ResultScene::onEnter()
{
	setScore(gameScene_.getScore());
}
