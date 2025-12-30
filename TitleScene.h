#pragma once
#include "Scene.h"

class TitleScene : public Scene
{
public:
	void update(const Input& input) override;
	void draw(Renderer& renderer) override;

private:
	// このクラスにInputの事情を知ったメンバがいるのはおかしい？
	bool entered = false;
};