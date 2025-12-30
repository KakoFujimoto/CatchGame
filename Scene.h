#pragma once

class Renderer;
class Scene
{
public:
	virtual ~Scene(){}
	virtual void onEnter(){}
	virtual void update() = 0;
	virtual void draw(Renderer& renderer) = 0;
};

