#ifndef CITEM3_H
#define CITEM3_H

#include "CRectangle.h"
#include "TaskInclude.h"
#include "CBase.h"
#include "SampleProperty.h"
#include "CPlayerHP.h"


class CItem3 :public CBase
{
private:
	DrawTask mDraw;		//�`��^�X�N����
	void Collision(CBase *i, CBase *y);		//�Փ˔���
public:

	CItem3();

	void Update();
	void Render();
};

#endif