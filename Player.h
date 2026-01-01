#pragma once
#include "Input.h"

class Renderer;
class HitArea;

class Player
{
public:
	void initialize(int startX, int startY);
	void update(const Input& input);
	void draw(Renderer& renderer) const;
	HitArea getHitArea() const;
private:
	int x_ = 0;
	int y_ = 0;
	int speed_ = 5;
	int width_ = 40;
	int height_ = 40;
};