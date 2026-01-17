#include "SceneManager.h"
#include "TitleScene.h"
#include "SceneId.h"
#include "System/GameManager.h"

SceneManager::SceneManager(
    const ImageLoader& imageLoader,
    const ImageStore& imageStore,
    const FallingObjectImages& fallingObjectImages,
    const PlayerImages& playerImages
)
    :titleScene(),
    gameScene(imageStore, fallingObjectImages, playerImages),
    resultScene()
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
        // ƒXƒRƒA‚ğResultScene‚É“n‚·
        resultScene.setScore(gameScene.getScore());
        currentScene = &resultScene;
        currentScene->onEnter();
        break;
    default:
        return;
    }
}