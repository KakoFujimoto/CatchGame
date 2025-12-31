#include "ResultScene.h"
#include "Input.h"
#include "Renderer.h"
#include "SceneId.h"
#include <DxLib.h>


SceneId ResultScene::update(const Input& input)
{
	if (input.isTriggered(KEY_INPUT_RETURN))
	{
		return SceneId::Game;
	}
	return SceneId::None;
}

void ResultScene::draw(Renderer& renderer)
{
	renderer.drawText(200, 200, "RESULT");
	renderer.drawText(200, 240, "ENTER TO REPLAY");
}
