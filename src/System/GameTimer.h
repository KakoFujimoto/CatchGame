#pragma once

class Renderer;
class GameUI;

class GameTimer
{
public:
	void start(int limitFrame);
	void update();
	bool isTimeUp() const;
	int getRemainingSecond() const;
	void draw(Renderer& renderer, const GameUI& ui) const;

private:
	int currentFrame_ = 0;
	int limitFrame_ = 0;
};
