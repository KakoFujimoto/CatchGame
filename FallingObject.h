#pragma once
#include "FallingObjectType.h"

class Renderer;
class HitArea;

class FallingObject
{
public:
	FallingObject(FallingObjectType type, int x, int y);
	void update();
	void draw(Renderer renderer) const;
	bool isOutOfScreen() const;
	HitArea getHitArea() const;
private:
	FallingObjectType type_;
	int x_;
	int y_;
	int width_ = 40;
	int height_ = 40;
	int fallspeed_;
};