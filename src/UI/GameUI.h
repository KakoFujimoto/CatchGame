#pragma once

class Renderer;

class GameUI
{
public:
	void drawTimer(Renderer& renderer, int remainingSecond) const;
};