#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "CRectangle.h"
#include "TaskInclude.h"
#include "SampleProperty.h"

class CCircle :public Task
{
private:
	int mFx;
	int mVj;
	void Update();
	void Draw();
	DrawTask mDraw;
public:
	CRectangle mRect;	//lŠpŒ`•`‰æ•Ï”
	CCircle();
};


#endif