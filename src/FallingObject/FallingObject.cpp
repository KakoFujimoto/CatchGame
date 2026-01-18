#include "FallingObject.h"
#include "Graphic/Renderer.h"
#include "System/HitArea.h"
#include "Graphic/ImageStore.h"
#include "FallingObjectImages.h"


FallingObject::FallingObject(
	FallingObjectType type,
	int x, int y
)
	: type_(type), x_(x), y_(y)
{
	switch (type_)
	{
	case FallingObjectType::Fish:
		width_ = 40;
		height_ = 40;
		fallspeed_ = 2;
		break;
	case FallingObjectType::Rock:
		width_ = 40;
		height_ = 40;
		fallspeed_ = 5;
		break;
	}
}

void FallingObject::update()
{
	y_ += fallspeed_;
}

void FallingObject::draw(
	Renderer& renderer,
	const ImageStore& imageStore,
	const FallingObjectImages& images) const
{
	auto imageId = images.resolve(type_);
	renderer.drawImage(x_, y_,imageStore.get(imageId));
}

bool FallingObject::isOutOfScreen() const
{
	return y_ > 500; // âÊñ â∫Ç…èoÇΩÇ©Ç«Ç§Ç©
}

HitArea FallingObject::getHitArea() const
{
	return HitArea(x_, y_, width_, height_);
}

ScoreEffect FallingObject::getScoreEffect() const
{
	switch (type_)
	{
	case FallingObjectType::Fish:
		return ScoreEffect::Plus;
	case FallingObjectType::Rock:
		return ScoreEffect::Minus;
	}
	return ScoreEffect::None;
}