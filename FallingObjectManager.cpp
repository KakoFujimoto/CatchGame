#include "FallingObjectManager.h"
#include "FallingObjectType.h"
#include "FallingObject.h"
#include "Renderer.h"

#include <DxLib.h>

void FallingObjectManager::update()
{
	spawn();
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

	// 60ƒtƒŒ[ƒ€‚É1‰ñ—N‚­
	if (spawnTimer_ < 60)
	{
		return;
	}

	spawnTimer_ = 0;

	int x = GetRand(640); // ‰æ–Ê•
	int y = 0;

	// ‚Ğ‚Æ‚Ü‚¸‹›‚¾‚¯
	// ‚Ì‚¿‚Ù‚ÇŠâ‚ğ‘«‚·
	objects_.emplace_back(FallingObjectType::Fish, x, y);
}
