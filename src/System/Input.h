#pragma once

class Input
{
public:
	//enum class 
	//{
	//	Left = KEY_INPUT_LEFT
	//};

public:
	void update();
	// ‰Ÿ‚µ‚Á‚Ï‚È‚µ
	bool isPressed(int key) const;
	// ‰Ÿ‚µ‚½uŠÔ
	bool isTriggered(int key) const;

private:
	int current[256] = {};
	int previous[256] = {};
};