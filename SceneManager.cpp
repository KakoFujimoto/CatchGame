#include "SceneManager.h"
#include "TitleScene.h"


void SceneManager::initialize()
{
	currentScene = &titleScene;
}
void SceneManager::update(const Input& input)
{
	if (currentScene)
	{
		currentScene->update(input);
	}
}
// ¡‚ÌScene‚É•`‰æ‚ðˆË—Š
void SceneManager::draw(Renderer& renderer)
{
	if (currentScene)
	{
		currentScene->draw(renderer);
	}
}

//void SceneManager::changeScene(SceneId id)
//{
//	switch (id)
//	{
//	case SceneId::Title:
//		currentScene = titleScene;
//		break;
//	case SceneId::Game:
//		currentScene = gameScene;
//		break;
//	case SceneId::Result:
//		currentScene = resultScene;
//		break;
//	default:
//		break;
//	}
//}