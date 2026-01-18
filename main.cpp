#include"DxLib.h"
#include"System/GameManager.h"
#include "GameConfig.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ÉtÉåÅ[ÉÄêßå‰ÇÕmainÇ≈çsÇ§
	ChangeWindowMode(TRUE);
	SetGraphMode(
		GameConfig::ScreenConfig::Width,
		GameConfig::ScreenConfig::Height,
		GameConfig::ScreenConfig::colorBit);

	if (DxLib_Init() == -1)
	{
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	GameManager gameManager;
	gameManager.initialize();

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();
		gameManager.update();
		gameManager.draw();
		ScreenFlip();
	}

	DxLib_End();
	return 0;
}