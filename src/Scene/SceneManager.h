#pragma once
#include "Scene.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "ResultScene.h"
#include "SceneId.h"


class Renderer;
class Input;
class GameManager;
class ImageStore;
class FallingObjectImages;
class PlayerImages;
class GameUI;


// 各Sceneのインスタンスを保持する
// Sceneの切り替えをする
class SceneManager
{
public:
    SceneManager(
        const ImageStore& imageStore,
        const FallingObjectImages& fallingObjectImages,
        const PlayerImages& playerImages,
        const GameUI& gameUi
    );
    void initialize(GameManager& gameManager);
    void update(const Input& input);
    void draw(Renderer& renderer);
    void changeScene(SceneId id);

private:
    Scene* currentScene = nullptr; // 今アクティブなScene実体
    SceneId currentSceneId = SceneId::None;

    // 各Sceneのインスタンス
    TitleScene titleScene;
    GameScene gameScene;
    ResultScene resultScene;

    GameManager* gameManager_ = nullptr;
};