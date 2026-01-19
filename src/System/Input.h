#pragma once
#include "UI/Gamekey.h"

class Input
{
public:
	void update();
	// 押しっぱなし
	bool isPressed(GameKey key) const;
	// 押した瞬間
	bool isTriggered(GameKey key) const;

private:
	static constexpr int KeyCount = 256; // DxLib仕様
	int current[KeyCount] = {};
	int previous[KeyCount] = {};
};