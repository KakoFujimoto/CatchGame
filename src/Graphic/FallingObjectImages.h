#pragma once
#include "ImageId.h"
#include "FallingObjectType.h"

class ImageStore;

class FallingObjectImages
{
public:
	void load(ImageStore& store);
	ImageId resolve(FallingObjectType fallingObjectType) const;

};