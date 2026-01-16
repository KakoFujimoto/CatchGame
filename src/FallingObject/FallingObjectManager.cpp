#include "FallingObjectManager.h"
#include "FallingObjectType.h"
#include "FallingObject.h"
#include "Graphic/ImageLoader.h"
#include "System/GameTimer.h"
#include "Graphic/Renderer.h"

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

void FallingObjectManager::draw(Renderer renderer, const ImageLoader& imageLoader) const
{
	for (const auto& obj : objects_)
	{
		obj.draw(renderer, imageLoader);
	}
}

void FallingObjectManager::spawn()
{
	spawnTimer_++;

	// 60フレームに1回湧く
	if (spawnTimer_ < 60)
	{
		return;
	}

	spawnTimer_ = 0;

	int x = GetRand(640); // 画面幅
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

void FallingObjectManager::removeMarkedObjects()
{
	auto& objs = objects_;

	objs.erase(
		std::remove_if(
			objs.begin(),
			objs.end(),
			[](const FallingObject& obj)
			{
				return obj.isMarkedForRemove();
			}
		),
		objs.end()
	);
}
