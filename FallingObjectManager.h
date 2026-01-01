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
	const std::vector<FallingObject>& getObject() const;
private:
	std::vector<FallingObject> objects_;
	int spawnTimer_ = 0;
};