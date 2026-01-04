#include "DxLib.h"
#include "GameManager.h"

GameManager::GameManager()
	: sceneManager()
	, renderer()
	, input()
	, imageLoader()
{ }

void GameManager::initialize()
{
	imageLoader.load();
	sceneManager.initialize(*this);
}
void GameManager::update()
{
	// 前フレームのキー押下状態の取得及び今フレームの状態の保存
	input.update();
	// シーン遷移
	sceneManager.update(input);
}

void GameManager::draw()
{
	sceneManager.draw(renderer);
}

ImageLoader& GameManager::getImageLoader()
{
	return imageLoader;
}