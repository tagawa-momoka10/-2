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
	DrawTask mDraw;		//�`��^�X�N����
	void Collision(CBase *i, CBase *y);		//�Փ˔���
public:

	CItem2();

	void Update();
	void Render();
};

#endif