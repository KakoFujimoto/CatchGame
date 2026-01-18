#include "GameTimer.h"
#include "Graphic/Renderer.h"
#include "UI/GameUI.h"



void GameTimer::start(int limitFrame)
{
	limitFrame_ = limitFrame;
	currentFrame_ = 0;
}

void GameTimer::update()
{
	if (currentFrame_ < limitFrame_)
	{
		currentFrame_++;
	}
}

bool GameTimer::isTimeUp() const
{
	return currentFrame_ >= limitFrame_;
}

int GameTimer::getRemainingSecond() const
{
	return (limitFrame_ - currentFrame_) / 60;
}

void GameTimer::draw(Renderer& renderer, const GameUI& ui) const
{
	ui.drawTimer(renderer, getRemainingSecond());
}
