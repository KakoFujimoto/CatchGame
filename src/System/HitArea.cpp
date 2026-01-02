#include "HitArea.h"

HitArea::HitArea(int leftX, int topY, int width, int height)
	: leftX_(leftX), topY_(topY), width_(width), height_(height) {
}

int HitArea::left() const
{
	return leftX_;
}

int HitArea::right() const
{
	return leftX_ + width_;
}

int HitArea::top() const
{
	return topY_;
}

int HitArea::bottom() const
{
	return topY_ + height_;
}