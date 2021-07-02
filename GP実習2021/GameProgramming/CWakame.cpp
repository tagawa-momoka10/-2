#include "CWakame.h"
#include "CPlayer.h"
#include "CKey.h"
#include "SampleProperty.h"
#include "TaskManager.h"
#include "DrawTaskManager.h"
#include "CPlayerAttack.h"
#include "CEnemy.h"
#include "CKey.h"

#define ANICNT 40		//�A�j���[�V����
#define INITIALIZE 0	//������

extern CTexture Texturewa;
bool CWakame::mMoving;

CWakame::CWakame(){
	mDraw.RegistDraw(this, (DrawFunc)&CWakame::Render, DrawPriority::Transparent, "CWakame");
	mTag = EWAKAME;
	mRect.x = 40;
	mRect.y = 600;
	mRect.w = 20;
	mRect.h = 300;
	mAniMoving = INITIALIZE;

}

void CWakame::Update(){
	mEnabled = true;
}


void CWakame::Collision(CBase *i, CBase *y){
	//�v���C���[1�Ɠ��������Ƃ�

	if (y->mTag == EPLAYER){
		if (y->mEnabled){
			if (CKey::Push('A')) {
				mRect.x += 2;

			}
			if (CKey::Push('D')) {
				mRect.x -= 2;

			}
			if (CKey::Push('S')) {
				mRect.x += 2;

			}
		}
	}


	if (mRect.y - CPlayer::spInstance->mRect.y < 20){
		if (y->mTag == EPLAYERATTACK){
			if (mRect.Collision(y->mRect)){
				//���G��ԂŖ������

				return;
			}
		}
	}
}


void CWakame::Render(){
	if (mTag == EWAKAME){
		mRect.Render(Texturewa, 0, 200, 600, 0);
	}
}