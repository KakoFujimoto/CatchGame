#pragma once

class HitArea
{
public:
	HitArea(int leftX, int topY, int width, int height);
	int left() const;
	int right() const;
	int top() const;
	int bottom() const;

private:
	int leftX_;
	int topY_;
	int width_;
	int height_;
};