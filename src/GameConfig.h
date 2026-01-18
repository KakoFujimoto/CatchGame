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
		static constexpr int DisplayMarignX = 200;
		static constexpr int ResultDisplayMarignY = 200;
		static constexpr int ReplayDisplayMarignY = 240;
	};

	struct TitleSceneConfig
	{
		static constexpr int DisplayMarignX = 200;
		static constexpr int TitleDisplayMarignY = 200;
		static constexpr int MessageDisplayMarignY = 240;
	};

	struct ScoreConfig
	{
		static constexpr int DisplayMarignX = 10;
		static constexpr int DisplayMarignY = 25;
	};
}