#pragma once

namespace GameConfig
{
	struct Time
	{
		static constexpr int FrameRate = 60;
		static constexpr int PlayTime = 15;
	};

	struct PlayerConfig
	{
		static constexpr int Speed = 5;
		static constexpr int Width = 40;
		static constexpr int Height = 40;
	};

	struct ScreenConfig
	{
		static constexpr int Width = 800;
		static constexpr int Height = 600;
		static constexpr int colorBit = 32;
		static constexpr int Margin = 100;
		static constexpr int DeadLineY = Height - Margin;
	};

	struct FallingObjectConfig
	{
		static constexpr int Width = 40;
		static constexpr int Height = 40;
		static constexpr int FishSpeed = 2;
		static constexpr int RockSpeed = 5;

	};

	struct FallingObjectManagerConfig
	{
		static constexpr int SpawnIntervalFrame = 60;
		static constexpr int SpawnMaxX = 640;
	};

	struct GameUIConfig
	{
		static constexpr int DisplayMargin = 10;
	};

	struct ResultSceneConfig
	{
		static constexpr int DisplayMarginX = 200;
		static constexpr int ResultDisplayMarginY = 200;
		static constexpr int ReplayDisplayMarginY = 240;
	};

	struct TitleSceneConfig
	{
		static constexpr int DisplayMarginX = 200;
		static constexpr int TitleDisplayMarginY = 200;
		static constexpr int MessageDisplayMarginY = 240;
	};

	struct ScoreConfig
	{
		static constexpr int DisplayMarginX = 10;
		static constexpr int DisplayMarginY = 25;
		static constexpr int PlusValue = 10;
		static constexpr int MinusValue = -5;
	};

	namespace Player
	{
		constexpr int startX = 400;
		constexpr int startY = 500;
	}
}