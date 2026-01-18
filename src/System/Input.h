#pragma once

class Input
{
public:
	void update();
	// ‰Ÿ‚µ‚Á‚Ï‚È‚µ
	bool isPressed(int key) const;
	// ‰Ÿ‚µ‚½uŠÔ
	bool isTriggered(int key) const;

private:
	static constexpr int KeyCount = 256;
	int current[KeyCount] = {};
	int previous[KeyCount] = {};
};