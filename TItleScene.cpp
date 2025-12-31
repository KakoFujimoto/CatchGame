#include "TitleScene.h"
#include "Input.h"
#include "Renderer.h"
#include "SceneId.h"
#include <DxLib.h>


SceneId TitleScene::update(const Input& input)
{
	if (input.isTriggered(KEY_INPUT_RETURN))
	{
		return SceneId::Game;
	}
	return SceneId::None;
}

void TitleScene::draw(Renderer& renderer)
{
	renderer.drawText(200, 200, "TITLE");
	renderer.drawText(200, 240, "PRESS ENTER");
}
