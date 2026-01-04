#pragma once
#include "SceneManager.h"
#include "Renderer.h"
#include "ImageLoader.h"
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