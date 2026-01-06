#pragma once
#include <map>
#include <string>

#include "Facing.h"
#include "MoveState.h"
#include "FallingObjectType.h"


class ImageLoader
{
public:
	void load();
	//int getPlayerImage(Facing facing, MoveState moveState) const;
	//int getFallingObjectImage(FallingObjectType type) const;

	int get(std::string name);

private:
	//int playerImages_[(int)Facing::Count][(int)MoveState::Count];
	//int fallingObjectImages_[(int)FallingObjectType::Count];

	std::map<std::string, int> images_;

};

class PlayerImageGetter
{
public:

	int getImage(ImageLoader& imageLoader, Facing facing, MoveState moveState)
	{
		int idList[2][2] = {
			{
				LoadGraph("player/player_left_1"),
				LoadGraph("player/player_left_2"),
			},
			{
				LoadGraph("player/player_right_1"),
				LoadGraph("player/player_right_2"),
			}
		};

		return idList[static_cast<int>(facing)][static_cast<int>(moveState)];
	}

};
