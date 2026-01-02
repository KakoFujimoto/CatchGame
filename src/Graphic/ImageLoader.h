#pragma once
#include "Facing.h"
#include "MoveState.h"
#include "FallingObjectType.h"


class ImageLoader
{
public:
	void load();
	int getPlayerImage(Facing facing, MoveState moveState) const;
	int getFallingObjectImage(FallingObjectType type) const;

private:
	int playerImages_[(int)Facing::Count][(int)MoveState::Count];
	int fallingObjectImages_[(int)FallingObjectType::Count];

};