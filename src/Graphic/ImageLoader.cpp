#include "ImageLoader.h"
#include <Dxlib.h>

void ImageLoader::load()
{
	playerImages_[(int)Facing::Left][(int)MoveState::Idle]
		//= LoadGraph("assets/images/player/player_left_1.png");
		= LoadGraph("player_left_1.png");


	playerImages_[(int)Facing::Left][(int)MoveState::Walk]
		= LoadGraph("player_left_2.png");

	playerImages_[(int)Facing::Right][(int)MoveState::Idle]
		= LoadGraph("player_right_1.png");

	playerImages_[(int)Facing::Right][(int)MoveState::Walk]
		= LoadGraph("player_right_2.png");
}

int ImageLoader::getPlayerImage(Facing facing, MoveState moveState) const
{
	return playerImages_[(int)facing][(int)moveState];
}