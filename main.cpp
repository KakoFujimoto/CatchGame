#include"DxLib.h"
#include"System/GameManager.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ƒtƒŒ[ƒ€§Œä‚Ímain‚Ås‚¤
	ChangeWindowMode(TRUE);
	SetGraphMode(800, 600, 32);

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