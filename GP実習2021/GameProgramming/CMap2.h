#ifndef CMAP2_H
#define CMAP2_H

#include "CRectangle.h"
#include "TaskInclude.h"
#include "CBase.h"

extern CTexture Texture2;

class CMap2 : public CBase {
	DrawTask m_Draw;		// 描画タスク操作クラス

public:
	CMap2();
	CRectangle m_Rect1;

	void Render();
};

#endif