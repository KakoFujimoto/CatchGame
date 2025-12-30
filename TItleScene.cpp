#include "TitleScene.h"
#include "Input.h"
#include "Renderer.h"
#include <DxLib.h>

void TitleScene::update(const Input& input)
{
	if (input.isTriggered(KEY_INPUT_RETURN))
	{
		entered = true;
	}
}
void TitleScene::draw(Renderer& renderer)
{
	renderer.drawText(200, 200, "TITLE");

	if (!entered)
	{
		renderer.drawText(200, 240, "PRESS ENTER");
	}
	else
	{
		renderer.drawText(200, 240, "ENTER PRESSED");

	}
}
