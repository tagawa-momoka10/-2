#ifndef CSMG_H
#define CSMG_H
#include "CRectangle.h"
#include "TaskInclude.h"
#include "CBase.h"
#include "SampleProperty.h"
class CSmg :public CBase
{
private:
	float m_Max; // 最大値
	float m_Min; // 最小値
	DrawTask mDraw;		//描画タスク操作
	void Update();

public:
	CSmg();
	// コンストラクタで初期化
	CSmg(float max, float min, float pre)
		:m_Max(max), m_Min(min)
	{
		//描画タスクに登録
		mDraw.RegistDraw(this, (DrawFunc)&CSmg::Render, DrawPriority::Transparent, "CSmg");
		mRect.x = -250;
		mRect.y = 600;
		mRect.w = 15;
		mRect.h = 15;
	}


	int max;
	int min;

	void Render();

	static CSmg*spInstance;

	CRectangle m_Rect1;
	CRectangle m_Rect2;
	CRectangle m_Rect3;
	CRectangle m_Rect4;
	CRectangle m_Rect5;
	CRectangle m_Rect6;
	CRectangle m_Rect7;
	CRectangle m_Rect8;
	CRectangle m_Rect9;
	CRectangle m_Rect10;
	CRectangle m_Rect11;
};


#endif