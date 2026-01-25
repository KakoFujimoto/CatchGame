#include "DxLib.h"
#include "GameManager.h"

GameManager::GameManager()
	: imageStore()
	, playerImages()
	, fallingObjectImages()
	, renderer()
	, input()
	, imageLoader()
	, sceneManager(imageStore, fallingObjectImages, playerImages, gameUi)
{
}

void GameManager::initialize()
{
	//imageLoader.loadAll(imageStore, playerImages, fallingObjectImages);
	//imageLoader.load(imageStore, playerImages);
	//imageLoader.load(imageStore, fallingObjectImages);
	playerImages.load(imageStore);
	fallingObjectImages.load(imageStore);
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