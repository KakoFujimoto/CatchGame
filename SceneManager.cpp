#include"SceneManager.h"

void SceneManager::initialize()
{

}
void SceneManager::update(Input& input)
{
	if (currentScene)
	{
		currentScene->update();
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