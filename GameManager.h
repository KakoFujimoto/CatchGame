#pragma once
#include"SceneManager.h"
#include"Renderer.h"
#include"Input.h"


class GameManager
{
public:
	void initialize();
	void update();
	void draw();
	void finalize();
private:
	SceneManager sceneManager;
	Renderer renderer;
	Input input;
};