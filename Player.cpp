#include "Player.h"
#include "Renderer.h"
#include <DxLib.h>

void Player::initialize(int startX, int startY)
{
	x = startX;
	y = startY;
}

void Player::update(const Input& input)
{
	if (input.isPressed(KEY_INPUT_LEFT))
	{
		x -= speed;
	}
	if (input.isPressed(KEY_INPUT_RIGHT))
	{
		x += speed;
	}
}

void Player::draw(Renderer& renderer) const
{
	renderer.drawText(x, y, "P");
}
