#ifndef CMAP_H
#define CMAP_H

#include "CRectangle.h"
#include "TaskInclude.h"
#include "CBase.h"

//extern CTexture TextureBos_background;

class CMap : public CBase {
	DrawTask m_Draw;		// �`��^�X�N����N���X

public:
	CMap();
	CRectangle m_Rect1;
	void Render();
};

#endif
