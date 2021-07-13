#ifndef CHPHERO_H
#define CHPHERO_H
#include "CRectangle.h"
#include "TaskInclude.h"
#include "CBase.h"
#include "SampleProperty.h"
class CPlayerHP :public CBase
{
private:
	DrawTask mDraw;		//�`��^�X�N����
	void Update();
	int mAniCnt;	//�A�j���[�V�����J�E���g
	int mHPReduCnt; //�g�o���炷�J�E���g
	int mAniMoving;	//���s�A�j���[�V�����p�̕ϐ�

public:
	CPlayerHP();
	// �R���X�g���N�^�ŏ�����
	CPlayerHP(float max, float min, float pre)

{
	//�`��^�X�N�ɓo�^
		mDraw.RegistDraw(this, (DrawFunc)&CPlayerHP::Render, DrawPriority::Transparent, "CPlayerHP");
	mTag = EPLAYERHP;
	mRect.x = -250;
	mRect.y = 600;
	mRect.w = 30;
	mRect.h = 30;
}

	int mPositionY1;	//Y���W�L��
	int mPositionX1;

	int mPositionY2;	//Y���W�L��
	int mPositionX2;
	
	static int mHPReduCnt;

	void Render();
	
	static CPlayerHP*spInstance;

	CRectangle m_Rect1;
	CRectangle m_Rect2;
};


#endif