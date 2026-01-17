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
	if (input.isTriggered(KEY_INPUT_RETURN))
	{
		return SceneId::Game;
	}
	return SceneId::None;
}

void ResultScene::draw(Renderer& renderer)
{
	auto score = std::to_string(score_);
	renderer.drawText(200, 200, "RESULT : " + score);
	renderer.drawText(200, 240, "ENTER TO REPLAY");
}

void ResultScene::setScore(int score)
{
	score_ = score;
}

void ResultScene::onEnter()
{
	setScore(gameScene_.getScore());
}
