#pragma once
#include <vector>
#include "FallingObject.h"


class Renderer;

class FallingObjectManager
{
public:
	void update();
	void draw(Renderer renderer) const;
	void spawn();
private:
	std::vector<FallingObject> objects_;
	int spawnTimer_ = 0;
};