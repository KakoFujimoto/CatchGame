#include "GameUI.h"
#include "Graphic/Renderer.h"
#include <string>

void GameUI::drawTimer(Renderer& renderer, int remainingSecond) const
{
	const int x = 10;
	const int y = 10;
	std::string header = "Time : ";
	std::string content = std::to_string(remainingSecond);

	renderer.drawText(x, y, header + content);
}
