#pragma once
#include "FallingObjectType.h"
#include "System/ScoreEffect.h"

class Renderer;
class HitArea;
class ImageLoader;
class FallingObjectImages;
class ImageStore;


class FallingObject
{
public:
	FallingObject(
		FallingObjectType type,
		int x, int y);
	void update();
	void draw(Renderer& renderer,
		const ImageStore& imageStore,
		const FallingObjectImages& fallingObjectImages) const;
	bool isOutOfScreen() const;
	HitArea getHitArea() const;
	ScoreEffect getScoreEffect() const;
	void markForRemove();
	bool isMarkedForRemove() const;
private:
	FallingObjectType type_;
	int x_;
	int y_;
	int width_ = 40;
	int height_ = 40;
	int fallspeed_;
	bool remove_ = false;
};