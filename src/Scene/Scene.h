#pragma once
#include "SceneId.h"

class Renderer;
class Input;

class Scene
{
public:
	virtual ~Scene(){}
	virtual void onEnter(){}
	virtual SceneId update(const Input& input) = 0;
	virtual void draw(Renderer& renderer) = 0;
};

