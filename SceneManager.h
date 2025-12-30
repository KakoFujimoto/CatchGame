#pragma once
#include "Scene.h"
#include "TitleScene.h"


class Renderer;
class Input;
// 各Sceneのインスタンスを保持する
// Sceneの切り替えをする
class SceneManager
{
public:
	void initialize();
	void update(const Input& input);
	void draw(Renderer& renderer);
	// void changeScene(SceneId id);

private:
	Scene* currentScene = nullptr; // 今アクティブなScene実体

	// 各Sceneのインスタンス
	TitleScene titleScene;
	// GameScene gameScene;
	// ResultScene resultScene;
};

// どのSceneに遷移するかを表す識別子
enum class SceneId
{
	None,
	Title,
	Game,
	Result
};