#ifndef CICON2_H
#define CICON2_H

#include "CRectangle.h"
#include "TaskInclude.h"
#include "CBase.h"
#include "SampleProperty.h"
class CIcon2 :public CBase
{
private:
	DrawTask mDraw;		//•`‰æƒ^ƒXƒN‘€ì
public:
	CIcon2();
	void Render();
	CRectangle m_Rect1;
};

#endif