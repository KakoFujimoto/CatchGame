#pragma once
#include "Scene.h"

class GameScene;

class ResultScene : public Scene
{
public:
	// ResultScene‚ªGameScene‚ÉˆË‘¶‚µ‚Ä‚µ‚Ü‚Á‚Ä‚¢‚é
	// GameResult‚Ì‚æ‚¤‚ÈãˆÊŠT”O‚É•ª—£‚·‚é—]’n‚ ‚è
	ResultScene(GameScene& gameScene);
	SceneId update(const Input& input) override;
	void draw(Renderer& renderer) override;
	void setScore(int score);
	void onEnter() override;

private:
	int score_ = 0;
	GameScene& gameScene_;
};