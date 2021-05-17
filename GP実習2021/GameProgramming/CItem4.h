#ifndef CITEM4_H
#define CITEM4_H

#include "CRectangle.h"
#include "TaskInclude.h"
#include "CBase.h"
#include "SampleProperty.h"
#include "CPlayerHP.h"

class CItem4 :public CBase
{
private:
	DrawTask mDraw;		//•`‰æƒ^ƒXƒN‘€ì
	void Collision(CBase *i, CBase *y);		//Õ“Ë”»’è
public:

	CItem4();

	void Update();
	void Render();
};

#endif