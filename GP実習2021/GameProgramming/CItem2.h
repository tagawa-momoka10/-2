#ifndef CITEM2_H
#define CITEM2_H

#include "CRectangle.h"
#include "TaskInclude.h"
#include "CBase.h"
#include "SampleProperty.h"
#include "CPlayerHP.h"


class CItem2 :public CBase
{
private:
	DrawTask mDraw;		//•`‰æƒ^ƒXƒN‘€ì
	void Collision(CBase *i, CBase *y);		//Õ“Ë”»’è
public:

	CItem2();

	void Update();
	void Render();
};

#endif