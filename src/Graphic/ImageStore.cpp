#include "ImageStore.h"

void ImageStore::set(ImageId id, int handle)
{
	images_[(int)id] = handle;
}

int ImageStore::get(ImageId id) const
{
	return images_[(int)id];
}