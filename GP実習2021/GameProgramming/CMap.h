#ifndef CMAP_H
#define CMAP_H

#include "CRectangle.h"
#include "TaskInclude.h"
#include "CBase.h"

//extern CTexture TextureBos_background;

class CMap : public CBase {
	DrawTask m_Draw;		// 描画タスク操作クラス

public:
	CMap();
	CRectangle m_Rect1;
	void Render();
};

#endif
