#include "Player.h"
#include "Graphic/Renderer.h"
#include "System/HitArea.h"
#include "Graphic/ImageLoader.h"
#include <DxLib.h>
#include <cassert>

void Player::initialize(int startX, int startY)
{
	x_ = startX;
	y_ = startY;
	facing_ = Facing::Left;
	moveState_ = MoveState::Idle;
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

void Player::draw(Renderer& renderer, const ImageLoader& imageLoader) const
{
	int img = imageLoader.getPlayerImage(facing_, moveState_);
	renderer.drawImage(x_, y_, img);
}

HitArea Player::getHitArea() const
{
	return HitArea(x_, y_, width_, height_);
}