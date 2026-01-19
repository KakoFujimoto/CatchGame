#include "FallingObject.h"
#include "Graphic/Renderer.h"
#include "System/HitArea.h"
#include "Graphic/ImageStore.h"
#include "FallingObjectImages.h"
#include "GameConfig.h"


FallingObject::FallingObject(
	FallingObjectType type,
	int x, int y
)
	: type_(type), x_(x), y_(y)
{
	switch (type_)
	{
	case FallingObjectType::Fish:
		fallspeed_ = GameConfig::FallingObjectConfig::FishSpeed;
		break;
	case FallingObjectType::Rock:
		fallspeed_ = GameConfig::FallingObjectConfig::RockSpeed;
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
	// 画面下に出たかどうか
	return y_ > GameConfig::ScreenConfig::DeadLineY;
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

int FallingObject::getScoreValue() const
{
	ScoreEffect effect = getScoreEffect();
	switch (effect)
	{
	case ScoreEffect::Plus:
		return GameConfig::ScoreConfig::PlusValue;
	case ScoreEffect::Minus:
		return GameConfig::ScoreConfig::MinusValue;
	default:
		return 0;
	}
}