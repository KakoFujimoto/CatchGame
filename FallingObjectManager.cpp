#include "FallingObjectManager.h"
#include "FallingObjectType.h"
#include "FallingObject.h"
#include "GameTimer.h"
#include "Renderer.h"

#include <DxLib.h>

void FallingObjectManager::update(bool canSpawn)
{
	if (canSpawn)
	{
		spawn();
	}
	for (auto& obj : objects_)
	{
		obj.update();
	}

	objects_.erase(
		std::remove_if(
			objects_.begin(),
			objects_.end(),
			[](const FallingObject& obj)
			{
				return obj.isOutOfScreen();
			}),
		objects_.end());
}

void FallingObjectManager::draw(Renderer renderer) const
{
	for (const auto& obj : objects_)
	{
		obj.draw(renderer);
	}
}

void FallingObjectManager::spawn()
{
	spawnTimer_++;

	// 60ÉtÉåÅ[ÉÄÇ…1âÒóNÇ≠
	if (spawnTimer_ < 60)
	{
		return;
	}

	spawnTimer_ = 0;

	int x = GetRand(640); // âÊñ ïù
	int y = 0;

	objects_.emplace_back(FallingObjectType::Fish, x, y);
	objects_.emplace_back(FallingObjectType::Rock, x, y);
}
