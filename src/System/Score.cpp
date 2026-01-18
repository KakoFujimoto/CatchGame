#include "Score.h"
#include "Graphic/Renderer.h"
#include "GameConfig.h"


void Score::add(int value)
{
	score_ += value;
}

int Score::get() const
{
	return score_;
}

void Score::reset()
{
	score_ = 0;
}

void Score::draw(Renderer& renderer) const
{
	renderer.drawText(
		GameConfig::ScoreConfig::DisplayMarignX,
		GameConfig::ScoreConfig::DisplayMarignY,
		"Score : " + std::to_string(score_));
}