#pragma once
#include"Scene.h"

class Renderer;
class Input;
class SceneManager
{
public:
	void initialize();
	void update(Input& input);
	void draw(Renderer& renderer);

private:
	Scene* currentScene = nullptr;
};