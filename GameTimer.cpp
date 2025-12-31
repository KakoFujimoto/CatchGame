#include "GameTimer.h"

void GameTimer::start(int limitFrame)
{
	limitFrame_ = limitFrame;
	currentFrame_ = 0;
}

void GameTimer::update()
{
	currentFrame_++;
}

bool GameTimer::isTimeUp() const
{
	return currentFrame_ >= limitFrame_;
}

int GameTimer::getRemainingFrame() const
{
	return limitFrame_ - currentFrame_;
}

