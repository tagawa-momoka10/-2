#ifndef CICON1_H
#define CICON1_H

#include "CRectangle.h"
#include "TaskInclude.h"
#include "CBase.h"
#include "SampleProperty.h"
class CIcon1 :public CBase
{
private:
	DrawTask mDraw;		//ï`âÊÉ^ÉXÉNëÄçÏ
public:
	CIcon1();
	//CIcon1(){
	//	//ï`âÊÉ^ÉXÉNÇ…ìoò^
	//	mDraw.RegistDraw(this, (DrawFunc)&CIcon1::Render, DrawPriority::Transparent, "CIcon1");
	//	mTag = EICON1;
	//	mRect.x = -450;
	//	mRect.y = 400;
	//	mRect.w = 50;
	//	mRect.h = 50;
	//}
	void Render();
	CRectangle m_Rect1;
};

#endif