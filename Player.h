#pragma once
#include "Input.h"

class Renderer;

class Player
{
public:
	void initialize(int startX, int startY);
	void update(const Input& input);
	void draw(Renderer& renderer) const;
private:
	int x = 0;
	int y = 0;
	int speed = 5;
	int width = 40;
	int height = 40;
};