#include "TitleScene.h"
#include "System/Input.h"
#include "Graphic/Renderer.h"
#include "SceneId.h"
#include "GameConfig.h"
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
	renderer.drawText(
		GameConfig::TitleSceneConfig::DisplayMarignX,
		GameConfig::TitleSceneConfig::TitleDisplayMarignY,
		"TITLE"
	);
	renderer.drawText(
		GameConfig::TitleSceneConfig::DisplayMarignX,
		GameConfig::TitleSceneConfig::MessageDisplayMarignY,
		"PRESS ENTER"
	);
}