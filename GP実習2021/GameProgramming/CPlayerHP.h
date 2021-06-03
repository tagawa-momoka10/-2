#ifndef CHPHERO_H
#define CHPHERO_H
#include "CRectangle.h"
#include "TaskInclude.h"
#include "CBase.h"
#include "SampleProperty.h"
class CPlayerHP :public CBase
{
private:
	float m_Max; // �ő�l
	float m_Min; // �ŏ��l
	DrawTask mDraw;		//�`��^�X�N����
	void Update();
	int mAniCnt;	//�A�j���[�V�����J�E���g
	int mAniMoving;	//���s�A�j���[�V�����p�̕ϐ�

public:
	CPlayerHP();
	// �R���X�g���N�^�ŏ�����
	CPlayerHP(float max, float min, float pre)
		:m_Max(max), m_Min(min)
{
	//�`��^�X�N�ɓo�^
		mDraw.RegistDraw(this, (DrawFunc)&CPlayerHP::Render, DrawPriority::Transparent, "CPlayerHP");
	mTag = EPLAYERHP;
	mRect.x = -250;
	mRect.y = 600;
	mRect.w = 30;
	mRect.h = 30;
}


	int max;
	int min;
	int mPositionY1;	//Y���W�L��
	int mPositionX1;

	int mPositionY2;	//Y���W�L��
	int mPositionX2;



	float getMax();
	float getMin();
	float get();

	float add(float value);
	float addMax(float value);
	float addMin(float value);

	float CPlayerHP::hp();
	float CPlayerHP::rate();


	void setMax(float value);
	void setMin(float value);
	void set(float value);


	bool CPlayerHP::isEmpty();
	bool CPlayerHP::isFull();

	void Render();
	
	static CPlayerHP*spInstance;

	CRectangle m_Rect1;
	CRectangle m_Rect2;
};


#endif