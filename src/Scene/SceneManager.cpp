#include "SceneManager.h"
#include "TitleScene.h"
#include "SceneId.h"
#include "System/GameManager.h"
#include "UI/GameUI.h"


SceneManager::SceneManager(
    const ImageStore& imageStore,
    const FallingObjectImages& fallingObjectImages,
    const PlayerImages& playerImages,
    const GameUI& gameUi
)
    :titleScene(),
    gameScene(imageStore, fallingObjectImages, playerImages, gameUi),
    resultScene(gameScene)
{
}

void SceneManager::initialize(GameManager& gameManager)
{
    gameManager_ = &gameManager;
    currentScene = &titleScene;
    currentScene->onEnter();
}

void SceneManager::update(const Input& input)
{
    if (!currentScene)
    {
        return;
    }
    SceneId next = currentScene->update(input);

    if (next != SceneId::None && next != currentSceneId)
    {
        changeScene(next);
        currentSceneId = next;
    }
}

// ¡‚ÌScene‚É•`‰æ‚ğˆË—Š
void SceneManager::draw(Renderer& renderer)
{
    if (currentScene)
    {
        currentScene->draw(renderer);
    }
}

void SceneManager::changeScene(SceneId id)
{
    switch (id)
    {
    case SceneId::Title:
        currentScene = &titleScene;
        currentScene->onEnter();
        break;
    case SceneId::Game:
        currentScene = &gameScene;
        gameScene.onEnter();
        break;
    case SceneId::Result:
        currentScene = &resultScene;
        currentScene->onEnter();
        break;
    default:
        return;
    }
}