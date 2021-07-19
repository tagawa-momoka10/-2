#include "CItem1.h"
#include "CScore.h"
#include "CPlayer.h"
#include "CRectangle.h"
#include "SampleProperty.h"
#include "TaskManager.h"

extern CTexture Textureitem1;
#define G 0.5	//�d��
#define VJ0 2	//�W�����v��
CItem1::CItem1()
:JumCnt(60)
{
	//�`��^�X�N�ɓo�^
	mDraw.RegistDraw(this, (DrawFunc)&CItem1::Render, DrawPriority::Opacity, "CItem1");
	
	mRect.x = 100;
	mRect.y = 100;
	mRect.w = 50;
	mRect.h = 50;

}

void CItem1::Update(){
	mTag = EITEM1;
	mEnabled = true;
	CScore::mScore += 10;

	if (mEnabled = true){
		mJump1 = mRect.y;
		mj1 = VJ0;
		mJumping1 = true;

	}
}

void CItem1::Collision(CBase *i, CBase *y){
	if (y->mTag == EPLAYER){
		if (mRect.Collision(y->mRect)){
			Kill();
		}
	}
}

void CItem1::Render(){
	if (mTag == EITEM1){
		mRect.Render(Textureitem1, 0, Textureitem1.mHeader.width, Textureitem1.mHeader.height, 0);
	}
}
