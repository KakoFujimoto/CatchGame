#pragma once
#include <vector>
#include "FallingObject.h"

class GameTimer;
class Renderer;

class FallingObjectManager
{
public:
	void update(bool canSpawn);
	void draw(Renderer renderer) const;
	void spawn();
private:
	std::vector<FallingObject> objects_;
	int spawnTimer_ = 0;
};