#include "FallingObjectManager.h"
#include "FallingObjectType.h"
#include "FallingObject.h"
#include "Graphic/ImageStore.h"
#include "System/GameTimer.h"
#include "Graphic/Renderer.h"
#include "FallingObject/FallingObjectImages.h"
#include "GameConfig.h"

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

void FallingObjectManager::draw(
	Renderer renderer,
	const ImageStore& imageStore,
	const FallingObjectImages images) const
{
	for (const auto& obj : objects_)
	{
		obj.draw(renderer, imageStore, images);
	}
}

void FallingObjectManager::spawn()
{
	spawnTimer_++;

	auto interval = GameConfig::FallingObjectManagerConfig::SpawnIntervalFrame;
	if (spawnTimer_ < interval)
	{
		return;
	}

	spawnTimer_ = 0;

	int x = GetRand(GameConfig::FallingObjectManagerConfig::SpawnMaxX);
	int y = 0;

	objects_.emplace_back(FallingObjectType::Fish, x, y);
	objects_.emplace_back(FallingObjectType::Rock, x, y);
}

// 読み取り専用
const std::vector<FallingObject>& FallingObjectManager::getObject() const
{
	return objects_;
}

// 更新・削除用
std::vector<FallingObject>& FallingObjectManager::getObjectForUpdate()
{
	return objects_;
}

void FallingObjectManager::requestRemove(FallingObject* obj)
{
	removeRequests_.push_back(obj);
}

void FallingObjectManager::applyRemovals()
{
	for (auto* obj : removeRequests_)
	{
		objects_.erase(
			std::remove_if(
				objects_.begin(),
				objects_.end(),
				[&](const FallingObject& o)
				{
					return &o == obj;
				}
			),
			objects_.end()
		);
	}
	removeRequests_.clear();
}

