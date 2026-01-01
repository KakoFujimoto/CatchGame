#pragma once
#include "HitArea.h"

class HitCheck
{
public:
	static bool isHit(const HitArea& a, const HitArea& b);
};