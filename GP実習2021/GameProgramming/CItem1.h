#ifndef CITEM1_H
#define CITEM1_H

#include "CRectangle.h"
#include "TaskInclude.h"
#include "CBase.h"
#include "SampleProperty.h"
#include "CPlayerHP.h"


class CItem1:public CBase
{
private:
	DrawTask mDraw;		//�`��^�X�N����
	void Collision(CBase *i, CBase *y);		//�Փ˔���
public:
	
	CItem1();

	void Update();
	void Render();
};

#endif