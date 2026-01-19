#include "GameScene.h"
#include "System/Input.h"
#include "Graphic/Renderer.h"
#include "SceneId.h"
#include "System/HitCheck.h"
#include "FallingObject/FallingObjectImages.h"
#include "UI/GameUI.h"
#include "GameConfig.h"
#include <DxLib.h>
#include <iostream>
#include <cassert>

GameScene::GameScene(
	const ImageStore& imageStore,
	const FallingObjectImages& fallingObjectimages,
	const PlayerImages& playerImages,
	const GameUI& gameUi
)
	: imageStore_(imageStore),
	fallingObjectimages_(fallingObjectimages),
	playerImages_(playerImages),
	gameUi_(gameUi)

{
}
void GameScene::onEnter()
{
	score.reset();
	player.initialize(
		GameConfig::Player::startX, 
		GameConfig::Player::startY
	);

	// プレイ時間の設定
	gameTimer.start(
		GameConfig::Time::FrameRate
		*
		GameConfig::Time::PlayTime
	);
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

	// 当たり判定
	for (auto& obj : fallingObjectManager.getObjectForUpdate())
	{
		bool hit = HitCheck::isHit(player.getHitArea(), obj.getHitArea());
		if (hit)
		{
			score.add(obj.getScoreValue());
			fallingObjectManager.requestRemove(&obj);
		}
	}
	if (timeUp)
	{
		return SceneId::Result;
	}
	fallingObjectManager.applyRemovals();
	return SceneId::None;
}

void GameScene::draw(Renderer& renderer)
{
	player.draw(renderer, imageStore_, playerImages_);
	fallingObjectManager.draw(renderer, imageStore_, fallingObjectimages_);
	gameTimer.draw(renderer, gameUi_);
	score.draw(renderer);
}

int GameScene::getScore() const
{
	return score.get();
}