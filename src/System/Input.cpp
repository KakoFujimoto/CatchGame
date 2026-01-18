#include "Input.h"
#include <DxLib.h>

void Input::update()
{
	// 前フレームの状態を保存
	memcpy(previous, current, sizeof(current));

	// 今フレームの状態を取得
	for (int i = 0; i < KeyCount; ++i)
	{
		current[i] = CheckHitKey(i);
	}
}

bool Input::isPressed(GameKey key) const
{
	switch (key)
	{
	case GameKey::Left:
		return CheckHitKey(KEY_INPUT_LEFT);
	case GameKey::Right:
		return CheckHitKey(KEY_INPUT_RIGHT);
	case GameKey::Enter:
		return CheckHitKey(KEY_INPUT_RETURN);
	}
	return false;
}

bool Input::isTriggered(GameKey key) const
{
	return current[key] != 0 && previous[key] == 0;
}