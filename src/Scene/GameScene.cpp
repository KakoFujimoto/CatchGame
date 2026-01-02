#include "GameScene.h"
#include "System/Input.h"
#include "Renderer.h"
#include "SceneId.h"
#include "System/HitCheck.h"
#include <DxLib.h>
#include <iostream>

void GameScene::onEnter()
{
	player.initialize(400, 500);
	// ç°ÇÕâºÇ≈êßå¿éûä‘30ïb
	gameTimer.start(60 * 30);
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

	// ìñÇΩÇËîªíË
	for (auto& obj : fallingObjectManager.getObjectForUpdate())
	{
		if (HitCheck::isHit(player.getHitArea(), obj.getHitArea()))
		{
			//printfDx("HIT effect=%d\n", (int)obj.getScoreEffect());
			switch (obj.getScoreEffect())
			{
			case ScoreEffect::Plus:
				score.add(10);
				break;
			case ScoreEffect::Minus:
				score.add(-5);
				break;
			}
			obj.markForRemove();
		}
	}
	if (timeUp)
	{
		return SceneId::Result;
	}
	fallingObjectManager.removeMarkedObjects();
	return SceneId::None;
}

void GameScene::draw(Renderer& renderer)
{
	player.draw(renderer);
	fallingObjectManager.draw(renderer);
	gameTimer.draw(renderer);
	score.draw(renderer);
}

int GameScene::getScore() const
{
	return score.get();
}