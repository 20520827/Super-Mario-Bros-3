#include "Pipe.h"

#include "Sprite.h"
#include "Sprites.h"

#include "Textures.h"

void Pipe::Render()
{
	CSprites* s = CSprites::GetInstance();

	s->Get(this->spriteIdPipe)->Draw(x, y);

	//RenderBoundingBox();
}

void Pipe::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - bbox_width / 2;
	t = y - bbox_height / 2;
	r = l + bbox_width;
	b = t + bbox_height;
}

void Pipe::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case PIPE_STATE_SOLID:
		this->isSolid = 1;
		break;
	case PIPE_STATE_TRANS:
		this->isSolid = 0;
		break;
	}
}