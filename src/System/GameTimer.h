#pragma once

class Renderer;

class GameTimer
{
public:
	void start(int limitFrame);
	void update();
	bool isTimeUp() const;
	int getRemainingSecond() const;
	void draw(Renderer& renderer) const;

private:
	int currentFrame_ = 0;
	int limitFrame_ = 0;
};
