#include "GameScene.h"
#include "Input.h"
#include "Renderer.h"
#include "SceneId.h"
#include "HitCheck.h"
#include <DxLib.h>

void GameScene::onEnter()
{
	player.initialize(400, 500);
	// ¡‚Í‰¼‚Å§ŒÀŠÔ5•b
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

	// “–‚½‚è”»’è
	for (const auto& obj : fallingObjectManager.getObject())
	{
		if (HitCheck::isHit(player.getHitArea(), obj.getHitArea()))
		{
			switch (obj.getScoreEffect())
			{
			case ScoreEffect::Plus:
				score_ += 10;
				break;
			case ScoreEffect::Minus:
				score_ -= 5;
				break;
			}
			// ‚Ô‚Â‚©‚Á‚½Object‚ÍÁ‚·(markForRemove‚Í–¢À‘•)
			// fallingObjectManager.markForRemove(obj);
		}
	}
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