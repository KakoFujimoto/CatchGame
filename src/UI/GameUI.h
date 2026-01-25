#pragma once

class Renderer;

class GameUI
{
public:
	void draw(Renderer& renderer, GameScene& scene) const;

private:
	void drawTimer(Renderer& renderer, int remainingSecond) const;
	void drawScore(Renderer& renderer, int score) const;
};