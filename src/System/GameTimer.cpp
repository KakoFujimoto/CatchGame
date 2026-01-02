#include "GameTimer.h"
#include "Renderer.h"


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

void GameTimer::draw(Renderer& renderer) const
{
	int remainingSecond = getRemainingSecond();
	renderer.drawText(10, 10, "Time : " + std::to_string(remainingSecond));
}
