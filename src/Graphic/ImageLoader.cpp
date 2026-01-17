#include "ImageLoader.h"
#include "FallingObject/FallingObjectImages.h"
#include "PlayerImages.h"


#include <Dxlib.h>

void ImageLoader::loadAll(
	ImageStore& imageStore,
	PlayerImages& playerImages,
	FallingObjectImages& fallingImages
)
{
	playerImages.load(imageStore);
	fallingImages.load(imageStore);
}