#pragma once
#include "Facing.h"
#include "MoveState.h"


class ImageLoader
{
public:
	void load();
	int getPlayerImage(Facing facing, MoveState moveState) const;
private:
	int playerImages_[2][2]; // [Facing][MoveState]
};