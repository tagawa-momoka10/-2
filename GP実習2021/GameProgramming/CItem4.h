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
	DrawTask mDraw;		//�`��^�X�N����
	void Collision(CBase *i, CBase *y);		//�Փ˔���
public:

	CItem4();

	void Update();
	void Render();
};

#endif