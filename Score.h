#pragma once

class Renderer;

class Score
{
public:
	void add(int value);
	int get() const;
	void reset();
	void draw(Renderer& renderer) const;

private:
	int score_ = 0;
};