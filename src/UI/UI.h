#pragma once

class UI
{
public:
	void draw(Renderer& renderer, GameScene& scene)
	{
		//scene.getScore().draw(renderer, 10, 25);
		renderer.drawTect(0, 0, "Score:" + std::to_string(scene.getScore().get()));
		renderer.drawTect(0, 0, scene.getTimer().getRemainingSecond());
	}
};