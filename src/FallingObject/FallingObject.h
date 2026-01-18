#pragma once
#include "FallingObjectType.h"
#include "System/ScoreEffect.h"
#include "GameConfig.h"

class Renderer;
class HitArea;
class ImageStore;
class FallingObjectImages;


class FallingObject
{
public:
	FallingObject(
		FallingObjectType type,
		int x, int y);
	void update();
	void draw(
		Renderer& renderer,
		const ImageStore& imageStore,
		const FallingObjectImages& images) const;
	bool isOutOfScreen() const;
	HitArea getHitArea() const;
	ScoreEffect getScoreEffect() const;
	int getScoreValue() const;

private:
	FallingObjectType type_;
	int x_;
	int y_;
	int width_ = GameConfig::FallingObjectConfig::Width;
	int height_ = GameConfig::FallingObjectConfig::Height;
	int fallspeed_;
};