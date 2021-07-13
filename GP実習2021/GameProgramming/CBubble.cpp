#include "CBubble.h"
#include "CPlayer.h"
#include "glut.h"
#include "SampleProperty.h"
#include "TaskManager.h"
#include "DrawTaskManager.h"

extern CTexture Texturekihou;//‹C–A

CBubble::CBubble(){
	mDraw.RegistDraw(this, (DrawFunc)&CBubble::Render, DrawPriority::Transparent, "Bubble");
	mRect.x = 600;
	mRect.y = 100;
	mRect.w = 25;
	mRect.h = 25;
	mTag = EKIHOU;

}


void CBubble::Update(){
	mEnabled = true;
	mRect.y += 1;

	if (mRect.y > 500){
		mRect.y = -300;
	}
}


void CBubble::Render(){
	if (mTag == EKIHOU){
		mRect.Render(Texturekihou, 0, Texturekihou.mHeader.width, Texturekihou.mHeader.height, 0);
	}

}

void CBubble::Collision(CBase *i, CBase *y){

	if (y->mTag == EPLAYER){
		if (mRect.Collision(y->mRect)){

			if (CPlayer::mHp < 100){
				CPlayer::mHp += 20;
			}
			Kill();
		}

	}
}
