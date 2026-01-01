#include "HitCheck.h"

bool HitCheck::isHit(const HitArea& a, const HitArea& b)
{
	return
		a.right() > b.left() &&
		a.left() < b.right() &&
		a.bottom() > b.top() &&
		a.top() < b.bottom();
}
