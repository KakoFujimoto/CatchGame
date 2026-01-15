#include "DxLib.h"
#include "PlayerImages.h"
#include "ImageStore.h"


void PlayerImages::load(ImageStore& store)
{
    store.set(ImageId::Player_Left_Idle, 
        LoadGraph("assets/images/player/player_left_1.png"));
    store.set(ImageId::Player_Left_Walk,
        LoadGraph("assets/images/player/player_left_2.png"));
    store.set(ImageId::Player_Right_Idle,
        LoadGraph("assets/images/player/player_right_1.png"));
    store.set(ImageId::Player_Right_Walk,
        LoadGraph("assets/images/player/player_right_2.png"));
}

ImageId PlayerImages::resolve(Facing facing, MoveState moveState) const
{
    switch (facing)
    {
    case Facing::Left:
        switch (moveState)
        {
        case MoveState::Idle:
            return ImageId::Player_Left_Idle;
        case MoveState::Walk:
            return ImageId::Player_Left_Walk;
        }
        break;
    case Facing::Right:
        switch (moveState)
        {
        case MoveState::Idle:
            return ImageId::Player_Right_Idle;
        case MoveState::Walk:
            return ImageId::Player_Right_Walk;
        }
        break;
    }
    return ImageId::Player_Left_Idle;
}
