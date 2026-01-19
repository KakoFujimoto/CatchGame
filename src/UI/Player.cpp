#include "Player.h"
#include "Graphic/Renderer.h"
#include "System/HitArea.h"
#include "Graphic/ImageStore.h"
#include "Graphic/PlayerImages.h"
#include "UI/GameKey.h"
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
	if (input.isPressed(GameKey::Left))
	{
		facing_ = Facing::Left;
		moveState_ = MoveState::Walk;
		x_ -= speed_;
	}
	if (input.isPressed(GameKey::Right))
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

void Player::draw(Renderer& renderer,
	const ImageStore& imageStore,
	const PlayerImages& images) const
{
	auto imageId = images.resolve(facing_, moveState_);
	renderer.drawImage(x_, y_,imageStore.get(imageId));
}

HitArea Player::getHitArea() const
{
	return HitArea(x_, y_, width_, height_);
}