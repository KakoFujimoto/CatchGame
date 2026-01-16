#pragma once
#include "UI/Facing.h"
#include "UI/MoveState.h"
#include "FallingObject/FallingObjectType.h"


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