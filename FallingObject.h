#pragma once
#include "FallingObjectType.h"

class Renderer;

class FallingObject
{
public:
	FallingObject(FallingObjectType type, int x, int y);
	void update();
	void draw(Renderer renderer) const;
	bool isOutOfScreen() const;

private:
	FallingObjectType type_;
	int x_;
	int y_;
	int fallspeed_;
};