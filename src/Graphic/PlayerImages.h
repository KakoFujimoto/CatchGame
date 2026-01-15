#pragma once
#include "Facing.h"
#include "MoveState.h"
#include "ImageId.h"


class ImageStore;

class PlayerImages
{
public:
	void load(ImageStore& store);
	ImageId resolve(Facing facing, MoveState moveState) const;
};