#pragma once
#include "Scene/SceneManager.h"
#include "Graphic/Renderer.h"
#include "Graphic/ImageLoader.h"
#include "Input.h"


class GameManager
{
public:
	GameManager();
	void initialize();
	void update();
	void draw();
	ImageLoader& getImageLoader();
private:
	SceneManager sceneManager;
	Renderer renderer;
	Input input;
	ImageLoader imageLoader;
};