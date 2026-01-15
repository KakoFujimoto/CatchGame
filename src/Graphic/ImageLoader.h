#pragma once
#include <map>
#include <string>

#include "Facing.h"
#include "MoveState.h"
#include "FallingObjectType.h"

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