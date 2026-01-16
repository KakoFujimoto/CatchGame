#pragma once
#include "UI/Facing.h"
#include "UI/MoveState.h"
#include "ImageId.h"


class ImageStore;

class PlayerImages
{
public:
	void load(ImageStore& store);
	ImageId resolve(Facing facing, MoveState moveState) const;
};