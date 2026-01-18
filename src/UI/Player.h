#pragma once
#include "System/Input.h"
#include "Facing.h"
#include "MoveState.h"
#include "GameConfig.h"

class Renderer;
class HitArea;
class ImageStore;
class PlayerImages;


class Player
{
public:
	void initialize(int startX, int startY);
	void update(const Input& input);
	void draw(
		Renderer& renderer,
		const ImageStore& imageStore,
		const PlayerImages& images) const;
	HitArea getHitArea() const;
private:
	int x_ = 0;
	int y_ = 0;
	int speed_ = GameConfig::PlayerConfig::Speed;
	int width_ = GameConfig::PlayerConfig::Width;
	int height_ = GameConfig::PlayerConfig::Height;
	
	Facing facing_ = Facing::Left;
	MoveState moveState_ = MoveState::Idle;
};