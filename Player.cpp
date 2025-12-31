#include "Player.h"
#include "Renderer.h"
#include <DxLib.h>

void Player::initialize(int startX, int startY)
{
	x_ = startX;
	y_ = startY;
}

void Player::update(const Input& input)
{
	if (input.isPressed(KEY_INPUT_LEFT))
	{
		x_ -= speed_;
	}
	if (input.isPressed(KEY_INPUT_RIGHT))
	{
		x_ += speed_;
	}
}

void Player::draw(Renderer& renderer) const
{
	renderer.drawText(x_, y_, "P");
}
