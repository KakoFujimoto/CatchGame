#pragma once
#include "Facing.h"
#include "MoveState.h"


class ImageLoader
{
public:
	void load();
	int getPlayerImage(Facing facing, MoveState moveState) const;
private:
	int playerImages_[(int)Facing::Count][(int)MoveState::Count];

};