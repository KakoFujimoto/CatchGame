#pragma once
#include "UI/Facing.h"
#include "UI/MoveState.h"
#include "FallingObject/FallingObjectType.h"

class ImageStore;
class PlayerImages;
class FallingObjectImages;

class ImageLoader
{
public:
	void loadAll(
		ImageStore& imageStore,
		PlayerImages& playerImages,
		FallingObjectImages& fallingImages
	);
};