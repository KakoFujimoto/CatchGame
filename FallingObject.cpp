#include "FallingObject.h"
#include "Renderer.h"
#include "HitArea.h"

FallingObject::FallingObject(FallingObjectType type, int x, int y)
	: type_(type), x_(x), y_(y)
{
	switch (type_)
	{
	case FallingObjectType::Fish:
		fallspeed_ = 2;
		break;
	case FallingObjectType::Rock:
		fallspeed_ = 5;
		break;
	}
}

void FallingObject::update()
{
	y_ += fallspeed_;
}

void FallingObject::draw(Renderer renderer) const
{
	const char* text = "?";

	switch (type_)
	{
	case FallingObjectType::Fish:
		text = "‹›";
		break;
	case FallingObjectType::Rock:
		text = "Šâ";
		break;
	}
	renderer.drawText(x_, y_, text);
}

bool FallingObject::isOutOfScreen() const
{
	return y_ > 500; // ‰æ–Ê‰º‚Éo‚½‚©‚Ç‚¤‚©
}

HitArea FallingObject::getHitArea() const
{
	return HitArea(x_, y_, width_, height_);
}
