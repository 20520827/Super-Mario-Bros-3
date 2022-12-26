#include "Bush.h"

#include "Sprite.h"
#include "Sprites.h"

#include "Textures.h"

void Bush::Render()
{
	CSprites* s = CSprites::GetInstance();

	s->Get(this->spriteIdBush)->Draw(x, y);

	//RenderBoundingBox();
}

void Bush::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - bbox_width / 2;
	t = y - bbox_height / 2;
	r = l + bbox_width;
	b = t + bbox_height;
}