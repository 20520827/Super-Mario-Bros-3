#include "InvisPlat.h"
void InvisPlat::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - bbox_width / 2;
	t = y - bbox_height / 2;
	r = l + bbox_width;
	b = t + bbox_height;
}
