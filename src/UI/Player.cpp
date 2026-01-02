#include "Player.h"
#include "Renderer.h"
#include "System/HitArea.h"
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
		facing_ = Facing::Left;
		moveState_ = MoveState::Walk;
		x_ -= speed_;
	}
	if (input.isPressed(KEY_INPUT_RIGHT))
	{
		facing_ = Facing::Right;
		moveState_ = MoveState::Walk;
		x_ += speed_;
	}
	else
	{
		moveState_ = MoveState::Idle;
	}
}

void Player::draw(Renderer& renderer) const
{
	renderer.drawText(x_, y_, "P");
}

HitArea Player::getHitArea() const
{
	return HitArea(x_, y_, width_, height_);
}