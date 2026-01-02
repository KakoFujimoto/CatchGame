#pragma once
#include "SceneManager.h"
#include "Renderer.h"
#include "ImageLoader.h"
#include "Input.h"


class GameManager
{
public:
	void initialize();
	void update();
	void draw();
	void finalize();
	ImageLoader& getImageLoader();
private:
	SceneManager sceneManager;
	Renderer renderer;
	Input input;
	ImageLoader imageLoader;
};