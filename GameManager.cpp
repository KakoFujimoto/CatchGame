#include"DxLib.h"
#include"GameManager.h"

void GameManager::initialize()
{

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
void GameManager::finalize()
{

}