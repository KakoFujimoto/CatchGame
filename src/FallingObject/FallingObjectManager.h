#pragma once
#include <vector>
#include "FallingObject.h"

class GameTimer;
class Renderer;
class ImageStore;
class FallingObjectImages;

class FallingObjectManager
{
public:
	void update(bool canSpawn);
	void draw(
		Renderer renderer,
		const ImageStore& imageStore,
		const FallingObjectImages images) const;
	void spawn();
	const std::vector<FallingObject>& getObject() const; // 読み取り専用
	std::vector<FallingObject>& getObjectForUpdate(); // 更新・削除用
	void removeMarkedObjects();
private:
	std::vector<FallingObject> objects_;
	int spawnTimer_ = 0;
};