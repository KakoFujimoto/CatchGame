#pragma once
#include "ImageId.h"

class ImageStore
{
public:
	void set(ImageId id, int handle);
	int get(ImageId id) const;

private:
	int images_[(int)ImageId::Count];
};
