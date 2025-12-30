#include"Input.h"
#include<DxLib.h>

void Input::update()
{
	// 前フレームの状態を保存
	memcpy(previous, current, sizeof(current));

	// 今フレームの状態を取得
	for (int i = 0; i < 256; ++i)
	{
		current[i] = CheckHitKey(i);
	}
}
bool Input::isPressed(int key) const
{
	return current[key] != 0;
}
bool Input::isTriggered(int key) const
{
	return current[key] != 0 && previous[key] == 0;
}