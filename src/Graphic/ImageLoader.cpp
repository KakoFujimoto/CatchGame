#include "ImageLoader.h"
#include <Dxlib.h>

void ImageLoader::load()
{/*
	playerImages_[(int)Facing::Left][(int)MoveState::Idle]
		= LoadGraph("assets/images/player/player_left_1.png");

	playerImages_[(int)Facing::Left][(int)MoveState::Walk]
		= LoadGraph("assets/images/player/player_left_2.png");

	playerImages_[(int)Facing::Right][(int)MoveState::Idle]
		= LoadGraph("assets/images/player/player_right_1.png");

	playerImages_[(int)Facing::Right][(int)MoveState::Walk]
		= LoadGraph("assets/images/player/player_right_2.png");

	fallingObjectImages_[(int)FallingObjectType::Fish]
		= LoadGraph("assets/images/falling_objects/fish.png");

	fallingObjectImages_[(int)FallingObjectType::Rock]
		= LoadGraph("assets/images/falling_objects/rock.png");*/

}

int loadImage(std::string name)
{
	return LoadGraph(("assets/images" + name + ".png").c_str());
}

int ImageLoader::get(std::string name)
{
	auto exists = images_.find(name);
	if (exists != images_.end()) {
		return images_[name];
	}

	int id = loadImage(name);
	images_[name] = id;
	return id;
}

//
//int ImageLoader::getPlayerImage(Facing facing, MoveState moveState) const
//{
//	return playerImages_[(int)facing][(int)moveState];
//}
//
//int ImageLoader::getFallingObjectImage(FallingObjectType type) const
//{
//	return fallingObjectImages_[(int)type];
//}