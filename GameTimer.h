#pragma once

class GameTimer
{
public:
	void start(int limitFrame);
	void update();
	bool isTimeUp() const;
	int getRemainingFrame() const;
private:
	int currentFrame_ = 0;
	int limitFrame_ = 0;
};
