#include "SceneManager.h"
#include "TitleScene.h"
#include "SceneId.h"
#include "System/GameManager.h"


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
	if (next != SceneId::None)
	{
		changeScene(next);
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
		break;
	case SceneId::Game:
		currentScene = &gameScene;
		// Œ»ó‚±‚¿‚ç‚Íg‚Á‚Ä‚¢‚È‚¢
		//currentScene->onEnter();
		gameScene.onEnter(gameManager_->getImageLoader());
		break;
	case SceneId::Result:
		// ƒXƒRƒA‚ğResultScene‚É“n‚·
		resultScene.setScore(gameScene.getScore());
		currentScene = &resultScene;
		break;
	default:
		break;
	}
	currentScene->onEnter();
}