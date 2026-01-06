#include "GameScene.h"
#include "System/Input.h"
#include "Renderer.h"
#include "SceneId.h"
#include "System/HitCheck.h"
#include <DxLib.h>
#include <iostream>
#include <cassert>

void GameScene::onEnter(const ImageLoader& imageLoader)
{
	score.reset();
	imageLoader_ = &imageLoader;
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

	std::vector<FallingObject> deletes;

	// ìñÇΩÇËîªíË
	for (auto& obj : fallingObjectManager.getObjectForUpdate())
	{
		if (HitCheck::isHit(player.getHitArea(), obj.getHitArea()))
		{
			obj.effect(this);

			//switch (obj.getScoreEffect())
			//{
			//case ScoreEffect::Plus:
			//	score.add(10);
			//	break;
			//case ScoreEffect::Minus:
			//	score.add(-5);
			//	break;
			//}
			deletes.push_back(obj);
			//obj.markForRemove();
		}
	}
	//fallingObjectManager.removeMarkedObjects();

	std::for_each(deletes.begin(), deletes.end(), [&x] { fallingObjectManager.remove(x) });

	if (timeUp)
	{
		return SceneId::Result;
	}
	return SceneId::None;
}

void GameScene::draw(Renderer& renderer)
{
	player.draw(renderer, *imageLoader_);
	fallingObjectManager.draw(renderer, *imageLoader_);
	//gameTimer.draw(renderer);
	//score.draw(renderer);
	ui.draw(renderer, *this);
}

int GameScene::getScore() const
{
	return score.get();
}