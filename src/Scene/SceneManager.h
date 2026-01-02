#pragma once
#include "Scene.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "ResultScene.h"

class Renderer;
class Input;
class GameManager;

// 各Sceneのインスタンスを保持する
// Sceneの切り替えをする
class SceneManager
{
public:
	void initialize(GameManager& gameManager);
	void update(const Input& input);
	void draw(Renderer& renderer);
	void changeScene(SceneId id);

private:
	Scene* currentScene = nullptr; // 今アクティブなScene実体

	// 各Sceneのインスタンス
	TitleScene titleScene;
	GameScene gameScene;
	ResultScene resultScene;

	GameManager* gameManager_ = nullptr;
};