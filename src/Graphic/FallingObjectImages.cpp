#include "DxLib.h"
#include "FallingObjectImages.h"
#include "ImageStore.h"

void FallingObjectImages::load(ImageStore& store)
{
    store.set(ImageId::Fish,
        LoadGraph("assets/images/falling_objects/fish.png"));
    store.set(ImageId::Rock,
        LoadGraph("assets/images/falling_objects/rock.png"));
}

ImageId FallingObjectImages::resolve(FallingObjectType fallingObjectType) const
{
    switch (fallingObjectType)
    {
    case FallingObjectType::Fish:
        return ImageId::Fish;
    case FallingObjectType::Rock:
        return ImageId::Rock;
    default:
        return ImageId::Fish;
    }
}
