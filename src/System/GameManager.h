#pragma once
#include "Scene/SceneManager.h"
#include "Graphic/Renderer.h"
#include "Graphic/ImageLoader.h"
#include "Input.h"
#include "Graphic/ImageStore.h"
#include "Graphic/PlayerImages.h"
#include "FallingObject/FallingObjectImages.h"
#include "UI/GameUI.h"


class GameManager
{
public:
	GameManager();
	void initialize();
	void update();
	void draw();

private:
    ImageStore imageStore;
    PlayerImages playerImages;
    FallingObjectImages fallingObjectImages;
    Renderer renderer;
    Input input;
    // ImageLoader imageLoader; // -> スコープが広いのでローカル変数でいいのでは？　※状態などを特にもっていない
    SceneManager sceneManager;
    GameUI gameUi;
};