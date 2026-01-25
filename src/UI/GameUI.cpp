#include "GameUI.h"
#include "Graphic/Renderer.h"
#include "GameConfig.h"
#include <string>

void GameUI::drawTimer(Renderer& renderer, int remainingSecond) const
{
	const int x = GameConfig::GameUIConfig::DisplayMargin;
	const int y = GameConfig::GameUIConfig::DisplayMargin;
	std::string header = "Time : ";
	std::string content = std::to_string(remainingSecond);

	renderer.drawText(x, y, header + content);
}

void GameUI::draw(Renderer& renderer, GameScene& scene) const
{
	auto& timer = scene.getTimer();
	auto& score = scene.getScore();

	drawTimer(timer.getRemainingSecond());
	drawScore(score.getCurrentScore());

	drawPlayerLife(renderer, scene.getPlayer().getLife());
}
