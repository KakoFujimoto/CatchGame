#pragma once
#include "UI/Gamekey.h"

class Input
{
public:
	void update();
	// ‰Ÿ‚µ‚Á‚Ï‚È‚µ
	bool isPressed(GameKey key) const;
	// ‰Ÿ‚µ‚½uŠÔ
	bool isTriggered(GameKey key) const;

private:
	static constexpr int KeyCount = 256;
	int current[KeyCount] = {};
	int previous[KeyCount] = {};
};