#pragma once
#include "SceneManager.h"
#include "Renderer.h"
#include "ImageLoader.h"
#include "Input.h"
#include "ImageStore.h"
#include "PlayerImages.h"
#include "FallingObjectImages.h"

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
	ImageStore imageStore;
	PlayerImages playerImages;
	FallingObjectImages fallingObjectImages;
};