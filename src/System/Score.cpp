#include "Score.h"
#include "Renderer.h"


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
	renderer.drawText(10, 25, "Score : " + std::to_string(score_));
}